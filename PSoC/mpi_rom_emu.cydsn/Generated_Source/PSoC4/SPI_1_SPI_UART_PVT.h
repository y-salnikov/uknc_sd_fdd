/*******************************************************************************
* File Name: SPI_1_SPI_UART_PVT.h
* Version 2.0
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_PVT_SPI_1_H)
#define CY_SCB_SPI_UART_PVT_SPI_1_H

#include "SPI_1_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if(SPI_1_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  SPI_1_rxBufferHead;
    extern volatile uint32  SPI_1_rxBufferTail;
    extern volatile uint8   SPI_1_rxBufferOverflow;
#endif /* (SPI_1_INTERNAL_RX_SW_BUFFER_CONST) */

#if(SPI_1_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  SPI_1_txBufferHead;
    extern volatile uint32  SPI_1_txBufferTail;
#endif /* (SPI_1_INTERNAL_TX_SW_BUFFER_CONST) */

#if(SPI_1_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 SPI_1_rxBufferInternal[SPI_1_RX_BUFFER_SIZE];
#endif /* (SPI_1_INTERNAL_RX_SW_BUFFER) */

#if(SPI_1_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 SPI_1_txBufferInternal[SPI_1_TX_BUFFER_SIZE];
#endif /* (SPI_1_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

#if(SPI_1_SCB_MODE_SPI_CONST_CFG)
    void SPI_1_SpiInit(void);
#endif /* (SPI_1_SCB_MODE_SPI_CONST_CFG) */

#if(SPI_1_SPI_WAKE_ENABLE_CONST)
    void SPI_1_SpiSaveConfig(void);
    void SPI_1_SpiRestoreConfig(void);
#endif /* (SPI_1_SPI_WAKE_ENABLE_CONST) */

#if(SPI_1_SCB_MODE_UART_CONST_CFG)
    void SPI_1_UartInit(void);
#endif /* (SPI_1_SCB_MODE_UART_CONST_CFG) */

#if(SPI_1_UART_WAKE_ENABLE_CONST)
    void SPI_1_UartSaveConfig(void);
    void SPI_1_UartRestoreConfig(void);
    #define SPI_1_UartStop() \
        do{                             \
            SPI_1_UART_RX_CTRL_REG &= ~SPI_1_UART_RX_CTRL_SKIP_START; \
        }while(0)
#else
        #define SPI_1_UartStop() do{ /* Does nothing */ }while(0)

#endif /* (SPI_1_UART_WAKE_ENABLE_CONST) */

/* Interrupt processing */
#define SPI_1_SpiUartEnableIntRx(intSourceMask)  SPI_1_SetRxInterruptMode(intSourceMask)
#define SPI_1_SpiUartEnableIntTx(intSourceMask)  SPI_1_SetTxInterruptMode(intSourceMask)
uint32  SPI_1_SpiUartDisableIntRx(void);
uint32  SPI_1_SpiUartDisableIntTx(void);


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in SPI_1_SetPins() */
#define SPI_1_UART_RX_PIN_ENABLE    (SPI_1_UART_RX)
#define SPI_1_UART_TX_PIN_ENABLE    (SPI_1_UART_TX)

/* UART RTS and CTS position to be used in  SPI_1_SetPins() */
#define SPI_1_UART_RTS_PIN_ENABLE    (0x10u)
#define SPI_1_UART_CTS_PIN_ENABLE    (0x20u)

#endif /* (CY_SCB_SPI_UART_PVT_SPI_1_H) */


/* [] END OF FILE */
