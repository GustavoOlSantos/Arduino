void PostPhP(String Qrdata){
  
  //=> Inclued once again the I2C  DIsplay Library
  #include "LiquidCrystal_I2C.h"


  //=> I2C Pisn (Again)
  byte pinSDA = 2;
  byte pinSCL = 13; 
  
  int addr = 0x27;                     // Display Address (0x27 or ox3F) [Again, you get it]
  LiquidCrystal_I2C lcd(addr, 16, 2); // Display Object
  TwoWire Wire0 = TwoWire(0);        // Secondary I2C set

  //=> Reboot e turn the Display again to ensure it still working
  lcd.init();
  lcd.backlight();
  
  //=> Create the Objects for WiFi communication e HTTP(S) Protocols
  WiFiClient clientt;
  HTTPClient https;
  clientt.setTimeout(15000); // Set the TimeOut for sending data to 15s

  bool isBegin = https.begin(clientt, serverName);

  if (isBegin){
  
    //=> Tell to website the type of the data using the header
    https.addHeader("Content-Type", "application/x-www-form-urlencoded");    
    String httpRequestData;
    
    httpRequestData = "api_key="+apiKeyValue+"&location="+setor+"&num_os="+Qrdata+"";

    //=> Show the Request line
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    
    //=> Send the HTTP POST Request
    int httpResponseCode = https.POST(httpRequestData);

    //=> If the data is sent successfully to the WebSite
    if (httpResponseCode > 0 and httpResponseCode < 400) {
      Serial.print("HTTP Response: ");
      Serial.println(httpResponseCode);

      String payload = https.getString();
      Serial.println(payload);

      if(payload == "Novo registro realizado no Banco!"){
        Serial.println("\n\nEnviado com Sucesso");

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sent to the");
        lcd.setCursor(0,1);
        lcd.print("Server :)");

        //=> BLINK as warning
        digitalWrite(flash, HIGH);       
        delay(200);
        digitalWrite(flash, LOW);       
        delay(200);
        digitalWrite(flash, HIGH);     
        delay(200);
        digitalWrite(flash, LOW);     
        delay(200);
        digitalWrite(flash, HIGH);   
        delay(200);
        digitalWrite(flash, LOW);   
  
        delay(900);
        delay(600);
        delay(600);
  
        lcd.clear();
        
        }
      else if(payload == "API Key Incorreta."){
        Serial.print("\n\nIncorrect API Key");

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Wrong");
        lcd.setCursor(0,1);
        lcd.print("API Key");

        delay(2000);
        delay(600);
        delay(600);
  
        lcd.clear();
        
        }
    }

    //=> If couldn't found the Website (de 400 a 500)
    else if(httpResponseCode > 0 and httpResponseCode >= 400){
      Serial.println("Url error Span");
      Serial.print("Código de Resposta HTTP: ");
      Serial.println(httpResponseCode);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("not");
      lcd.setCursor(0,1);
      lcd.print("found");

      delay(600);
      delay(900);
      delay(600);
      delay(600); 

      lcd.clear();
    }

    //=> IF the code is undefined
    else {
      Serial.print("Código de Erro: "); 
      Serial.println(httpResponseCode);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("couldn't send ");
      lcd.setCursor(0,1);
      lcd.print("Try again :(");

      delay(600);
      delay(900);
      
      lcd.clear();
    }
    
    // Free some storage
    https.end();
    
    return;
  } 

  else{

    Serial.print("\n\n=====================================================================================\n\n");
    Serial.println("Critical Error:");
    Serial.println("ERROR ON HTTP.BEGIN");
    Serial.println("Rebooting...");
    
    return;
    
    }
}
