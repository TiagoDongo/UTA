#include<stdio.h>
#include"funcoes.h"

//1 - elabore uma função que calcule por recorrencia potências de 2 
int potencia_2(int n){
    if(n == 0){
        return 1;
    }
    else{
        return 2*potencia_2(n-1);
    }
}

//2 - elabore um procedimento recursivo que conte por ordem decrescente de N para zero
void ordem(int n){
    if(n==0){
        printf("%d\n",n);
    }
    else{
        printf("%d\n",n);
        ordem(n-1);
    }
}

//3 - Elabore um procedimento recursivo que imprima um número por ordem inversa.
void inversao_numero(int n){
    if(n<10){
        printf("%d",n);
    }
    else{
        printf("%d",n%10);
        inversao_numero(n/10);
    }
}

//4 - Elabore um procedimento recursivo que imprima um determinado vetor por ordem inversa.
void inversao_vetor(int v[],int tam){
    if(tam > 0){
        printf("%d",v[tam-1]);
        inversao_vetor(v, tam - 1);
    }
    else{
        printf("\n");
    }
}

//5 - Elabore uma função recursiva que conte os elementos de um vetor de inteiros que sejam inferiores a um dado número.
int contar_n(int v[],int tam,int n){
    if(tam == 0){
        return 0;
    }
    else if(v[0]<n){
        return 1 + contar_n(v + 1, tam - 1, n);
    }
    else{
        return contar_n(v + 1, tam - 1, n);
    }
}

//6 - Elabore uma função recursiva que calcule o somatório dos elementos de um vetor.
int somar(int v[],int tam){
    if(tam == 0){
        return 0;
    }
    else{
        return v[0] + somar(v + 1, tam - 1);
    }
}

//7 - Escreva um programa que calcule o máximo divisor comum de dois números inteiros positivos, baseando-se nas seguintes propriedades:
int mdc(int m, int n){
    if(n == 0){
        return m;
    }
        return mdc(n, m % n);
}

//8 - Implemente uma função recursiva que permita calcular a potência
int calcular_potencia(int x, int n){
    if(n == 0){
        return 1;
    }
    else if(n > 0){
        return x * calcular_potencia(x, n - 1);
    }
    else{
        return  calcular_potencia(x, n + 1) / x;
    }
}

/*9 - Pretende-se implementar uma função recursiva que recebe dois números inteiros positivos calcule o valor da função de Ackermann. A função de Ackermann é definida pela seguinte relação de recorrência*/
int Ackermann(int m, int n){
    if(m == 0){
        return n + 1;
    }
    else if(n == 0){
        return Ackermann(m - 1, 1);
    }
    else if (m > 0 && n > 0)
    {
        return Ackermann(m - 1, Ackermann(m, n - 1));
    }
}

/*10 - Escreva uma função que devolva o número de Fibonacci associado a um determinado inteiro positivo. A sequência de Fibonacci, é definida da seguinte forma:*/
int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

/*11 - O puzzle Torres de Hanoi com 3 colunas resolve-se, para um número n de peças(discos), em h(n) = 2 x h(n-1)+1 movimentos (para n>1) e h(1) = 1. Desenvolva uma função recursiva para determinar h(n) e caso n < 1 a função deve devolver -1. */
int hanoi(int n){
    if (n < 1){
        return -1;
    }
    else if (n == 1){
        return 1;
    }
    else{
        return 2 * hanoi(n - 1) + 1;
    }
}
