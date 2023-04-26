void WifiDadosParaExcel()
{

  String Data;
  char Dados[24];
  int i = 0;

  while (Wire.available())
  {

    Dados[i] = Wire.read();
    i++;
  }

  //==============================================================================================================

  // CASO SEJA O SETOR DA MONTAGEM (ENDEREÇO 7)
  if (Dados[6] == '1')
  {

    char Receptor[4];
    Receptor[0] = Dados[1];
    Receptor[1] = Dados[2];
    Receptor[2] = Dados[3];
    Receptor[3] = Dados[4];
    Receptor[4] = '\0';

    int OS = atoi(Receptor);
    Serial.print("OS Recebida: ");
    Serial.println(OS);

    //=> Inicia o Arduino Leonardo como um Teclado
    Keyboard.begin();
    Keyboard.print(OS);

    Keyboard.write(KEY_TAB);

    Keyboard.print("Setor 1");

    Keyboard.write(KEY_RETURN);
    Keyboard.write(KEY_LEFT_ARROW);

    Keyboard.end();
    //=> Encerra a operação do modo teclado
  }

  //==============================================================================================================

  else if (Dados[6] == '2')
  {

    char Receptor[4];
    Receptor[0] = Dados[1];
    Receptor[1] = Dados[2];
    Receptor[2] = Dados[3];
    Receptor[3] = Dados[4];
    Receptor[4] = '\0';

    int OS = atoi(Receptor);
    Serial.print("OS Recebida: ");
    Serial.println(OS);

    //=> Inicia o Arduino Leonardo como um Teclado
    Keyboard.begin();
    Keyboard.print(OS);

    Keyboard.write(KEY_TAB);

    Keyboard.print("Setor 2");

    Keyboard.write(KEY_RETURN);
    Keyboard.write(KEY_LEFT_ARROW);

    Keyboard.end();
    //=> Encerra a operação do modo teclado
  }
}
