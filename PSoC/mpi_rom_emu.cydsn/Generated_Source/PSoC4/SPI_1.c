/*******************************************************************************
* File Name: SPI_1.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the SCB Component.
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
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 SPI_1_scbMode = SPI_1_SCB_MODE_UNCONFIG;
    uint8 SPI_1_scbEnableWake;
    uint8 SPI_1_scbEnableIntr;

    /* I2C configuration variables */
    uint8 SPI_1_mode;
    uint8 SPI_1_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * SPI_1_rxBuffer;
    uint8  SPI_1_rxDataBits;
    uint32 SPI_1_rxBufferSize;

    volatile uint8 * SPI_1_txBuffer;
    uint8  SPI_1_txDataBits;
    uint32 SPI_1_txBufferSize;

    /* EZI2C configuration variables */
    uint8 SPI_1_numberOfAddr;
    uint8 SPI_1_subAddrSize;
#endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/

uint8 SPI_1_initVar = 0u;

#if !defined (CY_REMOVE_SPI_1_CUSTOM_INTR_HANDLER)
    cyisraddress SPI_1_customIntrHandler = NULL;
#endif /* !defined (CY_REMOVE_SPI_1_CUSTOM_INTR_HANDLER) */


/***************************************
*    Private Function Prototypes
***************************************/

static void SPI_1_ScbEnableIntr(void);
static void SPI_1_ScbModeStop(void);


/*******************************************************************************
* Function Name: SPI_1_Init
********************************************************************************
*
* Summary:
*  Initializes the SCB component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  SCB_I2CInit, SCB_SpiInit, SCB_UartInit or SCB_EzI2CInit.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_Init(void)
{
#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
    if(SPI_1_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        SPI_1_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif(SPI_1_SCB_MODE_I2C_CONST_CFG)
    SPI_1_I2CInit();

#elif(SPI_1_SCB_MODE_SPI_CONST_CFG)
    SPI_1_SpiInit();

#elif(SPI_1_SCB_MODE_UART_CONST_CFG)
    SPI_1_UartInit();

#elif(SPI_1_SCB_MODE_EZI2C_CONST_CFG)
    SPI_1_EzI2CInit();

#endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SPI_1_Enable
********************************************************************************
*
* Summary:
*  Enables the SCB component operation.
*  The SCB configuration should be not changed when the component is enabled.
*  Any configuration changes should be made after disabling the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_Enable(void)
{
#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if(!SPI_1_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        SPI_1_CTRL_REG |= SPI_1_CTRL_ENABLED;

        SPI_1_ScbEnableIntr();
    }
#else
    SPI_1_CTRL_REG |= SPI_1_CTRL_ENABLED;

    SPI_1_ScbEnableIntr();
#endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SPI_1_Start
********************************************************************************
*
* Summary:
*  Invokes SCB_Init() and SCB_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZ I2C. Otherwise this function does not enable the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SPI_1_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void SPI_1_Start(void)
{
    if(0u == SPI_1_initVar)
    {
        SPI_1_Init();
        SPI_1_initVar = 1u; /* Component was initialized */
    }

    SPI_1_Enable();
}


/*******************************************************************************
* Function Name: SPI_1_Stop
********************************************************************************
*
* Summary:
*  Disables the SCB component and its interrupt.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_Stop(void)
{
#if(SPI_1_SCB_IRQ_INTERNAL)
    SPI_1_DisableInt();
#endif /* (SPI_1_SCB_IRQ_INTERNAL) */

    SPI_1_CTRL_REG &= (uint32) ~SPI_1_CTRL_ENABLED;  /* Disable scb IP */

#if(SPI_1_SCB_IRQ_INTERNAL)
    SPI_1_ClearPendingInt();
#endif /* (SPI_1_SCB_IRQ_INTERNAL) */

    SPI_1_ScbModeStop(); /* Calls scbMode specific Stop function */
}


