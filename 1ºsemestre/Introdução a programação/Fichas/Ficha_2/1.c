//Escreva um programa que pergunte ao utilizador a sua idade e compare com a idade legal de condu��o de dezoito anos.
//Se o utilizador tiver dezoito anos ou mais, ent�o o programa deve mostrar "Tem idade suficiente para conduzir legalmente".
//Se o utilizador tiver menos de dezoito anos, o programa deve mostrar "N�o tem idade suficiente para conduzir legalmente".
#include<stdio.h>
void main(){
int i;
printf("qual e sua idade? ");
scanf("%d",&i);
if(i<18){
    printf("Nao tem idade suficiente para conduzir legalmente");
}
if(i>=18){
    printf("Tem idade suficiente para conduzir legalmente\n\n");
}
}
