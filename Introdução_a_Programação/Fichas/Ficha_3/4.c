#include<stdio.h>

int main(){
    int cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,cont6=0;
    int i, j, quantidade;

    printf("Digite a quantidade de numeros a serem lidos: ");
    scanf("%d",&quantidade);

    for ( i = 0; i < quantidade; i++){
        printf("Introduza um numero: ");
        scanf("%d",&j);

        if(j<=0){
            cont1++;
        }
        else if(j>0 && j<=25){
            cont2++;
        }
        else if(j>25 && j<=50){
            cont3++;
        }
        else if(j>50 && j<=75){
            cont4++;
        }
        else if(j>75 && j<=100){
            cont5++;
        }
        else{
            cont6++;
        }
    }
    printf("A quantidade de numeros nos intervalos e:\n");
    printf("]-inf , 0], %d\n",cont1);
    printf("[0 , 25], %d\n",cont2);
    printf("[25 , 50], %d\n",cont3);
    printf("[50 , 75], %d\n",cont4);
    printf("[75 , 100], %d\n",cont5);
    printf("[100 , +inf], %d\n",cont6);

    return 0;
}