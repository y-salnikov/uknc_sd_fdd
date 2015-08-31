/*******************************************************************************
* File Name: STATE.h  
* Version 1.80
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_STATE_H) /* CY_STATUS_REG_STATE_H */
#define CY_STATUS_REG_STATE_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*        Function Prototypes
***************************************/

uint8 STATE_Read(void) ;
void STATE_InterruptEnable(void) ;
void STATE_InterruptDisable(void) ;
void STATE_WriteMask(uint8 mask) ;
uint8 STATE_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define STATE_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define STATE_INPUTS              3


/***************************************
*             Registers
***************************************/

/* Status Register */
#define STATE_Status             (* (reg8 *) STATE_sts_sts_reg__STATUS_REG )
#define STATE_Status_PTR         (  (reg8 *) STATE_sts_sts_reg__STATUS_REG )
#define STATE_Status_Mask        (* (reg8 *) STATE_sts_sts_reg__MASK_REG )
#define STATE_Status_Aux_Ctrl    (* (reg8 *) STATE_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_STATE_H */


/* [] END OF FILE */
