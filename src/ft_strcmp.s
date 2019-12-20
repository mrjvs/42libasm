section .text
	global	_ft_strcmp			; set function as global

_ft_strcmp:
	mov	rax, 0					; set initial index to 0 (and return value
	cmp	rdi, 0					; compare STR1 with NULL pointer
	je	.return					; return the value if NULL pointer
	cmp	rsi, 0					; compare STR2 with NULL pointer
	je	.return					; return the value if NULL pointer
	mov	rbx, 0					; set initial value to 0, to avoid big size comparisions
.loop:	
	mov	bl, byte [rdi+rax]		; move current char into register B
	cmp	bl, byte [rsi+rax]		; compare register B with STR2 char
	jne	.end					; jump to end if not equal
	cmp	bl, byte 0				; compare STR1 char with 0 byte
	je	.end					; jump to end if equal
	cmp [rsi+rax], byte 0		; compare STR2 char with 0 byte
	je	.end					; jump to end if equal
	add	rax, 1					; increment index by one
	jmp	.loop					; jump back to start of loop
.end:
	mov	rcx, 0					; clean register C
	mov	cl, byte [rsi+rax]		; move STR2 into register C
	sub	rbx, rcx				; subtract register C from register B into register B
	mov	rax, rbx				; move register B value to return value
.return:
	ret							; return
