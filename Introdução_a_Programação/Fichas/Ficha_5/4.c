#include<stdio.h>
#define N 3

int procura(int v[], int tamanho, int k){
    int i;
    for ( i = 0; i < tamanho; i++){
        if(k == v[i]){
            return i;
        }
    }
    return -1;
}

void ler_vetor(int v[], int tamanho){
    int i;

    for ( i = 0; i < tamanho; i++){
        printf("%d numero: ",i+1);
        scanf("%d",&v[i]);
    }
}

int main(){
    int k, v[N];

    ler_vetor(v,N);

    printf("\nDigite o numero que deseja procurar: ");
    scanf("%d",&k);

    printf("\n%d",procura(v,N,k));

    return 0;
}