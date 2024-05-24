//Elabore um programa que solicita uma pontuação entre 0 e 20 se a pontuação estiver fora do intervalo, imprime no terminal uma mensagem de erro.
//Se a pontuação estiver entre 0 e 20, imprime uma classificação de acordo com a seguinte tabela:
//>=19-sobresaliente
//>=16-notavel
//>=13-bom
//>=10-suficiente
//<10-insuficiente
#include<stdio.h>
void main()
{
    int i;
    printf("Introduza uma pontuacao entre 0 a 20: ");
    scanf("%d",&i);

    if(i>=19 && i<=20){
        printf("\nsobresaliente\n");
    }
    else if(i>=16 && i<=20){
        printf("\nnotavel\n");
    }
     else if(i>=13 && i<=20){
        printf("\nbom\n");
    }
     else if(i>=10 && i<=20){
        printf("\nsuficiente\n");
    }
     else if(i>0&&i<10){
        printf("\ninsuficiente\n");
    }
    else if(i<0 || i>20){
        printf("\no valor inserido esta fora do intervalo\n ");
    }

}
