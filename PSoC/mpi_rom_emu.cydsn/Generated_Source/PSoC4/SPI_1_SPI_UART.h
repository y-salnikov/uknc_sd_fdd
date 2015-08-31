/*******************************************************************************
* File Name: SPI_1_SPI_UART.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_SPI_1_H)
#define CY_SCB_SPI_UART_SPI_1_H

#include "SPI_1.h"


/***************************************
*   SPI Initial Parameter Constants
****************************************/

#define SPI_1_SPI_MODE                   (1u)
#define SPI_1_SPI_SUB_MODE               (0u)
#define SPI_1_SPI_CLOCK_MODE             (0u)
#define SPI_1_SPI_OVS_FACTOR             (16u)
#define SPI_1_SPI_MEDIAN_FILTER_ENABLE   (0u)
#define SPI_1_SPI_LATE_MISO_SAMPLE_ENABLE (0u)
#define SPI_1_SPI_RX_DATA_BITS_NUM       (8u)
#define SPI_1_SPI_TX_DATA_BITS_NUM       (8u)
#define SPI_1_SPI_WAKE_ENABLE            (0u)
#define SPI_1_SPI_BITS_ORDER             (1u)
#define SPI_1_SPI_TRANSFER_SEPARATION    (1u)
#define SPI_1_SPI_NUMBER_OF_SS_LINES     (1u)
#define SPI_1_SPI_RX_BUFFER_SIZE         (8u)
#define SPI_1_SPI_TX_BUFFER_SIZE         (8u)

#define SPI_1_SPI_INTERRUPT_MODE         (0u)

#define SPI_1_SPI_INTR_RX_MASK           (0u)
#define SPI_1_SPI_INTR_TX_MASK           (0u)

#define SPI_1_SPI_RX_TRIGGER_LEVEL       (7u)
#define SPI_1_SPI_TX_TRIGGER_LEVEL       (0u)

#define SPI_1_SPI_BYTE_MODE_ENABLE       (0u)
#define SPI_1_SPI_FREE_RUN_SCLK_ENABLE   (0u)
#define SPI_1_SPI_SS0_POLARITY           (0u)
#define SPI_1_SPI_SS1_POLARITY           (0u)
#define SPI_1_SPI_SS2_POLARITY           (0u)
#define SPI_1_SPI_SS3_POLARITY           (0u)


/***************************************
*   UART Initial Parameter Constants
****************************************/

#define SPI_1_UART_SUB_MODE              (0u)
#define SPI_1_UART_DIRECTION             (3u)
#define SPI_1_UART_DATA_BITS_NUM         (8u)
#define SPI_1_UART_PARITY_TYPE           (2u)
#define SPI_1_UART_STOP_BITS_NUM         (2u)
#define SPI_1_UART_OVS_FACTOR            (12u)
#define SPI_1_UART_IRDA_LOW_POWER        (0u)
#define SPI_1_UART_MEDIAN_FILTER_ENABLE  (0u)
#define SPI_1_UART_RETRY_ON_NACK         (0u)
#define SPI_1_UART_IRDA_POLARITY         (0u)
#define SPI_1_UART_DROP_ON_FRAME_ERR     (0u)
#define SPI_1_UART_DROP_ON_PARITY_ERR    (0u)
#define SPI_1_UART_WAKE_ENABLE           (0u)
#define SPI_1_UART_RX_BUFFER_SIZE        (8u)
#define SPI_1_UART_TX_BUFFER_SIZE        (8u)
#define SPI_1_UART_MP_MODE_ENABLE        (0u)
#define SPI_1_UART_MP_ACCEPT_ADDRESS     (0u)
#define SPI_1_UART_MP_RX_ADDRESS         (2u)
#define SPI_1_UART_MP_RX_ADDRESS_MASK    (255u)

#define SPI_1_UART_INTERRUPT_MODE        (0u)

#define SPI_1_UART_INTR_RX_MASK          (0u)
#define SPI_1_UART_INTR_TX_MASK          (0u)

#define SPI_1_UART_RX_TRIGGER_LEVEL      (7u)
#define SPI_1_UART_TX_TRIGGER_LEVEL      (0u)

#define SPI_1_UART_BYTE_MODE_ENABLE      (0u)
#define SPI_1_UART_CTS_ENABLE            (0u)
#define SPI_1_UART_CTS_POLARITY          (0u)
#define SPI_1_UART_RTS_POLARITY          (0u)
#define SPI_1_UART_RTS_FIFO_LEVEL        (4u)

/* SPI mode enum */
#define SPI_1_SPI_SLAVE  (0u)
#define SPI_1_SPI_MASTER (1u)

/* UART direction enum */
#define SPI_1_UART_RX    (1u)
#define SPI_1_UART_TX    (2u)
#define SPI_1_UART_TX_RX (3u)


/***************************************
*   Conditional Compilation Parameters
****************************************/

