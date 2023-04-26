void Preparativos(){

  int i = 0;
  
  while(Wire.available()){
    
    MensagemAtual[i] = Wire.read();
    i++;
  }

  Verificado = 1;
  
}
