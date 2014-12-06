#This program will take two numbers from standard input and output the largest of the two

        .global main

        .text
main:                                   # This is called by C library's startup code
        
	push %rbp

	mov $message, %rdi          # First integer (or pointer) parameter in %rdi
        call    puts                    # puts(message)
	
	
	#Allocate space on the stack for 1st var
	sub $8, %rsp
	
	#Move input format into rdi
	mov $input, %rdi
	#move this var into rsi to be used by scanf 
	mov %rsp, %rsi
	mov $0, %rax

	call scanf

	#store result in R14
	mov %rsp, %r14
	
	mov (%r14), %r14

	#restore RSP
	add $8, %rsp

        #load message 2 into rdi and print
	mov  $message2, %rdi
       	call puts
	
	#Allocate space on the stack for 2nd var
	sub $8, %rsp
	
	#Move input format into rdi and scan input
	mov  $input, %rdi
	#Move this var into rsi to be used by scanf
	mov %rsp, %rsi
	mov $0, %rax
	call scanf
	
	#store result into register 15
	mov %rsp, %r15	
	mov (%r15), %r15

	#restore RSP
	add $8, %rsp

	#Dereference values and store them in registers
	

	cmp %r15d, %r14d
	jl less

	
	#Set args for printf and print result
	mov $output, %rdi
	mov %r14, %rsi
	mov $0, %rax
	call printf

	#end program
	pop %rbp
	ret

less:
	#Set args for printf and print result
	mov $output, %rdi
	mov %r15, %rsi
	mov $0, %rax
	call printf

	#end program
	pop %rbp
        ret                             # Return to C library code

#First message to be displayed
message:
	.asciz "Please enter 1st number"

#Second message to be displayed
message2:
	.asciz "Please enter 2nd number"
#Input format
input:
	.asciz "%d"

output: 
	.asciz "The largest number is %d\n"
