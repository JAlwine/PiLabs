#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef cols
#define cols 16
#endif

void memdump(char * p , int len) {
    // Add your code here.
int i, j;
        
        for(i = 0; i < len + ((len % cols) ? (cols - len % cols) : 0); i++)
        {
                /* print offset */
                if(i % cols == 0)
                {
                        printf("0x%06x: ", i);
                }
 
                /* print hex data */
                if(i < len)
                {
                        printf("%02x ", 0xFF & ((char*)p)[i]);
                }
                else /* end of block, just aligning for ASCII dump */
                {
                        printf("   ");
                }
                
                /* print ASCII dump */
                if(i % cols == (cols - 1))
                {
                        for(j = i - (cols - 1); j <= i; j++)
                        {
                                if(j >= len) /* end of block, not really printing */
                                {
                                        putchar(' ');
                                }
                                else if(isprint(((char*)p)[j])) /* printable char */
                                {
                                        putchar(0xFF & ((char*)p)[j]);        
                                }
                                else /* other char */
                                {
                                        putchar('.');
                                }
                        }
                        putchar('\n');
                }
        }    
    
}

struct X{
  char a;
  int i;
  char b;
  int *p;
};

struct List {
  char * str;
  struct List * next;
};

main() {
  char str[20];
  int a = 5;
  int b = -5;
  double y = 12;
  struct X x;
  struct List * head;

  x.a = 'A';
  x.i = 9;
  x.b = '0';
  x.p = &x.i;
  strcpy(str, "Hello world\n");
  printf("&x=0x%x\n", &x.a);
  printf("&y=0x%x\n", &y);

  memdump((char *) &x.a, 64);
  head = (struct List *) malloc(sizeof(struct List));
  head->str=strdup("Welcome ");
  head->next = (struct List *) malloc(sizeof(struct List));
  head->next->str = strdup("to ");
  head->next->next = (struct List *) malloc(sizeof(struct List));
  head->next->next->str = strdup("cs250");
  head->next->next->next = NULL;
  printf("head=0x%x\n", head);
  memdump((char*) head, 128);
}
