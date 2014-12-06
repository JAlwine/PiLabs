#This program will take a string from stdin and tell you the length

        .global main

        .text
main:                                   # This is called by C library's startup code
        
	push %rbp
	
	mov $0, %R14
	#Moves the message into rdi
	mov $message, %rdi
	call puts

loop:
	mov $0, %rax
	call getchar
	#compare the returned char to '/n'
	cmp $10, %rax

je end
	#adds one to the counter
	add $1, %R14
jmp loop

end:
	mov $output, %rdi
	mov %R14, %rsi
	mov $0, %rax
	call printf

	#end program
	pop %rbp
        ret                             # Return to C library code

#First message to be displayed
message:
	.asciz "Please enter a string"

output:
	.asciz "The String length (%d) "
