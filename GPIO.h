#include "GPIO_MACROS.h"

void GPIO_PORT_INT(unsigned char PORTNAME);

void SET_PIN_DIRECTION(unsigned char PORTNAME, unsigned char PINNUMBER, unsigned char DIRECTION);

void WRITE_PIN_VALUE(unsigned char PORTNAME, unsigned char PINNUMBER, unsigned char VALUE);

unsigned char READ_PIN_VALUE(unsigned char PORTNAME, unsigned char PINNUMBER);

void TOGGLE_PIN(unsigned char PORTNAME, unsigned char PINNUMBER);

void SET_PORT_DIRECTION(unsigned char PORTNAME, unsigned char DIRECTION);

void WRITE_PORT_VALUE(unsigned char PORTNAME, unsigned char VALUE);

unsigned char READ_PORT(unsigned char PORTNAME);

void ENABLE_PULLUP(unsigned char PORTNAME, unsigned char PINNUMBER);

void WRITE_HIGH_NIPPLE(unsigned char PORTNAME, unsigned char VALUE);

void WRITE_LOW_NIPPLE(unsigned char PORTNAME, unsigned char VALUE);
