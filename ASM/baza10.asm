assume cs:code, ds:data

data segment public
	
data ends

code segment public
public baza10; functia baza10 este vizibila si in alte module

baza10:
	;intrare: ax=numarul de tiparit
	;tipareste numarul din ax in baza 10
	;nu modifica restul registriilor


mov dx,1
mov bx,ax
mov ax,0

shr bx,1
jc one

mov rez,ax

	
bucla:
    
	shr bx,1
	jc unu
	inc dx
	
	cmp bx,0
	jne Bucla	
    
unu:
    mov cx,dx
	
	
loop unu

inc dx

add rez,ax

	
one:
	mov ax,1
	mov rez,ax
	jmp bucla
		





	

code ends 
end 


