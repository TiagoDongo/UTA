#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define N 100

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

void ler_vetor(Item a[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}

void bubble(Item a[], int l, int r) {
    for (int i = l; i < r; i++) {
        int done = 1;
        for (int j = r; j > i; j--) {
            if (less(a[j], a[j - 1])) {
                exch(a[j - 1], a[j]);
                done = 0;
            }
        }
        if (done) break;
    }
}

int pes_linear(Item a[], int tam, int valor) {
    for (int i = 0; i < tam; i++) {
        if (a[i] == valor)
            return i;
    }
    return -1;
}

int pes_binaria(Item a[], int tam, int valor) {
    int inicio = 0;
    int fim = tam - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (valor == a[meio])
            return meio;
        else if (valor > a[meio])
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int main() {
    Item a[N];
    char opcao;
    int n;
    int sair = 0;

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        a[i] = 1 + rand() % 100;
    }

    while (!sair) {
        printf("\nTabela:\n");
        ler_vetor(a, N);

        printf("Digite 'b' para fazer uma pesquisa binaria\n");
        printf("Digite 'l' para fazer uma pesquisa linear\n");
        printf("Digite 'x' para sair\n");

        printf("\nIntroduza a opcao que deseja: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'b':
                bubble(a, 0, N - 1);
                printf("\nTabela ordenada:\n");
                ler_vetor(a, N);
                printf("\nDigite o valor que deseja procurar: ");
                scanf("%d", &n);
                printf("\n\nO valor %d se encontra na posicao %d\n", n, pes_binaria(a, N, n));
                break;
            case 'l':
                printf("\nDigite o valor que deseja procurar: ");
                scanf("%d", &n);
                printf("\n\nO valor %d se encontra na posicao %d\n", n, pes_linear(a, N, n));
                break;
            case 'x':
                sair = 1;
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }

    return 0;
}
