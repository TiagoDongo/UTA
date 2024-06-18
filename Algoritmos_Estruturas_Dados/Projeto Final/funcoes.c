#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// ################# OPÇÃO-1 ##################### //

//função para adicionar uma nova musica na playlist
void adicionarMusica(Musica **playlist){
    //aloca espaço para uma nova musica
    Musica *novaMusica = (Musica *)malloc(sizeof(Musica));
    printf(" Título: ");
    scanf(" %[^\n]", novaMusica->titulo);        // Lê uma linha inteira incluindo espaços
    printf(" Artista: ");
    scanf(" %[^\n]", novaMusica->artista);       // Lê uma linha inteira incluindo espaços
    printf(" Duração (segundos): ");
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
    printf("\n Música adicionada na PlayList!\n\n");
}


// ################# OPÇÃO-2 ##################### //
//Função para remover uma musica da playlist
void removerMusica(Musica **playlist) {
    char titulo[100];
    printf(" Título da música a remover: ");
    scanf(" %[^\n]", titulo);//lê o titulo da musica a ser removido

    Musica *temp = *playlist, *prev = NULL;

    //verifica se a musica a ser removida esta no inicio da playlist
    if (temp != NULL && strcmp(temp->titulo, titulo) == 0) {
        *playlist = temp->proxima; //atualiza o ponteiro da playlist
        free(temp); //liberta a memoria da musica removida
        printf(" Música removida da PlayList!\n");
        return;
    }

    //procura a musica a ser removida na playlist
    while (temp != NULL && strcmp(temp->titulo, titulo) != 0) {
        prev = temp; //atualiza o ponteiro anterior
        temp = temp->proxima; //avança para o proximo nó
    }

    //se a musica não for encontrada
    if (temp == NULL) {
        printf(" Música não encontrada!\n");
        return;
    }

    //remove a musica da playlist
    prev->proxima = temp->proxima;
    free(temp);//liberta a memoria da musica removida
    printf(" Música removida!\n");
}


// ################# OPÇÃO-3 ##################### //

//função para reproduzir a playlist
void reproduzirPlaylist(Musica *playlist, int ordem) {
    if (playlist == NULL) {
        printf(" Playlist vazia!\n");
        return;
    }

    if (ordem == 1) { //reprodução da playlist em ordem crescente
        Musica *temp = playlist; //ponteiro para o inicio da playlist
        while (temp != NULL) {
            printf(" Título: %s, Artista: %s, Duração: %d segundos, Ano: %d\n",
                   temp->titulo, temp->artista, temp->duracao, temp->ano);
            temp = temp->proxima;//avança para a proxima musica
        }
    } else if (ordem == 2) {// Reproduzir em ordem decrescente
        // usamos recursão para imprimir em ordem inversa
        if (playlist->proxima != NULL) {
            reproduzirPlaylist(playlist->proxima, ordem);
        }
        printf(" Título: %s, Artista: %s, Duração: %d segundos, Ano: %d\n",
               playlist->titulo, playlist->artista, playlist->duracao, playlist->ano);
    } else {
        printf(" Ordem inválida!\n");
    }
}


// ################# OPÇÃO-4 ##################### //

//função para procurar uma musica
void procurarMusica(Musica *playlist) {
    int opcao, ano;
    char artista[100];
    printf(" Procurar por:\n1. Artista\n2. Ano\n");
    scanf("%d", &opcao);

    if (opcao == 1) { //procura a musica atravez do nome do artista
        printf(" Nome do artista: ");
        scanf(" %[^\n]", artista); //lê o nome do artista
        Musica *temp = playlist;//ponteiro temporario para a playlist
        while (temp != NULL) {//enquato não chegar ao fim da playlist
            if (strcmp(temp->artista, artista) == 0) {//faz comparação entre os nomes dos artistas na playlist com o nome digitado pelo usuario
                printf(" Título: %s, Artista: %s, Duração: %d segundos, Ano: %d\n",
                       temp->titulo, temp->artista, temp->duracao, temp->ano);
            }
            temp = temp->proxima;//avança para o proximo musica
        }
    } else if (opcao == 2) {//procura a musica atravez do seu ano
        printf(" Ano: ");
        scanf("%d", &ano);//lê o ano
        Musica *temp = playlist;//ponteiro temporario para a playlist
        while (temp != NULL) {//enquato não chegar ao fim da lista
            if (temp->ano == ano) {//compara o ano
                printf(" Título: %s, Artista: %s, Duração: %d segundos, Ano: %d\n",
                       temp->titulo, temp->artista, temp->duracao, temp->ano);
            }
            temp = temp->proxima;//avança para a proxima musica
        }
    } else {
        printf(" Opção inválida!\n");
    }
}


