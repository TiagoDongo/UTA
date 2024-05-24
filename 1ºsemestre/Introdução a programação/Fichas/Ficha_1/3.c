//Elabore um algoritmo que converta uma quantia de euros em escudos. O algoritmo deverá solicitar
//o valor da cotação do euro e também a quantidade de euros disponíveis com o utilizador.
#include<stdio.h>
void main()
{
    int coteuro,euros_disponiveis,quant_euro,esc,troco;
    printf("\nqual e a cotacao do euro: ");
    scanf("%d",&coteuro);

    printf("\nqual e a quantidade de euros que tem disponivel: ");
    scanf("%d",&euros_disponiveis);

    printf("\nqual e a quantidade de euros que deseja comverter em escudos: ");
    scanf("%d",&quant_euro);

    esc=coteuro*quant_euro;
    troco=euros_disponiveis-quant_euro;
    printf("\no valor de %d euros comvertidos para escudos e de:%d esc",quant_euro,esc);
    printf(" e dispoe ainda de %d euros na sua conta\n\n",troco);
}
