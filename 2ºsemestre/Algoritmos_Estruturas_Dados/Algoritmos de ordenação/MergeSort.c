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

void merge(Item a[], int l, int m, int r)
{
  int i, j, k;
  for (i = m+1; i > l; i--)
    aux[i-1] = a[i-1];
  for (j = m; j < r; j++)
    aux[r+m-j] = a[j+1];
  for (k = l; k <= r; k++)
    if (less(aux[j], aux[i]))
      a[k] = aux[j--];
    else
      a[k] = aux[i++];
}

void mergesort(Item a[], int l, int r) {
  int m = (r+l)/2;

  if (r <= l)
    return;

  mergesort(a, l, m);
  mergesort(a, m+1, r);
  merge(a, l, m, r);
}