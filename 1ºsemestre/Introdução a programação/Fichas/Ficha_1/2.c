//Programa que receba dois números e ao final mostre a soma, subtraçao, multiplicaçao e a divisao dos numeros lidos.
#include<stdio.h>
void main(){
float x,y;
int soma,subtracao,multiplicacao,divisao;
printf("digite dois numeros: ");
scanf("%f\n%f",&x,&y);
soma=x+y;
subtracao=x-y;
multiplicacao=x*y;
divisao=x/y;
printf("soma:%d \n",soma);
printf("subtracao:%d \n",subtracao);
printf("multiplicacao:%d \n",multiplicacao);
printf("divisao:%d \n",divisao);
}
