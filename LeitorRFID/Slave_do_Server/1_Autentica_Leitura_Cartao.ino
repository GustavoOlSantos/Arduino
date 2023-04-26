void Sensor1(){
        
  Serial.println(F("\nCartão Reconhecido."));

  //=> Variáveis para a Autenticação da leitura    
  char Leitura[5];
  byte sector         = 1;
  byte blockAddr      = 4;
  byte trailerBlock   = 7;
  MFRC522::StatusCode status;
  byte buffer1[18];
  byte size = sizeof(buffer1);
 
  // Autentica a Leitura usando key A
  status = (MFRC522::StatusCode) Leitor1.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(Leitor1.uid));

  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Autenticação falhou, erro: "));
    Serial.println(Leitor1.GetStatusCodeName(status));

    //lcd.clear();
    //lcd.setCursor(0,0);
    //lcd.print("ERRO!");
    //lcd.setCursor(0,1);
    //lcd.print("Tente Novamente");

    delay(1000);
    
    return;
  }

  status = (MFRC522::StatusCode) Leitor1.MIFARE_Read(blockAddr, buffer1, &size);

  // Verifica se houve erros
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Leitura falhou, erro: "));
    Serial.println(Leitor1.GetStatusCodeName(status));
    
    //lcd.clear();
    //lcd.setCursor(0,0);
    //lcd.print("ERRO!");
    //lcd.setCursor(0,1);
    //lcd.print("Tente Novamente");

    delay(1000);
    
    return;
  }

  Serial.print(F("\nOS: "));
  int OS = LeituraDeOS(buffer1); 
  Serial.print("\n\n");
  
  // O número da OS deve possuir 4 dígitos
  if(OS < 999 or OS > 9999){
      Serial.println("\n\nOS INVÁLIDA!\n");
      return;
    }

  //Término da primeira Leitura
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
// Início da Segunda Leitura

  unsigned long MillisAtual;
        
  //Aguarda o Segundo Cartão
  Serial.println(F("\nAproxime um segundo cartão para ler o setor"));

  //=> Reinicia o Leitor RFID para uma nova leitura
  Leitor1.PCD_Reset();
  Leitor1.PCD_Init();
  delay(2000);
  
  setMillis(0);
  
  do{
        
    MillisAtual = millis();
        
    if(Leitor1.PICC_IsNewCardPresent()){

      if (Leitor1.PICC_ReadCardSerial()){

        //=> Verifica com qual setor a UID do Chaveiro bate
        int LeituraUID = UIDSetor();

        //=> Se a UID do chaveiro for da Coleta
        if(LeituraUID == 0){         
        
          //=> Inicia o Arduino Leonardo como um Teclado
          Keyboard.begin();
          Keyboard.print(OS);
        
          Keyboard.write(KEY_TAB);

          Keyboard.print("Coleta");

          Keyboard.write(KEY_RETURN);
          Keyboard.write(KEY_LEFT_ARROW);
    
          Keyboard.end();
          //=> Encerra a operação do modo teclado
//-------------------------------------------------------
          //=> Atualiza as leituras
          OSAtual = OS;
            
          //=> Salva a leitura na EEPROM           
          EEPROMWriteInt(582, LeituraUID); // Setor que a OS está
          EEPROMWriteInt(580, OSAtual);   // OS trabalhada

          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(OSAtual);
          lcd.setCursor(0,1);
          lcd.print("Coleta");
          
          return 0;         
          
        }
        
        //=> Se a UID do chaveiro for da Conferência-2 
        else if(LeituraUID == 1){

          //=> Inicia o Arduino Leonardo como um Teclado
          Keyboard.begin();
          Keyboard.print(OS);
      
          Keyboard.write(KEY_TAB);

          Keyboard.print("Conferência-2");

          Keyboard.write(KEY_RETURN);
          Keyboard.write(KEY_LEFT_ARROW);
        
  
          Keyboard.end();
          //=> Encerra a operação do modo teclado
//---------------------------------------------------------------------            
          //=> Atualiza as leituras
          OSAtual = OS;
          
          //=> Salva a leitura na EEPROM
          EEPROMWriteInt(582, LeituraUID); // Setor que a OS está
          EEPROMWriteInt(580, OSAtual);   // OS trabalhada

          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(OSAtual);
          lcd.setCursor(0,1);
          lcd.print("Conferencia-2");
          
          return 0;                    
      } 

        //=> Se a UID do chaveiro for da aprovação
        else if(LeituraUID == 2){
          
          //=> Inicia o Arduino Leonardo como um Teclado
          Keyboard.begin();
          Keyboard.print(OS);
        
          Keyboard.write(KEY_TAB);

          Keyboard.print("Aprovado");
    
          Keyboard.end();
          //=> Encerra a operação do modo teclado
// --------------------------------------------------------------------------------
          //=> Atualiza as leituras
          OSAtual = OS;
          
          //=> Salva a leitura na EEPROM
          EEPROMWriteInt(582, LeituraUID); // Setor que a OS está
          EEPROMWriteInt(580, OSAtual);   // OS trabalhada

          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(OSAtual);

          lcd.setCursor(0,1);
          lcd.print("Aprovado!");
           
          return 0;
          
        }
        
        //=> Se A UID do chaveiro não coincindir com nenhum setor
        else if (LeituraUID == 7){
            
          Serial.println(F("\n\nUID DESCONHECIDO"));
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Sem Setor");
          lcd.setCursor(0,1);
          lcd.print("Tente Novamente");
    
          delay(1000);
          return 1;
        }


        else{}
      }
    }
    //Caso o Tempo limite passe e não haja leitura
    else if (MillisAtual > 15000){

      Serial.println(F("Tempo Excedido"));

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tempo excedido");
      lcd.setCursor(0,1);
      lcd.print("Tente Novamente");
      
      delay(1000);
      return 1;
      
    }
  } 
   while(MillisAtual <= 17000);
}

      
void setMillis(unsigned long ms){
    extern unsigned long timer0_millis;
    ATOMIC_BLOCK (ATOMIC_RESTORESTATE) {
        timer0_millis = ms;
    }
}
