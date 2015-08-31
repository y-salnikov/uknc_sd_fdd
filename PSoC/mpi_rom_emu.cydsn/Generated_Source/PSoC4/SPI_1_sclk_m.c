/*******************************************************************************
* File Name: SPI_1_sclk_m.c  
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
#include "SPI_1_sclk_m.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SPI_1_sclk_m_PC =   (SPI_1_sclk_m_PC & \
                                (uint32)(~(uint32)(SPI_1_sclk_m_DRIVE_MODE_IND_MASK << (SPI_1_sclk_m_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SPI_1_sclk_m_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SPI_1_sclk_m_Write
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
void SPI_1_sclk_m_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SPI_1_sclk_m_DR & (uint8)(~SPI_1_sclk_m_MASK));
    drVal = (drVal | ((uint8)(value << SPI_1_sclk_m_SHIFT) & SPI_1_sclk_m_MASK));
    SPI_1_sclk_m_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SPI_1_sclk_m_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SPI_1_sclk_m_DM_STRONG     Strong Drive 
*  SPI_1_sclk_m_DM_OD_HI      Open Drain, Drives High 
*  SPI_1_sclk_m_DM_OD_LO      Open Drain, Drives Low 
*  SPI_1_sclk_m_DM_RES_UP     Resistive Pull Up 
*  SPI_1_sclk_m_DM_RES_DWN    Resistive Pull Down 
*  SPI_1_sclk_m_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SPI_1_sclk_m_DM_DIG_HIZ    High Impedance Digital 
*  SPI_1_sclk_m_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SPI_1_sclk_m_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SPI_1_sclk_m__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SPI_1_sclk_m_Read
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
*  Macro SPI_1_sclk_m_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SPI_1_sclk_m_Read(void) 
{
    return (uint8)((SPI_1_sclk_m_PS & SPI_1_sclk_m_MASK) >> SPI_1_sclk_m_SHIFT);
}


/*******************************************************************************
* Function Name: SPI_1_sclk_m_ReadDataReg
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
uint8 SPI_1_sclk_m_ReadDataReg(void) 
{
    return (uint8)((SPI_1_sclk_m_DR & SPI_1_sclk_m_MASK) >> SPI_1_sclk_m_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SPI_1_sclk_m_INTSTAT) 

    /*******************************************************************************
    * Function Name: SPI_1_sclk_m_ClearInterrupt
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
    uint8 SPI_1_sclk_m_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SPI_1_sclk_m_INTSTAT & SPI_1_sclk_m_MASK);
		SPI_1_sclk_m_INTSTAT = maskedStatus;
        return maskedStatus >> SPI_1_sclk_m_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
