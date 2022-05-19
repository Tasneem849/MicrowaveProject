#include "CountDown.h"
#include "additionalFunctions.h"
#include "GPIO.h"
#include "led.h"
#include "Buzzer.h"
#include "CountDown.h"
#include "systick.h"
void pause_func (){
	LED_TOGGLE('F' ,1);
	LED_TOGGLE('F' ,2);
	LED_TOGGLE('F' ,3);
	timer_wait();
	 }

void start_func( ){
   	
	LED_ON('F' ,1);
	LED_ON('F' ,2);
	LED_ON('F' ,3);
	}

void stop_func ( int switches){ // resets count and turns off leds 
	if (switches==2){
	countArray[0]='0';
	countArray[1]='0';
	countArray[2]='0';
	countArray[3]='0';
		timer_wait();
   LCD_ClearScreen();
   LED_OFF('F' ,1);
	LED_OFF('F' ,2);
	LED_OFF('F' ,3);
			Delay_OneMilliSec(300);
		LED_ON('F' ,1);
	LED_ON('F' ,2);
	LED_ON('F' ,3);


  }
}
void switchesInit(void){
	GPIO_PORT_INT('E');
	GPIO_PORT_INT('F');
	SET_PIN_DIRECTION( 'E',  4,  0); //DOOR SWITCH IS E4
  SET_PIN_DIRECTION( 'E',  5,  0);   // PAUSE SWITH IS E5
  SET_PIN_DIRECTION( 'F',  0,  0);   // DOOR SWITCH IS F1
    
  ENABLE_PULLUP( 'E',  4); //DOOR SWITCH IS E4
  ENABLE_PULLUP( 'E',  5);   // PAUSE SWITH IS E5
  ENABLE_PULLUP( 'F',  0);   // START SWITCH IS F0
	LED_Init('F' , 1);
  LED_Init('F' , 2);
	LED_Init('F' , 3);
    }
void DONE(){
  int i;
	Buzzer_Init();
 
   for (i=0;i<3;i++){
  LED_TOGGLE('F' ,1);
	LED_TOGGLE('F' ,2);
	LED_TOGGLE('F' ,3);
	Delay_OneMilliSec(200);
  }
	 Buzzer_Alarm(3);
 }
