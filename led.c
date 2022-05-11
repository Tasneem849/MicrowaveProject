#include "led.h"


void LED_Init(unsigned char PORTNAME , unsigned char PINNUMBER){
    GPIO_INT(PORTNAME);//intialize port
    SET_PIN_DIRECTION(PORTNAME, PINNUMBER, 1);//set the bin output

}
void LED_ON(unsigned char PORTNAME , unsigned char PINNUMBER){
    WRITE_PIN_VALUE(PORTNAME, PINNUMBER, 1);//turn on the led
    }
void LED_OFF(unsigned char PORTNAME , unsigned char PINNUMBER){
    WRITE_PIN_VALUE(PORTNAME, PINNUMBER, 0);//turn off the led


}
void LED_TOGGLE(unsigned char PORTNAME , unsigned char PINNUMBER) {
    TOGGLE_PIN(PORTNAME, PINNUMBER);//toggle the led

}


