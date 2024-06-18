//Escreva um programa que solicita ao utilizador cinco n�meros e calcula o total dos n�meros.
#include<stdio.h>
int main()
{
    int i,j,total=0;
    for(j=0;j<=5;j++){
        printf("Por favor,digite o %d numero: ",j+1);
        scanf("%d",&i);
        total+=i;
    }
    printf("o total dos numeros e de: %d",total);

    return 0;
}
