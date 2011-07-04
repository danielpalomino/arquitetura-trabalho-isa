	.file	1 "dfs_2.c"
	.version	"01.01"
gcc2_compiled.:
	.text
	.align	2
	.globl	dfs
	.type	dfs,@function
	.set	nomips16
	.ent	dfs
dfs:
	.frame	$30,24,$31		# vars= 0, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,24
	sw	$31,20($sp)
	sw	$30,16($sp)
	move	$30,$sp
	sw	$4,24($30)
	lw	$2,24($30)
	beq	$2,$0,$L3
	lw	$2,24($30)
	lw	$4,4($2)
	jal	dfs
	lw	$2,24($30)
	lw	$4,8($2)
	jal	dfs
$L3:
	move	$sp,$30
	lw	$31,20($sp)
	lw	$30,16($sp)
	addu	$sp,$sp,24
	j	$31
	.end	dfs
	.size	dfs,.-dfs
	.align	2
	.globl	main
	.type	main,@function
	.set	nomips16
	.ent	main
main:
	.frame	$30,32,$31		# vars= 8, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,32
	sw	$31,28($sp)
	sw	$30,24($sp)
	move	$30,$sp
	la	$2,n1
	sw	$2,16($30)
	la	$2,n2
	sw	$2,n1+4
	la	$2,n3
	sw	$2,n1+8
	la	$2,n4
	sw	$2,n2+4
	la	$2,n5
	sw	$2,n2+8
	la	$2,n6
	sw	$2,n3+4
	la	$2,n7
	sw	$2,n3+8
	la	$2,n8
	sw	$2,n4+4
	la	$2,n9
	sw	$2,n4+8
	la	$2,n10
	sw	$2,n5+4
	la	$2,n11
	sw	$2,n5+8
	la	$2,n12
	sw	$2,n6+4
	la	$2,n13
	sw	$2,n6+8
	la	$2,n14
	sw	$2,n7+4
	la	$2,n15
	sw	$2,n7+8
	sw	$0,n8+4
	sw	$0,n8+8
	sw	$0,n9+4
	sw	$0,n9+8
	sw	$0,n10+4
	sw	$0,n10+8
	sw	$0,n11+4
	sw	$0,n11+8
	sw	$0,n12+4
	sw	$0,n12+8
	sw	$0,n13+4
	sw	$0,n13+8
	sw	$0,n14+4
	sw	$0,n14+8
	sw	$0,n15+4
	sw	$0,n15+8
	li	$2,16			# 0x10
	sw	$2,20($30)
	lw	$3,20($30)
	li	$2,10			# 0xa
	sw	$2,0($3)
	lw	$4,16($30)
	jal	dfs
	li	$2,16			# 0x10
	sw	$2,20($30)
	lw	$3,20($30)
	li	$2,20			# 0x14
	sw	$2,0($3)
	move	$sp,$30
	lw	$31,28($sp)
	lw	$30,24($sp)
	addu	$sp,$sp,32
	j	$31
	.end	main
	.size	main,.-main

	.comm	n1,12,4

	.comm	n2,12,4

	.comm	n3,12,4

	.comm	n4,12,4

	.comm	n5,12,4

	.comm	n6,12,4

	.comm	n7,12,4

	.comm	n8,12,4

	.comm	n9,12,4

	.comm	n10,12,4

	.comm	n11,12,4

	.comm	n12,12,4

	.comm	n13,12,4

	.comm	n14,12,4

	.comm	n15,12,4
