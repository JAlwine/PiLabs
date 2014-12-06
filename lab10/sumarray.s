#This program will take a string from stdin and tell you the length

        .global main

        .text
main:                                   # This is called by C library's startup code
        
	push %rbp
	
	#zero out the regs	
	mov $0, %r15
	mov $0, %r14
	mov $0, %r13

	#Moves the message into rdi
	mov $message, %rdi
	call puts

loop:
	#allocate space on the stack for var
	sub $8, %rsp
	
	mov $input, %rdi
	mov %rsp, %rsi
	mov $0, %rax
	
	call scanf

	#store result in r13
	mov %rsp, %r13
	mov (%r13), %r13

	add %r13, %r14

	add $8, %rsp
	
	#compare the returned char to '/n'
	cmp $4, %r15


je end
	#adds one to the counter
	add $1, %r15
jmp loop

end:
	mov $output, %rdi
	mov %r14, %rsi
	mov $0, %rax
	call printf

	#end program
	pop %rbp
        ret                             # Return to C library code

#First message to be displayed
message:
	.asciz "Please enter 5 numbers"

input:
	.asciz "%d"

output:
	.asciz "The toatal is (%d) "
