;1
;tiago henrique da graca dongo
;26-09-2004

;2
;a)2004 = 7D4
;b)09 = 9
;c)26 = 1A
;d)2024 = 7E8
;e)2000 = 7D0

;3
mov ax, 7D4h
mov bl, 9h

;4
mul bl

;5
mov cx, 1ah
div cx
;o significado do valor colocado em dx e que ele e o resto da divisao

;6
mov dx, ax
mov ax, 7d4h
sub ax, dx
mov bl, al

;7
xor bl, cl
mov bh, bl

;8
inc dx
dec ax
and dx, ax

;9
cmp ax, 7d0h
jg maior

mov ax, 9999d
jmp fim

maior:
mov ax, 1111d


fim:
#start=led_display.exe# 

end