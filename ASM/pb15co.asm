assume cs:code,ds:data
data segment
a db 3
b db 5
c db 2
e dd 6
x dd ?
data ends
code segment
start:
mov ax,data
mov ds,ax
mov al,c
mov bl,3
imul bl;AX=3*c=6
cwd
mov bx,ax
mov cx,ax;CX:BX=3*c=6
mov al,a
mov cl,b
imul cl;AX=a*b
mov dx,25
imul dx;DX:AX=a*b*25
add bx,ax
adc cx,dx;CX:BX=a*b*25+c*3
mov al,a
mov bl,b
adc al,bl;AL=a+b
cbw
mov dx,ax
mov ax,bx
mov bx,dx
mov dx,cx
idiv bx
mov bx,word ptr e
mov cx,word ptr e+2
add ax, bx
adc dx,cx
mov word ptr x,ax
mov word ptr x+2,dx
mov ax,4c00h
int 21h
code ends
end start
