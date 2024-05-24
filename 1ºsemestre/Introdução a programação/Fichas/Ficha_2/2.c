//Elabore um programa que converta temperaturas de Fahrenheit para Celsius ou de Celsius para Fahrenheit.
//Solicita a temperatura inicial ao utilizador.
//O programa deve pedir o tipo de conversão e, em seguida, efetuar a conversão.
//As formulas sao: C = (F − 32) × 5/9 e F = (C × 9/5) + 32.
//Exemplo de saida (Output)
//Escolha o carater 'C' para converter de Fahrenheit para Celsius.
//Escolha o carater 'F' para converter de Celsius para Fahrenheit.
#include<stdio.h>
void main()
{
    char opcoes;
    float temp_inicial,resultado;
    printf("\ninsira 'c' ou 'C' para comverter fahrenheit para celcios\n");
    printf("\nincira 'f' ou 'F' para comverter celcios em fahrenheit\n\n");
    printf("\nintroduza uma opcaoa sua escolha: ");
    scanf("%c",&opcoes);

    if(opcoes=='c'||opcoes=='C'){
        printf("Insira a temperatura inicial em fahrenheit: ");
        scanf("%d",&temp_inicial);
        resultado=(temp_inicial-32)*5/9;
        printf("a temperatura em celcios e de: %d\n\n",resultado);
    }
    else if(opcoes=='f'||opcoes=='F'){
        printf("Insira a temperatura inicial em celcios: ");
        scanf("%d",&temp_inicial);
        resultado=(temp_inicial*9/5)+32;
        printf("a temperatura em fahrenheit e de: %d\n\n",resultado);
    }
    else{
        printf("A opcao iserida esta incorreta ou nao existe");
    }
}
