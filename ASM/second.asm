;10. Print of the screen, for each number between 32 and 126,
;the value of the number (in base 16) and the character whose ASCII code the number is.

assume cs:code, ds:data
data segment PUBLIC
	hex db 16
	hex_table db '0123456789ABCDEF'	
data ends 

code segment PUBLIC
PUBLIC base16
	
base16 PROC
	;we define a procedure which prints the value of the AL register in base 16 on the screen
	mov cx, 0
	repeat:
		mov ah, 0
		div hex
		
		mov bl, ah
		mov bh, 0
		push bx
		;we convert ah to bx, a word, so that we can push it on the stack
		;when popped, the numbers from the stack will be in reverse order, the correct order to form the hexa number
		
		inc cx
		cmp al, 0
		ja repeat
		
	scoate:
		pop ax
		;al contains the actual digit (from 0 to 15)
		lea bx, hex_table
		xlat hex_table
		mov dl, al
		mov ah, 02h
		int 21h
		loop scoate
		
	ret
base16 ENDP

code ends
end

	
		