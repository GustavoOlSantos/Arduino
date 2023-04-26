int OsPintura(int Leitura, int Op){
  // Leitura é a OS Lida no cartão
  // Op é a operação a ser feita, Leitura+Limpeza(1), Escrita(2) ou Apenas Leitura(3)  
  
  //Variáveis Auxiliares
  int OS101 = EEPROMReadInt(200);     int OS102 = EEPROMReadInt(202);
  int OS103 = EEPROMReadInt(204);     int OS104 = EEPROMReadInt(206);
  int OS105 = EEPROMReadInt(208);     int OS106 = EEPROMReadInt(210);
  int OS107 = EEPROMReadInt(212);     int OS108 = EEPROMReadInt(214);
  int OS109 = EEPROMReadInt(216);     int OS110 = EEPROMReadInt(218);
  int OS111 = EEPROMReadInt(220);     int OS112 = EEPROMReadInt(222);
  int OS113 = EEPROMReadInt(224);     int OS114 = EEPROMReadInt(226);
  int OS115 = EEPROMReadInt(228);     int OS116 = EEPROMReadInt(230);
  int OS117 = EEPROMReadInt(232);     int OS118 = EEPROMReadInt(234);
  int OS119 = EEPROMReadInt(236);     int OS120 = EEPROMReadInt(238);
  int OS121 = EEPROMReadInt(240);     int OS122 = EEPROMReadInt(242);
  int OS123 = EEPROMReadInt(244);     int OS124 = EEPROMReadInt(246);
  int OS125 = EEPROMReadInt(248);     int OS126 = EEPROMReadInt(250);
  int OS127 = EEPROMReadInt(252);     int OS128 = EEPROMReadInt(254);
  int OS129 = EEPROMReadInt(256);     int OS130 = EEPROMReadInt(258);
  int OS131 = EEPROMReadInt(260);     int OS132 = EEPROMReadInt(262);
  int OS133 = EEPROMReadInt(264);     int OS134 = EEPROMReadInt(266);
  int OS135 = EEPROMReadInt(268);     int OS136 = EEPROMReadInt(270);
  int OS137 = EEPROMReadInt(272);     int OS138 = EEPROMReadInt(274);
  int OS139 = EEPROMReadInt(276);     int OS140 = EEPROMReadInt(278);
  int OS141 = EEPROMReadInt(280);     int OS142 = EEPROMReadInt(282);
  int OS143 = EEPROMReadInt(284);     int OS144 = EEPROMReadInt(286);
  int OS145 = EEPROMReadInt(288);     int OS146 = EEPROMReadInt(290);
  int OS147 = EEPROMReadInt(292);     int OS148 = EEPROMReadInt(294);
  int OS149 = EEPROMReadInt(296);     int OS150 = EEPROMReadInt(298);
  
  //Para Leitura
  if (Op == 1 or Op == 3){
    Serial.print(F("\nLeitura na Pintura"));
    
   if(Leitura == OS101){

      if(Op == 1) {
        OS101 = 0;
        EEPROMWriteInt(200, OS101);
      }
      
      return 0;
    }
    
    else if(Leitura == OS102){

      if(Op == 1) {
        OS102 = 0;
        EEPROMWriteInt(202, OS102);
      }
      
      return 0;
    }
    
    else if(Leitura == OS103){

      if(Op == 1) {
        OS103 = 0;
        EEPROMWriteInt(204, OS103);
      }
      
      return 0;
    }
    
    else if(Leitura == OS104){
    
      if(Op == 1) {
        OS104 = 0;
        EEPROMWriteInt(206, OS104);
      }
      
      return 0;
    }
    
    else if(Leitura == OS105){

      if(Op == 1) {
        OS105 = 0;
        EEPROMWriteInt(208, OS105);
      }
      
      return 0;
    }
    
    else if(Leitura == OS106){

      if(Op == 1) {
        OS106 = 0;
        EEPROMWriteInt(210, OS106);
      }
      
      return 0;
    }
    
    else if(Leitura == OS107){

      if(Op == 1) {
        OS107 = 0;  
        EEPROMWriteInt(212, OS107);
      }  
      
      return 0;
    }
    
    else if(Leitura == OS108){

      if(Op == 1) {
        OS108 = 0;
        EEPROMWriteInt(214, OS108);
      }
      
      return 0;
    }
    
    else if(Leitura == OS109){
    
      if(Op == 1) {
        OS109 = 0;
        EEPROMWriteInt(216, OS109);
      }
      
      return 0;
    }
    
    else if(Leitura == OS110){

      if(Op == 1) {
        OS110 = 0;
        EEPROMWriteInt(218, OS110);
      }
      
      return 0;
    }
    
    else if(Leitura == OS111){
    
      if(Op == 1) {
        OS111 = 0;
        EEPROMWriteInt(220, OS111);
      }
      
      return 0;
    }
    
    else if(Leitura == OS112){

      if(Op == 1) {
        OS112 = 0;
        EEPROMWriteInt(222, OS112);
      }
      
      return 0;
    }
    
    else if(Leitura == OS113){
    
      if(Op == 1) {
        OS113 = 0;
        EEPROMWriteInt(224, OS113);
      }
      
      return 0;
    }
    
    else if(Leitura == OS114){
    
      if(Op == 1) {
        OS114 = 0;
        EEPROMWriteInt(226, OS114);
      }  
      
      return 0;
    }
    
    else if(Leitura == OS115){

      if(Op == 1) {
        OS115 = 0;
        EEPROMWriteInt(228, OS115);
      }
      
      return 0;
    }
    
    else if(Leitura == OS116){

      if(Op == 1) {
        OS116 = 0;
        EEPROMWriteInt(230, OS116);
      }
      return 0;
    }
    
    else if(Leitura == OS117){

      if(Op == 1) {
        OS117 = 0;
        EEPROMWriteInt(232, OS117);
      }
      return 0;
    }
    
    else if(Leitura == OS118){
    
      if(Op == 1) {
        OS118 = 0;
        EEPROMWriteInt(234, OS118);
      }
      return 0;
    }
    
    else if(Leitura == OS119){

      if(Op == 1) {
        OS119 = 0;
        EEPROMWriteInt(236, OS119);
      }
      return 0;
    }
    
    else if(Leitura == OS120){
    
      if(Op == 1) {
        OS120 = 0;
        EEPROMWriteInt(238, OS120);
      }
      return 0;
    }
    
    else if(Leitura == OS121){
    
      if(Op == 1) {
        OS121 = 0;
        EEPROMWriteInt(240, OS121);
      }
      return 0;
    }
    
    else if(Leitura == OS122){
    
      if(Op == 1) {
        OS122 = 0;
        EEPROMWriteInt(242, OS122);
      }
      return 0;
    }
    
    else if(Leitura == OS123){

      if(Op == 1) {
        OS123 = 0;
        EEPROMWriteInt(244, OS123);
      }
      return 0;
    }
    
    else if(Leitura == OS124){
    
      if(Op == 1) {
        OS124 = 0;
        EEPROMWriteInt(246, OS124);
      }
      return 0;
    }
    
    else if(Leitura == OS125){
    
      if(Op == 1) {
        OS125 = 0;
        EEPROMWriteInt(248, OS125);
      }
      return 0;
    }
    
    else if(Leitura == OS126){
    
      if(Op == 1) {
        OS126 = 0;
        EEPROMWriteInt(250, OS126);
      }
      return 0;
    }
    
    else if(Leitura == OS127){
    
      if(Op == 1) {
        OS127 = 0;
        EEPROMWriteInt(252, OS127);
      }
      return 0;
    }
    
    else if(Leitura == OS128){
    
      if(Op == 1) {
        OS128 = 0;
        EEPROMWriteInt(254, OS128);
      }
      return 0;
    }
    
    else if(Leitura == OS129){
    
      if(Op == 1) {
        OS129 = 0;
        EEPROMWriteInt(256, OS129);
      }
      return 0;
    }
    
    else if(Leitura == OS130){
    
      if(Op == 1) {
        OS130 = 0;
        EEPROMWriteInt(258, OS130);
      }
      return 0;
    }
    
    else if(Leitura == OS131){
    
      if(Op == 1) {
        OS131 = 0;
        EEPROMWriteInt(260, OS131);
      }
      return 0;
    }
    
    else if(Leitura == OS132){
    
      if(Op == 1) {
        OS132 = 0;
        EEPROMWriteInt(262, OS132);
      }
      return 0;
    }
    
    else if(Leitura == OS133){
    
      if(Op == 1) {
        OS133 = 0;
        EEPROMWriteInt(264, OS133);
      }
      return 0;
    }
    
    else if(Leitura == OS134){
    
      if(Op == 1) {
        OS134 = 0;
        EEPROMWriteInt(266, OS134);
      }
      return 0;
    }
    
    else if(Leitura == OS135){

       if(Op == 1) {
        OS135 = 0;
        EEPROMWriteInt(268, OS135);
       }
      return 0;
    }
    
    else if(Leitura == OS136){
    
      if(Op == 1) {
        OS136 = 0;
        EEPROMWriteInt(270, OS136);
      }
      return 0;
    }
    
    else if(Leitura == OS137){
    
      if(Op == 1) {
        OS137 = 0;
        EEPROMWriteInt(272, OS137);
      }
      return 0;
    }
    
    else if(Leitura == OS138){
    
      if(Op == 1) {
        OS138 = 0;
        EEPROMWriteInt(274, OS138);
      }
      return 0;
    }
    
    else if(Leitura == OS139){
    
      if(Op == 1) {
        OS139 = 0;
        EEPROMWriteInt(276, OS139);
      }
      return 0;
    }
    
    else if(Leitura == OS140){
    
      if(Op == 1) {
        OS140 = 0;
        EEPROMWriteInt(278, OS140);
      }
      return 0;
    }
    
    else if(Leitura == OS141){

      if(Op == 1) {
        OS141 = 0;
        EEPROMWriteInt(280, OS141);
      }
      
      return 0;
    }
    
    else if(Leitura == OS142){
    
      if(Op == 1) {
        OS142 = 0;
        EEPROMWriteInt(282, OS142);
      }
      
      return 0;
    }
    
    else if(Leitura == OS143){
    
      if(Op == 1) {
        OS143 = 0;
        EEPROMWriteInt(284, OS143);
      }
      
      return 0;
    }
    
    else if(Leitura == OS144){
    
      if(Op == 1) {
        OS144 = 0;
        EEPROMWriteInt(286, OS144);
      }
      
      return 0;
    }
    
    else if(Leitura == OS145){
    
      if(Op == 1) {
        OS145 = 0;
        EEPROMWriteInt(288, OS145);
      }
      
      return 0;
    }
    
    else if(Leitura == OS146){
    
      if(Op == 1) {
        OS146 = 0;
        EEPROMWriteInt(290, OS146);
      }
      
      return 0;
    }
    
    else if(Leitura == OS147){
    
      if(Op == 1) {
        OS147 = 0;
        EEPROMWriteInt(292, OS147);
      }
      
      return 0;
    }
    
    else if(Leitura == OS148){
    
      if(Op == 1) {
        OS148 = 0;
        EEPROMWriteInt(294, OS148);
      }
      
      return 0;
    }
    
    else if(Leitura == OS149){
    
      if(Op == 1) {
        OS149 = 0;
        EEPROMWriteInt(296, OS149);
      }
      
      return 0;
    }
    
    else if(Leitura == OS150){
    
      if(Op == 1) {
        OS150 = 0;
        EEPROMWriteInt(298, OS150);
      }
      
      return 0;
    }

    else{

      Serial.println("\tOS não encontrada no setor anterior.");
      return 1;
    }
  }

// ------------------------------------------------------------------------------------------------------------------------------------------- //

  //Para Escrita:
  else if(Op == 2){

    if(OS101 == 0){

      OS101 = Leitura;
      EEPROMWriteInt(200, OS101);
    
      return 0;
    }
    
    else if(OS102 == 0){
    
      OS102 = Leitura;
      EEPROMWriteInt(202, OS102);
    
      return 0;
    }
    
    else if(OS103 == 0){
    
      OS103 = Leitura;
      EEPROMWriteInt(204, OS103);
    
      return 0;
    }
    
    else if(OS104 == 0){
    
      OS104 = Leitura;
      EEPROMWriteInt(206, OS104);
    
      return 0;
    }
    
    else if(OS105 == 0){
    
      OS105 = Leitura;
      EEPROMWriteInt(208, OS105);
    
      return 0;
    }
    
    else if(OS106 == 0){
    
      OS106 = Leitura;
      EEPROMWriteInt(210, OS106);
    
      return 0;
    }
    
    else if(OS107 == 0){
    
      OS107 = Leitura;
      EEPROMWriteInt(212, OS107);
    
      return 0;
    }
    
    else if(OS108 == 0){
    
      OS108 = Leitura;
      EEPROMWriteInt(214, OS108);
    
      return 0;
    }
    
    else if(OS109 == 0){
    
      OS109 = Leitura;
      EEPROMWriteInt(216, OS109);
    
      return 0;
    }
    
    else if(OS110 == 0){
    
      OS110 = Leitura;
      EEPROMWriteInt(218, OS110);
    
      return 0;
    }
    
    else if(OS111 == 0){
    
      OS111 = Leitura;
      EEPROMWriteInt(220, OS111);
    
      return 0;
    }
    
    else if(OS112 == 0){
    
      OS112 = Leitura;
      EEPROMWriteInt(222, OS112);
    
      return 0;
    }
    
    else if(OS113 == 0){
    
      OS113 = Leitura;
      EEPROMWriteInt(224, OS113);
    
      return 0;
    }
    
    else if(OS114 == 0){
    
      OS114 = Leitura;
      EEPROMWriteInt(226, OS114);
    
      return 0;
    }
    
    else if(OS115 == 0){
    
      OS115 = Leitura;
      EEPROMWriteInt(228, OS115);
    
      return 0;
    }
    
    else if(OS116 == 0){
    
      OS116 = Leitura;
      EEPROMWriteInt(230, OS116);
    
      return 0;
    }
    
    else if(OS117 == 0){
    
      OS117 = Leitura;
      EEPROMWriteInt(232, OS117);
    
      return 0;
    }
    
    else if(OS118 == 0){
    
      OS118 = Leitura;
      EEPROMWriteInt(234, OS118);
    
      return 0;
    }
    
    else if(OS119 == 0){
    
      OS119 = Leitura;
      EEPROMWriteInt(236, OS119);
    
      return 0;
    }
    
    else if(OS120 == 0){
    
      OS120 = Leitura;
      EEPROMWriteInt(238, OS120);
    
      return 0;
    }
    
    else if(OS121 == 0){
    
      OS121 = Leitura;
      EEPROMWriteInt(240, OS121);
    
      return 0;
    }
    
    else if(OS122 == 0){
    
      OS122 = Leitura;
      EEPROMWriteInt(242, OS122);
    
      return 0;
    }
    
    else if(OS123 == 0){
    
      OS123 = Leitura;
      EEPROMWriteInt(244, OS123);
    
      return 0;
    }
    
    else if(OS124 == 0){
    
      OS124 = Leitura;
      EEPROMWriteInt(246, OS124);
    
      return 0;
    }
    
    else if(OS125 == 0){
    
      OS125 = Leitura;
      EEPROMWriteInt(248, OS125);
    
      return 0;
    }
    
    else if(OS126 == 0){
    
      OS126 = Leitura;
      EEPROMWriteInt(250, OS126);
    
      return 0;
    }
    
    else if(OS127 == 0){
    
      OS127 = Leitura;
      EEPROMWriteInt(252, OS127);
    
      return 0;
    }
    
    else if(OS128 == 0){
    
      OS128 = Leitura;
      EEPROMWriteInt(254, OS128);
    
      return 0;
    }
    
    else if(OS129 == 0){
    
      OS129 = Leitura;
      EEPROMWriteInt(256, OS129);
    
      return 0;
    }
    
    else if(OS130 == 0){
    
      OS130 = Leitura;
      EEPROMWriteInt(258, OS130);
    
      return 0;
    }
    
    else if(OS131 == 0){
    
      OS131 = Leitura;
      EEPROMWriteInt(260, OS131);
    
      return 0;
    }
    
    else if(OS132 == 0){
    
      OS132 = Leitura;
      EEPROMWriteInt(262, OS132);
    
      return 0;
    }
    
    else if(OS133 == 0){
    
      OS133 = Leitura;
      EEPROMWriteInt(264, OS133);
    
      return 0;
    }
    
    else if(OS134 == 0){
    
      OS134 = Leitura;
      EEPROMWriteInt(266, OS134);
    
      return 0;
    }
    
    else if(OS135 == 0){
    
      OS135 = Leitura;
      EEPROMWriteInt(268, OS135);
    
      return 0;
    }
    
    else if(OS136 == 0){
    
      OS136 = Leitura;
      EEPROMWriteInt(270, OS136);
    
      return 0;
    }
    
    else if(OS137 == 0){
    
      OS137 = Leitura;
      EEPROMWriteInt(272, OS137);
    
      return 0;
    }
    
    else if(OS138 == 0){
    
      OS138 = Leitura;
      EEPROMWriteInt(274, OS138);
    
      return 0;
    }
    
    else if(OS139 == 0){
    
      OS139 = Leitura;
      EEPROMWriteInt(276, OS139);
    
      return 0;
    }
    
    else if(OS140 == 0){
    
      OS140 = Leitura;
      EEPROMWriteInt(278, OS140);
    
      return 0;
    }
    
    else if(OS141 == 0){
    
      OS141 = Leitura;
      EEPROMWriteInt(280, OS141);
    
      return 0;
    }
    
    else if(OS142 == 0){
    
      OS142 = Leitura;
      EEPROMWriteInt(282, OS142);
    
      return 0;
    }
    
    else if(OS143 == 0){
    
      OS143 = Leitura;
      EEPROMWriteInt(284, OS143);
    
      return 0;
    }
    
    else if(OS144 == 0){
    
      OS144 = Leitura;
      EEPROMWriteInt(286, OS144);
    
      return 0;
    }
    
    else if(OS145 == 0){
    
      OS145 = Leitura;
      EEPROMWriteInt(288, OS145);
    
      return 0;
    }
    
    else if(OS146 == 0){
    
      OS146 = Leitura;
      EEPROMWriteInt(290, OS146);
    
      return 0;
    }
    
    else if(OS147 == 0){
    
      OS147 = Leitura;
      EEPROMWriteInt(292, OS147);
    
      return 0;
    }
    
    else if(OS148 == 0){
    
      OS148 = Leitura;
      EEPROMWriteInt(294, OS148);
    
      return 0;
    }
    
    else if(OS149 == 0){
    
      OS149 = Leitura;
      EEPROMWriteInt(296, OS149);
    
      return 0;
    }
    
    else if(OS150 == 0){
    
      OS150 = Leitura;
      EEPROMWriteInt(298, OS150);
    
      return 0;
    }

    else{

      Serial.println("Sem espaço disponível para escrita.");
      
      return 1;
    }
  }
}
