#include "Keypad.h"

void KEYPAD_INIT(void)
	{
		GPIO_PORT_INT(KEYPAD_ROWS);
		GPIO_PORT_INT(KEYPAD_COLUMNS);
		
		SET_PIN_DIRECTION(KEYPAD_ROWS, 4, 1);   //Set Rows as Output
		SET_PIN_DIRECTION(KEYPAD_ROWS, 5, 1);
		SET_PIN_DIRECTION(KEYPAD_ROWS, 6, 1);
		SET_PIN_DIRECTION(KEYPAD_ROWS, 7, 1);
		
		SET_PIN_DIRECTION(KEYPAD_COLUMNS, 4, 0);   //Set Columns as Input
		SET_PIN_DIRECTION(KEYPAD_COLUMNS, 5, 0);
		SET_PIN_DIRECTION(KEYPAD_COLUMNS, 6, 0);
		SET_PIN_DIRECTION(KEYPAD_COLUMNS, 7, 0);
		
		ENABLE_PULLUP(KEYPAD_COLUMNS, 4);
		ENABLE_PULLUP(KEYPAD_COLUMNS, 5);
		ENABLE_PULLUP(KEYPAD_COLUMNS, 6);
		ENABLE_PULLUP(KEYPAD_COLUMNS, 7);
	}


unsigned char KEYPAD_READ(void)
	{
			
			unsigned char ARRAY [4][4] = {  {'1', '2', '3', 'A'}
						       ,{'4', '5', '6', 'B'}
						       ,{'7', '8', '9', 'C'}
						       ,{'*', '0', '#', 'D'} };
			char ROW, J, COL;
																		 
			char RETURN_VAL = 0xFF;
																		 
			for (ROW = 0; ROW <= 3; ROW++)   //check which row has the pressed button
				{
					WRITE_HIGH_NIPPLE(KEYPAD_ROWS, 0xFF);
					WRITE_PIN_VALUE(KEYPAD_ROWS, ROW + 4, 0);
				//(ROW+ 4) because the rows start with A4 to A7
					

					for (COL = 0; COL <= 3; COL++)   //check wich column in this row has the pressed button
						{
							J = READ_PIN_VALUE(KEYPAD_COLUMNS, COL + 4);
						//(COL + 4) because the rows start with C4 to C7 
							
							if(J==0)
							{
								RETURN_VAL = ARRAY[ROW][COL];
								return RETURN_VAL;      //return which button is pressed
							}
						
					       }
				}
				
				return RETURN_VAL;       //return 0xFF if no button is pressed
	}
