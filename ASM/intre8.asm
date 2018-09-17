;16. Sa se citeasca de la tastatura numele unui fisier. Sa se verifice daca dimensiunea 
;fisierului este multiplu de 13, si in caz negativ sa se completeze fisierul cu un numar 
;minim de octeti 0 astfel incat dimensiunea fisierului sa devina multiplu de 13.

assume cs:code, ds:data

data segment

maxFileLen db 100
len db ?
fileName db 100 dup(?)

msg db 'Dati numele fisierului:$'
msg2 db 'Cant open file$'
msg3 db 'Cant read from file$'
zero db '0'
trei db 13
new db 10,13,'$'

buffer db 100 dup(?),'$'
data ends

code segment
start:

mov ax,data 
mov ds,ax

;Afisam un mesaj smecher
mov ah,09h
mov dx, offset msg
int 21h

;Citim numele fisierului
mov ah,0ah
mov dx,offset maxFileLen
int 21h

;Afisam o linie noua in caz de mesaj de eroare:
mov ah,09h
mov dx,offset new
int 21h

;Transformam numele in asciiz=punem zero la sfarsit :)
mov al,len
xor ah,ah
mov si,ax
mov fileName[si],0

;Deschidem fisierul
mov ah,3dh
mov al,2; deschidem fisierul pentru read/write
mov dx,offset fileName
int 21h; ax-file handle
jc openError

;Citim din fisier cu ajutorul unui buffer
mov bx,ax
mov ah,3fh
mov cx,100
mov dx,offset buffer
int 21h
jc readError
div trei
cmp ah,0
jne nuEMultiplu
jmp final

NuEMultiplu:
	mov al,ah
	mov ah,0
	mov dx,13
	sub dx,ax
	mov cx,dx
	mov si,0
	repeta:
		push cx
		mov cx,1
		mov ah,40h
		mov dx,offset zero
		int 21h
		pop cx
		inc si
		cmp si,cx
		jne repeta
		jmp final
		
		
openError:
	mov ah,09h
	mov dx,offset msg2
	int 21h
	jmp final
	
readError:
	mov ah,09h
	mov dx,offset msg3
	int 21h
	jmp final

final:
	mov ax,4c00h
	int 21h

code ends
end start
