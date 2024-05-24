//Elabore um algoritmo que converta uma quantia de dólares americanos em escudos cabo-verdianos.
#include<stdio.h>
void main()
{
    int cot_dollar,dolares_disponiveis,quant_dollar,esc,troco;
    printf("\nqual e a cotacao do dollar: ");
    scanf("%d",&cot_dollar);

    printf("\nqual e a quantidade de dolares que tem disponivel: ");
    scanf("%d",&dolares_disponiveis);

    printf("\nqual e a quantidade de dolares que deseja comverter em escudos: ");
    scanf("%d",&quant_dollar);

    esc=cot_dollar*quant_dollar;
    troco=dolares_disponiveis-quant_dollar;
    printf("\no valor de %d dolares comvertidos para escudos e de:%d esc",quant_dollar,esc);
    printf(" e dispoe ainda de %d dolares na sua conta\n\n",troco);
}