#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)

    /* Mode */
    #define SPI_1_SPI_MASTER_CONST       (1u)

    /* Direction */
    #define SPI_1_RX_DIRECTION           (1u)
    #define SPI_1_TX_DIRECTION           (1u)
    #define SPI_1_UART_RX_DIRECTION      (1u)
    #define SPI_1_UART_TX_DIRECTION      (1u)

    /* Only external RX and TX buffer for Uncofigured mode */
    #define SPI_1_INTERNAL_RX_SW_BUFFER   (0u)
    #define SPI_1_INTERNAL_TX_SW_BUFFER   (0u)

    /* Get RX and TX buffer size */
    #define SPI_1_RX_BUFFER_SIZE (SPI_1_rxBufferSize)
    #define SPI_1_TX_BUFFER_SIZE (SPI_1_txBufferSize)

    /* Return true if buffer is provided */
    #define SPI_1_CHECK_RX_SW_BUFFER (NULL != SPI_1_rxBuffer)
    #define SPI_1_CHECK_TX_SW_BUFFER (NULL != SPI_1_txBuffer)

    /* Always provide global variables to support RX and TX buffers */
    #define SPI_1_INTERNAL_RX_SW_BUFFER_CONST    (1u)
    #define SPI_1_INTERNAL_TX_SW_BUFFER_CONST    (1u)

    /* Get wakeup enable option */
    #define SPI_1_SPI_WAKE_ENABLE_CONST  (1u)
    #define SPI_1_CHECK_SPI_WAKE_ENABLE  (0u != SPI_1_scbEnableWake)
    #define SPI_1_UART_WAKE_ENABLE_CONST (1u)

    /* SPI/UART: TX or RX FIFO size */
    #if (SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1)
        #define SPI_1_SPI_UART_FIFO_SIZE (SPI_1_FIFO_SIZE)
    #else
        #define SPI_1_SPI_UART_FIFO_SIZE (SPI_1_GET_FIFO_SIZE(SPI_1_CTRL_REG & \
                                                                                    SPI_1_CTRL_BYTE_MODE))
    #endif /* (SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1) */

#else

    /* Internal RX and TX buffer: for SPI or UART */
    #if (SPI_1_SCB_MODE_SPI_CONST_CFG)

        /* SPI Direction */
        #define SPI_1_SPI_RX_DIRECTION (1u)
        #define SPI_1_SPI_TX_DIRECTION (1u)

        /* Get FIFO size */
        #if (SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1)
            #define SPI_1_SPI_UART_FIFO_SIZE    (SPI_1_FIFO_SIZE)
        #else
            #define SPI_1_SPI_UART_FIFO_SIZE \
                                           SPI_1_GET_FIFO_SIZE(SPI_1_SPI_BYTE_MODE_ENABLE)

        #endif /* (SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1) */

        /* SPI internal RX and TX buffers */
        #define SPI_1_INTERNAL_SPI_RX_SW_BUFFER  (SPI_1_SPI_RX_BUFFER_SIZE > \
                                                                SPI_1_SPI_UART_FIFO_SIZE)
        #define SPI_1_INTERNAL_SPI_TX_SW_BUFFER  (SPI_1_SPI_TX_BUFFER_SIZE > \
                                                                SPI_1_SPI_UART_FIFO_SIZE)

        /* Internal SPI RX and TX buffer */
        #define SPI_1_INTERNAL_RX_SW_BUFFER  (SPI_1_INTERNAL_SPI_RX_SW_BUFFER)
        #define SPI_1_INTERNAL_TX_SW_BUFFER  (SPI_1_INTERNAL_SPI_TX_SW_BUFFER)

        /* Internal SPI RX and TX buffer size */
        #define SPI_1_RX_BUFFER_SIZE         (SPI_1_SPI_RX_BUFFER_SIZE + 1u)
        #define SPI_1_TX_BUFFER_SIZE         (SPI_1_SPI_TX_BUFFER_SIZE)

        /* Get wakeup enable option */
        #define SPI_1_SPI_WAKE_ENABLE_CONST  (0u != SPI_1_SPI_WAKE_ENABLE)
        #define SPI_1_UART_WAKE_ENABLE_CONST (0u)

    #else

        /* UART Direction */
        #define SPI_1_UART_RX_DIRECTION (0u != (SPI_1_UART_DIRECTION & SPI_1_UART_RX))
        #define SPI_1_UART_TX_DIRECTION (0u != (SPI_1_UART_DIRECTION & SPI_1_UART_TX))

        /* Get FIFO size */
        #if (SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1)
            #define SPI_1_SPI_UART_FIFO_SIZE    (SPI_1_FIFO_SIZE)
        #else
            #define SPI_1_SPI_UART_FIFO_SIZE \
                                           SPI_1_GET_FIFO_SIZE(SPI_1_UART_BYTE_MODE_ENABLE)
        #endif /* (SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1) */

        /* UART internal RX and TX buffers */
        #define SPI_1_INTERNAL_UART_RX_SW_BUFFER  (SPI_1_UART_RX_BUFFER_SIZE > \
                                                                SPI_1_SPI_UART_FIFO_SIZE)
        #define SPI_1_INTERNAL_UART_TX_SW_BUFFER  (SPI_1_UART_TX_BUFFER_SIZE > \
                                                                    SPI_1_SPI_UART_FIFO_SIZE)

        /* Internal UART RX and TX buffer */
        #define SPI_1_INTERNAL_RX_SW_BUFFER  (SPI_1_INTERNAL_UART_RX_SW_BUFFER)
        #define SPI_1_INTERNAL_TX_SW_BUFFER  (SPI_1_INTERNAL_UART_TX_SW_BUFFER)

        /* Internal UART RX and TX buffer size */
        #define SPI_1_RX_BUFFER_SIZE         (SPI_1_UART_RX_BUFFER_SIZE + 1u)
        #define SPI_1_TX_BUFFER_SIZE         (SPI_1_UART_TX_BUFFER_SIZE)

        /* Get wakeup enable option */
        #define SPI_1_SPI_WAKE_ENABLE_CONST  (0u)
        #define SPI_1_UART_WAKE_ENABLE_CONST (0u != SPI_1_UART_WAKE_ENABLE)

    #endif /* (SPI_1_SCB_MODE_SPI_CONST_CFG) */

    /* Mode */
    #define SPI_1_SPI_MASTER_CONST   (SPI_1_SPI_MODE == SPI_1_SPI_MASTER)

    /* Direction */
    #define SPI_1_RX_DIRECTION ((SPI_1_SCB_MODE_SPI_CONST_CFG) ? \
                                            (SPI_1_SPI_RX_DIRECTION) : (SPI_1_UART_RX_DIRECTION))

    #define SPI_1_TX_DIRECTION ((SPI_1_SCB_MODE_SPI_CONST_CFG) ? \
                                            (SPI_1_SPI_TX_DIRECTION) : (SPI_1_UART_TX_DIRECTION))

    /* Internal RX and TX buffer: for SPI or UART. Used in conditional compilation check */
    #define SPI_1_CHECK_RX_SW_BUFFER (SPI_1_INTERNAL_RX_SW_BUFFER)
    #define SPI_1_CHECK_TX_SW_BUFFER (SPI_1_INTERNAL_TX_SW_BUFFER)

    /* Provide global variables to support RX and TX buffers */
    #define SPI_1_INTERNAL_RX_SW_BUFFER_CONST    (SPI_1_INTERNAL_RX_SW_BUFFER)
    #define SPI_1_INTERNAL_TX_SW_BUFFER_CONST    (SPI_1_INTERNAL_TX_SW_BUFFER)

    /* Wakeup for SPI */
    #define SPI_1_CHECK_SPI_WAKE_ENABLE  (SPI_1_SPI_WAKE_ENABLE_CONST)

