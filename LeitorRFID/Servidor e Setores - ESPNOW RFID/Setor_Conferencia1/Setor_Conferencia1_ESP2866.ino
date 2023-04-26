/* => Projeto: Controle de OS WiFi
 *
 * :Programador: Gustavo Oliveira Ferreira dos Santos
 * :Supervisor: Rubem Silva de Gusmão
 * :Email Programador: santos.gustavo.of@gmail.com
 * :Email Supervisor: riex@riex.com
 * :Data: 06.JUN.2022 - 30.JUN.2022
 *
 * Esse código tem a função de Ler os Números de Ordem de Serviço(OS) que foram cadastrados dentro de cartões RFID,
 * através de Leitores MFRC522 e enviar esses números, formatados com o setor que a placa se encontra, para o Servidor
 * principal, via protocolo ESP-NOW, e lá será repassado para o Arduino Leornardo  que interpretará e escreverá as mensagens
 * numa planilha do Excel.
 *
 * Formatação das Mensagens que devem ser enviadas ao arduino Leonardo:
 *
 * <1111-0>
 * ||||||||
 * <****-#>      , sendo:
 *
 * **** = Um número de OS específico que estará escrito dentro do cartão.
 * #    = Número que indica o setor que a placa se encontra, por exemplo: 0 = Conferência-1 / 1 = Orçamento
 *
 * Os caracteres "<", "-" e ">", servirão para, além de espaçar os dados, padronizar uma formatação específica,
 * facilitando a identificação de mensagens inválidas, caso ocorram.
 *
 * Todas os microcontroladores utilizados precisam ser do mesmo tipo, logo todas elas são ESP2866 NodeMCU 1.0.
 * Modelos diferentes que também possuem WiFi integrado podem apresentar incompatibilidades e impossibilitar o funcionamento.


 */
//------------------------------------------------------------------------------------
// INCLUSÃO DAS BIBLIOTECAS NECESSÁRIAS
//------------------------------------------------------------------------------------

//=> Padrôes C
#include <stdio.h>
#include <stdlib.h>

//=> Operações WiFi
#include <espnow.h>
#include <ESP8266WiFi.h>

//=> Operações especiais
#include <EEPROM.h>

//=> Para os periféricos e leitores
#include <SPI.h>           // Biblioteca para Comunicação SPI (Protocólo ICSP)
#include <LiquidCrystal.h> // Biblioteca da Tela LCD
#include <MFRC522.h>       // Biblioteca do Leitor RFID MFRC-522

//------------------------------------------------------------------------------------
// DEFINIÇÕES DE PINOS E VARIÁVEIS DA MEMÓRIA
//------------------------------------------------------------------------------------

//=> Pinos
#define RST_PIN1 D3 //=> Pino de Reset para o Leitor RFID (configurável)
#define SS_PIN1 D8  //=> Pino Slave Select para o Leitor RFID (configurável)

#define LED0 2 //=> LED do Módulo WIFI

//=> Declarações de funções
void EEPROMWriteInt(int address, int value); // Responsável por escrita de inteiros na eeprom, ocupa 2 Bytes
int EEPROMReadInt(int address);              // Lê 2 Bytes e os une, retornando ao código o número inteiro armazenado

//=> Variáveis Para exibir no Display (e seus endereços na EEPROM)
int OSAtual; // Sempre salva no (580)

//------------------------------------------------------------------------------------
// DEFINIÇÕES DA REDE, CONEXÕES MAC E TIPO DE CLIENTES
//------------------------------------------------------------------------------------

const String ClientType = "0"; // ALTERAR A CADA SETOR

//=> Endereços Mac das placas
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t OrcamentoAddress[] = {0x30, 0x83, 0x98, 0xA2, 0x67, 0xD6};
uint8_t ServerAddress[] = {0x48, 0x55, 0x19, 0x12, 0xFC, 0xF0};

//------------------------------------------------------------------------------------
// ESTRUTURA DAS MENSAGENS E MARCADORES DE TEMPO
//------------------------------------------------------------------------------------

//=> Estrutura para Enviar Informações (Deve ser igual a estrutura de quem receber)
typedef struct struct_message
{
  // char a[32];
  // int b;
  // float c;
  String LeituraOSSetor;
  // bool e;
} struct_message;

//=> Cria uma mensagem estruturada chamada "myData"
struct_message myData;

//=> Variáveis para o Millis
unsigned long lastTime = 0;
unsigned long timerDelay = 2000; // send readings timer

//------------------------------------------------------------------------------------
// DECLARAÇÃO DE OBJETOS E KEYS PARA LEITORES, SENSORES E PERIFÉRICOS
//------------------------------------------------------------------------------------

//=> Para o Leitor RFID mfrc522
MFRC522 Leitor1(SS_PIN1, RST_PIN1);
MFRC522::MIFARE_Key key;

//====================================================================================

// INICIALIZAÇÃO DO CÓDIGO

void setup()
{

  //=> Inicializações -------------------------------------------------------
  Serial.begin(115200); //=> Inicia o monitor Serial
  SPI.begin();          //=> Inicia a comunicação SPI
  Leitor1.PCD_Init();   //=> Inicia o leitor RFID MFRC522
  delay(20);

  //=> Configura os Pinos --------------------------------------------------
  pinMode(LED0, OUTPUT); //=> LED de WIFI Embarcado

  //=> Configurações para o WIFI -------------------------------------------
  WiFi.mode(WIFI_STA); //=> Define o Dispositivo como uma Estação WiFi

  if (esp_now_init() != 0)
  { //=> Inicia o protocolo ESP-NOW
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  Serial.print("\n\nESP-NOW INICIALIZADO COM SUCESSO!");
  Serial.print("\nMac Address in Station: ");
  Serial.println(WiFi.macAddress());

  // Cadastra os modos de operação e os pontos da Rede
  //====================================================================================

  //=> Se o protocolo se iniciar corretamente, Retornará o estado de envio ou recepção -
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);

  //=> Registra os Endereços MAC que a placa vai se Conectar ---------------------------
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  esp_now_add_peer(ServerAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  esp_now_add_peer(OrcamentoAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);

  //====================================================================================

  //=> Prepara a Key A e Key B, para Leitura(ou escrita) nas tags
  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF;
    // Usa a chave FFFFFFFFFFFFh
  }
}

//====================================================================================
//  REPETIÇÃO -  LEITURA DOS CARTÕES
void loop()
{

  //=> VERIFICA SE HÁ UM CARTÃO NA FRENTE DO LEITOR
  if (!Leitor1.PICC_IsNewCardPresent())
  {
    Serial.print(".");
    delay(200);
    Leitor1.PCD_Reset();
    Leitor1.PCD_Init();
    return;
  }

  //=> VERIFICA SE A UID DO CARTÃO FOI LIDA
  if (!Leitor1.PICC_ReadCardSerial())
  {
    Serial.print("Cartão Não lido!\n");
    Leitor1.PCD_Reset();
    Leitor1.PCD_Init();
    return;
  }

  Serial.print("\n\nCartão Detectado!\n\n");

  //=> Passa pelo protocolo de leitura do cartão e prepara o leitor para o Segundo cartão
  Sensor1();

  //=> Reinicia o Leitor RFID
  Leitor1.PCD_Reset();
  Leitor1.PCD_Init();
  delay(1500);

  return;
}
