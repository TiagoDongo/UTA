#include<stdio.h>

int Ackermann(int m, int n){
    if(m == 0){
        return n + 1;
    }
    else if (n == 0){
        return Ackermann(m - 1, 1);
    }
    else if (n > 0 && m > 0){
        return Ackermann(m - 1, Ackermann(m, n - 1));
    }
}

int main(){
    int m, n;

    printf("Digite um valor positivo: ");
    scanf("%d",&m);

    printf("\nDigite um segundo valor positivo: ");
    scanf("%d",&n);

    if (n < 0 && m < 0){
        return 1;
    }

    printf("O valor de de Ackermann de %d e %d e %d",m,n,Ackermann(m,n));
    



    return 0;
}