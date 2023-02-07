/*
 * --------------- INFORMAÇÕES DEV ---------------
 * => AUTOR:  Gustavo Oliveira Ferreira dos Santos
 * => GITHUB: https://github.com/GustavoOlSantos
 * => DATA:   OUT.2022 - JAN.2023
 * 
 * --------------- INFORMAÇÕES PROJETO ---------------
 * => Versão da IDE: Arduino 1.8.19
 * => Placa Utilizada: ESP32 CAM
 * => Placa Selecionada na IDE: AI THINKER ESP32-CAM
 * => Versão do pacote de placas: 1.0.2
 * 
 * => Arquivos de referência: https://github.com/fustyles/Arduino
 * => Pathway: Arduino/ESP32-CAM_QRCode_Recognition/ESP32QRCodeReader/
 */
 
// -------------------------------------------------------------------
// INCLUSÃO DAS BIBLIOTECAS NECESSÁRIAS
// -------------------------------------------------------------------

//=> Bibliotecas Básicas C++
#include <stdio.h>
#include <stdlib.h>
#include <Arduino.h>

//=> Bibliotecas para protocolos de comunicação
#include <Wire.h>

//=> Bibliotecas para WiFi e protocolos http(s)
#include <WiFi.h>
#include <WiFiClientSecure.h> 
#include <HTTPClient.h>

//=> Bibliotecas/Arquivos locais
#include "LiquidCrystal_I2C.h"
#include "ESP32CameraPins.h"
#include "ESP32QRCodeReader.h"
#include "soc/soc.h"             
#include "soc/rtc_cntl_reg.h"
#include "quirc.h"

// -------------------------------------------------------------------
// DECLARAÇÕES, DEFINIÇÕES DE SENSORES E VARIÁVEIS PARA O SERVER/WIFI
// -------------------------------------------------------------------

//=> Definições da Placa
#define flash 4                                      //=> Pino do Flash do ESP-CAM
#define resetB 14                                   //=> Pino do Reset
ESP32QRCodeReader reader(CAMERA_MODEL_AI_THINKER); //=> Modelo da placa Utilizada

//=> Variáveis Globais
struct QRCodeData qrCodeData;
int cont = 0;

//=> Pinos I2C para a Tela 16x02
byte pinSDA = 2;    //=> SDA do Display ligado no Pino IO2
byte pinSCL = 13;  //=> SCL do Display ligado no Pino IO13
int addr = 0x27;  // Endereço da Tela (0x27 or ox3F)

//=> OBjeto da Tela
LiquidCrystal_I2C lcd(addr, 16, 2); // Criação do Objeto
TwoWire Wire0 = TwoWire(0);        // Habilitando o segundo set de pinos I2C (A câmera usa o primeiro Set)

// ------------------ Variáveis para a conexão com WiFi ------------------

const char* ssid     = "SeuWifi" ;
const char* password = "SuaSenha";

IPAddress local_IP    (192, 168, 100, 183); //=> Endereço de IP fixo
IPAddress gateway     (192, 168, 100, 1);  //=> Endereço de IP para Gateway
IPAddress subnet      (255, 255, 255, 0); //=> Mascara de Subnet
IPAddress primaryDNS  (8, 8, 8, 8);      //=> DNS Primária  
IPAddress secondaryDNS(8, 8, 4, 4);     //=> DNS Secundária

// ------------------ Funções que PRECISAM ser EXPLICITAMENTE declaradas ------------------

void *ps_malloc(size_t size);               //=> Para Alocamento de memória
void *ps_calloc(size_t n, size_t size);    //=> Para Deslocamennto de memória

// ------------------ Variáveis para a conexão com Servidor ------------------
const char* serverName     = "http://192.168.0.102/esp/post_sensor_data.php";   //=> Link que recebe o http post (Nesse caso, um LocalHost)
String      apiKeyValue    = "keykey";                                         //=> Senha que deve coincidir com a senha definida na web
String      setor          = "1";                                             //=> Número do setor associado a essa placa
   
// =======================================================================================================================
// INICIALIZAÇÃO DA PLACA
// =======================================================================================================================   

