#ifndef LCDDRIVER_H_INCLUDED
#define LCDDRIVER_H_INCLUDED

#include "GPIO.h"
#include "LCDdriver_CONFIGURATION.h"
#include "DELAYdriver.h"

/********************** LCD Initialization Function **********************/

void LCD_Initialize(void)
{
    DIO_SetPortDir(LCD_DATAPORT, 0xFF);                //Set the LCD Data Port Direction as Output
    DIO_SetPinDir(LCD_CTRLPORT, LCD_RegSelect,1);      //Set the direction of RS Pin of LCD Control Port as Output
    DIO_SetPinDir(LCD_CTRLPORT, LCD_ReadWrite,1);      //Set the direction of RW Pin of LCD Control Port as Output
    DIO_SetPinDir(LCD_CTRLPORT, LCD_ENABLE,1);         //Set the direction of EN Pin of LCD Control Port as Output
    DIO_WritePin(LCD_CTRLPORT, LCD_ENABLE, 0);         //Set the RW Pin LOW to Enable the Write Operation on the LCD

    delay_ms(20);    //LCD Power On Delay

    LCD_Command(FOUR_BITS_MODE);          //Initialize The LCD in 4-bit Mode

    delay_ms(1);     //One Millisecond Delay

    LCD_Command(CursorBLINK_DisplayON);   //Initialize the LCD's display to be ON and cursor to be ON and Blinking

    delay_ms(1);     //One Millisecond Delay

    LCD_Command(ENTRY_MODE_3);            //Initialize the LCD's Entry Mode to Shift Cursor Right

    delay_ms(1);     //One Millisecond Delay

    LCD_ClearScreen();                  //Clear the LCD Display Screen by calling the LCD ClearScreen Function
}
/**********************************************************************************/

/************************** LCD SendClockPulse Function ***************************/

static void SendCLKPulse(void)
{
 DIO_WritePin(LCD_CTRLPORT, LCD_ENABLE, 1);     //Set Enable High

 delay_ms(2);     //Two Milliseconds Delay

 DIO_WritePin(LCD_CTRLPORT, LCD_ENABLE, 0);     //Set Enable Low

 delay_ms(2);     //Two Milliseconds Delay
}
/**********************************************************************************/

/**************************** LCD SendCommand Function ****************************/

void LCD_Command(unsigned char CMD)
{
    DIO_WritePort(LCD_DATAPORT, CMD);        //Send the Command needed to the LCD through Data Port

    DIO_WritePin(LCD_CTRLPORT, LCD_RegSelect, 0);   //Set RS Low for sending commands to LCD

    SendCLKPulse();      //Send Pulse to EN for Activating the LCD

    delay_ms(1);     //One Millisecond Delay
}
/**********************************************************************************/

/*************************** LCD SendCharacter Function ***************************/

void LCD_Character(unsigned char character)
{
    DIO_WritePort(LCD_DATAPORT, character);       //Send the Character needed to the LCD through Data Port

    DIO_WritePin(LCD_CTRLPORT, LCD_RegSelect, 1);   //Set RS High for sending data to LCD

    SendCLKPulse();      //Send Pulse to EN for Activating the LCD

    delay_ms(1);     //One Millisecond Delay
}
/**********************************************************************************/

/**************************** LCD SendString Function *****************************/

void LCD_String(unsigned char *STR)       //Sends one character at a time to the LCD SendCharacter Function till the end of the string.
{
    while ((*STR) != '0')       //As long as string is not terminated by NULL
    {
        LCD_Character(*STR);    //Calling the LCD SendCharacter Function once each loop iteration

        STR++;        //Incrementing the address by one each loop iteration
    }
}
/**********************************************************************************/

/**************************** LCD ClearScreen Function ****************************/

void LCD_ClearScreen(void)
{
    LCD_Command(CLR_DisplayScreen);             //Clear the LCD's Display Screen

    delay_ms(10);                               //LCD Clear Screen Delay

    LCD_Command(ReturnCursorHomePosition);      //Cursor at Home Position (Row1,Column1)

    delay_ms(1);     //One Millisecond Delay
}
/**********************************************************************************/

/**************************** LCD MoveCursor Function *****************************/

void LCD_MoveCursor(unsigned char row, unsigned char column)       //Rows and Columns start from "1" (Rows 1-->2 , Columns 1-->16)
{
    unsigned char position = 0;

    if (row == 1)
        position = (0x80) + (column - 1);

    else if (row == 2)
        position = (0xC0) + (column - 1);

    else
        position = ReturnCursorHomePosition;

    LCD_Command(position);        //Call The LCD SendCommand Function to Excute The Command That Moves Cursor To The Needed Position

    delay_ms(1);     //One Millisecond Delay
}
/**********************************************************************************/

/*********************** LCD CreateCustomCharacter Function ***********************/

/*void CreateCustomCharacter(unsigned char *Pattern, unsigned char Location)
{
    int i;

    LCD_Command(0x40 + (Location*8));  //Send the Address of CGRAM

    for(i = 0; i < 8; i++)
        LCD_Character(Pattern[i]);     //Pass the bytes of pattern to LCD
}
/**********************************************************************************/

//Hex value to create the pattern (Heart)
/*unsigned char HeartPattern[] = {0x00,0x1B,0x1F,0x1F,0x1F,0xE0,0x40,0x00};*/

#endif //LCDDRIVER_H_INCLUDED
