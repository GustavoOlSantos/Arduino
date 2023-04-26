/*-------------------- ATENÇÃO --------------------// 
 *
 * Antes de Carregar o código pela primeira vez, Leia a aba "zReadMe"
 * para ler as orientações e não causar erros no --> primeiro uso <--
 * 
 * E para ler a descrição do propósito e entender a rotina de cada aba.
 * 
 * -----------------------------------------------------------------
 * Para adiantar: 
 * A SENHA DE RESET MASTER PODE SER DEFINIDA NA ABA "TECLADO_SENHA" 
 *
 */

 
//------------ INCLUSÃO DAS BIBLIOTECAS -----------//

#include <stdio.h>            // Padrão para C++
#include <string.h>          // Inclui novas funções para Strings
#include <util/atomic.h>    // Permite a manipulaçao do Millis()
#include <LiquidCrystal.h> // Permite o Uso da Tela LCD
#include <EEPROM.h>       // Manipulação da memória não volátil (EEPROM)
#include <Keypad.h>      // Biblioteca a ser inclusa para o uso do teclado

//------------ VARIÁVEIS COMUNS ------------//

#define espacoEEPROM 4096         // Espaço da memória EEPROM do Arduino Mega 2560 em Bytes

// Resultados de funções
int BloqueioResult;           // Resultado da função de bloqueio
int MasterResult;            // Resultado da função de ResetMaster

          int ResetMaster;            // Servindo de ResetProvisório, apagar quando acabar os testes
// Indicadores
int Co2;                  // Indicador de disparo do Co2
int Temperatura;         // Indicador de disparo do Sensor de Temperatura
int Gas;                // Indicador de disparo do Sensor de Gás
int Saponif;           // Indicador de disparo do Tubo Sensor
int Acman;            // Indicador de disparo do Acionamento Manual
int Cman2;           // Indicador do Acionamento Manual do Co2
int Reset2 = 1;     // Limitador de disparos e Verificador do Reset
int Gate;          // Libera ou barra o disparo infinito do Reset

// Bloqueadores condicionais
int Locker1;     // Responsável por bloquear a entrada nas condicionais do Acman e Cman 
int Locker2;    // Responsável por bloquear a entrada nas condicionais do Cman e Temperatura
int Locker3;   // Responsável por bloquear a entrada nas condicionais do Acman e Temperatura

//------------ VARIÁVEIS PARA O MILLIS() ------------//

unsigned long MillisInicial;        // Inicio do loop
unsigned long MillisTotal;         // Tempo máximo para terminar a repetição
unsigned long MillisAtual;        // Tempo constantemente alterado
unsigned long Intervalo = 30000; // Tempo fixo que se deve passar antes de disparar o Co2

//------------ DEFINIÇÃO DOS PINOS DA TELA LCD ------------//

LiquidCrystal lcd(13 , 12 , 11 , 10 , 9 , 8); // Definição dos pinos digitais da tela

//------------ DEFINIÇÕES PARA O TECLADO  MATRICIAL ------------//

const byte LINHAS = 4;    // quantidade de linhas do teclado
const byte COLUNAS = 3;  // quantidade de colunas do teclado

// Matriz para colocar todos os caracteres do teclado:
char digitos[LINHAS][COLUNAS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}}; 

byte pinosLinha[LINHAS] = { 7, 6, 5, 4 }; // pinos de conexão das linhas no arduino 
byte pinosColuna[COLUNAS] = { 3, 2, 1}; // pinos de conexão das colunas no arduino 

// Objeto de leitura das teclas com os parâmetros lidos
Keypad keypad = Keypad( makeKeymap(digitos), pinosLinha, pinosColuna, LINHAS, COLUNAS ); 


//------------ DECLARAÇÃO DAS FUNÇÕES PARA INT NA EEPROM ------------//

void EEPROMWriteInt(int address, int value); // Ocupa 2 Bytes
int  EEPROMReadInt(int address);            // Lê 2 Bytes e os une

//------------ INICIALIZAÇÃO ------------//

