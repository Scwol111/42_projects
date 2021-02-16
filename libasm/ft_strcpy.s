section .text
	global _ft_strcpy

_ft_strcpy:	mov rax, 0

circle:		mov cl, byte [rsi + rax]
			cmp cl, 0
			jz finish
			mov byte[rdi + rax], cl
			inc rax
			jmp circle

finish:		mov byte [rdi + rax], 0
			mov rax, rdi
			ret
