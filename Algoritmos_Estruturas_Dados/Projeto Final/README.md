# Sistema de Playlist de Músicas

Este é um programa em **C** que permite gerenciar uma playlist de músicas. 

## Funcionalidades

1. **Adicionar Música**: Permite adicionar uma nova música à playlist.
2. **Remover Música**: Permite remover uma música da playlist.
3. **Reproduzir Playlist**: Reproduz as músicas da playlist em ordem crescente ou decrescente.
4. **Procurar Música**: Permite procurar músicas por artista ou ano.
5. **Duração da Playlist**: Exibe o número total de músicas e o tempo total da playlist.
6. **Avançar na Playlist**: Avança para a próxima música na playlist.
7. **Retroceder na Playlist**: Retrocede para a música anterior na playlist.
8. **Guardar Playlist**: Salva a playlist em um arquivo de texto (`playlist.txt`).
9. **Carregar Playlist**: Carrega a playlist de um arquivo de texto (`playlist.txt`), se existir.

## 🖥️ Requisitos

- **Compilador:** MinGW (para Windows) ou GCC (para Linux)
- **Extensões:** 

    - **C/C++** para suporte à linguagem
    - **Code Runner ou C/C++ Compile Run** para facilitar a execução do código


## 🚀 Compilação e Execução
1. Compile o código:
    ````bash
    gcc main.c funcoes.c prototipos.h -o playlist
    ````
2. Execute o programa: 
    ````
    ./playlist.exe
    ````