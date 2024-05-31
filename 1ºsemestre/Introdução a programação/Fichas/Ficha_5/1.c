#include<stdio.h>
#define N 5

void lerVetor(int v[], int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        printf("%d num: ",i+1);
        scanf("%d",&v[i]);
    }
}

void escreveVetor(int v[], int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        printf("%d\t",v[i]);
    }
}

int main(){
    int v[N];

    lerVetor(v,N);

    escreveVetor(v,N);

    return 0;
}