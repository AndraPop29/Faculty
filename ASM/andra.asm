; (a*a+b)/(b+b)+c
ASSUME cs: code, ds:data 
data SEGMENT 
a dw 1; 
b db 2; 
c dd 3; 
x dd ?
y dw ?
data ENDS

code SEGMENT 
start: 
mov ax,data 
mov ds,ax

mov ax,a;
mul a;	dx:ax=a*a
mov bl,b;
mov bh,0;
add ax,bx;  dx:ax=(a*a+b)

mov bl,b;
add bl,b;
mov bh,0;
mov y,bx;  y=(b+b)

div y;	ax=(a*a+b)/(b+b)
mov dx,0;
mov bx,word ptr c;
mov cx,word ptr c+2;   cx:bx=c	
add ax,bx;
adc dx,cx;  dx:ax= dx:ax + cx:bx

mov ax,4C00h 
int 21h 
code ENDS 
END start
