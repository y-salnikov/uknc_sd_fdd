/*******************************************************************************
* File Name: SE0.h  
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

#if !defined(CY_PINS_SE0_H) /* Pins SE0_H */
#define CY_PINS_SE0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SE0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SE0_Write(uint8 value) ;
void    SE0_SetDriveMode(uint8 mode) ;
uint8   SE0_ReadDataReg(void) ;
uint8   SE0_Read(void) ;
uint8   SE0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SE0_DRIVE_MODE_BITS        (3)
#define SE0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SE0_DRIVE_MODE_BITS))

#define SE0_DM_ALG_HIZ         (0x00u)
#define SE0_DM_DIG_HIZ         (0x01u)
#define SE0_DM_RES_UP          (0x02u)
#define SE0_DM_RES_DWN         (0x03u)
#define SE0_DM_OD_LO           (0x04u)
#define SE0_DM_OD_HI           (0x05u)
#define SE0_DM_STRONG          (0x06u)
#define SE0_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SE0_MASK               SE0__MASK
#define SE0_SHIFT              SE0__SHIFT
#define SE0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SE0_PS                     (* (reg32 *) SE0__PS)
/* Port Configuration */
#define SE0_PC                     (* (reg32 *) SE0__PC)
/* Data Register */
#define SE0_DR                     (* (reg32 *) SE0__DR)
/* Input Buffer Disable Override */
#define SE0_INP_DIS                (* (reg32 *) SE0__PC2)


#if defined(SE0__INTSTAT)  /* Interrupt Registers */

    #define SE0_INTSTAT                (* (reg32 *) SE0__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SE0_DRIVE_MODE_SHIFT       (0x00u)
#define SE0_DRIVE_MODE_MASK        (0x07u << SE0_DRIVE_MODE_SHIFT)


#endif /* End Pins SE0_H */


/* [] END OF FILE */
