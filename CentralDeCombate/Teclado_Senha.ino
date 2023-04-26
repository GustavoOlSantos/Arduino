//------------ FUNÇAO PARA LER REGISTRAR E COMPARAR AS SENHAS E INFORMAÇÕES DO TECLADO ------------//

int Teclado(){

  int Resultado = 0;

  do{
    
  const char SenhaAdm[30] = "123";   // DEFINA A SENHHA MASTER PARA RESETAR
  char Digito;                      // Caracter lido após ser digitado no teclado
  char SenhaDigitada[30];          // Todos os caracteres digitados para comparar com a SenhaAdm 
  
  DefTecladoMatriz(); // DEFINIÇÕES PARA O TECLADO  MATRICIAL
    
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("--RESET DA CENTRAL--");
    delay(2500);
    
    lcd.setCursor(0,1);
    lcd.print("SenhaAdm: ");
    
    for(int cont = 0; cont != 30;){

      lcd.setCursor((10 + cont),1);
      lcd.print("_");
      
      Digito = keypad.getKey(); // Armazena a leitura das teclas
      SenhaDigitada[cont] = Digito; // Joga a leitura numa posição da string

      if (SenhaDigitada[cont] != '*' and SenhaDigitada[cont] != '#' and SenhaDigitada[cont] == '1' or SenhaDigitada[cont] == '2' or SenhaDigitada[cont] == '3' or SenhaDigitada[cont] == '4' or SenhaDigitada[cont] == '5' or SenhaDigitada[cont] == '6' or SenhaDigitada[cont] == '7' or SenhaDigitada[cont] == '8' or SenhaDigitada[cont] == '9' or SenhaDigitada[cont] == '0'){
        

        // Imprime o dígito no LCD
        lcd.setCursor((10 + cont),1);
        //lcd.print(SenhaDigitada[cont]);
        lcd.print('*');

        /*if(cont > 0){

          lcd.setCursor((10 + cont - 1),1);
          lcd.print('*');
          
          }*/
      
        cont++;
      
      }
      

      // Permite o usuário apagar o que digitou anteriormente, ao escrever "*"
      else if(SenhaDigitada[cont] == '*' and cont > 0){

        // Acionamento do buzzer ao apertar qualquer 
        //digitalWrite(A0, HIGH);
        //delay(tempoBuzz);
        //digitalWrite(A0, LOW); 
      
        lcd.setCursor(10 + cont - 1,1);
        lcd.print(" ");
        lcd.setCursor(10+cont,1);
        lcd.print(" ");
        cont--;
      
      }

      // Encerra a contagem e substitui o digito "#" por "\0" (fim da string)
      else if(SenhaDigitada[cont] == '#'){ 
        
        SenhaDigitada[cont] = '\0';
        cont = 30;    
      }

      // Encerra a string defininido o caracter 30 como fim da string
      else if(cont == 29){

        cont = 30;
        SenhaDigitada[cont] = '\0';
      }

        
        
    }

  
    // Verifica se a String Digitada e a Senha definida estão corretas
    if(strcmp(SenhaDigitada,SenhaAdm)==0){
    
      FuncMasterReset();
      return 1;
    } 

    else{
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SENHA INCORRETA! ");
      delay(1500);
      lcd.clear();
      
      SenhaDigitada[0] = '\0';
      
      }
    } while(Resultado != 1);   
 }
