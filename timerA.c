#include "tm4c123gh6pm.h"
Timer_Init()
{
    SYSCTL_RCGCTIMER_R |= 0x01 // TIMERn =0//
    SYSCTL_RCGCGPIO_R // enable 
}
timer_wait_oneSec()
{
    // na2es lw hashaghal interrupt
    TIMER0_CTL_R &= ~(1<<0);  // disable timer count
    TIMER0_CFG_R = 0x0000000000; /// set conf=0
    TIMER0_TAMR_R  |= 0x02 // enabling periodic mode
    TIMER0_TAMR_R  &= ~(1<<4) // enabling count down 
    TIMER0_TAILR_R = 0x00F4240 // timer is set to one second
    // interrupt step here//
    TIMER0_CTL_R |= (1<<0); // enabling timer count
    while (1)
    { //checking the end of counting by checking flag if it is equal to 1
    if ((TIMER0_RIS_R & 0x01)==1)
    {
       TIMER0_ICR_R |= 0x01;
       TIMER0_MIS_R ^= (1<<2);
    }
    }

}