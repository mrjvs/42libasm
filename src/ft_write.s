section .text
	global	_ft_write			; set function as global

_ft_write:
	mov	rax, 0x2000004			; write system call, magic number
	syscall						; do system call, all params are already set
	jnc .return					; if success, return
	mov rax, -1					; set return to -1
.return:
	ret							; return