#endif /* End (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*       Type Definitions
***************************************/

/* SPI_1_SPI_INIT_STRUCT */
typedef struct
{
    uint32 mode;
    uint32 submode;
    uint32 sclkMode;
    uint32 oversample;
    uint32 enableMedianFilter;
    uint32 enableLateSampling;
    uint32 enableWake;
    uint32 rxDataBits;
    uint32 txDataBits;
    uint32 bitOrder;
    uint32 transferSeperation;
    uint32 rxBufferSize;
    uint8* rxBuffer;
    uint32 txBufferSize;
    uint8* txBuffer;
    uint32 enableInterrupt;
    uint32 rxInterruptMask;
    uint32 rxTriggerLevel;
    uint32 txInterruptMask;
    uint32 txTriggerLevel;
    uint8 enableByteMode;
    uint8 enableFreeRunSclk;
    uint8 polaritySs;
} SPI_1_SPI_INIT_STRUCT;

/* SPI_1_UART_INIT_STRUCT */
typedef struct
{
    uint32 mode;
    uint32 direction;
    uint32 dataBits;
    uint32 parity;
    uint32 stopBits;
    uint32 oversample;
    uint32 enableIrdaLowPower;
    uint32 enableMedianFilter;
    uint32 enableRetryNack;
    uint32 enableInvertedRx;
    uint32 dropOnParityErr;
    uint32 dropOnFrameErr;
    uint32 enableWake;
    uint32 rxBufferSize;
    uint8* rxBuffer;
    uint32 txBufferSize;
    uint8* txBuffer;
    uint32 enableMultiproc;
    uint32 multiprocAcceptAddr;
    uint32 multiprocAddr;
    uint32 multiprocAddrMask;
    uint32 enableInterrupt;
    uint32 rxInterruptMask;
    uint32 rxTriggerLevel;
    uint32 txInterruptMask;
    uint32 txTriggerLevel;
    uint8 enableByteMode;
    uint8 enableCts;
    uint8 ctsPolarity;
    uint8 rtsRxFifoLevel;
    uint8 rtsPolarity;
} SPI_1_UART_INIT_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

/* SPI specific functions */
#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
    void SPI_1_SpiInit(const SPI_1_SPI_INIT_STRUCT *config);
#endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(SPI_1_SCB_MODE_SPI_INC)
    #define SPI_1_SpiIsBusBusy() ((uint32) (0u != (SPI_1_SPI_STATUS_REG & \
                                                              SPI_1_SPI_STATUS_BUS_BUSY)))

    #if (SPI_1_SPI_MASTER_CONST)
        void SPI_1_SpiSetActiveSlaveSelect(uint32 slaveSelect);
    #endif /*(SPI_1_SPI_MASTER_CONST) */

    #if !(SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1)
        void SPI_1_SpiSetSlaveSelectPolarity(uint32 slaveSelect, uint32 polarity);
    #endif /* !(SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1) */