/*******************************************************************************
* Function Name: SPI_1_SetRxFifoLevel
********************************************************************************
*
* Summary:
*  Sets level in the RX FIFO to generate a RX level interrupt.
*  When the RX FIFO has more entries than the RX FIFO level an RX level
*  interrupt request is generated.
*
* Parameters:
*  level: Level in the RX FIFO to generate RX level interrupt.
*         The range of valid level values is between 0 and RX FIFO depth - 1.
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = SPI_1_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~SPI_1_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (SPI_1_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    SPI_1_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: SPI_1_SetTxFifoLevel
********************************************************************************
*
* Summary:
*  Sets level in the TX FIFO to generate a TX level interrupt.
*  When the TX FIFO has more entries than the TX FIFO level an TX level
*  interrupt request is generated.
*
* Parameters:
*  level: Level in the TX FIFO to generate TX level interrupt.
*         The range of valid level values is between 0 and TX FIFO depth - 1.
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = SPI_1_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~SPI_1_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (SPI_1_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    SPI_1_TX_FIFO_CTRL_REG = txFifoCtrl;
}


/*******************************************************************************
* Function Name: SPI_1_SetCustomInterruptHandler
********************************************************************************
*
* Summary:
*  Registers a function to be called by the internal interrupt handler.
*  First the function that is registered is called, then the internal interrupt
*  handler performs any operation such as software buffer management functions
*  before the interrupt returns.  It is the user's responsibility not to break
*  the software buffer operations. Only one custom handler is supported, which
*  is the function provided by the most recent call.
*  At the initialization time no custom handler is registered.
*
* Parameters:
*  func: Pointer to the function to register.
*        The value NULL indicates to remove the current custom interrupt
*        handler.
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_SetCustomInterruptHandler(cyisraddress func)
{
#if !defined (CY_REMOVE_SPI_1_CUSTOM_INTR_HANDLER)
    SPI_1_customIntrHandler = func; /* Register interrupt handler */
#else
    if(NULL != func)
    {
        /* Suppress compiler warning */
    }
#endif /* !defined (CY_REMOVE_SPI_1_CUSTOM_INTR_HANDLER) */
}


/*******************************************************************************
* Function Name: SPI_1_ScbModeEnableIntr
********************************************************************************
*
* Summary:
*  Enables an interrupt for a specific mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void SPI_1_ScbEnableIntr(void)
{
#if(SPI_1_SCB_IRQ_INTERNAL)
    #if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Enable interrupt in NVIC */
        if(0u != SPI_1_scbEnableIntr)
        {
            SPI_1_EnableInt();
        }
    #else
        SPI_1_EnableInt();

    #endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (SPI_1_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: SPI_1_ScbModeStop
