/*******************************************************************************
* File Name: CD.h  
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

#if !defined(CY_PINS_CD_H) /* Pins CD_H */
#define CY_PINS_CD_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CD_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    CD_Write(uint8 value) ;
void    CD_SetDriveMode(uint8 mode) ;
uint8   CD_ReadDataReg(void) ;
uint8   CD_Read(void) ;
uint8   CD_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CD_DRIVE_MODE_BITS        (3)
#define CD_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - CD_DRIVE_MODE_BITS))

#define CD_DM_ALG_HIZ         (0x00u)
#define CD_DM_DIG_HIZ         (0x01u)
#define CD_DM_RES_UP          (0x02u)
#define CD_DM_RES_DWN         (0x03u)
#define CD_DM_OD_LO           (0x04u)
#define CD_DM_OD_HI           (0x05u)
#define CD_DM_STRONG          (0x06u)
#define CD_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define CD_MASK               CD__MASK
#define CD_SHIFT              CD__SHIFT
#define CD_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CD_PS                     (* (reg32 *) CD__PS)
/* Port Configuration */
#define CD_PC                     (* (reg32 *) CD__PC)
/* Data Register */
#define CD_DR                     (* (reg32 *) CD__DR)
/* Input Buffer Disable Override */
#define CD_INP_DIS                (* (reg32 *) CD__PC2)


#if defined(CD__INTSTAT)  /* Interrupt Registers */

    #define CD_INTSTAT                (* (reg32 *) CD__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define CD_DRIVE_MODE_SHIFT       (0x00u)
#define CD_DRIVE_MODE_MASK        (0x07u << CD_DRIVE_MODE_SHIFT)


#endif /* End Pins CD_H */


/* [] END OF FILE */
