//------------ FUNÇÃO COM A DECLARAÇÃO DE TODOS OS OBJETOS E VARIÁVEIS DO TECLADO MATRICIAL ------------//

void DefTecladoMatriz(){
  
  const byte LINHAS = 4; // quantidade de linhas do teclado
  const byte COLUNAS = 3; // quantidade de colunas do teclado

  // Matriz para colocar todos os caracteres do teclado:
  char digitos[LINHAS][COLUNAS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}}; 

  byte pinosLinha[LINHAS] = { 7, 6, 5, 4 }; // pinos de conexão das linhas no arduino 
  byte pinosColuna[COLUNAS] = { 3, 2, 1}; // pinos de conexão das colunas no arduino 

  // Objeto de leitura das teclas com os parâmetros lidos
  Keypad keypad = Keypad( makeKeymap(digitos), pinosLinha, pinosColuna, LINHAS, COLUNAS );
  }
