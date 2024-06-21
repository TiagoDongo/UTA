#start=led_display.exe#   

;out porto, acumulador -> coloca o valor do 
;acumulador no endereco do porto
mov ax, 1234h
out 199, ax

;in acumulador, porto
mov ax, 0h
in ax, 199


mov ax, 1233h
mov bx, 1234h

cmp ax, bx       ; comparar

jg Maior ; jump if greater, salte para Maior se ax maior que bx

mov cx, bx
jmp Continuar ; jump: saltar para Continuar

Maior: 
mov cx, ax

Continuar:
add cx, 1h





hlt; halt: parar

;mov destino, origem

;mov ax, 1001110101010110b 
;mov al, 34h 
;mov ah, 15 

;add destino, origem -> destino = destino + origem

;add al, 01h  
mov bx, 1234h
add bx, ax

;sub destino, origem -> destino = destino - origem

mov dl, 08h
mov cl, 02h
sub dl, cl ;dl = dl-cl

; mul origem

;mov ax, 5h  
mov bl, 2h
mul bl  ; ax = ax * bl

;div origem
mov ax, 0bh
mov cl, 2h
div cl   ; ax / cl -> al = divisao inteira, ah = resto da divisao

;dec destino 
mov bl, 6h
dec bl  ; bl = bl - 1 -> 05

;inc destino
mov dx, 1234h
inc dx ; dx = dx + 1 -> 1235   

;and destino, origem
mov ah, 1110b
mov al, 0101b
and ah, al  

mov bh, 0eh
mov bl, 5h
and bh, bl    

;or destino, origem
mov ch, 1010b
mov cl, 0101b
or ch, cl  ;-> 1111b -> Fh

;xor destino, origem
mov dh, 1001b
mov dl, 1111b
xor dh, dl    

;not destino

;neg destino : complemento a2    

