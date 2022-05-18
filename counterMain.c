#include "LCDdriver.h"
#include "timerA.h" 
#include "GPIO.h"
#include "additionalFunctions.h"
#include "led.h"
#include "CountDown.h"
// input is array of char arranged where minutes tenth is the first value then munites unitth then seconds tenth then seconds units 
// example 0130 is 1 minute and 30 seconds
unsigned char countArray[4];
void displaycount(){
	  LCD_ClearScreen();
	  LCD_Character(countArray[0]);
		LCD_Character(countArray[1]);
		LCD_Character(':');
		LCD_Character(countArray[2]);
		LCD_Character(countArray[3]);
	
}
void Count(void){
int displayone,switches ,i;
LCD_Init();
Timer_Init();
switchesInit();	
start_func();

displayone=0;	// initialize all functions
  	
while (1)
	{  while (READ_PIN_VALUE( 'E',  4)==1){ // check door
	
		if (displayone==0){
			displayone=1;
	displaycount();}
		
	} // while door open toggle
	displayone=0;
  while ( READ_PIN_VALUE( 'E',  5)==0){ 
		// CHECK PAUSE
	pause:	pause_func();
				LCD_ClearScreen();
		pause_func();
		timer_wait();
    	if (displayone==0){
			displayone=1;
	displaycount();}
		while(1){
			for(i=0;i<5;i++){
			pause_func();}
    if (  READ_PIN_VALUE( 'E',  5)==0 ){ // CHECK PAUSE FOR SECOND TIME TO STOP
			stop_func(2);
			break;
    }
		if (  READ_PIN_VALUE( 'F',  0)==0 ){ // CHECK PAUSE FOR SECOND TIME TO STOP
			start_func();
			break;
    }
		pause_func();
	}
  }
  // read pause
     
		
			

		
	displaycount();
	for (i=0;i<10;i++){
 if(READ_PIN_VALUE( 'E',  5)==0) goto pause;
		timer_wait();
	}

		
	if(READ_PIN_VALUE( 'E',  5)==0) goto pause;
		if ( countArray[3] != '0') { countArray[3]--;}  // if seconds not equal zero minus seconds
		else if (countArray[3]=='0' & countArray[2] !='0')   {countArray[2]--; countArray[3]='9';} // minus 10th of seconds
		else if (countArray[3]=='0' & countArray[2] =='0' & countArray[1]!='0')   { countArray [3]='9' ; countArray[2]='5'; countArray[1]--;} // minus minutes
		else if (countArray[3]=='0' & countArray[2] =='0' & countArray[1]=='0' & countArray[0] != '0')   { countArray [3]='9' ; countArray[2]='5'; countArray[1]='9' ; countArray[0]--;}
		else if (countArray[3]=='0' & countArray[2] =='0' & countArray[1]=='0' & countArray[0] == '0' ) { break;}
	
	
}
	}

void Countdown_doubletochar(double Time)		//Convert double value to an array of characters
{
	unsigned char minutes_Tens;				//Variable to store the value of the integer part only in tens
	unsigned char minutes_Units;			//Variable to store the value of the integer part only in units
	int seconds;											//Variable to store the total value of the decimal part only (total seconds)
	unsigned char	seconds_Tens;				//Variable to store the value of the decimal part only in tens
	unsigned char seconds_Units;			//Variable to store the value of the decimal part only in units
	
	minutes_Tens = (Time / 10);
	minutes_Units = (Time - (minutes_Tens * 10));

	seconds = ((Time - (int)Time) * 60);

	seconds_Tens = (seconds / 10);
	seconds_Units =	(seconds - (seconds_Tens * 10));

	countArray[0] = minutes_Tens + '0';
	countArray[1] = minutes_Units + '0';
	countArray[2] = seconds_Tens + '0';
	countArray[3] = seconds_Units + '0';
}
