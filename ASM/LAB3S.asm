; (a*a+b)/(b+b)+c
assume cs:data, ds:data
data segment
a dw 2
b db 1
c dd 1
x dw ?
y dw ?
data ends

code segment
start:
mov ax,data
mov ds,ax

mov bl,b
cbw
;mov cl,b
;cbw
;add bx,cx;bx=b+b=2
add bl,b
mov x,bx

mov bl,b
cbw
cwd; cx:bx=b
mov ax,a
cwd; dx:ax=a
imul a; dx:ax=a*a
add ax,bx;
adc dx,cx; dx:ax=a*a+b=5
idiv x; ax=dx:ax/x
      ; dx=dx:ax%x
mov bx,ax
cwd;cx:bx=ax=2

mov ax, word ptr c
mov dx, word ptr c+2; dx:ax=c

add ax,bx
adc dx,cx; the final result is in dx:ax



mov ax,4C00H
int 21h
code ends
end start