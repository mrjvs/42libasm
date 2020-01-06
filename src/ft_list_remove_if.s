section .text
	global	_ft_list_remove_if		; set function as global
	extern	_malloc

_ft_list_remove_if:
	enter 0, 0
	cmp rdi, 0					; check if NULL pointer, return if it is
	je .return
	mov rdi, QWORD [rdi]
	mov r10, rdx
.loop:

	mov r11, QWORD [rdi]
	push rdi					; setup stack for function call
	push rsi
	push r10
	push rdx

	mov rdi, rsi
	mov rsi, r11
	call r10					; call compare function

	pop rdx
	pop r10
	pop rsi						; clean stack from function call
	pop rdi

	cmp QWORD [rdi+8], 0		; check if list->next is NULL pointer, return if it is
	je .return
	mov rdi, QWORD [rdi+8]		; set rdi to next list item
	jmp .loop					; jump to start of loop
.return:
	leave
	ret							; return