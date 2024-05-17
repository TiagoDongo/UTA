#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#include <assert.h>
#define N 100

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

int pes_linear(Item a[],int tam,int valor){
    int i;
    for(i=0;i<tam;i++)
        if(a[i]== valor)
        return i;
    return -1;