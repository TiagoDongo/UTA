//Escreva um programa que:
//leia um valor real, x
//calcule e escreva o valor da função:
//f(x) = 1/x*e^x se x > 0
//f(x) = e^|x| se x ≤ 0
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define e 1
void main()
{
    float x,f;
    printf("Digite um valor para x: ");
    scanf("%f",&x);

    if(x>0){
        f=(1/x)*pow(e,x);
        printf("o valor da funcao e: %f",f);
    }
    else if(x<0){
        f=pow(e,abs(x));
        printf("o valor da funcao e: %f",f);
    }
}
