#include "Keypad.h"

void KEYPAD_INIT(void)
	{
		GPIO_PORT_INT(KEYPAD_ROWS);
		GPIO_PORT_INT(KEYPAD_COLUMNS);
		
		SET_PIN_DIRECTION(KEYPAD_ROWS, 0, 1);   //Set Rows as Output
		SET_PIN_DIRECTION(KEYPAD_ROWS, 1, 1);
		SET_PIN_DIRECTION(KEYPAD_ROWS, 2, 1);
		SET_PIN_DIRECTION(KEYPAD_ROWS, 3, 1);
		
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
																		 
			for (ROW = 0; ROW <= 3; ROW++)
				{
					WRITE_LOW_NIPPLE(KEYPAD_ROWS, 0xFF);
					WRITE_PIN_VALUE(KEYPAD_ROWS, ROW, 0);
					

					for (COL = 0; COL <= 3; COL++)
						{
							J = READ_PIN_VALUE(KEYPAD_COLUMNS, COL + 4);
							
							if(J==0)
								RETURN_VAL = ARRAY[ROW][COL];
							break;
						}
						
					if(J==0) break;
						
					return RETURN_VAL;
				}
				
				return RETURN_VAL;
	}
