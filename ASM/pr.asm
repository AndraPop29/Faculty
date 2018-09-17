ASSUME CS:code, DS:data

data segment
startmessage db "Guve the name of the file: $"
fname db 15,?,15 DUP(?)
lung db ?
buffer db 2000 DUP(?)
errormessage db "The file could not be opened! $"
hexa db 16
data ends

code segment
start:
mov AX,data
mov DS,AX

;We print on the screen the start message for giving the filename

mov DX, offset startmessage
mov AH, 09h
int 21h

;We read the name of the file
	
mov DX, offset fname
mov AH, 0Ah
int 21h

;We transform the name of the file in an ASCII code by putting a zero at the ends
	
mov AL, fname[1]
mov AH, 0
mov SI, AX
mov fname[SI + 2], 0

;We open the file

clc
mov AX, 3D00h
mov DX, offset fname[2]
int 21h
	
jc error1
	
jmp noterror
	
error1:
	;new_ln
	mov DX, offset errormessage
	mov AH, 09h
	int 21h
	mov AX, 4C00h
	int 21h
	
noterror:
	;We read from file
	mov BX, AX
	mov AH, 3Fh
	mov CX, 20000
	mov DX, offset buffer
	int 21h
	
	mov SI, AX
	mov buffer[SI], '$'
	
	
	mov SI,0
	mov DI,0
	mov DL,2
	div DL
	mov AH,0
	mov CX,AX
	
		mov AL,buffer[SI]    ;AL=17
		mov DL,30h 
		sub AL,DL
		mov DL,10
		mul DL
		mov AH,0
		mov BX,AX
		mov AX,0
		mov AL,buffer[SI+1]
		mov AH,0
		mov DL,30h
		sub AL,DL
		ADD AX,BX
		;division:
			;mov AH,0
			;div hexa 			;AL=1
			;mov BL,AL
			;mov AH,0
			;push AX
			;mov AL,BL
			;cmp AL,hexa
			;jg division
			
		
		;mov AH,0
		;push AX
		;pop AX
		;mov BX,AX
		
		
		mov AH, 09h
		mov DX, offset AX
		int 21h

;closing the file


mov Ah, 3Eh
int 21h

mov AX, 4C00h
int 21h
code ENDS
END start
