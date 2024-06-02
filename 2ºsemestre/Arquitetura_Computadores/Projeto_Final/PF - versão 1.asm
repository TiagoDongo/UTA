org 100h

.stack

.data

    aluno_notas db 10 dup(?)
    aluno_numero db 10 dup(?)
    
    msg1 db "Digite o numero do aluno(0 a 9): $"
    msg2 db "Digite a nota do aluno(0 a 20): $"
    
    
    menu db 0dh,0ah,"-------- MENU --------",0dh,0ah
    op1 db 0dh,0ah,"1 - Inserir notas do aluno",0dh,0ah
    op2 db 0dh,0ah,"2 - Imprimir numero e nota do aluno com nota mais alta",0dh,0ah
    op3 db 0dh,0ah,"3 - Iprimir numero e nota do aluno com nota mais baixa",0dh,0ah
    op4 db 0dh,0ah,"4 - Iprimir a quantidade de alunos aprovados e reprovados",0dh,0ah
    op5 db 0dh,0ah,"5 - Media das notas da turma",0dh,0ah
    op6 db 0dh,0ah,"6 - Quantidade de notas acima e abaixo da media da turma",0dh,0ah
    op7 db 0dh,0ah,"7 - Tabela com numero,nota e se o aluno foi aprovado ou reprovado",0dh,0ah
    op8 db 0dh,0ah,"8 - Notas emordem decrescente",0dh,0ah
    op9 db 0dh,0ah,"9 - Sair",0dh,0ah
    
    op db "Opcao: $"
    
    opcao db ? 
    
    num db ?
    
    
    
.code
    macro Novalinha ;macro para inserir uma nova linha no console
        mov ah, 02h
        mov dl, 0ah
        int 21h
        mov dl, 0dh
        int 21h
    endm

    macro imprime_msg msg ;macro para imprimir mensagens na tela
        mov ah, 09h
        lea dx, msg
        int 21h
    endm
    
    
    macro numero_aluno num ;macro para introduzir o numero do aluno
        mov ah, 01h  ;faz a leitura de um caracter       
        int 21h            
        sub al, 30h  ;comverte o caracter ASCII para um valor numerico
        mov num, al
    endm
    
    
    macro nota_aluno    ;macro para ler e comverter a nota do aluno em ate dois digitos
        xor dx, dx
        xor bx, bx
        mov dl, 0ah
        mov ch, 2h
        notas:
            mov ah, 01h
            int 21h
            cmp al, 0dh
            je final
            
            mov ah, 0h
            sub al, 30h
            mov ah, al
            mov al, bl
            mul dl
            
            add al, dl
            
            mov bl, al
            
        loop notas
        final: 
    endm
    
    macro dados_aluno ;macro para coletar dados dos 10 aluno
        mov cx, 10h
        mov si, 0h
        
        aluno:
        
        Novalinha
        
        imprime_msg msg1 
        numero_aluno al 
        mov [aluno_numero + si],al
        
        Novalinha
       
        imprime_msg msg2
        nota_aluno
        mov num, bl
        mov [aluno_notas + si], bl
        
        inc si
        cmp si,9h
        je saltar_fora
        
        
        Novalinha
        
        loop  aluno
        saltar_fora:  
    endm
    
    
    macro encontrar_max
        mov si, 0h
        mov bl, 0
        mov bh, 0
        mov di, 0h
        max_loop:
            mov al, [aluno_notas + si]
            cmp al, bl
            jle nao_altera_max
            mov bl, al
            mov bh, [aluno_numero + si]
            mov di, si
        nao_altera_max:
            inc si
            cmp si, 10
            jl max_loop
    endm
    
main:

M_menu:
    mov ah, 09h
    lea dx, menu   ;exibe o menu principal
    int 21h
    
    mov ah, 01h
    int 21h        ; le a opcao do meno selecionado e guarda o valor em opcao
    mov opcao, al

;compara opcao com os valore e faz je(salta se for iguat) a opcao correspondente    
    cmp opcao, '1'
    je opcao_1 
    
    cmp opcao, '2'
    je opcao_2
    
    cmp opcao, '3'
    je opcao_3   
    
    cmp opcao, '4'
    je opcao_4   
    
    cmp opcao, '5'
    je opcao_5   
    
    cmp opcao, '6'
    je opcao_6   
    
    cmp opcao, '7'
    je opcao_7   
    
    cmp opcao, '8'
    je opcao_8   
    
    cmp opcao, '9'
    je opcao_9 
    
    
    
opcao_1:

   dados_aluno ;invocando o macro para para introduzir os dados do aluno(numero e nota)
   jmp M_menu  ;retorna ao menu principal
    
opcao_2:
    encontrar_max
    jmp M_menu
    
opcao_3:
    jmp M_menu
    
opcao_4:
    jmp M_menu
    
opcao_5:
    jmp M_menu    
    
opcao_6:
    jmp M_menu    
    
opcao_7:
    jmp M_menu
    
opcao_8:
    jmp M_menu
    
opcao_9:
    jmp Fim
    
    
    
    
    
    
Fim:

end main       