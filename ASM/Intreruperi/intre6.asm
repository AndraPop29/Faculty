;14. Sa se citeasca de la tastatura un cuvant si un nume de fisier. 
;Sa se afiseze daca cuvantul exista sau nu in fisierul dat.

assume cs:code, ds:data

data segment

maxCuvName db 50
lenCuv db ?
cuv db 50 dup(?)

maxFileName db 100
lenFile db ?
fileName db 100 dup(?)

buffer db 100 dup(?),'$'

msg db 'Enter file name:$'
msg2 db 'Enter word name:$'
readingError db 'Cannot read from file$'
openingError db 'Cannot open file$'
word_found db 'We found it yaaaaay$'
not_found db 'Go look elsewhere mothafuckaaaaa$'
new db 10,13,'$'

found db ?

data ends


code segment
start:
	mov ax,data
	mov ds,ax
	
	;Afiisam mesaj pentru introducerea numelui fisierului
	mov ah,09h
	mov dx,offset msg
	int 21h
	
	;Citim numele fisierului
	mov ah,0ah
	mov dx,offset maxFileName
	int 21h
	
	;Transformam numele fisierului intr-un sir ASCIIZ
	mov al,lenFile
	xor ah,ah
	mov si,ax
	mov fileName[si],0
	
	;Deschidem fisierul pentru citire
	mov ah, 3dh
	mov al,0
	mov dx,offset fileName
	int 21h
	jc openError
	
	;Citim din fisier folosind un buffer
	mov bx,ax; salvam identificatorul fisierului in bx
	mov ah,3fh
	mov cx,100
	mov dx,offset buffer
	int 21h
	jc readError
	mov si,ax
	mov buffer[si],'$'
	
	mov cx,ax
	
	;Afisam o linie noua
	mov ah,09h
	mov dx, offset new
	int 21h
	
	;Afisam mesaj pentru introducerea numelui cuvantului
	mov ah,09h
	mov dx,offset msg2
	int 21h
	
	;Citim numele cuvantului
	mov ah, 0ah
	mov dx,offset maxCuvName
	int 21h
	
	;Afisam o linie noua
	mov ah,09h
	mov dx, offset new
	int 21h
	
	mov si,0
	mov bx,0
	
	repeta:
		mov al,buffer[si]
		cmp al,cuv[bx]
		jne notEqual
		
		inc bx
		
		mov al,lenCuv
		mov ah,0
		
		cmp ax,bx
		jne continuam
		
		mov found,1
		cmp found,1
		je Break
		
		continuam:
			inc si
		
		notEqual:
			mov bx,0
	
    loop repeta	
	
    mov ah,09h
    mov dx,offset not_found
	int 21h
	jmp final
	
	Break:
		mov ah,09h
		mov dx,offset word_found
		int 21h
		jmp final
	
	openError:
		mov ah,09h
		mov dx, offset openingError
		int 21h
		jmp final
	
	readError:
		mov ah,09h
		mov dx, offset readingError
		int 21h
		
	final:
		mov ax,4c00h
		int 21h
	code ends
	end start