#include <htc.h>
#include <pic.h>
//#include <stdio.h>
#define _XTAL_FREQ 32768
#include "utils.c"


__CONFIG(LP & WDTDIS & PWRTEN & MCLRDIS & UNPROTECT & UNPROTECT & BORDIS & IESODIS & FCMDIS);

// Function Prototypes
void init(void);


volatile int numDisplay = 0;

char numLookup[10] = {
	0b10111110,  // 0
	0b10000010,  // 1
	0b01110110,  // 2
	0b11010110,  // 3
	0b11001010,  // 4
	0b11011100,  // 5
	0b11111100,  // 6
	0b10000110,  // 7
	0b11111110,  // 8
	0b11011110   // 9
};

unsigned char seconds = 0;
unsigned char minutes = 0;
unsigned char hours = 0;

void main(void) {
	static int ad_in;
	static char i = 0;
	static char temp_msb, temp_lsb, tempC, tempFrac;	

	init();

	while (1) {
		if(seconds) {
			//__delay_ms(100);
			numDisplay++;
			if(numDisplay > 9)
				numDisplay = 0;
			PORTC = ~numLookup[numDisplay];
			seconds = 0;
		}
		RB7 = 1;
		//__delay_ms(100);
		RB7 = 0;

	}
}

