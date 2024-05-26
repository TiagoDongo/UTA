#include<stdio.h>

int potencia(int x, int n){
    if(n == 0){
        return 1;
    }
    else if (n > 0){
        return x * potencia(x, n - 1);
    }
    else{
        return x / potencia(x, n + 1);
    }
}

int main(){
    int x,n;

    printf("Digite o valor da base da potencia: ");
    scanf("%d",&x);

    printf("Digite o valor do expoente da potencia: ");
    scanf("%d",&n);

    printf("O valor da potencia e: %d",potencia(x, n));

    return 0;
}