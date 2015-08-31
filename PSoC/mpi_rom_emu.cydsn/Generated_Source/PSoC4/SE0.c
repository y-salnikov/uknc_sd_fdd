/*******************************************************************************
* File Name: SE0.c  
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
#include "SE0.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SE0_PC =   (SE0_PC & \
                                (uint32)(~(uint32)(SE0_DRIVE_MODE_IND_MASK << (SE0_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SE0_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SE0_Write
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
void SE0_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SE0_DR & (uint8)(~SE0_MASK));
    drVal = (drVal | ((uint8)(value << SE0_SHIFT) & SE0_MASK));
    SE0_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SE0_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SE0_DM_STRONG     Strong Drive 
*  SE0_DM_OD_HI      Open Drain, Drives High 
*  SE0_DM_OD_LO      Open Drain, Drives Low 
*  SE0_DM_RES_UP     Resistive Pull Up 
*  SE0_DM_RES_DWN    Resistive Pull Down 
*  SE0_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SE0_DM_DIG_HIZ    High Impedance Digital 
*  SE0_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SE0_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SE0__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SE0_Read
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
*  Macro SE0_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SE0_Read(void) 
{
    return (uint8)((SE0_PS & SE0_MASK) >> SE0_SHIFT);
}


/*******************************************************************************
* Function Name: SE0_ReadDataReg
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
uint8 SE0_ReadDataReg(void) 
{
    return (uint8)((SE0_DR & SE0_MASK) >> SE0_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SE0_INTSTAT) 

    /*******************************************************************************
    * Function Name: SE0_ClearInterrupt
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
    uint8 SE0_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SE0_INTSTAT & SE0_MASK);
		SE0_INTSTAT = maskedStatus;
        return maskedStatus >> SE0_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
