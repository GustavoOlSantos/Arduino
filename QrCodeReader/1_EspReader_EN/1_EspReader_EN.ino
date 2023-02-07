/*
 * --------------- DEVELOPER INFOS ---------------
 * => AUTHOR:  Gustavo Oliveira Ferreira dos Santos
 * => GITHUB: https://github.com/GustavoOlSantos
 * => DATE:   OCT.2022 - JAN.2023
 * 
 * --------------- PROJECT INFO ---------------
 * => IDE Version:: Arduino 1.8.19
 * => Board: ESP32 CAM
 * => Board Selected in IDE: AI THINKER ESP32-CAM
 * => Board Package Version: 1.0.2
 * 
 * => Reference: https://github.com/fustyles/Arduino
 * => Pathway: Arduino/ESP32-CAM_QRCode_Recognition/ESP32QRCodeReader/
 */
 
// -------------------------------------------------------------------
// LIBRARIES
// -------------------------------------------------------------------

//=> C++ Basic Libraries 
#include <stdio.h>
#include <stdlib.h>
#include <Arduino.h>

//=> Comm protocols Libraries
#include <Wire.h>

//=> WiFi and https protocols Libraries
#include <WiFi.h>
#include <WiFiClientSecure.h> 
#include <HTTPClient.h>

//=> Local Libriries/Files
#include "LiquidCrystal_I2C.h"
#include "ESP32CameraPins.h"
#include "ESP32QRCodeReader.h"
#include "soc/soc.h"             
#include "soc/rtc_cntl_reg.h"
#include "quirc.h"

// -------------------------------------------------------------------
// PINS, DEFINITIONS, DECLARATIONS AND WIFI/SERVER VARIABLES
// -------------------------------------------------------------------

//=> Board pins definiitions
#define flash 4                                      //=> ESP-CAM Flash Pins
#define resetB 14                                   //=> Reset Pin
ESP32QRCodeReader reader(CAMERA_MODEL_AI_THINKER); //=> Board Model

//=> Global variables
struct QRCodeData qrCodeData;
int count = 0;

//=> I2C pins for 16x02 Display
byte pinSDA = 2;    //=> SDA Display pin connected on Pin IO2
byte pinSCL = 13;  //=> SCL Display pin connected on Pin IO13
int addr = 0x27;  // Display Address (0x27 or ox3F)

//=> Display Object
LiquidCrystal_I2C lcd(addr, 16, 2); 
TwoWire Wire0 = TwoWire(0);        // Enable the secondary I2C pins Set (Since the camera use the first one)

// ------------------ WiFi connection Variables ------------------

const char* ssid     = "YourWifi" ;
const char* password = "YourPassword";

IPAddress local_IP    (192, 168, 100, 183); //=> Choose a IP Address
IPAddress gateway     (192, 168, 100, 1);  //=> Gateway IP Address
IPAddress subnet      (255, 255, 255, 0); //=> Subnet Mask
IPAddress primaryDNS  (8, 8, 8, 8);      //=> Primary DNS
IPAddress secondaryDNS(8, 8, 4, 4);     //=> Secondary DNS

// ------------------ functions the NEED to be EXPLICITLY stated ------------------

void *ps_malloc(size_t size);               //=> For Memory Allocation
void *ps_calloc(size_t n, size_t size);    //=> For Memory Displacement

// ------------------ Variables for Server connection ------------------
const char* serverName     = "http://192.168.0.102/esp/post_sensor_data.php";   //=> Website who receives the HTTP POst Request (LocalHost)
String      apiKeyValue    = "keykey";                                         //=> Password that shoud be equal here and in the Website
String      ValueToSend          = "1";                                       //=> Some Data you want to send alongside with the data the board reads from a QR Code
   
// =======================================================================================================================
// BOARD SETUP
// =======================================================================================================================   

