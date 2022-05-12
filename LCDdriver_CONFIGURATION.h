#ifndef LCDdriver_CONFIGURATION_H
#define LCDdriver_CONFIGURATION_H

/*********************** LCD_MACROS ***********************/

#define LCD_DATAPORT 'B'            //Define LCD Data Pins (D0-D7) as Port B
#define LCD_CTRLPORT 'E'            //Define LCD Control Pins (RS,RW,E) as Port E
#define LCD_ENABLE 0                //Define Pin EN of LCD_CTRLPORT as Pin E0
#define LCD_ReadWrite 1             //Define Pin RW of LCD_CTRLPORT as Pin E1
#define LCD_RegSelect 2             //Define Pin RS of LCD_CTRLPORT as Pin E2

/********************** LCD_COMMANDS **********************/

#define EIGHT_BITS_MODE 0x38            //Initialize LCD As Two Rows, font size is 5 � 8 dot, Data width = 8 bits
#define FOUR_BITS_MODE 0x28             //Initialize LCD As Two Rows, font size is 5 � 8 dot, Data width = 4 bits
#define CLR_DisplayScreen 0x01          //Clears the whole LCD Display Screen and returns cursor to the home position
#define ENTRY_MODE_1 0x04               //Cursor Moves To the left one column while display Stays in the same place/no movement
#define ENTRY_MODE_2 0x05               //Cursor Stays in the same place/no movement whereas Display Moves to the right one column
#define ENTRY_MODE_3 0x06               //Cursor Moves To the right one column while display Stays in the same place/no movement
#define ENTRY_MODE_4 0x07               //Cursor Stays in the same place/no movement whereas Display Moves to the left one column
#define CursorOFF_DisplayON 0x0C        //Initialize Cursor to not appear while display is ON
#define CursorON_DisplayON 0x0E         //Initialize Cursor to appear but not blinking while display is ON
#define CursorBLINK_DisplayON 0x0F      //Initialize Cursor to appear and blink while display is ON
#define CursorOFF_DisplayOFF 0x08       //Initialize Cursor to not appear while display is OFF
#define ReturnCursorHomePosition 0x80   //Returns The Cursor to the Home Position (Row1,Column1)

#endif //LCDdriver_CONFIGURATION_H
