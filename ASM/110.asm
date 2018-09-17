;lab 10
;1. Se da un numar a reprezentat pe 16 biti fara semn. Se cere sa se afiseze reprezentarea in baza 16 a lui a, precum si 
;rezultatul permutarilor circulare ale cifrelor sale.

assume cs:code, ds:data
data segment
	a db 23
	tabela db '0123456789ABCDEF'
	newLine db 10,13, '$'
	msg db 'numarul in baza 16 este: $'
data ends

code segment

afisareBaza16 proc
	mov cx, 4
	repeta16:
		mov dx, 0
		push cx
		mov cx,4
		repeta4:
			rol ax, 1
			rcl dx, 1
		loop repeta4
		pop cx
		push ax
		mov al, dl
		lea bx, tabela
		xlat tabela
		
		mov dl, al
		mov ah, 02h
		int 21h
		pop ax
	loop repeta16
	ret
afisareBaza16 endp

afisare proc
	mov ah, 09h
	int 21h
	ret
afisare endp

start:
	
	mov ax, data
	mov ds, ax

	lea dx, msg
	call afisare
	
	mov al, a
	mov ah, 0
	call afisareBaza16
	
	mov ax, 4c00h
	int 21h

code ends
end start