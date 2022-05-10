#ifndef LCDdriver_H
#define LCDdriver_H

#include "GPIO.h"
#include "systick.h"
#include "LCDdriver_CONFIGURATION.h"

void LCD_Initialize(void);

static void SendCLKPulse(void);

void LCD_Command(unsigned char CMD);

void LCD_Character(unsigned char character);

void LCD_String(unsigned char *STR);

void LCD_ClearScreen(void);

void LCD_MoveCursor(unsigned char row, unsigned char column);

void CreateCustomCharacter(unsigned char *Pattern, unsigned char Location);

#endif //LCDdriver_H