org 100h

.code

;1 com loop
mov ax, 1h
mov cx, 9
num:
   add ax, 30h
   mov dl, al
   mov ah, 02h 
   int 21h
   
   sub ax, 30h
   inc ax
   
loop num 



;2 com loop
mov ah, 02h
mov dl, 61h
mov cx, 26d
rept:
    int 21h
    inc dl

loop rept


;2 com saltos condicionados
mov ah, 02h
mov dl, 7ah
reptt:
    int 21h
    dec dl
    cmp dl, 60h 
    jnz reptt






end