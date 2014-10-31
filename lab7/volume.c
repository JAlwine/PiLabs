#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

#include "adc.h"

#define LED1 8
#define LED2 27
#define LED3 28
#define LED4 29

int main(int argc, char **argv){
	/*WiringPi Setup - for GPIOs*/
	if(wiringPiSetup() == -1)
		return 1; /*exit with error*/	
	
	/*WiringPi SPI Setup - for MCP3008*/
	if(init() < 0)
		return 1; /*exit with error*/

	int chan = 0;

	if(argc > 1)
		chan = atoi(argv[1]);

	while(1){
		
		/********** Do not change **********/
		int reading = readADC(chan);
		reading *= 100;
		reading /= 1023;
		
		fprintf(stderr, "%d\n", reading);
		/***********************************/


		/*Write your code here */
		pinMode(LED1, OUTPUT);
		pinMode(LED2, OUTPUT);
		pinMode(LED3, OUTPUT);
		pinMode(LED4, OUTPUT);
		
		digitalWrite(LED1, 0);
		digitalWrite(LED2, 0);
		digitalWrite(LED3, 0);
		digitalWrite(LED4, 0);

		if (reading > 0) {
			digitalWrite(LED1, 100);
		}
		if (reading > 50){
               	 	digitalWrite(LED2, 100);
			}
		if (reading > 75) {
               	 	digitalWrite(LED3, 100);
		}
		if (reading == 100){
                	digitalWrite(LED4, 100);
		}

		delay(100);	
	}
	return 0; /*exit without errors*/
}