#endif /* (SPI_1_SCB_MODE_SPI_INC) */

/* UART specific functions */
#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
    void SPI_1_UartInit(const SPI_1_UART_INIT_STRUCT *config);
#endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(SPI_1_SCB_MODE_UART_INC)
    void SPI_1_UartSetRxAddress(uint32 address);
    void SPI_1_UartSetRxAddressMask(uint32 addressMask);

    /* UART RX direction APIs */
    #if(SPI_1_UART_RX_DIRECTION)
        uint32 SPI_1_UartGetChar(void);
        uint32 SPI_1_UartGetByte(void);

        #if !(SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1)
            /* UART APIs for Flow Control */
            void SPI_1_UartSetRtsPolarity(uint32 polarity);
            void SPI_1_UartSetRtsFifoLevel(uint32 level);
        #endif /* !(SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1) */
    #endif /* (SPI_1_UART_RX_DIRECTION) */

    /* UART TX direction APIs */
    #if(SPI_1_UART_TX_DIRECTION)
        #define SPI_1_UartPutChar(ch)    SPI_1_SpiUartWriteTxData((uint32)(ch))
        void SPI_1_UartPutString(const char8 string[]);
        void SPI_1_UartPutCRLF(uint32 txDataByte);

        #if !(SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1)
            /* UART APIs for Flow Control */
            void SPI_1_UartEnableCts(void);
            void SPI_1_UartDisableCts(void);
            void SPI_1_UartSetCtsPolarity(uint32 polarity);
        #endif /* !(SPI_1_CY_SCBIP_V0 || SPI_1_CY_SCBIP_V1) */
    #endif /* (SPI_1_UART_TX_DIRECTION) */
#endif /* (SPI_1_SCB_MODE_UART_INC) */

/* Common APIs RX direction */
#if(SPI_1_RX_DIRECTION)
    uint32 SPI_1_SpiUartReadRxData(void);
    uint32 SPI_1_SpiUartGetRxBufferSize(void);
    void   SPI_1_SpiUartClearRxBuffer(void);
#endif /* (SPI_1_RX_DIRECTION) */

/* Common APIs TX direction */
#if(SPI_1_TX_DIRECTION)
    void   SPI_1_SpiUartWriteTxData(uint32 txData);
    void   SPI_1_SpiUartPutArray(const uint8 wrBuf[], uint32 count);
    void   SPI_1_SpiUartClearTxBuffer(void);
    uint32 SPI_1_SpiUartGetTxBufferSize(void);
#endif /* (SPI_1_TX_DIRECTION) */

CY_ISR_PROTO(SPI_1_SPI_UART_ISR);

#if(SPI_1_UART_RX_WAKEUP_IRQ)
    CY_ISR_PROTO(SPI_1_UART_WAKEUP_ISR);
#endif /* (SPI_1_UART_RX_WAKEUP_IRQ) */


/***************************************
*     Buffer Access Macro Definitions
***************************************/

#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /* RX direction */
    void   SPI_1_PutWordInRxBuffer  (uint32 idx, uint32 rxDataByte);
    uint32 SPI_1_GetWordFromRxBuffer(uint32 idx);

    /* TX direction */
    void   SPI_1_PutWordInTxBuffer  (uint32 idx, uint32 txDataByte);
    uint32 SPI_1_GetWordFromTxBuffer(uint32 idx);

#else
    /* RX direction */
    #if(SPI_1_INTERNAL_RX_SW_BUFFER_CONST)
        #define SPI_1_PutWordInRxBuffer(idx, rxDataByte) \
                do{                                                 \
                    SPI_1_rxBufferInternal[(idx)] = ((uint8) (rxDataByte)); \
                }while(0)

        #define SPI_1_GetWordFromRxBuffer(idx) SPI_1_rxBufferInternal[(idx)]

    #endif /* (SPI_1_INTERNAL_RX_SW_BUFFER_CONST) */

    /* TX direction */
    #if(SPI_1_INTERNAL_TX_SW_BUFFER_CONST)
        #define SPI_1_PutWordInTxBuffer(idx, txDataByte) \
                    do{                                             \
                        SPI_1_txBufferInternal[(idx)] = ((uint8) (txDataByte)); \
                    }while(0)

        #define SPI_1_GetWordFromTxBuffer(idx) SPI_1_txBufferInternal[(idx)]

    #endif /* (SPI_1_INTERNAL_TX_SW_BUFFER_CONST) */

#endif /* (SPI_1_TX_SW_BUFFER_ENABLE) */


/***************************************
*         SPI API Constants
***************************************/

/* SPI sub mode enum */
#define SPI_1_SPI_MODE_MOTOROLA      (0x00u)
#define SPI_1_SPI_MODE_TI_COINCIDES  (0x01u)
#define SPI_1_SPI_MODE_TI_PRECEDES   (0x11u)
#define SPI_1_SPI_MODE_NATIONAL      (0x02u)
#define SPI_1_SPI_MODE_MASK          (0x03u)
#define SPI_1_SPI_MODE_TI_PRECEDES_MASK  (0x10u)
#define SPI_1_SPI_MODE_NS_MICROWIRE  (SPI_1_SPI_MODE_NATIONAL)

