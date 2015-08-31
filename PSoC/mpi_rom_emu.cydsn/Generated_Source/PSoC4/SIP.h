/*******************************************************************************
* File Name: SIP.h  
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

#if !defined(CY_PINS_SIP_H) /* Pins SIP_H */
#define CY_PINS_SIP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SIP_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SIP_Write(uint8 value) ;
void    SIP_SetDriveMode(uint8 mode) ;
uint8   SIP_ReadDataReg(void) ;
uint8   SIP_Read(void) ;
uint8   SIP_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SIP_DRIVE_MODE_BITS        (3)
#define SIP_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SIP_DRIVE_MODE_BITS))

#define SIP_DM_ALG_HIZ         (0x00u)
#define SIP_DM_DIG_HIZ         (0x01u)
#define SIP_DM_RES_UP          (0x02u)
#define SIP_DM_RES_DWN         (0x03u)
#define SIP_DM_OD_LO           (0x04u)
#define SIP_DM_OD_HI           (0x05u)
#define SIP_DM_STRONG          (0x06u)
#define SIP_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SIP_MASK               SIP__MASK
#define SIP_SHIFT              SIP__SHIFT
#define SIP_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SIP_PS                     (* (reg32 *) SIP__PS)
/* Port Configuration */
#define SIP_PC                     (* (reg32 *) SIP__PC)
/* Data Register */
#define SIP_DR                     (* (reg32 *) SIP__DR)
/* Input Buffer Disable Override */
#define SIP_INP_DIS                (* (reg32 *) SIP__PC2)


#if defined(SIP__INTSTAT)  /* Interrupt Registers */

    #define SIP_INTSTAT                (* (reg32 *) SIP__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SIP_DRIVE_MODE_SHIFT       (0x00u)
#define SIP_DRIVE_MODE_MASK        (0x07u << SIP_DRIVE_MODE_SHIFT)


#endif /* End Pins SIP_H */


/* [] END OF FILE */
