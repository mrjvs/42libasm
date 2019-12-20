section .text
	global	_ft_read			; set function as global

_ft_read:
	mov	rax, 0x2000003			; read system call, magic number
	syscall						; do system call, all params are already set
	ret							; return
