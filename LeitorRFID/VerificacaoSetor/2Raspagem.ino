int OsRaspagem(int Leitura, int Op){
  // Leitura é a OS Lida no cartão
  // Op é a operação a ser feita, Leitura+Limpeza(1), Escrita(2) ou Apenas Leitura(3)   
   
  //Variáveis Auxiliares
  int OS1 = EEPROMReadInt(0);       int OS2 = EEPROMReadInt(2);
  int OS3 = EEPROMReadInt(4);       int OS4 = EEPROMReadInt(6);
  int OS5 = EEPROMReadInt(8);       int OS6 = EEPROMReadInt(10);
  int OS7 = EEPROMReadInt(12);      int OS8 = EEPROMReadInt(14);
  int OS9 = EEPROMReadInt(16);      int OS10 = EEPROMReadInt(18);
  int OS11 = EEPROMReadInt(20);     int OS12 = EEPROMReadInt(22);
  int OS13 = EEPROMReadInt(24);     int OS14 = EEPROMReadInt(26);
  int OS15 = EEPROMReadInt(28);     int OS16 = EEPROMReadInt(30);
  int OS17 = EEPROMReadInt(32);     int OS18 = EEPROMReadInt(34);
  int OS19 = EEPROMReadInt(36);     int OS20 = EEPROMReadInt(38);
  int OS21 = EEPROMReadInt(40);     int OS22 = EEPROMReadInt(42);
  int OS23 = EEPROMReadInt(44);     int OS24 = EEPROMReadInt(46);
  int OS25 = EEPROMReadInt(48);     int OS26 = EEPROMReadInt(50);
  int OS27 = EEPROMReadInt(52);     int OS28 = EEPROMReadInt(54);
  int OS29 = EEPROMReadInt(56);     int OS30 = EEPROMReadInt(58);
  int OS31 = EEPROMReadInt(60);     int OS32 = EEPROMReadInt(62);
  int OS33 = EEPROMReadInt(64);     int OS34 = EEPROMReadInt(66);
  int OS35 = EEPROMReadInt(68);     int OS36 = EEPROMReadInt(70);
  int OS37 = EEPROMReadInt(72);     int OS38 = EEPROMReadInt(74);
  int OS39 = EEPROMReadInt(76);     int OS40 = EEPROMReadInt(78);
  int OS41 = EEPROMReadInt(80);     int OS42 = EEPROMReadInt(82);
  int OS43 = EEPROMReadInt(84);     int OS44 = EEPROMReadInt(86);
  int OS45 = EEPROMReadInt(88);     int OS46 = EEPROMReadInt(90);
  int OS47 = EEPROMReadInt(92);     int OS48 = EEPROMReadInt(94);
  int OS49 = EEPROMReadInt(96);     int OS50 = EEPROMReadInt(98);
     
  //Para Leitura
  if (Op == 1 or Op == 3){
    Serial.print(F("\nLeitura na Raspagem"));
    
    if(Leitura == OS1){

      if(Op == 1) {
        OS1 = 0;
        EEPROMWriteInt(0, OS1);
      }
      //Serial.println("OS1");
      //Serial.println("OS Encontrada no setor da raspagem e foi limpa com sucesso. \nPassagem liberada para o setor de Desmontagem.");    
     
      return 0;
    }

    else if(Leitura == OS2){

      if(Op == 1) {
        OS2 = 0;
        EEPROMWriteInt(2 ,OS2);
      }
      
      //Serial.println("OS2");
      //Serial.println("OS Encontrada no setor da raspagem e foi limpa com sucesso. \nPassagem liberada para o setor de Desmontagem.");      
      
      return 0;
    }
    
    else if(Leitura == OS3){

      if(Op == 1) {
        OS3 = 0;
        EEPROMWriteInt(4, OS3);      
      }

      return 0;
    }

    else if(Leitura == OS4){

      if(Op == 1) {
        OS4 = 0;
        EEPROMWriteInt(6, OS4);        
      }
      
      return 0;
    }
    else if(Leitura == OS5){
      
      if(Op == 1) {
        OS5 = 0;
        EEPROMWriteInt(8, OS5);        
      } 
      return 0;
    }
    else if(Leitura == OS6){
      
      if(Op == 1) {
        OS6 = 0;
        EEPROMWriteInt(10, OS6);        
      }
      return 0;
    }

    else if(Leitura == OS7){

      if(Op == 1) {
        OS7 = 0;  
        EEPROMWriteInt(12, OS7);      
      }
      return 0;
    }
    
    else if(Leitura == OS8){

      if(Op == 1) {
        OS8 = 0;  
        EEPROMWriteInt(14, OS8);      
      }    
      return 0;
    }
    else if(Leitura == OS9){

      if(Op == 1) {
        OS9 = 0;  
        EEPROMWriteInt(16, OS9);      
      }
      return 0;
    }
    
    else if(Leitura == OS10){

      if(Op == 1) {
        OS10 = 0;  
        EEPROMWriteInt(18, OS10);      
      }    
      return 0;
    }
    
    else if(Leitura == OS11){

      if(Op == 1) {
        OS11 = 0;  
        EEPROMWriteInt(20, OS11);     
      }
      return 0;
    }
    
    else if(Leitura == OS12){

      if(Op == 1) {
        OS12 = 0;  
        EEPROMWriteInt(22, OS12);      
      } 
      return 0;
    }

    else if(Leitura == OS13){
      
      if(Op == 1) {
        OS13 = 0;
        EEPROMWriteInt(24, OS13);      
      }
      return 0;
    }
    
    else if(Leitura == OS14){
      
      if(Op == 1) {
        OS14 = 0;
        EEPROMWriteInt(26, OS14);      
      }
      return 0;
    }
    
    else if(Leitura == OS15){

      if(Op == 1) {
        OS15 = 0;
        EEPROMWriteInt(28, OS15);      
      }
      return 0;
    }
    
    else if(Leitura == OS16){

      if(Op == 1) {
        OS16 = 0;
        EEPROMWriteInt(30, OS16);      
      }
      return 0;
    }
    
    else if(Leitura == OS17){

      if(Op == 1) {
        OS17 = 0;
        EEPROMWriteInt(32, OS17);      
      }
      return 0;
    }
    
    else if(Leitura == OS18){
      
      if(Op == 1) {
        OS18 = 0;
        EEPROMWriteInt(34, OS18);      
      }
      return 0;
    }
    
    else if(Leitura == OS19){

      if(Op == 1) {
        OS19 = 0;
        EEPROMWriteInt(36, OS19);      
      }
      return 0;
    }
    
    else if(Leitura == OS20){

      if(Op == 1) {
        OS20 = 0;
        EEPROMWriteInt(38, OS20);      
      }
      return 0;
    }
    
    else if(Leitura == OS21){

      if(Op == 1) {
        OS21 = 0;
        EEPROMWriteInt(40, OS21);      
      }
      return 0;
    }
    
    else if(Leitura == OS22){
            
      if(Op == 1) {
        OS22 = 0;
        EEPROMWriteInt(42, OS22);      
      }
      return 0;
    }
    
    else if(Leitura == OS23){

      if(Op == 1) {
        OS23 = 0;
        EEPROMWriteInt(44, OS23);      
      }
      return 0;
    }
    
    else if(Leitura == OS24){
            
      if(Op == 1) {
        OS24 = 0;
        EEPROMWriteInt(46, OS24);      
      }
      return 0;
    }
    
    else if(Leitura == OS25){
      
      if(Op == 1) {
        OS25 = 0;
        EEPROMWriteInt(48, OS25);      
      }
      return 0;
    }
    
    else if(Leitura == OS26){
      
      if(Op == 1) {
        OS26 = 0;
        EEPROMWriteInt(50, OS26);      
      }
      return 0;
    }
     
    else if(Leitura == OS27){
      
      if(Op == 1) {
        OS27 = 0;
        EEPROMWriteInt(52, OS27);      
      }
      return 0;
    }
    
    else if(Leitura == OS28){
      
      if(Op == 1) {
        OS28 = 0;
        EEPROMWriteInt(54, OS28);      
      }
      return 0;
    }
    
    else if(Leitura == OS29){
      
      if(Op == 1) {
        OS29 = 0;
        EEPROMWriteInt(56, OS29);      
      }
      return 0;
    }
    
    else if(Leitura == OS30){
            
      if(Op == 1) {
        OS30 = 0;
        EEPROMWriteInt(58, OS30);      
      }
      return 0;
    }
    
    else if(Leitura == OS31){
            
      if(Op == 1) {
        OS31 = 0;
        EEPROMWriteInt(60, OS31);     
      }
      return 0;
    }
    
    else if(Leitura == OS32){
            
      if(Op == 1) {
        OS32 = 0;
        EEPROMWriteInt(62, OS32);      
      }
      return 0;
    }
    
    else if(Leitura == OS33){
      
      if(Op == 1) {
        OS33 = 0;
        EEPROMWriteInt(64, OS33);      
      }
      return 0;
    }
    
    else if(Leitura == OS34){
      
      if(Op == 1) {
        OS34 = 0;
        EEPROMWriteInt(66, OS34);      
      }
      return 0;
    }
    
    else if(Leitura == OS35){
      
      if(Op == 1) {
        OS35 = 0;
        EEPROMWriteInt(68, OS35);      
      }
      return 0;
    }
    
    else if(Leitura == OS36){
            
      if(Op == 1) {
        OS36 = 0;
        EEPROMWriteInt(70, OS36);      
      }
      return 0;
    }
    
    else if(Leitura == OS37){
      
      if(Op == 1) {
        OS37 = 0;
        EEPROMWriteInt(72, OS37);      
      }
      return 0;
    }
    
    else if(Leitura == OS38){
      
      if(Op == 1) {
        OS38 = 0;
        EEPROMWriteInt(74, OS38);      
      }
      return 0;
    }
    
    else if(Leitura == OS39){
      
      if(Op == 1) {
        OS39 = 0;
        EEPROMWriteInt(76, OS39);      
      }
      return 0;
    }
    
    else if(Leitura == OS40){
      
      if(Op == 1) {
        OS40 = 0;
        EEPROMWriteInt(78, OS40);      
      }
      return 0;
    }

    else if(Leitura == OS41){
      
      if(Op == 1) {
        OS41 = 0;
        EEPROMWriteInt(80, OS41);      
      }
      return 0;
    }

    else if(Leitura == OS42){
      
      if(Op == 1) {
        OS42 = 0;
        EEPROMWriteInt(82, OS42);      
      }
      return 0;
    }

    else if(Leitura == OS43){
      
      if(Op == 1) {
        OS43 = 0;
        EEPROMWriteInt(84, OS43);      
      }
      return 0;
    }

    else if(Leitura == OS44){
      
      if(Op == 1) {
        OS44 = 0;
        EEPROMWriteInt(86, OS44);      
      }
      return 0;
    }

    else if(Leitura == OS45){
      
      if(Op == 1) {
        OS45 = 0;
        EEPROMWriteInt(88, OS45);      
      }
      return 0;
    }

    else if(Leitura == OS46){
      
      if(Op == 1) {
        OS46 = 0;
        EEPROMWriteInt(90, OS46);      
      }
      return 0;
    }

    else if(Leitura == OS47){
      
      if(Op == 1) {
        OS47 = 0;
        EEPROMWriteInt(92, OS47);      
      }
      return 0;
    }

    else if(Leitura == OS48){
      
      if(Op == 1) {
        OS48 = 0;
        EEPROMWriteInt(94, OS48);      
      }
      return 0;
    }

    else if(Leitura == OS49){
      
      if(Op == 1) {
        OS49 = 0;
        EEPROMWriteInt(96, OS49);      
      }
      return 0;
    }

    else if(Leitura == OS50){
      
      if(Op == 1) {
        OS50 = 0;
        EEPROMWriteInt(98, OS50);      
      }
      return 0;
    }
    
    else{

      Serial.println(F("\tOS não encontrada no setor anterior."));
      return 1;
      }
    }
    
  //Para Escrita:
  else if(Op == 2){

    Serial.println(F("\nEscrita na raspagem"));
    
      if(OS1 == 0){
  
        OS1 = Leitura;
        EEPROMWriteInt(0, OS1);
        
        Serial.println(OS1);
  
        Serial.println(F("Variável escrita com sucesso no endereço OS1 da Raspagem"));
        return 0;
      } 
  
      else if(OS2 == 0 ){
        
        OS2 = Leitura;
        EEPROMWriteInt(2, OS2);
        
        Serial.println("Variável escrita com sucesso no endereço OS2 da Raspagem");
        return 0;
      }
  
      else if(OS3 == 0){
        
        OS3 = Leitura;
        EEPROMWriteInt(4, OS3);
        
        return 0;
      }
  
      else if(OS4 == 0){
      
        OS4 = Leitura;
        EEPROMWriteInt(6, OS4);
        
        return 0;
      }
       
      else if(OS5 == 0){
        
        OS5 = Leitura;
        EEPROMWriteInt(8, OS5);
        
        return 0;
      }
      
      else if(OS6 == 0 ){
        
        OS6 = Leitura;
        EEPROMWriteInt(10, OS6);
        
        return 0;
      }
      
      else if(OS7 == 0){
        
        OS7 = Leitura;
        EEPROMWriteInt(12, OS7);
        
        return 0;
      }
      
      else if(OS8 == 0){
        
        OS8 = Leitura;
        EEPROMWriteInt(14, OS8);
        
        return 0;
      }
  
      else if(OS9 == 0){
        
        OS9 = Leitura;
        EEPROMWriteInt(16, OS9);
        
        return 0;
      }
  
      else if(OS10 == 0){
        
        OS10 = Leitura;
        EEPROMWriteInt(18, OS10);
        
        return 0;
      }
  
      else if(OS11 == 0){
        
        OS11 = Leitura;
        EEPROMWriteInt(20, OS11);
        
        return 0;
      }
  
      else if(OS12 == 0){
        
        OS12 = Leitura;
        EEPROMWriteInt(22, OS12);
        
        return 0;
      }
  
      else if(OS13 == 0){
        
        OS13 = Leitura;
        EEPROMWriteInt(24, OS13);
        return 0;
      }
  
      else if(OS14 == 0){
        
        OS14 = Leitura;
        EEPROMWriteInt(26, OS14);
        
        return 0;
      }
  
      else if(OS15 == 0){
        
        OS15 = Leitura;
       EEPROMWriteInt(28, OS15);
        
        return 0;
      }
  
      else if(OS16 == 0){
        
        OS16 = Leitura;
        EEPROMWriteInt(30, OS16);
        
        return 0;
      }
  
      else if(OS17 == 0){
        
        OS17 = Leitura;
        EEPROMWriteInt(32, OS17);
        
        return 0;
      }
  
      else if(OS18 == 0){
        
        OS18 = Leitura;
        EEPROMWriteInt(34, OS18);
        
        return 0;
      }
  
      else if(OS19 == 0){
        
        OS19 = Leitura;
        EEPROMWriteInt(36, OS19);
        
        return 0;
      }
  
      else if(OS20 == 0){
        
        OS20 = Leitura;
        EEPROMWriteInt(38, OS20);
        
        return 0;
      }
  
      else if(OS21 == 0){
        
        OS21 = Leitura;
        EEPROMWriteInt(40, OS21);
        
        return 0;
        
      }
  
      else if(OS22 == 0){
        
        OS22 = Leitura;
        EEPROMWriteInt(42, OS22);
        
        return 0;
      }
  
      else if(OS23 == 0){
        
        OS23 = Leitura;
        EEPROMWriteInt(44, OS23);
        
        return 0;
      }
  
      else if(OS24 == 0){
        
        OS24 = Leitura;
        EEPROMWriteInt(46, OS24);
        return 0;
      }
  
     else if(OS25 == 0){
      
      OS25 = Leitura;
      EEPROMWriteInt(48, OS25);
      
      return 0;
    }
  
    else if(OS26 == 0){
        
        OS26 = Leitura;
        EEPROMWriteInt(50, OS26);
        return 0;
    }
  
    else if(OS27 == 0){
        
      OS27 = Leitura;
      EEPROMWriteInt(52, OS27);
      
      return 0;
    }
  
    else if(OS28 == 0){
        
      OS28 = Leitura;
      EEPROMWriteInt(54, OS28);
      
      return 0;
    }
  
    else if(OS29 == 0){
        
        OS29 = Leitura;
        EEPROMWriteInt(56, OS29);
        
        return 0;
    }
  
    else if(OS30 == 0){
        
        OS30 = Leitura;
        EEPROMWriteInt(58, OS30);
        
        return 0;
    }
  
    else if(OS31 == 0){
        
        OS31 = Leitura;
        EEPROMWriteInt(60, OS31);
        
        return 0;
    }
  
    else if(OS32 == 0){
        
        OS32 = Leitura;
        EEPROMWriteInt(62, OS32);
        
        return 0;
    }
  
    else if(OS33 == 0){
        
        OS33 = Leitura;
        EEPROMWriteInt(64, OS33);
        
        return 0;
    }
  
    else if(OS34 == 0){
        
        OS34 = Leitura;
        EEPROMWriteInt(66, OS34);
        
        return 0;
      }
  
    else if(OS35 == 0){
      
      OS35 = Leitura;
      EEPROMWriteInt(68, OS35);
      
      return 0;
    }
  
    else if(OS36 == 0){
        
        OS36 = Leitura;
        EEPROMWriteInt(70, OS36);
        
        return 0;
    }
  
    else if(OS37 == 0){
        
        OS37 = Leitura;
        EEPROMWriteInt(72, OS37);
        
        return 0;
    }
  
    else if(OS38 == 0){
        
      OS38 = Leitura;
      EEPROMWriteInt(74, OS38);
      
      return 0;
    }
  
    else if(OS39 == 0){
        
      OS39 = Leitura;
      EEPROMWriteInt(76, OS39);
      
      return 0;
    }
  
    else if(OS40 == 0){

      OS40 = Leitura;
      EEPROMWriteInt(78, OS40);
    
      return 0;
    }
    
    else if(OS41 == 0){
    
      OS41 = Leitura;
      EEPROMWriteInt(80, OS41);
    
      return 0;
    }
    
    else if(OS42 == 0){
    
      OS42 = Leitura;
      EEPROMWriteInt(82, OS42);
    
      return 0;
    }
    
    else if(OS43 == 0){
    
      OS43 = Leitura;
      EEPROMWriteInt(84, OS43);
    
      return 0;
    }
    
    else if(OS44 == 0){
    
      OS44 = Leitura;
      EEPROMWriteInt(86, OS44);
    
      return 0;
    }
    
    else if(OS45 == 0){
    
      OS45 = Leitura;
      EEPROMWriteInt(88, OS45);
    
      return 0;
    }
    
    else if(OS46 == 0){
    
      OS46 = Leitura;
      EEPROMWriteInt(90, OS46);
    
      return 0;
    }
    
    else if(OS47 == 0){
    
      OS47 = Leitura;
      EEPROMWriteInt(92, OS47);
    
      return 0;
    }
    
    else if(OS48 == 0){
    
      OS48 = Leitura;
      EEPROMWriteInt(94, OS48);
    
      return 0;
    }
    
    else if(OS49 == 0){
    
      OS49 = Leitura;
      EEPROMWriteInt(96, OS49);
    
      return 0;
    }
    
    else if(OS50 == 0){
    
      OS50 = Leitura;
      EEPROMWriteInt(98, OS50);
    
      return 0;
    }

    
    else{

      Serial.println(F("\nSem espaço disponível para escrita."));      
      
      return 1;
    }
  }
}
