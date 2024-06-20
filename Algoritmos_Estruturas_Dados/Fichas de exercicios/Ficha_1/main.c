#include<stdio.h>
#include"funcoes.h"

int main(){
    int opcao,n,tam,m,x;

    do{
        printf("\nEscolha uma opcao:\n");
        printf("1 - Potencia de 2\n");
        printf("2 - Ordem decrescente\n");
        printf("3 - Inversao de numero\n");
        printf("4 - Inversao de vetor\n");
        printf("5 - Contar elementos menores que n em um vetor\n");
        printf("6 - Somatorio dos elementos de um vetor\n");
        printf("7 - Maximo divisor comum\n");
        printf("8 - Calcular potencia\n");
        printf("9 - Funcao de Ackermann\n");
        printf("10 - Fibonacci\n");
        printf("11 - Torres de Hanoi\n");
        printf("12 - Sair\n");
        
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:{
            printf("\nDigite um numero: ");
            scanf("%d", &n);
            printf("\nPotencia: 2^%d = %d\n", n, potencia_2(n));
            break;
        }
        
        case 2:{
            printf("\nDigite um numero: ");
            scanf("%d", &n);
            ordem(n);
            break;
        }

        case 3:{
            printf("\nDigite um numero: ");
            scanf("%d", &n);
            printf("\nInversao do numero %d: ", n);
            inversao_numero(n);
            printf("\n");
            break;
        }

        case 4:{
            printf("\nDigite o tamanho do vetor: ");
            scanf("%d", &tam);
            int v[tam];
            printf("\nDigite os elementos do vetor: ");
            for(int i = 0; i < tam; i++) {
                scanf("%d", &v[i]);
            }
            printf("\nInversao do vetor: ");
            inversao_vetor(v, tam);
            break;
        }

        case 5:{
            printf("\nDigite o tamanho do vetor: ");
            scanf("%d", &tam);
            int v[tam];
            printf("\nDigite os elementos do vetor: ");
            for(int i = 0; i < tam; i++) {
                scanf("%d", &v[i]);
            }
            printf("\nDigite o valor de n: ");
            scanf("%d", &n);
            printf("\nQuantidade de elementos menores que %d: %d\n", n, contar_n(v, tam, n));
            break;
        }

        case 6:{
                printf("\nDigite o tamanho do vetor: ");
                scanf("%d", &tam);
                int v[tam];
                printf("\nDigite os elementos do vetor: ");
                for(int i = 0; i < tam; i++) {
                    scanf("%d", &v[i]);
                }
                printf("\nSomatorio dos elementos do vetor: %d\n", somar(v, tam));
                break;
            }

        case 7:{
            printf("\nDigite dois numeros: ");
            scanf("%d %d", &m, &n);
            printf("\nMDC de %d e %d: %d\n", m, n, mdc(m, n));
            break;
        }

        case 8:{
            printf("\nDigite a base e o expoente: ");
            scanf("%d %d", &x, &n);
            printf("%d^%d = %d\n", x, n, calcular_potencia(x, n));
            break;
        }

        case 9:{
            printf("\nDigite dois numeros para a funcao de Ackermann: ");
            scanf("%d %d", &m, &n);
            printf("\nAckermann(%d, %d) = %d\n", m, n, Ackermann(m, n));
            break;
        }

        case 10:{
            printf("\nDigite um numero: ");
            scanf("%d", &n);
            printf("\nFibonacci(%d) = %d\n", n, fibonacci(n));
            break;
        }

        case 11:{
            printf("\nDigite o numero de discos: ");
            scanf("%d", &n);
            printf("\nNumero de movimentos para resolver Torres de Hanoi com %d discos: %d\n", n, hanoi(n));
            break;
        }

        case 12:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }

    } while (opcao != 12);
    
    return 0;
}