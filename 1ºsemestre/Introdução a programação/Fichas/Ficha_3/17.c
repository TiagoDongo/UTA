#include <stdio.h>

int main() {
    int altura, i, j;

    // Solicita a altura do triângulo
    printf("Insira a altura do triangulo: ");
    scanf("%d", &altura);

    // Imprime a parte superior do triângulo
    for (i = 1; i <= altura; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // Imprime a parte inferior do triângulo
    for (i = altura - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
