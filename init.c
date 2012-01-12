#include ".\TI\include.h"

extern char paTable[];
extern char paTableLen;
/* Just putting a comment in here to see what happens with GIT */

void init(){
	WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT


	// 5ms delay to compensate for time to startup between MSP430 and CC1100/2500
	__delay_cycles(5000);

	TI_CC_SPISetup();                         // Initialize SPI port

	TI_CC_PowerupResetCCxxxx();               // Reset CCxxxx
	writeRFSettings();                        // Write RF settings to config reg
	TI_CC_SPIWriteBurstReg(TI_CCxxx0_PATABLE, paTable, paTableLen);//Write PATABLE

	// Configure ports -- switch inputs, LEDs, GDO0 to RX packet info from CCxxxx
	TI_CC_SW_PxREN = TI_CC_SW1;               // Enable Pull up resistor
	TI_CC_SW_PxOUT = TI_CC_SW1;               // Enable pull up resistor
	TI_CC_SW_PxIES = TI_CC_SW1;               // Int on falling edge
	TI_CC_SW_PxIFG &= ~(TI_CC_SW1);           // Clr flags
	TI_CC_SW_PxIE = TI_CC_SW1;                // Activate interrupt enables
	TI_CC_LED_PxOUT &= ~(TI_CC_LED1 + TI_CC_LED2); // Outputs = 0
	TI_CC_LED_PxDIR |= TI_CC_LED1 + TI_CC_LED2;// LED Direction to Outputs

	TI_CC_GDO0_PxIES |= TI_CC_GDO0_PIN;       // Int on falling edge (end of pkt)
	TI_CC_GDO0_PxIFG &= ~TI_CC_GDO0_PIN;      // Clear flag
	TI_CC_GDO0_PxIE |= TI_CC_GDO0_PIN;        // Enable int on end of packet

	TI_CC_SPIStrobe(TI_CCxxx0_SRX);           // Initialize CCxxxx in RX mode.
											// When a pkt is received, it will
											// signal on GDO0 and wake CPU

	__bis_SR_register(LPM3_bits + GIE);       // Enter LPM3, enable interrupts
}
