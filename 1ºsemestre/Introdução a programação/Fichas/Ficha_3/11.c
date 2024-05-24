/*programa que le um número inteiro e verifique se é uma capicua*/
#include<stdio.h>
int main(){
    int n, ncpia, inverso=0, dgito;
    printf("num: ");
    scanf("%d",&n);
    ncpia=n;
    while (ncpia!=0){
        dgito%=ncpia;
        inverso=inverso*10+dgito;
        ncpia/=10;
    }
    if (n==inverso){
        printf("\nCapicua");
    }
    else{
        printf("\nNao Capicua");
    }
    return 0;
}