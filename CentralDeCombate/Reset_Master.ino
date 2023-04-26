//------------ FUNÇAO PARA DAR RESET MASTER NA CENTRAL ------------//

 int FuncMasterReset(){
    
   Temperatura =  0;
   EEPROMWriteInt(0, Temperatura);
   
   Acman = 0;
   EEPROMWriteInt(2, Acman);
   
   Saponif = 0;
   EEPROMWriteInt(4, Saponif);
   
   Gas = 0;
   EEPROMWriteInt(6, Gas);
   
   Co2 = 0;
   EEPROMWriteInt(8, Co2);  
                  
   Gate = 0;
   EEPROMWriteInt(10, Gate);

   Cman2 = 0;
   EEPROMWriteInt(12, Cman2);
   
   // Apagar esse return quando o resetmaster provisório for apagado
    return 1;
    }
