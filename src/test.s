section .text
    global  _maxofthree

_maxofthree:
    mov     rax, rdi                ; result (rax) initially holds x
    cmp     rax, rsi                ; is x less than y?
    cmovl   rax, rsi                ; if so, set result to y
    cmp     rax, rdx                ; is max(x,y) less than z?
    cmovl   rax, rdx                ; if so, set result to z
    ret                             ; the max will be in rax

_ft_strlen:
	mov	rax,	0				; set return value to 0
	inc	rax						; increment return value by 1
	ret							; return

_hello_world:					;tells linker entry point
	mov	rdx,	len				;message length
	mov	rsi,	msg				;message to write
	mov	rdi,	1				;file descriptor (stdout)
	mov	rax,	0x2000004		;system call number (sys_write)
	syscall

	mov	eax,	5				;system call number (sys_exit)
	ret

section	.data
	msg db 'Hello, world!', 0xa  ;string to be printed
	len equ $ - msg     ;length of the string