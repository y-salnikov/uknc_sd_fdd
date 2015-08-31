/*******************************************************************************
* File Name: SPI_1_SPI.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the SCB Component in
*  SPI mode.
*
* Note:
*
*******************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI_1_PVT.h"
#include "SPI_1_SPI_UART_PVT.h"

#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    const SPI_1_SPI_INIT_STRUCT SPI_1_configSpi =
    {
        SPI_1_SPI_MODE,
        SPI_1_SPI_SUB_MODE,
        SPI_1_SPI_CLOCK_MODE,
        SPI_1_SPI_OVS_FACTOR,
        SPI_1_SPI_MEDIAN_FILTER_ENABLE,
        SPI_1_SPI_LATE_MISO_SAMPLE_ENABLE,
        SPI_1_SPI_WAKE_ENABLE,
        SPI_1_SPI_RX_DATA_BITS_NUM,
        SPI_1_SPI_TX_DATA_BITS_NUM,
        SPI_1_SPI_BITS_ORDER,
        SPI_1_SPI_TRANSFER_SEPARATION,
        0u,
        NULL,
        0u,
        NULL,
        (uint32) SPI_1_SCB_IRQ_INTERNAL,
        SPI_1_SPI_INTR_RX_MASK,
        SPI_1_SPI_RX_TRIGGER_LEVEL,
        SPI_1_SPI_INTR_TX_MASK,
        SPI_1_SPI_TX_TRIGGER_LEVEL,
        (uint8) SPI_1_SPI_BYTE_MODE_ENABLE,
        (uint8) SPI_1_SPI_FREE_RUN_SCLK_ENABLE,
        (uint8) SPI_1_SPI_SS_POLARITY
    };


    /*******************************************************************************
    * Function Name: SPI_1_SpiInit
    ********************************************************************************
    *
    * Summary:
    *  Configures the SCB for the SPI operation.
    *
    * Parameters:
    *  config:  Pointer to a structure that contains the following ordered list of
    *           fields. These fields match the selections available in the
    *           customizer.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPI_1_SpiInit(const SPI_1_SPI_INIT_STRUCT *config)
    {
        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Configure pins */
            SPI_1_SetPins(SPI_1_SCB_MODE_SPI, config->mode, SPI_1_DUMMY_PARAM);

            /* Store internal configuration */
            SPI_1_scbMode       = (uint8) SPI_1_SCB_MODE_SPI;
            SPI_1_scbEnableWake = (uint8) config->enableWake;
            SPI_1_scbEnableIntr = (uint8) config->enableInterrupt;

            /* Set RX direction internal variables */
            SPI_1_rxBuffer      =         config->rxBuffer;
            SPI_1_rxDataBits    = (uint8) config->rxDataBits;
            SPI_1_rxBufferSize  = (uint8) config->rxBufferSize;

            /* Set TX direction internal variables */
            SPI_1_txBuffer      =         config->txBuffer;
            SPI_1_txDataBits    = (uint8) config->txDataBits;
            SPI_1_txBufferSize  = (uint8) config->txBufferSize;

            /* Configure SPI interface */
            SPI_1_CTRL_REG     = SPI_1_GET_CTRL_OVS(config->oversample)           |
                                            SPI_1_GET_CTRL_BYTE_MODE(config->enableByteMode) |
                                            SPI_1_GET_CTRL_EC_AM_MODE(config->enableWake)    |
                                            SPI_1_CTRL_SPI;

            SPI_1_SPI_CTRL_REG = SPI_1_GET_SPI_CTRL_CONTINUOUS    (config->transferSeperation)  |
                                            SPI_1_GET_SPI_CTRL_SELECT_PRECEDE(config->submode &
                                                                          SPI_1_SPI_MODE_TI_PRECEDES_MASK) |
                                            SPI_1_GET_SPI_CTRL_SCLK_MODE     (config->sclkMode)            |
                                            SPI_1_GET_SPI_CTRL_LATE_MISO_SAMPLE(config->enableLateSampling)|
                                            SPI_1_GET_SPI_CTRL_SCLK_CONTINUOUS(config->enableFreeRunSclk)  |
                                            SPI_1_GET_SPI_CTRL_SSEL_POLARITY (config->polaritySs)          |
                                            SPI_1_GET_SPI_CTRL_SUB_MODE      (config->submode)             |
                                            SPI_1_GET_SPI_CTRL_MASTER_MODE   (config->mode);

            /* Configure RX direction */
            SPI_1_RX_CTRL_REG     =  SPI_1_GET_RX_CTRL_DATA_WIDTH(config->rxDataBits)         |
                                                SPI_1_GET_RX_CTRL_BIT_ORDER (config->bitOrder)           |
                                                SPI_1_GET_RX_CTRL_MEDIAN    (config->enableMedianFilter) |
                                                SPI_1_SPI_RX_CTRL;

            SPI_1_RX_FIFO_CTRL_REG = SPI_1_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(config->rxTriggerLevel);

            /* Configure TX direction */
            SPI_1_TX_CTRL_REG      = SPI_1_GET_TX_CTRL_DATA_WIDTH(config->txDataBits) |
                                                SPI_1_GET_TX_CTRL_BIT_ORDER (config->bitOrder)   |
                                                SPI_1_SPI_TX_CTRL;

            SPI_1_TX_FIFO_CTRL_REG = SPI_1_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(config->txTriggerLevel);

            /* Configure interrupt with SPI handler but do not enable it */
            CyIntDisable    (SPI_1_ISR_NUMBER);
            CyIntSetPriority(SPI_1_ISR_NUMBER, SPI_1_ISR_PRIORITY);
            (void) CyIntSetVector(SPI_1_ISR_NUMBER, &SPI_1_SPI_UART_ISR);

            /* Configure interrupt sources */
            SPI_1_INTR_I2C_EC_MASK_REG = SPI_1_NO_INTR_SOURCES;
            SPI_1_INTR_SPI_EC_MASK_REG = SPI_1_NO_INTR_SOURCES;
            SPI_1_INTR_SLAVE_MASK_REG  = SPI_1_GET_SPI_INTR_SLAVE_MASK(config->rxInterruptMask);
            SPI_1_INTR_MASTER_MASK_REG = SPI_1_GET_SPI_INTR_MASTER_MASK(config->txInterruptMask);
            SPI_1_INTR_RX_MASK_REG     = SPI_1_GET_SPI_INTR_RX_MASK(config->rxInterruptMask);
            SPI_1_INTR_TX_MASK_REG     = SPI_1_GET_SPI_INTR_TX_MASK(config->txInterruptMask);

            /* Set active SS0 */
            SPI_1_SpiSetActiveSlaveSelect(SPI_1_SPI_SLAVE_SELECT0);

            /* Clear RX buffer indexes */
            SPI_1_rxBufferHead     = 0u;
            SPI_1_rxBufferTail     = 0u;
            SPI_1_rxBufferOverflow = 0u;

            /* Clear TX buffer indexes */
            SPI_1_txBufferHead = 0u;
            SPI_1_txBufferTail = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: SPI_1_SpiInit
    ********************************************************************************
    *
    * Summary:
    *  Configures the SCB for the SPI operation.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPI_1_SpiInit(void)
    {
        /* Configure SPI interface */
        SPI_1_CTRL_REG     = SPI_1_SPI_DEFAULT_CTRL;
        SPI_1_SPI_CTRL_REG = SPI_1_SPI_DEFAULT_SPI_CTRL;

        /* Configure TX and RX direction */
        SPI_1_RX_CTRL_REG      = SPI_1_SPI_DEFAULT_RX_CTRL;
        SPI_1_RX_FIFO_CTRL_REG = SPI_1_SPI_DEFAULT_RX_FIFO_CTRL;

        /* Configure TX and RX direction */
        SPI_1_TX_CTRL_REG      = SPI_1_SPI_DEFAULT_TX_CTRL;
        SPI_1_TX_FIFO_CTRL_REG = SPI_1_SPI_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with SPI handler but do not enable it */
    #if(SPI_1_SCB_IRQ_INTERNAL)
            CyIntDisable    (SPI_1_ISR_NUMBER);
            CyIntSetPriority(SPI_1_ISR_NUMBER, SPI_1_ISR_PRIORITY);
            (void) CyIntSetVector(SPI_1_ISR_NUMBER, &SPI_1_SPI_UART_ISR);
    #endif /* (SPI_1_SCB_IRQ_INTERNAL) */

        /* Configure interrupt sources */
        SPI_1_INTR_I2C_EC_MASK_REG = SPI_1_SPI_DEFAULT_INTR_I2C_EC_MASK;
        SPI_1_INTR_SPI_EC_MASK_REG = SPI_1_SPI_DEFAULT_INTR_SPI_EC_MASK;
        SPI_1_INTR_SLAVE_MASK_REG  = SPI_1_SPI_DEFAULT_INTR_SLAVE_MASK;
        SPI_1_INTR_MASTER_MASK_REG = SPI_1_SPI_DEFAULT_INTR_MASTER_MASK;
        SPI_1_INTR_RX_MASK_REG     = SPI_1_SPI_DEFAULT_INTR_RX_MASK;
        SPI_1_INTR_TX_MASK_REG     = SPI_1_SPI_DEFAULT_INTR_TX_MASK;

        /* Set active SS0 for master */
    #if (SPI_1_SPI_MASTER_CONST)
        SPI_1_SpiSetActiveSlaveSelect(SPI_1_SPI_SLAVE_SELECT0);
    #endif /* (SPI_1_SPI_MASTER_CONST) */

    #if(SPI_1_INTERNAL_RX_SW_BUFFER_CONST)
        SPI_1_rxBufferHead     = 0u;
        SPI_1_rxBufferTail     = 0u;
        SPI_1_rxBufferOverflow = 0u;
    #endif /* (SPI_1_INTERNAL_RX_SW_BUFFER_CONST) */

    #if(SPI_1_INTERNAL_TX_SW_BUFFER_CONST)
        SPI_1_txBufferHead = 0u;
        SPI_1_txBufferTail = 0u;
    #endif /* (SPI_1_INTERNAL_TX_SW_BUFFER_CONST) */


    }
#endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (SPI_1_SPI_MASTER_CONST)
    /*******************************************************************************
    * Function Name: SPI_1_SetActiveSlaveSelect
    ********************************************************************************
    *
    * Summary:
    *  Selects one of the four slave select lines to be active during the transfer.
    *  After initialization the active slave select line is 0.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled
    *   - The component has completed transfer (TX FIFO is empty and the
    *     SCB_INTR_MASTER_SPI_DONE status is set)
    *  This function does not check that these conditions are met.
    *  This function is only applicable to SPI Master mode of operation.
    *
    * Parameters:
    *  slaveSelect: slave select line which will be active while the following
    *               transfer.
    *   SPI_1_SPI_SLAVE_SELECT0 - Slave select 0
    *   SPI_1_SPI_SLAVE_SELECT1 - Slave select 1
    *   SPI_1_SPI_SLAVE_SELECT2 - Slave select 2
    *   SPI_1_SPI_SLAVE_SELECT3 - Slave select 3
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPI_1_SpiSetActiveSlaveSelect(uint32 slaveSelect)
    {
        uint32 spiCtrl;

        spiCtrl = SPI_1_SPI_CTRL_REG;

        spiCtrl &= (uint32) ~SPI_1_SPI_CTRL_SLAVE_SELECT_MASK;
        spiCtrl |= (uint32)  SPI_1_GET_SPI_CTRL_SS(slaveSelect);

        SPI_1_SPI_CTRL_REG = spiCtrl;
    }
#endif /* (SPI_1_SPI_MASTER_CONST) */


