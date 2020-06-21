.global codegen
codegen:
addi sp, sp, -4
sw s0, 0(sp)
addi s0, sp, 0
addi sp, sp, -4
sw ra, 0(sp)
addi sp, sp, -4
sw s1, 0(sp)
addi sp, sp, -4
sw s2, 0(sp)
addi sp, sp, -4
sw s3, 0(sp)
addi sp, sp, -4
sw s4, 0(sp)
addi sp, sp, -4
sw s5, 0(sp)
addi sp, sp, -4
sw s6, 0(sp)
addi sp, sp, -4
sw s7, 0(sp)
addi sp, sp, -4
sw s8, 0(sp)
addi sp, sp, -4
sw s9, 0(sp)
addi sp, sp, -4
sw s10, 0(sp)
addi sp, sp, -4
sw s11, 0(sp)
li t0, 26
addi a0, t0, 0
li t0, 1
addi a1, t0, 0
addi sp, sp, -4
sw ra, 0(sp)
jal ra, digitalWrite
lw ra, 0(sp)
addi sp, sp, 4
li t0, 1000
addi a0, t0, 0
addi sp, sp, -4
sw ra, 0(sp)
jal ra, delay
lw ra, 0(sp)
addi sp, sp, 4
li t0, 26
addi a0, t0, 0
li t0, 0
addi a1, t0, 0
addi sp, sp, -4
sw ra, 0(sp)
jal ra, digitalWrite
lw ra, 0(sp)
addi sp, sp, 4
li t0, 1000
addi a0, t0, 0
addi sp, sp, -4
sw ra, 0(sp)
jal ra, delay
lw ra, 0(sp)
addi sp, sp, 4
addi sp, s0, -4
lw ra, 0(sp)
addi sp, sp, 4
lw s0, 0(sp)
addi sp, sp, 4
