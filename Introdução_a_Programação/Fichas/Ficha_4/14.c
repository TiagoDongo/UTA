#include<stdio.h>

int fibonacci(int n){
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else if (n > 1){
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    
}


int main(){
    int n;

    printf("Digite um numero inteiro positico: ");
    scanf("%d",&n);

    printf("O numero de Fibonacci associado a %d e: %d",n,fibonacci(n));

    return 0;
}