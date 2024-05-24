//Escreva um programa que converta um número de 1 a 12 para o mês correspondente.
//Solicita um número e exiba o mês correspondente, com 1 sendo janeiro e12 corresponde a dezembro.
//Para qualquer valor fora desse intervalo, apresenta uma mensagem de erro adequada.
#include<stdio.h>
void main()
{
    int mes;
    printf("Digite um numero entre '1' a '12' para saber que mescada numero representa: ");
    scanf("%d",&mes);

    switch(mes){
    case 1:
        printf("O nome do mes e Janeiro\n");
        break;
    case 2:
        printf("O nome do mes e Fevereiro\n");
        break;
    case 3:
        printf("O nome do mes e Marco\n");
        break;
    case 4:
        printf("O nome do mes e Abril\n");
        break;
    case 5:
        printf("O nome do mes e Maio\n");
        break;
    case 6:
        printf("O nome do mes e Junho\n");
        break;
    case 7:
        printf("O nome do mes e Julho\n");
        break;
    case 8:
        printf("O nome do mes e Agosto\n");
        break;
    case 9:
        printf("O nome do mes e Setembro\n");
        break;
    case 10:
        printf("O nome do mes e Outubro\n");
        break;
    case 11:
        printf("O nome do mes e Novembro\n");
        break;
    case 12:
        printf("O nome do mes e Dezembro\n");
        break;
    default:
        printf("%d nao corresponde a nenhum mes\n",mes);
    }
}
