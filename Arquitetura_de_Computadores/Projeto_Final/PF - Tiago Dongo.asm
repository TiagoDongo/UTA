;PROJETO FINAL DA DISCIPLINA ARQUITETURA DE COMPUTADORES

;Trabalho realizado por:
    ;Eric Reis
    ;Liedson Delgado
    ;Tiago Dongo


org 100h


.stack


.data

    ;Vetores
    aluno_notas db 10 dup(?) ;vetor para nota
    aluno_numero db 10 dup(?) ;vetor para numero do aluno
    
    
    ;Mensagens    
    msg1 db "Digite o numero do aluno(0 a 9): $"
    msg2 db "Digite a nota do aluno(0 a 20): $"
    
    melhor db "Aluno com nota mais alta: $"
    pior db "Aluno com nota mais baixa: $"     
    
    aprovado db " Aprovados: $"    
    reprovado db " Reprovados: $"
    
    nota_abaixo_media db "Notas abaixo da media: $"
    nota_acima_media db "Notas acima da media: $"  
    
    msg_numero db " ->Aluno: $"
    msg_nota db " ->Nota: $"
    msg_estado db " ->Estado: $"
    msg_media db "Media da turma: $"
    aprov_aluno db " ->Aprovadp$"
    reprov_aluno db " ->Reprovado$"
    
    
    ;Variaveis
    num db ?
    
    maior db ?
    
    menor db ?
    
    indice db ?
    
    ap db ?
    rp db ?
    
    media db ?
    
    acima db ?
    abaixo db ?
    
    mais db ?
    menos db ?
    
    
    ;Menu
    menu db 0dh,0ah,"-------- MENU --------",0dh,0ah
    op1 db 0dh,0ah,"1 - Inserir notas do aluno",0dh,0ah
    op2 db 0dh,0ah,"2 - Imprimir numero e nota do aluno com nota mais alta",0dh,0ah
    op3 db 0dh,0ah,"3 - Imprimir numero e nota do aluno com nota mais baixa",0dh,0ah
    op4 db 0dh,0ah,"4 - Imprimir a quantidade de alunos aprovados e reprovados",0dh,0ah
    op5 db 0dh,0ah,"5 - Media das notas da turma",0dh,0ah
    op6 db 0dh,0ah,"6 - Quantidade de notas acima e abaixo da media da turma",0dh,0ah
    op7 db 0dh,0ah,"7 - Tabela com numero,nota e se o aluno foi aprovado ou reprovado",0dh,0ah
    op8 db 0dh,0ah,"8 - Notas em ordem decrescente",0dh,0ah
    op9 db 0dh,0ah,"9 - Sair",0dh,0ah
    op10 db 0dh,0ah, " ",0dh,0ah
    op db "Opcao: $"
     
    opcao db ?
    

