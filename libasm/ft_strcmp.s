section .text
	global _ft_strcmp

_ft_strcmp:	mov rax, 0

circle:		movsx rcx, byte [rsi + rax]
			movsx rdx, byte [rdi + rax]
			cmp rcx, rdx
			jl finish_up
			jg finish_low
			cmp rcx, 0
			jz finish
			cmp rdx, 0
			jz finish
			inc rax
			jmp circle

finish:		mov rax, 0
			ret

finish_up:	cmp rcx, 0
			jl finish_low
			mov rax, 1
			ret

finish_low:	cmp rdx, 0
			jl finish_up
			mov rax, -1
			ret