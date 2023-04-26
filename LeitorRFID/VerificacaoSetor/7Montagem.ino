int OsMontagem(int Leitura, int Op){
  // Leitura é a OS Lida no cartão
  // Op é a operação a ser feita, Leitura+Limpeza(1), Escrita(2) ou Apenas Leitura(3)
  
  //Variáveis Auxiliares
  int OS251 = EEPROMReadInt(500);     int OS252 = EEPROMReadInt(502);
  int OS253 = EEPROMReadInt(504);     int OS254 = EEPROMReadInt(506);
  int OS255 = EEPROMReadInt(508);     int OS256 = EEPROMReadInt(510);
  int OS257 = EEPROMReadInt(512);     int OS258 = EEPROMReadInt(514);
  int OS259 = EEPROMReadInt(516);     int OS260 = EEPROMReadInt(518);
  int OS261 = EEPROMReadInt(520);     int OS262 = EEPROMReadInt(522);
  int OS263 = EEPROMReadInt(524);     int OS264 = EEPROMReadInt(526);
  int OS265 = EEPROMReadInt(528);     int OS266 = EEPROMReadInt(530);
  int OS267 = EEPROMReadInt(532);     int OS268 = EEPROMReadInt(534);
  int OS269 = EEPROMReadInt(536);     int OS270 = EEPROMReadInt(538);
  int OS271 = EEPROMReadInt(540);     int OS272 = EEPROMReadInt(542);
  int OS273 = EEPROMReadInt(544);     int OS274 = EEPROMReadInt(546);
  int OS275 = EEPROMReadInt(548);     int OS276 = EEPROMReadInt(550);
  int OS277 = EEPROMReadInt(552);     int OS278 = EEPROMReadInt(554);
  int OS279 = EEPROMReadInt(556);     int OS280 = EEPROMReadInt(558);
  int OS281 = EEPROMReadInt(560);     int OS282 = EEPROMReadInt(562);
  int OS283 = EEPROMReadInt(564);     int OS284 = EEPROMReadInt(566);
  int OS285 = EEPROMReadInt(568);     int OS286 = EEPROMReadInt(570);
  int OS287 = EEPROMReadInt(572);     int OS288 = EEPROMReadInt(574);
  int OS289 = EEPROMReadInt(576);     int OS290 = EEPROMReadInt(578);
  int OS291 = EEPROMReadInt(580);     int OS292 = EEPROMReadInt(582);
  int OS293 = EEPROMReadInt(584);     int OS294 = EEPROMReadInt(586);
  int OS295 = EEPROMReadInt(588);     int OS296 = EEPROMReadInt(590);
  int OS297 = EEPROMReadInt(592);     int OS298 = EEPROMReadInt(594);
  int OS299 = EEPROMReadInt(596);     int OS300 = EEPROMReadInt(598);
  
     
  //Para Leitura
  if (Op == 1 or Op == 3){
    Serial.print(F("\nLeitura na Montagem"));
    
    if(Leitura == OS251){

      if(Op == 1) {
        OS251 = 0;
        EEPROMWriteInt(500, OS251);
      }
      
      return 0;
    }
    
    else if(Leitura == OS252){
    
      if(Op == 1) {
        OS252 = 0;
        EEPROMWriteInt(502, OS252);
      }
      return 0;
    }
    
    else if(Leitura == OS253){
    
      if(Op == 1) {
        OS253 = 0;
        EEPROMWriteInt(504, OS253);
      }
      return 0;
    }
    
    else if(Leitura == OS254){
    
      if(Op == 1) {
        OS254 = 0;
        EEPROMWriteInt(506, OS254);
      }
      
      return 0;
    }
    
    else if(Leitura == OS255){
    
      if(Op == 1) {
        OS255 = 0;
        EEPROMWriteInt(508, OS255);      
      }
      return 0;
    }
    
    else if(Leitura == OS256){
    
      if(Op == 1) {
        OS256 = 0;
        EEPROMWriteInt(510, OS256);
      }
      return 0;
    }
    
    else if(Leitura == OS257){
    
      if(Op == 1) {
        OS257 = 0;
        EEPROMWriteInt(512, OS257);
      }
      
      return 0;
    }
    
    else if(Leitura == OS258){
    
      if(Op == 1) {
        OS258 = 0;
        EEPROMWriteInt(514, OS258);
      }
      
      return 0;
    }
    
    else if(Leitura == OS259){
    
      if(Op == 1) {
        OS259 = 0;
        EEPROMWriteInt(516, OS259);
      }    
      return 0;
    }
    
    else if(Leitura == OS260){
    
      if(Op == 1) {
        OS260 = 0;
        EEPROMWriteInt(518, OS260);
      }
      
      return 0;
    }
    
    else if(Leitura == OS261){
    
      if(Op == 1) {
        OS261 = 0;
        EEPROMWriteInt(520, OS261);
      }
      
      return 0;
    }
    
    else if(Leitura == OS262){
    
      if(Op == 1) {
        OS262 = 0;
        EEPROMWriteInt(522, OS262);
      }
      
      return 0;
    }
    
    else if(Leitura == OS263){
    
      if(Op == 1) {
        OS263 = 0;
        EEPROMWriteInt(524, OS263);
      }
      
      return 0;
    }
    
    else if(Leitura == OS264){
    
      if(Op == 1) {
        OS264 = 0;
        EEPROMWriteInt(526, OS264);
      }
      
      return 0;
    }
    
    else if(Leitura == OS265){

      if(Op == 1) {
        OS265 = 0;
        EEPROMWriteInt(528, OS265);
      }
      
      return 0;
    }
    
    else if(Leitura == OS266){
      
      if(Op == 1) {
        OS266 = 0;
        EEPROMWriteInt(530, OS266);
      }
      return 0;
    }
    
    else if(Leitura == OS267){

      if(Op == 1) {
        OS267 = 0;
        EEPROMWriteInt(532, OS267);
      }
      return 0;
    }
    
    else if(Leitura == OS268){
    
      if(Op == 1) {
        OS268 = 0;
        EEPROMWriteInt(534, OS268);
      }
      return 0;
    }
    
    else if(Leitura == OS269){
    
      if(Op == 1) {
        OS269 = 0;
        EEPROMWriteInt(536, OS269);
      }
      return 0;
    }
    
    else if(Leitura == OS270){
    
      if(Op == 1) {
        OS270 = 0;
        EEPROMWriteInt(538, OS270);
      }
      return 0;
    }
    
    else if(Leitura == OS271){
    
      if(Op == 1) {
        OS271 = 0;
        EEPROMWriteInt(540, OS271);
      }
      return 0;
    }
    
    else if(Leitura == OS272){
    
      if(Op == 1) {
        OS272 = 0;
        EEPROMWriteInt(542, OS272);
      }
      return 0;
    }
    
    else if(Leitura == OS273){
    
      if(Op == 1) {
        OS273 = 0;
        EEPROMWriteInt(544, OS273);
      }
      return 0;
    }
    
    else if(Leitura == OS274){
    
      if(Op == 1) {
        OS274 = 0;
        EEPROMWriteInt(546, OS274);
      }
      return 0;
    }
    
    else if(Leitura == OS275){
    
      if(Op == 1) {
        OS275 = 0;
        EEPROMWriteInt(548, OS275);
      }
      return 0;
    }
    
    else if(Leitura == OS276){
    
      if(Op == 1) {
        OS276 = 0;
        EEPROMWriteInt(550, OS276);
      }
      return 0;
    }
    
    else if(Leitura == OS277){
    
      if(Op == 1) {
        OS277 = 0;
        EEPROMWriteInt(552, OS277);
      }
      return 0;
    }
    
    else if(Leitura == OS278){
    
      if(Op == 1) {
        OS278 = 0;
        EEPROMWriteInt(554, OS278);
      }
      return 0;
    }
    
    else if(Leitura == OS279){
    
      if(Op == 1) {
        OS279 = 0;
        EEPROMWriteInt(556, OS279);
      }
      return 0;
    }
    
    else if(Leitura == OS280){
    
      if(Op == 1) {
        OS280 = 0;
        EEPROMWriteInt(558, OS280);
      }
      return 0;
    }
    
    else if(Leitura == OS281){
    
      if(Op == 1) {
        OS281 = 0;
        EEPROMWriteInt(560, OS281);
      }
      return 0;
    }
    
    else if(Leitura == OS282){
    
      if(Op == 1) {
        OS282 = 0;
        EEPROMWriteInt(562, OS282);
      }
      return 0;
    }
    
    else if(Leitura == OS283){
    
      if(Op == 1) {
        OS283 = 0;
        EEPROMWriteInt(564, OS283);
      }
      return 0;
    }
    
    else if(Leitura == OS284){
    
      if(Op == 1) {
        OS284 = 0;
        EEPROMWriteInt(566, OS284);
      }
      return 0;
    }
    
    else if(Leitura == OS285){
    
      if(Op == 1) {
        OS285 = 0;
        EEPROMWriteInt(568, OS285);
      }
      return 0;
    }
    
    else if(Leitura == OS286){
    
      if(Op == 1) {
        OS286 = 0;
        EEPROMWriteInt(570, OS286);
      }
      return 0;
    }
    
    else if(Leitura == OS287){
    
      if(Op == 1) {
        OS287 = 0;
        EEPROMWriteInt(572, OS287);
      }
      return 0;
    }
    
    else if(Leitura == OS288){
    
      if(Op == 1) {
        OS288 = 0;
        EEPROMWriteInt(574, OS288);
      }
      return 0;
    }
    
    else if(Leitura == OS289){

    if(Op == 1) {
        OS289 = 0;
        EEPROMWriteInt(576, OS289);
    }
      return 0;
    }
    
    else if(Leitura == OS290){
    
      if(Op == 1) {
        OS290 = 0;
        EEPROMWriteInt(578, OS290);
      }
      return 0;
    }
    
    else if(Leitura == OS291){

      if(Op == 1) {
        OS291 = 0;
        EEPROMWriteInt(580, OS291);
      }
      return 0;
    }
    
    else if(Leitura == OS292){

      if(Op == 1) {
        OS292 = 0;
        EEPROMWriteInt(582, OS292);
      }
      
      return 0;
    }
    
    else if(Leitura == OS293){
    
      if(Op == 1) {
        OS293 = 0;
        EEPROMWriteInt(584, OS293);
      }
      
      return 0;
    }
    
    else if(Leitura == OS294){
    
      if(Op == 1) {
        OS294 = 0;
        EEPROMWriteInt(586, OS294);
      }
      
      return 0;
    }
    
    else if(Leitura == OS295){
    
      if(Op == 1) {
        OS295 = 0;
        EEPROMWriteInt(588, OS295);
      }
      
      return 0;
    }
    
    else if(Leitura == OS296){
    
      if(Op == 1) {
        OS296 = 0;
        EEPROMWriteInt(590, OS296);
      }
      
      return 0;
    }
    
    else if(Leitura == OS297){
    
      OS297 = 0;
      EEPROMWriteInt(592, OS297);
    
      return 0;
    }
    
    else if(Leitura == OS298){
    
      if(Op == 1) {
        OS298 = 0;
        EEPROMWriteInt(594, OS298);
      }
      
      return 0;
    }
    
    else if(Leitura == OS299){
    
      if(Op == 1) {
        OS299 = 0;
        EEPROMWriteInt(596, OS299);
      }
      
      return 0;
    }
    
    else if(Leitura == OS300){
    
      if(Op == 1) {
        OS300 = 0;
        EEPROMWriteInt(598, OS300);
      }
      
      return 0;
    }
    
    else{

      Serial.println(F("\tOS não encontrada no setor anterior."));
      return 1;
      }
    }

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- //
    
  //Para Escrita:
  else if(Op == 2){

    Serial.println(F("\nEscrita na Montagem"));
    
    if(OS251 == 0){

      OS251 = Leitura;
      EEPROMWriteInt(500, OS251);
    
      return 0;
    }
    
    else if(OS252 == 0){
    
      OS252 = Leitura;
      EEPROMWriteInt(502, OS252);
    
      return 0;
    }
    
    else if(OS253 == 0){
    
      OS253 = Leitura;
      EEPROMWriteInt(504, OS253);
    
      return 0;
    }
    
    else if(OS254 == 0){
    
      OS254 = Leitura;
      EEPROMWriteInt(506, OS254);
    
      return 0;
    }
    
    else if(OS255 == 0){
    
      OS255 = Leitura;
      EEPROMWriteInt(508, OS255);
    
      return 0;
    }
    
    else if(OS256 == 0){
    
      OS256 = Leitura;
      EEPROMWriteInt(510, OS256);
    
      return 0;
    }
    
    else if(OS257 == 0){
    
      OS257 = Leitura;
      EEPROMWriteInt(512, OS257);
    
      return 0;
    }
    
    else if(OS258 == 0){
    
      OS258 = Leitura;
      EEPROMWriteInt(514, OS258);
    
      return 0;
    }
    
    else if(OS259 == 0){
    
      OS259 = Leitura;
      EEPROMWriteInt(516, OS259);
    
      return 0;
    }
    
    else if(OS260 == 0){
    
      OS260 = Leitura;
      EEPROMWriteInt(518, OS260);
    
      return 0;
    }
    
    else if(OS261 == 0){
    
      OS261 = Leitura;
      EEPROMWriteInt(520, OS261);
    
      return 0;
    }
    
    else if(OS262 == 0){
    
      OS262 = Leitura;
      EEPROMWriteInt(522, OS262);
    
      return 0;
    }
    
    else if(OS263 == 0){
    
      OS263 = Leitura;
      EEPROMWriteInt(524, OS263);
    
      return 0;
    }
    
    else if(OS264 == 0){
    
      OS264 = Leitura;
      EEPROMWriteInt(526, OS264);
    
      return 0;
    }
    
    else if(OS265 == 0){
    
      OS265 = Leitura;
      EEPROMWriteInt(528, OS265);
    
      return 0;
    }
    
    else if(OS266 == 0){
    
      OS266 = Leitura;
      EEPROMWriteInt(530, OS266);
    
      return 0;
    }
    
    else if(OS267 == 0){
    
      OS267 = Leitura;
      EEPROMWriteInt(532, OS267);
    
      return 0;
    }
    
    else if(OS268 == 0){
    
      OS268 = Leitura;
      EEPROMWriteInt(534, OS268);
    
      return 0;
    }
    
    else if(OS269 == 0){
    
      OS269 = Leitura;
      EEPROMWriteInt(536, OS269);
    
      return 0;
    }
    
    else if(OS270 == 0){
    
      OS270 = Leitura;
      EEPROMWriteInt(538, OS270);
    
      return 0;
    }
    
    else if(OS271 == 0){
    
      OS271 = Leitura;
      EEPROMWriteInt(540, OS271);
    
      return 0;
    }
    
    else if(OS272 == 0){
    
      OS272 = Leitura;
      EEPROMWriteInt(542, OS272);
    
      return 0;
    }
    
    else if(OS273 == 0){
    
      OS273 = Leitura;
      EEPROMWriteInt(544, OS273);
    
      return 0;
    }
    
    else if(OS274 == 0){
    
      OS274 = Leitura;
      EEPROMWriteInt(546, OS274);
    
      return 0;
    }
    
    else if(OS275 == 0){
    
      OS275 = Leitura;
      EEPROMWriteInt(548, OS275);
    
      return 0;
    }
    
    else if(OS276 == 0){
    
      OS276 = Leitura;
      EEPROMWriteInt(550, OS276);
    
      return 0;
    }
    
    else if(OS277 == 0){
    
      OS277 = Leitura;
      EEPROMWriteInt(552, OS277);
    
      return 0;
    }
    
    else if(OS278 == 0){
    
      OS278 = Leitura;
      EEPROMWriteInt(554, OS278);
    
      return 0;
    }
    
    else if(OS279 == 0){
    
      OS279 = Leitura;
      EEPROMWriteInt(556, OS279);
    
      return 0;
    }
    
    else if(OS280 == 0){
    
      OS280 = Leitura;
      EEPROMWriteInt(558, OS280);
    
      return 0;
    }
    
    else if(OS281 == 0){
    
      OS281 = Leitura;
      EEPROMWriteInt(560, OS281);
    
      return 0;
    }
    
    else if(OS282 == 0){
    
      OS282 = Leitura;
      EEPROMWriteInt(562, OS282);
    
      return 0;
    }
    
    else if(OS283 == 0){
    
      OS283 = Leitura;
      EEPROMWriteInt(564, OS283);
    
      return 0;
    }
    
    else if(OS284 == 0){
    
      OS284 = Leitura;
      EEPROMWriteInt(566, OS284);
    
      return 0;
    }
    
    else if(OS285 == 0){
    
      OS285 = Leitura;
      EEPROMWriteInt(568, OS285);
    
      return 0;
    }
    
    else if(OS286 == 0){
    
      OS286 = Leitura;
      EEPROMWriteInt(570, OS286);
    
      return 0;
    }
    
    else if(OS287 == 0){
    
      OS287 = Leitura;
      EEPROMWriteInt(572, OS287);
    
      return 0;
    }
    
    else if(OS288 == 0){
    
      OS288 = Leitura;
      EEPROMWriteInt(574, OS288);
    
      return 0;
    }
    
    else if(OS289 == 0){
    
      OS289 = Leitura;
      EEPROMWriteInt(576, OS289);
    
      return 0;
    }
    
    else if(OS290 == 0){
    
      OS290 = Leitura;
      EEPROMWriteInt(578, OS290);
    
      return 0;
    }
    
    else if(OS291 == 0){
    
      OS291 = Leitura;
      EEPROMWriteInt(580, OS291);
    
      return 0;
    }
    
    else if(OS292 == 0){
    
      OS292 = Leitura;
      EEPROMWriteInt(582, OS292);
    
      return 0;
    }
    
    else if(OS293 == 0){
    
      OS293 = Leitura;
      EEPROMWriteInt(584, OS293);
    
      return 0;
    }
    
    else if(OS294 == 0){
    
      OS294 = Leitura;
      EEPROMWriteInt(586, OS294);
    
      return 0;
    }
    
    else if(OS295 == 0){
    
      OS295 = Leitura;
      EEPROMWriteInt(588, OS295);
    
      return 0;
    }
    
    else if(OS296 == 0){
    
      OS296 = Leitura;
      EEPROMWriteInt(590, OS296);
    
      return 0;
    }
    
    else if(OS297 == 0){
    
      OS297 = Leitura;
      EEPROMWriteInt(592, OS297);
    
      return 0;
    }
    
    else if(OS298 == 0){
    
      OS298 = Leitura;
      EEPROMWriteInt(594, OS298);
    
      return 0;
    }
    
    else if(OS299 == 0){
    
      OS299 = Leitura;
      EEPROMWriteInt(596, OS299);
    
      return 0;
    }
    
    else if(OS300 == 0){
    
      OS300 = Leitura;
      EEPROMWriteInt(598, OS300);
    
      return 0;
    }

    
    else{

      Serial.println(F("\nSem espaço disponível para escrita."));
      
      return 1;
    }
  }
}
