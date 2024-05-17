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

void selection(Item a[], int l, int r)
{
  int i, j, min;
  for (i = l; i < r; i++) {
    min = i;
    for (j = i+1; j <= r; j++)
      if (less(a[j], a[min]))
        min = j;
    exch(a[i], a[min]);
  }
}