/* SPI phase and polarity mode enum */
#define SPI_1_SPI_SCLK_CPHA0_CPOL0   (0x00u)
#define SPI_1_SPI_SCLK_CPHA0_CPOL1   (0x02u)
#define SPI_1_SPI_SCLK_CPHA1_CPOL0   (0x01u)
#define SPI_1_SPI_SCLK_CPHA1_CPOL1   (0x03u)

/* SPI bits order enum */
#define SPI_1_BITS_ORDER_LSB_FIRST   (0u)
#define SPI_1_BITS_ORDER_MSB_FIRST   (1u)

/* SPI transfer separation enum */
#define SPI_1_SPI_TRANSFER_SEPARATED     (0u)
#define SPI_1_SPI_TRANSFER_CONTINUOUS    (1u)

/* SPI slave select constants */
#define SPI_1_SPI_SLAVE_SELECT0    (SPI_1_SCB__SS0_POSISTION)
#define SPI_1_SPI_SLAVE_SELECT1    (SPI_1_SCB__SS1_POSISTION)
#define SPI_1_SPI_SLAVE_SELECT2    (SPI_1_SCB__SS2_POSISTION)
#define SPI_1_SPI_SLAVE_SELECT3    (SPI_1_SCB__SS3_POSISTION)

/* SPI slave select polarity settings */
#define SPI_1_SPI_SS_ACTIVE_LOW  (0u)
#define SPI_1_SPI_SS_ACTIVE_HIGH (1u)


/***************************************
*         UART API Constants
***************************************/

/* UART sub-modes enum */
#define SPI_1_UART_MODE_STD          (0u)
#define SPI_1_UART_MODE_SMARTCARD    (1u)
#define SPI_1_UART_MODE_IRDA         (2u)

/* UART direction enum */
#define SPI_1_UART_RX    (1u)
#define SPI_1_UART_TX    (2u)
#define SPI_1_UART_TX_RX (3u)

/* UART parity enum */
#define SPI_1_UART_PARITY_EVEN   (0u)
#define SPI_1_UART_PARITY_ODD    (1u)
#define SPI_1_UART_PARITY_NONE   (2u)

/* UART stop bits enum */
#define SPI_1_UART_STOP_BITS_1   (2u)
#define SPI_1_UART_STOP_BITS_1_5 (3u)
#define SPI_1_UART_STOP_BITS_2   (4u)

/* UART IrDA low power OVS enum */
#define SPI_1_UART_IRDA_LP_OVS16     (16u)
#define SPI_1_UART_IRDA_LP_OVS32     (32u)
#define SPI_1_UART_IRDA_LP_OVS48     (48u)
#define SPI_1_UART_IRDA_LP_OVS96     (96u)
#define SPI_1_UART_IRDA_LP_OVS192    (192u)
#define SPI_1_UART_IRDA_LP_OVS768    (768u)
#define SPI_1_UART_IRDA_LP_OVS1536   (1536u)

/* Uart MP: mark (address) and space (data) bit definitions */
#define SPI_1_UART_MP_MARK       (0x100u)
#define SPI_1_UART_MP_SPACE      (0x000u)

/* UART CTS/RTS polarity settings */
#define SPI_1_UART_CTS_ACTIVE_LOW    (0u)
#define SPI_1_UART_CTS_ACTIVE_HIGH   (1u)
#define SPI_1_UART_RTS_ACTIVE_LOW    (0u)
#define SPI_1_UART_RTS_ACTIVE_HIGH   (1u)

/* Sources of RX errors */
#define SPI_1_INTR_RX_ERR        (SPI_1_INTR_RX_OVERFLOW    | \
                                             SPI_1_INTR_RX_UNDERFLOW   | \
                                             SPI_1_INTR_RX_FRAME_ERROR | \
                                             SPI_1_INTR_RX_PARITY_ERROR)

/* Shifted INTR_RX_ERR defines ONLY for SPI_1_UartGetByte() */
#define SPI_1_UART_RX_OVERFLOW       (SPI_1_INTR_RX_OVERFLOW << 8u)
#define SPI_1_UART_RX_UNDERFLOW      (SPI_1_INTR_RX_UNDERFLOW << 8u)
#define SPI_1_UART_RX_FRAME_ERROR    (SPI_1_INTR_RX_FRAME_ERROR << 8u)
#define SPI_1_UART_RX_PARITY_ERROR   (SPI_1_INTR_RX_PARITY_ERROR << 8u)
#define SPI_1_UART_RX_ERROR_MASK     (SPI_1_UART_RX_OVERFLOW    | \
                                                 SPI_1_UART_RX_UNDERFLOW   | \
                                                 SPI_1_UART_RX_FRAME_ERROR | \
                                                 SPI_1_UART_RX_PARITY_ERROR)


/***************************************
*     Vars with External Linkage
***************************************/

#if(SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)
    extern const SPI_1_SPI_INIT_STRUCT  SPI_1_configSpi;
    extern const SPI_1_UART_INIT_STRUCT SPI_1_configUart;
