#include <stdio.h>

int main() {

int a;
int b;

printf("number 1:");
scanf("%d", &a);

printf("\nnumber 2:");
scanf("%d", &b); 

printf("a=%d b=%d\n", a, b);

if (a > b)
	printf("The largest number is %d\n", a);
else
	printf("The largest number is %d\n", b);

}
