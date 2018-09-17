;6. Sa se implementeze un program de autentificare. Programul are definit in 
; segmentul de date un sir de caractere numit 'parola'. 
; Programul va cere utilizatorului sa introduca parola de la tastatura si va verifica 
; daca aceasta este identica cu sirul 'parola' din segmentul de date si va afisa un mesaj corespunzator. 
; Programul tot cere utilizatorului parola, pana cand acesta o ghiceste.

assume cs:code, ds:data, es:data

data segment

parola db 'abcd$'
len EQU $-parola
mesaj db 'parola:$'
maxsir db 100 
lsircitit db ?
sircitit db 100 dup(?)
new db 10,13,'$'
a db 'parola corecta$'

data ends

code segment
start:
	mov ax,data
	mov ds,ax
	mov es,ax
	
	repeta:
		;afisare mesaj
		mov ah,09h
		mov dx,offset mesaj
		int 21h
		
		;introducere parola
		mov ah,0ah
		mov dx,offset maxsir
		int 21h
		
		;punem caracterul de sfarsit de sir
		mov bl,lsircitit
		mov bh,0
	    mov sircitit[bx],'$'
		
		;linie noua
		mov ah,09h
		mov dx,offset new
		int 21h
		
		mov cx,len
		cld
		mov si,offset parola
		mov di,offset sircitit
		repeta2:
			cmpsb
			jne repeta
		loop repeta2;scade cx si cresc si si di
		
		corecta:
			;afisam o linie noua
			mov ah,09h
			mov dx,offset new
			int 21h
			
			;afisam mesajul 'parola corecta'
			mov ah,09h
			mov dx,offset a
			int 21h
		
		mov ax,4c00h
		int 21h
		
		code ends
		end start