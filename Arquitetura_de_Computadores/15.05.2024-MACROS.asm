org 100h

.stack

.data
    msg1  db "Mensagem 1$"
    msg2 db "Digite um numero: $"
    msg3 db "Dobro: $"



.code

    meu_macro macro ;macro que adiciona ax com bx
        add ax, bx
        mov cx, ax 
    endm
    
    macro imprimirString msg  ;macro que imprime uma string
        mov ah, 09h
        lea dx, msg
        int 21h
    endm
    
    
    macro Receber_digito numero
        mov ah, 01h
        int 21h 
        sub al, 30h
        mov numero, al
    endm
    
    
    macro Dobro_numero numero
        mov al, 02h
        mul numero
        mov numero, al
    endm 
    
    
    macro ImprimirDigito numero 
        mov ah, 02h
        mov dl, numero
        add dl, 30h
        int 21h
    endm
        
    

main:

    imprimirString msg2
    Receber_digito bl
    
    call NewLine
    
    
    imprimirString msg3 
    Dobro_numero bl
    imprimirDigito bl
    
    call NewLine 
    

    imprimirString msg1
    mov ax, 10h
    mov bx, 20h
    meu_macro ;incovacao do macro
    
    
    
    
    
    
    
    
    
    NewLine proc
        mov ah, 02h
        mov dl, 0ah
        int 21h
        mov dl, 0dh
        int 21h
        ret    
    NewLine endp


end main