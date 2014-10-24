.data
.align 2
p_length:
.asciz "String length is %d\n"
.align 2
prompt1:
.asciz "Enter a string."
.align 2
count:
.word 0


.text
.global main
main:
push {ip, lr} @Used with pop at end of main, allowing program to end.

ldr r5, =count
ldr r5, [r5]

ldr r0, =prompt1
bl puts

loop:
bl getchar

mov r1, #10 /*10 is the ascii value of \n*/
cmp r0, r1

beq print_length
add r5, r5, #1
b loop

print_length:
ldr r0, =p_length
mov r1, r5
bl printf

pop {ip, pc} @Used with push at start of Main, allowing program to end.
