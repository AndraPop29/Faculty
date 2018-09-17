; Se da un sir de caractere format din litere mici. Sa se transforme in literele mari corespunzatoare

assume cs:code, ds:data
data segment
s db 'a','v','x','a','c'
l EQU $-s
d db l DUP(?)
data ends

code segment
mov ax, data
mov ds,ax
mov cx,l
mov si,0
jcxz Sfarsit; vom folosi instructiunea loop, care executa o bucla de cx ori, motiv pt care val din cx trebuie sa fie diferita de 0 cand intram in bucla
            ;daca cx=0 bucla se execut de 65535 ori datorita decrementarii(cx va fi -1)

Repeta:
mov al, byte ptr s[si]; in al se copiaza octetul care se afla in seg de date la offset-ul lui s plus si octeti
                      ; obtinem octetul de rang si din sir
					  ; in acest moment in al avem codul ascii al unei litere mici din sirul s
					  ; datorita tipului byte al variabilei s este corect si: mov al, s[si]
					  ; daca era sir de cuvinte: mov al, s[si]=eroare sintactica
sub al,'a'-'A'
mov d[si], al
inc si
loop Repeta

Sfarsit:
mov ax,4C00h
int 21h

code ends
end start


