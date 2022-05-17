#include "GPIO.h"

void BUTTON_INIT(unsigned char PORT_NAME , unsigned char PIN_NUMBER);

unsigned char READ_BUTTON(unsigned char PORT_NAME , unsigned char PIN_NUMBER);

void enable_PULLUP_RESISTOR(unsigned char PORT_NAME , unsigned char PIN_NUMBER);
