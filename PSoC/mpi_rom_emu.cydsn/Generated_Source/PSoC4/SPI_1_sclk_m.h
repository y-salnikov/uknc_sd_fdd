/*******************************************************************************
* File Name: SPI_1_sclk_m.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SPI_1_sclk_m_H) /* Pins SPI_1_sclk_m_H */
#define CY_PINS_SPI_1_sclk_m_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SPI_1_sclk_m_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SPI_1_sclk_m_Write(uint8 value) ;
void    SPI_1_sclk_m_SetDriveMode(uint8 mode) ;
uint8   SPI_1_sclk_m_ReadDataReg(void) ;
uint8   SPI_1_sclk_m_Read(void) ;
uint8   SPI_1_sclk_m_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SPI_1_sclk_m_DRIVE_MODE_BITS        (3)
#define SPI_1_sclk_m_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SPI_1_sclk_m_DRIVE_MODE_BITS))

#define SPI_1_sclk_m_DM_ALG_HIZ         (0x00u)
#define SPI_1_sclk_m_DM_DIG_HIZ         (0x01u)
#define SPI_1_sclk_m_DM_RES_UP          (0x02u)
#define SPI_1_sclk_m_DM_RES_DWN         (0x03u)
#define SPI_1_sclk_m_DM_OD_LO           (0x04u)
#define SPI_1_sclk_m_DM_OD_HI           (0x05u)
#define SPI_1_sclk_m_DM_STRONG          (0x06u)
#define SPI_1_sclk_m_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SPI_1_sclk_m_MASK               SPI_1_sclk_m__MASK
#define SPI_1_sclk_m_SHIFT              SPI_1_sclk_m__SHIFT
#define SPI_1_sclk_m_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SPI_1_sclk_m_PS                     (* (reg32 *) SPI_1_sclk_m__PS)
/* Port Configuration */
#define SPI_1_sclk_m_PC                     (* (reg32 *) SPI_1_sclk_m__PC)
/* Data Register */
#define SPI_1_sclk_m_DR                     (* (reg32 *) SPI_1_sclk_m__DR)
/* Input Buffer Disable Override */
#define SPI_1_sclk_m_INP_DIS                (* (reg32 *) SPI_1_sclk_m__PC2)


#if defined(SPI_1_sclk_m__INTSTAT)  /* Interrupt Registers */

    #define SPI_1_sclk_m_INTSTAT                (* (reg32 *) SPI_1_sclk_m__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SPI_1_sclk_m_DRIVE_MODE_SHIFT       (0x00u)
#define SPI_1_sclk_m_DRIVE_MODE_MASK        (0x07u << SPI_1_sclk_m_DRIVE_MODE_SHIFT)


#endif /* End Pins SPI_1_sclk_m_H */


/* [] END OF FILE */
