;Sa se transforme un numar din baza 2 in baza 10 si sa se afiseze pe ecran rezultatul

assume cs:code, ds:data

data segment

a dw 1000b
rez dw ?
doi db 2
zece dw 10

data ends

code segment

afisare10 proc
	mov cx,0
	repeta10:
		mov dx,0
		div zece
		push dx
		inc cx
		cmp ax,0
		jne repeta10
	repetaAfis:
		pop dx
		add dl,'0'
		mov ah,02h
		int 21h
	loop repetaAfis
	ret
afisare10 endp
start:
	mov ax,data
	mov ds,ax
	
	mov dx,0
	mov bx,a
	mov ax,1
    mov rez,0

bucla:
    
	shr bx,1
	jc unu
	inc dx
	cmp bx,0
	jne bucla
	


Afis:
	mov ah,09h
	mov dx,offset rez
	int 21h
    
	mov ax,4c00h
	int 21h

unu:
    mov cx,dx
    push dx
	puteri:
    cmp cx,0
    je fin
multi:
mul doi
dec cx
cmp cx,0
jne multi
add rez,ax
mov ax,1
fin:
pop dx
inc dx
cmp bx,0
jne bucla
mov ax,rez
call afisare10
	mov ax,4c00h
	int 21h

code ends 
end start

