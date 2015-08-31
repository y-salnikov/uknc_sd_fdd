/*******************************************************************************
* File Name: RD.h  
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

#if !defined(CY_PINS_RD_H) /* Pins RD_H */
#define CY_PINS_RD_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RD_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RD_Write(uint8 value) ;
void    RD_SetDriveMode(uint8 mode) ;
uint8   RD_ReadDataReg(void) ;
uint8   RD_Read(void) ;
uint8   RD_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RD_DRIVE_MODE_BITS        (3)
#define RD_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RD_DRIVE_MODE_BITS))

#define RD_DM_ALG_HIZ         (0x00u)
#define RD_DM_DIG_HIZ         (0x01u)
#define RD_DM_RES_UP          (0x02u)
#define RD_DM_RES_DWN         (0x03u)
#define RD_DM_OD_LO           (0x04u)
#define RD_DM_OD_HI           (0x05u)
#define RD_DM_STRONG          (0x06u)
#define RD_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define RD_MASK               RD__MASK
#define RD_SHIFT              RD__SHIFT
#define RD_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RD_PS                     (* (reg32 *) RD__PS)
/* Port Configuration */
#define RD_PC                     (* (reg32 *) RD__PC)
/* Data Register */
#define RD_DR                     (* (reg32 *) RD__DR)
/* Input Buffer Disable Override */
#define RD_INP_DIS                (* (reg32 *) RD__PC2)


#if defined(RD__INTSTAT)  /* Interrupt Registers */

    #define RD_INTSTAT                (* (reg32 *) RD__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define RD_DRIVE_MODE_SHIFT       (0x00u)
#define RD_DRIVE_MODE_MASK        (0x07u << RD_DRIVE_MODE_SHIFT)


#endif /* End Pins RD_H */


/* [] END OF FILE */
