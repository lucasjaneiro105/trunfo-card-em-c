# trunfo-card-em-c
trabalho da materia de algoritmo, o programa feito na linguagem c gera mil cartas de jogadores com tributos aleatórios  

Esse codigo gera um jogo de cartas chamado "Trunfo" com atletas de futebol do Brasil. Ele gera aleatoriamente um conjunto de cartas de atletas, salva as informações dessas cartas em um arquivo CSV e, em seguida, permite que o usuário jogue o jogo com a ajuda de uma lista encadeada de jogadores.

O programa começa gerando as cartas de atletas com a função gerar_cartas, que define as características de cada carta e as armazena em um array de CartaAtleta. Em seguida, ele salva as informações dessas cartas em um arquivo CSV com a função salvar_cartas. A partir daí, o usuário pode jogar o jogo.

Como rodar o código:

Para rodar esse programa, é necessário um compilador C, como o GCC. Basta salvar o código em um arquivo com a extensão .c, abri-lo em um terminal e compilá-lo com o comando gcc main.c -o jogo. Em seguida, execute o programa digitando ./jogo no terminal. Certifique-se de ter todas as bibliotecas necessárias instaladas.
