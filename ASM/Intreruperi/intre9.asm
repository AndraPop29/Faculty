; Citeste de la tastatura un string, concateneaza-i extensia ".txt" si creaza un fisier cu acest nume (ex. citesti "abc", creezi fisierul "abc.txt")

assume cs:code, ds:data, es:data

data segment

nume db 10,?,10 dup (?)
ex db 5,?,5 dup(?)
msg db 'Dati stringul: $'
msg2 db 'Dati extensia: $'
new db 10,13,'$'

data ends

code segment

start:
mov ax,data
mov ds,ax
mov es,ax

;Mesajul
mov ah,09h
mov dx,offset msg
int 21h

;Citim stringul cu functia 0ah
mov ah,0ah
mov dx, offset nume
int 21h

;Linie noua
mov ah,09h
mov dx,offset new
int 21h

;Mesajul
mov ah,09h
mov dx,offset msg2
int 21h

;Citim extensia
mov ah,0ah
mov dx,offset ex
int 21h

;Punem . dupa nume
mov al,byte ptr nume[1]
mov ah,0
mov si,ax
mov nume[si],'.'
inc si
mov bp,2
mov cl,3
xor ch,ch
bucla:
	mov al,ex[bp]
	mov nume[si],al
	inc si
	inc bp
loop bucla

mov cx,00h
mov ah,3ch
mov dx,offset nume[2]
int 21h

mov ax,4c00h
int 21h

code ends
end start

	
