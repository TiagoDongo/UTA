;Tiago Henrique Da Graca Dongo

org 100h

.stack 

.data
  msg db "Digite um numero entre 00 e 99: $"
  
  array db 5 dup(?) ;array inicializado vazio
  
  num db ? ;variavel

.code

  ;macro para imprimir mensagens na tela
  macro imprimeString mensagem
    mov ah, 09h
    lea dx, mensagem
    int 21h
  endm 
  
  ;macro para receber um numero de dois digitos( 00 )
  macro Recebe2Digitos 
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
      
    endm
  
  ;macro para saltar para proxima linha
  macro novalinha
    mov ah, 02h
    mov dl, 0ah
    int 21h
    mov dl, 0dh
    int 21h 
  endm
  
  
  macro exercicio1
    mov cx, 5h
    mov si, 1h
    
    a:
    imprimeString msg
    Recebe2Digitos
    mov num, bl
    mov [array + si], bl
    cmp si, 5h
    je fora
    inc si
    
    novalinha
    
    loop a
    fora:
  endm
  
  


main: 
  
  
  ;numero 1  
  exercicio1
  
  
  ;numero 2
  ;não foi feito
end main