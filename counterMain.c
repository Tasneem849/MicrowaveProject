#include "LCDdriver.h"
#include "timerA.h" 
// input is array of char arranged where minutes tenth is the first value then munites unitth then seconds tenth then seconds units 
// example 0130 is 1 minute and 30 seconds


void Count(unsigned char count[]){
LCD_Init();
LCD_String(count);
Timer_Init();
while (1) {
if ( count[3] != '0') { count[3]--;}  // if seconds not equal zero minus seconds
else if (count[3]=='0' & count[2] !='0')   {count[2]--; count[3]='9';} // minus 10th of seconds
else if (count[3]=='0' & count[2] =='0' & count[1]!='0')   { count [3]='9' ; count[2]='5'; count[1]--;} // minus minutes
else if (count[3]=='0' & count[2] =='0' & count[1]=='0' & count[0] != '0')   { count [3]='9' ; count[2]='5'; count[1]='9' ; count[0]--;}
else if (count[3]=='0' & count[2] =='0' & count[1]=='0' & count[0] == '0' ) { break;}
 LCD_Character(count[0]);
 LCD_Character(count[1]);
LCD_Character(':');
 LCD_Character(count[2]);
 LCD_Character(count[3]);
timer_wait_oneSec();
LCD_ClearScreen();
}
}

