; Sa se citeasca de la tastatura numele unui fisier. Sa se afiseze acest fisier pe ecran.

assume cs:code, ds:data

data segment

maxFileLen db 100
fileLen db ?
fileName db 100 dup(?)
buffer db 100 dup(?),'$'

openingError db 'Fisierul nu se poate deschide$'
readingError db 'Nu se poate citi din fisier$'
msg db 'Dati numele fisierului:$'
new db 10,13,'$'

data ends

code segment
start:
	mov ax,data
	mov ds,ax
	
	;Mesaj pentru introducerea numelui fisierului
	mov ah,09h
	mov dx,offset msg
	int 21h
	
	;Citim numele fisierului
	mov ah,0ah
	mov dx,offset maxFileLen
	int 21h
	
	;Il transformam in sir ASCIIZ
	mov al,fileLen
	xor ah,ah
	mov si,ax
	mov fileName[si],0
	
	;Afisam o linie noua
	mov ah,09h
	mov dx,offset new
	int 21h
	
	;Deschidem fisierului
	mov ah,3dh
	mov al,0
	mov dx,offset fileName
	int 21h
	jc openError
	
	mov bx,ax; salvam in bx identificatorul fisierului
	
	;Citim din fisier cu ajutorul unui buffer:
	repeta:
		mov ah,3fh
		mov cx,100
		mov dx,offset buffer
		int 21h
		jc readError; daca nu avem eroare in ax se salveaza numarul de bytes cititi
		mov si,ax
		mov buffer[si],'$'
		
		mov ah,09h
		int 21h
		
		cmp si,100
		je repeta; daca am citit 100 de octeti inseamna ca nu am terminat de citit
	
	jmp final
		
	;Eroare la deschidere
	openError:
		mov ah,09h
		mov dx,offset openingError
		int 21h
		jmp final
		
	;Eroare la citire
	readError:
		mov ah,09h
		mov dx,offset readingError
		int 21h
		jmp final
		
	final:
		mov ax,4c00h
		int 21h
	
	code ends
	end start