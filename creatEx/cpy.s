	.file	"cpy.c"
	.section	.rodata
.LC0:
	.string	"Usage : copy file1 file2\n"
.LC1:
	.string	"file open error!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1072, %rsp
	movl	%edi, -1060(%rbp)
	movq	%rsi, -1072(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpl	$2, -1060(%rbp)
	jg	.L2
	movl	$25, %edx
	movl	$.LC0, %esi
	movl	$2, %edi
	call	write
	movl	$-1, %eax
	jmp	.L8
.L2:
	movq	-1072(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open
	movl	%eax, -1052(%rbp)
	movq	-1072(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movl	$438, %edx
	movl	$577, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open
	movl	%eax, -1048(%rbp)
	cmpl	$0, -1048(%rbp)
	js	.L4
	cmpl	$0, -1052(%rbp)
	jns	.L6
.L4:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	jmp	.L6
.L7:
	movl	-1044(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-1040(%rbp), %rcx
	movl	-1048(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
.L6:
	leaq	-1040(%rbp), %rcx
	movl	-1052(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -1044(%rbp)
	cmpl	$0, -1044(%rbp)
	jg	.L7
	movl	-1052(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	-1048(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$0, %eax
.L8:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L9
	call	__stack_chk_fail
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
