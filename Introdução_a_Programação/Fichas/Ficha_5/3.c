#include<stdio.h>
#define N 8

int posicaoMaxima(int v[], int tamanho){
    int max = v[0];
    int posicaoMax = 0;
    for (int i = 0; i < tamanho; i++){
        if(v[i] > max){
            max = v[i];
            posicaoMax = i;
        }
    }
    return posicaoMax;
}

int posicaoMinima(int v[], int tamanho){
    int min = v[0];
    int posicaoMin = 0;
    for (int i = 0; i < tamanho; i++){
        if(v[i] < min){
            min = v[i];
            posicaoMin = i;
        }
    }
    return posicaoMin;
}

void escrevevetor(int v[], int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        printf("\nPosicao %d: %d\n",i,v[i]);
    }
}

void ler_vetor(int v[], int tamanho){
    int i;

    for ( i = 0; i < tamanho; i++){
        printf("%d numero: ",i+1);
        scanf("%d",&v[i]);
    }
}

int main(){
    int v[N], max, min;

    ler_vetor(v, N);
    escrevevetor(v, N);

    printf("\n");
    
    max = posicaoMaxima(v, N);
    min = posicaoMinima(v, N);

    printf("Posicao do maximo: %d\n",max);
    printf("Posicao do minimo: %d\n",min);

    return 0;
}