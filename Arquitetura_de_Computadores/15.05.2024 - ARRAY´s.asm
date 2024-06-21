org 100h

.stack

.data
    meu_array db 1,2,3,4,5; array com 5 elementos
    meu_array2 db 5 dup(?); dup=duplicar

.code
    macro ImprimirDigito numero 
        mov ah, 02h
        mov dl, numero
        add dl, 30h
        int 21h
    endm 
    
    macro Receber_digito numero
        mov ah, 01h
        int 21h 
        sub al, 30h
        mov numero, al
    endm
    
    
main:
  
  mov si,0h
  Receber_digito bl
  mov [meu_array2 + 0h], bl 
  
  
  imprimirDigito [meu_array+si] ;imprime o valor na primeira posicao  meu_array[si]   
  ;imprimirDigito [meu_array+4h] ; meu_array[4h]
        
end main