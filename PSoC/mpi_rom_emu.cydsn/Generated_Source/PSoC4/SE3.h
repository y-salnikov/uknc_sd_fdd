/*******************************************************************************
* File Name: SE3.h  
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

#if !defined(CY_PINS_SE3_H) /* Pins SE3_H */
#define CY_PINS_SE3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SE3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SE3_Write(uint8 value) ;
void    SE3_SetDriveMode(uint8 mode) ;
uint8   SE3_ReadDataReg(void) ;
uint8   SE3_Read(void) ;
uint8   SE3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SE3_DRIVE_MODE_BITS        (3)
#define SE3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SE3_DRIVE_MODE_BITS))

#define SE3_DM_ALG_HIZ         (0x00u)
#define SE3_DM_DIG_HIZ         (0x01u)
#define SE3_DM_RES_UP          (0x02u)
#define SE3_DM_RES_DWN         (0x03u)
#define SE3_DM_OD_LO           (0x04u)
#define SE3_DM_OD_HI           (0x05u)
#define SE3_DM_STRONG          (0x06u)
#define SE3_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SE3_MASK               SE3__MASK
#define SE3_SHIFT              SE3__SHIFT
#define SE3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SE3_PS                     (* (reg32 *) SE3__PS)
/* Port Configuration */
#define SE3_PC                     (* (reg32 *) SE3__PC)
/* Data Register */
#define SE3_DR                     (* (reg32 *) SE3__DR)
/* Input Buffer Disable Override */
#define SE3_INP_DIS                (* (reg32 *) SE3__PC2)


#if defined(SE3__INTSTAT)  /* Interrupt Registers */

    #define SE3_INTSTAT                (* (reg32 *) SE3__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SE3_DRIVE_MODE_SHIFT       (0x00u)
#define SE3_DRIVE_MODE_MASK        (0x07u << SE3_DRIVE_MODE_SHIFT)


#endif /* End Pins SE3_H */


/* [] END OF FILE */
