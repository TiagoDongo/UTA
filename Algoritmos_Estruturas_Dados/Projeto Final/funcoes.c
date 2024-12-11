#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// ################# OP��O-1 ##################### //

//fun��o para adicionar uma nova musica na playlist
void adicionarMusica(Musica **playlist){
    //aloca espa�o para uma nova musica
    Musica *novaMusica = (Musica *)malloc(sizeof(Musica));
    printf(" T�tulo: ");
    scanf(" %[^\n]", novaMusica->titulo);        // L� uma linha inteira incluindo espa�os
    printf(" Artista: ");
    scanf(" %[^\n]", novaMusica->artista);       // L� uma linha inteira incluindo espa�os
    printf(" Dura��o (segundos): ");
    scanf("%d", &novaMusica->duracao);
    printf(" Ano: ");
    scanf("%d", &novaMusica->ano);
    novaMusica->proxima = NULL;

    if (*playlist == NULL) {
        //se a playlist estiver vazia, insere a nova musica no inicio
        *playlist = novaMusica;
    } else {
        //caso contrario, insere a nova musica no final da playlist
        Musica *temp = *playlist;
        while (temp->proxima != NULL) {
            temp = temp->proxima;
        }
        temp->proxima = novaMusica;
    }
    printf("\n M�sica adicionada na PlayList!\n\n");
}


// ################# OP��O-2 ##################### //
//Fun��o para remover uma musica da playlist
void removerMusica(Musica **playlist) {
    char titulo[100];
    printf(" T�tulo da m�sica a remover: ");
    scanf(" %[^\n]", titulo);//l� o titulo da musica a ser removido

    Musica *temp = *playlist, *prev = NULL;

    //verifica se a musica a ser removida esta no inicio da playlist
    if (temp != NULL && strcmp(temp->titulo, titulo) == 0) {
        *playlist = temp->proxima; //atualiza o ponteiro da playlist
        free(temp); //liberta a memoria da musica removida
        printf(" M�sica removida da PlayList!\n");
        return;
    }

    //procura a musica a ser removida na playlist
    while (temp != NULL && strcmp(temp->titulo, titulo) != 0) {
        prev = temp; //atualiza o ponteiro anterior
        temp = temp->proxima; //avan�a para o proximo n�
    }

    //se a musica n�o for encontrada
    if (temp == NULL) {
        printf(" M�sica n�o encontrada!\n");
        return;
    }

    //remove a musica da playlist
    prev->proxima = temp->proxima;
    free(temp);//liberta a memoria da musica removida
    printf(" M�sica removida!\n");
}


// ################# OP��O-3 ##################### //

//fun��o para reproduzir a playlist
void reproduzirPlaylist(Musica *playlist, int ordem) {
    if (playlist == NULL) {
        printf(" Playlist vazia!\n");
        return;
    }

    if (ordem == 1) { //reprodu��o da playlist em ordem crescente
        Musica *temp = playlist; //ponteiro para o inicio da playlist
        while (temp != NULL) {
            printf(" T�tulo: %s, Artista: %s, Dura��o: %d segundos, Ano: %d\n",
                   temp->titulo, temp->artista, temp->duracao, temp->ano);
            temp = temp->proxima;//avan�a para a proxima musica
        }
    } else if (ordem == 2) {// Reproduzir em ordem decrescente
        // usamos recurs�o para imprimir em ordem inversa
        if (playlist->proxima != NULL) {
            reproduzirPlaylist(playlist->proxima, ordem);
        }
        printf(" T�tulo: %s, Artista: %s, Dura��o: %d segundos, Ano: %d\n",
               playlist->titulo, playlist->artista, playlist->duracao, playlist->ano);
    } else {
        printf(" Ordem inv�lida!\n");
    }
}


// ################# OP��O-4 ##################### //

//fun��o para procurar uma musica
void procurarMusica(Musica *playlist) {
    int opcao, ano;
    char artista[100];
    printf(" Procurar por:\n1. Artista\n2. Ano\n");
    scanf("%d", &opcao);

    if (opcao == 1) { //procura a musica atravez do nome do artista
        printf(" Nome do artista: ");
        scanf(" %[^\n]", artista); //l� o nome do artista
        Musica *temp = playlist;//ponteiro temporario para a playlist
        while (temp != NULL) {//enquato n�o chegar ao fim da playlist
            if (strcmp(temp->artista, artista) == 0) {//faz compara��o entre os nomes dos artistas na playlist com o nome digitado pelo usuario
                printf(" T�tulo: %s, Artista: %s, Dura��o: %d segundos, Ano: %d\n",
                       temp->titulo, temp->artista, temp->duracao, temp->ano);
            }
            temp = temp->proxima;//avan�a para o proximo musica
        }
    } else if (opcao == 2) {//procura a musica atravez do seu ano
        printf(" Ano: ");
        scanf("%d", &ano);//l� o ano
        Musica *temp = playlist;//ponteiro temporario para a playlist
        while (temp != NULL) {//enquato n�o chegar ao fim da lista
            if (temp->ano == ano) {//compara o ano
                printf(" T�tulo: %s, Artista: %s, Dura��o: %d segundos, Ano: %d\n",
                       temp->titulo, temp->artista, temp->duracao, temp->ano);
            }
            temp = temp->proxima;//avan�a para a proxima musica
        }
    } else {
        printf(" Op��o inv�lida!\n");
    }
}


