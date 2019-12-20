section .text
	global	_ft_strcpy			; set function as global

_ft_strcpy:
	mov rax, 0
	cmp	rdi, 0					; compare DST with NULL pointer / original strlen segfaults
	je	.return					; return the value if NULL pointer
	cmp	rsi, 0					; compare SRC with NULL pointer / original strlen segfaults
	je	.return					; return the value if NULL pointer
	mov	rax, rdi				; set return value to DST
.loop:	
	mov	bl, byte [rsi]			; copy SRC char into register B
	mov	[rdi], byte bl			; copy register B into DST
	cmp	bl, byte 0				; compare register B with 0 byte
	je	.return					; jump to return if true
	inc	rdi						; increment pointer of DST
	inc rsi						; increment pointer of SRC
	jmp	.loop					; jump back to start of loop
.return:
	ret							; return
