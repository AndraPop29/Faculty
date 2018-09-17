; Laborator 8 - intreruperi
; 1. Se da un sir de octeti in segmentul de date. Sa se afiseze elementele acestui sir 
; la iesirea standard (ecran) in baza 2.

assume cs:code, ds:data

data segment
s db 16,32,33,127,-2
l EQU $-s
doi dw 2; for dividing a dd by 2
new db 10,13,'$'; new line on the screen
data ends

code segment

afisare proc

	mov cx,0
	repeta:
		mov dx,0
		div doi
		push dx
		inc cx
		cmp ax,0
	jne repeta
	
	afis:
		pop dx
		add dl,'0';adaugam codul ascii a lui 0 pt a transforma in caracte
		mov ah,02h
		int 21h
	loop afis
	ret
afisare endp

start:
	mov ax,data
	mov ds,ax
    mov si,0
	repeta2:
		mov al,s[si]
		mov ah,0
		call afisare
		mov ah,09h
		mov dx,offset new
		int 21h
		inc si
		cmp si,l
	jb repeta2 
    
mov ax,4C00h
int 21h
code ends
end start
    	
		
