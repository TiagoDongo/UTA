#include <stdio.h>

void retangulo(int L, int C) {
    int contador = 10002; 

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            // Encontrar o próximo múltiplo de 3
            while (contador % 3 != 0) {
                contador++;
            }
            // Imprimir o múltiplo de 3
            printf("%d ", contador);
            // Avançar para o próximo número
            contador++;
        }
        printf("\n");
    }
}

int main() {
    int L, C;

    printf("Digite o valor de L: ");
    scanf("%d", &L);

    printf("Digite o valor de C: ");
    scanf("%d", &C);

    retangulo(L, C);

    return 0;
}
