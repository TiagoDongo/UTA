org 100h

.stack

.data 
msg1 db "Primeiro numero: $" 
msg2 db "Segundo numero: $"
nummaior db " maior que $"
nummenor db " menor que $" 
iguais db "Sao iguais.$"

.code

mov ah, 09h
lea dx, msg1
int 21h

mov ah, 01h
int 21h

mov bh, al 

call NewLine

mov ah, 09h
lea dx, msg2
int 21h

mov ah, 01h
int 21h

mov bl, al 

call NewLine

cmp bh, bl
jg Maior
jb Menor

mov ah, 09h
lea dx, iguais
int 21h
;hlt 
jmp Fim

Menor:
    mov ah, 02h
    mov dl, bh
    int 21h
    
    mov ah, 09h
    lea dx, nummenor
    int 21h
    
    mov ah, 02h
    mov dl, bl
    int 21h
    ;hlt 
    jmp Fim


Maior: 
    mov ah, 02h
    mov dl, bh
    int 21h
    
    mov ah, 09h
    lea dx, nummaior
    int 21h
    
    mov ah, 02h
    mov dl, bl
    int 21h  
    ;hlt 
    jmp Fim

NewLine proc
    mov ah, 02h
    mov dl, 0ah
    int 21h
    mov dl, 0dh
    int 21h
    ret    
NewLine endp


Fim:
end