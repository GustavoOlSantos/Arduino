//------------ FUNÇAO PARA ESCREVER VARIÁVEIS INT NA EEPROM ------------// 

void EEPROMWriteInt(int address, int value) {
   byte hiByte = highByte(value);
   byte loByte = lowByte(value);

   EEPROM.write(address, hiByte);
   EEPROM.write(address + 1, loByte);   
}

//------------ FUNÇAO PARA LER VARIÁVEIS INT NA EEPROM ------------//

int EEPROMReadInt(int address) {
   byte hiByte = EEPROM.read(address);
   byte loByte = EEPROM.read(address + 1);
   
   return word(hiByte, loByte); 
}
