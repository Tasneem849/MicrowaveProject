#include "tm4c123gh6pm.h"

//Function Like Macros
#define SET_BIT(RegName, BitNumber) (RegName) |= (1<<BitNumber)
#define CLR_BIT(RegName, BitNumber) (RegName) &= (~(1<<BitNumber))
#define TOG_BIT(RegName, BitNumber) (RegName) ^= (1<<BitNumber)
#define READ_BIT(RegName, BitNumber) ((RegName) & (1<<BitNumbre)) >> BitNumber
#define SET_PORT(RegName) (RegName) = 0xFF
#define CLR_PORT(RegName) (RegName) = 0x00

//Ports
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4
#define GPIO_PORTF 5

//Pins
#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7
