/**/
#include<stdio.h>
int main(){
    int idade, FCR, x;

    printf("Introduza a idade: ");
    scanf("%d",&idade);

    printf("\nSua frequencia cardiaca em repouso: ");
    scanf("%d",&FCR);

    for(x=55 ; x<=95 ; x+=5){
        int FCM = (((220.0 - idade)-FCR)*(x/00.0))+FCR;
        printf("\n%d%% \t\t %d",x,FCM);
    }
    return 0;
}