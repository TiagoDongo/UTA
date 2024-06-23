#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"lista_simples.h"

int main(){
    PALUNO head;
    criar(&head);

    int opcao, numero, n;
    char nome[100];

    do{
        printf("\n\n----------MENU----------\n");
        printf("1 - Inserir dados do alunos.\n");
        printf("2 - Mostrar os alunos.\n");
        printf("3 - Procura aluno por nome.\n");
        printf("4 - Procura aluno por numero.\n");
        printf("5 - Deletar um aluno da lista.\n");
        printf("6 - Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d",&opcao);
        printf("--------------------------------\n");


        switch (opcao){
            case 1:
                printf("\nQuantos aluno voce deseja digitar dados: ");
                scanf("%d",&n);
                printf("\n");
                for(int i = 0; i < n; i++){
                    inserir_dados(&head);
                }
                break;

            case 2:
                show(head);
                break;

            case 3:
                printf("\nDigite o nome do aluno: ");
                scanf("%s", nome);
                if(searchByname(head, nome)){
                    printf("\nAluno encontrado.\n");
                }
                else{
                    printf("\nAluno nao encontrado.\n");
                }
                break;

            case 4:
                printf("\nDigite o numero do aluno: ");
                scanf("%d", &numero);
                if (searchBynumber(head, numero)) {
                    printf("\nAluno encontrado.\n");
                }
                else {
                    printf("\nAluno nao encontrado.\n");
                }
                break;

            case 5:
                printf("\nDigite o nome do aluno a ser deletado: ");
                scanf("%s", nome);
                head = deleteStudent(head, nome);
                if(head){
                    printf("\nAluno %s deletado com sucesso!.\n",nome);
                }
                else{
                    printf("\nAluno %s nao esta na lista ou ja foi deletado.\n",nome);
                }
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("ERRO: Opcao invalida!\n");
                break;
        }
    }while (opcao != 6);

    return 0;
}
