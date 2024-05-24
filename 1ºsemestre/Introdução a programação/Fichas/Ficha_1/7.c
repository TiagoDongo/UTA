//Elabore um algoritmo que receba uma temperatura em graus Celsius e apresente-a
//em graus Fahrenheit, de acordo com a fórmula: F = (1.8 × C) + 32.
#include<stdio.h>
void main(){
float c,f;
 printf("\nInsira uma temperatura em graus celcios: ");
 scanf("%f",&c);
 f=(1.8*c)+32;
 printf("\nA tepertura em graus fahrenheit e de: %f",f);
}
