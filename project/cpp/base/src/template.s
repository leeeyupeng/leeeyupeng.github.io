	.file	"template.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	$1, -16(%rbp)
	movl	$2, -12(%rbp)
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	_Z4swapIiEvT_S0_
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -8(%rbp)
	movss	.LC1(%rip), %xmm0
	movss	%xmm0, -4(%rbp)
	movss	-4(%rbp), %xmm0
	movl	-8(%rbp), %eax
	movaps	%xmm0, %xmm1
	movl	%eax, -36(%rbp)
	movss	-36(%rbp), %xmm0
	call	_Z4swapIfEvT_S0_
	movb	$1, -18(%rbp)
	movb	$2, -17(%rbp)
	movsbl	-17(%rbp), %edx
	movsbl	-18(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	_Z4swapIcEvT_S0_
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.text._Z4swapIiEvT_S0_,"axG",@progbits,_Z4swapIiEvT_S0_,comdat
	.weak	_Z4swapIiEvT_S0_
	.type	_Z4swapIiEvT_S0_, @function
_Z4swapIiEvT_S0_:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_Z4swapIiEvT_S0_, .-_Z4swapIiEvT_S0_
	.section	.text._Z4swapIfEvT_S0_,"axG",@progbits,_Z4swapIfEvT_S0_,comdat
	.weak	_Z4swapIfEvT_S0_
	.type	_Z4swapIfEvT_S0_, @function
_Z4swapIfEvT_S0_:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -4(%rbp)
	movss	%xmm1, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_Z4swapIfEvT_S0_, .-_Z4swapIfEvT_S0_
	.section	.text._Z4swapIcEvT_S0_,"axG",@progbits,_Z4swapIcEvT_S0_,comdat
	.weak	_Z4swapIcEvT_S0_
	.type	_Z4swapIcEvT_S0_, @function
_Z4swapIcEvT_S0_:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %edx
	movl	%esi, %eax
	movb	%dl, -4(%rbp)
	movb	%al, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	_Z4swapIcEvT_S0_, .-_Z4swapIcEvT_S0_
	.section	.rodata
	.align 4
.LC0:
	.long	1065353216
	.align 4
.LC1:
	.long	1067030938
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
