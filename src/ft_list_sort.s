section .text
	global	_ft_list_sort		; set function as global

_ft_list_sort:
	enter	0, 0
	cmp		rdi, 0				; check if list is NULL pointer, return if it is
	je		.return
	mov		r10, rdi			; save parent pointer to reg 10
	mov		r8, rdi				; save beginning of the list
	mov		rdi, [rdi]			; derefrence list once
	cmp		rdi, 0				; check if list item is NULL pointer, return if it is
	je		.return
	mov		r12, [rdi+8]		; save next list item
	cmp		r12, 0				; check if next list item is NULL pointer, return if it is
	je		.return

	mov		r9, 0				; set list size counter to 0
	mov		rax, rdi			; move derefrenced list to rax to count
.sizeloop:
	cmp		QWORD [rax+8], 0	; check if list->next is NULL pointer, return if it is
	je		.listloop
	inc		r9					; increment counter by 1
	mov		rax, [rax+8]		; set rdi to next list item
	jmp		.sizeloop			; jump to start of loop

.listloop:
	push	rdi					; setup stack for function call
	push	rsi
	push	r9
	push	r10
	push	r8
	push	r12

	mov		rax, rsi			; setup args for function call
	mov		rdi, [rdi]
	mov		rsi, [r12]
	call	rax					; call compare function

	pop		r12					; clean stack from function call
	pop		r8
	pop		r10
	pop		r9
	pop		rsi
	pop		rdi

	cmp		eax, 0				; check compare return value
	jl		.skipswap			; skip swap if compare > 0

	mov		QWORD [r10], r12	; change pointer to item 1 to item 2
	mov		r11, [r12+8]		; save item 2 next pointer to register 13
	mov		[rdi+8], r11		; move register 13 to item 1 next pointer
	mov		QWORD [r12+8], rdi	; move item 1 pointer to item 2 next pointer
	mov		rdi, r12			; prepare list for next loop
	mov		r12, [rdi+8]

.skipswap:
	mov		r10, rdi			; save parent pointer of next list item
	add		r10, 8

	cmp		QWORD [r12+8], 0	; check if nextlist->next is NULL pointer, return if it is
	je		.endlistloop

	mov		rdi, [rdi+8]		; set rdi to next list item
	mov		r12, [rdi+8]		; set reg 12 to next next list item
	jmp		.listloop			; jump to start of loop

.endlistloop:
	mov		rdi, [r8]			; reset rdi to beginning of list
	mov		r12, [rdi+8]		; reset register 12 to next list item
	mov		r10, r8				; reset register 10 to pointer to parent pointer
	dec		r9					; decrement sort loop counter
	cmp		r9, 1				; check if counter hit bottom
	jg		.listloop			; do list loop if counter did is greater than 1

.return:
	leave
	ret							; return
