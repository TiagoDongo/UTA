/*programa que lê diversos caracteres do teclado e escreve-os no ecrã mas convertendo todas as letras minúsculas para maiúsculas. A leitura termina ao fim de uma linha (isto é, quando o utilizador premir a tecla <ENTER>).*/
#include<stdio.h>
#include<ctype.h>

int main(){
    char c, maiuscula;

    printf("Introduza caracteres e prima ENTER: ");
    
    while((c=getchar())!='\n'){
        if(c >= 'a' && c <= 'z'){
            maiuscula=toupper(c);
        }
        putchar(maiuscula);
    }
    return 0;
}