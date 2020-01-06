section .text
	global	_ft_list_push_front		; set function as global
	extern	_malloc

_ft_list_push_front:
	enter 0,0
	cmp rdi, 0						; check if NULL pointer, return if it is
	je .return

	push rdi						; add new parameter to stack
	push rsi
	mov rdi, 16						; set parameter to 16, the size of the list item
	call _malloc					; call malloc
	pop	rsi
	pop rdi							; pop parameter
	cmp	rax, 0						; check if malloc return is NULL pointer
	je	.return						; return NULL if malloc failed

	mov QWORD [rax], rsi			; move data pointer to new list->data
	mov rcx, [rdi]					; move list pointer to register C
	mov QWORD [rax+8], rcx			; move register C to new list->next

	mov	QWORD [rdi], rax			; move new list item to input

.return:
	leave
	ret								; return
