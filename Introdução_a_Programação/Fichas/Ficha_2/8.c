//Escreva um programa que peça a quantidade de litros de combustível de um abastecimento e determine o preço a pagar.
//Considere que o combustível custa 160$00 por litro e que abastecimentos de mais de 40 litros têm um desconto de 5%.
#include<stdio.h>
void main()
{
    float quant_litros,pagar,combustivel=160;
    printf("quantos litros de combustivel deseja: ");
    scanf("%f",&quant_litros);

    if(quant_litros<40){
        pagar=quant_litros*160;
        printf("\nO preco a pagar e de: %.3f\n",pagar);
    }
    else if(quant_litros>40){
        pagar=(quant_litros*160)*0.05;
        printf("\no total a pagar com um desconto de 5 porcento e de %.3f\n",pagar);
    }
}
