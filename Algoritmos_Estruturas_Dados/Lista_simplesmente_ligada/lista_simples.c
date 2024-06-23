#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"lista_simples.h"


void criar(PALUNO *head){
    *head = NULL;
}

char *newName(char *name){
    char *new_name = (char*)malloc((strlen(name)+1)*sizeof(char));
    if(new_name == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_name, name);
    return new_name;
}

void show_student(int number, char *name){
    printf("\nNumero: %d \t Nome: %s\n",number, name);
}

int itemCompare(char *name1, char *name2){
    return strcmp(name1, name2);
}

PALUNO insertStudentSorted(PALUNO head, char *name, int number){
    PALUNO novo_aluno = (PALUNO)malloc(sizeof(Aluno));
    if (novo_aluno == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    novo_aluno->numero = number;
    novo_aluno->nome = newName(name);
    novo_aluno->next = NULL;

    if (head == NULL || itemCompare(name, head->nome) < 0) {
        novo_aluno->next = head;
        return novo_aluno;
    }

    PALUNO atual = head;
    PALUNO anterior = NULL;

    while (atual->next != NULL && itemCompare(name, atual->next->nome) > 0) {
        anterior = atual;
        atual = atual->next;
    }

    anterior->next = novo_aluno;
    novo_aluno->next = atual;

    return head;
}

void show(PALUNO head){
    PALUNO atual = head;
    while (atual != NULL) {
        show_student(atual->numero, atual->nome);
        atual = atual->next;

    }
}

int searchByname(PALUNO head, char *name){
    PALUNO atual = head;
    while (atual != NULL) {
        if (itemCompare(atual->nome, name) == 0) {
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}

int searchBynumber(PALUNO head, int number){
    PALUNO atual = head;
    while (atual != NULL) {
        if (atual->numero == number) {
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}

PALUNO deleteStudent(PALUNO head, char *name) {
    PALUNO atual = head;
    PALUNO anterior = NULL;
    while (atual != NULL && itemCompare(atual->nome, name) != 0) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL){
        return head;
    }

    if (anterior == NULL) {
        head = atual->next;
    }

    else {
        anterior->next = atual->next;
    }

    free(atual->nome);
    free(atual);

    return head;

}

void inserir_dados(PALUNO *head){
    char nome[100];
    int numero;

    printf("Digite o nome do aluno: ");
    scanf("%s", nome);
    printf("Digite o numero do aluno: ");
    scanf("%d", &numero);
    printf("\n");

    *head = insertStudentSorted(*head, nome, numero);
}
