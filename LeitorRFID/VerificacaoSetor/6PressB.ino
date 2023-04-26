int OsPressurizacaoB(int Leitura, int Op){
  // Leitura é a OS Lida no cartão
  // Op é a operação a ser feita, Leitura+Limpeza(1), Escrita(2) ou Apenas Leitura(3)    
  
  //Variáveis Auxiliares
  int OS201 = EEPROMReadInt(400);     int OS202 = EEPROMReadInt(402);
  int OS203 = EEPROMReadInt(404);     int OS204 = EEPROMReadInt(406);
  int OS205 = EEPROMReadInt(408);     int OS206 = EEPROMReadInt(410);
  int OS207 = EEPROMReadInt(412);     int OS208 = EEPROMReadInt(414);
  int OS209 = EEPROMReadInt(416);     int OS210 = EEPROMReadInt(418);
  int OS211 = EEPROMReadInt(420);     int OS212 = EEPROMReadInt(422);
  int OS213 = EEPROMReadInt(424);     int OS214 = EEPROMReadInt(426);
  int OS215 = EEPROMReadInt(428);     int OS216 = EEPROMReadInt(430);
  int OS217 = EEPROMReadInt(432);     int OS218 = EEPROMReadInt(434);
  int OS219 = EEPROMReadInt(436);     int OS220 = EEPROMReadInt(438);
  int OS221 = EEPROMReadInt(440);     int OS222 = EEPROMReadInt(442);
  int OS223 = EEPROMReadInt(444);     int OS224 = EEPROMReadInt(446);
  int OS225 = EEPROMReadInt(448);     int OS226 = EEPROMReadInt(450);
  int OS227 = EEPROMReadInt(452);     int OS228 = EEPROMReadInt(454);
  int OS229 = EEPROMReadInt(456);     int OS230 = EEPROMReadInt(458);
  int OS231 = EEPROMReadInt(460);     int OS232 = EEPROMReadInt(462);
  int OS233 = EEPROMReadInt(464);     int OS234 = EEPROMReadInt(466);
  int OS235 = EEPROMReadInt(468);     int OS236 = EEPROMReadInt(470);
  int OS237 = EEPROMReadInt(472);     int OS238 = EEPROMReadInt(474);
  int OS239 = EEPROMReadInt(476);     int OS240 = EEPROMReadInt(478); 
  int OS241 = EEPROMReadInt(480);     int OS242 = EEPROMReadInt(482);
  int OS243 = EEPROMReadInt(484);     int OS244 = EEPROMReadInt(486);
  int OS245 = EEPROMReadInt(488);     int OS246 = EEPROMReadInt(490);
  int OS247 = EEPROMReadInt(492);     int OS248 = EEPROMReadInt(494);
  int OS249 = EEPROMReadInt(496);     int OS250 = EEPROMReadInt(498);
  

     
  //Para Leitura
  if (Op == 1 or Op == 3){
    Serial.print(F("\nLeitura na Pressurização Baixa"));
    
    if(Leitura == OS201){

      if(Op == 1) {
        OS201 = 0;
        EEPROMWriteInt(400, OS201);
      }
      
      return 0;
      
    }
    
    else if(Leitura == OS202){
    
      if(Op == 1) {
        OS202 = 0;
        EEPROMWriteInt(402, OS202);
      }
      
      return 0;
    }
    
    else if(Leitura == OS203){

    
    if(Op == 1) {  
      OS203 = 0;
      EEPROMWriteInt(404, OS203);
    }
      
      return 0;
    }
    
    else if(Leitura == OS204){
    
     if(Op == 1) { 
      OS204 = 0;
      EEPROMWriteInt(406, OS204);
     }
      
      return 0;
    }
    
    else if(Leitura == OS205){
    
      if(Op == 1) {
        OS205 = 0;
        EEPROMWriteInt(408, OS205);
      }
      
      return 0;
    }
    
    else if(Leitura == OS206){
    
      if(Op == 1) {
        OS206 = 0;
        EEPROMWriteInt(410, OS206);
      }
      
      return 0;
    }
    
    else if(Leitura == OS207){
    
      if(Op == 1) {
        OS207 = 0;
        EEPROMWriteInt(412, OS207);
      }
      
      return 0;
    }
    
    else if(Leitura == OS208){

      if(Op == 1) {
        OS208 = 0;
        EEPROMWriteInt(414, OS208);
      }
      
      return 0;
    }
    
    else if(Leitura == OS209){
    
      if(Op == 1) {
        OS209 = 0;
        EEPROMWriteInt(416, OS209);
      }
      
      return 0;
    }
    
    else if(Leitura == OS210){
    
      if(Op == 1) {
        OS210 = 0;
        EEPROMWriteInt(418, OS210);
      }
      
      return 0;
    }
    
    else if(Leitura == OS211){
    
      if(Op == 1) {
        OS211 = 0;
        EEPROMWriteInt(420, OS211);
      }
      
      return 0;
    }
    
    else if(Leitura == OS212){
    
      if(Op == 1) {
        OS212 = 0;
        EEPROMWriteInt(422, OS212);
      }
      
      return 0;
    }
    
    else if(Leitura == OS213){
    
      if(Op == 1) {
        OS213 = 0;
        EEPROMWriteInt(424, OS213);
      }
      
      return 0;
    }
    
    else if(Leitura == OS214){
    
      if(Op == 1) {
        OS214 = 0;
        EEPROMWriteInt(426, OS214);
      }
      
      return 0;
    }
    
    else if(Leitura == OS215){
    
      if(Op == 1) {
        OS215 = 0;
        EEPROMWriteInt(428, OS215);
      }
      
      return 0;
    }
    
    else if(Leitura == OS216){
    
      if(Op == 1) {
        OS216 = 0;
        EEPROMWriteInt(430, OS216);
      }
      
      return 0;
    }
    
    else if(Leitura == OS217){
    
      if(Op == 1) {
        OS217 = 0;
        EEPROMWriteInt(432, OS217);
      }
      
      return 0;
    }
    
    else if(Leitura == OS218){
    
      if(Op == 1) {
        OS218 = 0;
        EEPROMWriteInt(434, OS218);
      }
      
      return 0;
    }
    
    else if(Leitura == OS219){
    
      if(Op == 1) {
        OS219 = 0;
        EEPROMWriteInt(436, OS219);
      }
      
      return 0;
    }
    
    else if(Leitura == OS220){
    
      if(Op == 1) {
        OS220 = 0;
        EEPROMWriteInt(438, OS220);
      }
      
      return 0;
    }
    
    else if(Leitura == OS221){
    
      if(Op == 1) {
        OS221 = 0;
        EEPROMWriteInt(440, OS221);
      }
      
      return 0;
    }
    
    else if(Leitura == OS222){
    
      if(Op == 1) {
        OS222 = 0;
        EEPROMWriteInt(442, OS222);
      }
      
      return 0;
    }
    
    else if(Leitura == OS223){
    
      if(Op == 1) {
        OS223 = 0;
        EEPROMWriteInt(444, OS223);
      }
      
      return 0;
    }
    
    else if(Leitura == OS224){
    
      if(Op == 1) {
        OS224 = 0;
        EEPROMWriteInt(446, OS224);
      }
      
      return 0;
    }
    
    else if(Leitura == OS225){
    
      if(Op == 1) {
        OS225 = 0;
        EEPROMWriteInt(448, OS225);
      }
      
      return 0;
    }
    
    else if(Leitura == OS226){
    
      if(Op == 1) {
        OS226 = 0;
        EEPROMWriteInt(450, OS226);
      }
      
      return 0;
    }
    
    else if(Leitura == OS227){
    
      if(Op == 1) {
        OS227 = 0;
        EEPROMWriteInt(452, OS227);
      }
      
      return 0;
    }
    
    else if(Leitura == OS228){
    
      if(Op == 1) {
        OS228 = 0;
        EEPROMWriteInt(454, OS228);
      }
      
      return 0;
    }
    
    else if(Leitura == OS229){
    
      if(Op == 1) {
        OS229 = 0;
        EEPROMWriteInt(456, OS229);
      }
      
      return 0;
    }
    
    else if(Leitura == OS230){
    
      if(Op == 1) {
        OS230 = 0;
        EEPROMWriteInt(458, OS230);
      }
      
      return 0;
    }
    
    else if(Leitura == OS231){
    
      if(Op == 1) {
        OS231 = 0;
        EEPROMWriteInt(460, OS231);
      }
      
      return 0;
    }
    
    else if(Leitura == OS232){
    
      if(Op == 1) {
        OS232 = 0;
        EEPROMWriteInt(462, OS232);
      }
      
      return 0;
    }
    
    else if(Leitura == OS233){
    
      if(Op == 1) {
        OS233 = 0;
        EEPROMWriteInt(464, OS233);
      }
      
      return 0;
    }
    
    else if(Leitura == OS234){
    
      if(Op == 1) {
        OS234 = 0;
        EEPROMWriteInt(466, OS234);
      }
      
      return 0;
    }
    
    else if(Leitura == OS235){
    
      if(Op == 1) {
        OS235 = 0;
        EEPROMWriteInt(468, OS235);
      }
      
      return 0;
    }
    
    else if(Leitura == OS236){
    
      if(Op == 1) {
        OS236 = 0;
        EEPROMWriteInt(470, OS236);
      }
      
      return 0;
    }
    
    else if(Leitura == OS237){
    
      if(Op == 1) {
        OS237 = 0;
        EEPROMWriteInt(472, OS237);
      }
      
      return 0;
    }
    
    else if(Leitura == OS238){
    
      if(Op == 1) {
        OS238 = 0;
        EEPROMWriteInt(474, OS238);
      }
      
      return 0;
    }
    
    else if(Leitura == OS239){
    
      if(Op == 1) {
        OS239 = 0;
        EEPROMWriteInt(476, OS239);
      }
      
      return 0;
    }
    
    else if(Leitura == OS240){
    
      if(Op == 1) {
        OS240 = 0;
        EEPROMWriteInt(478, OS240);
      }
      
      return 0;
    }
    
    else if(Leitura == OS241){

      if(Op == 1) {
        OS241 = 0;
        EEPROMWriteInt(480, OS241);
      }
      
      return 0;
    }
    
    else if(Leitura == OS242){
    
      if(Op == 1) {
        OS242 = 0;
        EEPROMWriteInt(482, OS242);
      }
      
      return 0;
    }
    
    else if(Leitura == OS243){
    
      if(Op == 1) {
        OS243 = 0;
        EEPROMWriteInt(484, OS243);
      }
      
      return 0;
    }
    
    else if(Leitura == OS244){
    
      if(Op == 1) {
        OS244 = 0;
        EEPROMWriteInt(486, OS244);
      }
      
      return 0;
    }

    
    
    else if(Leitura == OS245){
    
      if(Op == 1) {
        OS245 = 0;
        EEPROMWriteInt(488, OS245);
      }
      
      return 0;
    }
    
    else if(Leitura == OS246){
    
      if(Op == 1) {
        OS246 = 0;
        EEPROMWriteInt(490, OS246);
      }
      
      return 0;
    }
    
    else if(Leitura == OS247){
    
      if(Op == 1) {
        OS247 = 0;
        EEPROMWriteInt(492, OS247);
      }
      
      return 0;
    }
    
    else if(Leitura == OS248){

      if(Op == 1) {
        OS248 = 0;
        EEPROMWriteInt(494, OS248);
      }
      
      return 0;
    }
    
    else if(Leitura == OS249){
    
      if(Op == 1) {
        OS249 = 0;
        EEPROMWriteInt(496, OS249);
      }
      
      return 0;
    }
    
    else if(Leitura == OS250){
    
      if(Op == 1) {
        OS250 = 0;
        EEPROMWriteInt(498, OS250);
      }
      
      return 0;
    }
    
    else{

      Serial.println(F("\tOS não encontrada no setor anterior."));
      return 1;
      }
    }

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    
  //Para Escrita:
  else if(Op == 2){

    Serial.println(F("\nEscrita na Pressurização Baixa"));
    
      if(OS201 == 0){

      OS201 = Leitura;
      EEPROMWriteInt(400, OS201);
    
      return 0;
    }
    
    else if(OS202 == 0){
    
      OS202 = Leitura;
      EEPROMWriteInt(402, OS202);
    
      return 0;
    }
    
    else if(OS203 == 0){
    
      OS203 = Leitura;
      EEPROMWriteInt(404, OS203);
    
      return 0;
    }
    
    else if(OS204 == 0){
    
      OS204 = Leitura;
      EEPROMWriteInt(406, OS204);
    
      return 0;
    }
    
    else if(OS205 == 0){
    
      OS205 = Leitura;
      EEPROMWriteInt(408, OS205);
    
      return 0;
    }
    
    else if(OS206 == 0){
    
      OS206 = Leitura;
      EEPROMWriteInt(410, OS206);
    
      return 0;
    }
    
    else if(OS207 == 0){
    
      OS207 = Leitura;
      EEPROMWriteInt(412, OS207);
    
      return 0;
    }
    
    else if(OS208 == 0){
    
      OS208 = Leitura;
      EEPROMWriteInt(414, OS208);
    
      return 0;
    }
    
    else if(OS209 == 0){
    
      OS209 = Leitura;
      EEPROMWriteInt(416, OS209);
    
      return 0;
    }
    
    else if(OS210 == 0){
    
      OS210 = Leitura;
      EEPROMWriteInt(418, OS210);
    
      return 0;
    }
    
    else if(OS211 == 0){
    
      OS211 = Leitura;
      EEPROMWriteInt(420, OS211);
    
      return 0;
    }
    
    else if(OS212 == 0){
    
      OS212 = Leitura;
      EEPROMWriteInt(422, OS212);
    
      return 0;
    }
    
    else if(OS213 == 0){
    
      OS213 = Leitura;
      EEPROMWriteInt(424, OS213);
    
      return 0;
    }
    
    else if(OS214 == 0){
    
      OS214 = Leitura;
      EEPROMWriteInt(426, OS214);
    
      return 0;
    }
    
    else if(OS215 == 0){
    
      OS215 = Leitura;
      EEPROMWriteInt(428, OS215);
    
      return 0;
    }
    
    else if(OS216 == 0){
    
      OS216 = Leitura;
      EEPROMWriteInt(430, OS216);
    
      return 0;
    }
    
    else if(OS217 == 0){
    
      OS217 = Leitura;
      EEPROMWriteInt(432, OS217);
    
      return 0;
    }
    
    else if(OS218 == 0){
    
      OS218 = Leitura;
      EEPROMWriteInt(434, OS218);
    
      return 0;
    }
    
    else if(OS219 == 0){
    
      OS219 = Leitura;
      EEPROMWriteInt(436, OS219);
    
      return 0;
    }
    
    else if(OS220 == 0){
    
      OS220 = Leitura;
      EEPROMWriteInt(438, OS220);
    
      return 0;
    }
    
    else if(OS221 == 0){
    
      OS221 = Leitura;
      EEPROMWriteInt(440, OS221);
    
      return 0;
    }
    
    else if(OS222 == 0){
    
      OS222 = Leitura;
      EEPROMWriteInt(442, OS222);
    
      return 0;
    }
    
    else if(OS223 == 0){
    
      OS223 = Leitura;
      EEPROMWriteInt(444, OS223);
    
      return 0;
    }
    
    else if(OS224 == 0){
    
      OS224 = Leitura;
      EEPROMWriteInt(446, OS224);
    
      return 0;
    }
    
    else if(OS225 == 0){
    
      OS225 = Leitura;
      EEPROMWriteInt(448, OS225);
    
      return 0;
    }
    
    else if(OS226 == 0){
    
      OS226 = Leitura;
      EEPROMWriteInt(450, OS226);
    
      return 0;
    }
    
    else if(OS227 == 0){
    
      OS227 = Leitura;
      EEPROMWriteInt(452, OS227);
    
      return 0;
    }
    
    else if(OS228 == 0){
    
      OS228 = Leitura;
      EEPROMWriteInt(454, OS228);
    
      return 0;
    }
    
    else if(OS229 == 0){
    
      OS229 = Leitura;
      EEPROMWriteInt(456, OS229);
    
      return 0;
    }
    
    else if(OS230 == 0){
    
      OS230 = Leitura;
      EEPROMWriteInt(458, OS230);
    
      return 0;
    }
    
    else if(OS231 == 0){
    
      OS231 = Leitura;
      EEPROMWriteInt(460, OS231);
    
      return 0;
    }
    
    else if(OS232 == 0){
    
      OS232 = Leitura;
      EEPROMWriteInt(462, OS232);
    
      return 0;
    }
    
    else if(OS233 == 0){
    
      OS233 = Leitura;
      EEPROMWriteInt(464, OS233);
    
      return 0;
    }
    
    else if(OS234 == 0){
    
      OS234 = Leitura;
      EEPROMWriteInt(466, OS234);
    
      return 0;
    }
    
    else if(OS235 == 0){
    
      OS235 = Leitura;
      EEPROMWriteInt(468, OS235);
    
      return 0;
    }
    
    else if(OS236 == 0){
    
      OS236 = Leitura;
      EEPROMWriteInt(470, OS236);
    
      return 0;
    }
    
    else if(OS237 == 0){
    
      OS237 = Leitura;
      EEPROMWriteInt(472, OS237);
    
      return 0;
    }
    
    else if(OS238 == 0){
    
      OS238 = Leitura;
      EEPROMWriteInt(474, OS238);
    
      return 0;
    }
    
    else if(OS239 == 0){
    
      OS239 = Leitura;
      EEPROMWriteInt(476, OS239);
    
      return 0;
    }
    
    else if(OS240 == 0){
    
      OS240 = Leitura;
      EEPROMWriteInt(478, OS240);
    
      return 0;
    }
    
    else if(OS241 == 0){
    
      OS241 = Leitura;
      EEPROMWriteInt(480, OS241);
    
      return 0;
    }
    
    else if(OS242 == 0){
    
      OS242 = Leitura;
      EEPROMWriteInt(482, OS242);
    
      return 0;
    }
    
    else if(OS243 == 0){
    
      OS243 = Leitura;
      EEPROMWriteInt(484, OS243);
    
      return 0;
    }
    
    else if(OS244 == 0){
    
      OS244 = Leitura;
      EEPROMWriteInt(486, OS244);
    
      return 0;
    }
    
    else if(OS245 == 0){
    
      OS245 = Leitura;
      EEPROMWriteInt(488, OS245);
    
      return 0;
    }
    
    else if(OS246 == 0){
    
      OS246 = Leitura;
      EEPROMWriteInt(490, OS246);
    
      return 0;
    }
    
    else if(OS247 == 0){
    
      OS247 = Leitura;
      EEPROMWriteInt(492, OS247);
    
      return 0;
    }
    
    else if(OS248 == 0){
    
      OS248 = Leitura;
      EEPROMWriteInt(494, OS248);
    
      return 0;
    }
    
    else if(OS249 == 0){
    
      OS249 = Leitura;
      EEPROMWriteInt(496, OS249);
    
      return 0;
    }
    
    else if(OS250 == 0){
    
      OS250 = Leitura;
      EEPROMWriteInt(498, OS250);
    
      return 0;
    }

    
    else{

      Serial.println(F("\nSem espaço disponível para escrita."));
      
      return 1;
    }
  }
}
