int VerifSetor(byte UID){


// Chaveiros da Coleta
      uint8_t Coleta1[4] = {0x63, 0xE1, 0xF1, 0x0B};
      uint8_t Coleta2[4];// = {0x, 0x, 0x, 0x};

  // Chaveiros da Conferência-2
      uint8_t Conferencia1[4] = {0xE3, 0xEF, 0xBD, 0x0D};
      uint8_t Conferencia2[4];// = {0x, 0x, 0x, 0x};

  // Chaveiros da Aprovação
      uint8_t Aprovado1[4];// = {0x, 0x, 0x, 0x};
      uint8_t Aprovado2[4];// = {0x, 0x, 0x, 0x};
      
   
   if((Coleta1[0] == Leitor1.uid.uidByte[0] and Coleta1[1] == Leitor1.uid.uidByte[1] and Coleta1[2] == Leitor1.uid.uidByte[2] 
   and Coleta1[3] == Leitor1.uid.uidByte[3]) or (Coleta2[0] == Leitor1.uid.uidByte[0] and Coleta2[1] == Leitor1.uid.uidByte[1] and Coleta2[2] == Leitor1.uid.uidByte[2]
   and Coleta2[3] == Leitor1.uid.uidByte[3])){

        Serial.print(F("\nCartão do Setor"));
        Serial.println("Coleta");
        return 0;
      }

      else if((Conferencia1[0] == Leitor1.uid.uidByte[0] and Conferencia1[1] == Leitor1.uid.uidByte[1] and Conferencia1[2] == Leitor1.uid.uidByte[2] 
   and Conferencia1[3] == Leitor1.uid.uidByte[3]) or (Conferencia2[0] == Leitor1.uid.uidByte[0] and Conferencia2[1] == Leitor1.uid.uidByte[1] and Conferencia2[2] == Leitor1.uid.uidByte[2]
   and Conferencia2[3] == Leitor1.uid.uidByte[3])){
    
        Serial.print(F("\nCartão do Setor"));
        Serial.println("Conferência");
        return 1;
      }

      else if((Aprovado1[0] == Leitor1.uid.uidByte[0] and Aprovado1[1] == Leitor1.uid.uidByte[1] and Aprovado1[2] == Leitor1.uid.uidByte[2] 
   and Aprovado1[3] == Leitor1.uid.uidByte[3]) or (Aprovado2[0] == Leitor1.uid.uidByte[0] and Aprovado2[1] == Leitor1.uid.uidByte[1] and Aprovado2[2] == Leitor1.uid.uidByte[2]
   and Aprovado2[3] == Leitor1.uid.uidByte[3])){

        Serial.print(F("\nCartão do Setor"));
        Serial.println("Aprovação");
        return 2;
        }

      else{

        return 7;
      }  
  }

int UIDSetor(){
  
    uint8_t UIDLida[4];

    Serial.print("Segunda Tag identificada: ");
    for (byte i = 0; i < 4; i++){
      
      // Printa o byte atual
      Serial.print(Leitor1.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(Leitor1.uid.uidByte[i], HEX);
    
    
  if(i == 3){   

       //=> Verifica se a UID Lida no chaveiro coincide com a UID de algum setor
      int SetorReturn = VerifSetor(Leitor1.uid.uidByte);
      
      if(SetorReturn == 0){
          
        return 0;
      }

      else if(SetorReturn == 1){
      
        return 1;
      }

      else if(SetorReturn == 2){
      
        return 2;
        }

      else if(SetorReturn == 3){
      
        return 3;
      }
  
      else{

        return 7;
      }
    }
  }
}

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