#endif /* (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*    Specific SPI Macro Definitions
***************************************/

#define SPI_1_GET_SPI_INTR_SLAVE_MASK(sourceMask)  ((sourceMask) & SPI_1_INTR_SLAVE_SPI_BUS_ERROR)
#define SPI_1_GET_SPI_INTR_MASTER_MASK(sourceMask) ((sourceMask) & SPI_1_INTR_MASTER_SPI_DONE)
#define SPI_1_GET_SPI_INTR_RX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~SPI_1_INTR_SLAVE_SPI_BUS_ERROR)

#define SPI_1_GET_SPI_INTR_TX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~SPI_1_INTR_MASTER_SPI_DONE)


/***************************************
*    Specific UART Macro Definitions
***************************************/

#define SPI_1_UART_GET_CTRL_OVS_IRDA_LP(oversample) \
        ((SPI_1_UART_IRDA_LP_OVS16   == (oversample)) ? SPI_1_CTRL_OVS_IRDA_LP_OVS16 : \
         ((SPI_1_UART_IRDA_LP_OVS32   == (oversample)) ? SPI_1_CTRL_OVS_IRDA_LP_OVS32 : \
          ((SPI_1_UART_IRDA_LP_OVS48   == (oversample)) ? SPI_1_CTRL_OVS_IRDA_LP_OVS48 : \
           ((SPI_1_UART_IRDA_LP_OVS96   == (oversample)) ? SPI_1_CTRL_OVS_IRDA_LP_OVS96 : \
            ((SPI_1_UART_IRDA_LP_OVS192  == (oversample)) ? SPI_1_CTRL_OVS_IRDA_LP_OVS192 : \
             ((SPI_1_UART_IRDA_LP_OVS768  == (oversample)) ? SPI_1_CTRL_OVS_IRDA_LP_OVS768 : \
              ((SPI_1_UART_IRDA_LP_OVS1536 == (oversample)) ? SPI_1_CTRL_OVS_IRDA_LP_OVS1536 : \
                                                                          SPI_1_CTRL_OVS_IRDA_LP_OVS16)))))))

#define SPI_1_GET_UART_RX_CTRL_ENABLED(direction) ((0u != (SPI_1_UART_RX & (direction))) ? \
                                                                     (SPI_1_RX_CTRL_ENABLED) : (0u))

#define SPI_1_GET_UART_TX_CTRL_ENABLED(direction) ((0u != (SPI_1_UART_TX & (direction))) ? \
                                                                     (SPI_1_TX_CTRL_ENABLED) : (0u))


/***************************************
*        SPI Register Settings
***************************************/

#define SPI_1_CTRL_SPI      (SPI_1_CTRL_MODE_SPI)
#define SPI_1_SPI_RX_CTRL   (SPI_1_RX_CTRL_ENABLED)
#define SPI_1_SPI_TX_CTRL   (SPI_1_TX_CTRL_ENABLED)


/***************************************
*       SPI Init Register Settings
***************************************/

#define SPI_1_SPI_SS_POLARITY \
             (((uint32) SPI_1_SPI_SS0_POLARITY << SPI_1_SPI_SLAVE_SELECT0) | \
              ((uint32) SPI_1_SPI_SS1_POLARITY << SPI_1_SPI_SLAVE_SELECT1) | \
              ((uint32) SPI_1_SPI_SS2_POLARITY << SPI_1_SPI_SLAVE_SELECT2) | \
              ((uint32) SPI_1_SPI_SS3_POLARITY << SPI_1_SPI_SLAVE_SELECT3))

