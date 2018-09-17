assuma cs:data, ds: data
data segment
a db 1
b db 2
c dd 3
d db 2
data ends

code segment
start:
mov ax,data
mov ds,ax

mov al,a; ax=a*b
mul b
mov bx,100
mul ax

mov ax,4C00h
int 21h
code ends
end start