void setup() {
  
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  // Controla o desligamento por instabilidade de alimentação

  pinMode     (flash, OUTPUT);          //=> Flash Pin as Output
  pinMode     (resetB, INPUT_PULLUP);  //=> Reset Button
  digitalWrite(flash, LOW);           //=> Turn the flash Off
    
  //=> SETUPS
  Serial.begin(115200);            //=> Serial Monitor (115200 rate) Startup
  Wire.begin(pinSDA, pinSCL);     //=> I2C Communication Startup
  Wire.setClock(10000);          //=> Define a Clock for transmission
  

  // ------------------ Configuration and WiFi Startup ------------------
  
  Serial.println("Configuring network...");
  
  while(!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)){ Serial.print("*"); }
  Serial.println("network configured successfully");
    
  Serial.setDebugOutput(true);  //=> Enable the Diagnostic 
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);           
  delay(1000);             
    
  Serial.print("Connecting to:  ");     Serial.println(ssid);  

  unsigned long MillisInicial = millis();
  unsigned long MillisAtual;
  
  while (WiFi.status() != WL_CONNECTED) {
    
    delay(200); 
    Serial.print("---");
    
    MillisAtual = millis();

    if(MillisAtual - MillisInicial >= 6000){

      Serial.println("\n\nConnection TimeOut, restarting...");
      Serial.print("======================================================================\n\n");
      ESP.restart(); //=> Restart the ESP
    }

    int reset = ! digitalRead(resetB);

    if(reset == 1){

      Serial.println("\n\nReset Button pressed\n");
      ESP.restart();
    }
  }
  
  Serial.println("");
  Serial.println("Connected to                    : " + String(WiFi.SSID()));
  Serial.println("Signal Strenght                 : " + String(WiFi.RSSI()) + " dBm");
  Serial.println("Router BSSID                    : " + String(WiFi.BSSIDstr()));
  Serial.print  ("MAC Address                     : ");
  Serial.println(String(WiFi.macAddress()));
  Serial.print  ("IP Address of this Board      : ");
  Serial.println(WiFi.localIP());

  lcd.init(); //=> Display LCD Startup

  // ------------------ Camera as QR Code Reader Startup ------------------

  //=> If the initialization is successfull
  if(!reader.setup()){
    
    Serial.println("Initializing QRCode Reader...");
    reader.begin();
    Serial.println("QRCode Reader initialized successfully.");
    delay(20);

    //=> Blink the flash as a Warning
    digitalWrite(flash, HIGH);    
    delay(200);                  
    digitalWrite(flash, LOW);  
    delay(200);
  
    lcd.backlight();         //=> Turn On the Display Backlight
  }

  //=> If something goes wrong
  else{

      Serial.print("\n\nCannot start the camera, restarting...");
      Serial.print("======================================================================\n\n");
      
      ESP.restart();
  }
}

// =======================================================================================================================
// MAIN LOOP
// =======================================================================================================================   

void loop() {

  if (WiFi.status() != WL_CONNECTED){
    
    Serial.println("Connection lost, trying to Recconect...");
    WiFi.disconnect();
    WiFi.reconnect();

    delay(200);
    
  }

  int reset = ! digitalRead(resetB); //=> Resedt Button Reading

  // Rebbot the Esp if the button is pressed
  if(reset == 1){
    ESP.restart();  
  }

  // connected
  else{

    if(count < 2){
      lcd.setCursor(0, 0);
      lcd.print("Ready to Read   ");
      lcd.setCursor(0,1);
      lcd.print("the QR Code ");
    }
    
    //=> If a Qr Code is Recognized       ------------------------------------------------------------------------------
    if (reader.receiveQrCode(&qrCodeData, 100)) {
  
      //=> And if the QRCode IS VALID
      if (qrCodeData.valid) {
        
        String qrcode = (const char *)qrCodeData.payload;

          Serial.print  ("Data that will be sent to the Server             : ");
          Serial.println(qrcode);
          Serial.print("\n\n" );

          digitalWrite(flash, LOW); 
          
          //=> Call the fuction that has all the http(s) protocols
          PostPhP(qrcode);
          count = 0;
        }
      }
      //=> If the QR Code is invalid --------------------------------------------------------------------------------
      else {

        Serial.print("Invalid: ");
        String qrcode = (const char *)qrCodeData.payload;
        Serial.print(qrcode);
        digitalWrite(flash, HIGH); 
      }
    }
    delay(300);
    count++;
  }
}
