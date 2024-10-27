#include <stdio.h>
#include <stdlib.h>
#include"header.h"

//função para adicionar numero a lista
int potencia(int base, int expoente){
    if (base == 0 && expoente == 0)
    {
        return 1;
    }
    else if (expoente < 0){
        return 0;
    }
    
    else if (base == 0){
        return 0;
    }
    else if ( expoente == 0){
        return 1;
    }
    else{
        return base*potencia(base, expoente - 1);
    }
}
//funcao para comparar uma potencia  com a mesma potencia so que tem a base e o expoente trocadas de lugar
void comparacao(int p1, int p2){
    if (p1 > p2){
                printf("%d e maior que %d\n",p1, p2);
            }
            else if (p1 < p2){
                printf("%d e menor que %d\n",p1, p2);
            }
            else{
                printf("%d e igual a %d\n",p1, p2);
            }
}

//função responsavel por fazer as operaçoes de multiplicação,divisão e potencia de potencia
void operacoe_basicas(){
    //vareaveis
    int base1,base2,expo1,expo2;
    int n;
    int result;
    int sub_opcao;

    //ciclo do-while que continuara a rodar enquanto a opção escolhida for diferente de 3
    do{
        printf("\n--------MENU--------\n");
        printf("1. Multiplicacao ou divisao de potencias\n"); 
        printf("2. potencia de potencia\n");
        printf("3. Sair\n");
        printf("Escolha a sua opcao: ");
        scanf("%d",&n);

        switch (n)
        {
            //1º caso
        case 1:
            printf("\nDigite a base: ");
            scanf("%d", &base1);
            printf("\nDigite o expoente: ");
            scanf("%d", &expo1);
            printf("\n");
            printf("\nDigite a base: ");
            scanf("%d", &base2);
            printf("\nDigite o expoente: ");
            scanf("%d", &expo2);

            printf("\n---subMenu---");
            printf("\n1. Multiplicacao");
            printf("\n2. Divisao");
            printf("\n3. Sair");
            printf("\nEscolha a sua opcao: ");
            scanf("%d",&sub_opcao);
            
            //sub meno para o utilizador escolher qual operação deseja fazer
            switch (sub_opcao){
            //multiplicação ou divisão de potencias com a mesma base
            case 1:
                if (base1== base2){
                    result = potencia(base1, expo1 + expo2);
                    printf("O resultado do produto e %d\n",result);
                }
                else{
                    printf("As potencias tem bases diferente\n");
                }
                break;

            case 2:
                if (base1 == base2){
                    if (expo1 >= expo2) {
                        result = potencia(base1, expo1 - expo2);
                        printf("O resultado da divisao e %d\n", result);
                    } 
                    else {
                        printf("\nExpoente resultante negativo. Operacao invalida no contexto atual\n");
                    }
                }
                else{
                    printf("\nAs potencias tem bases diferente\n");
                }
                break;

            case 3:
                printf("\nVoltando ao menu principal\n");
                break;
            
            default:
                printf("\nOpcao invalida\n");
                break;
            }
            break;

            //2º caso potencia de potencia
        case 2:
            printf("\nDigite a base: ");
            scanf("%d", &base1);
            printf("\nDigite o expoente 1: ");
            scanf("%d", &expo1);
            printf("\nDigite o expoente 2: ");
            scanf("%d", &expo2);
            result = potencia(potencia(base1, expo1), expo2);
            printf("O resultado da potencia de potencia e %d",result);
            break;

            //3º caso para sair do switch
        case 3:
            printf("\nSaindo\n");
            break;

        default:
            printf("\nOpcao invalida\n");
            break;
        }
        
    } while (n != 3); //condição de paragem do ciclo do-while
    
}