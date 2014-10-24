.data
.align 2
scan_format:
.asciz "%d"
.align 2
p_result:
.asciz "Sum is  %d\n"
.align 2
prompt:
.asciz "Enter an integer."
.align  2
num:
.word 0
sum:
.word 0
count:
.word 0



.text
.global main
main:
push {ip, lr} @Used with pop at end of main, allowing program to end.

//sum is stored in r4
ldr r4, =sum
ldr r4, [r4]
//counter is stored in r5
ldr r5, =count
ldr r5, [r5]

loop:
mov r6, #5 /*This is the loop bounds*/
ldr r0, =prompt
bl puts

ldr r1, =num
ldr r0, =scan_format
bl scanf

ldr r1, =num
ldr r1, [r1]
add r4, r4, r1

add r5, r5, #1
cmp r5, r6 /*compare counter and the r6*/

beq print_result /*if greater print result*/
b loop

print_result:
ldr r0, =p_result
mov  r1, r4
bl printf
pop {ip, pc} @Used with push at start of Main, allowing program to end.
