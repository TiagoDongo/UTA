//Elabore um programa que dados tres numeros, imprime no terminal o maior numero.
//Exemplo de saida (Output)
//Introduzir o primeiro numero: 1
//Introduzir o segundo numero: 51
//Introduzir o terceiro numero: 2
//O maior numero é 51.
#include<stdio.h>
void main()
{
    int x,y,z;
    printf("\nIntroduza o primeiro numero: ");
    scanf("%d",&x);
    printf("\nIntroduza o segundo numero: ");
    scanf("%d",&y);
    printf("\nIntroduza o terceiro numero: ");
    scanf("%d",&z);

    if(x>y&&x>z){
        printf("\no maior numero e:%d\n",x);
    }

    else if(y>x&&y>z){
        printf("\no maior numero e:%d\n",y);}


    else if(z>x&&z>y){
        printf("\no maior numero e:%d\n",z);}

    else{
        printf("\no maior numero nao existe\n");
    }

}
