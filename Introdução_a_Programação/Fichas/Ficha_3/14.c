#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int nivel, numero_secreto, palpite, tentativas;
    char jogar_novamente;

    printf("Vamos jogar 'Adivinhe o numero'.\n");
    do {
        // Solicita o nível de dificuldade
        printf("Escolha um nivel de dificuldade (1, 2 ou 3): ");
        scanf("%d", &nivel);

        // Define o limite superior baseado no nível de dificuldade
        int limite_superior;
        switch (nivel) {
            case 1:
                limite_superior = 10;
                break;
            case 2:
                limite_superior = 100;
                break;
            case 3:
                limite_superior = 1000;
                break;
            default:
                printf("Nivel de dificuldade invalido. Escolha 1, 2 ou 3.\n");
                continue;
        }

        // Gera o número aleatório
        srand(time(NULL));
        numero_secreto = rand() % limite_superior + 1;

        // Inicializa o número de tentativas
        tentativas = 0;

        printf("Eu tenho o meu numero. Qual e o seu palpite? ");

        // Loop do jogo
        do {
            scanf("%d", &palpite);
            tentativas++;

            if (palpite == numero_secreto) {
                printf("Parabens! Voce adivinhou o numero em %d tentativas.\n", tentativas);
                break;
            } else if (palpite < numero_secreto) {
                printf("Muito baixo. Tente novamente: ");
            } else {
                printf("Muito alto. Tente novamente: ");
            }
        } while (1);

        // Pergunta se o jogador quer jogar novamente
        printf("Quer jogar novamente? (s/n): ");
        scanf(" %c", &jogar_novamente);
    } while (jogar_novamente == 's' || jogar_novamente == 'S');

    printf("Obrigado por jogar!\n");

    return 0;
}
