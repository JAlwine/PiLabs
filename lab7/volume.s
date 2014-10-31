.data
print_val:
.asciz "%d\n"
out:
.asciz "OUTPUT"

.text 

.global main

main:
	str lr, [sp, #-4]!
ldr r0, [r1, #+4]
bl atoi
mov r7, r0

bl wiringPiSetup
bl init
//Set pin 8 to output
Mov r0, #8
ldr r1, =out
bl pinMode 
//Set remaining pins
mov r0, #27
bl pinMode
mov r0, #28
bl pinMode
mov r0, #29
bl pinMode

Loop:
//set leds to off
mov r0, #8
mov r1, #0
bl digitalWrite
mov r0, #27
mov r1, #0
bl digitalWrite
mov r0, #28
mov r1, #0
bl digitalWrite
mov r0, #29
mov r1, #0
bl digitalWrite

Mov r0, r7
bl readADC
str r0, [sp]

mov r1, r0

ldr r0,= print_val
bl printf


//Compare the read value stored in sp
ldr r0, [sp]
mov  r1, #768
cmp r0, r1

blt skip1

mov r0, #8
mov r1, #100
bl digitalWrite

skip1:
ldr r0, [sp]
mov r1, #512
cmp r0,r1

blt skip2

mov r0, #27
mov r1, #100
bl digitalWrite

skip2:
ldr r0, [sp]
mov r1, #256
cmp r0, r1

blt skip3

mov r0, #28
mov r1, #100
bl digitalWrite

skip3:
ldr r0, [sp]
mov r1, #1
cmp r0, r1

blt skip4

mov r0, #29
mov r1, #100
bl digitalWrite

skip4:
mov r0, #100
bl delay
b Loop
	

	/*End of main, return */
	ldr lr, [sp], #+4
	bx lr
