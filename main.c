#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef enum {
    GOL,
    DEFESA,
    MEIO,
    ATAQUE,
    LIBERO
} Posicao;

typedef struct {
    int id;
    char primeiroNome[20];
    char sobrenome[20];
    int idade;
    char time[20];
    int valorMercado;
    int forca;
    int velocidade;
    int resistencia;
    int forcaVontade;
    int criatividade;
    bool lideranca;
    Posicao posicao;
    int machucado;
} CartaAtleta;

void gerar_cartas(CartaAtleta* cartas, int num_cartas) {
    char nomes[][20] = {"Lucas", "Gustavo", "Pedro", "Matheus", "João", "Fernando", "Rafael", "Thiago", "Davi", "Breno", "Marcelo", "Caue", "Peron", "Jean", "Maurício", "Ricardo", "Henrique", "Leonardo", "Eduardo", "Carlos"};
   char sobrenomes[][20] = {"Silva", "Santos", "Becker", "Neves", "Oliveira", "Pereira", "Menezes", "Santiago", "Costa", "Carvalho", "Janeiro", "Gomes", "Rodrigues", "Lemos", "Araujo", "Lima", "Castro", "Cavalcanti", "Reis", "Nascimento"};
 char times[][20] = {"Flamengo", "Grêmio", "São Paulo", "Palmeiras", "Fortaleza", "Botafogo", "Fluminense", "América", "Corinthians", "Bahia", "Portuguesa", "Atlético-PR", "Santos", "Cruzeiro", "Vitória", "Internacional", "Goiás", "Volta Redonda", "Vasco", "Chapecoense"};
    int i;
    for (i = 0; i < num_cartas; i++) {
        cartas[i].id = i + 1;
        int nome_idx = rand() % 20;
        int sobrenome_idx = rand() % 20;
        sprintf(cartas[i].primeiroNome, "%s", nomes[nome_idx]);
        sprintf(cartas[i].sobrenome, "%s", sobrenomes[sobrenome_idx]);
        cartas[i].idade = 18 + (rand() % 15);
        int time_idx = rand() % 20;
        sprintf(cartas[i].time, "%s", times[time_idx]);
        cartas[i].valorMercado = 50000 + (rand() % 5000000);
        cartas[i].forca = 50 + (rand() % 50);
        cartas[i].velocidade = 50 + (rand() % 50);
        cartas[i].resistencia = 50 + (rand() % 50);
        cartas[i].forcaVontade = 50 + (rand() % 50);
         50 + (rand() % 50);
        cartas[i].criatividade = 50 + (rand() % 50);
        cartas[i].lideranca = rand() % 2;
        cartas[i].posicao = rand() % 5;
        cartas[i].machucado = rand() % 10;
    }
}

const char* posicao_to_string(Posicao pos) {
    switch (pos) {
        case GOL:
            return "GOL";
        case DEFESA:
            return "DEFESA";
        case MEIO:
            return "MEIO";
        case ATAQUE:
            return "ATAQUE";
        case LIBERO:
            return "LIBERO";
        default:
            return "";
    }
}


void salvar_csv(CartaAtleta* cartas, int num_cartas) {
    FILE* fp;
    fp = fopen("cartas.csv", "w");
    fprintf(fp, "id,primeiroNome,sobrenome,idade,time,valorMercado,forca,velocidade,resistencia,forcaVontade,criatividade,lideranca,posicao,machucado\n");
    int i;
    for (i = 0; i < num_cartas; i++) {
        fprintf(fp, "%d,%s,%s,%d,%s,%d,%d,%d,%d,%d,%d,%d,%s,%d\n", cartas[i].id, cartas[i].primeiroNome, cartas[i].sobrenome, cartas[i].idade, cartas[i].time, cartas[i].valorMercado, cartas[i].forca, cartas[i].velocidade, cartas[i].resistencia, cartas[i].forcaVontade, cartas[i].criatividade, cartas[i].lideranca, posicao_to_string(cartas[i].posicao), cartas[i].machucado);
    }
    fclose(fp);
  
}

int main() {
    srand(time(NULL)); // inicializa a semente do gerador de números aleatórios
    int num_cartas = 1000;
    CartaAtleta cartas[num_cartas];
    gerar_cartas(cartas, num_cartas);
    salvar_csv(cartas, num_cartas);
    return 0;
  
  // O dado liderança é definido por 1 ou 0 (1 - SIM), (0 - NÃO).

 // O dado machucado é definido por 0 a 10, no qual quanto mais alto for o numero mais machucado o jogador está.
}
