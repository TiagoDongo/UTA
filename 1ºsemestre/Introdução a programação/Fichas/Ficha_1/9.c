//Elabore um algoritmo que leia o valor do salário mínimo e o valor do salário de
//uma pessoa. Calcular e imprimir quantos salários mínimos essa pessoa ganha.
#include<stdio.h>
void main()
{
float salariomin,salariopessoal,quantsalarios;

printf("qual e salario minimo:");
scanf("%f",&salariomin);

printf("qual e o seu salario:");
scanf("%f",&salariopessoal);

quantsalarios=salariomin/salariopessoal;

printf("a quantidade de salarios minimos ganhos e:%.f",quantsalarios);
}
