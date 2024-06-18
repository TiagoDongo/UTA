#include<stdio.h>

float N_media(int N){
    int i;
    float media = 0,n;

    for ( i = 1; i <= N; i++){
        printf("Digite o %d numero: ",i);
        scanf("%f",&n);
        media += n;
    }

    return media/N;
}

int main(){
    int N;
    float resultado;

    printf("Digite a quantidade de numeros que deseja calcular a media: ");
    scanf("%d",&N);

    resultado = N_media(N);

    printf("\nO resultado da media e: %.2f",resultado);

    return 0;
}