//Programa que calcule a soma dos numeros pares entre 1 e 75
#include<stdio.h>
int main()
{
    int soma=0;
     for (int i = 1; i <= 75; i++) {
        if (i % 2 == 0) {
            soma += i;
        }
     }
     printf("a soma dos numeros pares entre 1 e 75 e: %d",soma);

     return 0;
}


