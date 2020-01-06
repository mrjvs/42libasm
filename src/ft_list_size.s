section .text
	global	_ft_list_size		; set function as global

_ft_list_size:
	xor rax, rax				; set return value to 0
	cmp rdi, 0					; check if NULL pointer, return if it is
	je .return
.loop:
	inc rax						; increment return value by 1
	cmp QWORD [rdi+8], 0		; check if list->next is NULL pointer, return if it is
	je .return
	mov rdi, QWORD [rdi+8]		; set rdi to next list item
	jmp .loop					; jump to start of loop
.return:
	ret							; return
