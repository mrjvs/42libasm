section .text
	global	_ft_write			; set function as global

_ft_write:
	mov	rax, 0x2000004			; write system call, magic number
	syscall						; do system call, all params are already set
	ret							; return
