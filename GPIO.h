#include "GPIO_MACROS.h"

void GPIO_PORT_INT(unsigned char PORT_NAME);

void SET_PIN_DIRECTION(unsigned char PORT_NAME, unsigned char PIN_NUMBER, unsigned char DIRECTION);

void WRITE_PIN_VALUE(unsigned char PORT_NAME, unsigned char PIN_NUMBER, unsigned char VALUE);

unsigned char READ_PIN_VALUE(unsigned char PORT_NAME, unsigned char PIN_NUMBER);

void TOGGLE_PIN(unsigned char PORT_NAME, unsigned char PIN_NUMBER);

void SET_PORT_DIRECTION(unsigned char PORT_NAME, unsigned char DIRECTION);

void WRITE_PORT_VALUE(unsigned char PORT_NAME, unsigned char VALUE);

unsigned char READ_PORT(unsigned char PORT_NAME);

void ENABLE_PULLUP(unsigned char PORT_NAME, unsigned char PIN_NUMBER);

void WRITE_HIGH_NIPPLE(unsigned char PORT_NAME, unsigned char VALUE);

void WRITE_LOW_NIPPLE(unsigned char PORT_NAME, unsigned char VALUE);
