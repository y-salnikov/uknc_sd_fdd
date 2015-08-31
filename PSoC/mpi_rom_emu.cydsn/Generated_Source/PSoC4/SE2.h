/*******************************************************************************
* File Name: SE2.h  
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

#if !defined(CY_PINS_SE2_H) /* Pins SE2_H */
#define CY_PINS_SE2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SE2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SE2_Write(uint8 value) ;
void    SE2_SetDriveMode(uint8 mode) ;
uint8   SE2_ReadDataReg(void) ;
uint8   SE2_Read(void) ;
uint8   SE2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SE2_DRIVE_MODE_BITS        (3)
#define SE2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SE2_DRIVE_MODE_BITS))

#define SE2_DM_ALG_HIZ         (0x00u)
#define SE2_DM_DIG_HIZ         (0x01u)
#define SE2_DM_RES_UP          (0x02u)
#define SE2_DM_RES_DWN         (0x03u)
#define SE2_DM_OD_LO           (0x04u)
#define SE2_DM_OD_HI           (0x05u)
#define SE2_DM_STRONG          (0x06u)
#define SE2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SE2_MASK               SE2__MASK
#define SE2_SHIFT              SE2__SHIFT
#define SE2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SE2_PS                     (* (reg32 *) SE2__PS)
/* Port Configuration */
#define SE2_PC                     (* (reg32 *) SE2__PC)
/* Data Register */
#define SE2_DR                     (* (reg32 *) SE2__DR)
/* Input Buffer Disable Override */
#define SE2_INP_DIS                (* (reg32 *) SE2__PC2)


#if defined(SE2__INTSTAT)  /* Interrupt Registers */

    #define SE2_INTSTAT                (* (reg32 *) SE2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SE2_DRIVE_MODE_SHIFT       (0x00u)
#define SE2_DRIVE_MODE_MASK        (0x07u << SE2_DRIVE_MODE_SHIFT)


#endif /* End Pins SE2_H */


/* [] END OF FILE */
