/*******************************************************************************
* File Name: CS.h  
* Version 2.0
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

#if !defined(CY_PINS_CS_H) /* Pins CS_H */
#define CY_PINS_CS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CS_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    CS_Write(uint8 value) ;
void    CS_SetDriveMode(uint8 mode) ;
uint8   CS_ReadDataReg(void) ;
uint8   CS_Read(void) ;
uint8   CS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CS_DRIVE_MODE_BITS        (3)
#define CS_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - CS_DRIVE_MODE_BITS))
#define CS_DRIVE_MODE_SHIFT       (0x00u)
#define CS_DRIVE_MODE_MASK        (0x07u << CS_DRIVE_MODE_SHIFT)

#define CS_DM_ALG_HIZ         (0x00u << CS_DRIVE_MODE_SHIFT)
#define CS_DM_DIG_HIZ         (0x01u << CS_DRIVE_MODE_SHIFT)
#define CS_DM_RES_UP          (0x02u << CS_DRIVE_MODE_SHIFT)
#define CS_DM_RES_DWN         (0x03u << CS_DRIVE_MODE_SHIFT)
#define CS_DM_OD_LO           (0x04u << CS_DRIVE_MODE_SHIFT)
#define CS_DM_OD_HI           (0x05u << CS_DRIVE_MODE_SHIFT)
#define CS_DM_STRONG          (0x06u << CS_DRIVE_MODE_SHIFT)
#define CS_DM_RES_UPDWN       (0x07u << CS_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define CS_MASK               CS__MASK
#define CS_SHIFT              CS__SHIFT
#define CS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CS_PS                     (* (reg32 *) CS__PS)
/* Port Configuration */
#define CS_PC                     (* (reg32 *) CS__PC)
/* Data Register */
#define CS_DR                     (* (reg32 *) CS__DR)
/* Input Buffer Disable Override */
#define CS_INP_DIS                (* (reg32 *) CS__PC2)


#if defined(CS__INTSTAT)  /* Interrupt Registers */

    #define CS_INTSTAT                (* (reg32 *) CS__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins CS_H */


/* [] END OF FILE */
