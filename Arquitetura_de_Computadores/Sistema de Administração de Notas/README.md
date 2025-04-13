# Sistema de Administração de Notas

![Assembly](https://img.shields.io/badge/Assembly-%234682B4?style=for-the-badge)
![EMU8086](https://img.shields.io/badge/EMU8086-%2332CD32?style=for-the-badge)
![disciplina](https://img.shields.io/badge/Arquitetura_de_Computadores-darkred?style=for-the-badge)

Este é um programa desenvolvido em **Assembly** para o ambiente **EMU8086**. Ele permite gerenciar as notas de até 10 alunos, oferecendo diversas funcionalidades para análise e visualização dos dados.

## ⚙️ Estrutura do Código

O código Assembly está organizado em seções `.stack`, `.data` e `.code`. As principais partes são:

* **.data:** Define os vetores para armazenar as notas (`aluno_notas`) e o número dos alunos (`aluno_numero`), além de diversas mensagens para interação com o usuário e exibição dos resultados. Variáveis temporárias também são definidas aqui.
  
* **.code:** Contém a lógica principal do programa, incluindo macros para facilitar tarefas como impressão de mensagens (`imprime_msg`), leitura de números (`numero_aluno`), leitura de notas (`nota_aluno`) e a coleta de dados para os alunos (`dados_aluno`). Também inclui macros para realizar os cálculos e as funcionalidades do menu:
  
    * `melhor_aluno`: Encontra o aluno com a maior nota.
    * `pior_aluno`: Encontra o aluno com a menor nota.
    * `aprovado_reprovado`: Conta o número de alunos aprovados (nota ≥ 10) e reprovados (nota < 10).
    * `media_da_turma`: Calcula a média das notas da turma.
    * `notas_acima_abaixo`: Conta quantas notas estão acima e abaixo da média da turma.
    * `tabela`: Exibe uma tabela com o número do aluno, sua nota e o status (Aprovado/Reprovado).
  
* **Macros:** Funções embutidas (`Novalinha`) para formatação da saída.
  
* **Procedimentos (`procs`):** `Imprimir2Digitos` para exibir números de dois dígitos e `limpeza` para limpar a tela.
  
* **`main`:** A rotina principal que exibe o menu de opções e direciona a execução para a funcionalidade escolhida pelo usuário.

## ✨ Funcionalidades

1.  **Inserir notas (0 a 20):** Permite ao usuário digitar o número (0 a 9) e a nota de cada um dos 10 alunos. Os dados são armazenados nos vetores `aluno_numero` e `aluno_notas`.
2.  **Exibir aluno com maior e menor nota:** Identifica e mostra o número do aluno e a respectiva maior e menor nota da turma.
3.  **Contar aprovados (≥10) e reprovados (<10):** Calcula e exibe a quantidade de alunos que obtiveram nota igual ou superior a 10 (aprovados) e aqueles com nota inferior a 10 (reprovados).
4.  **Calcular média da turma:** Computa a média aritmética de todas as notas dos alunos.
5.  **Contar notas acima/abaixo da média:** Determina e exibe o número de notas que estão acima e abaixo da média da turma calculada.
6.  **Exibir tabela com alunos, notas e status:** Apresenta uma tabela formatada mostrando o número de cada aluno, sua respectiva nota e se ele foi aprovado ou reprovado.
7.  **Ordenar notas em ordem decrescente:** *(Funcionalidade presente no menu, mas a implementação no código fornecido não está completa. Ao selecionar esta opção, o programa retorna ao menu principal)*.
8.  **Sair do programa:** Encerra a execução do programa.

## 🚀 Compilação e Execução

Este programa foi desenvolvido especificamente para o ambiente **EMU8086**.

1.  **Carregue o arquivo `.asm` no EMU8086.**
2.  **Compile e execute no emulador.** Utilize as ferramentas de compilação e execução fornecidas pelo EMU8086.
3.  **Interface:** A interação com o programa é feita através de um menu de texto exibido no console do EMU8086. Digite o número da opção desejada e pressione Enter.

## 🛠️ Ferramentas Utilizadas

* **Linguagem de Programação:** Assembly (específico para arquitetura 8086)
* **Emulador:** EMU8086
