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


void CaseD(void)
{
int s = 0;
Dagain:	LCD_Command(ENTRY_MODE_3);   //Cursor Moves To the right one column while display Stays in the same place/no movement
	LCD_ClearScreen();
	LCD_String("Cooking Time?");
	Delay_OneSec(2);            //2 seconds delay
	LCD_ClearScreen();
	LCD_Command(ENTRY_MODE_4); //Cursor Moves To the left one column while display Stays in the same place/no movement
	LCD_MoveCursor(1,16);     //Cursor Moves at the end of the end of first row 

	while(1)
	{
	while(KEYPAD_READ() == 0xFF);  //Read the input from the keybad while pressing on it
	countArray[s] = KEYPAD_READ();
        LCD_Character(countArray[s]);
	
       //Cases to deal with any invalid inputs from the user like entering Letters instead of numbers				
	if(countArray[s] == 'A')
	{
          LCD_Command(CLR_DisplayScreen); //Sending clear LCD screen command 
	  Delay_OneMilliSec(10);         //10 milliseconds delay
	  LCD_MoveCursor(1,16);
	  Delay_OneMilliSec(10);
	  LCD_String("Err");
	  Delay_OneSec(1);
	  goto Dagain;                 // Return to enter a valid cooking time
          }

	if(countArray[s] == 'B')
	{
          LCD_Command(CLR_DisplayScreen);
	  Delay_OneMilliSec(10);
	  LCD_MoveCursor(1,16);
	  Delay_OneMilliSec(10);
	  LCD_String("Err");
	  Delay_OneSec(1);        
	  goto Dagain;           // Return to enter a valid cooking time
	}

	if(countArray[s] == 'C')
	{
          LCD_Command(CLR_DisplayScreen);
	  Delay_OneMilliSec(10);
	  LCD_MoveCursor(1,16);
	  Delay_OneMilliSec(10);
	  LCD_String("Err");
	  Delay_OneSec(1);
	  goto Dagain;
          }

	if(countArray[s] == 'D')
	{
          LCD_Command(CLR_DisplayScreen);
	  Delay_OneMilliSec(10);
	  LCD_MoveCursor(1,16);
	  Delay_OneMilliSec(10);
	  LCD_String("Err");
	  Delay_OneSec(1);
	  goto Dagain;     // Return to enter a valid cooking time
          }

	if(countArray[s] == '#')
	{
          LCD_Command(CLR_DisplayScreen);
	  Delay_OneMilliSec(10);
	  LCD_MoveCursor(1,16);
	  Delay_OneMilliSec(10);
	  LCD_String("Err");
	  Delay_OneSec(1);
	  goto Dagain;     // Return to enter a valid cooking time				
          }

	if(countArray[s] == '*')
	{
          LCD_Command(CLR_DisplayScreen);
	  Delay_OneMilliSec(10);
	  LCD_MoveCursor(1,16);
	  Delay_OneMilliSec(10);
	  LCD_String("Err");
	  Delay_OneSec(1);
	  goto Dagain;     // Return to enter a valid cooking time				
	}             
					 

	if(s == 3) break;  //To allow the user to enter 4 numbers only
	Delay_OneMilliSec(150);
	if(s==1)LCD_Character(':');
	s++;
					
       }
	// minus '0' in the following steps to convert character to integer
				
	if ((countArray[3]-'0')>=5)  //To make sure not to enter an valid no. of seconds which is more than 59
	{
	 LCD_Command(CLR_DisplayScreen);
	 Delay_OneMilliSec(10);
	 LCD_MoveCursor(1,16);
	 Delay_OneMilliSec(10);
	 LCD_String("Err");
	 Delay_OneSec(1);
	 goto Dagain;
	}


	if((countArray[0]-'0' ==3) && (countArray[1]-'0' != 0) && (countArray[2]-'0' != 0) && (countArray[3]-'0' != 0))  //To limit the input to 30 minutes maximum 30:00
	{
         LCD_Command(CLR_DisplayScreen);
	 Delay_OneMilliSec(10);
	 LCD_MoveCursor(1,16);
	 Delay_OneMilliSec(10);
	 LCD_String("Err");
	 Delay_OneSec(1);
	 goto Dagain;
	}


	while(!((READ_PIN_VALUE('F', 0) == 1) ^ (READ_PIN_VALUE('E', 5) == 1)));  //It will get out of while loop if either of the switches is pressed

	while(READ_PIN_VALUE('E', 5) == 0)   //If SW1 is pressed
	{
	  LCD_ClearScreen();   
	  goto Dagain;
	}

	while(1)
	{
	if((countArray[0]-'0' == 0) && (countArray[1]-'0' == 0) && (countArray[2]-'0' == 0) && (countArray[3]-'0' == 0)) //In order not to enter zeros 00:00 
	{
	  LCD_Command(CLR_DisplayScreen);
	  Delay_OneMilliSec(10);
	  LCD_MoveCursor(1,16);
	  Delay_OneMilliSec(10);
	  LCD_String("Err");
	  Delay_OneSec(1);
	  goto Dagain;
	}
	if((countArray[0]-'0' >= 3) && (countArray[1]-'0'  >=  0) && (countArray[2]-'0'  >=  0) && (countArray[3]-'0'  >=  0))  //In order not to enter more than 30 minutes
	{
	  LCD_Command(CLR_DisplayScreen);
	  Delay_OneMilliSec(10);
	  LCD_MoveCursor(1,16);
	  Delay_OneMilliSec(10);
	  LCD_String("Err");
	  Delay_OneSec(1);
	  goto Dagain;
	}
					
	if (READ_PIN_VALUE('F' , 0)==0){break;}    //If SW2 is pressed
	LCD_Command(CLR_DisplayScreen);
	Delay_OneMilliSec(10);
	LCD_MoveCursor(1,16);
	}
}


