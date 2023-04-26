int OsPressurizacaoA(int Leitura, int Op){
  // Leitura é a OS Lida no cartão
  // Op é a operação a ser feita, Leitura+Limpeza(1), Escrita(2) ou Apenas Leitura(3)  
  
  //Variáveis Auxiliares
  int OS151 = EEPROMReadInt(300);     int OS152 = EEPROMReadInt(302);
  int OS153 = EEPROMReadInt(304);     int OS154 = EEPROMReadInt(306);
  int OS155 = EEPROMReadInt(308);     int OS156 = EEPROMReadInt(310);
  int OS157 = EEPROMReadInt(312);     int OS158 = EEPROMReadInt(314);
  int OS159 = EEPROMReadInt(316);     int OS160 = EEPROMReadInt(318);
  int OS161 = EEPROMReadInt(320);     int OS162 = EEPROMReadInt(322);
  int OS163 = EEPROMReadInt(324);     int OS164 = EEPROMReadInt(326);
  int OS165 = EEPROMReadInt(328);     int OS166 = EEPROMReadInt(330);
  int OS167 = EEPROMReadInt(332);     int OS168 = EEPROMReadInt(334);
  int OS169 = EEPROMReadInt(336);     int OS170 = EEPROMReadInt(338);
  int OS171 = EEPROMReadInt(340);     int OS172 = EEPROMReadInt(342);
  int OS173 = EEPROMReadInt(344);     int OS174 = EEPROMReadInt(346);
  int OS175 = EEPROMReadInt(348);     int OS176 = EEPROMReadInt(350);
  int OS177 = EEPROMReadInt(352);     int OS178 = EEPROMReadInt(354);
  int OS179 = EEPROMReadInt(356);     int OS180 = EEPROMReadInt(358);
  int OS181 = EEPROMReadInt(360);     int OS182 = EEPROMReadInt(362);
  int OS183 = EEPROMReadInt(364);     int OS184 = EEPROMReadInt(366);
  int OS185 = EEPROMReadInt(368);     int OS186 = EEPROMReadInt(370);
  int OS187 = EEPROMReadInt(372);     int OS188 = EEPROMReadInt(374);
  int OS189 = EEPROMReadInt(376);     int OS190 = EEPROMReadInt(378);
  int OS191 = EEPROMReadInt(380);     int OS192 = EEPROMReadInt(382);
  int OS193 = EEPROMReadInt(384);     int OS194 = EEPROMReadInt(386);
  int OS195 = EEPROMReadInt(388);     int OS196 = EEPROMReadInt(390);
  int OS197 = EEPROMReadInt(392);     int OS198 = EEPROMReadInt(394);
  int OS199 = EEPROMReadInt(396);     int OS200 = EEPROMReadInt(398);

     
  //Para Leitura
  if (Op == 1 or Op == 3){
    Serial.print(F("\nLeitura na Pressurização Alta"));
    
    if(Leitura == OS151){

      if(Op == 1) {
      OS151 = 0;
      EEPROMWriteInt(300, OS151);
      }
      
      return 0;
    }
    
    else if(Leitura == OS152){
    
      if(Op == 1) {
        OS152 = 0;
        EEPROMWriteInt(302, OS152);
      }
      
      return 0;
    }
    
    else if(Leitura == OS153){
    
      if(Op == 1) {      
        OS153 = 0;
        EEPROMWriteInt(304, OS153);
      }
      
      return 0;
    }
    
    else if(Leitura == OS154){
    
      if(Op == 1) {
        OS154 = 0;
        EEPROMWriteInt(306, OS154);
      }
      
      return 0;
    }
    
    else if(Leitura == OS155){
    
      if(Op == 1) {
        OS155 = 0;
        EEPROMWriteInt(308, OS155);
      }
      
      return 0;
    }
    
    else if(Leitura == OS156){
    
      if(Op == 1) {
        OS156 = 0;
        EEPROMWriteInt(310, OS156);
      }
      
      return 0;
    }
    
    else if(Leitura == OS157){
    
      if(Op == 1) {
        OS157 = 0;
        EEPROMWriteInt(312, OS157);
      }
      
      return 0;
    }
    
    else if(Leitura == OS158){
    
      if(Op == 1) {
        OS158 = 0;
        EEPROMWriteInt(314, OS158);
      }
      
      return 0;
    }
    
    else if(Leitura == OS159){
    
      if(Op == 1) {
        OS159 = 0;
        EEPROMWriteInt(316, OS159);
      }
      
      return 0;
    }
    
    else if(Leitura == OS160){
    
      if(Op == 1) {
        OS160 = 0;
        EEPROMWriteInt(318, OS160);
      }  
      
      return 0;
    }
    
    else if(Leitura == OS161){
    
      if(Op == 1) {
        OS161 = 0;
        EEPROMWriteInt(320, OS161);
      }
      
      return 0;
    }
    
    else if(Leitura == OS162){
    
      if(Op == 1) {
        OS162 = 0;
        EEPROMWriteInt(322, OS162);
      }
      
      return 0;
    }
    
    else if(Leitura == OS163){
    
      if(Op == 1) {
        OS163 = 0;
        EEPROMWriteInt(324, OS163);
      }
      return 0;
    }
    
    else if(Leitura == OS164){
    
      if(Op == 1) {
        OS164 = 0;
        EEPROMWriteInt(326, OS164);
      }
    
      return 0;
    }
    
    else if(Leitura == OS165){
    
      if(Op == 1) {
        OS165 = 0;
        EEPROMWriteInt(328, OS165);
      }
      
      return 0;
    }
    
    else if(Leitura == OS166){
    
      if(Op == 1) {
        OS166 = 0;
        EEPROMWriteInt(330, OS166);
      }
      
      return 0;
    }
    
    else if(Leitura == OS167){
    
      if(Op == 1) {
        OS167 = 0;
        EEPROMWriteInt(332, OS167);
      }
      
      return 0;
    }
    
    else if(Leitura == OS168){
    
      if(Op == 1) {
        OS168 = 0;
        EEPROMWriteInt(334, OS168);
      }
      
      return 0;
    }
    
    else if(Leitura == OS169){
    
      if(Op == 1) {
        OS169 = 0;
        EEPROMWriteInt(336, OS169);
      }
      
      return 0;
    }
    
    else if(Leitura == OS170){
    
      if(Op == 1) {
        OS170 = 0;
        EEPROMWriteInt(338, OS170);
      }    
      
      return 0;
    }
    
    else if(Leitura == OS171){
    
      if(Op == 1) {
        OS171 = 0;
        EEPROMWriteInt(340, OS171);
      }
      
      return 0;
    }
    
    else if(Leitura == OS172){
    
      if(Op == 1) {
        OS172 = 0;
        EEPROMWriteInt(342, OS172);
      }
      
      return 0;
    }
    
    else if(Leitura == OS173){
    
      if(Op == 1) {
        OS173 = 0;
        EEPROMWriteInt(344, OS173);
      }
      return 0;
    }
    
    else if(Leitura == OS174){
    
      if(Op == 1) {
        OS174 = 0;
        EEPROMWriteInt(346, OS174);
      }
          
      return 0;
    }
    
    else if(Leitura == OS175){
    
      if(Op == 1) {
        OS175 = 0;
        EEPROMWriteInt(348, OS175);
      }
      
      return 0;
    }
    
    else if(Leitura == OS176){
    
      if(Op == 1) {
        OS176 = 0;
        EEPROMWriteInt(350, OS176);
      }
      
      return 0;
    }
    
    else if(Leitura == OS177){
    
      if(Op == 1) {
        OS177 = 0;
        EEPROMWriteInt(352, OS177);
      }
      
      return 0;
    }
    
    else if(Leitura == OS178){
    
      if(Op == 1) {
        OS178 = 0;
        EEPROMWriteInt(354, OS178);
      }
      
      return 0;
    }
    
    else if(Leitura == OS179){
    
      if(Op == 1) {
        OS179 = 0;
        EEPROMWriteInt(356, OS179);
      }  
      
      return 0;
    }
    
    else if(Leitura == OS180){
    
      if(Op == 1) {
        OS180 = 0;
        EEPROMWriteInt(358, OS180);
      }
      
      return 0;
    }
    
    else if(Leitura == OS181){
    
      if(Op == 1) {
        OS181 = 0;
        EEPROMWriteInt(360, OS181);
      }
      
      return 0;
    }
    
    else if(Leitura == OS182){
    
      if(Op == 1) {
        OS182 = 0;
        EEPROMWriteInt(362, OS182);
      }
      
      return 0;
    }
    
    else if(Leitura == OS183){
    
      if(Op == 1) {
        OS183 = 0;
        EEPROMWriteInt(364, OS183);
      }
      
      return 0;
    }
    
    else if(Leitura == OS184){
    
      if(Op == 1) {
        OS184 = 0;
        EEPROMWriteInt(366, OS184);
      }
      
      return 0;
    }
    
    else if(Leitura == OS185){
    
      if(Op == 1) {
        OS185 = 0;  
        EEPROMWriteInt(368, OS185);
      }
      
      return 0;
    }
    
    else if(Leitura == OS186){
    
      if(Op == 1) {
        OS186 = 0;
        EEPROMWriteInt(370, OS186);
      }
      
      return 0;
    }
    
    else if(Leitura == OS187){
    
      if(Op == 1) {
        OS187 = 0;
        EEPROMWriteInt(372, OS187);
      }
      
      return 0;
    }
    
    else if(Leitura == OS188){
    
      if(Op == 1) {
        OS188 = 0;
        EEPROMWriteInt(374, OS188);
      }
      
      return 0;
    }
    
    else if(Leitura == OS189){
    
      if(Op == 1) {
        OS189 = 0;
        EEPROMWriteInt(376, OS189);
      }
      
      return 0;
    }
    
    else if(Leitura == OS190){
    
      if(Op == 1) {
        OS190 = 0;
        EEPROMWriteInt(378, OS190);
      }
      
      return 0;
    }
    
    else if(Leitura == OS191){

      if(Op == 1) {
        OS191 = 0;
        EEPROMWriteInt(380, OS191);
      }
      
      return 0;
    }
    
    else if(Leitura == OS192){

      if(Op == 1) {
        OS192 = 0;
        EEPROMWriteInt(382, OS192);
      }
      
      return 0;
    }
    
    else if(Leitura == OS193){
    
      if(Op == 1) {
        OS193 = 0;
        EEPROMWriteInt(384, OS193);
      }
      
      return 0;
    }
    
    else if(Leitura == OS194){
    
      if(Op == 1) {
        OS194 = 0;
        EEPROMWriteInt(386, OS194);
      }
      
      return 0;
    }
    
    else if(Leitura == OS195){
    
      if(Op == 1) {
        OS195 = 0;
        EEPROMWriteInt(388, OS195);
      }
      
      return 0;
    }
    
    else if(Leitura == OS196){
    
      if(Op == 1) {
        OS196 = 0;
        EEPROMWriteInt(390, OS196);
      }
      
      return 0;
    }
    
    else if(Leitura == OS197){
    
      if(Op == 1) {
        OS197 = 0;
        EEPROMWriteInt(392, OS197);
      }
      
      return 0;
    }
    
    else if(Leitura == OS198){
    
      if(Op == 1) {
        OS198 = 0;
        EEPROMWriteInt(394, OS198);
      }
      
      return 0;
    }
    
    else if(Leitura == OS199){
    
      if(Op == 1) {
        OS199 = 0;
        EEPROMWriteInt(396, OS199);
      }
      
      return 0;
    }
    
    else if(Leitura == OS200){
    
      if(Op == 1) {
        OS200 = 0;
        EEPROMWriteInt(398, OS200);
      }
      
      return 0;
    }
    
    else{

      Serial.println(F("\tOS não encontrada no setor anterior."));
      return 1;
      }
    }

// --------------------------------------------------------------------------------------------------------------------------------------------------------//
    
  //Para Escrita:
  else if(Op == 2){

    Serial.println(F("\nEscrita na Pressurização Alta"));
    
    if(OS151 == 0){

      OS151 = Leitura;
      EEPROMWriteInt(300, OS151);
    
      return 0;
    }
    
    else if(OS152 == 0){
    
      OS152 = Leitura;
      EEPROMWriteInt(302, OS152);
    
      return 0;
    }
    
    else if(OS153 == 0){
    
      OS153 = Leitura;
      EEPROMWriteInt(304, OS153);
    
      return 0;
    }
    
    else if(OS154 == 0){
    
      OS154 = Leitura;
      EEPROMWriteInt(306, OS154);
    
      return 0;
    }
    
    else if(OS155 == 0){
    
      OS155 = Leitura;
      EEPROMWriteInt(308, OS155);
    
      return 0;
    }
    
    else if(OS156 == 0){
    
      OS156 = Leitura;
      EEPROMWriteInt(310, OS156);
    
      return 0;
    }
    
    else if(OS157 == 0){
    
      OS157 = Leitura;
      EEPROMWriteInt(312, OS157);
    
      return 0;
    }
    
    else if(OS158 == 0){
    
      OS158 = Leitura;
      EEPROMWriteInt(314, OS158);
    
      return 0;
    }
    
    else if(OS159 == 0){
    
      OS159 = Leitura;
      EEPROMWriteInt(316, OS159);
    
      return 0;
    }
    
    else if(OS160 == 0){
    
      OS160 = Leitura;
      EEPROMWriteInt(318, OS160);
    
      return 0;
    }
    
    else if(OS161 == 0){
    
      OS161 = Leitura;
      EEPROMWriteInt(320, OS161);
    
      return 0;
    }
    
    else if(OS162 == 0){
    
      OS162 = Leitura;
      EEPROMWriteInt(322, OS162);
    
      return 0;
    }
    
    else if(OS163 == 0){
    
      OS163 = Leitura;
      EEPROMWriteInt(324, OS163);
    
      return 0;
    }
    
    else if(OS164 == 0){
    
      OS164 = Leitura;
      EEPROMWriteInt(326, OS164);
    
      return 0;
    }
    
    else if(OS165 == 0){
    
      OS165 = Leitura;
      EEPROMWriteInt(328, OS165);
    
      return 0;
    }
    
    else if(OS166 == 0){
    
      OS166 = Leitura;
      EEPROMWriteInt(330, OS166);
    
      return 0;
    }
    
    else if(OS167 == 0){
    
      OS167 = Leitura;
      EEPROMWriteInt(332, OS167);
    
      return 0;
    }
    
    else if(OS168 == 0){
    
      OS168 = Leitura;
      EEPROMWriteInt(334, OS168);
    
      return 0;
    }
    
    else if(OS169 == 0){
    
      OS169 = Leitura;
      EEPROMWriteInt(336, OS169);
    
      return 0;
    }
    
    else if(OS170 == 0){
    
      OS170 = Leitura;
      EEPROMWriteInt(338, OS170);
    
      return 0;
    }
    
    else if(OS171 == 0){
    
      OS171 = Leitura;
      EEPROMWriteInt(340, OS171);
    
      return 0;
    }
    
    else if(OS172 == 0){
    
      OS172 = Leitura;
      EEPROMWriteInt(342, OS172);
    
      return 0;
    }
    
    else if(OS173 == 0){
    
      OS173 = Leitura;
      EEPROMWriteInt(344, OS173);
    
      return 0;
    }
    
    else if(OS174 == 0){
    
      OS174 = Leitura;
      EEPROMWriteInt(346, OS174);
    
      return 0;
    }
    
    else if(OS175 == 0){
    
      OS175 = Leitura;
      EEPROMWriteInt(348, OS175);
    
      return 0;
    }
    
    else if(OS176 == 0){
    
      OS176 = Leitura;
      EEPROMWriteInt(350, OS176);
    
      return 0;
    }
    
    else if(OS177 == 0){
    
      OS177 = Leitura;
      EEPROMWriteInt(352, OS177);
    
      return 0;
    }
    
    else if(OS178 == 0){
    
      OS178 = Leitura;
      EEPROMWriteInt(354, OS178);
    
      return 0;
    }
    
    else if(OS179 == 0){
    
      OS179 = Leitura;
      EEPROMWriteInt(356, OS179);
    
      return 0;
    }
    
    else if(OS180 == 0){
    
      OS180 = Leitura;
      EEPROMWriteInt(358, OS180);
    
      return 0;
    }
    
    else if(OS181 == 0){
    
      OS181 = Leitura;
      EEPROMWriteInt(360, OS181);
    
      return 0;
    }
    
    else if(OS182 == 0){
    
      OS182 = Leitura;
      EEPROMWriteInt(362, OS182);
    
      return 0;
    }
    
    else if(OS183 == 0){
    
      OS183 = Leitura;
      EEPROMWriteInt(364, OS183);
    
      return 0;
    }
    
    else if(OS184 == 0){
    
      OS184 = Leitura;
      EEPROMWriteInt(366, OS184);
    
      return 0;
    }
    
    else if(OS185 == 0){
    
      OS185 = Leitura;
      EEPROMWriteInt(368, OS185);
    
      return 0;
    }
    
    else if(OS186 == 0){
    
      OS186 = Leitura;
      EEPROMWriteInt(370, OS186);
    
      return 0;
    }
    
    else if(OS187 == 0){
    
      OS187 = Leitura;
      EEPROMWriteInt(372, OS187);
    
      return 0;
    }
    
    else if(OS188 == 0){
    
      OS188 = Leitura;
      EEPROMWriteInt(374, OS188);
    
      return 0;
    }
    
    else if(OS189 == 0){
    
      OS189 = Leitura;
      EEPROMWriteInt(376, OS189);
    
      return 0;
    }
    
    else if(OS190 == 0){
    
      OS190 = Leitura;
      EEPROMWriteInt(378, OS190);
    
      return 0;
    }
    
    else if(OS191 == 0){
    
      OS191 = Leitura;
      EEPROMWriteInt(380, OS191);
    
      return 0;
    }
    
    else if(OS192 == 0){
    
      OS192 = Leitura;
      EEPROMWriteInt(382, OS192);

    
      return 0;
    }
    
    else if(OS193 == 0){
    
      OS193 = Leitura;
      EEPROMWriteInt(384, OS193);
    
      return 0;
    }
    
    else if(OS194 == 0){
    
      OS194 = Leitura;
      EEPROMWriteInt(386, OS194);
    
      return 0;
    }
    
    else if(OS195 == 0){
    
      OS195 = Leitura;
      EEPROMWriteInt(388, OS195);
    
      return 0;
    }
    
    else if(OS196 == 0){
    
      OS196 = Leitura;
      EEPROMWriteInt(390, OS196);
    
      return 0;
    }
    
    else if(OS197 == 0){
    
      OS197 = Leitura;
      EEPROMWriteInt(392, OS197);
    
      return 0;
    }
    
    else if(OS198 == 0){
    
      OS198 = Leitura;
      EEPROMWriteInt(394, OS198);
    
      return 0;
    }
    
    else if(OS199 == 0){
    
      OS199 = Leitura;
      EEPROMWriteInt(396, OS199);
    
      return 0;
    }
    
    else if(OS200 == 0){
    
      OS200 = Leitura;
      EEPROMWriteInt(398, OS200);
    
      return 0;
    }
    
    else{

      Serial.println(F("\nSem espaço disponível para escrita."));
      
      return 1;
    }
  }
}
