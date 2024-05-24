#include<stdio.h>

void Maior_Menor(int N) {
    int i;
    float n, maior, menor;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n);
    maior = n;
    menor = n;

    for (i = 2; i <= N; i++) {
        printf("Digite o %d numero: ", i);
        scanf("%f", &n);

        if (n > maior) {
            maior = n;
        }

        if (n < menor) {
            menor = n;
        }
    }

    printf("O maior numero: %.2f\n", maior);
    printf("O menor numero: %.2f\n", menor);
}

int main(){
    int N;

    printf("\nDigite a quantidade de numeros que deseja inserir: ");
    scanf("%d", &N);

    Maior_Menor(N);

    return 0;
}