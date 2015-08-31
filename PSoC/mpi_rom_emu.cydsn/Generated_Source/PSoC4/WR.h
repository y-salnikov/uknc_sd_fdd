/*******************************************************************************
* File Name: WR.h  
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

#if !defined(CY_PINS_WR_H) /* Pins WR_H */
#define CY_PINS_WR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WR_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    WR_Write(uint8 value) ;
void    WR_SetDriveMode(uint8 mode) ;
uint8   WR_ReadDataReg(void) ;
uint8   WR_Read(void) ;
uint8   WR_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define WR_DRIVE_MODE_BITS        (3)
#define WR_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WR_DRIVE_MODE_BITS))

#define WR_DM_ALG_HIZ         (0x00u)
#define WR_DM_DIG_HIZ         (0x01u)
#define WR_DM_RES_UP          (0x02u)
#define WR_DM_RES_DWN         (0x03u)
#define WR_DM_OD_LO           (0x04u)
#define WR_DM_OD_HI           (0x05u)
#define WR_DM_STRONG          (0x06u)
#define WR_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define WR_MASK               WR__MASK
#define WR_SHIFT              WR__SHIFT
#define WR_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define WR_PS                     (* (reg32 *) WR__PS)
/* Port Configuration */
#define WR_PC                     (* (reg32 *) WR__PC)
/* Data Register */
#define WR_DR                     (* (reg32 *) WR__DR)
/* Input Buffer Disable Override */
#define WR_INP_DIS                (* (reg32 *) WR__PC2)


#if defined(WR__INTSTAT)  /* Interrupt Registers */

    #define WR_INTSTAT                (* (reg32 *) WR__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define WR_DRIVE_MODE_SHIFT       (0x00u)
#define WR_DRIVE_MODE_MASK        (0x07u << WR_DRIVE_MODE_SHIFT)


#endif /* End Pins WR_H */


/* [] END OF FILE */
