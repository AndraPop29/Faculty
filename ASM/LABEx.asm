;3. (8-a*b*100+c)/d *UNSIGNED*
assume cs:data, ds: data
data segment
a db 1
b db 2
c dd 3
d db 2
x dd ?
data ends

code segment
start:
mov ax,data
mov ds,ax

mov bx,100
mov al,a; ax=a*b
mov ah,0
mul b
mul bx;dx:ax=a*b*100=200
mov x,


mov ax,4C00h
int 21h
code ends
end start