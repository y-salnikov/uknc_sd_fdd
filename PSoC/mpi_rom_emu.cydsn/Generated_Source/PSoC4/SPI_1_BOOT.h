/*******************************************************************************
* File Name: SPI_1_BOOT.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the bootloader
*  communication interface of SCB component.
*
* Note:
*
********************************************************************************
* Copyright 2014, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_SPI_1_H)
#define CY_SCB_BOOT_SPI_1_H

#include "SPI_1_PVT.h"

#if (SPI_1_SCB_MODE_I2C_INC)
    #include "SPI_1_I2C.h"
#endif /* (SPI_1_SCB_MODE_I2C_INC) */

#if (SPI_1_SCB_MODE_EZI2C_INC)
    #include "SPI_1_EZI2C.h"
#endif /* (SPI_1_SCB_MODE_EZI2C_INC) */

#if (SPI_1_SCB_MODE_SPI_INC || SPI_1_SCB_MODE_UART_INC)
    #include "SPI_1_SPI_UART.h"
#endif /* (SPI_1_SCB_MODE_SPI_INC || SPI_1_SCB_MODE_UART_INC) */


/***************************************
*        Function Prototypes
***************************************/

/* Bootloader communication interface enable */
#define SPI_1_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI_1) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

#if (SPI_1_SCB_MODE_I2C_INC)

    #define SPI_1_I2C_BTLDR_COMM_ENABLED     (SPI_1_BTLDR_COMM_ENABLED && \
                                                            (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             SPI_1_I2C_SLAVE_CONST))

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_I2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void SPI_1_I2CCyBtldrCommStart(void);
    void SPI_1_I2CCyBtldrCommStop (void);
    void SPI_1_I2CCyBtldrCommReset(void);
    cystatus SPI_1_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_1_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Size of Read/Write buffers for I2C bootloader  */
    #define SPI_1_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
    #define SPI_1_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)
    #define SPI_1_I2C_MIN_UINT16(a, b)           ( ((uint16)(a) < (uint16) (b)) ? \
                                                                    ((uint32) (a)) : ((uint32) (b)) )
    #define SPI_1_WAIT_1_MS                      (1u)
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_I2C_BTLDR_COMM_ENABLED) */

#endif /* (SPI_1_SCB_MODE_I2C_INC) */


#if (SPI_1_SCB_MODE_EZI2C_INC)

    /* Provide EMPTY bootloader communication functions. EZI2C is NOT supported yet */
    #define SPI_1_EZI2C_BTLDR_COMM_ENABLED   (SPI_1_BTLDR_COMM_ENABLED && \
                                                         SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void SPI_1_EzI2CCyBtldrCommStart(void);
    void SPI_1_EzI2CCyBtldrCommStop (void);
    void SPI_1_EzI2CCyBtldrCommReset(void);
    cystatus SPI_1_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_1_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_EZI2C_BTLDR_COMM_ENABLED) */

#endif /* (SPI_1_SCB_MODE_EZI2C_INC) */

#if (SPI_1_SCB_MODE_SPI_INC || SPI_1_SCB_MODE_UART_INC)
    /* Provide EMPTY bootloader communication functions. SPI and UART is NOT supported yet */
    #define SPI_1_SPI_BTLDR_COMM_ENABLED     (SPI_1_BTLDR_COMM_ENABLED && \
                                                        SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)

    #define SPI_1_UART_BTLDR_COMM_ENABLED    (SPI_1_BTLDR_COMM_ENABLED && \
                                                        SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void SPI_1_SpiCyBtldrCommStart(void);
    void SPI_1_SpiCyBtldrCommStop (void);
    void SPI_1_SpiCyBtldrCommReset(void);
    cystatus SPI_1_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_1_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void SPI_1_UartCyBtldrCommStart(void);
    void SPI_1_UartCyBtldrCommStop (void);
    void SPI_1_UartCyBtldrCommReset(void);
    cystatus SPI_1_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus SPI_1_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_UART_BTLDR_COMM_ENABLED) */

#endif /* (SPI_1_SCB_MODE_SPI_INC || SPI_1_SCB_MODE_UART_INC) */

#if !defined (SPI_1_I2C_BTLDR_COMM_ENABLED)
    #define SPI_1_I2C_BTLDR_COMM_ENABLED     (0u)
#endif /* (SPI_1_I2C_BTLDR_COMM_ENABLED) */

#if !defined (SPI_1_EZI2C_BTLDR_COMM_ENABLED)
    #define SPI_1_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (SPI_1_EZI2C_BTLDR_COMM_ENABLED) */

#if !defined (SPI_1_SPI_BTLDR_COMM_ENABLED)
    #define SPI_1_SPI_BTLDR_COMM_ENABLED     (0u)
#endif /* (SPI_1_SPI_BTLDR_COMM_ENABLED) */

#if !defined (SPI_1_UART_BTLDR_COMM_ENABLED)
    #define SPI_1_UART_BTLDR_COMM_ENABLED    (0u)
#endif /* (SPI_1_UART_BTLDR_COMM_ENABLED) */

/* Bootloader enabled condition for each mode */
#define SPI_1_BTLDR_COMM_MODE_ENABLED    (SPI_1_I2C_BTLDR_COMM_ENABLED   || \
                                                     SPI_1_EZI2C_BTLDR_COMM_ENABLED || \
                                                     SPI_1_SPI_BTLDR_COMM_ENABLED   || \
                                                     SPI_1_UART_BTLDR_COMM_ENABLED)

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_BTLDR_COMM_ENABLED)
    #if (SPI_1_BTLDR_COMM_MODE_ENABLED)
        /* Bootloader physical layer functions */
        void SPI_1_CyBtldrCommStart(void);
        void SPI_1_CyBtldrCommStop (void);
        void SPI_1_CyBtldrCommReset(void);
        cystatus SPI_1_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus SPI_1_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (SPI_1_BTLDR_COMM_MODE_ENABLED) */

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI_1)
        #define CyBtldrCommStart    SPI_1_CyBtldrCommStart
        #define CyBtldrCommStop     SPI_1_CyBtldrCommStop
        #define CyBtldrCommReset    SPI_1_CyBtldrCommReset
        #define CyBtldrCommWrite    SPI_1_CyBtldrCommWrite
        #define CyBtldrCommRead     SPI_1_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPI_1) */
#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_BTLDR_COMM_ENABLED) */

#endif /* (CY_SCB_BOOT_SPI_1_H) */

/* [] END OF FILE */
