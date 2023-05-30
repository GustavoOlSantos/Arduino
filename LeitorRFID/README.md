# Leitor RFID

# Sobre o projeto

Criado com o propósito de verificarem em qual setor de uma empresa o produto está sendo trabalhado, utilizando uma tag RFID para identificar o código do produto e o próprio  controlador identifica o setor.

Consiste em uma rede ponto a ponto (ESP_NOW) de micro controladores ESP2866, onde, apesar de todos poderem se comunicar, a comunicação fica restrita a um relacionamento de mestre (servidor) e escravos (clientes), que aos escravos realizarem a leitura de uma tag válida, esse código é enviado ao mestre/servidor, realiza verificações hierárquicas e digita, automáticamente o código, o setor e outros dados.

<div display="flex" align='center'>
  <img src="https://media.licdn.com/dms/image/C4E22AQHvkA4ezhVg8A/feedshare-shrink_1280/0/1655859885068?e=1688601600&v=beta&t=hf6XxRhna6m5De4iSTLOkBBmlV765A76pD4Gc8L963g"   height="350px"> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;

  <img src="https://media.licdn.com/dms/image/C4E22AQGWPo0mej3Idw/feedshare-shrink_2048_1536/0/1655859884160?e=1688601600&v=beta&t=mZPMIRKrf8aslMQsRzENxF-l8E0RapzEkaVqDDao_to"  height="350px">
</div>

# Tecnologias utilizadas
## Micro Controladores
- C/C++
- Arduíno


# Autor

Gustavo Santos

https://www.linkedin.com/in/gustavo-of-santos/



