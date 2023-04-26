//------------------------------------------------------------------------------------
// INCLUSÃO DAS BIBLIOTECAS NECESSÁRIAS
//------------------------------------------------------------------------------------

//=>Padrões para C++
#include <stdio.h>
#include <stdlib.h>
      
//=> Operações especiais
#include <EEPROM.h>                // Permite o uso da memória não volátil (EEPROM)
#include <util/atomic.h>          // Permite a manipulaçao do Millis()

//=> Para os periféricos e leitores
#include <Wire.h>              // Biblioteca Para Comunicação I2C (Esse Arduino Servirá como Escravo)
#include <SPI.h>              // Biblioteca para Comunicação SPI (Protocólo ICSP)
#include <LiquidCrystal.h>   // Biblioteca da Tela LCD
#include <MFRC522.h>        // Biblioteca do Leitor RFID MFRC-522
#include <Keypad.h>        // Biblioteca para o uso do teclado Matricial
#include <Keyboard.h>     // Biblioteca Para Arduino Leonardo ser um teclado

//------------------------------------------------------------------------------------
// DEFINIÇÕES DE PINOS, VARIÁVEIS MAIS IMPORTANTES E FUNÇÕES
//------------------------------------------------------------------------------------

//=> Pinos
#define RST_PIN1     A2       // Pino de Reset para o Leitor RFID (configurável)
#define SS_PIN1      A1      // Pino Slave Select para o Leitor RFID (configurável)
#define Button       A0    // Pino da Conexão do Botão

//=> Verificadores de Operação
boolean OpAnterior = 0;
boolean OpAgora;

//=> Declarações de funções
void EEPROMWriteInt(int address, int value); // Responsável por escrita de inteiros na eeprom, ocupa 2 Bytes
int  EEPROMReadInt(int address);            // Lê 2 Bytes e os une, retornando ao código o número inteiro armazenado

//=> Variáveis Para exibir no Display (e seus endereços na EEPROM)
int SetorAtual; // Pega a info do (582)
int OSAtual;     // Sempre salva no (580)

//------------------------------------------------------------------------------------
// DECLARAÇÃO DE OBJETOS E KEYS PARA LEITORES, SENSORES E PERIFÉRICOS
//------------------------------------------------------------------------------------

//=> Para o Leitor RFID mfrc522
MFRC522 Leitor1(SS_PIN1, RST_PIN1);
MFRC522::MIFARE_Key key;

//=> Para Tela LCD
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); // Definição dos pinos digitais da tela
  
//====================================================================================
// INICIALIZAÇÃO DO CÓDIGO
  
void setup() {

  pinMode(Button, INPUT_PULLUP);
  
  Serial.begin(115200);    //=> Inicia o monitor Serial       
  SPI.begin();            //=> Inicia a comunicação SPI
  lcd.begin(16, 2);      //=> Inicia o Display LCD 16x2
  Leitor1.PCD_Init();   //=> Inicia o leitor RFID MFRC522
  Wire.begin(1);       //=> Inicia a comunicação I2C
  
  Wire.onReceive(WifiDadosParaExcel); 

  //=> Resgata o nº de OS e o setor trabalhado
  OSAtual = EEPROMReadInt(580);

  //=> Imprime o nº de OS na tela
  lcd.clear();

  //=> Prepara a Key A e Key B, para Leitura(ou escrita) nas tags
  for (byte i = 0; i < 6; i++) {
      key.keyByte[i] = 0xFF;
      // Usa a chave FFFFFFFFFFFFh 
  }

  
}

//====================================================================================

void loop() {

  //=> FAZ LEITURA
  if(OpAnterior == false){
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Leia a OS");
    lcd.setCursor(0,1);
    lcd.print("de um Cartao");

    delay(200);
    do{
      
      //=> Verifica se o botão foi pressionado
      OpAgora = !digitalRead(Button);
      //delay(50);
      if(OpAgora != OpAnterior){
        //=>  Se sim, Muda operação
        OpAnterior = OpAgora;
        Serial.println("Operação de Escrita"); 
        return;
        }

    //=> Verifica se há um cartão na frente do leitor
    if(Leitor1.PICC_IsNewCardPresent()){

      if (Leitor1.PICC_ReadCardSerial()){
      
        // Passa pelo protocolo de leitura do cartão
        Sensor1();

        // Reinicia o Leitor RFID
        Leitor1.PCD_Reset();
        setup();
        delay(1500);

        return;
          
        }   
      }

      // Reinicia o código caso não haja nenhum cartão, evitando todo o processo e leituras desnecessárias
      else{
        
        Leitor1.PCD_Reset();
        Leitor1.PCD_Init();
        return;
      }
    }
    while(OpAnterior == OpAgora);
  }
  
 // FAZ ESCRITA
  if(OpAnterior == true){    

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Cadastre uma");
    lcd.setCursor(0,1);
    lcd.print("OS no Cartao");

    delay(200);
    do{

      OpAgora = digitalRead(Button);
      //delay(50);
      if(OpAgora != OpAnterior){
        OpAnterior = OpAgora;
        Serial.println("Operação de leitura"); 
        return;
      }

    //=> Verifica se há um cartão na frente do leitor
    if(Leitor1.PICC_IsNewCardPresent()){

      if (!Leitor1.PICC_ReadCardSerial()){

        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Erro. Por favor");
        lcd.setCursor(0,1);
        lcd.print("Tente Novamente");

        delay(1000);
        
        Leitor1.PCD_Reset();
        Leitor1.PCD_Init();
        return;
      }

      Serial.println("");

      lcd.clear();
      lcd.setCursor(0,0);
      
      lcd.print("Cartão aceito!");
    
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Nao o afaste!!");
    
      delay(1500);
      
      byte buffer[34];
      MFRC522::StatusCode status;
      byte len;
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("OS: ");
    
      Serial.print("\n\nCartão Aprovado\nEntrando na escrita da OS Via Tecladinho\n\n");
      for(byte i = 0; i > 20; i++) buffer[i] = ' ';
      
      EscreveOS(); 
        
      // Reinicia o Leitor RFID
      Leitor1.PCD_Reset();
      Leitor1.PCD_Init();
      delay(1500);

      return;        
           
      }

      // Reinicia o código caso não haja nenhum cartão, evitando todo o processo e leituras desnecessárias
      else{
        
        Leitor1.PCD_Reset();
        Leitor1.PCD_Init();
        return;
      }

    }
    while(OpAnterior == OpAgora);
  }
}
