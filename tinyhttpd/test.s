	.file	"simpleclient.c"
	.section	.rodata
.LC0:
	.string	"127.0.0.1"
.LC1:
	.string	"oops: client1"
.LC2:
	.string	"char from server = %c\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movb	$65, -45(%rbp)
	movl	$0, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket
	movl	%eax, -44(%rbp)
	movw	$2, -32(%rbp)
	movl	$.LC0, %edi
	call	inet_addr
	movl	%eax, -28(%rbp)
	movl	$9734, %edi
	call	htons
	movw	%ax, -30(%rbp)
	movl	$16, -40(%rbp)
	movl	-40(%rbp), %edx
	leaq	-32(%rbp), %rcx
	movl	-44(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	connect
	movl	%eax, -36(%rbp)
	cmpl	$-1, -36(%rbp)
	jne	.L2
	movl	$.LC1, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L2:
	leaq	-45(%rbp), %rcx
	movl	-44(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
	leaq	-45(%rbp), %rcx
	movl	-44(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movzbl	-45(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	-44(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$0, %edi
	call	exit
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
