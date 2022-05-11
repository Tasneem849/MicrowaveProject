#include "button.h"


void BUTTON_INIT(unsigned char PORTNAME , unsigned char PINNUMBER){

    GPIO_INIT(PORTNAME);//intialize port

    SET_PIN_DIRECTION(PORTNAME , PINNUMBER , 0);//set the pin input
    }


unsigned char READ_BUTTON(unsigned char PORTNAME , unsigned char PINNUMBER){

    return(READ_PIN_VALUE(PORTNAME , PINNUMBER));//set the button push on or not
}




void enable_PULLUP_RESISTOR(unsigned char PORTNAME , unsigned char PINNUMBER) {

    SET_PIN_DIRECTION(PORTNAME , PINNUMBER , 0);//set the pin input

    ENABLE_PULLUP(PORTNAME , PINNUMBER);//enable pull up resistance


}
