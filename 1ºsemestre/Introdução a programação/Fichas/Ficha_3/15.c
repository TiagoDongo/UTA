#include<stdio.h>
int main(){
    int n, i=1, j;

    do{
        printf("digite um numero inteiro: ");
        scanf("%d",&n);
    }
    while (n<=2);

    for( i = 1; i < n; i++ ){
        for ( j = i; j <= i+n-1; j++){
            printf("%d \t",j);
        }
        printf("\n");
    }

    return 0;
}