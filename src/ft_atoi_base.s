section .text
	global	_ft_atoi_base				; set function as global

_ft_atoi_base:
	cmp		rdi, 0						; check if STR is NULL pointer, error if it is
	je		.error
	cmp		rsi, 0						; check if BASE is NULL pointer, error if it is
	je		.error

	; check if str length > 0
	cmp		BYTE [rdi], 0
	je		.error

;	get base size
	xor		r9, r9						; set r9 (size) to zero
.base_size_loop:
	cmp		BYTE [rsi+r9], 0			; check if end of null terminated string, end loop if it is
	je		.after_base_size_loop

	xor		r11, r11					; set r10 (counter) to zero
	mov		r12b, BYTE [rsi+r9]			; move current char into r12b
;	check base duplicates or '+', '-'
.base_dup_loop:
	cmp		BYTE [rsi+r11], 0			; check if end of null terminated string, end loop if it is
	je		.after_base_dup
	cmp		r11, r9						; check if current char is the same index of current char of previous loop, skip compare if it is
	je		.base_dup_skip
	cmp		BYTE [rsi+r11], r12b		; check if duplicate char, error if it is
	je		.error

.base_dup_skip:
	cmp		[rsi+r11], BYTE 45				; check if character is '-' (45)
	je		.error
	cmp		[rsi+r11], BYTE 43				; check if character is '+' (43)
	je		.error
	inc		r11							; increment counter
	jmp		.base_dup_loop				; return to start of loop

.after_base_dup:
	inc		r9							; increment size
	jmp		.base_size_loop				; jump back to start of loop

.after_base_size_loop:
	cmp		r9, 1						; check if base size > 1, error if it is not
	jle		.error

;	loop through string
	xor		r10b, r10b					; set r10b (is_neg) to zero
	xor		rdx, rdx					; set rdx (index) to zero
	xor		rax, rax					; set rax (return value) to zero

;	find prefix ('-' or '+')
	cmp		[rdi], BYTE 45				; check if first character is '-' (45)
	je		.add_neg
	cmp		[rdi], BYTE 43				; check if first character is '+' (43)
	je		.inc_prefix
	jmp		.char_loop					; if none apply, start character loop

.add_neg:
	inc		r10b						; set r10b (is_neg) to 1

.inc_prefix:
	inc		rdx							; increment counter

.char_loop:
	cmp		[rdi+rdx], BYTE 0			; check if end of null terminated string, return if it is
	je		.return

;	find current char in base string
	xor		rcx, rcx					; set rcx/ecx (base counter) to zero
.base_loop:
	cmp		[rsi+rcx], BYTE 0			; check if end of null terminated string, error if it is
	je		.error

	mov		r8b, BYTE [rsi+rcx]
	cmp		BYTE [rdi+rdx], r8b			; compare current char with current base char
	je		.after_base_loop			; continue to main loop if equal
	inc		rcx							; increment counter
	jmp		.base_loop

.after_base_loop:
;	turn base into number
	imul	rax, r9						; multiply return value by 10
	add		rax, rcx					; add base value to return value

	inc		rdx							; increment counter by one
	jmp		.char_loop					; go to beginning of loop

.return:
	cmp		r10b, BYTE 0				; check if r10b (is_neg) is 0
	je		.real_return				; return if not negative
	imul	rax, -1						; make number negative

.real_return:
	ret									; return

.error:
	xor		rax, rax					; set return value to zero
	ret
