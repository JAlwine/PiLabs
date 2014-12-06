#include <stdio.h>

main() { 
int counter=0;

printf("Please enter a string: ");

while (getchar() != 10){
counter++;
}

printf("The string length is %d.", counter);

}
