//------------ FUNÇÃO RESPONSÁVEL POR REALIZAR OU NÃO O BLOQUEIO DO Co2  ------------//

int Bloqueio() {

  unsigned long Timer = 0;
  unsigned long Stamp = 1000;
  int Segundos = 30;

  pinMode(39, INPUT_PULLUP); // Acionamento bloqueio
  

  MillisInicial = millis();
  
  setMillis(0);
  
  do {

    MillisAtual = millis();
    int AcBloqueio = ! digitalRead(39);

    Timer = MillisAtual;
      if(Timer >= Stamp and Timer < Stamp + 1000 and Segundos >= 10){
        
      lcd.setCursor(12, 3);
      lcd.print(Segundos);
      lcd.setCursor(14, 3);
      lcd.print("s");
      Segundos = Segundos - 1;
      Stamp = Stamp + 1000;

      }

      else if(Segundos < 10 and Timer >= Stamp and Timer < Stamp + 1000){

        lcd.setCursor(12, 3);
        
        lcd.print("0");
        lcd.setCursor(13, 3);
        lcd.print(Segundos);
        lcd.setCursor(14, 3);
        lcd.print("s");
        Segundos = Segundos - 1;
        Stamp = Stamp + 1000;
        
        }

    if(AcBloqueio == 1){
      
      //Serial.print("\n\nBloqueio Ativo! \n\n ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("********FOGO********");
        lcd.setCursor(3, 1);
        lcd.print("EVACUAR O LOCAL");
        lcd.setCursor(0, 3);
        lcd.print("BLOQUEIO ATIVO");
        
        return 0;
      }


      if (MillisAtual > Intervalo){
        
        //Serial.print("\n\nTempo de espera excedido: ");
        //Serial.print(MillisAtual);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("********FOGO********");
        lcd.setCursor(3, 1);
        lcd.print("EVACUAR O LOCAL");
        lcd.setCursor(0, 3);
        lcd.print("DISPARADO");
        
        return 1;
 
        }  
        
  } while ( MillisAtual <= Intervalo);
}

//------------ FUNÇAO PARA SETAR O TEMPORIZADOR MILLIS() ------------//

void setMillis(unsigned long ms)
{
    extern unsigned long timer0_millis;
    ATOMIC_BLOCK (ATOMIC_RESTORESTATE) {
        timer0_millis = ms;
    }
}
