/* ----> ATENÇÃO!  TODAS AS ORIENTAÇÕES DE INÍCIO DE PROGRAMAÇÃO, DRIVERS, MONTAGEM, DETALHES DE COMPONENTES, PINAGEM ESTARÃO NESTA ABA.
 *  
 *  
 * -> Projeto: Central de Combate a Incêndio
 * -> Empresa Responsável: RIEX EQUIPAMENTOS CONTRA INCÊNDIO LTDA
 *   
 * :Autor: Gustavo Oliveira Ferreira dos Santos
 * :Supervisor: Rubem de Gusmão  
 * :Email Autor: santos.gustavo.of@gmail.com
 * :Email Supervisor: riex@riex.com
 * :Data: /04/2022
 * :Revisão: v2
 * 
 * 
 * |=== S U M Á R I O
 * | LINHA |       TÓPICO       
 * |  35   | Lista de componentes
 * |  57   | Guia de conexão 
 * |  120  | Orientações para início da programação em novas placas
 * |  132  | Descrição das abas/funções e suas rotinas 
 * |  194  | Escolhas Incomuns na lógica de programação 
 * | | 
 * | | 
 * | | 
 * | | 
 * | |
 * | |
 * | |
 * | | 
 * | | 
 * | | 
 * |===
 * 
 * 
 * 
 *  -> Segue a Listagem de Componentes Necessários para a Montagem
 * 
 * |=== P/ MONTAGEM ELETRÔNICA
 * | ID |       Componentes       | Quantidade
 * | AD | Arduino Mega 2560 R3    | 1       
 * | M1 | Mod. Relé 5v - 6 Canais | 1        
 * | M2 | Mód. Relé 24v - 6 Canais| 1        
 * | TL | Tela LCD 20x4           | 1
 * | R1 | Resistor 250            | 1
 * | R2 | Resistor 3k             | 3
 * | R3 | Resistor 2k             | 1
 * | R4 | Resistor 0,5k           | 1
 * | TM | Teclado Matricial 3x4   | 1
 * | MF | Fio Jumper Macho-Fêmea  | 1 pct
 * | MM | Fio Jumper Macho-Macho  | 1 pct
 * | C1 | Conversor 24v p/ 9v     | 1
 * | B1 | Bateria 24v             | 1 
 * | B2 | Fonte de tensão 24v     | 1 
 * |===
 * 
 * -> Segue o Guia de Conexão para auxiliar na montagem do projeto 
 * 
----------------------------------------------------- GUIA DE CONEXÃO -----------------------------------------------------
 *
 *
---------- PARA TECLADO MATRICIAL 3X4 ----------
 *
 *
-> LINHA 1 TECLADO: Pino Digital 7
-> LINHA 2 TECLADO: Pino Digital 6
-> LINHA 3 TECLADO: Pino Digital 5
-> LINHA 4 TECLADO: Pino Digital 4

-> COLUNA 1 TECLADO: Pino Digital 1
-> COLUNA 2 TECLADO: Pino Digital 2
-> COLUNA 3 TECLADO: Pino Digital 3
 *
 *
---------- PARA TELA LCD 20x4 ----------
 *
 *
-> VSS: GND
-> VDD: 5V
-> V0: Potenciômetro
-> RS: 13
-> RW: GND
-> D4: Pino Digital 12
-> D5: Pino Digital 10
-> D6: Pino Digital 9
-> D7: Pino Digital 8
-> A: 5V
-> K: GND
 *
 *
---------- PARA MOD RELÉ 6 CANAIS 5V ----------
 *
 *
-> VCC: 5V
-> GND: GND
-> INT1: Pino Digital 43 / Sirene
-> INT2: Pino Digital 45 / CO2
-> INT3: Pino Digital 47 / Dumper
-> INT4: Pino Digital 49 / Exaustão
-> INT5: Pino Digital 51 / Shopping
-> INT6: Pino Digital 53 / Ar Condicionado
-> COM X: 5V
-> NA: Conectado no pino positivo periférico
-> NF: Não utilizado
 *
 *
---------- PARA MOD RELÉ 6 CANAIS 24V ----------
 *
 *
-> DC+: 24v
-> DC-: GND
-> IN1: Conectado na Saída de sinal do Sensor utilizado
-> IN2: Conectado na Saída de sinal do Sensor utilizado
-> COM1: GND
-> COM2: GND
-> NO: Conectado no Pino Digital referente a entrada
-> NF: Não utilizado
 *
 *
---------------------------------------------------------------------------------------------------------------------------
 * 
 * |=== Orientações para Inicio de programação em nova placa
 * 
 * -> Caso o Arduino Mega utilizado seja um genérico e esteja compilando em outro computador, instale o driver "CH340" no computador para que o mesmo reconheça o Arduino.
 * 
 * -> Antes de carregar o código principal, limpe a memória EEPROM do Arduino, pois ela pode ocasionar erros ao ser utilizada, considerando que a EEPROM é essencial nesse
 * projeto. Para isso, ainda na IDE, abra "Arquivo > Exemplos > EEPROM > eeprom_clear" e compile o código. Caso queira verificar, faça o mesmo caminho, mas abre o 
 * "eeprom_read" e compile. Todos os endereços devem estar como  "0".
 * 
 * 
---------------------------------------------------------------------------------------------------------------------------
 * 
 * |=== Descrição de cada Aba/Funções e suas rotinas
 * 
 * ------> Def_Matriz
 * 
 * -> Responsável por fazer as declarações do teclado matricial e é chamada dentro da função "Teclado_Senha", pois facilita a leitura desta.
 * 
 * 
 * 
 * ------> Teclado_Senha
 * 
 * ----> NESSA FUNÇÃO, VOCÊ PRECISA DECLARAR QUAL É A SENHA MASTER QUE SERÁ UTILIZADA PARA RESETAR A CENTRAL NA MANUNTENÇÃO.
 * Obs: A Senha deve ter no máximo 29 dígitos.
 * 
 * --> Essa função é responsável por:
 * 
 * Chama a função Def_Matriz para ser capaz de realizar a leitura
 * Ler os dígitos do teclado matricial
 * Dar um retorno do que foi digitado na tela LCD
 * Definir a senha que ser utilizada
 * Comparar o que foi digitado com uma senha Pré Estabelecida
 * Caso a senha esteja incorreta, se mantém preso nesssa função, até que se acerte
 * Caso a senha esteja correta, a função "Reset_Master" é chamada
 * 
 *  ------> Reset_Master
 *  
 *  ---> No geral, essa função vai atualizar para 0 as variáveis que são alteradas quando algum sensor ou botão dispara a central e armazena na memória
 *  não volátil, para que caso a Central seja desligada, ela permaneça exatamente onde parou, totalmente zerada na tela inicial. 
 *  
 *  -> Essa função é responsável por:
 *  
 *  Tornar todas as variáveis "Indicadoras" e "Resultados de função" como 0
 *  Armazenar essas variáveis zeradas na memória EEPROM, chamando a função EEPROM_Int
 * 
 *  ------> EEPROM_Int 
 *  
 *  ---> Nessa função é onde  é feito as operações de armazenamento de variáveis inteiras. Ela se torna necessária a partir do momento que ela facilita esse 
 *  processo, porquê como 1 inteiro ocupa 2 Bytes, ao fazer a leitura e armazenamento seria necessário cálculos repetitivos e essa função facilita fazendo 
 *  essas contas com apenas 1 comando/linha.
 * 
 * --> Nesse projeto, a EEPROM é utilizada para que os dados não sejam perdidos caso ocorra algum desligamento com corte de energia ou esgotamento da bateria. Assim, toda vez
 * que a Central for disparada, ela armazena o sensor que foi disparado, se o Co2 precisa ou  não de recarga..., voltando exatamente de onde parou caso seja desligada, impedindo
 * que as informações sejam omitidas.
 * 
 *   ------> Bloqueio_Co2_SetMillis
 *   
 *   ---> Essa aba aglomera duas funções separadas, mas que na maioria das vezes, são usadas simultâneamente, a Função de Bloqueio do Co2 e a Função responsável por Setar o
 *   o Millis(). Elas são usadas simultâneamente porque o Co2 precisa esperar 30s antes de ser disparado, mas ao mesmo tempo, tem que estar disponível para ler o botão de entrada
 *   pode impedir essa disparo. Por isso, o Millis é utilizado, mas para evitar problema de Overflow (já que a central será utilizada por tempo indeterminado e a capacidade de 
 *   contagem do millis é limitada) o millis é Setado como 0 toda vez que a função Bloqueio for iniciada e a partir daí, conta-se 30.000 millisegundos (30 segundos), caso não 
 *   ocorra nenhuma interrupção.
 * 
 *  -> Essa função é responsável por: 
 *  
 *  Setar o temporizador como 0
 *  Iniciar a contagem repetitiva de no máximo 30 segundos
 *  Mostra na tela quanto tempo falta para que o Co2 dispare
 *  Caso o botão de Bloqueio for apertado, ele sai da função retornando 0 e avisando que o Bloqueio foi ativo 
 *  Caso se passe 30 segundos e o botão não for pressionado, ele avisa que o Co2 foi disparado, sai da funçaõ retornado 1 e dispara o Co2
 * 
 * 
 ---------------------------------------------------------------------------------------------------------------------------
 * 
 * |=== Escolhas incomuns na lógica de programação
 * 
 * -> No "Void Setup" (Aba principal), na declaração como entrada para os sensores, foi necessário uma lógica diferente do usual para evitar problemas. Nesse projeto, os
 * sensores emitiriam um sinal Positivo(5v) ao Arduino quando houvesse alguma detecção e o 0v seria o Repouso, logo declarando como "INPUT". Porém, nessa declaração, os pinos 
 * de entrada ficaram flutuando, com valores aleatórios e inconstantes, sendo necessário usar um "PULL DOWN" ou um "PULL UP". Para usar o pull down, seria necessário utilizar 
 * resistores, o que aumentaria a quantidade de componentes e a dificuldade nas ligação, então utilizei o "INPUT_PULLUP", para manter o valor sempre fixo, evitando a flutuação,
 * mas nesse caso, a 0v seria quem disparia o arduino. Então, no "Void Loop", para evitar confusôes, a leitura dos sensores digitais é sempre invertida, o repouso (5v) como 0 
 * e o ativo(GND) valendo 1, usando " 'variável' = ! digitalread(pino);" . Assim, a ligação do borne de "COM" no relé seria diretamente no GND.
 * 
 * -> Também no "Void Setup", foi declado a variável "unsigned long", ela é a variável que mais ocupa memória disponível no arduino. Ela é utilizada para fazer cálculos, 
 * leituras e armazenamento dos valores lidos na função millis(). Caso qualquer outra variável seja utilizada com o Millis, até mesmo o "long", é muito provável que ocorram 
 * problemas.
 *  
 * -> Em todo o código é possível notar um excesso de funções separadas do código principal e isso se deve pela proporção desse projeto. Por ele ter uma quantidade grande de
 * rotinas independentes umas das outras, que se relacionam ou que se repetem diversas vezes no mesmo código, acaba sendo necessário que ocorra essa separação para facilitar
 * a leitura do usuário, do programador e não tornar o código principal excessivamente grande, confuso e repetitivo. Além de tornar mais fácil a localização de erros e de
 * seções específicas do código.
 * 
 * -> O "millis()" se tornou preferível ao "delay()", porquê ao se utilizar o delay, o controlador para de fazer qualquer leitura de informação, seja de código ou das entradas
 * de sinal durante o período determinado pelo programador, sendo que era necessário, na maioria das vezes, ter a possibilidade de fazer algum tipo de leitura durante o tempo
 * em que se deveria esperar para realizar alguma ação.
 * 
---------------------------------------------------------------------------------------------------------------------------
 */
