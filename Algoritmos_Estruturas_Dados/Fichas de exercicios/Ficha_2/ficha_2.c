#include<stdio.h>
#include<stdlib.h>
#include"ficha_2.h"

//1
void hm(int t, int *h, int *m){
    if(t == 0){
        printf("ERRO: tempo negativo.\n");
        return;
    }
    *h = t / 60;
    *m = t % 60;
}

//2
void mm(int v[], int n, int *mx, int *mn){
    if(n <= 0){
        printf("O vetor esta vazio: deve haver pelo menos um elemento.\n");
        return;
    }
    *mx = v[0];
    *mn = v[0];

    for (int i = 0; i < n; i++){
        if (v[i] > *mx){
            *mx = v[i];
        }
        if (v[i] < *mn){
            *mn = v[i];
        }
    }    
}

//3
void inversa(int n){
    int *num = (int*)malloc(n * sizeof(int));
    if (num == NULL){
        printf("ERRO AO ALOCAR MEMORIA.\n");
        return;
    }

    printf("Digite %d numeros inteiros:\n",n);
    for (int i = 0; i < n; i++){
        scanf("%d",&num[i]);
    }

    printf("Numero em ordem invertida:\n");
    for (int i = n - 1; i >= 0; i--){
        printf("%d",num[i]);
    }

    printf("\n");

    free(num);
    
}

//4
float **alocar(int a, int s){
    float **v;
    int i,j;
    v=(float**)malloc(a*sizeof(float*));
    if(v==NULL){
        printf("ERRO: nao foi possivel alocar espaco");
        exit(1);
    }
    for(i=0;i<a;i++){
        v[i]=(float*)malloc(s*sizeof(float));
        if(v[i]==NULL){
            for(j=0;j<i;j++){
                free(v[i]);
                printf("ERRO: nao foi possivel alocar espaco");
                exit(2);
            }
        }
    }
    return v;
}

void ler_info(float **v,int a,int s){
    int i,j;
    for(i=0;i<a;i++){
        for(j=0;j<s;j++)
        printf("\nintroduz os dados do atleta %d sessao %d: ",i+1,j+1);
        scanf("%f",&v[i][j]);

    }
}

void mostrar_info(float **v, int a, int s){
    for(int i=0;i<a;i++){
        for(int j=0;j<s;j++){
            printf("%f",v[i][j]);
        }
        printf("\n");
    }

}

void media_colunas(float **v, int a, int s){
    int st,i,j;
    float m;
    for(j=0;j<s;j++){
        st=0;
        for(i=0;i<a;i++)
            st=st+v[i][j];
        m =(float)st/a;
        printf("a media: %f",m);

    }
}

void freetabela(float **v,int a){
    int i;
    for(i=0;i<a;i++)
        free(v[i]);
    free(v);
}


//5
Complexo ler_numComplexo(){
    Complexo c;
    printf("Digite um numero complexo no formato X + Yi: ");
    scanf("%f + %fi",&c.real, &c.imaginario);
    return c;
}

//6
Complexo soma(Complexo a, Complexo b){
    Complexo resultado;
    resultado.real = a.real + b.real;
    resultado.imaginario = a.imaginario + b.imaginario;
    return resultado;
}

//8
void preencherDVD(DVD v[], int n){
    for (int i = 0; i < n; i++){
        printf("Digite o titulo do DVD %d: ", i+1);
        scanf("%[^\n]",v[i].titulo);
        printf("Digite a duracao(em minuutos) do DVD %d: ", i+1);
        scanf("%d",&v[i].duracao);
        printf("O DVD %d esta disponivel para aluguer?(1 -> sim; 0 -> nao): ", i+1);
        scanf("%d",&v[i].disponivel);
    }
}

void mostrarinfo(DVD v[], int n){
    int indice_curto = 0;
    int indice_longo = 0;

    printf("\nFilmes disponíveis para aluguer:\n");
    for (int i = 0; i < n; i++) {
        if (v[i].disponivel) {
            printf("%s\n", v[i].titulo);
        }

        if (v[i].duracao < v[indice_curto].duracao) {
            indice_curto = i;
        }
        if (v[i].duracao > v[indice_longo].duracao) {
            indice_longo = i;
        }
    }

    printf("\nO título do filme mais curto: %s\n", v
    [indice_curto].titulo);
    printf("A duração do filme mais longo: %d minutos\n", v[indice_curto].duracao);
    printf("\nTodos os DVDs:\n");
    for (int i = 0; i < n; i++) {
        printf("Título: %s, Duração: %d, Disponível: %s\n", v[i].titulo, v[i].duracao, v[i].disponivel ? "Sim" : "Não");
    }
}


//9
int strlen_indice(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int strlen_ponteiro(const char *str) {
    const char *ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

//10
void soma_modifica(Complexo *a, Complexo b) {
    a->real += b.real;
    a->imaginario += b.imaginario;
}

//11
Complexo* soma_retorna_ponteiro(Complexo a, Complexo b) {
    Complexo *resultado = (Complexo *)malloc(sizeof(Complexo));
    if (resultado != NULL) {
        resultado->real = a.real + b.real;
        resultado->imaginario = a.imaginario + b.imaginario;
    }
    return resultado;
}

//12
Inscricao* lerInscricoes(int n) {
    // Alocar memória para n inscrições
    Inscricao* inscricoes = (Inscricao*)malloc(n * sizeof(Inscricao));
    if (inscricoes == NULL) {
        printf("Erro ao alocar memória para inscrições.\n");
        exit(1);
    }

    // Ler cada inscrição
    for (int i = 0; i < n; i++) {
        inscricoes[i].cod_disc = (char*)malloc(11 * sizeof(char)); // Alocar memória para o código da disciplina
        if (inscricoes[i].cod_disc == NULL) {
            printf("Erro ao alocar memória para o código da disciplina.\n");
            exit(1);
        }

        printf("Digite o número do aluno %d: ", i + 1);
        scanf("%d", &inscricoes[i].num_aluno);
        printf("Digite o código da disciplina do aluno %d: ", i + 1);
        scanf("%s", inscricoes[i].cod_disc);
    }

    return inscricoes;
}