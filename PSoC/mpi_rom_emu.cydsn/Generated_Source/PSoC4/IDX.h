/*******************************************************************************
* File Name: IDX.h  
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

#if !defined(CY_PINS_IDX_H) /* Pins IDX_H */
#define CY_PINS_IDX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "IDX_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    IDX_Write(uint8 value) ;
void    IDX_SetDriveMode(uint8 mode) ;
uint8   IDX_ReadDataReg(void) ;
uint8   IDX_Read(void) ;
uint8   IDX_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define IDX_DRIVE_MODE_BITS        (3)
#define IDX_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - IDX_DRIVE_MODE_BITS))

#define IDX_DM_ALG_HIZ         (0x00u)
#define IDX_DM_DIG_HIZ         (0x01u)
#define IDX_DM_RES_UP          (0x02u)
#define IDX_DM_RES_DWN         (0x03u)
#define IDX_DM_OD_LO           (0x04u)
#define IDX_DM_OD_HI           (0x05u)
#define IDX_DM_STRONG          (0x06u)
#define IDX_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define IDX_MASK               IDX__MASK
#define IDX_SHIFT              IDX__SHIFT
#define IDX_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IDX_PS                     (* (reg32 *) IDX__PS)
/* Port Configuration */
#define IDX_PC                     (* (reg32 *) IDX__PC)
/* Data Register */
#define IDX_DR                     (* (reg32 *) IDX__DR)
/* Input Buffer Disable Override */
#define IDX_INP_DIS                (* (reg32 *) IDX__PC2)


#if defined(IDX__INTSTAT)  /* Interrupt Registers */

    #define IDX_INTSTAT                (* (reg32 *) IDX__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define IDX_DRIVE_MODE_SHIFT       (0x00u)
#define IDX_DRIVE_MODE_MASK        (0x07u << IDX_DRIVE_MODE_SHIFT)


#endif /* End Pins IDX_H */


/* [] END OF FILE */
