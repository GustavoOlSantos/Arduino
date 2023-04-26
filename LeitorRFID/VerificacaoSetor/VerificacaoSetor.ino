//------------------------------------------------------------------------------------
// INCLUSÃO DAS BIBLIOTECAS NECESSÁRIAS
//------------------------------------------------------------------------------------

// PINAGEM I2C ARDUINO MEGA
// SDA: 20 
// SCL: 21 

//=> Padrôes C
#include <stdio.h>           
#include <stdlib.h>           
#include <string.h>

//=> Operações especiais
#include <EEPROM.h>      //=> Acesso a memória não volátil
#include <Wire.h>       //=> Envio de informações via Cabeamento

//------------------------------------------------------------------------------------
// DEFINIÇÕES DE PINOS E VARIÁVEIS DA MEMÓRIA
//------------------------------------------------------------------------------------

//=> Declarações de funções
void EEPROMWriteInt(int address, int value); // Responsável por escrita de inteiros na eeprom, ocupa 2 Bytes
int  EEPROMReadInt(int address);            // Lê 2 Bytes e os une, retornando ao código o número inteiro armazenado

//=> Variáveis para a Verificação.
char MensagemAtual[30]    = "ATUAL\0";
char MensagemAnterior[30] = "ANTERIOR\0";

int Verificado = 0;

// 0 => SIM
// 1=> NÃO

  
// ===========================================================================================================================
// => INICIALIZAÇÃO DO CÓDIGO
// ===========================================================================================================================

void setup() {
  
  //=> Inicializações ----------------------------------------------------------------
  Serial.begin(115200);             //=> Inicia o monitor Serial 
  Wire.begin(44);                  //=> Inicia o protocolo I2C
  delay(20);

  //=> Chamado para Salvar as Mensagens recebidas via I2C ---------------------------
  Wire.onReceive(Preparativos);   //=> Recebe a mensagem do ESP2866

  //=> Declaração de um pino de entrada para controlar a EEPROM ---------------------
  pinMode(2, INPUT_PULLUP);
  
}

// ===========================================================================================================================
// => INICIO DO LOOP DE VERIFICAÇÕES
// ===========================================================================================================================
void loop() {

  //=> Limpa a memória EEPROM, caso o pino 2 esteja vazio
  int Eclear = ! digitalRead(2);
  if(Eclear == 0){
    
    EEPROMCLEAR();
  }

  //=> Caso o fio esteja devidamente conectado
  else{

    //=> Caso a OS recebida do Servidor não tenha sido conferida
    if(Verificado == 1){

      //=> Faz a conferência, envia e relata
      Verificador();
      Verificado = 0;
    }

    // Se as Mensagens divergirem, envia a nova para a anterior
    if (strcmp(MensagemAtual, MensagemAnterior) != 0){
        
      strcpy(MensagemAnterior, MensagemAtual);
        
      Serial.println("Mensagem Atual: " + String(MensagemAtual));
      Serial.println("Mensagem Anterior: " + String(MensagemAnterior));
    }

    Serial.print("."); 
    delay(200);
  }
}

// ===========================================================================================================================
// => FIM DO LOOP
// ===========================================================================================================================

//------------ FUNÇAO PARA ESCREVER VARIÁVEIS INT NA EEPROM ------------// 

// Divide o inteiro em 2 Bytes, sendo um mais significativo que outro e os salva em endereços consecutivos
void EEPROMWriteInt(int address, int value) {
   byte hiByte = highByte(value);
   byte loByte = lowByte(value);

   EEPROM.write(address, hiByte);
   EEPROM.write(address + 1, loByte);   
}
  

//------------ FUNÇAO PARA LER VARIÁVEIS INT NA EEPROM ------------// 

// Agrupa o Byte registrado no endereço especificado com o do posterior e retorna uma palavra contendo os bytes unidos 
int EEPROMReadInt(int address) {
   byte hiByte = EEPROM.read(address);
   byte loByte = EEPROM.read(address + 1);
   
   return word(hiByte, loByte); 
}

//------------ FUNÇAO PARA LIMPAR A MEMÓRIA EEPROM ------------// 

// Define todos os endereços como 0
void EEPROMCLEAR(){
  
  for (int i = 0 ; i < 1023 ; i++) {
    EEPROM.write(i, 0);
  }

  Serial.println(F("Memória EEPROM Limpa com sucesso!s"));
}
