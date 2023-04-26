void EnviaOS(char OS[6]){
  
  Serial.print("\n\n");
  
  byte buffer[34];

  buffer[0] = OS[0];
  buffer[1] = OS[1];
  buffer[2] = OS[2];
  buffer[3] = OS[3];
  buffer[4] = OS[4];

  int OrdemDeServico = atoi(OS);

  for(byte i = 0; i != 4; i++){
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
 
  byte block = 4;
  byte sector         = 1;
  byte blockAddr      = 4;
  byte trailerBlock   = 7;
  byte size = sizeof(buffer);
  MFRC522::StatusCode status;
    
  //=> Tenta Autenticar 
  status = Leitor1.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(Leitor1.uid));
  if (status != MFRC522::STATUS_OK){

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Erro ao autenti-");

    Serial.print("\n\nERRO NA AUTENTICACAÇÃO!!\n\n");
    
    lcd.setCursor(0,1);
    lcd.print("car.");

    delay(1000);

    setup();
    return;
    
    }
  
  else{//=> Tenta escrever a OS no bloco

  status = Leitor1.MIFARE_Write(block, buffer, 16);
  if (status != MFRC522::STATUS_OK) {

    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Erro na escrita");

    Serial.print("\n\nERRO NA ESCRITA NO BLOCO!!!\n\n");
    
    lcd.setCursor(0,1);
    lcd.print("Tente novamente");

    delay(1500);
    
    setup();
    return;
  }
  
  else{
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Cadastro Feito");
    lcd.setCursor(0,1);
    lcd.print("com sucesso!");
    delay(4000);

    Serial.print("\n\nSucesso!!\n\n");

    //=> Inicia o Arduino Leonardo como um Teclado
    Keyboard.begin();
    Keyboard.print(OrdemDeServico);

    Keyboard.write(KEY_TAB);

    Keyboard.print("Cadastro");

    Keyboard.write(KEY_RETURN);
    Keyboard.write(KEY_LEFT_ARROW);

    Keyboard.end();
    //=> Encerra a operação do modo teclado
    
    return;
  }
 }  
}
