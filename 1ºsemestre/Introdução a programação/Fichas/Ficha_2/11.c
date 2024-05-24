//O índice de massa corporal (IMC) é uma medida usada para avaliar se uma pessoa
//tem o peso ideal para a sua estatura. Elabore um programa que determina o IMC
//do utilizador e classifica-o quanto às quatro categorias apresentadas na tabela abaixo:
//IMC: <18.5 [18.5, 25[ [25, 30[ 30 ou mais
//Categoria: Magro Saudável Forte Obeso
#include<stdio.h>
void main()
{
    float i;
    printf("Digite o seu indice de massa corporal: ");
    scanf("%f",&i);

    if(i<18.5){
        printf("\nmagro\n");
    }
    else if(i>18.5 && i<25){
        printf("\nsaudavel\n");
    }
    else if(i>25 && i<30){
        printf("\nforte\n");
    }
    else if(i>=30){
        printf("\nobeso\n");
    }
}
