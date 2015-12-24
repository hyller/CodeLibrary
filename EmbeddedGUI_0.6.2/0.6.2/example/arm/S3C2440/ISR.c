#include "BSP.h"

	extern unsigned int timerScale;

void desktopRedraw(void);
void timerISR(void);

void HaltUndef(void){
	BSP_UART_SendCongestionString(0,"Undefined instruction exception!!!\n\0");
	while(1);
}

void HaltSwi(void){
	BSP_UART_SendCongestionString(0,"SWI exception!!!\n\0");
	while(1);
}

void HaltPabort(void){
	BSP_UART_SendCongestionString(0,"Pabort exception!!!\n\0");
	while(1);
}

void HaltDabort(void){
	BSP_UART_SendCongestionString(0,"Dabort exception!!!\n\0");
	while(1);
}

void __irq IRQ_ISR(void){
	BSP_UART_SendCongestionString(0,"IRQ exception!!!\n\0");
	if(SRCPND&0x80000000){
	//Touchscreen IRQ
		BSP_TouchScreen_ISR();
	}
	if(SRCPND&BIT_TIMER2){
	// Timer2  IRQ				
		timerISR();
	}
}

void timerISR(void){	
	if(timerScale<=0x00010000){
		timerScale++;
	}else{
		timerScale=0;
		BSP_UART_SendCongestionString(0,"Timer2 IRQ. \n\0");
		desktopRedraw();
	}
	BSP_Timer_ClearInterruptFlag(0);
}

void FIQ_ISR(void){
	BSP_UART_SendCongestionString(0,"FIQ exception!!!\n\0");
	while(1);
}

