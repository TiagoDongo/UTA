/*programa que peça ao utilizador uma sequência de números reais. O programa termina quando o utilizador introduzir o número zero. Nessa altura, o programa deve mostrar o valor máximo, o valor mínimo e a média dos números introduzidos.*/
#include<stdio.h>
int main(){
    int n, cont=-1, m=0,M=0,soma=0;

    printf("Insira numeros inteiros: ");
    scanf("%d",&n);

    m=n;
    M=n;
    soma+=n;
    cont++;

    do{
        scanf("%d",&n);
        cont++;
        if(n>M && n!=0){
            M=n;
        }
        else if (n<m){
            m=n;
        }
        soma+=n;
    }
    while (n!=0);

    printf("media = %d \t",soma/cont);
        printf("max: %d \t min: %d",M,m);

    return 0;
}