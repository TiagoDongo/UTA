//Escreva um programa que dada uma data composta pelo mês e o ano (valores
//inteiros introduzidos através do teclado), calcula e escreve no terminal o número
//de dias desse mês. Um ano é bissexto se e só se o ano for divisível por 4 mas
//não por 100 ou então for divisível por 400. Por exemplo: 1980, 1984, 2004 foram
//bissextos; 1800, 1900, foram anos comuns, mas 2000 foi bissexto.
#include<stdio.h>
void main(){
int mes,ano;

printf("digite um mes(1 a 12): ");
scanf("%d",&mes);

printf("digite um ano: ");
scanf("%d",&ano);

switch(mes){
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12:
    printf("O mes %d tem 31 dias",mes);
    break;
case 2:
    printf("o mes %d tem 28 ou 29 dias",mes);
    break;
case 4:
case 6:
case 9:
case 11:
    printf("o mes %d tem 30 dias",mes);
    break;
default:
    printf("%d nao corresponde a nenhum mes",mes);
    break;
}

if(ano/4 && !(ano/100) || ano/400){
    printf(" e %d e um ano bissexto",ano);
}
else {
    printf(" e %d nao e um ano bissexto",ano);
}
}
