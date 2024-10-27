/*
    *Programa que calcula a potencia de um numero
    *compara a potencia calculada com o outra potencia que tem a base e o expoente trocadas de lugar
    *usuario pode escolher a base e o expoente
 */

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include"header.h"

int main(){
    //variaveis
    int base,expoente,opcao, resultado,r1,r2;
    int *n_base, *n_expoente;

    //ciclo do-while que ira rodar enquanto a opcao for diferente de 2
    do{
        printf("\n--------MENU--------\n");
        printf("1. Calcular Potencia\n"); 
        printf("2: Comparar a potencias\n");
        printf("3. Operacoes de potencias\n");
        printf("4. Sair\n");
        printf("Escolha a sua opcao: ");
        scanf("%d",&opcao);


        switch (opcao){
        //calcula a potencia com os dados fornecidos
        case 1:

            printf("\nDigite a base: ");
            scanf("%d", &base);
            printf("\nDigite o expoente: ");
            scanf("%d", &expoente);

            // Usando ponteiros para armazenar os valores
            n_base = &base;
            n_expoente = &expoente;

            //calculo da potencia
            resultado = potencia(*n_base,*n_expoente);

            printf("\n%d elevado a %d é: %d\n", base, expoente, resultado);
            break;
        
        //comparação de duas de uma potencia com a mesma so que com base e expoente trocada de lugar
        case 2:
            printf("\nDigite a base: ");
            scanf("%d", &base);
            printf("\nDigite o expoente: ");
            scanf("%d", &expoente);

            // Usando ponteiros para armazenar os valores
            n_base = &base;
            n_expoente = &expoente;

            //calcula das potencias
            r1= potencia(*n_base,*n_expoente);
            r2= potencia(*n_expoente,*n_base);

            //exibicao do resultado das potencias
            printf("%d elevado a %d é: %d\n", base, expoente, r1);
            printf("%d elevado a %d é: %d\n", expoente, base, r2);
            comparacao(r1,r2);
            break;

        case 3:
            operacoe_basicas();
            break;
        //opcao para sair do programa
        case 4:
            printf("Saindo do programa.\n");
            break;

        //caso a opcao inserida nao estiver no menu
        default:
            printf("Opcao invalida.\n");
            break;
        }

    } while (opcao != 4); //condicao de paragem do ciclo

    return 0;
}
