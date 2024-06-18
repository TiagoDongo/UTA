#include<stdio.h>
#define N 5

int somaVetor(int v[], int tamanho){
    int soma = 0, i;

    for ( i = 0; i < tamanho; i++){
        soma += v[i];
    }
    return soma;
}

void ler_vetor(int v[], int tamanho){
    int i;

    for ( i = 0; i < tamanho; i++){
        printf("%d numero: ",i+1);
        scanf("%d",&v[i]);
    }
}

int main(){
    int v[N], resultado;
    
    ler_vetor(v, N);

    resultado = somaVetor(v,N);

    printf("A soma dos elementos do vetor e: %d",resultado);

    return 0;
}