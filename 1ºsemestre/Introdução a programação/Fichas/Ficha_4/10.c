#include<stdio.h>

int fatorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        int resultado = 1;
        for (int i = 2; i <= num; i++) {
            resultado *= i;
        }
        return resultado;
    }
}

int combinacoes(int m, int n) {
    if (n > m) {
        return 0;  
    }
    int  fatorialM = fatorial(m);
    int  fatorialN = fatorial(n);
    int  fatorialMmenosN = fatorial(m - n);
    
    return fatorialM / (fatorialN * fatorialMmenosN);
}

int main() {
    int m, n;

    printf("Digite o valor de m: ");
    scanf("%d", &m);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n > m) {
        printf("O valor de n deve ser menor ou igual a m.\n");
    } else {
        int resultado = combinacoes(m, n);
        printf("C(%d, %d) = %d\n", m, n, resultado);
    }

    return 0;
}