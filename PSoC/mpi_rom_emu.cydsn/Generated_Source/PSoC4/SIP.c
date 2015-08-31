/*******************************************************************************
* File Name: SIP.c  
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
#include "SIP.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SIP_PC =   (SIP_PC & \
                                (uint32)(~(uint32)(SIP_DRIVE_MODE_IND_MASK << (SIP_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SIP_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SIP_Write
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
void SIP_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SIP_DR & (uint8)(~SIP_MASK));
    drVal = (drVal | ((uint8)(value << SIP_SHIFT) & SIP_MASK));
    SIP_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SIP_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SIP_DM_STRONG     Strong Drive 
*  SIP_DM_OD_HI      Open Drain, Drives High 
*  SIP_DM_OD_LO      Open Drain, Drives Low 
*  SIP_DM_RES_UP     Resistive Pull Up 
*  SIP_DM_RES_DWN    Resistive Pull Down 
*  SIP_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SIP_DM_DIG_HIZ    High Impedance Digital 
*  SIP_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SIP_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SIP__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SIP_Read
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
*  Macro SIP_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SIP_Read(void) 
{
    return (uint8)((SIP_PS & SIP_MASK) >> SIP_SHIFT);
}


/*******************************************************************************
* Function Name: SIP_ReadDataReg
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
uint8 SIP_ReadDataReg(void) 
{
    return (uint8)((SIP_DR & SIP_MASK) >> SIP_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SIP_INTSTAT) 

    /*******************************************************************************
    * Function Name: SIP_ClearInterrupt
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
    uint8 SIP_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SIP_INTSTAT & SIP_MASK);
		SIP_INTSTAT = maskedStatus;
        return maskedStatus >> SIP_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
