/*******************************************************************************
* File Name: SPI_1_BOOT.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the bootloader
*  communication support in the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI_1_BOOT.h"


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_BTLDR_COMM_MODE_ENABLED)

/*******************************************************************************
* Function Name: SPI_1_CyBtldrCommStart
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommStart function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_CyBtldrCommStart(void)
{
    #if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
        if(SPI_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SPI_1_I2CCyBtldrCommStart();
        }
        else if(SPI_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SPI_1_SpiCyBtldrCommStart();
        }
        else if(SPI_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SPI_1_UartCyBtldrCommStart();
        }
        else if(SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
             SPI_1_EzI2CCyBtldrCommStart();
        }
        else
        {
            /* Unknown mode */
        }
    #elif(SPI_1_SCB_MODE_I2C_CONST_CFG)
        SPI_1_I2CCyBtldrCommStart();

    #elif(SPI_1_SCB_MODE_SPI_CONST_CFG)
        SPI_1_SpiCyBtldrCommStart();

    #elif(SPI_1_SCB_MODE_UART_CONST_CFG)
        SPI_1_UartCyBtldrCommStart();

    #elif(SPI_1_SCB_MODE_EZI2C_CONST_CFG)
        SPI_1_EzI2CCyBtldrCommStart();

    #else
        /* Unknown mode */

    #endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SPI_1_CyBtldrCommStop
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommStop function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_CyBtldrCommStop(void)
{
    #if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
        if(SPI_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SPI_1_I2CCyBtldrCommStop();
        }
        else if(SPI_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SPI_1_SpiCyBtldrCommStop();
        }
        else if(SPI_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SPI_1_UartCyBtldrCommStop();
        }
        else if(SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SPI_1_EzI2CCyBtldrCommStop();
        }
        else
        {
            /* Unknown mode */
        }
    #elif(SPI_1_SCB_MODE_I2C_CONST_CFG)
        SPI_1_I2CCyBtldrCommStop();

    #elif(SPI_1_SCB_MODE_SPI_CONST_CFG)
        SPI_1_SpiCyBtldrCommStop();

    #elif(SPI_1_SCB_MODE_UART_CONST_CFG)
        SPI_1_UartCyBtldrCommStop();

    #elif(SPI_1_SCB_MODE_EZI2C_CONST_CFG)
        SPI_1_EzI2CCyBtldrCommStop();

    #else
        /* Unknown mode */

    #endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SPI_1_CyBtldrCommReset
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommReset function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_CyBtldrCommReset(void)
{
    #if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
        if(SPI_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SPI_1_I2CCyBtldrCommReset();
        }
        else if(SPI_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SPI_1_SpiCyBtldrCommReset();
        }
        else if(SPI_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SPI_1_UartCyBtldrCommReset();
        }
        else if(SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SPI_1_EzI2CCyBtldrCommReset();
        }
        else
        {
            /* Unknown mode */
        }
    #elif(SPI_1_SCB_MODE_I2C_CONST_CFG)
        SPI_1_I2CCyBtldrCommReset();

    #elif(SPI_1_SCB_MODE_SPI_CONST_CFG)
        SPI_1_SpiCyBtldrCommReset();

    #elif(SPI_1_SCB_MODE_UART_CONST_CFG)
        SPI_1_UartCyBtldrCommReset();

    #elif(SPI_1_SCB_MODE_EZI2C_CONST_CFG)
        SPI_1_EzI2CCyBtldrCommReset();

    #else
        /* Unknown mode */

    #endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SPI_1_CyBtldrCommRead
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommRead function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to storage for the block of data to be read from the
*            bootloader host
*  size:     Number of bytes to be read.
*  count:    Pointer to the variable to write the number of bytes actually
*            read.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus SPI_1_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
        if(SPI_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = SPI_1_I2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(SPI_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = SPI_1_SpiCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(SPI_1_SCB_MODE_UART_RUNTM_CFG)
        {
            status = SPI_1_UartCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = SPI_1_EzI2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }

    #elif(SPI_1_SCB_MODE_I2C_CONST_CFG)
        status = SPI_1_I2CCyBtldrCommRead(pData, size, count, timeOut);

    #elif(SPI_1_SCB_MODE_SPI_CONST_CFG)
        status = SPI_1_SpiCyBtldrCommRead(pData, size, count, timeOut);

    #elif(SPI_1_SCB_MODE_UART_CONST_CFG)
        status = SPI_1_UartCyBtldrCommRead(pData, size, count, timeOut);

    #elif(SPI_1_SCB_MODE_EZI2C_CONST_CFG)
        status = SPI_1_EzI2CCyBtldrCommRead(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode: return status */

    #endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}


/*******************************************************************************
* Function Name: SPI_1_CyBtldrCommWrite
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommWrite  function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to the block of data to be written to the bootloader host.
*  size:     Number of bytes to be written.
*  count:    Pointer to the variable to write the number of bytes actually
*            written.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus SPI_1_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
        if(SPI_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = SPI_1_I2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(SPI_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = SPI_1_SpiCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(SPI_1_SCB_MODE_UART_RUNTM_CFG)
        {
            status = SPI_1_UartCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = SPI_1_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode */
        }
    #elif(SPI_1_SCB_MODE_I2C_CONST_CFG)
        status = SPI_1_I2CCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(SPI_1_SCB_MODE_SPI_CONST_CFG)
        status = SPI_1_SpiCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(SPI_1_SCB_MODE_UART_CONST_CFG)
        status = SPI_1_UartCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(SPI_1_SCB_MODE_EZI2C_CONST_CFG)
        status = SPI_1_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode */

    #endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_BTLDR_COMM_MODE_ENABLED) */


/* [] END OF FILE */
