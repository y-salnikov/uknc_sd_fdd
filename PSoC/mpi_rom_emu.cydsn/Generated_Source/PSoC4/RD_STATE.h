/*******************************************************************************
* File Name: RD_STATE.h  
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

#if !defined(CY_STATUS_REG_RD_STATE_H) /* CY_STATUS_REG_RD_STATE_H */
#define CY_STATUS_REG_RD_STATE_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*        Function Prototypes
***************************************/

uint8 RD_STATE_Read(void) ;
void RD_STATE_InterruptEnable(void) ;
void RD_STATE_InterruptDisable(void) ;
void RD_STATE_WriteMask(uint8 mask) ;
uint8 RD_STATE_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define RD_STATE_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define RD_STATE_INPUTS              1


/***************************************
*             Registers
***************************************/

/* Status Register */
#define RD_STATE_Status             (* (reg8 *) RD_STATE_sts_sts_reg__STATUS_REG )
#define RD_STATE_Status_PTR         (  (reg8 *) RD_STATE_sts_sts_reg__STATUS_REG )
#define RD_STATE_Status_Mask        (* (reg8 *) RD_STATE_sts_sts_reg__MASK_REG )
#define RD_STATE_Status_Aux_Ctrl    (* (reg8 *) RD_STATE_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_RD_STATE_H */


/* [] END OF FILE */