void setup() {

  lcd.begin(20, 4); // Inicia A tela lcd 20x4
  lcd.clear();     // Limpa tela ao iniciar

  //---------- Entradas de sinal (Relés 24v) ----------//

  // Essas entradas estão todas marcadas como altas(HIGH) a todo momento

  /*pinMode(2, INPUT_PULLUP);//          // Sensor de temperatura
  pinMode(3, INPUT_PULLUP);//         // Acionador manual
  pinMode(4, INPUT_PULLUP);//        // Acionamento bloqueio
  pinMode(5, INPUT_PULLUP);//       // Tubo sensor
  pinMode(6, INPUT_PULLUP);//      // Botão de RESET (desligar a situação de alarme)
  pinMode(7, INPUT_PULLUP);//     // Sensor de gás
  pinMode(22, INPUT_PULLUP);//   // Acionamento Local do Co2 MANUAL
*/

  pinMode(27, INPUT_PULLUP);        // Sensor de temperatura
  pinMode(29, INPUT_PULLUP);       // Acionador manual
  pinMode(31, INPUT_PULLUP);      // Acionamento Local do Co2 
  pinMode(33, INPUT_PULLUP);     // Tubo sensor
  pinMode(35, INPUT_PULLUP);    // Sensor de gás 
  pinMode(37, INPUT_PULLUP);   // Botão de RESET (desligar a situação de alarme)
  pinMode(39, INPUT_PULLUP);  // Acionamento bloqueio




  pinMode(24, INPUT_PULLUP);// RESET MASTER PROVISÓRIO, APAGAR AO FIM DOS TESTES

  //---------- Saídas de sinal (Relés 5v) ----------//

  pinMode(43, OUTPUT);      // Sirene
  pinMode(45, OUTPUT);     // CO2
  pinMode(47, OUTPUT);    // Dumper
  pinMode(49, OUTPUT);   // Exaustão
  pinMode(51, OUTPUT);  // Shopping
  pinMode(53, OUTPUT); // Ar Condicionado

  digitalWrite(43, HIGH);      // Desativa Sirene 
  digitalWrite(45, HIGH);     // Desativa Co2
  digitalWrite(47, HIGH);    // Desativa Dumper
  digitalWrite(49, HIGH);   // Desativa Exaustão
  digitalWrite(51, HIGH);  // Desativa Ar Condicionado
  digitalWrite(53, HIGH); // Desativa Shopping

//---------- Valores Registrados na EEPROM para recuperar os dados e voltar do ponto em que parou ----------//

   Temperatura = EEPROMReadInt(0);   // Leitura do valor registrado na EEPROM (End. 0 e 1)
   Acman = EEPROMReadInt(2);        // Leitura do valor registrado na EEPROM (End. 2 e 3)
   Saponif = EEPROMReadInt(4);     // Leitura do valor registrado na EEPROM (End. 4 e 5)
   Gas = EEPROMReadInt(6);        // Leitura do valor registrado na EEPROM (End. 6 e 7)
   Co2 = EEPROMReadInt(8);       // Leitura do valor registrado na EEPROM (End. 8 e 9)                 
   Gate = EEPROMReadInt(10);    // Leitura do valor registrado na EEPROM (End. 10 e 11) 
   Cman2 = EEPROMReadInt(12);  // Leitura do valor registrado na EEPROM (End. 12 e 13)    

}

