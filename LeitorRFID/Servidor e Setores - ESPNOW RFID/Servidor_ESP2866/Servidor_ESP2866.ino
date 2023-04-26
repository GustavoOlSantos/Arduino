/* => Projeto: Controle de OS WiFi
 *
 * :Programador: Gustavo Oliveira Ferreira dos Santos
 * :Email Programador: santos.gustavo.of@gmail.com
 * :Data: 06.JUN.2022 - 30.JUN.2022

  Esse código tem a função de Receber os números de Ordem de Serviço(OS) que foram lidos em outras placas (NodeMCU2866) com leitores MFRC522
  via protocolo ESP-NOW e reenviar essas informações recebidas para o Arduino Leonardo via protocolo I2C (Transferência de informação cabeada),
  para que lá, ele interprete as mensagens contendo o Número de OS e o Setor que o cartão foi lido e escreva numa planilha de Excel.

  Formatação das Mensagens que devem ser enviadas ao arduino Leonardo:

  <1111-0>
  ||||||||
  <****-#>      , sendo:

  **** = Um número de OS específico que estará escrito dentro do cartão.
  #    = Número que indica o setor que a placa se encontra, por exemplo: 0 = Conferência-1 / 1 = Orçamento

  Os caracteres "<", "-" e ">", servirão para, além de espaçar os dados, padronizar uma formatação específica,
  facilitando a identificação de mensagens inválidas, caso ocorram.

  Todas os microcontroladores utilizados precisam ser do mesmo tipo, logo todas elas são ESP2866 NodeMCU 1.0.
  Modelos diferentes que também possuem WiFi integrado podem apresentar incompatibilidades e impossibilitar o funcionamento.


  Números de identificação dos controladores secundários (escravos)

  1 - Arduino Leoonardo: Responsável por Receber as OS, escrever no PC e Requisitar Verificações

  2 - Arduino Mega: Responsável por Realizar as verificações requisitadas pelo Mestre, que será requisitado pelo (1)
 */
//------------------------------------------------------------------------------------
// INCLUSÃO DAS BIBLIOTECAS NECESSÁRIAS
//------------------------------------------------------------------------------------

//=> Padrôes C
#include <stdio.h>
#include <stdlib.h>

//=> Operações WiFi
#include <espnow.h>      //=> Protocolo ESP-NOW
#include <ESP8266WiFi.h> //=> Protocolos básicos de rede WiFi

//=> Operações especiais
#include <EEPROM.h> //=> Acesso a memória não volátil
#include <Wire.h>   //=> Envio de informações via Cabeamento

//------------------------------------------------------------------------------------
// DEFINIÇÕESM DE PINOS E VARIÁVEIS DA MEMÓRIA
//------------------------------------------------------------------------------------

#define LED0 2 // LED do Módulo WIFI

//=> Declarações de funções
void EEPROMWriteInt(int address, int value); // Responsável por escrita de inteiros na eeprom, ocupa 2 Bytes
int EEPROMReadInt(int address);              // Lê 2 Bytes e os une, retornando ao código o número inteiro armazenado

//=> Variáveis Para exibir no Display (e seus endereços na EEPROM)
int OSAtual; // Sempre salva no (580)

//------------------------------------------------------------------------------------
// DEFINIÇÕES DA REDE E CONEXÕES MAC
//------------------------------------------------------------------------------------

//=> ENDEREÇO GERAL
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

//=> ENDEREÇOS MAC
uint8_t OrcamentoAddress[] = {0x94, 0xB5, 0x55, 0x2C, 0x50, 0x28};
uint8_t Conferencia1Address[] = {0x58, 0xBF, 0x25, 0xDA, 0x8E, 0x90};

//------------------------------------------------------------------------------------
// ESTRUTURA DAS MENSAGENS E MARCADORES DE TEMPO
//------------------------------------------------------------------------------------

//=> Estrutura para Enviar/receber Informações (Deve ser igual a estrutura de quem receber)
typedef struct struct_message
{
  String LeituraOSSetor;
} struct_message;

String OsAnterior;

//=> Cria uma mensagem estruturada chamada "myData"
struct_message myData;

//=> Variáveis para o Millis
unsigned long lastTime = 0;
unsigned long timerDelay = 2000;

//====================================================================================

// INICIALIZAÇÃO DO CÓDIGO
void setup()
{

  //=> Inicializações -------------------------------------------------------------------------------------------
  Serial.begin(115200);            //=> Inicia o monitor Serial
  Wire.begin();                    //=> Inicia o protocolo I2C
  Wire.setClockStretchLimit(1500); // in µs
  delay(20);

  //=> Configura os Pinos ---------------------------------------------------------------------------------------
  pinMode(LED0, OUTPUT); //=> LED de WIFI Embarcado

  //=> Configurações para o WIFI --------------------------------------------------------------------------------
  WiFi.mode(WIFI_STA); //=> Define o Dispositivo como uma Estação WiFi

  if (esp_now_init() != 0)
  { //=> Inicia o protocolo ESP-NOW
    Serial.println("Erro ao inicializar o ESP-NOW");
    return;
  }

  Serial.print("\n\nESP-NOW INICIALIZADO COM SUCESSO!");
  Serial.print("\nEndereço Mac da placa: ");
  Serial.println(WiFi.macAddress());
  Serial.println();

  // Cadastra os modos de operação e os pontos da Rede
  //============================================================================================================

  //=> Se o protocolo se iniciar corretamente, Retornará informações sobre o envio ou a recepção das informações
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);

  // Registra os Endereços MAC que a placa vai se Conectar ---------------------------------------------------

  //=> Setores Administrativos
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  esp_now_add_peer(OrcamentoAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  esp_now_add_peer(Conferencia1Address, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

//===============================================================================================================
//  REPETIÇÃO - Relaxa enquanto aguarda a chegada de informações
void loop()
{
  Serial.print(".");
  delay(200);
}
