; 11. Se da un sir de dublucuvinte. Sa se obtina sirul format din octetii
; superiori ai cuvintelor inferioare din elementele sirului de dublucuvinte,
; care sunt multiplii de 10. 
; Ex: Se da sirul de dublucuvinte: s dd 12345678h, 1A2B3C4Dh, FE98DC76h 
;  Sa se obtina sirul d db 56h, 3Ch, DCh.


ASSUME cs:code, ds:data
data segment
	sir dd 12345678h, 1A2B3C4Dh, 0FE98DC76h 
	len EQU ($-sir)/4 ;lungimea sirului de dublucuvinte
	len2 equ ($-sir)/2; lungimea sirului de cuvinte
	len3 equ ($-sir); lungimea sirului de octeti
	
	w dw len2 dup(?)
	b db len3 dup(?)
	d db len3 dup(?)
	zece db 10

data ends

code segment
start:
	mov ax,data
	mov ds, ax
	mov es, ax
	
	mov si, offset sir
	mov di, offset w
	mov cx, len
	parsed:
	;parsing the doublewords string
		lodsw
		add si, 2
		stosw
		loop parsed
	
	
	mov si, offset w+1
	mov di, offset b
	mov cx, len
	parsew:
	;parsing the words string
		lodsb
		inc si
		stosb
		loop parsew
	
	
	mov si, offset b
	mov di, offset d
	mov cx, len
	parseb:
	;verify if 
		lodsb
		mov bl, al
		mov ah,0
		div zece
		cmp ah, 0
		jne break
		mov al, bl
		stosb
		break:
		loop parseb
	
	
	mov ax, 4c00h
	int 21h
code ends
end start