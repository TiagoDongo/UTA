#include <stdio.h>

void piramide(int N) {
    int i,j;
    if (N < 2) {
        printf("O valor de N deve ser maior ou igual a 2.\n");
        return;
    }

    for (i = 1; i <= N; i++) {
        for ( j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        for ( j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n"); 
    }
}

int main() {
    int N;

    printf("Digite o valor de N (>= 2): ");
    scanf("%d", &N);

    piramide(N);

    return 0;
}
