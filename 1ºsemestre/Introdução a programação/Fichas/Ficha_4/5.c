/*Escreva um programa que pede ao utilizador um valor positivo N. O seu programa deverá voltar a pedir um valor
para N caso o utilizador introduza um valor inválido.Como output, deverá mostrar o número de dígitos que compõem o N, 
assim como a soma dos dígitos de N. Por exemplo, o número 54321 tem 5 dígitos e a soma desses dígitos é 15*/
#include<stdio.h>

int contarDigitos(int num){
    int count = 0;
    while(num != 0){
        num /= 10;
        count++;
    }
    return count;
}

int somaDigitos(int num){
    int soma = 0;
    while(num != 0){
        soma += num % 10;
        num /= 10;
    }
    return soma;
}

int main(){
    int N;

    do{
        printf("Insira um valor positivo: ");
        scanf("%d", &N);
    } while(N <= 0);

    printf("O numero %d tem %d digitos e a soma desses digitos e %d.\n", N, contarDigitos(N), somaDigitos(N));

    return 0;
}