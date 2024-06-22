#ifndef FICHA_2_H
#define FICHA_2_H

typedef struct {
    float real;
    float imaginario;
}Complexo;


typedef struct{
    char titulo[100];
    int duracao;
    int disponivel;
}DVD;

typedef struct {
int num_aluno;
char* cod_disc;
} Inscricao;

//1
void hm(int t, int *h, int *m);

//2
void mm(int v[], int n, int *mx, int *mn);

//3
void inversa(int n);

//4
float **alocar(int a,int s);
void ler_info(float **v,int a,int s);
void mostrar_info(float **v, int a, int s);
void media_colunas(float **v, int a, int s);
void minimo_linhas(float **v, int a, int s);
void freetabela(float **v,int a);

//5
Complexo ler_numComplexo();

//6
Complexo soma(Complexo a, Complexo b);

//8
void preencherDVD(DVD v[], int n);
void mostrarinfo(DVD v[], int n);

//9
int strlen_indice(const char *str);
int strlen_ponteiro(const char *str);

//10
void soma_modifica(Complexo *a, Complexo b);

//11
Complexo* soma_retorna_ponteiro(Complexo a, Complexo b);

//12
Inscricao *lerInscricoes(int n);

#endif