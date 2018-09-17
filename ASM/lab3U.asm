; (a*a+b)/(b+b)+c
ASSUME cs: code, ds: data
data segment
a DW 2
b DB 1
C DD 1
x DW ?

data ends

code segment
start:
mov ax,data 
mov ds,ax

mov bh,0
mov bl,b
add bl,b
mov x,bx
mov ax,a
mul a
;dx:ax=a*a
mov bl,b
mov bh,0
mov cx,0

add ax,bx
adc dx,cx; dx:ax=a*a+b=2*2+3=7
div x
mov dx,0

mov bx, word ptr c
mov cx,word ptr c+2; dx:ax=c

add ax,bx
adc dx,cx;the final result is in dx:ax

mov ax,4C00h
int 21h
code ends
end start