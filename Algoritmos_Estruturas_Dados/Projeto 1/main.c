#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");     //permite usar palavras com acentos

    Musica *playlist = NULL;
    Musica *atual = NULL;
    int opcao, ordem;

    do {
        printf("\n");
        printf(" ###### My PlayList ######\n\n");
        printf(" 1. Adicionar M�sica\n");
        printf(" 2. Remover M�sica\n");
        printf(" 3. Reproduzir Playlist\n");
        printf(" 4. Procurar M�sica\n");
        printf(" 5. Dura��o Playlist\n");
        printf(" 6. Avan�ar na Playlist\n");
        printf(" 7. Retroceder na Playlist\n");
        printf(" 8. Guardar Playlist\n");
        printf(" 9. Carregar Playlist\n");
        printf(" 10. Sair\n");
        printf("\n op��o: ");
        scanf("%d", &opcao);


        switch (opcao) {
            case 1:
                adicionarMusica(&playlist);
                break;
            case 2:
                removerMusica(&playlist);
                break;
            case 3:
                printf(" 1. Ordem Crescente\n 2. Ordem Decrescente\n");
                scanf("%d", &ordem);
                reproduzirPlaylist(playlist, ordem);
                break;
            case 4:
                procurarMusica(playlist);
                break;
            case 5:
                duracaoPlaylist(playlist);
                break;
            case 6:
                avancarPlaylist(&playlist, &atual);
                break;
            case 7:
                retrocederPlaylist(&playlist, &atual);
                break;
            case 8:
                guardarPlaylist(playlist);
                break;
            case 9:
                carregarPlaylist(&playlist);
                break;
            case 10:
                exit(0);
            default:
                printf(" Op��o inv�lida!\n");
        }
    }while(opcao != 10);

    return 0;
}
