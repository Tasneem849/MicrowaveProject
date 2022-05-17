#include "led.h"


void LED_Init(unsigned char PORT_NAME , unsigned char PIN_NUMBER){
    GPIO_PORT_INT(PORT_NAME);//intialize port
    SET_PIN_DIRECTION(PORT_NAME, PIN_NUMBER, 1);//set the bin output

}
void LED_ON(unsigned char PORT_NAME , unsigned char PIN_NUMBER){
    WRITE_PIN_VALUE(PORT_NAME, PIN_NUMBER, 1);//turn on the led
    }
void LED_OFF(unsigned char PORT_NAME , unsigned char PIN_NUMBER){
    WRITE_PIN_VALUE(PORT_NAME, PIN_NUMBER, 0);//turn off the led


}
void LED_TOGGLE(unsigned char PORT_NAME , unsigned char PIN_NUMBER) {
    TOGGLE_PIN(PORT_NAME, PIN_NUMBER);//toggle the led

}


