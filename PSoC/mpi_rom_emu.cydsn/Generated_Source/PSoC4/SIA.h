/*******************************************************************************
* File Name: SIA.h  
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

#if !defined(CY_PINS_SIA_H) /* Pins SIA_H */
#define CY_PINS_SIA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SIA_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SIA_Write(uint8 value) ;
void    SIA_SetDriveMode(uint8 mode) ;
uint8   SIA_ReadDataReg(void) ;
uint8   SIA_Read(void) ;
uint8   SIA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SIA_DRIVE_MODE_BITS        (3)
#define SIA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SIA_DRIVE_MODE_BITS))

#define SIA_DM_ALG_HIZ         (0x00u)
#define SIA_DM_DIG_HIZ         (0x01u)
#define SIA_DM_RES_UP          (0x02u)
#define SIA_DM_RES_DWN         (0x03u)
#define SIA_DM_OD_LO           (0x04u)
#define SIA_DM_OD_HI           (0x05u)
#define SIA_DM_STRONG          (0x06u)
#define SIA_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SIA_MASK               SIA__MASK
#define SIA_SHIFT              SIA__SHIFT
#define SIA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SIA_PS                     (* (reg32 *) SIA__PS)
/* Port Configuration */
#define SIA_PC                     (* (reg32 *) SIA__PC)
/* Data Register */
#define SIA_DR                     (* (reg32 *) SIA__DR)
/* Input Buffer Disable Override */
#define SIA_INP_DIS                (* (reg32 *) SIA__PC2)


#if defined(SIA__INTSTAT)  /* Interrupt Registers */

    #define SIA_INTSTAT                (* (reg32 *) SIA__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SIA_DRIVE_MODE_SHIFT       (0x00u)
#define SIA_DRIVE_MODE_MASK        (0x07u << SIA_DRIVE_MODE_SHIFT)


#endif /* End Pins SIA_H */


/* [] END OF FILE */
