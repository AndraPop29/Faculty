; 13.Sa se citeasca de la tastatura un nume de fisier si un nume de director.
; Sa se afiseze un mesaj corespunzator daca fisierul exista sau nu in
; directorul dat.

assume cs:code,ds:data

data segment
mesaj1 db 10,13,'Dati numele fisierului: $',10,13
mesaj2 db 10,13,'Dati numele directorului: $',10,13
file db 30 dup(?)
dir db 30 dup(?)
dnf db 10,13,'Directory not found.$',10,13
found db 10,13,'The file was found.$',10,13
fnf db 10,13,'File not found.$',10,13
a dw ?
data ends

code segment
start:
mov ax,data
mov ds,ax
mov si,0

mov ah,09h
mov dx,offset mesaj1
int 21h

mov ah,01h; read a character from the keyboard, al=character read
int 21h
bucla1:
mov file[si],al
inc si
int 21h
cmp al,13
je sf1

jmp bucla1
sf1:
mov file[si],0

mov si,0
mov ah,09h
mov dx,offset mesaj2
int 21h

mov ah,01h
int 21h
bucla2:
mov dir[si],al
inc si
int 21h
cmp al,13
je sf2
jmp bucla2
sf2:
mov dir[si],0

;schimbam directorul in cel pe care l-am citit
mov ah,3Bh
mov dx,offset dir
int 21h
jc dirnotfound

;cautam fisierul
mov ah,4Eh
mov cx,27h
mov dx,offset file
int 21h
mov a,ax ; a=codul de eroare
jc eroare
mov ah,09h
mov dx,offset found
int 21h
jmp sf

dirnotfound:
mov ah,09h
mov dx,offset dnf
int 21h
jmp sf

eroare:
cmp a,2
je filenotfound
cmp a,3
je filenotfound
cmp a,18
je filenotfound
jmp sf

filenotfound:
mov ah,09h
mov dx,offset fnf
int 21h

sf:
mov ax,4C00h
int 21h
code ends
end start