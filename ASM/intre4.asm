;5. Sa se afiseze ora sistem curenta sub forma hh:mm si sa se specifice cu sirul
; 'AM' sau 'PM' daca este antemeridian sau postmeridian.

assume cs:code, ds:data

data segment

am db ' AM$'
pm db ' PM$'
hh db 2 dup(?),':$'
mm db 2 dup(?),'$'
zece db 10

data ends

code segment
start:
	mov ax, data
	mov ds, ax
	
	mov ah, 2ch
	int 21h; ch-hours, cl-minutes, dh-seconds, dl-hundredths of seconds
	
	mov al,cl
	mov ah,0
	div zece
	add ah,'0'
	mov mm[1],ah
	add al,'0'
	mov mm[0],al
	
	
	
	cmp ch,12
	ja et2
	
	et1:
		mov al,ch
		mov ah,0
		div zece
		add ah,'0'
		mov hh[1],ah
		add al,'0'
		mov hh[0],al
        
		mov ah,09h
		mov dx, offset hh
		int 21h	

		mov dx, offset mm
		int 21h
		
		mov dx, offset am
		int 21h
		
		jmp final
	
	
	et2:
		sub ch,12
		mov al,ch
		mov ah,0
		div zece
		add ah,'0'
		mov hh[1],ah
		add al,'0'
		mov hh[0],al
        mov ah,09h
		mov dx, offset hh
		int 21h	
		
		mov dx, offset mm
		int 21h
		
		mov dx, offset pm
		int 21h
		
		jmp final
	
	final:
		mov ax,4c00h
		int 21h
	
	code ends 
	end start