#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct aluno{
    char * nome;
    int numero;
    struct aluno *next;
}Aluno;

typedef Aluno *PALUNO;

// Declarações das funções
void criar(PALUNO *head);
char *newName(char *name);
void show_student(int number, char *name);
int itemCompare(char *name1, char *name2);
PALUNO insertStudentSorted(PALUNO head, char *name, int number);
void show(PALUNO head);
int searchByname(PALUNO head, char *name);
int searchBynumber(PALUNO head, int number);
PALUNO deleteStudent(PALUNO head, char *name);

//funçãoo para innserir os dados do aluno
void inserir_dados(PALUNO *head);



#endif // LISTA_SIMPLES_H