//------------ REPETIÇÃO INFINITA  ------------//
void loop() {

  MasterResult = 0; // Zera o Reset Master após a Central ser resetada
  Locker1 = 0;     // Zera o Bloqueador 1 após a Central ser resetada
  Locker2 = 0;    // Zera o Bloqueador 2 após a Central ser resetada
  Locker3 = 0;   // Zera o Bloqueador 3 após a Central ser resetada

  lcd.clear();
  lcd.setCursor(1, 0);               //Define posição da escrita
  lcd.print("CENTRAL DE COMBATE");  //Mensagem inicial a ser impressa
  lcd.setCursor(4, 1);
  lcd.print("R8X SISTEMAS");
  lcd.setCursor(3, 3);
  lcd.print("SISTEMA ATIVO");

  do {

    // A leitura HIGH é convertida para LOW em todos os casos, definindo esse estado como repouso
    // As portas reagem quando conectadas ao GND(LOW/0), invertendo a lógica e transformando para 5v(HIGH/1)
    // Logo, é necessário conectar o GND no Comum dos relés de entrada

    int SensorTemp = ! digitalRead(27);
    delay(20);
    int AcManual = ! digitalRead(29);
    delay(20);
    int Cman = ! digitalRead(31);
    delay(20);
    int TuboSensor = ! digitalRead(33);
    delay(20);
    int SensorGas = ! digitalRead(35);
    delay(20);
    int Reset = ! digitalRead(37);
    delay(20);

  
  

    
    //------------ SE O SENSOR DE TEMPERATURA FOR ATIVO  ------------///
    if (SensorTemp == 1 and Reset2 == 1) {

      Temperatura = 1;
      EEPROMWriteInt(0, Temperatura);       // Escreve na Posição 0 e 1 da EEPROM
      Reset2 = 0;
      Gate = 0;

      digitalWrite(43, LOW);     // Aciona Sirene
      digitalWrite(47, LOW);    // Aciona o Dumper
      digitalWrite(49, LOW);   // Aciona Exaustão
      digitalWrite(51, LOW);  // Desliga Ar Condicionado
      digitalWrite(53, LOW); // Shopping

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("********FOGO********");
      lcd.setCursor(3, 1);
      lcd.print("EVACUAR O LOCAL");
      lcd.setCursor(0, 3);
      lcd.print("DISPARO EM: ");


      BloqueioResult = Bloqueio();

      if(BloqueioResult == 1){
        digitalWrite(45, LOW);    // Aciona o Co2
        Co2 = 1;
        EEPROMWriteInt(8, Co2);  // Escreve na Posição 8 e 9 da EEPROM
        
        }

        if(BloqueioResult == 0){

          digitalWrite(45, HIGH); // Mantém o Co2 desligado
        }

    }


    //------------ SE O ACIONAMENTO MANUAL FOR ATIVO  ------------//
    if (AcManual == 1 and Reset2 == 1) {

      Acman = 1;
      EEPROMWriteInt(2, Acman);       // Escreve na Posição 2 e 3 da EEPROM
      Reset2 = 0;
      Gate = 0;

      digitalWrite(43, LOW);     // Aciona Sirene
      digitalWrite(47, LOW);    // Aciona o Dumper
      digitalWrite(49, LOW);   // Aciona Exaustão
      digitalWrite(51, LOW);  // Desliga Ar Condicionado
      digitalWrite(53, LOW); // Shopping

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("********FOGO********");
      lcd.setCursor(3, 1);
      lcd.print("EVACUAR O LOCAL");
      lcd.setCursor(0, 3);
      lcd.print("DISPARO EM: ");

      
      BloqueioResult = Bloqueio();

      if(BloqueioResult == 1){
        digitalWrite(45, LOW);    // Aciona o Co2
        Co2 = 1;
        EEPROMWriteInt(8, Co2);  // Escreve na Posição 8 e 9 da EEPROM
        
        }

      if(BloqueioResult == 0){

        digitalWrite(45, HIGH); // Mantém o Co2 desligado
        }

    }

    //------------ SE O TUBO SENSOR DISPARAR  ------------//
    if (TuboSensor == 1) {

      Saponif = 1;
      EEPROMWriteInt(4, Saponif);       // Escreve na Posição 4 e 5 da EEPROM
      Reset2 = 0;
      Gate = 0;

      digitalWrite(43, LOW);     // Aciona Sirene
      digitalWrite(47, LOW);    // Aciona o Dumper
      digitalWrite(49, LOW);   // Aciona Exaustão
      digitalWrite(51, LOW);  // Desliga Ar Condicionado
      digitalWrite(53, LOW); // Shopping

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("********FOGO********");
      lcd.setCursor(3, 1);
      lcd.print("EVACUAR O LOCAL");
      lcd.setCursor(0, 3);
      lcd.print("SAPONIF DISPARADO");

    }

    //------------ SE O SENSOR DE GÁS DISPARAR  ------------// 
    if (SensorGas == 1) {

      Gas = 1;
      EEPROMWriteInt(6, Gas);       // Escreve na Posição 6 e 7 da EEPROM
      Reset2 = 0;
      Gate = 0;

      digitalWrite(43, LOW);     // Aciona Sirene
      digitalWrite(47, LOW);    // Aciona o Dumper
      digitalWrite(49, LOW);   // Aciona Exaustão
      digitalWrite(51, LOW);  // Desliga Ar Condicionado
      digitalWrite(53, LOW); // Shopping

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("********FOGO********");
      lcd.setCursor(3, 1);
      lcd.print("EVACUAR O LOCAL");
      lcd.setCursor(0, 3);
      lcd.print("VAZAMENTO DE GAS");
    }




    //------------ SE O Co2 FOR DISPARADO MANUALMENTE  ------------//
    if (Cman == 1) {

      Co2 = 1;
      EEPROMWriteInt(8, Co2);       // Escreve na Posição 8 e 9 da EEPROM
      Cman2 = 1;
      EEPROMWriteInt(12, Cman2);   // Escreve na Posição 12 e 13 da EEPROM
      Reset2 = 0;
      Gate = 0;

      digitalWrite(43, LOW);     // Aciona Sirene
      digitalWrite(47, LOW);    // Aciona o Dumper
      digitalWrite(49, LOW);   // Aciona Exaustão
      digitalWrite(51, LOW);  // Desliga Ar Condicionado
      digitalWrite(53, LOW); // Shopping

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("********FOGO********");
      lcd.setCursor(3, 1);
      lcd.print("EVACUAR O LOCAL");
      lcd.setCursor(3, 2);
      lcd.print("DISPARO LOCAL");
      lcd.setCursor(6,3);
      lcd.print("DO CO2");

    }

    //------------ SE O RESET PARCIAL FOR ACIONADO  ------------//
    if ((Reset == 1 and Reset2 == 0) or Gate == 1){

      Reset2 = 1;
      Gate = 1;
      EEPROMWriteInt(10, Gate);      // Escreve na Posição 10 e 11 da EEPROM

      digitalWrite(43, HIGH);      // Desliga sirene
      digitalWrite(45, HIGH);     // Co2
      digitalWrite(47, HIGH);    // Dumper
      digitalWrite(49, HIGH);   // Exaustão
      digitalWrite(51, HIGH);  // Shopping
      digitalWrite(53, HIGH); // Ar condionado



      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("--CENTRAL ACIONADA--");

      //------------ SEQUÊNCIA DE VERIFICAÇÃO DE QUAIS SENSORES DISPARARAM  ------------//

      // S. TEMPERATURA
      if (Temperatura == 1 and (Locker2 == 0 and Locker3 == 0)){
        lcd.setCursor(0, 1);
        lcd.print("S.TEMP: 1"); 
        Locker1 = 1;

      }
      
      // AC. MANUAL
      else if(Acman == 1 and (Locker1 == 0 and Locker3 == 0)){
        lcd.setCursor(0, 1);
        lcd.print("AC.MAN: 1");
        Locker2 = 1;
      }

      
      // DISPARO LOCAL
      else if(Cman2 == 1 and (Locker2 == 0 and Locker1 == 0)){
        lcd.setCursor(0, 1);
        lcd.print("DISPARO LOCAL: 1");
        Locker3 = 1;
        }
      else{}

        

      // DET. GAS
      if (Gas == 1 and (Temperatura == 0 and Acman == 0 and Cman2 == 0 and Saponif == 0)) {
        lcd.setCursor(0, 1);
        lcd.print("DET.GAS: 1");
      }
      else if((Temperatura == 1 or Acman == 1 or Cman2 == 1 or Saponif == 1)and Gas == 1 ){
      lcd.setCursor(0, 2);
      lcd.print("DET.GAS: 1");
      }
      
      // SAPONIFICANTE
      if (Saponif == 1 and Temperatura == 0 and Acman == 0 and Acman == 0 and Cman2 == 0) {
        lcd.setCursor(0, 1);
        lcd.print("SAPONIF: 1");
      }
      else if ((Temperatura == 1 or Acman == 1 or Cman2 == 1) and Saponif == 1 and Gas == 0) {
        lcd.setCursor(0, 2);
        lcd.print("SAPONIF: 1");
      }
      else if (Gas == 1 and Saponif == 1) {
        lcd.setCursor(11 , 2);
        lcd.print("SAPONF: 1");
      }

      // Co2
      if (Co2 == 1) {
        lcd.setCursor(0, 3); // Co2
        lcd.print("Co2: 1");

        lcd.setCursor(7, 3); // Resposta de carregamento
        lcd.print("RECARGA: SIM");
      }

      else if (Co2 == 0) {
        lcd.setCursor(0, 3); // Co2
        lcd.print("Co2: 0");

        lcd.setCursor(7, 3); // Resposta de carregamento
        lcd.print("RECARGA: NAO");
      }

      setMillis(0);
      do{
          
        MillisAtual = millis();

        char Digito;                    // Caracter lido após ser digitado no teclado
        char DigitoRecebido[1];

        DefTecladoMatriz();
    
        Digito = keypad.getKey(); // Armazena a leitura das teclas
        DigitoRecebido[0] = Digito;

        if (DigitoRecebido[0] == '*'){

          lcd.clear();
          MasterResult = Teclado();
     
          DigitoRecebido[0] = '\0';
        }
      
        // EXCLUIR O MASTER RESET VIA PINO DIGITAL APÓS O FIM DOS TESTES
        ResetMaster = ! digitalRead(24);
      
        if(ResetMaster == 1){
        
          MasterResult = FuncMasterReset();
        }

       int SensorTemp = ! digitalRead(27);
       delay(20);
       int AcManual = ! digitalRead(29);
       delay(20);
       int Cman = ! digitalRead(31);
       delay(20);
       int TuboSensor = ! digitalRead(33);
       delay(20);
       int SensorGas = ! digitalRead(35);
       delay(20);
    
       if(SensorTemp == 1 or AcManual == 1 or TuboSensor == 1 or SensorGas == 1 or Cman == 1){

         setMillis(12000);
         MillisAtual == millis(); 
        }
      
      }while(MillisAtual <= 10000);
    
      if(MasterResult == 0){
        //delay(10000);
    
      //------------ MENSAGEM DE CONTATO A R8X PARA MANUTENÇÃO  ------------//

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CONTACTAR R8X SIST.");

      lcd.setCursor(0, 1);
      lcd.print("P/ NORMALIZ. A CEN-");

      lcd.setCursor(0, 2);
      lcd.print("TRAL WWW.R8X.COM.BR");
      lcd.setCursor(2, 3);
      lcd.print("TEL(21)2501-3130");

      //delay(10000);

      setMillis(0);
      do{

        MillisAtual = millis();

        char Digito;                    // Caracter lido após ser digitado no teclado
        char DigitoRecebido[1];

        DefTecladoMatriz();
        Digito = keypad.getKey(); // Armazena a leitura das teclas
        DigitoRecebido[0] = Digito;

        if (DigitoRecebido[0] == '*'){

          lcd.clear();
          MasterResult = Teclado();
      
          DigitoRecebido[0] = '\0';
          }
      
        // EXCLUIR O MASTER RESET VIA PINO DIGITAL APÓS O FIM DOS TESTES
      
        ResetMaster = ! digitalRead(24);
        if(ResetMaster == 1){
      
          MasterResult = FuncMasterReset();
          
        }

        int SensorTemp = ! digitalRead(27);
        delay(20);
        int AcManual = ! digitalRead(29);
        delay(20);
        int Cman = ! digitalRead(31);
        delay(20);
        int TuboSensor = ! digitalRead(33);
        delay(20);
        int SensorGas = ! digitalRead(35);
        delay(20);
    
        if(SensorTemp == 1 or AcManual == 1 or TuboSensor == 1 or SensorGas == 1 or Cman == 1){

          setMillis(12000);
          MillisAtual == millis(); 
          }
                 
        }while(MillisAtual <= 10000);
        }
      }
    } while (MasterResult == 0);
}
