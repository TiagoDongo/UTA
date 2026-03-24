# Sistema de Playlist de Músicas

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![disciplina](https://img.shields.io/badge/Algoritmos_e_Estrutura_de_Dados-blue?style=for-the-badge)

Este é um programa em **C** que permite gerenciar uma playlist de músicas. 

## ⚙ Estrutura do Codigo

* `prototipos.h`: Contém a definição da estrutura de dados `Musica`, as declarações das funções utilizadas no programa e a inclusão das bibliotecas necessárias.
* `funcoes.c`: Implementa todas as funcionalidades do sistema de playlist, seguindo as declarações presentes em `prototipos.h`.
* `main.c`: Contém a função principal (`main`) do programa, responsável por exibir o menu de interação com o usuário e chamar as funções correspondentes às opções escolhidas.

## 💾 Armazenamento de Dados

As músicas da playlist são armazenadas utilizando uma **lista duplamente ligada**.

As playlists podem ser **salvas** e **carregadas** de arquivos de texto (`.txt`). O formato do arquivo `.txt` armazena as informações de cada música em linhas separadas.


## Funcionalidades

1.  **Adicionar Música:** adiciona novas músicas à playlist, solicitando informações como título, artista, duração (em segundos) e ano de lançamento.
2.  **Remover Música:** Remove uma música específica da playlist com base no seu título. 
3.  **Reproduzir Playlist:** reproduz a playlist em ordem crescente.
4.  **Procurar Música:** Permite buscar por uma música na playlist através do seu título e ano.
5.  **Duração da Playlist:** Calcula e exibe o tempo total de reprodução da playlist, somando a duração de cada música (armazenada em segundos).
6.  **Avançar na Playlist:** Move para a próxima música na playlist.
7.  **Retroceder na Playlist:** Move para a música anterior na playlist.
8.  **Guardar Playlist:** Salva o estado atual da playlist em um arquivo `.txt`.
9.  **Carregar Playlist:** Carrega uma playlist previamente salva a partir de um arquivo `.txt`.

## 🚀 Compilação e Execução

1.  **Compile o código:**
    ```bash
    gcc main.c funcoes.c prototipos.h -o playlist
    ```
2.  **Execute o programa:**
    ```bash
    ./playlist
    ```
    *(Observação: Em alguns sistemas, pode ser necessário usar `./playlist.exe`)*
