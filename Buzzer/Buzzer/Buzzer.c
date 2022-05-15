#include "Buzzer.h"

void Buzzer_Init(void)
{
	GPIO_PORT_INT(BuzzerPort);
	SET_PIN_DIRECTION(BuzzerPort, BuzzerPin, 1); 		//Set the Buzzer's Pin as Output
}

void Buzzer_ON(void)
{
	WRITE_PIN_VALUE(BuzzerPort, BuzzerPin, 1);		//Set the Buzzer High
}

void Buzzer_OFF(void)
{
	WRITE_PIN_VALUE(BuzzerPort, BuzzerPin, 0);		//Set the Buzzer Low
}

void Buzzer_BUZZ(void)			//Buzzer Buzzes Once
{
		Buzzer_ON();
		Delay_OneMilliSec(100);
		Buzzer_OFF();
		Delay_OneMilliSec(100);
}

void Buzzer_Alarm(unsigned long seconds)			//Buzzer produce an alarm for certain number of seconds
{
	int i;
  for (i=0; i<seconds; i++)
	{
	  WRITE_PIN_VALUE(BuzzerPort,BuzzerPin, 1);
	  Delay_OneMilliSec(500);
	  WRITE_PIN_VALUE(BuzzerPort,BuzzerPin, 0);
	  Delay_OneMilliSec(500);
  }
  WRITE_PIN_VALUE(BuzzerPort,BuzzerPin, 0);
}
