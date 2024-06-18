 org 100h

;Tiago Henrique Da Graca Dongo

;Engenharia informatica e telecomunicacoes

;######## ->134af83h

;20040926 -> 131ccde 

;2004 -> 7d4


;2  
;codigo aluno: ######## ->134af83h

;Data de nascimento: 20040926 -> 131ccde 

;ano 2004 -> 7d4


;3
mov bx, 0af83h



;4 
mov ax, 131ch 

;5
mov cl, 02h
mul cl

;6
mul bx

;7
cmp ax,bx
jg maior
    sub bx, ax
jmp continuar

maior:
    sub ax, bx  
    
continuar: 
    
 
 
;8
mov cx, 7d4h
or ax, cx


;9
xor ch,cl



;10
mov bx, 0134h
mov ax, 0cdeh
add ax, bx

;11
mov dl, 00h
mov cl, 02h
div cl 
cmp ah, dl

     
