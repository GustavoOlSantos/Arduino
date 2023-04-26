void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("String: ");
  Serial.println(myData.LeituraOSSetor);


  // Formatação:
  //<2017-1>


  if(myData.LeituraOSSetor[0] == '<' and myData.LeituraOSSetor[5] == '-' and myData.LeituraOSSetor[7] == '>'){
    
    // Envia a Mensagem via ESP-NOW
    Serial.println("Enviando para o Servidor principal!");
    Serial.print("Mensagem a ser enviada: ");
    
    Serial.print(myData.LeituraOSSetor);
    esp_now_send(ServerAddress, (uint8_t *) &myData, sizeof(myData));
    
    Serial.print("\n\nMensagem enviada com Sucesso!\n\n");
    myData.LeituraOSSetor = " ";
  }
  
}
