assume cs: code, ds:data
data segment
a db 3
b db 5
c db 2
x db ?
data ends
code segment
start:
mov ax,data
mov ds,ax
mov bl,a
add bl,b
sub bl,c
mov x,bl
mov ax,4C00h
int 21h
code ends
end start