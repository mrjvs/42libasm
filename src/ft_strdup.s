extern	_ft_strlen
extern	_malloc

section .text
	global	_ft_strdup			; set function as global

_ft_strdup:
	mov rax, 0					; initalize to 0
	cmp	rdi, 0					; compare SRC with NULL pointer
	je	.return					; return the value if NULL pointer
	mov	rax, rdi				; set return value to DST

	push rdi					; add new parameter to stack
	call _ft_strlen				; call strlen
	pop rdi						; pop parameter

	push rdi					; add new parameter to stack
	mov rdi, rax				; set parameter to string length

	; TODO - increment length for 0 byte

	call _malloc				; call malloc
	pop rdi						; pop parameter

	mov rcx, 0					; initialize to 0
.loop:	
	mov	bl, byte [rdi+rcx]		; copy SRC char into register B
	mov	[rax+rcx], byte bl		; copy register B into OUT
	cmp	bl, byte 0				; compare register B with 0 byte
	je	.return					; jump to return if true
	add	rcx, 1					; increment index
	jmp	.loop					; jump back to start of loop
.return:
	ret							; return
