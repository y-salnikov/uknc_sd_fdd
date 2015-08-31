//**************************************************************
// ****** FUNCTIONS FOR SPI COMMUNICATION *******
//**************************************************************
//**************************************************
// ***** SOURCE FILE : SPI_routines.c ******
//**************************************************
#include <project.h>
#include "sd/SPI_routines.h"

//SPI initialize for SD card

void spi_init(void)
{
	SPI_1_Start();
    
}

unsigned char SPI_transmit(unsigned char data)
{
    SPI_1_SpiUartWriteTxData(data);
    while(SPI_1_SpiUartGetTxBufferSize()!=0);
    while(SPI_1_SpiUartGetRxBufferSize()==0);
    return SPI_1_SpiUartReadRxData();
}

unsigned char SPI_receive(void)
{
   return  SPI_transmit(0xff);
}


