#include <stdio.h>

int
isLittleEndian() {
	int val;
	char *ptr;

	val=1;
	ptr=(char*) &val;
	return(*ptr);
}

main()
{
  if (isLittleEndian()) {
    printf("Machine is Little Endian\n");
  }
  else {
    printf("Machine is Big Endian\n");
  }
}
