#include<stdio.h>

void periodo(int N){
    int horas,minutos,segundos;
    
    horas = N / 3600;
    minutos = (N % 3600)/60;
    segundos = (N % 3600) % 60;

    printf("O periodo de tempo e: %02dh : %02dmin : %02ds",horas,minutos,segundos);
}

int main(){
    int tseg;

    printf("Digite o valor tempo em segundos: ");
    scanf("%d",&tseg);

    periodo(tseg);

    return 0;
}