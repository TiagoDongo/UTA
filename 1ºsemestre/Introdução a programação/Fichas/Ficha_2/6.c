//Elabore um programa que leia um par de coordenadas inteiras (x, y) e imprima uma mensagem informando em qual quadrante está o ponto.
//O algoritmo deve também ser capaz de identificar se o ponto está sobre um dos eixos ou na origem do plano cartesiano.
#include<stdio.h>
void main()
{
    int x,y;
    char casos;
    printf("\nDigite a coordenada x: ");
    scanf("%d",&x);
    printf("\nDigite a coordenada y: ");
    scanf("%d",&y);

    if(x>0 && y>0){
        printf("\nesta no primeiro quadrante\n");
    }

     else if(x<0 && y>0){
        printf("\nesta no segundo quadrante\n");
    }

     else if(x<0 && y<0){
        printf("\nesta no terceiro quadrante\n");
    }

     else if(x>0&&y<0){
        printf("\nesta no quarto quadrante\n");
    }
    else{
        printf("\nesta na origem do plano cartesiano\n");
    }
}
