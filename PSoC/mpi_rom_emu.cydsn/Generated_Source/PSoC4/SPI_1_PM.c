/*******************************************************************************
* File Name: SPI_1_PM.c
* Version 2.0
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI_1.h"
#include "SPI_1_PVT.h"

#if(SPI_1_SCB_MODE_I2C_INC)
    #include "SPI_1_I2C_PVT.h"
#endif /* (SPI_1_SCB_MODE_I2C_INC) */

#if(SPI_1_SCB_MODE_EZI2C_INC)
    #include "SPI_1_EZI2C_PVT.h"
#endif /* (SPI_1_SCB_MODE_EZI2C_INC) */

#if(SPI_1_SCB_MODE_SPI_INC || SPI_1_SCB_MODE_UART_INC)
    #include "SPI_1_SPI_UART_PVT.h"
#endif /* (SPI_1_SCB_MODE_SPI_INC || SPI_1_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG || \
   (SPI_1_SCB_MODE_I2C_CONST_CFG   && (!SPI_1_I2C_WAKE_ENABLE_CONST))   || \
   (SPI_1_SCB_MODE_EZI2C_CONST_CFG && (!SPI_1_EZI2C_WAKE_ENABLE_CONST)) || \
   (SPI_1_SCB_MODE_SPI_CONST_CFG   && (!SPI_1_SPI_WAKE_ENABLE_CONST))   || \
   (SPI_1_SCB_MODE_UART_CONST_CFG  && (!SPI_1_UART_WAKE_ENABLE_CONST)))

    SPI_1_BACKUP_STRUCT SPI_1_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: SPI_1_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component to enter Deep Sleep.
*  The "Enable wakeup from Sleep Mode" selection has an influence on
*  this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_Sleep(void)
{
#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)

    if(SPI_1_SCB_WAKE_ENABLE_CHECK)
    {
        if(SPI_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SPI_1_I2CSaveConfig();
        }
        else if(SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SPI_1_EzI2CSaveConfig();
        }
    #if(!SPI_1_CY_SCBIP_V1)
        else if(SPI_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SPI_1_SpiSaveConfig();
        }
        else if(SPI_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SPI_1_UartSaveConfig();
        }
    #endif /* (!SPI_1_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        SPI_1_backup.enableState = (uint8) SPI_1_GET_CTRL_ENABLED;

        if(0u != SPI_1_backup.enableState)
        {
            SPI_1_Stop();
        }
    }

#else

    #if (SPI_1_SCB_MODE_I2C_CONST_CFG && SPI_1_I2C_WAKE_ENABLE_CONST)
        SPI_1_I2CSaveConfig();

    #elif (SPI_1_SCB_MODE_EZI2C_CONST_CFG && SPI_1_EZI2C_WAKE_ENABLE_CONST)
        SPI_1_EzI2CSaveConfig();

    #elif (SPI_1_SCB_MODE_SPI_CONST_CFG && SPI_1_SPI_WAKE_ENABLE_CONST)
        SPI_1_SpiSaveConfig();

    #elif (SPI_1_SCB_MODE_UART_CONST_CFG && SPI_1_UART_WAKE_ENABLE_CONST)
        SPI_1_UartSaveConfig();

    #else

        SPI_1_backup.enableState = (uint8) SPI_1_GET_CTRL_ENABLED;

        if(0u != SPI_1_backup.enableState)
        {
            SPI_1_Stop();
        }

    #endif /* defined (SPI_1_SCB_MODE_I2C_CONST_CFG) && (SPI_1_I2C_WAKE_ENABLE_CONST) */

#endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SPI_1_Wakeup
********************************************************************************
*
* Summary:
*  Prepares the component for the Active mode operation after exiting
*  Deep Sleep. The "Enable wakeup from Sleep Mode" option has an influence
*  on this function implementation.
*  This function should not be called after exiting Sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_Wakeup(void)
{
#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)

    if(SPI_1_SCB_WAKE_ENABLE_CHECK)
    {
        if(SPI_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SPI_1_I2CRestoreConfig();
        }
        else if(SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SPI_1_EzI2CRestoreConfig();
        }
    #if(!SPI_1_CY_SCBIP_V1)
        else if(SPI_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SPI_1_SpiRestoreConfig();
        }
        else if(SPI_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SPI_1_UartRestoreConfig();
        }
    #endif /* (!SPI_1_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != SPI_1_backup.enableState)
        {
            SPI_1_Enable();
        }
    }

#else

    #if (SPI_1_SCB_MODE_I2C_CONST_CFG  && SPI_1_I2C_WAKE_ENABLE_CONST)
        SPI_1_I2CRestoreConfig();

    #elif (SPI_1_SCB_MODE_EZI2C_CONST_CFG && SPI_1_EZI2C_WAKE_ENABLE_CONST)
        SPI_1_EzI2CRestoreConfig();

    #elif (SPI_1_SCB_MODE_SPI_CONST_CFG && SPI_1_SPI_WAKE_ENABLE_CONST)
        SPI_1_SpiRestoreConfig();

    #elif (SPI_1_SCB_MODE_UART_CONST_CFG && SPI_1_UART_WAKE_ENABLE_CONST)
        SPI_1_UartRestoreConfig();

    #else

        if(0u != SPI_1_backup.enableState)
        {
            SPI_1_Enable();
        }

    #endif /* (SPI_1_I2C_WAKE_ENABLE_CONST) */

#endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
