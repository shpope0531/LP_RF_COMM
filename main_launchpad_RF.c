/* This file is licensed under BSD. It is originally copyright Texas Instruments, 
* but has been adapted by Lars Kristian Roland
*/

#include "./ti/include.h"


extern char paTable[];
extern char paTableLen;

char txBuffer[4];
char rxBuffer[4];
unsigned int i = 0;

void main (void)
{
	init();

	while(1){

	}
}


// The ISR assumes the interrupt came from a pressed button
#pragma vector=PORT1_VECTOR
__interrupt void Port1_ISR (void)
{
  // If Switch was pressed
  if(TI_CC_SW_PxIFG & TI_CC_SW1)
  {
    // Build packet
    txBuffer[0] = 2;                        // Packet length
    txBuffer[1] = 0x01;                     // Packet address
    txBuffer[2] = TI_CC_LED1;
    //(~TI_CC_SW_PxIFG << 1) & 0x02; // Load switch inputs
    RFSendPacket(txBuffer, 3);              // Send value over RF
    __delay_cycles(5000);                   // Switch debounce
  }
  TI_CC_SW_PxIFG &= ~(TI_CC_SW1);           // Clr flag that caused int
}

// The ISR assumes the interrupt came from GDO0. GDO0 fires indicating that
// CCxxxx received a packet
#pragma vector=PORT2_VECTOR
__interrupt void Port2_ISR(void)
{
    // if GDO fired
  if(TI_CC_GDO0_PxIFG & TI_CC_GDO0_PIN)
  {
    char len=2;                             // Len of pkt to be RXed (only addr
                                            // plus data; size byte not incl b/c
                                            // stripped away within RX function)
    if (RFReceivePacket(rxBuffer,&len))     // Fetch packet from CCxxxx
    TI_CC_LED_PxOUT ^= rxBuffer[1];         // Toggle LEDs according to pkt data
  }

  TI_CC_GDO0_PxIFG &= ~TI_CC_GDO0_PIN;      // After pkt RX, this flag is set.
}
