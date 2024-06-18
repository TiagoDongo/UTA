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


int partition(Item a[], int l, int r) {
  int i = l-1;
  int j = r;

  /* a[r] 'e o pivot. */
  Item v = a[r];

  /* Enquanto o iterador da esquerda for menor que o iterador da direita. */
  while (i < j) {

    /* Enquanto a[i]<v avanca com o i para a direita. */
    while (less(a[++i], v));

    /* Enquanto v<a[j] avanca com o j para a esquerda. */
    while (less(v, a[--j]))
      if (j == l) /* O elemento onde se faz a particao pode ser o primeiro! */
        break;

    /* Trocar, se for o caso! */
    if (i < j)
      exch(a[i], a[j]);
  }

  /* Colocar o pivot na posicao i. */
  exch(a[i], a[r]);

  /* Retorna posicao onde ocorreu a particao. */
  return i;
}

void quicksort(Item a[], int l, int r)
{
  int i;

  if (r <= l)
    return;

  i = partition(a, l, r);
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);
}


#define QM 10

void quicksortM(Item a[], int l, int r)
{
  int i;

  if(r-l <= QM) {
    insertion(a, l, r);
    return;
  }

  i = partition(a, l, r);
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);
}