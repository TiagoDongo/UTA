#include<stdio.h>
#define ATLETAS 5
#define SESSOES 7

void leMatriz(float tempos[][SESSOES], int atletas, int sessoes) {
    for (int i = 0; i < atletas; i++) {
        for (int j = 0; j < sessoes; j++) {
            printf("Digite o tempo do atleta %d na %d sessao : ", i + 1, j + 1);
            scanf("%f", &tempos[i][j]);
        }
    }
}

void escreveMediaColunas(float tempos[][SESSOES], int atletas, int sessoes) {
    printf("\nMedia dos tempos em cada sessao:\n");
    for (int j = 0; j < sessoes; j++) {
        float soma = 0;
        for (int i = 0; i < atletas; i++) {
            soma += tempos[i][j];
        }
        printf("Sessao %d: %.2f segundos\n", j + 1, soma / atletas);
    }
}

void escreveMinimoLinhas(float tempos[][SESSOES], int atletas, int sessoes) {
    printf("\nMelhor tempo de cada atleta:\n");
    for (int i = 0; i < atletas; i++) {
        float min = tempos[i][0];
        for (int j = 1; j < sessoes; j++) {
            if (tempos[i][j] < min) {
                min = tempos[i][j];
            }
        }
        printf("Atleta %d: %.2f segundos\n", i + 1, min);
    }
}

int main() {
    float tempos[ATLETAS][SESSOES];

    leMatriz(tempos, ATLETAS, SESSOES);
    escreveMediaColunas(tempos, ATLETAS, SESSOES);
    escreveMinimoLinhas(tempos, ATLETAS, SESSOES);

    return 0;
}