#if(SPI_1_SCB_MODE_SPI_CONST_CFG)

    /* SPI Configuration */
    #define SPI_1_SPI_DEFAULT_CTRL \
                    (SPI_1_GET_CTRL_OVS(SPI_1_SPI_OVS_FACTOR) | \
                     SPI_1_GET_CTRL_BYTE_MODE (SPI_1_SPI_BYTE_MODE_ENABLE) | \
                     SPI_1_GET_CTRL_EC_AM_MODE(SPI_1_SPI_WAKE_ENABLE)      | \
                     SPI_1_CTRL_SPI)

    #define SPI_1_SPI_DEFAULT_SPI_CTRL \
                    (SPI_1_GET_SPI_CTRL_CONTINUOUS    (SPI_1_SPI_TRANSFER_SEPARATION)       | \
                     SPI_1_GET_SPI_CTRL_SELECT_PRECEDE(SPI_1_SPI_SUB_MODE &                   \
                                                                  SPI_1_SPI_MODE_TI_PRECEDES_MASK)     | \
                     SPI_1_GET_SPI_CTRL_SCLK_MODE     (SPI_1_SPI_CLOCK_MODE)                | \
                     SPI_1_GET_SPI_CTRL_LATE_MISO_SAMPLE(SPI_1_SPI_LATE_MISO_SAMPLE_ENABLE) | \
                     SPI_1_GET_SPI_CTRL_SCLK_CONTINUOUS(SPI_1_SPI_FREE_RUN_SCLK_ENABLE)     | \
                     SPI_1_GET_SPI_CTRL_SSEL_POLARITY (SPI_1_SPI_SS_POLARITY)               | \
                     SPI_1_GET_SPI_CTRL_SUB_MODE      (SPI_1_SPI_SUB_MODE)                  | \
                     SPI_1_GET_SPI_CTRL_MASTER_MODE   (SPI_1_SPI_MODE))

    /* RX direction */
    #define SPI_1_SPI_DEFAULT_RX_CTRL \
                    (SPI_1_GET_RX_CTRL_DATA_WIDTH(SPI_1_SPI_RX_DATA_BITS_NUM)     | \
                     SPI_1_GET_RX_CTRL_BIT_ORDER (SPI_1_SPI_BITS_ORDER)           | \
                     SPI_1_GET_RX_CTRL_MEDIAN    (SPI_1_SPI_MEDIAN_FILTER_ENABLE) | \
                     SPI_1_SPI_RX_CTRL)

    #define SPI_1_SPI_DEFAULT_RX_FIFO_CTRL \
                    SPI_1_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(SPI_1_SPI_RX_TRIGGER_LEVEL)

    /* TX direction */
    #define SPI_1_SPI_DEFAULT_TX_CTRL \
                    (SPI_1_GET_TX_CTRL_DATA_WIDTH(SPI_1_SPI_TX_DATA_BITS_NUM) | \
                     SPI_1_GET_TX_CTRL_BIT_ORDER (SPI_1_SPI_BITS_ORDER)       | \
                     SPI_1_SPI_TX_CTRL)

    #define SPI_1_SPI_DEFAULT_TX_FIFO_CTRL \
                    SPI_1_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(SPI_1_SPI_TX_TRIGGER_LEVEL)

    /* Interrupt sources */
    #define SPI_1_SPI_DEFAULT_INTR_SPI_EC_MASK   (SPI_1_NO_INTR_SOURCES)

    #define SPI_1_SPI_DEFAULT_INTR_I2C_EC_MASK   (SPI_1_NO_INTR_SOURCES)
    #define SPI_1_SPI_DEFAULT_INTR_SLAVE_MASK \
                    (SPI_1_SPI_INTR_RX_MASK & SPI_1_INTR_SLAVE_SPI_BUS_ERROR)

    #define SPI_1_SPI_DEFAULT_INTR_MASTER_MASK \
                    (SPI_1_SPI_INTR_TX_MASK & SPI_1_INTR_MASTER_SPI_DONE)

    #define SPI_1_SPI_DEFAULT_INTR_RX_MASK \
                    (SPI_1_SPI_INTR_RX_MASK & (uint32) ~SPI_1_INTR_SLAVE_SPI_BUS_ERROR)

    #define SPI_1_SPI_DEFAULT_INTR_TX_MASK \
                    (SPI_1_SPI_INTR_TX_MASK & (uint32) ~SPI_1_INTR_MASTER_SPI_DONE)

#endif /* (SPI_1_SCB_MODE_SPI_CONST_CFG) */


/***************************************
*        UART Register Settings
***************************************/

#define SPI_1_CTRL_UART      (SPI_1_CTRL_MODE_UART)
#define SPI_1_UART_RX_CTRL   (SPI_1_RX_CTRL_LSB_FIRST) /* LSB for UART goes first */
#define SPI_1_UART_TX_CTRL   (SPI_1_TX_CTRL_LSB_FIRST) /* LSB for UART goes first */


/***************************************
*      UART Init Register Settings
***************************************/

