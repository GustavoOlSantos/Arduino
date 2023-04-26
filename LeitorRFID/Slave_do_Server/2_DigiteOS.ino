void EscreveOS(){

  unsigned long MillisAtual;
  setMillis(0);
  
  for(int cont = 0; cont <= 4;){
    MillisAtual = millis();
    
    char Digito;                      // Caracter lido após ser digitado no teclado
    char SenhaDigitada[5];          // Todos os caracteres digitados para serem convertidos em Inteiros 

    //=> Para o Teclado Matricial 3x4
    const byte LINHAS = 4;    // quantidade de linhas do teclado
    const byte COLUNAS = 4;  // quantidade de colunas do teclado
    
    // Matriz para colocar todos os caracteres do teclado:
    char digitos[LINHAS][COLUNAS] = {
    {'1','2','3', 'A'},
    {'4','5','6', 'B'},
    {'7','8','9', 'C'},
    {'*','0','#', 'D'}}; 
    
    //byte pinosLinha[LINHAS] = { 2, 7, 6, 4 }; // pinos de conexão das linhas no arduino 
    //byte pinosColuna[COLUNAS] = { 3, 1, 5}; // pinos de conexão das colunas no arduino  


    byte pinosLinha[LINHAS] = { 4, 5, 6, 7 }; // pinos de conexão das linhas no arduino 
    byte pinosColuna[COLUNAS] = { 0, 1, A4, A3}; // pinos de conexão das colunas no arduino  

      if(MillisAtual > 25000){
  
    Serial.println("Tempo Excedido!!!");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tempo excedido!");
    lcd.setCursor(0,1);
    lcd.print("Tente Novamente");
    return;
    }
    
    // Objeto de leitura das teclas com os parâmetros lidos
    Keypad keypad = Keypad( makeKeymap(digitos), pinosLinha, pinosColuna, LINHAS, COLUNAS );

    Digito = keypad.getKey();      // Armazena a leitura das teclas
    SenhaDigitada[cont] = Digito; // Joga a leitura numa posição da string

    //=> Caso o Dígito seja um Número, escreva na tela
    if(SenhaDigitada[cont] == '1' or SenhaDigitada[cont] == '2' or SenhaDigitada[cont] == '3' or SenhaDigitada[cont] == '4'
    or SenhaDigitada[cont] == '5' or SenhaDigitada[cont] == '6' or SenhaDigitada[cont] == '7' or SenhaDigitada[cont] == '8' or SenhaDigitada[cont] == '9'
    or SenhaDigitada[cont] == '0'){
    
      //=> Imprinme o dígito no LCD
      lcd.setCursor(4 + cont,0);
      
      lcd.print(SenhaDigitada[cont]);

      Serial.print(SenhaDigitada[cont]);
      cont++;

      delay(800);
    }
    
    //=> Caso o Dígito seja um '*' ou um '#', apague o anterior
    else if(SenhaDigitada[cont] == '*' or SenhaDigitada[cont] == '#'){

      cont--;
             
      lcd.setCursor(4 + cont,0);
      lcd.print(" ");

      Serial.print("\b");

      delay(800);
    }

    else{}

      if(cont == 4){

        SenhaDigitada[4] = '*';
        SenhaDigitada[5] = '\0';
        cont = 5;
        MillisAtual = 30000;

        //int OS = atoi(SenhaDigitada);

        Serial.print("\n\nOS DIGITADA: ");
        //Serial.println(OS);
    
        Serial.println(SenhaDigitada);
    
        //return OS;
        EnviaOS(SenhaDigitada);
        return;
      } 
  }
}