// ################# OP��O-5 ##################### //

//fun��o para calcular a dura��o total da playlist
void duracaoPlaylist(Musica *playlist) {
    int totalMusicas = 0, totalDuracao = 0;//variaveis auxiliares
    Musica *temp = playlist;//ponteiro para o inicio da playlist
    while (temp != NULL) {//enquanto n�o chegar ao fim da playlist
        totalMusicas++;//incrementa a variavel totalMusicas
        totalDuracao += temp->duracao;//soma a dura��o da musica
        temp = temp->proxima;//avan�a para a proxima musica
    }

    //converte a dura��o total para horas, minutos e segundos
    int horas = totalDuracao / 3600;
    int minutos = (totalDuracao % 3600) / 60;
    int segundos = totalDuracao % 60;

    //exibe o numero total de musicas e a dura��o total da playlist
    printf(" N�mero total de m�sicas: %d\n", totalMusicas);//mostra o total de musicas que tem a playlist
    printf(" Tempo total de dura��o: %d horas, %d minutos, %d segundos\n", horas, minutos, segundos);//mostra o tempo total da playlist
}


// ################# OP��O-6 ##################### //

//fun��o para avan�ar na playlist
void avancarPlaylist(Musica **playlist, Musica **atual) {
    if (*atual == NULL) {
        *atual = *playlist;//come�a do inicio da playlist
    } else if ((*atual)->proxima != NULL) {
        *atual = (*atual)->proxima;//avan�a para a proxima musica
    } else {
        printf(" J� est� na �ltima m�sica da playlist!\n");
    }

    if (*atual != NULL) {
        printf(" Reproduzindo: %s - %s\n", (*atual)->titulo, (*atual)->artista);
    }
}


// ################# OP��O-7 ##################### //

//fun��o para retroceder na playlist
void retrocederPlaylist(Musica **playlist, Musica **atual) {
    if (*atual == NULL) {
        printf(" Playlist vazia ou n�o come�ou a reprodu��o!\n");
        return;
    }

    if (*atual == *playlist) {
        printf(" J� est� na primeira m�sica da playlist!\n");
        return;
    }

    Musica *temp = *playlist;
    while (temp->proxima != *atual) {
        temp = temp->proxima;//avan�a para a proxima musica
    }
    *atual = temp;//atualiza o poteiro atual

    if (*atual != NULL) {
        printf(" Reproduzindo: %s - %s\n", (*atual)->titulo, (*atual)->artista);
    }
}


// ################# OP��O-8 ##################### //

//fun��o para guardar a playlist em um arquivo
void guardarPlaylist(Musica *playlist) {
    FILE *arquivo = fopen("playlist.txt", "w");
    if (arquivo == NULL) {
        printf(" Erro ao abrir o arquivo!\n");
        return;
    }

    Musica *temp = playlist;
    while (temp != NULL) {
        //escreve os detalhes da musica no arquivo
        fprintf(arquivo, "%s\n%s\n%d\n%d\n", temp->titulo, temp->artista, temp->duracao, temp->ano);
        temp = temp->proxima;//avan�a para a proxima musica
    }
    fclose(arquivo);
    printf(" Playlist guardada com sucesso!\n");
}


// ################# OP��O-9 ##################### //

//fun��o para carregar a playlist de um arquivo
void carregarPlaylist(Musica **playlist) {
    FILE *arquivo = fopen("playlist.txt", "r");
    if (arquivo == NULL) {
        printf(" Erro ao abrir o arquivo!\n");
        return;
    }

    char titulo[100], artista[100];
    int duracao, ano;
    while (fscanf(arquivo, " %[^\n]\n%[^\n]\n%d\n%d\n", titulo, artista, &duracao, &ano) == 4) {
        //aloca espa�o para uma nova musica e preenche os detalhes
        Musica *novaMusica = (Musica *)malloc(sizeof(Musica));
        strcpy(novaMusica->titulo, titulo);
        strcpy(novaMusica->artista, artista);
        novaMusica->duracao = duracao;
        novaMusica->ano = ano;
        novaMusica->proxima = NULL;

        if (*playlist == NULL) {
            //se a playlist estiver vazia, insere a nova musica no inicio
            *playlist = novaMusica;
        } else {
             // Caso contr�rio, insere a nova m�sica no final da playlist
            Musica *temp = *playlist;
            while (temp->proxima != NULL) {
                temp = temp->proxima;
            }
            temp->proxima = novaMusica;
        }
    }
    fclose(arquivo);
    printf(" Playlist carregada com sucesso!\n");
}






