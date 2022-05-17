#include "button.h"


void BUTTON_INIT(unsigned char PORT_NAME , unsigned char PIN_NUMBER){

    GPIO_INIT(PORT_NAME);//intialize port

    SET_PIN_DIRECTION(PORT_NAME , PIN_NUMBER , 0);//set the pin input
    }


unsigned char READ_BUTTON(unsigned char PORT_NAME , unsigned char PIN_NUMBER){

    return(READ_PIN_VALUE(PORT_NAME , PIN_NUMBER));//set the button push on or not
}




void enable_PULLUP_RESISTOR(unsigned char PORT_NAME , unsigned char PIN_NUMBER) {

    SET_PIN_DIRECTION(PORT_NAME , PIN_NUMBER , 0);//set the pin input

    ENABLE_PULLUP(PORT_NAME , PIN_NUMBER);//enable pull up resistance


}
