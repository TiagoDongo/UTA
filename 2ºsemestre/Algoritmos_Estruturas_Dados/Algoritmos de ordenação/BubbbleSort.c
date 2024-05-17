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

void bubble(Item a[], int l, int r)
{
  int i, j, done;
  for (i = l; i < r; i++){
    done=1;
    for (j = r; j > i; j--)
      if (less(a[j], a[j-1])){
        exch(a[j-1], a[j]);
        done=0;
      }
    if (done) break;
  }
}