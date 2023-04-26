void OsNaTela(){

  //=> Resgata o nº de OS e o setor trabalhado
  int OSAtual = EEPROMReadInt(0);

  Serial.print("Os atual resgatada: ");
  Serial.println(OSAtual);
  
  //=> Imprime o nº de OS na tela
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OS Trabalhando: ");
  lcd.setCursor(0,1);
  lcd.print(OSAtual);
  
  }
