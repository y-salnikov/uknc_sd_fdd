/*******************************************************************************
* File Name: BYTE.h  
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

#if !defined(CY_PINS_BYTE_H) /* Pins BYTE_H */
#define CY_PINS_BYTE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BYTE_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BYTE_Write(uint8 value) ;
void    BYTE_SetDriveMode(uint8 mode) ;
uint8   BYTE_ReadDataReg(void) ;
uint8   BYTE_Read(void) ;
uint8   BYTE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BYTE_DRIVE_MODE_BITS        (3)
#define BYTE_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BYTE_DRIVE_MODE_BITS))

#define BYTE_DM_ALG_HIZ         (0x00u)
#define BYTE_DM_DIG_HIZ         (0x01u)
#define BYTE_DM_RES_UP          (0x02u)
#define BYTE_DM_RES_DWN         (0x03u)
#define BYTE_DM_OD_LO           (0x04u)
#define BYTE_DM_OD_HI           (0x05u)
#define BYTE_DM_STRONG          (0x06u)
#define BYTE_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define BYTE_MASK               BYTE__MASK
#define BYTE_SHIFT              BYTE__SHIFT
#define BYTE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BYTE_PS                     (* (reg32 *) BYTE__PS)
/* Port Configuration */
#define BYTE_PC                     (* (reg32 *) BYTE__PC)
/* Data Register */
#define BYTE_DR                     (* (reg32 *) BYTE__DR)
/* Input Buffer Disable Override */
#define BYTE_INP_DIS                (* (reg32 *) BYTE__PC2)


#if defined(BYTE__INTSTAT)  /* Interrupt Registers */

    #define BYTE_INTSTAT                (* (reg32 *) BYTE__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define BYTE_DRIVE_MODE_SHIFT       (0x00u)
#define BYTE_DRIVE_MODE_MASK        (0x07u << BYTE_DRIVE_MODE_SHIFT)


#endif /* End Pins BYTE_H */


/* [] END OF FILE */
