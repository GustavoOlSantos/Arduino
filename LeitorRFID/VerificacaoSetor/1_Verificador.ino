void Verificador(){

  Serial.println(F("\n\nInício da Verificação da Ordem de Serviço!"));
  Serial.print(F("Mensagem contendo a OS a ser verificada: "));
  Serial.println(MensagemAtual);

  //=> Variáveis para as operações de verificação de setor  
  int Op;
  int ResultRasp    = 0;
  int ResultDesm    = 0;
  int ResultPint    = 0;
  int ResultPressA  = 0;
  int ResultPressB  = 0;
  int ResultMont    = 0;

// ====================================================================================================================  

  // CASO SEJA O SETOR DA RASPAGEM (ENDEREÇO 2)
  if(MensagemAtual[6] == '2'){

    char Receptor[4];
    Receptor[0] = MensagemAtual[1];
    Receptor[1] = MensagemAtual[2]; 
    Receptor[2] = MensagemAtual[3];
    Receptor[3] = MensagemAtual[4];
    Receptor[4] = '\0'; 

    int OS = atoi(Receptor);
    Serial.print  (F("OS Recebida: "));
    Serial.println(OS);

    //=> Verifica se a OS já foi cadastrada
    Op = 3;
    ResultRasp   = OsRaspagem(OS, Op);
    ResultDesm   = OsDesmontagem(OS, Op);
    ResultPint   = OsPintura(OS, Op);
    ResultPressA = OsPressurizacaoA(OS, Op);
    ResultPressB = OsPressurizacaoB(OS, Op);
    ResultMont   = OsMontagem(OS, Op);
    
    if(ResultRasp == 1 and ResultDesm == 1 and ResultPint == 1 and ResultPressA == 1 and ResultPressB == 1 and ResultMont == 1){

      //=> Escreve na aba de RASPAGEM
      Op = 2;
      ResultRasp = OsRaspagem(OS, Op);

      // Contagem de Caracteres da formatação Recebida
      // < 2 0 1 7 - 2 >
      // 0 1 2 3 4 5 6 7 

      //=> Formata a mensagem de retorno
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '0';
      MensagemAtual[9] = '>';

      //=> Formatação a ser enviada ao Arduino Leonardo
      // < 2 0 1 7 - 2 - 0 >
      // 0 1 2 3 4 5 6 7 8 9
      
      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();

      char Resultado = '0';
      Serial.println("Número a ser enviado: " +  String(Resultado));

      
      return;
    
    }

    // Caso a OS lida Agora não se encontre no setor anterior...
    else{

      Serial.println(F("OS já cadastrada!"));
      
      char Resultado = '1';
      
      //=> Formata a mensagem de MensagemAtual
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '1';
      MensagemAtual[9] = '>';       

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();
      
      Serial.println("Número a ser enviado: " +  String(Resultado));
    }
  }

// ====================================================================================================================

  // CASO SEJA O SETOR DA DESMONTAGEM (ENDEREÇO 3)
  else if(MensagemAtual[6] == '3'){

    char Receptor[4];
    Receptor[0] = MensagemAtual[1];
    Receptor[1] = MensagemAtual[2];
    Receptor[2] = MensagemAtual[3];
    Receptor[3] = MensagemAtual[4];
    Receptor[4] = '\0'; 

    int OS = atoi(Receptor);
    Serial.print  (F("OS Recebida: "));
    Serial.println(OS);

    //=> Verifica se a OS passou pela Raspagem
    Op = 1;
    ResultRasp = OsRaspagem(OS, Op);    
      
    if(ResultRasp == 0){          
      
      //=> Escreve na aba da Desmontagem
      Op = 2;
      ResultDesm = OsDesmontagem(OS, Op); 

      char Resultado = '0';
      
      //=> Formata a mensagem de retorno
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '0';
      MensagemAtual[9] = '>';

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();

      Serial.println("Número a ser enviado: " +  String(Resultado));
      
      return;
    
    }

    // Caso a OS lida Agora não se encontre no setor anterior...
    else{
      
      //=> Formata a mensagem de MensagemAtual
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '1';
      MensagemAtual[9] = '>';       

      char Resultado = '1';

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();
      
      Serial.println("Número a ser enviado: " +  String(Resultado));
    }
  }

// ====================================================================================================================  

  // CASO SEJA O SETOR DA PINTURA (ENDEREÇO 4)
  else if(MensagemAtual[6] == '4'){

    char Receptor[4];
    Receptor[0] = MensagemAtual[1];
    Receptor[1] = MensagemAtual[2];
    Receptor[2] = MensagemAtual[3];
    Receptor[3] = MensagemAtual[4];
    Receptor[4] = '\0'; 

    int OS = atoi(Receptor);
    Serial.print  (F("OS Recebida: "));
    Serial.println(OS);

    //=> Verifica se a OS Passou pela Desmontagem antes
    Op = 1;
    ResultDesm = OsDesmontagem(OS, Op);
          
    if(ResultDesm == 0){
    
      //=> Escreve na aba da pintura
      Op = 2;
      ResultPint = OsPintura(OS, Op);

      //=> Formata a mensagem de retorno
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '0';
      MensagemAtual[9] = '>';

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();

      char Resultado = '0';
      Serial.println("Número a ser enviado: " +  String(Resultado));
      
      return;
    
    }

    // Caso a OS lida Agora não se encontre no setor anterior...
    else{

      
      //=> Formata a mensagem de MensagemAtual
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '1';
      MensagemAtual[9] = '>';       

      char Resultado = '1';

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();
      
      Serial.println("Número a ser enviado: " +  String(Resultado));
    }
  }

// ====================================================================================================================
  
  // CASO SEJA O SETOR DA PRESSURIZAÇÃO ALTA (ENDEREÇO 5)
  else if(MensagemAtual[6] == '5'){

    char Receptor[4];
    Receptor[0] = MensagemAtual[1];
    Receptor[1] = MensagemAtual[2];
    Receptor[2] = MensagemAtual[3];
    Receptor[3] = MensagemAtual[4];
    Receptor[4] = '\0'; 

    int OS = atoi(Receptor);
    //Serial.print  ("OS Recebida: ");
    //Serial.println(OS);

    //=> Verifica se a OS Passou pela Pintura antes
    Op = 1;
    ResultPint = OsPintura(OS, Op);

    if(ResultPint == 0){

      //=> Escreve na Aba de Pressurização Alta
      Op = 2;
      ResultPressA = OsPressurizacaoA(OS, Op);

      //=> Formata a mensagem de retorno
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '0';
      MensagemAtual[9] = '>';

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();

      char Resultado = '0';
      Serial.println("Número a ser enviado: " +  String(Resultado));
      
      return;
    
    }

    // Caso a OS lida Agora não se encontre no setor anterior...
    else{
      
      //=> Formata a mensagem de MensagemAtual
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '1';
      MensagemAtual[9] = '>';       

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();

      char Resultado = '1';
      Serial.println("Número a ser enviado: " +  String(Resultado));
    }
  }

// ====================================================================================================================  

  // CASO SEJA O SETOR DA PRESSURIZAÇÃO BAIXA (ENDEREÇO 6)
  else if(MensagemAtual[6] == '6'){

    char Receptor[4];
    Receptor[0] = MensagemAtual[1];
    Receptor[1] = MensagemAtual[2];
    Receptor[2] = MensagemAtual[3];
    Receptor[3] = MensagemAtual[4];
    Receptor[4] = '\0'; 

    int OS = atoi(Receptor);
    Serial.print  (F("OS Recebida: "));
    Serial.println(OS);

    //=> Verifica se a OS Passou pela Pintura antes
    Op = 1;
    ResultPint = OsPintura(OS, Op);
       
    //=> Ou pela Pressurização Alta
    ResultPressA = OsPressurizacaoA(OS, Op);

    if(ResultPint == 0 or ResultPressA == 0){

      //=> Escreve na Aba de Pressurização Baixa
      Op = 2;
      ResultPressB = OsPressurizacaoB(OS, Op);

      //=> Formata a mensagem de retorno
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '0';
      MensagemAtual[9] = '>';

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();

      char Resultado = '0';
      Serial.println("Número a ser enviado: " +  String(Resultado));
      
      return;
    
    }

    // Caso a OS lida Agora não se encontre no setor anterior...
    else{
      
      //=> Formata a mensagem de MensagemAtual
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '1';
      MensagemAtual[9] = '>';       

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();

      char Resultado = '1';
      Serial.println("Número a ser enviado: " +  String(Resultado));
    }
  }

// ====================================================================================================================

  // CASO SEJA O SETOR DA MONTAGEM (ENDEREÇO 7)
  else if(MensagemAtual[6] == '7'){

    char Receptor[4];
    Receptor[0] = MensagemAtual[1];
    Receptor[1] = MensagemAtual[2];
    Receptor[2] = MensagemAtual[3];
    Receptor[3] = MensagemAtual[4];
    Receptor[4] = '\0'; 

    int OS = atoi(Receptor);
    Serial.print  (F("OS Recebida: "));
    Serial.println(OS);

    //=> Verifica se a OS Passou por alguma das pressurizações
    Op = 1;
    ResultPressA = OsPressurizacaoA(OS, Op);
    ResultPressB = OsPressurizacaoB(OS,Op);
      
    if(ResultPressA == 0 or ResultPressB == 0){
  
      //=> Escreve a OS na aba de Montagem
      Op = 2;
      ResultMont = OsMontagem(OS, Op);

      //=> Formata a mensagem de retorno
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '0';
      MensagemAtual[9] = '>';

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();

      char Resultado = '0';
      Serial.println("Número a ser enviado: " +  String(Resultado));
      
      return;
    
    }

    // Caso a OS lida Agora não se encontre no setor anterior...
    else{
      
      //=> Formata a mensagem de MensagemAtual
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '1';
      MensagemAtual[9] = '>';       

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();

      char Resultado = '1';
      Serial.println("Número a ser enviado: " +  String(Resultado));
    }
  }

// ====================================================================================================================  

  // CASO SEJA O SETOR DA LAUDO (ENDEREÇO 8)
  else if(MensagemAtual[6] == '8'){

    char Receptor[4];
    Receptor[0] = MensagemAtual[1];
    Receptor[1] = MensagemAtual[2];
    Receptor[2] = MensagemAtual[3];
    Receptor[3] = MensagemAtual[4];
    Receptor[4] = '\0'; 

    int OS = atoi(Receptor);
    Serial.print  (F("OS Recebida: "));
    Serial.println(OS);

    //=> Verifica se a OS Passou pelo setor de Montagem
    Op = 1;
    ResultMont = OsMontagem(OS, Op);

    if(OsMontagem == 0){

      //=> Formata a mensagem de retorno
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '0';
      MensagemAtual[9] = '>';

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();

      char Resultado = '0';
      Serial.println("Número a ser enviado: " +  String(Resultado));
      
      return;
    
    }

    // Caso a OS lida Agora não se encontre no setor anterior...
    else{
      
      //=> Formata a mensagem de MensagemAtual
      MensagemAtual[7] = '-';
      MensagemAtual[8] = '1';
      MensagemAtual[9] = '>';       

      //=> Envia a Mensagem para o Arduino Leonardo
      Wire.beginTransmission(1);
      Wire.write(MensagemAtual); 
      Wire.endTransmission();

      char Resultado = '1';
      Serial.println("Número a ser enviado: " + String(Resultado));
    }
  }
}
