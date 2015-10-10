//**************************************************************
//******** FUNCTIONS FOR SERIAL COMMUNICATION USING UART *******
//**************************************************************
//Controller: ATmega32 (Clock: 8 Mhz-internal)
//Compiler	: AVR-GCC (winAVR with AVRStudio)
//Version 	: 2.3
//Author	: CC Dharmani, Chennai (India)
//			  www.dharmanitech.com
//Date		: 08 May 2010
//**************************************************************

//**************************************************
// ***** HEADER FILE : UART_routines.h ******
//**************************************************

#ifndef _UART_ROUTINES_H_
#define _UART_ROUTINES_H_

#define CHAR 0
#define INT  1
#define LONG 2

#define TX_NEWLINE {transmitByte('\n');}

void uart0_init(void);
unsigned char receiveByte(void);
void transmitByte(unsigned char);
void transmitString_F(char*);
void transmitString(unsigned char*);
void transmitHex( unsigned char dataType, unsigned long data );


#endif
