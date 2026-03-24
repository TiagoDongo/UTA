#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

// Estrutura para representar uma música //
typedef struct Musica {
    char titulo[100];
    char artista[100];
    int duracao; // em segundos
    int ano;
    struct Musica *proxima;
} Musica;


// Protótipos das Funções para manipular a playlist //
void adicionarMusica(Musica **playlist);
void removerMusica(Musica **playlist);
void reproduzirPlaylist(Musica *playlist, int ordem);
void procurarMusica(Musica *playlist);
void duracaoPlaylist(Musica *playlist);
void avancarPlaylist(Musica **playlist, Musica **atual);
void retrocederPlaylist(Musica **playlist, Musica **atual);
void guardarPlaylist(Musica *playlist);
void carregarPlaylist(Musica **playlist);


#endif // PROTOTIPOS_H_INCLUDED
