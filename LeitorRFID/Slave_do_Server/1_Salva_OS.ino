int LeituraDeOS(byte buffer1[5]){
  
  uint8_t i = 0;
           
  do{
    char Leitura[10];          
 
    if(buffer1[i] != 0 and buffer1[i] != 1 and buffer1[i] != 2 and buffer1[i] != 3 and buffer1[i] != 4 and buffer1[i] != 5 and buffer1[i] != 6
    and buffer1[i] != 7 and buffer1[i] != 8 and buffer1[i] != 9 and buffer1[i] != '*'){
            
      Leitura[i] = buffer1[i];
          
      i++;
            
      if(buffer1[i] == '*'){
            
        Leitura[i] = '\0';
        Serial.print(Leitura);

        // "atoi" é um comando da "Stdlib.h" para converter variáveis char[*](cadeia de caracteres) em variáveis int(números inteiros)
        int OS = atoi(Leitura);
              
        return OS;
        }
      }
      
      else{
        return 0;
      }
  }
  while(buffer1[i] != '*' and buffer1[i] != '#');
}
