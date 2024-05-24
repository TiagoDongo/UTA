/*programa que permita determinar a soma dos dígitos de um dado número inteiro positivo.*/
#include<stdio.h>
int main(){
    int n, soma=0;

    printf("Digite um numero inteiro: ");
    scanf("%d",&n);

    while(n!=0){
        soma=soma+(n%10);
        n=n/10;
    }
    printf("Soma: %d",soma);
    return 0;
}