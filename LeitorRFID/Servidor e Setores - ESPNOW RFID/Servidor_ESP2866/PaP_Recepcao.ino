void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len)
{

  memcpy(&myData, incomingData, sizeof(myData));
  // Serial.print("Bytes received: ");
  // Serial.println(len);
  Serial.print("\nString: ");
  Serial.println(myData.LeituraOSSetor);

  // Formatação:
  //<2017-1>

  if (myData.LeituraOSSetor[0] == '<' and myData.LeituraOSSetor[5] == '-' and myData.LeituraOSSetor[7] == '>')
  {

    char Receptor[4];

    Receptor[0] = myData.LeituraOSSetor[1];
    Receptor[1] = myData.LeituraOSSetor[2];
    Receptor[2] = myData.LeituraOSSetor[3];
    Receptor[3] = myData.LeituraOSSetor[4];
    Receptor[4] = '\0';

    int OS = atoi(Receptor);

    Serial.print("Número Recebido: ");
    Serial.println(OS);

    // Envia para o Arduino Leonardo via I2C
    Wire.beginTransmission(1);
    Wire.write(myData.LeituraOSSetor.c_str());
    Wire.endTransmission();
  }
}
