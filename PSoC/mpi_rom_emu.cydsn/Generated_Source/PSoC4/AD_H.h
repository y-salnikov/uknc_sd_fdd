/*******************************************************************************
* File Name: AD_H.h  
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

#if !defined(CY_PINS_AD_H_H) /* Pins AD_H_H */
#define CY_PINS_AD_H_H

#include "cytypes.h"
#include "cyfitter.h"
#include "AD_H_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    AD_H_Write(uint8 value) ;
void    AD_H_SetDriveMode(uint8 mode) ;
uint8   AD_H_ReadDataReg(void) ;
uint8   AD_H_Read(void) ;
uint8   AD_H_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define AD_H_DRIVE_MODE_BITS        (3)
#define AD_H_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - AD_H_DRIVE_MODE_BITS))

#define AD_H_DM_ALG_HIZ         (0x00u)
#define AD_H_DM_DIG_HIZ         (0x01u)
#define AD_H_DM_RES_UP          (0x02u)
#define AD_H_DM_RES_DWN         (0x03u)
#define AD_H_DM_OD_LO           (0x04u)
#define AD_H_DM_OD_HI           (0x05u)
#define AD_H_DM_STRONG          (0x06u)
#define AD_H_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define AD_H_MASK               AD_H__MASK
#define AD_H_SHIFT              AD_H__SHIFT
#define AD_H_WIDTH              8u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AD_H_PS                     (* (reg32 *) AD_H__PS)
/* Port Configuration */
#define AD_H_PC                     (* (reg32 *) AD_H__PC)
/* Data Register */
#define AD_H_DR                     (* (reg32 *) AD_H__DR)
/* Input Buffer Disable Override */
#define AD_H_INP_DIS                (* (reg32 *) AD_H__PC2)


#if defined(AD_H__INTSTAT)  /* Interrupt Registers */

    #define AD_H_INTSTAT                (* (reg32 *) AD_H__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define AD_H_DRIVE_MODE_SHIFT       (0x00u)
#define AD_H_DRIVE_MODE_MASK        (0x07u << AD_H_DRIVE_MODE_SHIFT)


#endif /* End Pins AD_H_H */


/* [] END OF FILE */
