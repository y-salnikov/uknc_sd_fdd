/*******************************************************************************
* File Name: SE1.h  
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

#if !defined(CY_PINS_SE1_H) /* Pins SE1_H */
#define CY_PINS_SE1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SE1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SE1_Write(uint8 value) ;
void    SE1_SetDriveMode(uint8 mode) ;
uint8   SE1_ReadDataReg(void) ;
uint8   SE1_Read(void) ;
uint8   SE1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SE1_DRIVE_MODE_BITS        (3)
#define SE1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SE1_DRIVE_MODE_BITS))

#define SE1_DM_ALG_HIZ         (0x00u)
#define SE1_DM_DIG_HIZ         (0x01u)
#define SE1_DM_RES_UP          (0x02u)
#define SE1_DM_RES_DWN         (0x03u)
#define SE1_DM_OD_LO           (0x04u)
#define SE1_DM_OD_HI           (0x05u)
#define SE1_DM_STRONG          (0x06u)
#define SE1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SE1_MASK               SE1__MASK
#define SE1_SHIFT              SE1__SHIFT
#define SE1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SE1_PS                     (* (reg32 *) SE1__PS)
/* Port Configuration */
#define SE1_PC                     (* (reg32 *) SE1__PC)
/* Data Register */
#define SE1_DR                     (* (reg32 *) SE1__DR)
/* Input Buffer Disable Override */
#define SE1_INP_DIS                (* (reg32 *) SE1__PC2)


#if defined(SE1__INTSTAT)  /* Interrupt Registers */

    #define SE1_INTSTAT                (* (reg32 *) SE1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SE1_DRIVE_MODE_SHIFT       (0x00u)
#define SE1_DRIVE_MODE_MASK        (0x07u << SE1_DRIVE_MODE_SHIFT)


#endif /* End Pins SE1_H */


/* [] END OF FILE */
