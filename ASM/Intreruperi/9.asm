; 9.Sa se afiseze numele si continutul directorului curent.

assume cs:code,ds:data

data segment
nume db 64 dup(?),'$'
fis db '*.*'
fnf db 'File not found.$'
pnf db 'Path not found.$'
nmf db 'No more files to be found.$'
buffer db 43 dup(?),'$'
fisier db 13 dup(?),'$'
data ends

code segment
start:
mov ax,data
mov ds,ax

; returneaza numele directorului curent
mov ah,47h ; dl->numarului driver-ului
mov dl,0 ; in dl se pune 0 adica nu se stie driver-ul curent
mov si,offset nume ;in ds:si->numele directorului curent
int 21h

mov ah,09h
mov dx,offset nume
int 21h

mov fis[3],0 ;fac sir
mov ah,1ah ; 1Ah seteaza DTA (disk transfer adress)
mov dx,offset buffer
int 21h
mov ah,4Eh ; gaseste primul fisier din direstorul curent
mov dx,offset fis
mov cx,27h ;
int 21h
jc eroare
mov si,0
mov cx,13
mov di,30
iar:
mov bl,buffer[di]
mov fisier[si],bl ; la offset-ul 1Eh se pune numele si extensia fisierului
inc si
inc di
loop iar
mov si,0
mov ah,09h
mov dx,offset fisier
int 21h

bucla:
mov ah,1Ah
mov dx,offset buffer
mov ah,4Fh
mov dx,offset fis
mov cx,27h
int 21h
jc nomorefiles
mov si,0
mov cx,13
mov di,30
iar1:
mov bl,buffer[di] 
mov fisier[si],bl
inc si
inc di
loop iar1
mov ah,09h
mov dx,offset fisier
int 21h
je sf
jmp bucla

eroare:
cmp ax,2
je filenotfound
cmp ax,3
je pathnotfound
cmp ax,18
je nomorefiles
jmp sf
filenotfound:
mov ah,09h
mov dx,offset fnf
int 21h
jmp sf

pathnotfound:
mov ah,09h
mov dx,offset pnf
int 21h
jmp sf

nomorefiles:
mov ah,09h
mov dx,offset nmf
int 21h
sf:
mov ax,4C00h
int 21h
code ends
end start

