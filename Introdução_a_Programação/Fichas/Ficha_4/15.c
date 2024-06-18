#include<stdio.h>

int hanoi(int n){
    if (n < 1) {
        return -1; 
    } else if (n == 1) {
        return 1; 
    } else {
        return 2 * hanoi(n - 1) + 1; 
    }
}

int main(){
    int n;

    printf("Digite um numero: ");
    scanf("%d",&n);

    printf("O resultado do puzzle Torres de Hanoi com 3 colunas e de: %d",hanoi(n));

    return 0;
}