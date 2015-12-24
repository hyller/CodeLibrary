
//EmbeddedGUI includes
#include "LCDDriver.h"
#include "EControl.h"
#include "EFrame.h"

//redraw is the highest priority
#define mainREDRAW_TASK_PRIORITY		( tskIDLE_PRIORITY + 3 )
//UART task priority
#define mainCOM_TASK_PRIORITY		( tskIDLE_PRIORITY + 2 )

/* The Rx task will block on the Rx queue for a long period. */
#define comRX_BLOCK_TIME			( ( portTickType ) 0xffff )

void nextButtonCBF(EControl* control,EEvent* curevent);

	ESimpleDesktop desk;
	EWindow introWin("EGUI Guide\0",EPosition(0,0),ESize(127,63),true);
	ELabel labelCtrl(EPosition(4,25),"Example of EGUI",16*8);
	EButton nextButn(nextButtonCBF,EPosition(35,40),"Next>>",6*8);
	ECheckButton chkButn1(false,EPosition(10,14),"choice1",7*8);
	ECheckButton chkButn2(false,EPosition(10,24),"choice2",7*8);
	EEdit editCtrl(false,EPosition(10,20),60);
	EEvent UARTevent;
	unsigned char click;
	unsigned char stage;

extern "C"{	 

#include "FreeRTOS.h"
#include "Task.h"
#include "Serial.h"

extern xComPortHandle hComHandle;

void vGUIRedraw( void * pvParameters );
void vUARTCursorInfo( void * pvParameters );

void vGUIInit(void){

	stage=0;
	//init the LCD 
	EG_LCDInit();
    // Clear the buffer, set the buffer to 0
    EG_LCDClearBuffer();
    // Global Redraw upon the buffer
	introWin.AddControl(&labelCtrl);
	introWin.AddControl(&nextButn);
	desk.AddWindow(&introWin);
	//desk.SetCursorShape(EG_DefaultCursorShape);
	desk.GlobalRedraw();
	//create the redraw task
	xTaskCreate( vGUIRedraw, "Redraw", configMINIMAL_STACK_SIZE, NULL, mainREDRAW_TASK_PRIORITY, NULL );
	//create the event task
	xTaskCreate( vUARTCursorInfo, "Event", configMINIMAL_STACK_SIZE, NULL, mainCOM_TASK_PRIORITY, NULL );

}

void vGUIRedraw( void * pvParameters ){

	/* Parameters are not used. */
	( void ) pvParameters;

	portTickType xLastWakeTime;
	const portTickType xFrequency = 10;
	
	// Initialise the xLastWakeTime variable with the current time.
	xLastWakeTime = xTaskGetTickCount ();
	for( ;; ){
		// Wait for the next cycle.
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
		
		//redraw all the desktop here.
		desk.ScheduleRedraw();
	}
}


void vUARTCursorInfo( void * pvParameters ){
	signed char temp;
	for(;;){
		if(xSerialGetChar(hComHandle,&temp,comRX_BLOCK_TIME)){
			if(temp=='\0'){
				//synchronous token
				stage=0;			
			}else{
				if(stage==0){
					stage=1;
					UARTevent.m_pPosition.m_uX=temp;				
				}else if(stage==1){
					stage=2;
					UARTevent.m_pPosition.m_uY=temp;
				}else if(stage==2){
					stage=3;
					UARTevent.m_uSource=temp;
				}else if(stage==3){
					stage=0;
					UARTevent.m_uMessage=temp;
				}else{
					stage=0;
				}
			}		
		}	
	}	
}

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
				vSerialPutString(hComHandle,"check button 1 is true.",23);
			}
			if(chkButn2.GetCheckState()){
				vSerialPutString(hComHandle,"check button 2 is true.",23);
			}
			introWin.RemoveControl(1);  //remove check1
			introWin.RemoveControl(2);  //remove check2
			introWin.AddControl(&editCtrl);	
			click=2;
		}else if(click==2){
			editCtrl.AddCharToString('\0');		
			introWin.RemoveControl(1);  //remove edit
			vSerialPutString(hComHandle,"edit is removed.",16);
			click=3;
		}
	}
}