void setup() {
  
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  // Controla o desligamento por instabilidade de alimentação

  pinMode     (flash, OUTPUT);          //=> Define o Pino do Flash
  pinMode     (resetB, INPUT_PULLUP);  //=> Botão de reset (nem vai ser usado)
  digitalWrite(flash, LOW);           //=> Desliga o flash
    
  //=> Inicializações
  Serial.begin(115200);            //=> Monitor Serial (Taxa de 115200)
  Wire.begin(pinSDA, pinSCL);     //=> Inicia a Comunicação I2C
  Wire.setClock(10000);          //=> Define um Clock para transmissão
  

  // ------------------ Configuração e inicialização da rede WiFi ------------------
  
  Serial.println("Configurando a rede...");
  
  while(!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)){ Serial.print("*"); }
  Serial.println("Rede configurada com sucesso");
    
  Serial.setDebugOutput(true);  //=> Ativa a saída de Diagnóstico/debug
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);           
  delay(1000);             
    
  Serial.print("Se Conectando a Rede:  ");     Serial.println(ssid);  

  unsigned long MillisInicial = millis();
  unsigned long MillisAtual;
  
  while (WiFi.status() != WL_CONNECTED) {
    
    delay(200); 
    Serial.print("---");
    
    MillisAtual = millis();

    if(MillisAtual - MillisInicial >= 6000){

      Serial.println("\n\nReiniciado a placa por TimeOut na conexão");
      Serial.print("======================================================================\n\n");
      ESP.restart(); //=> Reinicia o ESP
    }

    int reset = ! digitalRead(resetB);

    // Reinicia o ESP caso o botão de RESET seja pressionado
    if(reset == 1){

      Serial.println("\n\nBOTÂO DE RESET EXTERNO PRESSIONADO\n");
      ESP.restart();
    }
  }
  
  Serial.println("");
  Serial.println("Conectado a                     : " + String(WiFi.SSID()));
  Serial.println("Força do Sinal                  : " + String(WiFi.RSSI()) + " dBm");
  Serial.println("BSSID do Roteador               : " + String(WiFi.BSSIDstr()));
  Serial.print  ("Endereço MAC do Dispositivo     : ");
  Serial.println(String(WiFi.macAddress()));
  Serial.print  ("Endereço de IP do Dispositivo : ");
  Serial.println(WiFi.localIP());

  //Adição nova para Testar o retorno de Mensagens com o Python
  lcd.init(); //=> Inicia o Display LCD

  // ------------------ Inicialização da Câmera como Leitor de QRCODE ------------------

  //=> Caso a Câmera inicialize com sucesso
  if(!reader.setup()){
    
    //reader.setDebug(true);
    Serial.println("Inicializando Leitor QRCode...");
    reader.begin();
    Serial.println("Leitor QRCode inicializado com sucesso.");
    delay(20);

    //=> Pisca o Flash como aviso
    digitalWrite(flash, HIGH);    
    delay(200);                  //=> Desliga o flash 
    digitalWrite(flash, LOW);   //=> Desliga o flash
    delay(200);
  
    lcd.backlight();         //=> Liga a luz de fundo no LCD
  }

  //=> Caso ocorra alguma falha
  else{

      Serial.print("\n\nERRO AO INICIALIZAR A CÂMERA, REINICIANOO O MICRO...");
      Serial.print("======================================================================\n\n");
      
      ESP.restart();
  }
}

// =======================================================================================================================
// REPETIÇÃO PRINCIPAL DA PLACA
// =======================================================================================================================   

void loop() {

  // Caso a Conexão com o WiFi seja perdida, tenta reconectar antes dse prosseguir
  if (WiFi.status() != WL_CONNECTED){
    
    Serial.println("Conexão Perdida, tentando reestabelecer...");
    WiFi.disconnect();
    WiFi.reconnect();

    delay(200);
    
  }

  int reset = ! digitalRead(resetB); //=> botão de reste não utilizado

  // Reinicia o ESP caso o botão de RESET seja pressionado
  if(reset == 1){

    Serial.println("\n\nBOTÂO DE RESET EXTERNO PRESSIONADO\n");
    ESP.restart();  
  }

  // Se houver conexão...
  else{

    if(cont < 2){
      lcd.setCursor(0, 0);
      lcd.print("Pronto Para Ler ");
      lcd.setCursor(0,1);
      lcd.print("um Codigo QR");
    }
    
    //=> Se a Câmera reconheceu um QRCode ------------------------------------------------------------------------------
    if (reader.receiveQrCode(&qrCodeData, 100)) {
  
      //=> E se o QRCode reconhecido FOR VÁLIDO
      if (qrCodeData.valid) {
        
        String qrcode = (const char *)qrCodeData.payload;
        int EhNum = 0; // Verifica se a String completa é um numero
        char QrConvertido[5];

         for (int i = 0; i <= 3; i++) {
         
            if(isdigit(qrcode[i])){

                QrConvertido[i] = qrcode[i];

                if(i + 1 == 4 ){
                  QrConvertido[i+1] = '\0';
                  EhNum = 1;
                  i = 6;
                }
              }

              else{
                EhNum = 0;
                i = 6;
              }
            }
        
        //=> Inicia o protocolo de Envio -------------------------------------------------------------------------------
        if(EhNum == 1){
  
          int OS = atoi(QrConvertido);
  
          Serial.print  ("Ordem de Serviço a ser enviada p/ o Servidor    : ");
          Serial.println(OS);
          Serial.print("\n\n" );

          digitalWrite(flash, LOW); 
          
          //=> Chama a função que possui os comandos e protocolos para o envio da Ordem de Serviço par o servidor
         
          EnvioPhP(OS, QrConvertido); // Com as opções para String e para Inteiros
          cont = 0;
        }

        //=> Caso não a informação do QRCode não seja uma OS Válida, considera como um QRCobaia para ajustar o Display LCD
        else{

            Serial.print("QRCode cobaia para iniciar restartar a tela");

            lcd.clear();
            delay(200);
            lcd.setCursor(0, 0);
            lcd.print("QRCode de Testes");
            lcd.setCursor(0,1);
            lcd.print("!!!!!!!!!!!!!!!!");

            String qrcode = (const char *)qrCodeData.payload;
            Serial.print(qrcode);

            digitalWrite(flash, LOW);
                     
            lcd.noBacklight();
            delay(300);
            lcd.backlight();
            delay(300);
            lcd.noBacklight();
            lcd.clear();
            delay(200);

            lcd.backlight();
        }
      }
      //=> Caso o QRCode não seja Válido --------------------------------------------------------------------------------
      else {

        Serial.print("Inválido: ");
        String qrcode = (const char *)qrCodeData.payload;
        Serial.print(qrcode);
        digitalWrite(flash, HIGH); 
      }
    }
    delay(300);
    cont++;
  }
}
