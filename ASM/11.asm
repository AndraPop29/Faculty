;11. Two character strings S1 and S2 are given. Obtain the string D which contains all the elements of S1 that do not appear in S2.
;Exemple:
;S1: '+', '4', '2', 'a', '8', '4', 'X', '5'
;S2: 'a', '4', '5'
;D: '+', '2', '8', 'X'

ASSUME CS:code, DS:data

data segment
S1 db '+', '4', '2', 'a', '8', '4', 'X', '5'
l equ $-S1
S2 db 'a', '4', '5'
l2 equ $-S2
D db l dup (?)

data ends

code segment
start:
mov ax, data
mov ds, ax

mov si, -1
mov bp, 0

repeat:

mov bx, -1
inc si
repeat2:

inc bx
mov al, S1[si]
cmp al, S2[bx]
je repeat

cmp bx, l2
jb repeat2

mov D[bp], al
inc bp

cmp si, l
jb repeat

mov ax, 4C00h
int 21h
code ends
end start
