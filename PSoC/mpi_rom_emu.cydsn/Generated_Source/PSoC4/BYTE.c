/*******************************************************************************
* File Name: BYTE.c  
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
#include "BYTE.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        BYTE_PC =   (BYTE_PC & \
                                (uint32)(~(uint32)(BYTE_DRIVE_MODE_IND_MASK << (BYTE_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (BYTE_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: BYTE_Write
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
void BYTE_Write(uint8 value) 
{
    uint8 drVal = (uint8)(BYTE_DR & (uint8)(~BYTE_MASK));
    drVal = (drVal | ((uint8)(value << BYTE_SHIFT) & BYTE_MASK));
    BYTE_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: BYTE_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  BYTE_DM_STRONG     Strong Drive 
*  BYTE_DM_OD_HI      Open Drain, Drives High 
*  BYTE_DM_OD_LO      Open Drain, Drives Low 
*  BYTE_DM_RES_UP     Resistive Pull Up 
*  BYTE_DM_RES_DWN    Resistive Pull Down 
*  BYTE_DM_RES_UPDWN  Resistive Pull Up/Down 
*  BYTE_DM_DIG_HIZ    High Impedance Digital 
*  BYTE_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void BYTE_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(BYTE__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: BYTE_Read
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
*  Macro BYTE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BYTE_Read(void) 
{
    return (uint8)((BYTE_PS & BYTE_MASK) >> BYTE_SHIFT);
}


/*******************************************************************************
* Function Name: BYTE_ReadDataReg
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
uint8 BYTE_ReadDataReg(void) 
{
    return (uint8)((BYTE_DR & BYTE_MASK) >> BYTE_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BYTE_INTSTAT) 

    /*******************************************************************************
    * Function Name: BYTE_ClearInterrupt
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
    uint8 BYTE_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(BYTE_INTSTAT & BYTE_MASK);
		BYTE_INTSTAT = maskedStatus;
        return maskedStatus >> BYTE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
