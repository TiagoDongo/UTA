#include<stdio.h>

int main(){
    int n,i;

    printf("Entre com um numero ([0 , 100]): ");
    scanf("%d",&n);

    while(n<0 || n>100){
        printf("\nERRO!!!");
        printf("Entre com um numero ([0 , 100]): ");
        scanf("%d",&n);
    }

    for(i=1; i<12; i++){
        printf("%d * %d = %d",n,i,n*i);
    }

    return 0;
}