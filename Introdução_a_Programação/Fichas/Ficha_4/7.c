#include<stdio.h>

void quadrado(int N){
    int i,j;
    if (N < 2){
        printf("O valor de N deve ser maior ou igual a 2.\n");
        return;
    }
    
    for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            if ((i+j) % 2 == 0){
                printf("X ");
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    
}

int main(){
    int N;

    printf("Digite um valor para N (>=2): ");
    scanf("%d",&N);

    quadrado(N);

    return 0;
}