#include<stdio.h>

int maior_n(int a, int b, int c){
    int maior;
    if(a>b && a>c){
        maior = a;
    }
    else if(b > a && b > c){
        maior = b;
    }
    else if (c > a && c > b){
        maior = c;
    }

    return maior;
}

int main(){
    int a, b, c;
    printf("Digite o primeiro numero: ");
    scanf("%d",&a);

    printf("Digite o segundo numero: ");
    scanf("%d",&b);

    printf("Digite o terceiro numero: ");
    scanf("%d",&c);

    printf("O maior dos tres numeros e: %d",maior_n(a, b, c));

    return 0;
}