//------------ FUNÇAO PARA ESCREVER VARIÁVEIS INT NA EEPROM ------------// 

// Divide o inteiro em 2 Bytes, sendo um mais significativo que outro e os salva em endereços consecutivos
void EEPROMWriteInt(int address, int value) {
   byte hiByte = highByte(value);
   byte loByte = lowByte(value);

   EEPROM.write(address, hiByte);
   EEPROM.write(address + 1, loByte);   
}
  

//------------ FUNÇAO PARA LER VARIÁVEIS INT NA EEPROM ------------// 

// Agrupa o Byte registrado no endereço especificado com o do posterior e retorna uma palavra contendo os bytes unidos 
int EEPROMReadInt(int address) {
   byte hiByte = EEPROM.read(address);
   byte loByte = EEPROM.read(address + 1);
   
   return word(hiByte, loByte); 
}

//------------ FUNÇAO PARA LIMPAR A MEMÓRIA EEPROM ------------// 

//Usada somente durante o período de testes, define todos os endereços como 0
void EEPROMCLEAR(){
  
  for (int i = 0 ; i < 1023 ; i++) {
    EEPROM.write(i, 0);
  }
}
