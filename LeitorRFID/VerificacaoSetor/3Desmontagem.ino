int OsDesmontagem(int Leitura, int Op){
  // Leitura é a OS Lida no cartão
  // Op é a operação a ser feita, Leitura+Limpeza(1), Escrita(2) ou Apenas Leitura(3)
  
  //Variáveis Auxiliares
  int OS51 = EEPROMReadInt(100);     int OS52 = EEPROMReadInt(102);
  int OS53 = EEPROMReadInt(104);     int OS54 = EEPROMReadInt(106);
  int OS55 = EEPROMReadInt(108);     int OS56 = EEPROMReadInt(110);
  int OS57 = EEPROMReadInt(112);     int OS58 = EEPROMReadInt(114);
  int OS59 = EEPROMReadInt(116);     int OS60 = EEPROMReadInt(118);
  int OS61 = EEPROMReadInt(120);     int OS62 = EEPROMReadInt(122);
  int OS63 = EEPROMReadInt(124);     int OS64 = EEPROMReadInt(126);
  int OS65 = EEPROMReadInt(128);     int OS66 = EEPROMReadInt(130);
  int OS67 = EEPROMReadInt(132);     int OS68 = EEPROMReadInt(134);
  int OS69 = EEPROMReadInt(136);     int OS70 = EEPROMReadInt(138);
  int OS71 = EEPROMReadInt(140);     int OS72 = EEPROMReadInt(142);
  int OS73 = EEPROMReadInt(144);     int OS74 = EEPROMReadInt(146);  
  int OS75 = EEPROMReadInt(148);     int OS76 = EEPROMReadInt(150);
  int OS77 = EEPROMReadInt(152);     int OS78 = EEPROMReadInt(154);
  int OS79 = EEPROMReadInt(156);     int OS80 = EEPROMReadInt(158);
  int OS81 = EEPROMReadInt(160);     int OS82 = EEPROMReadInt(162);
  int OS83 = EEPROMReadInt(164);     int OS84 = EEPROMReadInt(166);
  int OS85 = EEPROMReadInt(168);     int OS86 = EEPROMReadInt(170);
  int OS87 = EEPROMReadInt(172);     int OS88 = EEPROMReadInt(174);
  int OS89 = EEPROMReadInt(176);     int OS90 = EEPROMReadInt(178);  
  int OS91 = EEPROMReadInt(180);     int OS92 = EEPROMReadInt(182);
  int OS93 = EEPROMReadInt(184);     int OS94 = EEPROMReadInt(186);
  int OS95 = EEPROMReadInt(188);     int OS96 = EEPROMReadInt(190);
  int OS97 = EEPROMReadInt(192);     int OS98 = EEPROMReadInt(194);
  int OS99 = EEPROMReadInt(166);     int OS100 = EEPROMReadInt(198);
  
  //Para Leitura
  if (Op == 1 or Op == 3){
    Serial.print(F("\nLeitura na Desmontagem"));
    
   if(Leitura == OS51){

      if(Op == 1) {
        OS51 = 0;
        EEPROMWriteInt(100, OS51);
      }
      
      return 0;
    }
    
    else if(Leitura == OS52){

      if(Op == 1) {
        OS52 = 0;
        EEPROMWriteInt(102, OS52);
      }
      
      return 0;
    }
    
    else if(Leitura == OS53){

      if(Op == 1) {
        OS53 = 0;
        EEPROMWriteInt(104, OS53);
      }
    
      return 0;
    }
    
    else if(Leitura == OS54){

      if(Op == 1) {
        OS54 = 0; 
        EEPROMWriteInt(106, OS54);
      }
      
      return 0;
    }
    
    else if(Leitura == OS55){

      if(Op == 1) {
        OS55 = 0;
        EEPROMWriteInt(108, OS55);
      }
      
      return 0;
    }
    
    else if(Leitura == OS56){

      if(Op == 1) {
        OS56 = 0;
        EEPROMWriteInt(110, OS56);
      }
      
      return 0;
    }
    
    else if(Leitura == OS57){

      if(Op == 1) {
        OS57 = 0;
        EEPROMWriteInt(112, OS57);
      }
      
      return 0;
    }
    
    else if(Leitura == OS58){

      if(Op == 1) {
        OS58 = 0;
        EEPROMWriteInt(114, OS58);
      }
      
      return 0;
    }
    
    else if(Leitura == OS59){

      if(Op == 1) {    
        OS59 = 0;
        EEPROMWriteInt(116, OS59);
      }
    
      return 0;
    }
    
    else if(Leitura == OS60){

      if(Op == 1) {
        OS60 = 0;
        EEPROMWriteInt(118, OS60);
      }
      
      return 0;
    }
    
    else if(Leitura == OS61){

      if(Op == 1) {
        OS61 = 0;
        EEPROMWriteInt(120, OS61);
      }
      
      return 0;
    }
    
    else if(Leitura == OS62){

      if(Op == 1) {
        OS62 = 0;
        EEPROMWriteInt(122, OS62);
      }
      
      return 0;
    }
    
    else if(Leitura == OS63){

      if(Op == 1) {
        OS63 = 0;
        EEPROMWriteInt(124, OS63);
      }
      
      return 0;
    }
    
    else if(Leitura == OS64){

      if(Op == 1) {
        OS64 = 0;
        EEPROMWriteInt(126, OS64);
      }
      
      return 0;
    }
    
    else if(Leitura == OS65){

      if(Op == 1) {
        OS65 = 0;
        EEPROMWriteInt(128, OS65);
      }
      
      return 0;
    }
    
    else if(Leitura == OS66){
    
      if(Op == 1) {
        OS66 = 0;
        EEPROMWriteInt(130, OS66);
      }
      
      return 0;
    }
    
    else if(Leitura == OS67){
      
      if(Op == 1) {   
        OS67 = 0;
        EEPROMWriteInt(132, OS67);
      }
    
      return 0;
    }
    
    else if(Leitura == OS68){

      if(Op == 1) {
        OS68 = 0;
        EEPROMWriteInt(134, OS68);
      }
      
      return 0;
    }
    
    else if(Leitura == OS69){

      if(Op == 1) {
        OS69 = 0;
        EEPROMWriteInt(136, OS69);
      }
      
      return 0;
    }
    
    else if(Leitura == OS70){
    
        if(Op == 1) {
          OS70 = 0;
          EEPROMWriteInt(138, OS70);
        }
      
      return 0;
    }
    
    else if(Leitura == OS71){
    
      if(Op == 1) {
        OS71 = 0;
        EEPROMWriteInt(140, OS71);
      }
      
      return 0;
    }
    
    else if(Leitura == OS72){
    
      if(Op == 1) {
        OS72 = 0;
        EEPROMWriteInt(142, OS72);
      }
      
      return 0;
    }
    
    else if(Leitura == OS73){
    
      if(Op == 1) {
        OS73 = 0;
        EEPROMWriteInt(144, OS73);
      }
      
      return 0;
    }
    
    else if(Leitura == OS74){
    
      if(Op == 1) {
        OS74 = 0;
        EEPROMWriteInt(146, OS74);
      }    
      return 0;
    }
    
    else if(Leitura == OS75){

      if(Op == 1) {
        OS75 = 0;
        EEPROMWriteInt(148, OS75);      
      }
      return 0;
    }
    
    else if(Leitura == OS76){

      if(Op == 1) {
        OS76 = 0; 
        EEPROMWriteInt(150, OS76);
      }    
      return 0;
    }
    
    else if(Leitura == OS77){
    
      if(Op == 1) {
        OS77 = 0;
        EEPROMWriteInt(152, OS77);      
      }
      return 0;
    }
    
    else if(Leitura == OS78){
    
      if(Op == 1) {
        OS78 = 0;
        EEPROMWriteInt(154, OS78);      
      }
      return 0;
    }
    
    else if(Leitura == OS79){
    
      if(Op == 1) {
        OS79 = 0;
        EEPROMWriteInt(156, OS79);      
      }
      return 0;
    }
    
    else if(Leitura == OS80){
    
      if(Op == 1) {
        OS80 = 0;
        EEPROMWriteInt(158, OS80);      
      }
      return 0;
    }
    
    else if(Leitura == OS81){
    
      if(Op == 1) {
        OS81 = 0;
        EEPROMWriteInt(160, OS81);    
      }
      return 0;
    }
    
    else if(Leitura == OS82){
    
      if(Op == 1) {
        OS82 = 0;
        EEPROMWriteInt(162, OS82);      
      }
      return 0;
    }
    
    else if(Leitura == OS83){
    
      if(Op == 1) {
        OS83 = 0;
        EEPROMWriteInt(164, OS83);      
      }
      return 0;
    }
    
    else if(Leitura == OS84){
    
      if(Op == 1) {
        OS84 = 0;
        EEPROMWriteInt(166, OS84);      
      }
      return 0;
    }
    
    else if(Leitura == OS85){
    
      if(Op == 1) {
        OS85 = 0;
        EEPROMWriteInt(168, OS85);      
      }    
      return 0;
    }
    
    else if(Leitura == OS86){

      if(Op == 1) {
        OS86 = 0;
        EEPROMWriteInt(170, OS86);    
      }
      return 0;
    }
    
    else if(Leitura == OS87){

      if(Op == 1) {
        OS87 = 0;
        EEPROMWriteInt(172, OS87);      
      }
      return 0;
    }
    
    else if(Leitura == OS88){

      if(Op == 1) {
        OS88 = 0;
        EEPROMWriteInt(174, OS88);      
      }
      return 0;
    }
    
    else if(Leitura == OS89){
    
      if(Op == 1) {
        OS89 = 0;
        EEPROMWriteInt(176, OS89);      
      }
      return 0;
    }
    
    else if(Leitura == OS90){
    
      if(Op == 1) {
        OS90 = 0;
        EEPROMWriteInt(178, OS90);      
      }
      return 0;
    }

    else if(Leitura == OS91){
    
      if(Op == 1) {
        OS91 = 0;
        EEPROMWriteInt(180, OS91);      
      }
      return 0;
    }

    else if(Leitura == OS92){
    
      if(Op == 1) {
        OS92 = 0;
        EEPROMWriteInt(182, OS92);      
      }
      return 0;
    }

    else if(Leitura == OS93){
    
      if(Op == 1) {
        OS93 = 0;
        EEPROMWriteInt(184, OS93);      
      }
      return 0;
    }

    else if(Leitura == OS94){
    
      if(Op == 1) {
        OS94 = 0;
        EEPROMWriteInt(186, OS94);      
      }
      return 0;
    }

    else if(Leitura == OS95){
    
      if(Op == 1) {
        OS95 = 0;
        EEPROMWriteInt(188, OS95);      
      }
      return 0;
    }

    else if(Leitura == OS96){
    
      if(Op == 1) {
        OS96 = 0;
        EEPROMWriteInt(190, OS96);      
      }
      return 0;
    }

    else if(Leitura == OS97){
    
      if(Op == 1) {
        OS97 = 0;
        EEPROMWriteInt(192, OS97);      
      }
      return 0;
    }

    else if(Leitura == OS98){
    
      if(Op == 1) {
        OS98 = 0;
        EEPROMWriteInt(194, OS98);      
      }
      return 0;
    }

    else if(Leitura == OS99){
    
      if(Op == 1) {
        OS99 = 0;
        EEPROMWriteInt(196, OS99);      
      }
      return 0;
    }

    else if(Leitura == OS100){
    
      if(Op == 1) {
        OS100 = 0;
        EEPROMWriteInt(198, OS100);      
      }
      return 0;
    }

    else{

      Serial.println(F("\tOS não encontrada no setor anterior."));
      return 1;
    }
  }

// --------------------------------------------------------------------------------------------------------------------------------------------------------- //
  
  //Para Escrita:
  else if(Op == 2){
    Serial.println(F("\nEscrita na Desmontagem"));
    
    if(OS51 == 0){

      OS51 = Leitura;
      EEPROMWriteInt(100, OS51);
    
      return 0;
    }
    
    else if(OS52 == 0){
    
      OS52 = Leitura;
      EEPROMWriteInt(102, OS52);
    
      return 0;
    }
    
    else if(OS53 == 0){
    
      OS53 = Leitura;
      EEPROMWriteInt(104, OS53);
    
      return 0;
    }
    
    else if(OS54 == 0){
    
      OS54 = Leitura;
      EEPROMWriteInt(106, OS54);
    
      return 0;
    }
    
    else if(OS55 == 0){
    
      OS55 = Leitura;
      EEPROMWriteInt(108, OS55);
    
      return 0;
    }
    
    else if(OS56 == 0){
    
      OS56 = Leitura;
      EEPROMWriteInt(110, OS56);
    
      return 0;
    }
    
    else if(OS57 == 0){
    
      OS57 = Leitura;
      EEPROMWriteInt(112, OS57);
    
      return 0;
    }
    
    else if(OS58 == 0){
    
      OS58 = Leitura;
      EEPROMWriteInt(114, OS58);
    
      return 0;
    }
    
    else if(OS59 == 0){
    
      OS59 = Leitura;
      EEPROMWriteInt(116, OS59);
    
      return 0;
    }
    
    else if(OS60 == 0){
    
      OS60 = Leitura;
      EEPROMWriteInt(118, OS60);
    
      return 0;
    }
    
    else if(OS61 == 0){
    
      OS61 = Leitura;
      EEPROMWriteInt(120, OS61);
    
      return 0;
    }
    
    else if(OS62 == 0){
    
      OS62 = Leitura;
      EEPROMWriteInt(122, OS62);
    
      return 0;
    }
    
    else if(OS63 == 0){
    
      OS63 = Leitura;
      EEPROMWriteInt(124, OS63);
    
      return 0;
    }
    
    else if(OS64 == 0){
    
      OS64 = Leitura;
      EEPROMWriteInt(126, OS64);
    
      return 0;
    }
    
    else if(OS65 == 0){
    
      OS65 = Leitura;
      EEPROMWriteInt(128, OS65);
    
      return 0;
    }
    
    else if(OS66 == 0){
    
      OS66 = Leitura;
      EEPROMWriteInt(130, OS66);
    
      return 0;
    }
    
    else if(OS67 == 0){
    
      OS67 = Leitura;
      EEPROMWriteInt(132, OS67);
    
      return 0;
    }
    
    else if(OS68 == 0){
    
      OS68 = Leitura;
      EEPROMWriteInt(134, OS68);
    
      return 0;
    }
    
    else if(OS69 == 0){
    
      OS69 = Leitura;
      EEPROMWriteInt(136, OS69);
    
      return 0;
    }
    
    else if(OS70 == 0){
    
      OS70 = Leitura;
      EEPROMWriteInt(138, OS70);
    
      return 0;
    }
    
    else if(OS71 == 0){
    
      OS71 = Leitura;
      EEPROMWriteInt(140, OS71);
    
      return 0;
    }
    
    else if(OS72 == 0){
    
      OS72 = Leitura;
      EEPROMWriteInt(142, OS72);
    
      return 0;
    }
    
    else if(OS73 == 0){
    
      OS73 = Leitura;
      EEPROMWriteInt(144, OS73);
    
      return 0;
    }
    
    else if(OS74 == 0){
    
      OS74 = Leitura;
      EEPROMWriteInt(146, OS74);
    
      return 0;
    }
    
    else if(OS75 == 0){
    
      OS75 = Leitura;
      EEPROMWriteInt(148, OS75);
    
      return 0;
    }
    
    else if(OS76 == 0){
    
      OS76 = Leitura;
      EEPROMWriteInt(150, OS76);
    
      return 0;
    }
    
    else if(OS77 == 0){
    
      OS77 = Leitura;
      EEPROMWriteInt(152, OS77);
    
      return 0;
    }
    
    else if(OS78 == 0){
    
      OS78 = Leitura;
      EEPROMWriteInt(154, OS78);
    
      return 0;
    }
    
    else if(OS79 == 0){
    
      OS79 = Leitura;
      EEPROMWriteInt(156, OS79);
    
      return 0;
    }
    
    else if(OS80 == 0){
    
      OS80 = Leitura;
      EEPROMWriteInt(158, OS80);
    
      return 0;
    }
    
    else if(OS81 == 0){
    
      OS81 = Leitura;
      EEPROMWriteInt(160, OS81);
    
      return 0;
    }
    
    else if(OS82 == 0){
    
      OS82 = Leitura;
      EEPROMWriteInt(162, OS82);
    
      return 0;
    }
    
    else if(OS83 == 0){
    
      OS83 = Leitura;
      EEPROMWriteInt(164, OS83);
    
      return 0;
    }
    
    else if(OS84 == 0){
    
      OS84 = Leitura;
      EEPROMWriteInt(166, OS84);
    
      return 0;
    }
    
    else if(OS85 == 0){
    
      OS85 = Leitura;
      EEPROMWriteInt(168, OS85);
    
      return 0;
    }
    
    else if(OS86 == 0){
    
      OS86 = Leitura;
      EEPROMWriteInt(170, OS86);
    
      return 0;
    }
    
    else if(OS87 == 0){
    
      OS87 = Leitura;
      EEPROMWriteInt(172, OS87);
    
      return 0;
    }
    
    else if(OS88 == 0){
    
      OS88 = Leitura;
      EEPROMWriteInt(174, OS88);
    
      return 0;
    }
    
    else if(OS89 == 0){
    
      OS89 = Leitura;
      EEPROMWriteInt(176, OS89);
    
      return 0;
    }
    
    else if(OS90 == 0){
    
      OS90 = Leitura;
      EEPROMWriteInt(178, OS90);
    
      return 0;
    }
    
    else if(OS91 == 0){
    
      OS91 = Leitura;
      EEPROMWriteInt(180, OS91);
    
      return 0;
    }
    
    else if(OS92 == 0){
    
      OS92 = Leitura;
      EEPROMWriteInt(182, OS92);
    
      return 0;
    }
    
    else if(OS93 == 0){
    
      OS93 = Leitura;
      EEPROMWriteInt(184, OS93);
    
      return 0;
    }
    
    else if(OS94 == 0){
    
      OS94 = Leitura;
      EEPROMWriteInt(186, OS94);
    
      return 0;
    }
    
    else if(OS95 == 0){
    
      OS95 = Leitura;
      EEPROMWriteInt(188, OS95);
    
      return 0;
    }
    
    else if(OS96 == 0){
    
      OS96 = Leitura;
      EEPROMWriteInt(190, OS96);
    
      return 0;
    }
    
    else if(OS97 == 0){
    
      OS97 = Leitura;
      EEPROMWriteInt(192, OS97);
    
      return 0;
    }
    
    else if(OS98 == 0){
    
      OS98 = Leitura;
      EEPROMWriteInt(194, OS98);
    
      return 0;
    }
    
    else if(OS99 == 0){
    
      OS99 = Leitura;
      EEPROMWriteInt(196, OS99);
    
      return 0;
    }
    
    else if(OS100 == 0){
    
      OS100 = Leitura;
      EEPROMWriteInt(198, OS100);
    
      return 0;
    }

    else{

      Serial.println(F("Sem espaço disponível para escrita."));

      return 1;
    }
  }
}
