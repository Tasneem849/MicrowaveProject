#include "keypad.h"
#include "additionalFunctions.h"
#include "Cases.h"
#include <String.h>
#define START 1
#define COOKING 2
#define COUNT 3
#define Done 4
unsigned char type_cooking;
 void SystemInit(void){}
  int main(){
		unsigned char string[] = {'Y','o','u','r',' ','C','h','o','i','c','e','?','\0'};
		int STATE;
		
  KEYPAD_INIT();
		LCD_Init();
		switchesInit();
		Buzzer_Init();
  
  STATE =START ;
  while (1){
    switch(STATE){
  
  case START:{
		LCD_ClearScreen();
    LCD_String(string);
	  while (1){type_cooking= KEYPAD_READ();
		if(type_cooking=='A'||type_cooking=='B'||type_cooking=='C'||type_cooking=='D'){break;}}
	  Delay_OneSec(1);
    STATE = COOKING;
 		LCD_ClearScreen();
		break;}
  case COOKING:
		if (type_cooking=='A')
	{
			 CaseA(); 
			STATE = COUNT;
	}
   else if (type_cooking=='B')
	{
			 CaseB(); 
			STATE = COUNT;
	}
	else if (type_cooking=='C')
	{
			 CaseC(); 
			STATE = COUNT;
	}
	else if (type_cooking=='D')
	{
			 CaseD(); 
			STATE = COUNT;
	}
   break;
	  
  case COUNT:{
		Count();
	STATE = Done;
    break;
  case Done:
     DONE();
	STATE= START;
    break;
      
    }
  }
 
}
}  
