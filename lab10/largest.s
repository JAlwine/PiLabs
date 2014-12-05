#This program will take two numbers from standard input and output the largest of the two

        .global main

        .text
main:                                   # This is called by C library's startup code
        
	push %rbp

	mov $message, %rdi          # First integer (or pointer) parameter in %rdi
        call    puts                    # puts(message)
	
	#Move input format into rdi
	mov $input, %rdi
	#Allocate space on the stack for 1st var
	sub $8, %rsp
	#move this var into rsi to be used by scanf 
	mov %rsp, %rsi
	mov $0, %rax

	call scanf

        #load message 2 into rdi and print
	mov  $message2, %rdi
       	call puts
	
	#Move input format into rdi and scan input
	mov  $input, %rdi
	#Allocate space on the stack for 2nd var
	sub $8, %rsp
	#Move this var into rsi to be used by scanf
	mov %rsp, %rsi
	mov $0, %rax
	call scanf
	#store result into register 13
	mov %rsp, %r13

	#restore the stack pointer
	#Dereference values and store them in registers
	
	pop %r12
	mov -8(%rsp), %r12
	mov (%rsp), %r13

	cmp %r12, %r13
	jl less

	
	#Set args for printf and print result
	mov $output, %rdi
	mov -8(%rsp), %rsi
	mov $0, %rax
	call printf

	#end program
	add $16, %rsp
	pop %rbp
	ret

less:
	#Set args for printf and print result
	mov $output, %rdi
	mov %rsp, %rsi
	mov $0, %rax
	call printf

	#end program
	add $16, %rsp
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
