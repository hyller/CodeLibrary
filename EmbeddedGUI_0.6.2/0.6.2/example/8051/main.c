//main.c
#include <REG54.H>
#include "INTRINS.H"
#include "LCDDriver.h"
#include "GraphicFunc.h"

void UART_SendStringCongestion(char* string){
	while(*string!='\0'){
		CY=P;
		TB8=CY;
		SBUF=ACC;
		while(TI==0){
			_nop_();
		}	
		TI=0;
	}
}

void emain(){
	//init the LCD 
	EG_LCDInit();
    // Clear the buffer, set the buffer to 0
    EG_LCDClearBuffer();
    // Redraw sth..
	EG_Graphic_DrawHorizonLine(10,10,20);
    // Flush buffer to RAM in LCD
	EG_LCDFlushBuffer();
	UART_SendStringCongestion("Init EmbeddedGUI Finished.\0");
	while(1){
		EG_LCDFlushBuffer();			
	}
}


