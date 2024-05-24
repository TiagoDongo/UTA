//A biblioteca do ISECMAR empresta gratuitamente seus livros a alunos, professores e funcionários de toda a instituição.
//Porém, sempre que um utilizador atrasa a entrega de um livro, ele tem que pagar uma multa de 250 Esc. por cada dia de atraso.
//Elabore um algoritmo que receba como entrada a quantidade de dias de atraso do empréstimo de um livro, e mostra o valor da multa
//a ser paga pelo utilizador.
#include<stdio.h>
void main(){
int multa,dia_atraso;
 printf("\nInsira a quantidade de dias de atraso: ");
 scanf("%d",&dia_atraso);
 multa=250*dia_atraso;
 printf("\nO valor da multa a ser paga e de: %d esc",multa);
}
