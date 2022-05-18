#include "tm4c123gh6pm.h"
void Timer_Init(void)
{
    SYSCTL_RCGCTIMER_R |= 0x01 ;// TIMERn =0//
     // enable 
}
void timer_wait(void)
{
    // na2es lw hashaghal interrupt
    TIMER0_CTL_R &= ~(1<<0);  // disable timer count
    TIMER0_CFG_R = 0x0000000000; /// set conf=0
    TIMER0_TAMR_R  |= 0x02; // enabling periodic mode
    TIMER0_TAMR_R  &= ~(1<<4); // enabling count down 
    TIMER0_TAILR_R = 0x186A00; // timer is set to one second
    // interrupt step here//
    TIMER0_CTL_R |= (1<<0); // enabling timer count
    while (1)
    { //checking the end of counting by checking flag if it is equal to 1
    if ((TIMER0_RIS_R & 0x01)==1)
    {
       TIMER0_ICR_R |= 0x01;
       TIMER0_MIS_R ^= (1<<2);
	    break; 
    }
    }
}
void timer_wait_inSec(int number)
{
	int i;
    for(i=0 ;i<10*number;i++)
    {
        timer_wait();
    }
}