.code

    ;macro para mudanca de linha
    macro Novalinha 
        mov ah, 02h ;move para ah 02h
        mov dl, 0ah ;move para dl o caracter de mudanca de linha
        int 21h ;realiza a funcao
        mov dl, 0dh ;move para dl o caracter que move o cursor para o inicio da linha
        int 21h ;realiza a funcao
    endm
    
    
    
    ;macro para imprimir mensagens
    macro imprime_msg msg 
        mov ah, 09h ;funcao para imprimir uma string
        lea dx, msg ;carrega o endereco da string em dx
        int 21h  ;chama a interrupcao para imprimir a string
    endm
    
    
    
    ;macro para digitar numero do aluno
    macro numero_aluno numero 
        mov ah, 01h ;funcao para ler um caracter do teclado        
        int 21h ;le o caracter do teclado e o coloca em al           
        sub al, 30h ;converte o caracter ASCII para um valor numerico 
        mov numero, al ;armazena o valor na variavel num
    endm
    
    
    
    ;macro para digitar nota do aluno
    macro nota_aluno   
        xor dx, dx  ;zera o registrador dx
        xor bx, bx  ;zera o registrador bx
        mov dl, 0ah ;move para dl 10
        mov cx, 2h  ;move para ch 2 - contador do loop para 2 digitos
        notas:
            mov ah, 01h ;funcao para ler um caracter do teclado
            int 21h ;le o caracter do teclado e o coloca em al
            cmp al, 0dh ;compara o caracter lido com enter(0Dh)
            je final ;salta para o label final se al for igual a enter
            
            mov ah, 0h ;zera ah para para multuplicacao
            sub al, 30h ;converte o caracter ASCII para um valor numerico  
            mov dh, al ;coloca o valor numerico em ah
            mov al, bl ;move o valor de bl para al
            mul dl ;multiplica al por 10 para deslocar o disco
            
            add al, dh ;adiciona o novo digito ao acumulador
            
            mov bl, al ;atualiza bl com o novo valor do acumulador
            
        loop notas ;faz o loop de notas
        final: 
    endm 
    
    
    
    ;macro que faz a coleta de dados para 10 aluno
    macro dados_aluno 
        mov cx, 10h ;move para cx 10
        mov si, 0h  ;move para si 0
        
        aluno:        
            Novalinha  ;imprime uma nova linha
            
            imprime_msg msg1 ;imprime a mensagem para inserei o numero do aluno
            numero_aluno bl ;le o numero do aluno e armazena em al
            mov [aluno_numero + si], bl ;move para a primeira posicao do vetor o calor de al
            
            Novalinha  ;imprime uma nova linha
           
            imprime_msg msg2 ;imprime a mensagem para inserir a nota do aluno
            nota_aluno ;le a nota do aluno e armazena bl
            mov num, bl ;armazena a nota lida na variavel num
            mov [aluno_notas + si], bl ;Armazena a nota do aluno no vetor aluno_notas
            
            inc si ;incrementa o valor de si
            cmp si,10 ;compara se si > 10
            je saltar_fora ;se si > 10 salta para o rotulo salta_fora
            
            
            Novalinha ;imprime uma nova linha
        
        loop  aluno ;decrementa cx e repete o loop se cx nao for zero
        
        saltar_fora:  
    endm
        
    
    
    ;macro para encontrar o aluno com a nota mais alta
    macro melhor_aluno
        mov si, 0d  ;inicializa o indice de aluno com 0
        mov al, [aluno_notas + si]  ;bl toma o valor que esta na primeira posicao do vetor
        mov maior, al ;move para maior aluno_notas[si]       
        mov cx, 9d  ;loop para percorrer 10 alunos

    
        procura_maior:   
            inc si ;incrementa o indice
            mov ah, [aluno_notas + si]  ;move para ah aluno_notas[si]
            cmp ah, maior ;compara se ah > al
            jg proximo ;salta para proximo se ah > al
            jmp avancar ;salta para continua se nao for
            
            proximo:
                mov maior, ah ;move para maior o valor de ah->aluno_notas[si]
                mov bx, si ;move para bx o valor de si
                mov indice, bl 
                
            avancar:
                        
        loop procura_maior ;faz loop do label procura
                
    endm 
    
    
    
    ;macro para encontra o aluno com a nota mais baixa
    macro pior_aluno
        mov si, 0d ;inicializa si a zero
        mov al, [aluno_notas + si] ;move para al aluno_notas[si]
        mov menor, al ;armazena o valor de al na variavel menor
        mov cx, 9d ;loop para percorrer 10 alunos
        
        procura_menor:
            inc si ;incrementa si
            mov ah, [aluno_notas + si] ;move para al aluno_notas[si]
            cmp ah, menor ;compara al com menor
            jl proximo_aluno ;salta se o valor de al for abaixode 10
            jmp continuar  ;salta para continuar se o valor de al nao for abaixo de 10
                         
            proximo_aluno:
                mov menor, ah ;move o valor de al para menor
                mov bx, si ;move para bx o valor de si
                mov indice, bl ;move para indice o valor de bl
                
            continuar:

            loop procura_menor ;decrementa cx e faz o loop se cx nao for zero
                
    endm
    
    
    
    ;macro para saber a quatidade de alunos aprovados e reprovado
    macro aprovado_reprovado 
        mov si, 0d ;inicializa si a 0
        mov cx, 10d ;loop para percorrer 10 alunos
        
        contar:
            mov al, [aluno_notas + si] ;move para al aluno_notas[si]
            cmp al, 10 ;compara se al > 10
            jb reprova ;faz um salto para o rotulo reprovou se for abaixo de 10
            
            inc ap ;incrementa a variavel ap ->aprovados
            jmp sair_fora ;salta para o rotulo fora
            
            reprova:
                inc rp ;incrementa a variavel rp ->reprovados
            
            sair_fora:
                inc si ;incrementa si
                loop contar ;decrementa cx e faz o loop enquanto cx nao for zero
    endm
    
    
    
    macro media_da_turma 
        xor ax, ax ;zera ax
        xor dx, dx ;zera dx
        xor bx, bx ;zera bx
        mov si, 0d ;inicializa si a zero
        mov cx, 10d ;loop para percorrer 10 alunos 
        loop_media:
            mov al, [aluno_notas + si] ;move para al aluno_notas[si]
            add bl, al ;faz a adicao bx= bx + ax
            inc si ;incrementa si
            loop loop_media ;decrementa cx e faz o loop enquanto cx nao for zero
            
            mov ax, bx
            mov cx, 10d
            div cx
            mov media, al ;armazena o resultado na variavel media
            
    endm
    
       
    
    
    ;macro para saber a quantidade de notas acima e abaixo da media de turma 
    macro notas_acima_abaixo
        mov si, 0d ;inicializa si a zero
        mov cx, 10d ;loop para percorrer 10 alunos
                
        mov acima, 0d  ;inicializa acima a zero
        mov abaixo, 0d ;inicializa abaixo a zero
        
        acima_abaixo:
            mov al, [aluno_notas +si] ;move para al aluno_notas[si]
            cmp al, media ;compara al com a media da turma
            jg acima_da_media ;salta se for maior que a media
    
            inc abaixo ;incrementa a variavelabaixo
            jmp resultado_final ;salta para o rotulo resultado_final
            
            acima_da_media:
                inc acima ;incrementa a variavel acima
                
            resultado_final:
                inc si ;incrementa si
                loop acima_abaixo  ;decrementa cx e faz o loop enquanto cx nao for zero
    endm
    
    
    ;macro para imprimir uma tabela com numero,nota e estado(aprovado ou reprovado) do aluno 
    macro tabela
        mov si, 0h ;inicializa o indice si
        mov cx, 10  ;loop para 10 alunos
        
        imprime_tabela:
            imprime_msg msg_numero ;imprime a mensagem " ->Aluno: "
            mov dl, [aluno_numero + si]  ;carrega a nota do aluno
            add dl, 30h ;converte para caracter ASCII
            mov ah, 02h ;funcao para imprimir um caracter
            int 21h ;realiza a funcao
            
            imprime_msg msg_nota ;imprime a mensagem " ->Nota: "
            mov bl, [aluno_notas + si] ;carrega a nota do aluno
            call Imprimir2Digitos ;imprime a nota do aluno
            
            cmp bl, 10 ;compara a nota com 10
            jb aluno_reprovado ;salta se for menor que 10 para o rotulo indicado
            
            imprime_msg aprov_aluno ;imprime a mensagem " ->Aprovado"
            jmp prox_aluno;salta para o rotulo indicado
            
            aluno_reprovado:
                imprime_msg reprov_aluno ;imprime a mensagem " ->Reprovado"
                
            prox_aluno:
                Novalinha  ;nova linha para proximo aluno
                
                inc si ;incrementa o indice
                loop imprime_tabela  ;decrementa cx e faz o loop enquantocx nao for zero
    endm
    
    
