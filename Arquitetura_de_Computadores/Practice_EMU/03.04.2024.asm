org 100h

.stack

.data
; Declaracao das variaveis msg e carater
msg db "Introduza um carater: $"
carater db ?

.code
; imprimir a string em msg
mov ah, 09h
lea dx, msg ;Significa Load Effective Address -> 
            ;coloca uma copia do offset do endereco 
            ;da posicao de memoria fonte no registrador destino
int 21h

; ler um carater
mov ah, 01h
int 21h

mov carater, al 

call NewLine; invocacao do procedimento NewLine 

; imprimir um carater
mov ah, 02h
mov dl, carater
int 21h

; Procedimento de nome NewLine
NewLine proc
   mov ah, 02h
   mov dl, 0ah ; 0ah -> codigo ascii para mudar de linha
   int 21h
   
   mov ah, 02h
   mov dl, 0dh ; 0dh -> codigo ascii carater para colocar
   int 21h
NewLine endp


ret