#include "LCDdriver.h"

/********************** LCD Initialization Function **********************/

void LCD_Init(void)
{
    GPIO_PORT_INT(LCD_DATAPORT);            //Initialize Port B to interface with LCD
    GPIO_PORT_INT(LCD_CTRLPORT);            //Initialize Port E to interface with LCD
    SET_PORT_DIRECTION(LCD_DATAPORT, 0xFF);               //Set the LCD Data Port Direction as Output
    SET_PIN_DIRECTION(LCD_CTRLPORT, LCD_RegSelect, 1);    //Set the direction of RS Pin of LCD Control Port as Output
    SET_PIN_DIRECTION(LCD_CTRLPORT, LCD_ReadWrite, 1);    //Set the direction of RW Pin of LCD Control Port as Output
    SET_PIN_DIRECTION(LCD_CTRLPORT, LCD_ENABLE, 1);       //Set the direction of EN Pin of LCD Control Port as Output
    WRITE_PIN_VALUE(LCD_CTRLPORT, LCD_ReadWrite, 0);      //Set the RW Pin LOW to Enable the Write Operation on the LCD
    WRITE_PIN_VALUE(LCD_CTRLPORT, LCD_ENABLE, 0);         //Initialize the EN Pin Low

    Delay_OneMilliSec(20);    //LCD Power On Delay

    LCD_Command(EIGHT_BITS_MODE);          //Initialize The LCD in 8-bit Mode

    Delay_OneMilliSec(1);     //One Millisecond Delay

    LCD_Command(CursorBLINK_DisplayON);   //Initialize the LCD's display to be ON and cursor to be ON and Blinking

    Delay_OneMilliSec(1);     //One Millisecond Delay

    LCD_Command(ENTRY_MODE_3);            //Initialize the LCD's Entry Mode to Shift Cursor Right

    Delay_OneMilliSec(1);     //One Millisecond Delay

    LCD_ClearScreen();                  //Clear the LCD Display Screen by calling the LCD ClearScreen Function
}
/**********************************************************************************/

/************************** LCD SendClockPulse Function ***************************/

static void SendCLKPulse(void)
{
 WRITE_PIN_VALUE(LCD_CTRLPORT, LCD_ENABLE, 1);     //Set Enable High

 Delay_OneMilliSec(2);     //Two Milliseconds Delay

 WRITE_PIN_VALUE(LCD_CTRLPORT, LCD_ENABLE, 0);     //Set Enable Low

 Delay_OneMilliSec(2);     //Two Milliseconds Delay
}
/**********************************************************************************/

/**************************** LCD SendCommand Function ****************************/

void LCD_Command(unsigned char CMD)
{
    WRITE_PORT_VALUE(LCD_DATAPORT, CMD);        //Send the Command needed to the LCD through Data Port

    WRITE_PIN_VALUE(LCD_CTRLPORT, LCD_RegSelect, 0);   //Set RS Low for sending commands to LCD

    SendCLKPulse();      //Send Pulse to EN for Activating the LCD

    Delay_OneMilliSec(1);     //One Millisecond Delay
}
/**********************************************************************************/

/*************************** LCD SendCharacter Function ***************************/

void LCD_Character(unsigned char character)
{
    WRITE_PORT_VALUE(LCD_DATAPORT, character);         //Send the Character needed to the LCD through Data Port

    WRITE_PIN_VALUE(LCD_CTRLPORT, LCD_RegSelect, 1);   //Set RS High for sending data to LCD

    SendCLKPulse();      //Send Pulse to EN for Activating the LCD

    Delay_OneMilliSec(1);     //One Millisecond Delay
}
/**********************************************************************************/

/**************************** LCD SendString Function *****************************/

void LCD_String(unsigned char *STR)       //Sends one character at a time to the LCD SendCharacter Function till the end of the string.
{
    while ((*STR) != '\0')       //As long as string is not terminated by NULL
    {
        LCD_Character(*STR);    //Calling the LCD SendCharacter Function once each loop iteration

        STR++;        //Incrementing the address by one for each loop iteration
    }
}
/**********************************************************************************/

/**************************** LCD ClearScreen Function ****************************/

void LCD_ClearScreen(void)
{
    LCD_Command(CLR_DisplayScreen);            //Clear the LCD's Display Screen

    Delay_OneMilliSec(10);                     //LCD Clear Screen Delay

    LCD_Command(ReturnCursorHomePosition);     //Cursor at Home Position (Row1,Column1)

    Delay_OneMilliSec(1);     //One Millisecond Delay
}
/**********************************************************************************/

/**************************** LCD MoveCursor Function *****************************/

void LCD_MoveCursor(unsigned char row, unsigned char column)       //Rows and Columns start from "1" (Rows 1-->2 , Columns 1-->16)
{
    unsigned char position = 0;

    if (row == 1)
        position = (0x80) + (column - 1);             //Cursor at first row

    else if (row == 2)
        position = (0xC0) + (column - 1);             //Cursor at second row

    else                                              //To ensure no garbage value is passed as a command
        position = ReturnCursorHomePosition;

    LCD_Command(position);

    Delay_OneMilliSec(1);     //One Millisecond Delay
}

/**********************************************************************************/

void LCD_DisplayPressed(void)
{
	int K;
	unsigned char PressedKey;
	PressedKey = KEYPAD_READ();

	while(PressedKey == 0xFF);

	if(PressedKey == '1')
		{
			LCD_Character('1');
			K++;
		}

		if(PressedKey == '4')
		{
			LCD_Character('4');
			K++;
		}

		if(PressedKey == '7')
		{
			LCD_Character('7');
			K++;
		}

		if(PressedKey == '*')
		{
			LCD_Character('*');
			K++;
		}

		if(PressedKey == '2')
		{
			LCD_Character('2');
			K++;
		}

		if(PressedKey == '5')
		{
			LCD_Character('5');
			K++;
		}

		if(PressedKey == '8')
		{
			LCD_Character('8');
			K++;
		}

		if(PressedKey == '0')
		{
			LCD_Character('0');
			K++;
		}

		if(PressedKey == '3')
		{
			LCD_Character('3');
			K++;
		}

		if(PressedKey == '6')
		{
			LCD_Character('6');
			K++;
		}

		if(PressedKey == '9')
		{
			LCD_Character('9');
			K++;
		}

		if(PressedKey == '#')
		{
			LCD_Character('#');
			K++;
		}

		if(PressedKey == 'A')
		{
			LCD_Character('A');
			K++;
		}

		if(PressedKey == 'B')
		{
			LCD_Character('B');
			K++;
		}

		if(PressedKey == 'C')
		{
			LCD_Character('C');
			K++;
		}

		if(PressedKey == 'D')
		{
			LCD_Character('D');
			K++;
		}

		if(K == 32)			//if LCD Display is full
		{
			LCD_ClearScreen();    //Clear Screen and Return Cursor to Home Position
			K = 0;	//Counter resets
		}
}