# Sistema de Gestão de Requisição e Devolução de Equipamentos Informáticos 🚀

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Static Badge](https://img.shields.io/badge/Introdu%C3%A7%C3%A3o_a_Programa%C3%A7%C3%A3o-gren?style=for-the-badge)

Um sistema simples  desenvolvido em **C** para gerenciar o processo de requisição e devolução de equipamentos informáticos.

## ⚙️ Funcionalidades

1.  **Adicionar Requisição:** Permite registrar uma nova requisição de equipamento , solicitando o nome do usuário e o equipamento desejado. O estado inicial da requisição é definido como "Pendente".
   
2.  **Listar Requisições:** Exibe todas as requisições cadastradas.
   
3.  **Aprovar/Rejeitar Requisições:** Processa requisições pendentes, solicitandoo nome do usuário e oferece opções para aprovar ou rejeitar a requisição correspondente, atualizando o estado da mesma.

4.  **Registrar Devolução:** Permite marcar uma requisição aprovada como devolvida. 
   
5.  **Listar Requisições por Usuário:** Solicita o nome de um usuário e exibe todas as requisições associadas a ele, juntamente com o equipamento, estado e status de devolução.
   
6.  **Listar Requisições Aprovadas:** Exibe todas as requisições que foram aprovadas.
   
7.  **Listar Requisições Devolvidas:** Exibe todas as requisições onde o equipamento já foi devolvido.

## 🚀 Compilação e Execução

1.  **Compile o código:** 
    ```bash
    gcc projeto_final.c -o gestao_equipamentos
    ```
2.  **Execute o programa:** 
    ```bash
    ./gestao_equipamentos
    ```
