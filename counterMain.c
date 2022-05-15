#include "counterMain.h" 
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

void Countdown_doubletochar(double Time)		//Convert double value to char
{
	unsigned char minutes_Tens;				//Variable to store the value of the integer part only in tens
	unsigned char minutes_Units;			//Variable to store the value of the integer part only in units
	int seconds;											//Variable to store the total value of the decimal part only (total seconds)
	unsigned char	seconds_Tens;				//Variable to store the value of the decimal part only in tens
	unsigned char seconds_Units;			//Variable to store the value of the decimal part only in units
	unsigned char ArrayOfChar[4];			//Array to store in it the four variables as characters
	
	minutes_Tens = (Time / 10);
	minutes_Units = (Time - (minutes_Tens * 10));

	seconds = ((Time - (int)Time) * 60);

	seconds_Tens = (seconds / 10);
	seconds_Units =	(seconds - (seconds_Tens * 10));

	ArrayOfChar[0] = minutes_Tens + '0';
	ArrayOfChar[1] = minutes_Units + '0';
	ArrayOfChar[2] = seconds_Tens + '0';
	ArrayOfChar[3] = seconds_Units + '0';
	
	Count(ArrayOfChar);
}
