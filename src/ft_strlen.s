section .text
	global	_ft_strlen			; set function as global

_ft_strlen:
	mov	rax, 0					; set initial return value to 0
.loop:
	mov	rbx, [rdi+rax]			; move current char into register B
	cmp	bl, 0					; compare register B with 0 byte
	je	.return					; return the value
	add	rax, 1					; increment return value by 1
	jmp	.loop					; jump back to start of loop
.return:
	ret							; return
