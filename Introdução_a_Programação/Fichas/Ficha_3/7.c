/*programa que produz uma tabela com temperaturas em graus centígrados, equivalentes às temperaturas em graus Farenheit /entre -40º F e 120º F.*/
#include<stdio.h>

int main(){
    int f;
    float c;

    printf("Fahrenheit \t celcios:\n");

    for(f=-40;f<=120;f++){
        c=(5.0/9.0)*(f - 32);
        printf("%d \t \t %.2f\n",f,c);
    }

    return 0;
}