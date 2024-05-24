//Elabore um programa que pede ao utilizador que lhe forneça um número e que imprime no terminal
//positivo, negativo ou zero, caso o número seja, respectivamente, maior, menor ou igual a zero.
#include<stdio.h>
void main()
{
    int i;
    printf("Insira um numero: ");
    scanf("%d",&i);

    if(i<0){
        printf("o numero %d e negativo e menor que zero",i);
    }
    else if(i>0){
        printf("o numero %d e positivo e maior que zero",i);
    }
    else{
        printf("o numero e zero e igual a zero");
    }
}
