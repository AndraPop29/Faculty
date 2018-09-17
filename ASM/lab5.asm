ASSUME cs: code, ds:data 
data SEGMENT 
A DW 1010101010101010b
b DW ?
data ENDS

code SEGMENT 
start: 
mov ax,data 
mov ds,ax

mov ax,a
or ax,1110000000000000b; separam biti 13-15
mov cl,13; 
roR ax,cl; mutam biti 13-15 pe 0-2 ... care este echivalent cu convertirea bitilor 13-15 in zecimal
mov cl,al;
mov ax,a;
roL ax,cl; rotim ax la stanga cu zecimal(cl)
mov b,ax; rezultatul in mutam in b


mov ax,4C00h 
int 21h 
code ENDS 
END start