assume cs:code, ds:data

data segment
s db ?
n db 3
a db ?
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
mov a,bl
mul a
add bl,1
loop repeta; de cx(=n) ori


mov cx,0
pregatire:
div zece; ah-rest
mov dl,ah
mov dh,0
push dl
mov ah,0
inc cx
cmp al,0

jne pregatire

mov si,0


construire:
pop dl
add dl,'0'
mov s[si],dl
mov al,dl
xor ah,ah
inc si
loop construire

afisare:
mov ah,09h
mov dx,offset s
int 21h

mov ax,4c00h
int 21h

code ends
end start


