;15. Read from the standard input several numbers, in base 2. Print on the screen these numbers in base 10.

assume cs:code, ds:data

data segment public

;maxS db 100
;lenS db ?
;s dw 100 dup(?)
s dw 1001b,1001b,1010b,1011b,11111111b
final_sir label word
msg db 'Give numbers in base 2: $'
new db 10,13,'$'

data ends

code segment public
extrn proc2:proc
start:
	mov ax,data
	mov ds,ax
	
	;Afisam mesajul pentru a introduce numerele
	;mov ah,09h
	;mov dx,offset msg
	;int 21h
	
	;Citim un sir de numere
	;mov ah,0ah
	;mov dx,offset maxS
	;int 21h
	
	mov si,offset s
	cld
	
	bucla:
		cmp si, offset final_sir
		je final
		lodsw
		call proc2
		mov dl,' '
		mov ah,02h
		int 21h
	jmp bucla
	
	final:
		mov ax,4c00h
		int 21h
	
	code ends
	end start
		