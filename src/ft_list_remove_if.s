section .text
	global	_ft_list_remove_if	; set function as global
	extern	_free

_ft_list_remove_if:
	enter	0, 0
	cmp		rdi, 0				; check if list is NULL pointer, return if it is
	je		.return
	mov		r10, rdi			; save parent pointer to reg 10
	mov		rdi, [rdi]			; derefrence list once
	cmp		rdi, 0				; check if list item is NULL pointer, return if it is
	je		.return
.loop:

	mov		r11, [rdi]			; move data of current list item to reg 11
	push	rdi					; setup stack for function call
	push	rsi
	push	rdx

	mov		rdi, rsi			; setup args for function call
	mov		rsi, r11
	call	rdx					; call compare function

	pop		rdx					; clean stack from function call
	pop		rsi
	pop		rdi

	cmp		rax, 0				; check compare return value
	jne		.normal				; skip stitching if difference

	mov		r9, [rdi+8]
	mov		QWORD [r10], r9		; stitch list->next to parent pointer

	push	rdi					; setup stack for function call
	push	rsi
	push	rdx
	push	r10

	mov		rdi, r11			; move list data to function arg
	call	_free				; call free

	pop		r10					; clean stack from function call
	pop		rdx
	pop		rsi
	pop		rdi

	jmp		.afterstitch

.normal:
	mov		r10, rdi			; save parent pointer of next list item
	add		r10, 8

.afterstitch:
	cmp		QWORD [rdi+8], 0	; check if list->next is NULL pointer, return if it is
	je		.return


	mov		rdi, [rdi+8]		; set rdi to next list item
	jmp		.loop				; jump to start of loop
.return:
	leave
	ret							; return
