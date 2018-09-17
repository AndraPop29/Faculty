assume cs:code, ds:data

data segment
s dw ?
n db 3
a dw ?
msg db 'Sirul este: $'
zece db 10

data ends

code segment
start:

mov ax,data
mov ds,ax

mov al,1
mov ah,0
mov bl,1
mov bh,0
mov cl,n
mov ch,0
repeta:
mov a,bx
mul a
add bl,1
loop repeta; de cx(=n) ori


mov cx,0
pregatire:
div zece; ah-rest
mov dl,ah
mov dh,0
push dx
mov ah,0
inc cx
cmp al,0

jne pregatire

mov si,0


construire:
pop dx
add dl,'0'
mov s[si],dx
mov al,dl
xor ah,ah
inc si
loop construire

mov s[si],'$'
mov ah,09h
mov dx,offset msg
int 21h
afisare:
mov ah,09h
mov dx,offset s
int 21h

mov ax,4c00h
int 21h

code ends
end start


