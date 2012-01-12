/* --COPYRIGHT--,BSD
 * Copyright (c) 2011, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//******************************************************************************
//  Description:  This file contains definitions specific to the hardware board.
//  Specifically, the definitions include hardware connections with the
//  CCxxxx connector port, LEDs, and switches.
//
//  MSP430/CC1100-2500 Interface Code Library v1.1
//
//  W. Goh
//  Texas Instruments, Inc.
//  December 2009
//  Built with IAR Embedded Workbench Version: 4.20
//******************************************************************************
// Change Log:
//******************************************************************************
// Version:  1.1
// Comments: Added support for eZ430-RF2500 board
// Version:  1.00
// Comments: Initial Release Version
//******************************************************************************

#define TI_CC_LED_PxOUT         P2OUT
#define TI_CC_LED_PxDIR         P2DIR
#define TI_CC_LED1              BIT4
#define TI_CC_LED2              BIT5

#define TI_CC_SW_PxIN           P1IN
#define TI_CC_SW_PxIE           P1IE
#define TI_CC_SW_PxIES          P1IES
#define TI_CC_SW_PxIFG          P1IFG
#define TI_CC_SW_PxREN          P1REN
#define TI_CC_SW_PxOUT          P1OUT
#define TI_CC_SW1               BIT3

#define TI_CC_GDO0_PxOUT        P2OUT
#define TI_CC_GDO0_PxIN         P2IN
#define TI_CC_GDO0_PxDIR        P2DIR
#define TI_CC_GDO0_PxIE         P2IE
#define TI_CC_GDO0_PxIES        P2IES
#define TI_CC_GDO0_PxIFG        P2IFG
#define TI_CC_GDO0_PIN          BIT6

#define TI_CC_GDO1_PxOUT        P3OUT
#define TI_CC_GDO1_PxIN         P3IN
#define TI_CC_GDO1_PxDIR        P3DIR
#define TI_CC_GDO1_PIN          0x04

#define TI_CC_GDO2_PxOUT        P1OUT
#define TI_CC_GDO2_PxIN         P1IN
#define TI_CC_GDO2_PxDIR        P1DIR
#define TI_CC_GDO2_PIN          BIT0

#define TI_CC_CSn_PxOUT         P1OUT
#define TI_CC_CSn_PxDIR         P1DIR
#define TI_CC_CSn_PIN           BIT4


//******************************************************************************
// Select which port will be used for interface to CCxxxx
//******************************************************************************
#define TI_CC_RF_SER_INTF       TI_CC_SER_INTF_USCIB0  // Interface to CCxxxx
//#define TI_5xx                              // Using a 5xx
#define TI_MSP430G2553

