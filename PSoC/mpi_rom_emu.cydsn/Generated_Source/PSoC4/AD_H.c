/*******************************************************************************
* File Name: AD_H.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "AD_H.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        AD_H_PC =   (AD_H_PC & \
                                (uint32)(~(uint32)(AD_H_DRIVE_MODE_IND_MASK << (AD_H_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (AD_H_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: AD_H_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void AD_H_Write(uint8 value) 
{
    uint8 drVal = (uint8)(AD_H_DR & (uint8)(~AD_H_MASK));
    drVal = (drVal | ((uint8)(value << AD_H_SHIFT) & AD_H_MASK));
    AD_H_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: AD_H_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  AD_H_DM_STRONG     Strong Drive 
*  AD_H_DM_OD_HI      Open Drain, Drives High 
*  AD_H_DM_OD_LO      Open Drain, Drives Low 
*  AD_H_DM_RES_UP     Resistive Pull Up 
*  AD_H_DM_RES_DWN    Resistive Pull Down 
*  AD_H_DM_RES_UPDWN  Resistive Pull Up/Down 
*  AD_H_DM_DIG_HIZ    High Impedance Digital 
*  AD_H_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void AD_H_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(AD_H__0__SHIFT, mode);
	SetP4PinDriveMode(AD_H__1__SHIFT, mode);
	SetP4PinDriveMode(AD_H__2__SHIFT, mode);
	SetP4PinDriveMode(AD_H__3__SHIFT, mode);
	SetP4PinDriveMode(AD_H__4__SHIFT, mode);
	SetP4PinDriveMode(AD_H__5__SHIFT, mode);
	SetP4PinDriveMode(AD_H__6__SHIFT, mode);
	SetP4PinDriveMode(AD_H__7__SHIFT, mode);
}


/*******************************************************************************
* Function Name: AD_H_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro AD_H_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 AD_H_Read(void) 
{
    return (uint8)((AD_H_PS & AD_H_MASK) >> AD_H_SHIFT);
}


/*******************************************************************************
* Function Name: AD_H_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 AD_H_ReadDataReg(void) 
{
    return (uint8)((AD_H_DR & AD_H_MASK) >> AD_H_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(AD_H_INTSTAT) 

    /*******************************************************************************
    * Function Name: AD_H_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 AD_H_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(AD_H_INTSTAT & AD_H_MASK);
		AD_H_INTSTAT = maskedStatus;
        return maskedStatus >> AD_H_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
