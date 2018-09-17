
assume cs:code, ds:data

data segment public



rez dw ?
doi db 2
zece dw 10
zeceb db 10

data ends

code segment public
public proc2
public afisare10

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
proc2 proc
   
	
	mov dx,0
    mov rez,0
	mov bx,ax
	mov ax,1
bucla:
    
	shr bx,1
	jc unu
	inc dx
	cmp bx,0
	jne bucla


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
jmp over
fin:
add rez,ax
over:
pop dx
inc dx
cmp bx,0
jne bucla
mov ax,rez
call afisare10
ret



proc2 endp

code ends 
end 

