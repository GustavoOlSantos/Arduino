void EnvioPhP(int Os, String OSstr){
  
  //=> Inclui novamente a biblioteca local para o display I2C
  #include "LiquidCrystal_I2C.h"


  //=> Pinos I2C para a Tela 16x02
  byte pinSDA = 2;
  byte pinSCL = 13; 
  
  int addr = 0x27;                     // Endereço da Tela (0x27 or ox3F)
  LiquidCrystal_I2C lcd(addr, 16, 2); // Objeto para a Tela
  TwoWire Wire0 = TwoWire(0);        // Habilitando o segundo set de pinos I2C (A câmera usa o primeiro Set)

  //=> Reinicia a tela parea garantir funcionamento e liga a tela mais uma vez
  lcd.init();
  lcd.backlight();
  
  //=> Cria os Clientes para a comunicação WiFi e para os protocolos HTTP(S) 
  WiFiClient clientt;
  HTTPClient https;
  clientt.setTimeout(15000); // Seta 15s para o Timeout no envio

  bool isBegin = https.begin(clientt, serverName);

  if (isBegin){
  
    //=> Informa para a header o tipo de informação a ser enviada
    https.addHeader("Content-Type", "application/x-www-form-urlencoded");    
    String httpRequestData;
    
    httpRequestData = "api_key="+apiKeyValue+"&location="+setor+"&num_os="+OSstr+"";

    //=> Imprime a frase montada.
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    
    //=> Envia o pedido HTTP POST 
    int httpResponseCode = https.POST(httpRequestData);

    //=> Caso a mensagem recebida seja de um envio bem sucedido
    if (httpResponseCode > 0 and httpResponseCode < 400) {
      Serial.print("Código de Resposta HTTP: ");
      Serial.println(httpResponseCode);

      String payload = https.getString();
      Serial.println(payload);


      //API Key Incorreta
      //Novo registro realizado no Banco!
      //Escrita no banco não autorizada :(!
      if(payload == "Novo registro realizado no Banco!"){
        Serial.println("\n\nEnviado com Sucesso");

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("OS Enviada ao");
        lcd.setCursor(0,1);
        lcd.print("Servidor :)");

        //=> PISCA O FLASH CASO ENVIE A ORDEM DE SERVIÇO
        digitalWrite(flash, HIGH);       // Desliga o flash
        delay(200);
        digitalWrite(flash, LOW);       // Desliga o flash
        delay(200);
        digitalWrite(flash, HIGH);     // Desliga o flash
        delay(200);
        digitalWrite(flash, LOW);     // Desliga o flash
        delay(200);
        digitalWrite(flash, HIGH);   // Desliga o flash
        delay(200);
        digitalWrite(flash, LOW);   // Desliga o flash
  
        delay(900);
        delay(600);
        delay(600);
  
        lcd.clear();
        
        }
      else if(payload == "API Key Incorreta."){
        Serial.print("\n\nErro na API Key");

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Contate o erro");
        lcd.setCursor(0,1);
        lcd.print("de API");

        delay(2000);
        delay(600);
        delay(600);
  
        lcd.clear();
        
        }
      else if(payload == "Escrita no banco não autorizada"){
        Serial.println("\n\nEnvio Fora de Ordem");

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Fora de Ordem");
        lcd.setCursor(0,1);
        lcd.print("Confira o setor");

        delay(1500);
        delay(600);
        delay(600);
  
        lcd.clear();
        }
      else{
        Serial.println("\n\nErro no mysql");

        Serial.println("\n\nEnvio Fora de Ordem");

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Erro de Envio BD");
        lcd.setCursor(0,1);
        lcd.print("Busque Ajuda");

        delay(1500);
        delay(600);
        delay(600);
        delay(600);
  
        lcd.clear();
        
        }
    }

    //=> Caso a mensagem recebida seja na faixa de erro de conexão com a URL do servidor (de 400 a 500)
    else if(httpResponseCode > 0 and httpResponseCode >= 400){
      Serial.println("Faixa de erro na URL");
      Serial.print("Código de Resposta HTTP: ");
      Serial.println(httpResponseCode);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Site nao foi");
      lcd.setCursor(0,1);
      lcd.print("Encontrado");

      delay(600);
      delay(900);
      delay(600);
      delay(600); 

      lcd.clear();
    }

    //=> Caso a mensagem recebida seja de um erro indeterminado(erro -1)
    else {
      Serial.print("Código de Erro: "); 
      Serial.println(httpResponseCode);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Envio mal sucedido ");
      lcd.setCursor(0,1);
      lcd.print("Tente Novamente :(");

      delay(600);
      delay(900);
      
      lcd.clear();
    }
    
    // Libera armazenamento
    https.end();
    
    return;
  } 

  else{

    Serial.print("\n\n=====================================================================================\n\n");
    Serial.println("Erro Crítico:");
    Serial.println("FALHA AO INICIAR O HTTP.BEGIN");
    Serial.println("Reiniciando dispositivo...");
    
    return;
    
    }
}
