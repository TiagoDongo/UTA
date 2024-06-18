#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>



typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

#define N 20
#define maxN 1000
#define M 1000

void insertion(Item a[], int l, int r)
{
  int i;

  /* Coloca menor elemento na primeira posicao */
  for (i = l+1; i <= r; i++)
    compexch(a[l], a[i]);

  for (i = l+2; i <= r; i++) {
    int j = i;

    /* Variavel auxiliar para guardar o valor a[i] */
    Item v = a[i];

    /* Enquanto v < a[j] puxar os valores para a direita */
    /* Como o primeiro elemento e' o menor podemos omitir a condicao j>=l */
    while (less(v, a[j-1])) {
      a[j] = a[j-1];
      j--;
    }

    /* Guardar o valor originalmente na posicao i na posicao libertada */
    a[j] = v;
  }
}