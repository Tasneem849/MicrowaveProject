#include "GPIO.h"
#include "systick.h"

#define BuzzerPort 'E'		//Initialize Buzzer on Port E
#define BuzzerPin 3				//Initialize Buzzer on Pin E3

void Buzzer_Init(void);
void Buzzer_ON(void);
void Buzzer_OFF(void);
void Buzzer_BUZZ(void);
void Buzzer_Alarm(unsigned long seconds);