// ################# OPÇÃO-5 ##################### //

//função para calcular a duração total da playlist
void duracaoPlaylist(Musica *playlist) {
    int totalMusicas = 0, totalDuracao = 0;//variaveis auxiliares
    Musica *temp = playlist;//ponteiro para o inicio da playlist
    while (temp != NULL) {//enquanto não chegar ao fim da playlist
        totalMusicas++;//incrementa a variavel totalMusicas
        totalDuracao += temp->duracao;//soma a duração da musica
        temp = temp->proxima;//avança para a proxima musica
    }

    //converte a duração total para horas, minutos e segundos
    int horas = totalDuracao / 3600;
    int minutos = (totalDuracao % 3600) / 60;
    int segundos = totalDuracao % 60;

    //exibe o numero total de musicas e a duração total da playlist
    printf(" Número total de músicas: %d\n", totalMusicas);//mostra o total de musicas que tem a playlist
    printf(" Tempo total de duração: %d horas, %d minutos, %d segundos\n", horas, minutos, segundos);//mostra o tempo total da playlist
}


// ################# OPÇÃO-6 ##################### //

//função para avançar na playlist
void avancarPlaylist(Musica **playlist, Musica **atual) {
    if (*atual == NULL) {
        *atual = *playlist;//começa do inicio da playlist
    } else if ((*atual)->proxima != NULL) {
        *atual = (*atual)->proxima;//avança para a proxima musica
    } else {
        printf(" Já está na última música da playlist!\n");
    }

    if (*atual != NULL) {
        printf(" Reproduzindo: %s - %s\n", (*atual)->titulo, (*atual)->artista);
    }
}


// ################# OPÇÃO-7 ##################### //

//função para retroceder na playlist
void retrocederPlaylist(Musica **playlist, Musica **atual) {
    if (*atual == NULL) {
        printf(" Playlist vazia ou não começou a reprodução!\n");
        return;
    }

    if (*atual == *playlist) {
        printf(" Já está na primeira música da playlist!\n");
        return;
    }

    Musica *temp = *playlist;
    while (temp->proxima != *atual) {
        temp = temp->proxima;//avança para a proxima musica
    }
    *atual = temp;//atualiza o poteiro atual

    if (*atual != NULL) {
        printf(" Reproduzindo: %s - %s\n", (*atual)->titulo, (*atual)->artista);
    }
}


// ################# OPÇÃO-8 ##################### //

//função para guardar a playlist em um arquivo
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
        temp = temp->proxima;//avança para a proxima musica
    }
    fclose(arquivo);
    printf(" Playlist guardada com sucesso!\n");
}


// ################# OPÇÃO-9 ##################### //

//função para carregar a playlist de um arquivo
void carregarPlaylist(Musica **playlist) {
    FILE *arquivo = fopen("playlist.txt", "r");
    if (arquivo == NULL) {
        printf(" Erro ao abrir o arquivo!\n");
        return;
    }

    char titulo[100], artista[100];
    int duracao, ano;
    while (fscanf(arquivo, " %[^\n]\n%[^\n]\n%d\n%d\n", titulo, artista, &duracao, &ano) == 4) {
        //aloca espaço para uma nova musica e preenche os detalhes
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
             // Caso contrário, insere a nova música no final da playlist
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






