;2. Sa se citeasca cate un caracter de la tastatura, fara ecou.
; Daca este cifra, sa se tipareasca pe ecran, daca este caracterul '$', se termina programul, 
; in orice alta situatie se adauga caracterul intr-un buffer care se va tipari in final pe ecran.

assume cs:code, ds:data

data segment

s db 100 DUP(?)
new db 10,13,'$'

data ends

code segment
start:

	mov ax,data
	mov ds,ax
	mov si,0
	mov ah,08h
	int 21h
	repeta:
		cmp al,'$'
		je final
		
		cmp al,'9'
		ja et1
		
		cmp al,'0'
		jb et1
		
		mov ah,05h
		mov dl,al
		int 21h
		
		jmp et
		et:
			mov ah,08h
			int 21h
			jmp repeta
		et1:
			mov s[si],al
			inc si
	
		final:
			mov s[si],al
		
			mov ah,09h
			mov dx, offset s
			int 21h
		
mov ax, 4C00h
int 21h
code ends
end start


