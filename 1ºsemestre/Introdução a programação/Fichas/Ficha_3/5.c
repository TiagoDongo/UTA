#include<stdio.h>

int main(){
    int n, i=1, fatorial=1;

    printf("Digite um numero: ");
    scanf("%d",&n);

    while (i<=n){
        fatorial*=i;
        i=i+1;
    }

    printf("O fatorial de %d e: %d",n,fatorial);

    return 0;
}