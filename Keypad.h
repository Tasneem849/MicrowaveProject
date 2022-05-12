#include "GPIO.h"
#include "Button.h"

#define KEYPAD_ROWS 'D'					//Rows are on pins D0, D1, D2, D3
#define KEYPAD_COLUMNS 'C'      //Columns are on pins C4, C5, C6, C7


void KEYPAD_INIT(void);

unsigned char KEYPAD_READ(void);
