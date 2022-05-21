#include "Cases.h"



void CaseB(void)
{
unsigned char RETURN;
int i;
double time;
Bweight:	LCD_ClearScreen();
					LCD_String("Beef Weight?");
					Delay_OneSec(1);
					while(KEYPAD_READ()==0xFF);
					RETURN = KEYPAD_READ();


          i = RETURN -'0';

          if(i<=9&&i!=0&&i!=-13&&i!=-6)
					{
						LCD_ClearScreen();

						LCD_Character(RETURN);

							Delay_OneMilliSec(200);
//delay 2 seconds
						LCD_ClearScreen();

						time = (RETURN -'0')* 0.5;

						Countdown_doubletochar(time);
						displaycount();
						while(READ_PIN_VALUE('F' , 0)== 1);

					}

					if(RETURN == 'A'){

                LCD_ClearScreen();
                LCD_String("Err");
                Delay_OneMilliSec(1000);
                LCD_ClearScreen();
							  goto Bweight;
             }

				 if(RETURN == 'B'){

                LCD_ClearScreen();
                LCD_String("Err");
                Delay_OneMilliSec(1000);
                LCD_ClearScreen();
							  goto Bweight;
             }

						   if(RETURN == 'C'){

                LCD_ClearScreen();
                LCD_String("Err");
                Delay_OneMilliSec(1000);
                LCD_ClearScreen();
								 goto Bweight;
             }

						    if(RETURN == 'D'){

                LCD_ClearScreen();
                LCD_String("Err");
                Delay_OneMilliSec(1000);
                LCD_ClearScreen();
								goto Bweight;
             }

						   if(RETURN == '#'){

                LCD_ClearScreen();
                LCD_String("Err");
                Delay_OneMilliSec(1000);
                LCD_ClearScreen();
								goto Bweight;
             }

						    if(RETURN == '*'){

                LCD_ClearScreen();
                LCD_String("Err");
                Delay_OneMilliSec(1000);
                LCD_ClearScreen();
								goto Bweight;
             }


						 if(RETURN == '0'){

                LCD_ClearScreen();
                LCD_String("Err");
                Delay_OneMilliSec(1000);
                LCD_ClearScreen();
								goto Bweight;
             }
					while (READ_PIN_VALUE('F' , 0) == 1);
}



