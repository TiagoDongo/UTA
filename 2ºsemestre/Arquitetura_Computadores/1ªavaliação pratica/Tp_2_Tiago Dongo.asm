org 100h

.stack

.data

menu db 0dh,0ah,"##################### - MENU - #####################",0dh,0ah 
op1 db 0dh,0ah,"T - Imprimir o meu nome",0dh,0ah
op2 db "I - Imprimir a minha idade ",0dh,0ah
op3 db "A - Imprimir numeros (0 a idade)",0dh,0ah
op4 db "G - Calcular soma e divisao",0dh,0ah
op5 db "O - Sair",0dh,0ah
op db "Opcao: $"
opcao db ? 
nome db 0dh,0ah,"O meu nome e Tiago Henrique Da Graca Dongo$"
invalida db "Opcao Invalida!!",0dh,0ah,"$" 
tenho db 0dh,0ah,"Tenho $"
anos db " anos.$"
NovaLinha db 0dh,0ah,"$"
num db "Insira um numero: $" 
num1 db ?
num2 db ?
soma db "Soma: $"
divisao db "Divisao: $"

ano1 dw 2004;7d4h
ano2 dw 2024;7e8h
.code 

meu_menu:
    mov ah, 09h
    lea dx, menu
    int 21h 
    
    mov ah, 01h
    int 21h
    
    mov opcao, al
    cmp opcao, 54h 
    je opcaoT
    
    cmp opcao, 49h 
    je opcaoI
    
    cmp opcao, 41h
    je opcaoA 
    
    cmp opcao, 47h  
    je opcaoG
    
    cmp opcao, 4Fh 
    je opcaoO  
    
    jmp OpcaoInvalida
    

opcaoT:
    mov ah, 09h
    lea dx, nome
    int 21h 
    call NewLine
    JMP meu_menu 

opcaoI: 
    mov ah, 09h
    lea dx, tenho
    int 21h
    
    mov bx, ano2
    sub bx, ano1
    
    call Imprimir2Digitos 
    
    mov ah, 09h
    lea dx, anos
    int 21h 
    call NewLine
    JMP meu_menu

opcaoA:
    mov cx, ano2
    sub cx, ano1
    inc cx
    mov bl, 0h
    
    imprimir:
        call NewLine
        call Imprimir2Digitos
        inc bl    
    loop imprimir
    call NewLine
    JMP meu_menu

opcaoG:
    call NewLine 
    mov ah, 09h
    lea dx, num
    int 21h     
    
    call Recebe2Digitos
    mov num1, bl
    
    call NewLine 
    mov ah, 09h
    lea dx, num
    int 21h     
    
    call Recebe2Digitos
    mov num2, bl 
    
    call NewLine
    
    mov bl, num1
    add bl, num2
    
    mov ah, 09h
    lea dx, soma
    int 21h
    
    call Imprimir2Digitos
    
    call NewLine
    
    mov ah, 09h
    lea dx, divisao
    int 21h 
    
    xor ax, ax
    mov al, num1
    div num2
    
    mov bl, al
    
    call Imprimir2Digitos

    call NewLine
    
    JMP meu_menu

opcaoO: 
 
    JMP Fim

OpcaoInvalida:
    mov ah, 09h
    lea dx, invalida
    int 21h
    jmp meu_menu
     
jmp Fim

NewLine proc
    mov ah, 09h
    lea dx, NovaLinha
    int 21h
    ret
NewLine endp 

Imprimir2Digitos proc
    mov al, bl 
    MOV ah, 0h
    mov bh, 0ah
    div bh
    mov dl, al
    mov bh, ah
    mov ah, 02h 
    add dl, 30h
    int 21h    
    mov dl, bh
    add dl, 30h
    int 21h
    ret
Imprimir2Digitos endp   

Recebe2Digitos proc
   xor dx, dx
   xor bx, bx
   mov dl, 0ah
   
   mov cx, 2h  
   
   meu_loop:   
        mov ah, 01h
        int 21h
        cmp al, 0dh
        je termina  
   
        mov ah, 0h
        sub al, 30h
        mov dh, al
        mov al, bl
        mul dl
       
        add al, dh
       
        mov bl, al
   loop meu_loop 
   termina:
   ret
Recebe2Digitos endp

Fim:

end