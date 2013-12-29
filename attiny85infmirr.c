#include "hardware.h"
#include "light_ws2812.h"

struct CRGB { uint8_t g; uint8_t r; uint8_t b; };
struct CRGB refled[23];
struct CRGB led[13];
uint8_t mask;
// uint8_t pos=0;
// uint8_t direction=1;	
int8_t i;
int8_t j;

// Initialise the hardware
void appInitHardware(void) {
	initHardware();
}
// Initialise the software
TICK_COUNT appInitSoftware(TICK_COUNT loopStart){
	
	refled[0].r=32;refled[0].g=0 ;refled[0].b=0;
	refled[1].r=31;refled[1].g=0 ;refled[1].b=1;
	refled[2].r=30;refled[2].g=0 ;refled[2].b=2;
	refled[3].r=29;refled[3].g=0 ;refled[3].b=3;
	refled[4].r=28;refled[4].g=0 ;refled[4].b=4;
	refled[5].r=27;refled[5].g=0 ;refled[5].b=5;
	refled[6].r=26;refled[6].g=0 ;refled[6].b=6;
	refled[7].r=25;refled[7].g=0 ;refled[7].b=7;
	refled[8].r=24;refled[8].g=0 ;refled[8].b=8;
	refled[9].r=23;refled[9].g=0 ;refled[9].b=9;
	refled[10].r=22;refled[10].g=0;refled[10].b=10;
	refled[11].r=21;refled[11].g=0;refled[11].b=11;
	
	refled[12].r=20;refled[12].g=0 ;refled[12].b=12;
	refled[13].r=19;refled[13].g=0 ;refled[13].b=13;
	refled[14].r=18;refled[14].g=0 ;refled[14].b=14;
	refled[15].r=17;refled[15].g=0 ;refled[15].b=15;
	refled[16].r=16;refled[16].g=0 ;refled[16].b=16;
	refled[17].r=15;refled[17].g=0 ;refled[17].b=17;
	refled[18].r=14;refled[18].g=0 ;refled[18].b=18;
	refled[19].r=13;refled[19].g=0 ;refled[19].b=19;
	refled[20].r=12;refled[20].g=0 ;refled[20].b=20;
	refled[21].r=11;refled[21].g=0 ;refled[21].b=21;
	refled[22].r=10;refled[22].g=0 ;refled[22].b=22;
	
	
	return 0;
}
// This is the main loop
TICK_COUNT appControl(LOOP_COUNT loopCount, TICK_COUNT loopStart) {
	// while (1) {
	
	// refled[0].r=16;refled[0].g=0;refled[0].b=0;
	// refled[1].r=15;refled[1].g=0;refled[1].b=1;
	// refled[2].r=14;refled[2].g=0;refled[2].b=2;
	// refled[3].r=13;refled[3].g=0;refled[3].b=3;
	// refled[4].r=12;refled[4].g=0;refled[4].b=4;
	// refled[5].r=11;refled[5].g=0;refled[5].b=5;
	// refled[6].r=10;refled[6].g=0;refled[6].b=6;
	// refled[7].r=9;refled[7].g=0;refled[7].b=7;
	// refled[8].r=8;refled[8].g=0;refled[8].b=8;
	// refled[9].r=7;refled[9].g=0;refled[9].b=9;
	// refled[10].r=6;refled[10].g=0;refled[10].b=10;
	// refled[11].r=5;refled[11].g=0;refled[11].b=11;
	
	for (j=0; j < 23; j++) {
		cli();							// Disable interrupts. Can be removed if no interrupts are used.
		for (i=0; i<13; i++)
			led[i] = refled[j];
		
		ws2812_sendarray((uint8_t *)&led[0],39);
			
		sei();							// Enable interrupts.
		
		delay_ms(125);	
	}	
	
	delay_ms(375);	
	// for (j=0; j < 12; j++) {
		// cli();							// Disable interrupts. Can be removed if no interrupts are used.
		// for (i=0; i<12; i++)
			// led[i] = refled[j];
		
		// ws2812_sendarray((uint8_t *)&led[0],36);
			
		// sei();							// Enable interrupts.
		
		// delay_ms(250);	
	// }
	//if ((pos==16)||(pos==0)) direction=-direction;
	// direction=-direction;
	
	// delay_ms(250);	
	
	for (j=22; j >= 0; j--) {
		cli();							// Disable interrupts. Can be removed if no interrupts are used.
		for (i=0; i<13; i++)
			led[i] = refled[j];
	
		ws2812_sendarray((uint8_t *)&led[0],39);
			
		sei();							// Enable interrupts.
		
		delay_ms(125);
	}
	
	delay_ms(375);	
	// for (i=0; i<12; i++)
			// led[i] = refled[0];
	// }
	
	// cli();												// Disable interrupts. Can be removed if no interrupts are used.
	// for (i=0; i<pos; i++) 
		// ws2812_sendarray((uint8_t *)&led[1],36);			// Repeatedly send "red" to the led string. 
														// // No more than 1-2µs should pass between calls
														// // to avoid issuing a reset condition.			
	// for (i=0; i<(36-pos); i++) 
		// ws2812_sendarray((uint8_t *)&led[0],36);			// white
		
	// sei();												// Enable interrupts.
	
	// delay_ms(250);										// Issue reset and wait for 50 ms.
	
	// pos+=direction;		
	// if ((pos==36)||(pos==0)) direction=-direction;
	// -------- Start Digital Output-------
	// // Set the pin high
	// pin_high(outputB0); 
	
	// // Set the pin low
	// pin_low(outputB0); 
	
	// // Toggle the pin ie high->low, or low->high
	// pin_toggle(outputB0); 
	
	// // Output a high pulse of 1000us
	// pin_pulseOut(outputB0,1000,TRUE);
	
	// delay_ms(100);
	// -------- End   Digital Output-------

	// -------- Start Analogue Input-------
	{		
		// Read the Analogue Input and store results
		//uint16_t val = a2dConvert10bit(adc1_B2);
		// Dump out the value
		// cout << "adc1: " << val;
		// cout.println();
	}
	// -------- End   Analogue Input-------

	return 0;
}
