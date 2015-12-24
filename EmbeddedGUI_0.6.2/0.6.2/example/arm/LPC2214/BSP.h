#include "LPC22xx.H"
#ifndef BSP_H
#define BSP_H

//  defination of the registers
#define  FIO0CLR0    (*((volatile unsigned char *) 0x3FFFC01C))
#define  FIO0SET0    (*((volatile unsigned char *) 0x3FFFC018))

void delay(unsigned int n);

// UART functions
//void BSP_UART_SendStringCongestion(const char* string);
//void BSP_UART_SendBufferCongestion(char* string,int length);
//void BSP_UART_ReceiveStringCongestion(char* pBuffer,int size);

#define BSP_UART_SendStringCongestion(x)
#define BSP_UART_ReceiveStringCongestion(x,y)

// LED functions
__inline void BSP_OpenGreenLED(void){
	IOSET2=0x2000000;	
}
__inline void BSP_CloseGreenLED(void){
	IOCLR2=0x2000000;	
}
__inline void BSP_OpenRedLED(void){
	IOSET0=0x0000020;	
}
__inline void BSP_CloseRedLED(void){
	IOCLR0=0x0000020;	
}

//WatchDog functions
__inline void BSP_FeedDog(void){
	IOSET0=0x00008000;
	;
	;
	;
	IOCLR0=0x00008000;
} 

//key functions
unsigned char BSP_GetFuncKey();

#endif
