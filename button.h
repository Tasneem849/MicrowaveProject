#include "GPIO.h"

void BUTTON_INIT(unsigned char PORTNAME , unsigned char PINNUMBER);

unsigned char READ_BUTTON(unsigned char PORTNAME , unsigned char PINNUMBER);

void enable_PULLUP_RESISTOR(unsigned char PORTNAME , unsigned char PINNUMBER);
