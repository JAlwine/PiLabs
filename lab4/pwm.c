#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

/*You can set Pin numbers here */
#define Rb 0
#define Gb 1
#define Bb 2
#define increase 4
#define decrease 3
#define Rled 5
#define Gled 8
#define Bled 29

int main (void) {

 /* Initialize GPIO pins to map to wiringPi numbers */
    if(wiringPiSetup() == -1) 
        return 1; //return with error status (initialization failed)

/* Set modes for GPIO pins*/

/*Inputs*/
pinMode(Rb, INPUT);
pinMode(Gb, INPUT);
pinMode(Bb, INPUT);
pinMode(increase, INPUT);
pinMode(decrease, INPUT);

/*Outputs*/
softPwmCreate (Rled, 0, 100);
softPwmCreate (Gled, 0, 100);
softPwmCreate (Bled, 0, 100);

int Rval = 0;
int Gval = 0;
int Bval = 0;

while(1) {

	if (digitalRead(Rb)== LOW){
		if (digitalRead(increase) == LOW) {
			/* Increase Rled */
			Rval = Rval + 5;
			printf("increase red\n");
		} 
		else if (digitalRead(decrease) == LOW) {
			/* Decreaset Rled */
			Rval = Rval-5;
			printf("decrease red\n");
		}
	
		softPwmWrite (Rled, Rval);
	}


	if (digitalRead(Gb)== LOW){
        	if (digitalRead(increase) == LOW) {
                		/* Increase Gled */
				Gval = Gval+5;
				printf("increase green\n");	
		}
        	else if (digitalRead(decrease) == LOW) {
                		/* decrease Gled */
				Gval = Gval-5;
				printf("decrease green\n");		
		}

		softPwmWrite (Gled, Gval);
	}


	if (digitalRead(Bb)== LOW){
        	if (digitalRead(increase) == LOW) {
                	/* Increase Bled */
			Bval = Bval+5;
			printf("increase blue\n");
		}
        	else if (digitalRead(decrease) == LOW) {
                	/* decrease Bled */
			Bval = Bval-5;
			printf("decrease blue\n");
		}
	
		softPwmWrite (Bled, Bval);
	}


delay(100);
}


return 0;
}
