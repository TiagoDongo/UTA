#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

#define N 100
#define maxN 1000
#define M 1000
#define QM 10

void ler_vetor(Item v[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n\n");
}

void selection(Item a[], int l, int r) {
    int i, j, min;
    for (i = l; i < r; i++) {
        min = i;
        for (j = i + 1; j <= r; j++)
            if (less(a[j], a[min]))
                min = j;
        exch(a[i], a[min]);
    }
}

void insertion(Item a[], int l, int r) {
    int i;
    for (i = l + 1; i <= r; i++)
        compexch(a[l], a[i]);
    for (i = l + 2; i <= r; i++) {
        int j = i;
        Item v = a[i];
        while (less(v, a[j - 1])) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
    }
}

void bubble(Item a[], int l, int r) {
    int i, j, done;
    for (i = l; i < r; i++) {
        done = 1;
        for (j = r; j > i; j--)
            if (less(a[j], a[j - 1])) {
                exch(a[j - 1], a[j]);
                done = 0;
            }
        if (done) break;
    }
}

int partitionn(Item a[], int l, int r) {
    int i = l - 1;
    int j = r;
    Item v = a[r];
    while (i < j) {
        while (less(a[++i], v));
        while (less(v, a[--j]))
            if (j == l)
                break;
        if (i < j)
            exch(a[i], a[j]);
    }
    exch(a[i], a[r]);
    return i;
}

void quicksort(Item a[], int l, int r) {
    int i;
    if (r <= l)
        return;
    i = partitionn(a, l, r);
    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);
}

void quicksortM(Item a[], int l, int r) {
    int i;
    if (r - l <= QM) {
        insertion(a, l, r);
        return;
    }
    i = partitionn(a, l, r);
    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);
}

Item aux[maxN];

void mergee(Item a[], int l, int m, int r) {
    int i, j, k;
    for (i = m + 1; i > l; i--)
        aux[i - 1] = a[i - 1];
    for (j = m; j < r; j++)
        aux[r + m - j] = a[j + 1];
    for (k = l; k <= r; k++)
        if (less(aux[j], aux[i]))
            a[k] = aux[j--];
        else
            a[k] = aux[i++];
}

void mergesort(Item a[], int l, int r) {
    int m = (r + l) / 2;
    if (r <= l)
        return;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    mergee(a, l, m, r);
}

void FixHeap(Item a[], int n, int pos) {
    int temp, son;
    if (n <= 1)
        return;
    temp = a[pos];
    for (; pos * 2 + 1 < n; pos = son) {
        son = 2 * pos + 1;
        if (son < n - 1 && a[son] < a[son + 1])
            son++;
        if (a[son] > temp)
            a[pos] = a[son];
        else
            break;
    }
    a[pos] = temp;
}

void buildheap(Item a[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        FixHeap(a, n, i);
}

void heapsort(Item a[], int n) {
    int i = n - 1;
    buildheap(a, n);
    while (i > 0) {
        exch(a[i], a[0]);
        FixHeap(a, i, 0);
        i--;
    }
}

int main() {
    Item v[N];
    char opcao_n;

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        v[i] = 1 + rand() % 100;
    }

    do {

        printf("\n\n-------MENU-------\n");
        printf(" 's' para Selectionsort\n");
        printf(" 'i' para Insertionsort\n");
        printf(" 'b' para Bubblesort\n");
        printf(" 'q' para Quicksort\n");
        printf(" 'm' para Mergesort\n");
        printf(" 'h' para Heapsort\n");
        printf(" 'x' para Sair\n\n");

        printf("Introduza a opção que deseja: ");
        scanf(" %c", &opcao_n);

        printf("\n\nTabela antes da ordenação: \n");
        ler_vetor(v, N);

        switch (opcao_n) {
            case 's':
                selection(v, 0, N - 1);
                printf("\nTabela depois do SELECTION:\n");
                ler_vetor(v, N);
                break;

            case 'i':
                insertion(v, 0, N - 1);
                printf("\nTabela depois do INSERTION:\n");
                ler_vetor(v, N);
                break;

            case 'b':
                bubble(v, 0, N - 1);
                printf("\nTabela depois do BUBBLE:\n");
                ler_vetor(v, N);
                break;

            case 'q':
                quicksortM(v, 0, N - 1);
                printf("\nTabela depois do QUICKSORT:\n");
                ler_vetor(v, N);
                break;

            case 'm':
                mergesort(v, 0, N - 1);
                printf("\nTabela depois do MERGE:\n");
                ler_vetor(v, N);
                break;

            case 'h':
                heapsort(v, N);
                printf("\nTabela depois do HEAPSORT:\n");
                ler_vetor(v, N);
                break;

            case 'x':
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida\n");
                break;
        }

    } while (opcao_n != 'x');

    return 0;
}
