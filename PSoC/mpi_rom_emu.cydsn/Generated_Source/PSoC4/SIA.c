/*******************************************************************************
* File Name: SIA.c  
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
#include "SIA.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SIA_PC =   (SIA_PC & \
                                (uint32)(~(uint32)(SIA_DRIVE_MODE_IND_MASK << (SIA_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SIA_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SIA_Write
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
void SIA_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SIA_DR & (uint8)(~SIA_MASK));
    drVal = (drVal | ((uint8)(value << SIA_SHIFT) & SIA_MASK));
    SIA_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SIA_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SIA_DM_STRONG     Strong Drive 
*  SIA_DM_OD_HI      Open Drain, Drives High 
*  SIA_DM_OD_LO      Open Drain, Drives Low 
*  SIA_DM_RES_UP     Resistive Pull Up 
*  SIA_DM_RES_DWN    Resistive Pull Down 
*  SIA_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SIA_DM_DIG_HIZ    High Impedance Digital 
*  SIA_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SIA_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SIA__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SIA_Read
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
*  Macro SIA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SIA_Read(void) 
{
    return (uint8)((SIA_PS & SIA_MASK) >> SIA_SHIFT);
}


/*******************************************************************************
* Function Name: SIA_ReadDataReg
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
uint8 SIA_ReadDataReg(void) 
{
    return (uint8)((SIA_DR & SIA_MASK) >> SIA_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SIA_INTSTAT) 

    /*******************************************************************************
    * Function Name: SIA_ClearInterrupt
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
    uint8 SIA_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SIA_INTSTAT & SIA_MASK);
		SIA_INTSTAT = maskedStatus;
        return maskedStatus >> SIA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
