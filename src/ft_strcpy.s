section .text
	global	_ft_strcpy			; set function as global

_ft_strcpy:
	mov rax, 0
	mov	rax, rdi				; set return value to DST
.loop:
	mov	bl, byte [rsi]			; copy SRC char into register B
	mov	[rdi], byte bl			; copy register B into DST
	cmp	bl, byte 0				; compare register B with 0 byte
	je	.return					; jump to return if true
	add	rdi, 1 					; increment pointer of DST
	add rsi, 1					; increment pointer of SRC
	jmp	.loop					; jump back to start of loop
.return:
	ret							; return
