/*******************************************************************************
* File Name: RD_STATE.c  
* Version 1.80
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "RD_STATE.h"

#if !defined(RD_STATE_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: RD_STATE_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 RD_STATE_Read(void) 
{ 
    return RD_STATE_Status;
}


/*******************************************************************************
* Function Name: RD_STATE_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RD_STATE_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    RD_STATE_Status_Aux_Ctrl |= RD_STATE_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: RD_STATE_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RD_STATE_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    RD_STATE_Status_Aux_Ctrl &= (uint8)(~RD_STATE_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: RD_STATE_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void RD_STATE_WriteMask(uint8 mask) 
{
    #if(RD_STATE_INPUTS < 8u)
    	mask &= (uint8)((((uint8)1u) << RD_STATE_INPUTS) - 1u);
	#endif /* End RD_STATE_INPUTS < 8u */
    RD_STATE_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: RD_STATE_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 RD_STATE_ReadMask(void) 
{
    return RD_STATE_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