********************************************************************************
*
* Summary:
*  Calls the Stop function for a specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void SPI_1_ScbModeStop(void)
{
#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
    if(SPI_1_SCB_MODE_I2C_RUNTM_CFG)
    {
        SPI_1_I2CStop();
    }
    else if (SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        SPI_1_EzI2CStop();
    }
#if (!SPI_1_CY_SCBIP_V1)
    else if (SPI_1_SCB_MODE_UART_RUNTM_CFG)
    {
        SPI_1_UartStop();
    }
#endif /* (!SPI_1_CY_SCBIP_V1) */
    else
    {
        /* Do nothing for other modes */
    }
#elif(SPI_1_SCB_MODE_I2C_CONST_CFG)
    SPI_1_I2CStop();

#elif(SPI_1_SCB_MODE_EZI2C_CONST_CFG)
    SPI_1_EzI2CStop();

#elif(SPI_1_SCB_MODE_UART_CONST_CFG)
    SPI_1_UartStop();

#endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: SPI_1_SetPins
    ********************************************************************************
    *
    * Summary:
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    * Parameters:
    *  mode:      Mode of SCB operation.
    *  subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  uartEnableMask: enables TX or RX direction and RTS and CTS signals.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPI_1_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 hsiomSel [SPI_1_SCB_PINS_NUMBER];
        uint32 pinsDm   [SPI_1_SCB_PINS_NUMBER];

    #if (!SPI_1_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!SPI_1_CY_SCBIP_V1) */

        uint32 i;

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for(i = 0u; i < SPI_1_SCB_PINS_NUMBER; i++)
        {
            hsiomSel[i]  = SPI_1_HSIOM_DEF_SEL;
            pinsDm[i]    = SPI_1_PIN_DM_ALG_HIZ;
        }

        if((SPI_1_SCB_MODE_I2C   == mode) ||
           (SPI_1_SCB_MODE_EZI2C == mode))
        {
            hsiomSel[SPI_1_MOSI_SCL_RX_PIN_INDEX] = SPI_1_HSIOM_I2C_SEL;
            hsiomSel[SPI_1_MISO_SDA_TX_PIN_INDEX] = SPI_1_HSIOM_I2C_SEL;

            pinsDm[SPI_1_MOSI_SCL_RX_PIN_INDEX] = SPI_1_PIN_DM_OD_LO;
            pinsDm[SPI_1_MISO_SDA_TX_PIN_INDEX] = SPI_1_PIN_DM_OD_LO;
        }
    #if (!SPI_1_CY_SCBIP_V1)
        else if(SPI_1_SCB_MODE_SPI == mode)
        {
            hsiomSel[SPI_1_MOSI_SCL_RX_PIN_INDEX] = SPI_1_HSIOM_SPI_SEL;
            hsiomSel[SPI_1_MISO_SDA_TX_PIN_INDEX] = SPI_1_HSIOM_SPI_SEL;
            hsiomSel[SPI_1_SCLK_PIN_INDEX]        = SPI_1_HSIOM_SPI_SEL;

            if(SPI_1_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[SPI_1_MOSI_SCL_RX_PIN_INDEX] = SPI_1_PIN_DM_DIG_HIZ;
                pinsDm[SPI_1_MISO_SDA_TX_PIN_INDEX] = SPI_1_PIN_DM_STRONG;
                pinsDm[SPI_1_SCLK_PIN_INDEX]        = SPI_1_PIN_DM_DIG_HIZ;

            #if(SPI_1_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[SPI_1_SS0_PIN_INDEX] = SPI_1_HSIOM_SPI_SEL;
                pinsDm  [SPI_1_SS0_PIN_INDEX] = SPI_1_PIN_DM_DIG_HIZ;
            #endif /* (SPI_1_SS1_PIN) */

            #if(SPI_1_MISO_SDA_TX_PIN)
                /* Disable input buffer */
                 pinsInBuf |= SPI_1_MISO_SDA_TX_PIN_MASK;
            #endif /* (SPI_1_MISO_SDA_TX_PIN_PIN) */
            }
            else /* (Master) */
            {
                pinsDm[SPI_1_MOSI_SCL_RX_PIN_INDEX] = SPI_1_PIN_DM_STRONG;
                pinsDm[SPI_1_MISO_SDA_TX_PIN_INDEX] = SPI_1_PIN_DM_DIG_HIZ;
                pinsDm[SPI_1_SCLK_PIN_INDEX]        = SPI_1_PIN_DM_STRONG;

            #if(SPI_1_SS0_PIN)
                hsiomSel [SPI_1_SS0_PIN_INDEX] = SPI_1_HSIOM_SPI_SEL;
                pinsDm   [SPI_1_SS0_PIN_INDEX] = SPI_1_PIN_DM_STRONG;
                pinsInBuf                                |= SPI_1_SS0_PIN_MASK;
            #endif /* (SPI_1_SS0_PIN) */

            #if(SPI_1_SS1_PIN)
                hsiomSel [SPI_1_SS1_PIN_INDEX] = SPI_1_HSIOM_SPI_SEL;
                pinsDm   [SPI_1_SS1_PIN_INDEX] = SPI_1_PIN_DM_STRONG;
                pinsInBuf                                |= SPI_1_SS1_PIN_MASK;
            #endif /* (SPI_1_SS1_PIN) */

            #if(SPI_1_SS2_PIN)
                hsiomSel [SPI_1_SS2_PIN_INDEX] = SPI_1_HSIOM_SPI_SEL;
                pinsDm   [SPI_1_SS2_PIN_INDEX] = SPI_1_PIN_DM_STRONG;
                pinsInBuf                                |= SPI_1_SS2_PIN_MASK;
            #endif /* (SPI_1_SS2_PIN) */

            #if(SPI_1_SS3_PIN)
                hsiomSel [SPI_1_SS3_PIN_INDEX] = SPI_1_HSIOM_SPI_SEL;
                pinsDm   [SPI_1_SS3_PIN_INDEX] = SPI_1_PIN_DM_STRONG;
                pinsInBuf                                |= SPI_1_SS3_PIN_MASK;
            #endif /* (SPI_1_SS2_PIN) */

                /* Disable input buffers */
            #if(SPI_1_MOSI_SCL_RX_PIN)
                pinsInBuf |= SPI_1_MOSI_SCL_RX_PIN_MASK;
            #endif /* (SPI_1_MOSI_SCL_RX_PIN) */

             #if(SPI_1_MOSI_SCL_RX_WAKE_PIN)
                pinsInBuf |= SPI_1_MOSI_SCL_RX_WAKE_PIN_MASK;
            #endif /* (SPI_1_MOSI_SCL_RX_WAKE_PIN) */

            #if(SPI_1_SCLK_PIN)
                pinsInBuf |= SPI_1_SCLK_PIN_MASK;
            #endif /* (SPI_1_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if(SPI_1_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
                hsiomSel[SPI_1_MISO_SDA_TX_PIN_INDEX] = SPI_1_HSIOM_UART_SEL;
                pinsDm  [SPI_1_MISO_SDA_TX_PIN_INDEX] = SPI_1_PIN_DM_OD_LO;
            }
            else /* Standard or IrDA */
            {
                if(0u != (SPI_1_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                    hsiomSel[SPI_1_MOSI_SCL_RX_PIN_INDEX] = SPI_1_HSIOM_UART_SEL;
                    pinsDm  [SPI_1_MOSI_SCL_RX_PIN_INDEX] = SPI_1_PIN_DM_DIG_HIZ;
                }

                if(0u != (SPI_1_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                    hsiomSel[SPI_1_MISO_SDA_TX_PIN_INDEX] = SPI_1_HSIOM_UART_SEL;
                    pinsDm  [SPI_1_MISO_SDA_TX_PIN_INDEX] = SPI_1_PIN_DM_STRONG;

                #if(SPI_1_MISO_SDA_TX_PIN)
                     pinsInBuf |= SPI_1_MISO_SDA_TX_PIN_MASK;
                #endif /* (SPI_1_MISO_SDA_TX_PIN_PIN) */
                }

            #if !(SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1)
                if(SPI_1_UART_MODE_STD == subMode)
                {
                    if(0u != (SPI_1_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                        hsiomSel[SPI_1_SCLK_PIN_INDEX] = SPI_1_HSIOM_UART_SEL;
                        pinsDm  [SPI_1_SCLK_PIN_INDEX] = SPI_1_PIN_DM_DIG_HIZ;
                    }

                    if(0u != (SPI_1_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                        hsiomSel[SPI_1_SS0_PIN_INDEX] = SPI_1_HSIOM_UART_SEL;
                        pinsDm  [SPI_1_SS0_PIN_INDEX] = SPI_1_PIN_DM_STRONG;

                    #if(SPI_1_SS0_PIN)
                        /* Disable input buffer */
                        pinsInBuf |= SPI_1_SS0_PIN_MASK;
                    #endif /* (SPI_1_SS0_PIN) */
                    }
                }
            #endif /* !(SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1) */
            }
        }
    #endif /* (!SPI_1_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if(SPI_1_MOSI_SCL_RX_PIN)
        SPI_1_SET_HSIOM_SEL(SPI_1_MOSI_SCL_RX_HSIOM_REG,
                                       SPI_1_MOSI_SCL_RX_HSIOM_MASK,
                                       SPI_1_MOSI_SCL_RX_HSIOM_POS,
                                       hsiomSel[SPI_1_MOSI_SCL_RX_PIN_INDEX]);

        SPI_1_spi_mosi_i2c_scl_uart_rx_SetDriveMode((uint8) pinsDm[SPI_1_MOSI_SCL_RX_PIN_INDEX]);

    #if (!SPI_1_CY_SCBIP_V1)
        SPI_1_SET_INP_DIS(SPI_1_spi_mosi_i2c_scl_uart_rx_INP_DIS,
                                     SPI_1_spi_mosi_i2c_scl_uart_rx_MASK,
                                     (0u != (pinsInBuf & SPI_1_MOSI_SCL_RX_PIN_MASK)));
    #endif /* (!SPI_1_CY_SCBIP_V1) */
    #endif /* (SPI_1_MOSI_SCL_RX_PIN) */

    #if(SPI_1_MOSI_SCL_RX_WAKE_PIN)
        SPI_1_SET_HSIOM_SEL(SPI_1_MOSI_SCL_RX_WAKE_HSIOM_REG,
                                       SPI_1_MOSI_SCL_RX_WAKE_HSIOM_MASK,
                                       SPI_1_MOSI_SCL_RX_WAKE_HSIOM_POS,
                                       hsiomSel[SPI_1_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        SPI_1_spi_mosi_i2c_scl_uart_rx_wake_SetDriveMode((uint8)
                                                               pinsDm[SPI_1_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        SPI_1_SET_INP_DIS(SPI_1_spi_mosi_i2c_scl_uart_rx_wake_INP_DIS,
                                     SPI_1_spi_mosi_i2c_scl_uart_rx_wake_MASK,
                                     (0u != (pinsInBuf & SPI_1_MOSI_SCL_RX_WAKE_PIN_MASK)));

         /* Set interrupt on falling edge */
        SPI_1_SET_INCFG_TYPE(SPI_1_MOSI_SCL_RX_WAKE_INTCFG_REG,
                                        SPI_1_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK,
                                        SPI_1_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS,
                                        SPI_1_INTCFG_TYPE_FALLING_EDGE);
    #endif /* (SPI_1_MOSI_SCL_RX_WAKE_PIN) */

    #if(SPI_1_MISO_SDA_TX_PIN)
        SPI_1_SET_HSIOM_SEL(SPI_1_MISO_SDA_TX_HSIOM_REG,
                                       SPI_1_MISO_SDA_TX_HSIOM_MASK,
                                       SPI_1_MISO_SDA_TX_HSIOM_POS,
                                       hsiomSel[SPI_1_MISO_SDA_TX_PIN_INDEX]);

        SPI_1_spi_miso_i2c_sda_uart_tx_SetDriveMode((uint8) pinsDm[SPI_1_MISO_SDA_TX_PIN_INDEX]);

    #if (!SPI_1_CY_SCBIP_V1)
        SPI_1_SET_INP_DIS(SPI_1_spi_miso_i2c_sda_uart_tx_INP_DIS,
                                     SPI_1_spi_miso_i2c_sda_uart_tx_MASK,
                                    (0u != (pinsInBuf & SPI_1_MISO_SDA_TX_PIN_MASK)));
    #endif /* (!SPI_1_CY_SCBIP_V1) */
    #endif /* (SPI_1_MOSI_SCL_RX_PIN) */

    #if(SPI_1_SCLK_PIN)
        SPI_1_SET_HSIOM_SEL(SPI_1_SCLK_HSIOM_REG, SPI_1_SCLK_HSIOM_MASK,
                                       SPI_1_SCLK_HSIOM_POS, hsiomSel[SPI_1_SCLK_PIN_INDEX]);

        SPI_1_spi_sclk_SetDriveMode((uint8) pinsDm[SPI_1_SCLK_PIN_INDEX]);

        SPI_1_SET_INP_DIS(SPI_1_spi_sclk_INP_DIS,
                                     SPI_1_spi_sclk_MASK,
                                     (0u != (pinsInBuf & SPI_1_SCLK_PIN_MASK)));
    #endif /* (SPI_1_SCLK_PIN) */

    #if(SPI_1_SS0_PIN)
        SPI_1_SET_HSIOM_SEL(SPI_1_SS0_HSIOM_REG, SPI_1_SS0_HSIOM_MASK,
                                       SPI_1_SS0_HSIOM_POS, hsiomSel[SPI_1_SS0_PIN_INDEX]);

        SPI_1_spi_ss0_SetDriveMode((uint8) pinsDm[SPI_1_SS0_PIN_INDEX]);

        SPI_1_SET_INP_DIS(SPI_1_spi_ss0_INP_DIS,
                                     SPI_1_spi_ss0_MASK,
                                     (0u != (pinsInBuf & SPI_1_SS0_PIN_MASK)));
    #endif /* (SPI_1_SS1_PIN) */

    #if(SPI_1_SS1_PIN)
        SPI_1_SET_HSIOM_SEL(SPI_1_SS1_HSIOM_REG, SPI_1_SS1_HSIOM_MASK,
                                       SPI_1_SS1_HSIOM_POS, hsiomSel[SPI_1_SS1_PIN_INDEX]);

        SPI_1_spi_ss1_SetDriveMode((uint8) pinsDm[SPI_1_SS1_PIN_INDEX]);

        SPI_1_SET_INP_DIS(SPI_1_spi_ss1_INP_DIS,
                                     SPI_1_spi_ss1_MASK,
                                     (0u != (pinsInBuf & SPI_1_SS1_PIN_MASK)));
    #endif /* (SPI_1_SS1_PIN) */

    #if(SPI_1_SS2_PIN)
        SPI_1_SET_HSIOM_SEL(SPI_1_SS2_HSIOM_REG, SPI_1_SS2_HSIOM_MASK,
                                       SPI_1_SS2_HSIOM_POS, hsiomSel[SPI_1_SS2_PIN_INDEX]);

        SPI_1_spi_ss2_SetDriveMode((uint8) pinsDm[SPI_1_SS2_PIN_INDEX]);

        SPI_1_SET_INP_DIS(SPI_1_spi_ss2_INP_DIS,
                                     SPI_1_spi_ss2_MASK,
                                     (0u != (pinsInBuf & SPI_1_SS2_PIN_MASK)));
    #endif /* (SPI_1_SS2_PIN) */

    #if(SPI_1_SS3_PIN)
        SPI_1_SET_HSIOM_SEL(SPI_1_SS3_HSIOM_REG,  SPI_1_SS3_HSIOM_MASK,
                                       SPI_1_SS3_HSIOM_POS, hsiomSel[SPI_1_SS3_PIN_INDEX]);

        SPI_1_spi_ss3_SetDriveMode((uint8) pinsDm[SPI_1_SS3_PIN_INDEX]);

        SPI_1_SET_INP_DIS(SPI_1_spi_ss3_INP_DIS,
                                     SPI_1_spi_ss3_MASK,
                                     (0u != (pinsInBuf & SPI_1_SS3_PIN_MASK)));
    #endif /* (SPI_1_SS3_PIN) */
    }

#endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: SPI_1_I2CSlaveNackGeneration
    ********************************************************************************
    *
    * Summary:
    *  Sets command to generate NACK to the address or data.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPI_1_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (SPI_1_CTRL_REG & SPI_1_CTRL_EC_AM_MODE)) &&
            (0u == (SPI_1_I2C_CTRL_REG & SPI_1_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            SPI_1_CTRL_REG &= ~SPI_1_CTRL_EC_AM_MODE;
            SPI_1_CTRL_REG |=  SPI_1_CTRL_EC_AM_MODE;
        }

        SPI_1_I2C_SLAVE_CMD_REG = SPI_1_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1) */


/* [] END OF FILE */
