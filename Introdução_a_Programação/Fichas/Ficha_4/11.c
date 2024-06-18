#include<stdio.h>

int mdc(int m, int n){
    if (n == 0){
        return m;
    }

    else{
        return mdc(n, m % n);
    }
}

int main(){
    int m, n;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d",&m);

    printf("Digite outro numero inteiro positivo: ");
    scanf("%d",&n);

    if (m <= 0 || n <= 0) {
        printf("Ambos os números devem ser inteiros positivos.\n");
        return 1;
    }

    printf("O maximo divisor comum enter %d e %d e: %d",m,n,mdc(m,n));

    return 0;
}