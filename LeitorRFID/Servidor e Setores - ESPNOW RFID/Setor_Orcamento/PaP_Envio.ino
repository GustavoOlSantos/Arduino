// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  
  Serial.print("Status do último Pacote enviado: ");
  
  if (sendStatus == 0){
    
    Serial.println("Enviado com Sucesso!");

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Envio Realizado");
    lcd.setCursor(0,1);
    lcd.print("com sucesso!");
  }
  
  else{
    
    Serial.println("Falha no envio");

    int ResgataAnterior = EEPROMReadInt(2);
    EEPROMWriteInt(0, ResgataAnterior);

    Serial.print("OS Anterior (variável): ");
    Serial.println(EEPROMReadInt(2));
    Serial.print("OS Atual(anterior recuperada): ");
    Serial.println(EEPROMReadInt(0));
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Falha no Envio!");
    lcd.setCursor(0,1);
    lcd.print("Tente novamente.");
     
  }
}
