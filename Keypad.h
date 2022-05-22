#include "GPIO.h"
#include "Button.h"

#define KEYPAD_ROWS 'A'					//ROWS are on pins A4, A5, A6, A7
#define KEYPAD_COLUMNS 'C'      //COLUMNS are on pins C4, C5, C6, C7


void KEYPAD_INIT(void);

unsigned char KEYPAD_READ(void);
