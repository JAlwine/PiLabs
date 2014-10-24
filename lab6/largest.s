.data
.align 2
scan_format:
.asciz "%d"
.align 2
out_format:
.asciz "Largest is %d\n"
.align 2
instr1:
.asciz "Enter first integer."
instr2:
.asciz "Enter second integer."
.align  2
num1:
.word 0
num2:
.word 0
.text
.global main
main:
push {ip, lr} @Used with pop at end of main, allowing program to end.

ldr r0, =instr1
bl puts
ldr r1, =num1
ldr r0, =scan_format
bl scanf

ldr r0, =instr2
bl puts
ldr r1, =num2
ldr r0, =scan_format
bl scanf

ldr r6, =num1  @load address of num1 into r6
ldr r1, [r6]  @load value of num1 into r1

ldr r6, =num2
ldr r2, [r6]

cmp r1, r2 @compare contents of r1 and r2

bgt print_result  @if greater than print the result

mov r1, r2 

print_result:
ldr r0, =out_format
bl printf

pop {ip, pc} @Used with push at start of Main, allowing program to end.
