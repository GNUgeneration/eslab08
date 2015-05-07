// ***** 0. Documentation Section *****
// SwitchLEDInterface.c for Lab 8
// Runs on LM4F120/TM4C123
// Use simple programming structures in C to toggle an LED
// while a button is pressed and turn the LED on when the
// button is released.  This lab requires external hardware
// to be wired to the LaunchPad using the prototyping board.
// December 28, 2014
//      Jon Valvano and Ramesh Yerraballi

// ***** 1. Pre-processor Directives Section *****
#include "TExaS.h"
#include "tm4c123gh6pm.h"

// ***** 2. Global Declarations Section *****
unsigned long in; //eja

// FUNCTION PROTOTYPES: Each subroutine defined
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

// ***** 3. Subroutines Section *****

// PE0, PB0, or PA2 connected to positive logic momentary switch using 10k ohm pull down resistor
// PE1, PB1, or PA3 connected to positive logic LED through 470 ohm current limiting resistor
// To avoid damaging your hardware, ensure that your circuits match the schematic
// shown in Lab8_artist.sch (PCB Artist schematic file) or 
// Lab8_artist.pdf (compatible with many various readers like Adobe Acrobat).

void delay100ms(unsigned long t) { //eja
	unsigned long i; //eja
	while (t > 0) { //eja
		i = 1333333; //eja
		while (i > 0) { //eja
			i = i - 1; //eja
		} //eja
		t = t - 1; //eja
	} //eja
} //eja

int main(void){
	
	unsigned long volatile delay; //eja
	
//**********************************************************************
// The following version tests input on PE0 and output on PE1
//**********************************************************************
  TExaS_Init(SW_PIN_PE0, LED_PIN_PE1);  // activate grader and set system clock to 80 MHz
  SYSCTL_RCGC2_R = SYSCTL_RCGC2_R | SYSCTL_RCGC2_GPIOE; //eja
	delay = SYSCTL_RCGC2_R; //eja
	GPIO_PORTE_AMSEL_R = GPIO_PORTE_AMSEL_R & ~0x03; //eja
	GPIO_PORTE_PCTL_R = GPIO_PORTE_PCTL_R & ~0x000000FF; //eja
	GPIO_PORTE_DIR_R = GPIO_PORTE_DIR_R | 0x02; //eja
	GPIO_PORTE_DIR_R = GPIO_PORTE_DIR_R & ~0x01; //eja
	
	
  EnableInterrupts();           // enable interrupts for the grader
  while(1){
    
  }
	
}