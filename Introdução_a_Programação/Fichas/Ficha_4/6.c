#include<stdio.h>

float imc(float peso, float altura){
    return peso/(altura * altura);
}

void escrevaCategoria(int imc){
    if (imc < 19){
        printf("Magro");
    }
    else if (imc >= 19 && imc <= 25){
        printf("Normal");
    }
    else if (imc > 25 && imc <= 30){
        printf("Excesso Peso");
    }
    else if (imc > 30 && imc <= 40){
        printf("Obeso I");
    }
    else if (imc > 40){
        printf("Obeso II");
    }
    
}

float pesoMinimo(float altura){
    return 19 * (altura * altura);
}

float pesoMaximo(float altura){
    return 25 * (altura * altura);
}

int main(){
    float peso, altura, imcc,pmin,pmax;

    printf("Qual e a sua altura: ");
    scanf("%f",&altura);

    printf("\nQual e o seu peso: ");
    scanf("%f",&peso);

    imcc = imc(peso, altura);
    pmin = pesoMinimo(altura);
    pmax = pesoMaximo(altura);

    printf("IMC: %.2f\nCategoria: ",imcc);
    escrevaCategoria(imcc);
    printf("\nPeso Minimo: %.2f \nPeso Maximo: %.2f",pmin,pmax);


    return 0;
}