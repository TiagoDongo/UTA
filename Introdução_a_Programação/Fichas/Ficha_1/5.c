//Elabore um algoritmo que calcule a hipotenusa de um triângulo retângulo, conhecendo as medidas dos seus catetos.
#include<stdio.h>
#include<math.h>
void main(){
int cat_a,cat_o,hip;
 printf("\nqual e o valor do cateto adjacente: ");
 scanf("%d",&cat_a);
 printf("\nqual e o valor do cateto oposto: ");
 scanf("%d",&cat_o);
 hip=sqrt(cat_a*cat_a+cat_o*cat_o);//funcao sqrt calcula a raiz quadrada
 printf("a hipotenusa e de: %d",hip);
}
