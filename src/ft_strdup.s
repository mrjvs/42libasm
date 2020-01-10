section .text
	global	_ft_strdup			; set function as global
	extern	_ft_strlen
	extern	_malloc

_ft_strdup:
	push	rdi					; add new parameter to stack
	call	_ft_strlen			; call strlen
	pop		rdi					; pop parameter

	push	rdi					; add new parameter to stack
	mov		rdi, rax			; set parameter to string length
	add		rdi, 1				; increment length for 0 char
	call	_malloc				; call malloc
	pop		rdi					; pop parameter
	cmp		rax, 0				; check if malloc return is NULL pointer
	je		.return				; return NULL if malloc failed

	mov		rcx, 0				; initialize to 0
.loop:	
	mov		bl, BYTE [rdi+rcx]	; copy SRC char into register B
	mov		[rax+rcx], BYTE bl	; copy register B into OUT
	cmp		bl, BYTE 0			; compare register B with 0 byte
	je		.return				; jump to return if true
	add		rcx, 1				; increment index
	jmp		.loop				; jump back to start of loop
.return:
	ret							; return
