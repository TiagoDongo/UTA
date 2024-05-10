#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char usuario[50];
    char equipamento[20];
    char estado[30];
    int devolvido;
}Requisicao;

void adicionarRequisicao(Requisicao requisicoes[], int *numRequisicoes){
    printf("Nome do usuario: ");
    scanf("%s",requisicoes[*numRequisicoes].usuario);
    printf("Equipamento desejado: ");
    scanf("%s",requisicoes[*numRequisicoes].equipamento);
    strcpy(requisicoes[*numRequisicoes].estado,"Pendente");
    requisicoes[*numRequisicoes].devolvido = 0;
    (*numRequisicoes)++;
}

void listarRequisicao(Requisicao requisicoes[], int *numRequisicoes){
    int i;
    printf("\n---Lista de Requisicoes---\n");
    for ( i = 0; i < *numRequisicoes ; i++){
        printf("\nUsuario: %s",requisicoes[i].usuario);
        printf("\nEquipamento: %s",requisicoes[i].equipamento);
        printf("\nEstado: %s",requisicoes[i].estado);
        printf("\nDevolvido: %s",(requisicoes[i].devolvido) ? "Sim" : "Nao");
    }    
}

void processarRequisicao(Requisicao requisicoes[], int numRequisicoes, int opcao) {
    char usuario[50];
    switch (opcao) {
        case 1:
            printf("Digite o nome do usuario para aprovar a requisicao: ");
            scanf("%s", usuario);
            for (int i = 0; i < numRequisicoes; i++) {
                if (strcmp(requisicoes[i].usuario, usuario) == 0 && strcmp(requisicoes[i].estado, "Pendente") == 0) {
                    strcpy(requisicoes[i].estado, "Aprovada");
                    printf("Requisicao aprovada!\n");
                    return;
                }
            }
            printf("Requisicao nao encontrada ou ja aprovada/rejeitada.\n");
            break;

        case 2:
            printf("Digite o nome do usuario para rejeitar a requisicao: ");
            scanf("%s", usuario);
            for (int i = 0; i < numRequisicoes; i++) {
                if (strcmp(requisicoes[i].usuario, usuario) == 0 && strcmp(requisicoes[i].estado, "Pendente") == 0) {
                    strcpy(requisicoes[i].estado, "Rejeitada");
                    printf("Requisicao rejeitada!\n");
                    return;
                }
            }
            printf("Requisicao nao encontrada ou ja foi aprovada/rejeitada\n");
            break;

        default:
            printf("Opcao invalida.\n");
    }
}

void registrarDevolucao(Requisicao requisicoes[], int numRequisicoes){
    char usuario[50];
    int i;
    printf("Digite o nome do usuario para registrar a devolucao: ");
    scanf("%s",usuario);
    for ( i = 0; i < numRequisicoes; i++){
        if(strcmp(requisicoes[i].usuario, usuario) == 0 && strcmp(requisicoes[i].estado, "Aprovada") == 0){
            requisicoes[i].devolvido = 1;
            printf("\nDevolucao registrada com sucesso!\n");
            return;
        }
    }
    printf("Usuario nao encontrado ou requisicao nao foi aprovada.\n");
}

void listarRequisicoesPorUsuario(Requisicao requisicoes[], int numRequisicoes) {
    char usuario[50];
    printf("Introduza o nome do usuario para listar as requisicoes: ");
    scanf("%s", usuario);

    printf("\nRequisicoes de %s:\n", usuario);
    for (int i = 0; i < numRequisicoes; i++) {
        if (strcmp(requisicoes[i].usuario, usuario) == 0) {
            printf("\nEquipamento: %s",requisicoes[i].equipamento);
            printf("\nEstado: %s",requisicoes[i].estado);
            printf("\nDevolvido: %s",(requisicoes[i].devolvido) ? "Sim" : "Nao");
        }
    }
}

void listarRequisicoesAprovadas(Requisicao requisicoes[], int numRequisicoes) {
    printf("\nRequisicoes Aprovadas:");
    for (int i = 0; i < numRequisicoes; i++) {
        if (strcmp(requisicoes[i].estado, "Aprovada") == 0) {
            printf("\nUsuario: %s",requisicoes[i].usuario);
            printf("\nEquipamento: %s",requisicoes[i].equipamento);
            printf("\nDevolvido: %s",(requisicoes[i].devolvido) ? "Sim" : "Nao");
        }
    }
}

void listarRequisicoesDevolvidas(Requisicao requisicoes[], int numRequisicoes) {
    printf("\nRequisicoes Devolvidas:\n");
    for (int i = 0; i < numRequisicoes; i++) {
        if (requisicoes[i].devolvido) {
            printf("\nUsuario: %s",requisicoes[i].usuario);
            printf("\nEquipamento: %s",requisicoes[i].equipamento);
        }
    }
}

int main() {
    Requisicao requisicoes[100];
    int numRequisicoes = 0;
    int opcao,escolha;

    do {
    	printf("\n\nSistema Gestao de Requisicao e Devolucao de Equipamentos Informaticos\n");
        printf("----Menu----\n\n");
        printf("1. Adicionar Requisicao\n");
        printf("2. Listar Requisicoes\n");
        printf("3. Aprovar/Rejeitar Requisicao\n");
        printf("4. Registrar Devolucao\n");
        printf("5. Listar Requisicoes por Usuario\n");
        printf("6. Listar Requisicoes Aprovadas\n");
        printf("7. Listar Requisicoes Devolvidas\n");
        printf("8. +Info.\n");
        printf("9. Sair\n\n");

        printf("Digite a opcao que deseja: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarRequisicao(requisicoes, &numRequisicoes);
                break;
            case 2:
                listarRequisicao(requisicoes, &numRequisicoes);
                break;
            case 3:
                printf("\nDigite 1 - para rejeitar requisicao\n");
                printf("Digite 2 - para aprovar requisicao\n");
                printf("Digite a sua escolha: ");
                scanf("%d",&escolha);
                processarRequisicao(requisicoes, numRequisicoes,escolha);
                break;
            case 4:
                registrarDevolucao(requisicoes, numRequisicoes);
                break;
            case 5:
                listarRequisicoesPorUsuario(requisicoes, numRequisicoes);
                break;
            case 6:
                listarRequisicoesAprovadas(requisicoes, numRequisicoes);
                break;
            case 7:
                listarRequisicoesDevolvidas(requisicoes, numRequisicoes);
                break;
            case 8:
                printf("\nSistema de Gestao desenvolvido por:\n-ERIC REIS\n-LIEDSON DELGADO\n-TIAGO DONGO\nFoi criado em:30/01/2024\n\n");
                break;
            case 9:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("[OPCAO INVALIDA]\nTente novamente.\n\n");
        }
    } while (opcao != 9);

    return 0;
}