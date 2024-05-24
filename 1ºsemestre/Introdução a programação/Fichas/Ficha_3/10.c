/*programa que permite calcular o maior divisor comum de dois números inteiros positivos,*/
#include<stdio.h>
int main(){
    int a,b,r;

    printf("Introduza um primeiro numero: ");
    scanf("%d",&a);

    printf("\n\nIntroduza um segundo numero: ");
    scanf("%d",&b);

    while (b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    printf("O maximo divisor comum e: %d",a);

    return 0;
}
