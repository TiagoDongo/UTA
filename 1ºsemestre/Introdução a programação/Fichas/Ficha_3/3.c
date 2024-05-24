//programa que calcula todos os divisores de um numero. Exemplo do programa ao ser executado:
//Exemplo de saida (Output)
//Introduz um numero:24
//Os divisores de 24 s�o 1, 2, 3, 4, 6, 8, 12, 24
#include<stdio.h>
int main()
{
        int n;
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
                if (n % i == 0) {
                        printf(" %d , ",i);
        }
        }
        
        printf(" sao divisores de %d",n);

        return 0;
}


