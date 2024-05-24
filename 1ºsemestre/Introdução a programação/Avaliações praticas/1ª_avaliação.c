#include<stdio.h>

void classificacao(int mat, int prog, int sist_digitais){
    if(mat>=10 && prog>=10 && sist_digitais>=10){
        printf("Voce foi aprovado!\n");
    }
    else if(mat>=16 && prog>=16 && sist_digitais>=16){
        printf("Voce foi aprovado com disticao!\n");
    }
    else if(mat<10 && prog<10 && sist_digitais<10){
        printf("Voce foi reprovado !\n");
    }
    else if(mat<10 && prog<10 && sist_digitais>=10){
        printf("Voce foi reprovado em matematica e programacao!\n");  
    }
    else if(mat<10 && prog>=10 && sist_digitais<10){
        printf("Voce foi reprovado em matematica e sistemas digitais!\n");
    }
    else if(mat>=10 && prog<10 && sist_digitais<10){
        printf("Voce reprovou em programacao e sistemas digitais");
    }
}

int main(){
    int mat,prog,sd;
    printf("\nDigite a nota que obtiveste em matematica: ");
    scanf("%d",&mat);
    printf("\nDigite a nota que obtiveste em programacao: ");
    scanf("%d",&prog);
    printf("\nDigite a nota que obtiveste em sistemas digitais: ");
    scanf("%d",&sd);
    
    classificacao(mat, prog, sd);

    return 0;
}