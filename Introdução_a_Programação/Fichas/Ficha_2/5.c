//Escreva um programa que leia um número inteiro e mostre uma mensagem indicando se o número é par ou ímpar.
//Sugestão: pode usar o operador resto da divisão.
#include<stdio.h>
void main()
{
    int i;
    printf("Introduza um numero inteiro: ");
    scanf("%d",&i);

    if(i%2==0){
        printf("\n%d e um numero par\n",i);
    }
    else{
        printf("\n%d e um numero impar\n",i);
    }
}