#if !(SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: SPI_1_SpiSetSlaveSelectPolarity
    ********************************************************************************
    *
    * Summary:
    *  Sets active polarity for slave select line.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled.
    *   - The component has completed transfer.
    *  This function does not check that these conditions are met.
    *
    * Parameters:
    *  slaveSelect: slave select line to change active polarity.
    *   SPI_1_SPI_SLAVE_SELECT0 - Slave select 0
    *   SPI_1_SPI_SLAVE_SELECT1 - Slave select 1
    *   SPI_1_SPI_SLAVE_SELECT2 - Slave select 2
    *   SPI_1_SPI_SLAVE_SELECT3 - Slave select 3
    *
    *  polarity: active polarity of slave select line.
    *   SPI_1_SPI_SS_ACTIVE_LOW  - Slave select is active low
    *   SPI_1_SPI_SS_ACTIVE_HIGH - Slave select is active high
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPI_1_SpiSetSlaveSelectPolarity(uint32 slaveSelect, uint32 polarity)
    {
        uint32 ssPolarity;

        /* Get position of the polarity bit associated with slave select line */
        ssPolarity = SPI_1_GET_SPI_CTRL_SSEL_POLARITY((uint32) 1u << slaveSelect);

        if (0u != polarity)
        {
            SPI_1_SPI_CTRL_REG |= (uint32)  ssPolarity;
        }
        else
        {
            SPI_1_SPI_CTRL_REG &= (uint32) ~ssPolarity;
        }
    }
#endif /* !(SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1) */


#if(SPI_1_SPI_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: SPI_1_SpiSaveConfig
    ********************************************************************************
    *
    * Summary:
    *  Clears INTR_SPI_EC.WAKE_UP and enables it. This interrupt
    *  source triggers when the master assigns the SS line and wakes up the device.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPI_1_SpiSaveConfig(void)
    {
        SPI_1_ClearSpiExtClkInterruptSource(SPI_1_INTR_SPI_EC_WAKE_UP);
        SPI_1_SetSpiExtClkInterruptMode(SPI_1_INTR_SPI_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: SPI_1_SpiRestoreConfig
    ********************************************************************************
    *
    * Summary:
    *  Disables the INTR_SPI_EC.WAKE_UP interrupt source. After wakeup
    *  slave does not drive the MISO line and the master receives 0xFF.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPI_1_SpiRestoreConfig(void)
    {
        SPI_1_SetSpiExtClkInterruptMode(SPI_1_NO_INTR_SOURCES);
    }
#endif /* (SPI_1_SPI_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
