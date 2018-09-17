;Se da un sir de caractere. Sa se determine numarul vocalelor din sir
;Sol: Vom folosi un sir auxiliar care va contine toate vocalele

assume cs:code, ds:data

data segment
s db 'Acesta este sirul sursa'
l EQU $-s
vocale db 'aeiouAEIOU'
lvoc EQU $-vocale
nr db ?
data ends

code segment
start:
mov ax, data
mov ds,ax
mov es,ax
mov cx,l
lea si,s
cld
mov nr,0
Repeta:
lodsb
lea di,vocale
push cx
mov cx,lvoc
repne scasb; scasb compara valoarea din al cu octetul de la adresa es:di, setand flagurile corespunzator rezultatelor(la fel ca si cmp)
           ;di fiind apoi incrementat deoarece valoarea flagului de directie este 0
		   ; repne provoaca executia repetata a intrusctiunii scasb pana cand cx devine 0 sau pana cand apare o potrivire(ZF=1)
jnz NuEVocala
inc nr
NuEVocala:
pop cx
loop Repeta
Sfarsit:
mov ax,4C00h
int 21h
code ends
end start


