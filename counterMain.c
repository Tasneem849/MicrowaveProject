#include "counterMain.h" 
// input is array of char arranged where minutes tenth is the first value then munites unitth then seconds tenth then seconds units 
// example 0130 is 1 minute and 30 seconds



void Count(){

LCD_Init();
LCD_String(countArray);
Timer_Init();

while (1)
	{
		if ( countArray[3] != '0') { countArray[3]--;}  // if seconds not equal zero minus seconds
		else if (countArray[3]=='0' & countArray[2] !='0')   {countArray[2]--; countArray[3]='9';} // minus 10th of seconds
		else if (countArray[3]=='0' & countArray[2] =='0' & countArray[1]!='0')   { countArray [3]='9' ; countArray[2]='5'; countArray[1]--;} // minus minutes
		else if (countArray[3]=='0' & countArray[2] =='0' & countArray[1]=='0' & countArray[0] != '0')   { countArray [3]='9' ; countArray[2]='5'; countArray[1]='9' ; countArray[0]--;}
		else if (countArray[3]=='0' & countArray[2] =='0' & countArray[1]=='0' & countArray[0] == '0' ) { break;}
		LCD_Character(countArray[0]);
		LCD_Character(countArray[1]);
		LCD_Character(':');
		LCD_Character(countArray[2]);
		LCD_Character(countArray[3]);
		timer_wait_oneSec();
		LCD_ClearScreen();
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
