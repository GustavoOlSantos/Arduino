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

  //=> Inicia o protocolo de Envio -------------------------------------------------------------------------------
  Serial.print("Se preparando para enviar a OS para o Servidor...\n\n");

  Serial.print  ("Ordem de Serviço a ser enviada p/ o Servidor    : ");
  Serial.println(OS);
  Serial.print  ("Setor onde a OS se encontra                     : Conferência-1"); //Coferência-1
  Serial.print("\n\n");

  String Ordem = String(OS); //=> Converte a OS em inteiro para String
  
  Serial.println("<" + Ordem + "-" + ClientType + ">");
  myData.LeituraOSSetor = "<" + Ordem + "-" + ClientType + ">";

  EEPROMWriteInt(580, OS);

  
  // Envia a Mensagem via ESP-NOW
  esp_now_send(OrcamentoAddress, (uint8_t *) &myData, sizeof(myData));
  

  return;
      
}
