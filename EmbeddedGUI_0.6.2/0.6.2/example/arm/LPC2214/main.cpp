#include "BSP.h"
#include "LCDDriver.h"
#include "EControl.h"
#include "EFrame.h"

extern "C"{
void PERIPHERIAL_INIT(void);	
}

__irq void timerISR();
void nextButtonCBF(EControl* control,EEvent* curevent);

	ESimpleDesktop desk;
	EWindow introWin("EGUI Guide\0",EPosition(0,0),ESize(127,63),true);
	ELabel labelCtrl(EPosition(4,25),"Example of EGUI",16*8);
	EButton nextButn(nextButtonCBF,EPosition(35,40),"Next>>",6*8);
	ECheckButton chkButn1(false,EPosition(10,14),"choice1",7*8);
	ECheckButton chkButn2(false,EPosition(10,24),"choice2",7*8);
	EEdit editCtrl(false,EPosition(10,20),60);
	unsigned char click;

extern "C"{	
int main(){
	unsigned int n=0;
	click=0;
	EEvent e;
    //Initialise the peripherial
	PERIPHERIAL_INIT();

	//set VIC interrupt slot
	unsigned int* vicaddr=(unsigned int*)0xFFFFF100;
	*vicaddr=(unsigned int)timerISR;
	
	BSP_FeedDog();
	BSP_UART_SendStringCongestion("Init Finished.\0");

	//init the LCD 
	EG_LCDInit();
    // Clear the buffer, set the buffer to 0
    EG_LCDClearBuffer();
	BSP_FeedDog();
    // Global Redraw upon the buffer
	introWin.AddControl(&labelCtrl);
	introWin.AddControl(&nextButn);
	desk.AddWindow(&introWin);
	//desk.SetCursorShape(EG_DefaultCursorShape);
	desk.GlobalRedraw();
	BSP_FeedDog();

	BSP_UART_SendStringCongestion("Init EmbeddedGUI Finished.\0");
	while(1){
		BSP_FeedDog();
		//receive the event from UART.
		BSP_UART_ReceiveStringCongestion((char*)(&e),sizeof(e));
		//dispatch this event
		desk.DispatchEvent(&e);
	}
	return 0;
}
}

__irq void timerISR(){
 	unsigned int* upoint=(unsigned int*)0xE0008000; 
	*upoint=0x01;		//	 reset the timer1 IR 
	upoint=(unsigned int*)0xFFFFF030; 
	*upoint=0x00;		//   Vector Address register should be written near the end of an ISR
						//	  ,to update the priority hardware.
	desk.ScheduleRedraw();
}

void nextButtonCBF(EControl* control,EEvent* curevent){
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
		if(click==0){
			introWin.RemoveControl(0);  //remove lable
			introWin.AddControl(&chkButn1);
			introWin.AddControl(&chkButn2);
			click=1;
		}else if(click==1){
			if(chkButn1.GetCheckState()){
				BSP_UART_SendStringCongestion("check button 1 is true.\0");
			}
			if(chkButn2.GetCheckState()){
				BSP_UART_SendStringCongestion("check button 2 is true.\0");
			}
			introWin.RemoveControl(1);  //remove check1
			introWin.RemoveControl(2);  //remove check2
			introWin.AddControl(&editCtrl);	
			click=2;
		}else if(click==2){
			editCtrl.AddCharToString('\0');		
			introWin.RemoveControl(1);  //remove edit
			BSP_UART_SendStringCongestion(editCtrl.m_saString);
			click=3;
		}
		//introWin.ForceRedrawAllControls();
	}
}

