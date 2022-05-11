#include "tm4c123gh6pm.h"

//Function Like Macros
#define SET_BIT(RegName, BitNumber) (RegName) |= (1<<BitNumber)
#define CLR_BIT(RegName, BitNumber) (RegName) &= (~(1<<BitNumber))
#define TOG_BIT(RegName, BitNumber) (RegName) ^= (1<<BitNumber)
#define READ_BIT(RegName, BitNumber) ((RegName) & (1<<BitNumber)) >> BitNumber
#define SET_PORT(RegName) (RegName) = 0xFF
#define CLR_PORT(RegName) (RegName) = 0x00

//Ports
#define GPIO_PORTA 'A'
#define GPIO_PORTB 'B'
#define GPIO_PORTC 'C'
#define GPIO_PORTD 'D'
#define GPIO_PORTE 'E'
#define GPIO_PORTF 'F'

//Pins
#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7
