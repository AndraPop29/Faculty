assume cs:code, ds:data

data segment public
	no db 32
data ends

code segment
EXTRN base16:PROC

start:
	mov ax, data
	mov ds, ax
	
	repeta:
		mov al, no
		call base16		
		
		;print a space between the numbers
		mov dl, ' '
		mov ah, 02h
		int 21h
		
		add no, 1 
		cmp no,126
		jng repeta
	
	mov ax,4c00h
	int 21h
code ends
end start

	