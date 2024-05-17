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


/*OBS: Na pesquisa binaria é obigatoria que os elementos do vetor estejam ordenados, por isso deve-se usar qualquer um dos de ordenação primeiro e so depois fazer a pesquisa binaria */

int pes_binaria(Item a[],int tam, int valor){
    int inicio=0;
    int fim = tam-1;
    while(inicio<=fim){
        int meio = (inicio+fim)/2;
        if(valor==a[meio])
            return meio;
        else{
            if(valor>a[meio])
                inicio=meio+1;
            else
                fim=meio-1;
        }
    }
    return -1;
}