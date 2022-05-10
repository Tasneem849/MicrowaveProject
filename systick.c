#include "tm4c123gh6pm.h"
void systick_VInit(void)
{
	NVIC_ST_CTRL_R =0;
	NVIC_ST_RELOAD_R =0x00FFFFFF;
	NVIC_ST_CURRENT_R =0;
	NVIC_ST_CTRL_R=0x5;
	
	
}
void SysTick_wait(unsigned long delay){
	NVIC_ST_CTRL_R=0x00;
	NVIC_ST_RELOAD_R=delay-1;
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R=0x05;
	while((NVIC_ST_CTRL_R&0x00010000)==0){}//wait for count flag;
}

void Delay_OneSec(unsigned long time){
	int i;
	for(i=0;i<time*100;i++){
		SysTick_wait(80000); //1s
	}
}
void Delay_OneMilliSec(unsigned long time){
	int i;
	for(i=0;i<time;i++){
		SysTick_wait(80000); //1ms
	}
}