#if(SPI_1_SCB_MODE_UART_CONST_CFG)

    /* UART configuration */
    #if(SPI_1_UART_MODE_IRDA == SPI_1_UART_SUB_MODE)

        #define SPI_1_DEFAULT_CTRL_OVS   ((0u != SPI_1_UART_IRDA_LOW_POWER) ?              \
                                (SPI_1_UART_GET_CTRL_OVS_IRDA_LP(SPI_1_UART_OVS_FACTOR)) : \
                                (SPI_1_CTRL_OVS_IRDA_OVS16))

    #else

        #define SPI_1_DEFAULT_CTRL_OVS   SPI_1_GET_CTRL_OVS(SPI_1_UART_OVS_FACTOR)

    #endif /* (SPI_1_UART_MODE_IRDA == SPI_1_UART_SUB_MODE) */

    #define SPI_1_UART_DEFAULT_CTRL \
                                (SPI_1_GET_CTRL_BYTE_MODE  (SPI_1_UART_BYTE_MODE_ENABLE)  | \
                                 SPI_1_GET_CTRL_ADDR_ACCEPT(SPI_1_UART_MP_ACCEPT_ADDRESS) | \
                                 SPI_1_DEFAULT_CTRL_OVS                                              | \
                                 SPI_1_CTRL_UART)

    #define SPI_1_UART_DEFAULT_UART_CTRL \
                                    (SPI_1_GET_UART_CTRL_MODE(SPI_1_UART_SUB_MODE))

    /* RX direction */
    #define SPI_1_UART_DEFAULT_RX_CTRL_PARITY \
                                ((SPI_1_UART_PARITY_NONE != SPI_1_UART_PARITY_TYPE) ?      \
                                  (SPI_1_GET_UART_RX_CTRL_PARITY(SPI_1_UART_PARITY_TYPE) | \
                                   SPI_1_UART_RX_CTRL_PARITY_ENABLED) : (0u))

    #define SPI_1_UART_DEFAULT_UART_RX_CTRL \
                    (SPI_1_GET_UART_RX_CTRL_MODE(SPI_1_UART_STOP_BITS_NUM)                    | \
                     SPI_1_GET_UART_RX_CTRL_POLARITY(SPI_1_UART_IRDA_POLARITY)                | \
                     SPI_1_GET_UART_RX_CTRL_MP_MODE(SPI_1_UART_MP_MODE_ENABLE)                | \
                     SPI_1_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(SPI_1_UART_DROP_ON_PARITY_ERR) | \
                     SPI_1_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(SPI_1_UART_DROP_ON_FRAME_ERR)   | \
                     SPI_1_UART_DEFAULT_RX_CTRL_PARITY)

    #define SPI_1_UART_DEFAULT_RX_CTRL \
                                (SPI_1_GET_RX_CTRL_DATA_WIDTH(SPI_1_UART_DATA_BITS_NUM)        | \
                                 SPI_1_GET_RX_CTRL_MEDIAN    (SPI_1_UART_MEDIAN_FILTER_ENABLE) | \
                                 SPI_1_GET_UART_RX_CTRL_ENABLED(SPI_1_UART_DIRECTION))

    #define SPI_1_UART_DEFAULT_RX_FIFO_CTRL \
                                SPI_1_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(SPI_1_UART_RX_TRIGGER_LEVEL)

    #define SPI_1_UART_DEFAULT_RX_MATCH_REG  ((0u != SPI_1_UART_MP_MODE_ENABLE) ?          \
                                (SPI_1_GET_RX_MATCH_ADDR(SPI_1_UART_MP_RX_ADDRESS) | \
                                 SPI_1_GET_RX_MATCH_MASK(SPI_1_UART_MP_RX_ADDRESS_MASK)) : (0u))

    /* TX direction */
    #define SPI_1_UART_DEFAULT_TX_CTRL_PARITY (SPI_1_UART_DEFAULT_RX_CTRL_PARITY)

    #define SPI_1_UART_DEFAULT_UART_TX_CTRL \
                                (SPI_1_GET_UART_TX_CTRL_MODE(SPI_1_UART_STOP_BITS_NUM)       | \
                                 SPI_1_GET_UART_TX_CTRL_RETRY_NACK(SPI_1_UART_RETRY_ON_NACK) | \
                                 SPI_1_UART_DEFAULT_TX_CTRL_PARITY)

    #define SPI_1_UART_DEFAULT_TX_CTRL \
                                (SPI_1_GET_TX_CTRL_DATA_WIDTH(SPI_1_UART_DATA_BITS_NUM) | \
                                 SPI_1_GET_UART_TX_CTRL_ENABLED(SPI_1_UART_DIRECTION))

    #define SPI_1_UART_DEFAULT_TX_FIFO_CTRL \
                                SPI_1_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(SPI_1_UART_TX_TRIGGER_LEVEL)

    #define SPI_1_UART_DEFAULT_FLOW_CTRL \
                        (SPI_1_GET_UART_FLOW_CTRL_TRIGGER_LEVEL(SPI_1_UART_RTS_FIFO_LEVEL) | \
                         SPI_1_GET_UART_FLOW_CTRL_RTS_POLARITY (SPI_1_UART_RTS_POLARITY)   | \
                         SPI_1_GET_UART_FLOW_CTRL_CTS_POLARITY (SPI_1_UART_CTS_POLARITY)   | \
                         SPI_1_GET_UART_FLOW_CTRL_CTS_ENABLE   (SPI_1_UART_CTS_ENABLE))

    /* Interrupt sources */
    #define SPI_1_UART_DEFAULT_INTR_I2C_EC_MASK  (SPI_1_NO_INTR_SOURCES)
    #define SPI_1_UART_DEFAULT_INTR_SPI_EC_MASK  (SPI_1_NO_INTR_SOURCES)
    #define SPI_1_UART_DEFAULT_INTR_SLAVE_MASK   (SPI_1_NO_INTR_SOURCES)
    #define SPI_1_UART_DEFAULT_INTR_MASTER_MASK  (SPI_1_NO_INTR_SOURCES)
    #define SPI_1_UART_DEFAULT_INTR_RX_MASK      (SPI_1_UART_INTR_RX_MASK)
    #define SPI_1_UART_DEFAULT_INTR_TX_MASK      (SPI_1_UART_INTR_TX_MASK)

#endif /* (SPI_1_SCB_MODE_UART_CONST_CFG) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

#define SPI_1_SPIM_ACTIVE_SS0    (SPI_1_SPI_SLAVE_SELECT0)
#define SPI_1_SPIM_ACTIVE_SS1    (SPI_1_SPI_SLAVE_SELECT1)
#define SPI_1_SPIM_ACTIVE_SS2    (SPI_1_SPI_SLAVE_SELECT2)
#define SPI_1_SPIM_ACTIVE_SS3    (SPI_1_SPI_SLAVE_SELECT3)

#endif /* CY_SCB_SPI_UART_SPI_1_H */


/* [] END OF FILE */