main:
    main_menu:
        Novalinha
        
        mov ah, 09h ;funcao para imprimir uma string
        lea dx, menu ;carrega o endereco da string   
        int 21h ;imprime o menu
        
        mov ah, 01h ;funcao para ler uma caracter do teclado
        int 21h  ;interrompe para chamar a funcao 01h       
        mov opcao, al ;armazena o valor de al na variavel opcao
        
        Novalinha  ;imprime uma nova linha
        
      
        cmp opcao, '1'  ;compara opcao com 1
        je opcao_1  ;se for opcao for igual a 1 salta para opcao_1
        
        cmp opcao, '2' ;compara opcao com 2
        je opcao_2 ;se for opcao for igual a 1 salta para opcao_2
        
        cmp opcao, '3' ;compara opcao com 3
        je opcao_3 ;se for opcao for igual a 1 salta para opcao_3  
        
        cmp opcao, '4' ;compara opcao com 4
        je opcao_4  ;se for opcao for igual a 1 salta para opcao_4 
        
        cmp opcao, '5' ;compara opcao com 5
        je opcao_5 ;se for opcao for igual a 1 salta para opcao_5  
        
        cmp opcao, '6' ;compara opcao com 6
        je opcao_6 ;se for opcao for igual a 1 salta para opcao_6  
        
        cmp opcao, '7' ;compara opcao com 7
        je opcao_7 ;se for opcao for igual a 1 salta para opcao_7  
        
        cmp opcao, '8' ;compara opcao com 8
        je opcao_8 ;se for opcao for igual a 1 salta para opcao_8  
        
        cmp opcao, '9' ;compara opcao com 9
        je opcao_9 ;se for opcao for igual a 1 salta para opcao_9
    
    
        
        opcao_1:
            Novalinha
            
            dados_aluno ;invoca a macro dados_aluno para digitar o numero e a nota de 10 alunos  
            
            jmp main_menu ;salta para o rotulo M_menu 
        
        
        opcao_2:
            call limpeza 
            Novalinha
        
            melhor_aluno
            Novalinha
            
            imprime_msg melhor
            Novalinha
            
            imprime_msg msg_numero
            add indice, 1h
            mov bl, indice
            call Imprimir2Digitos       
 
            Novalinha
            
            imprime_msg msg_nota
            mov bl, maior
            call Imprimir2Digitos
            
            Novalinha
            
            jmp main_menu
        
        
        opcao_3:
            call limpeza 
            Novalinha
        
            pior_aluno
            Novalinha
            
            imprime_msg pior
            Novalinha
            
            imprime_msg msg_numero
            add indice, 1h
            mov bl, indice
            call Imprimir2Digitos  
            
            Novalinha
            
            imprime_msg msg_nota
            mov bl, menor
            call Imprimir2Digitos
            Novalinha
            jmp main_menu
        
        
        opcao_4:
            call limpeza 
            Novalinha
            
            aprovado_reprovado 
        
            Novalinha
            
            imprime_msg aprovado
            mov bl, ap
            call Imprimir2Digitos
            
            Novalinha
            
            imprime_msg reprovado
            mov bl, rp
            call Imprimir2Digitos        

            jmp main_menu
        
    
        opcao_5:
        call limpeza
            Novalinha
        
            media_da_turma
        
            imprime_msg msg_media
            mov bl, media
            call Imprimir2Digitos
            Novalinha
            jmp main_menu    
        
        
        opcao_6:
            call limpeza
            Novalinha
                        
            notas_acima_abaixo
                        
            Novalinha
            imprime_msg nota_acima_media
            mov bl, acima
            call Imprimir2Digitos
            
            Novalinha
            
            imprime_msg nota_acima_media
            mov bl, abaixo
            call Imprimir2Digitos
            
            Novalinha
            jmp main_menu    
            
        
        opcao_7:
            Novalinha
            
            tabela
            
            jmp main_menu
            
        
        opcao_8:
            jmp main_menu
            
        
        opcao_9:
            jmp Fim ;salta para o rotulo Fim  
            
            
            
        Fim:

;procedimento para imprimir um numero de dois digitos
Imprimir2Digitos proc
    mov al, bl ;move para al o valor de bl
    MOV ah, 0h ;zera ah
    mov bh, 0ah ;move para bh o divisor 10
    div bh ;divide ax por 10
    mov dl, al ;move para dl o quociente  al
    mov bh, ah ;move para bl o resto ah
    mov ah, 02h ;funcao para imprimir um caracter
    add dl, 30h ;converte o valor para ASCII
    int 21h  ;realiza a funcao  
    mov dl, bh ;move para dl o valor de bh
    add dl, 30h ;converte o valor para seu codigo ASCCI
    int 21h ;realiza a funcao
    ret ;retorna do procedimento
Imprimir2Digitos endp  

;procedimento para limpar a tela e os registradores
limpeza proc
    xor ax, ax ;zera o registrador ax
    xor bx, bx ;zera o registrador bx
    xor cx, cx ;zera o registrador cx
    xor dx, dx ;zera o registrador dx
    mov ah, 06h ;funcao para rolar a tela para cima
    int 10h ;interrupcao para realizar a funcao
    ret ;retorna do procedimento
endp

end main    
