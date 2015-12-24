#include "LCDDriver.h"
#include "EControl.h"
#include "EFrame.h"
#include "SerialCursor.h"

	unsigned int prog;
	EProgress* pglbProgress;
	EDesktop* pDesktop;
	unsigned int timerScale;
	
extern "C"{	
#include "BSP.h"

void HaltUndef(void);
void HaltSwi(void);
void HaltPabort(void);
void HaltDabort(void);
void __irq IRQ_ISR(void);
void FIQ_ISR(void);

void desktopRedraw(void);

void desktopIconCallback(EControl* control,EEvent* event);
void progressBtnCallback(EControl* control,EEvent* event);
void menu1Callback(EControl* control,EEvent* event);
void menu2Callback(EControl* control,EEvent* event);
void menu3Callback(EControl* control,EEvent* event);
void popmenu1Callback(EControl* control,EEvent* event);
void popmenu2Callback(EControl* control,EEvent* event);
void popmenu3Callback(EControl* control,EEvent* event);

void Main(){
	//I don't know why,but the compiler of ADS1.2 never invoke the 
	// constructor of global struct and class.....
 	// So, I have to move these global variables to stack.
 	// And initialize the EStyle here.....
	EG_DefaultStyle.m_cTextColor=EColor(30,30,30);
	EG_DefaultStyle.m_cFrameColor=EColor(100,150,200);
	EG_DefaultStyle.m_cContentColor=EColor(120,100,200);
	EG_DefaultStyle.m_cBackgroundColor=EColor(230,230,230);
	EG_DefaultStyle.m_cSelectColor=EColor(100,200,100);
	#ifdef EG_RICH_STYLE
	EG_DefaultStyle.m_fFont=EFont(1,1);
	#endif //EG_RICH_STYLE
	prog=0;	
	timerScale=0;
	
	EDesktop desk;
	EWindow introWin("EGUI Guide\0",EPosition(0,0),ESize(127,63),true);
	EWindow secWin("Fun\0",EPosition(50,100),ESize(200,103),true);
	ELabel labelCtrl(EPosition(4,25),"Example of EGUI\0",16*8);
	EButton nextButn(NULL,EPosition(35,40),"Next>>\0",6*8);
	EIconButton icon(desktopIconCallback,EPosition(200,30),ESize(50,50),3,"Help!\0",false);
	EMenu startMenu("Start\0",50,EPosition(0,0),true);
	EMenu::EMenuItem startItem1,startItem2,startItem3;
	EPopupMenu popMenu;
	EPopupMenu::EPopupMenuItem popItem1,popItem2,popItem3;
	EEvent event;
	EButton progressButn(progressBtnCallback,EPosition(200,126),"+\0",12);
	EEdit editCtrl("a\0",false,EPosition(80,155),100);
	EProgress progress(0,EPosition(65,126),ESize(116,17));
	pglbProgress=&progress;
	pDesktop=&desk;
	
	EG_LCDInit();
	// Clear the buffer, set the buffer to 0
	EG_LCDClearBuffer();
	//GUI variable init...
	introWin.AddControl(&labelCtrl);
	introWin.AddControl(&nextButn);
	secWin.AddControl(&progress);
	secWin.AddControl(&progressButn);
	secWin.AddControl(&editCtrl);
	desk.AddWindow(&introWin);
	desk.AddWindow(&secWin);
	desk.AddIconButton(&icon);
	desk.AppendStartMenu(&startMenu);
	desk.AppendPopupMenu(&popMenu);
	startMenu.RemovedAllItems();
	#ifdef EG_RICH_STYLE
	//make sure pIcon =0 when you add the items
	startItem1.m_piIcon=NULL;
	startItem2.m_piIcon=NULL;
	startItem3.m_piIcon=NULL;
	#endif //EG_RICH_STYLE
	startItem1.m_pcLabel[0]='\0';
	startItem2.m_pcLabel[0]='\0';
	startItem3.m_pcLabel[0]='\0';
	startMenu.AddItem(&startItem1);
	startMenu.AddItem(&startItem2);
	startMenu.AddItem(&startItem3);
	startMenu.SetMenuItem(0,"Menu1\0",0,menu1Callback);
	startMenu.SetMenuItem(1,"Menu2\0",0,menu2Callback);
	startMenu.SetMenuItem(2,"Menu3\0",0,menu3Callback);
	#ifdef EG_RICH_STYLE
	//make sure pIcon =0 when you add the items
	popItem1.m_piIcon=NULL;
	popItem2.m_piIcon=NULL;
	popItem3.m_piIcon=NULL;
	#endif //EG_RICH_STYLE
	popItem1.m_pcLabel[0]='\0';
	popItem2.m_pcLabel[0]='\0';
	popItem3.m_pcLabel[0]='\0';
	popMenu.AddItem(&popItem1);
	popMenu.AddItem(&popItem2);
	popMenu.AddItem(&popItem3);
	popMenu.SetPopupMenuItem(0,"PopupMenu1\0",0,popmenu1Callback);
	popMenu.SetPopupMenuItem(1,"PopupMenu2\0",0,popmenu2Callback);
	popMenu.SetPopupMenuItem(2,"PopupMenu3\0",0,popmenu3Callback);
	
   	 // Global Redraw upon the buffer
	desk.GlobalRedraw();
	desk.SetCursorShape((unsigned char*)(&EG_DefaultCursorShape));
	//BSP_UART_SendCongestionString(0,"Desktop Global Redraw!\n\0");

	//labelCtrl.RedrawControl();
	//nextButn.RedrawControl();

	//EG_Graphic_DrawFilledRectangle(EPosition(12,23),ESize(50,80),EColor(0,255,0));
	//EG_Graphic_DrawString(EPosition(100,100),"red\0",EColor(255,0,0));
	//EG_Graphic_DrawString(EPosition(200,160),"blue\0",EColor(0,0,255));
	//EG_Graphic_DrawFilledCircle(EPosition(70,70),30,EColor(255,0,0));
	//EG_Graphic_DrawVerticalLine(EPosition(63,5),200,EColor(255,0,0));
	//EG_Graphic_DrawHorizonLine(EPosition(8,3),200,EColor(0,0,255));
	//EG_Graphic_DrawPoint(EPosition(100,100),EColor(255,0,0));
	//EG_Graphic_DrawPoint(EPosition(100,102),EColor(255,0,0));
	//EG_Graphic_DrawPoint(EPosition(102,100),EColor(255,0,0));
	//EG_Graphic_DrawPoint(EPosition(102,102),EColor(255,0,0));
	//EG_Graphic_DrawPoint(EPosition(104,100),EColor(255,0,0));
	//EG_Graphic_DrawPoint(EPosition(104,104),EColor(255,0,0));
	BSP_GPIO_Init(7,0x0000AAAA);
	BSP_UART_Init_HighCLK(0);
	
	BSP_ISR_Init();
	BSP_Timer_Init(2,0x0000FF00,0x00000000);
    	BSP_TimerSys_Init(0x0000F000);
    	BSP_Timer_InterruptInit(2);
	BSP_Timer_Start(2);
	BSP_TouchScreen_Init();
	BSP_TouchScreen_InterruptInit();
	
	while(1){
		if(EG_ReceiveEvent(&event)==0){
			desk.SetCursorEvent(&event);
		}
	}
}

void desktopIconCallback(EControl* control,EEvent* event){
	if((event->m_uSource==1)&&(event->m_uMessage==1))
		BSP_UART_SendCongestionString(0,"Desktop Icon Clicked!\n\0");
}

void menu1Callback(EControl* control,EEvent* event){
	if((event->m_uSource==1)&&(event->m_uMessage==1))
		BSP_UART_SendCongestionString(0,"Menu1 Clicked!\n\0");
}

void menu2Callback(EControl* control,EEvent* event){
	if((event->m_uSource==1)&&(event->m_uMessage==1))
		BSP_UART_SendCongestionString(0,"Menu2 Clicked!\n\0");
}

void menu3Callback(EControl* control,EEvent* event){
	if((event->m_uSource==1)&&(event->m_uMessage==1))
		BSP_UART_SendCongestionString(0,"Menu3 Clicked!\n\0");
}

void popmenu1Callback(EControl* control,EEvent* event){
	if((event->m_uSource==1)&&(event->m_uMessage==1))
		BSP_UART_SendCongestionString(0,"PopMenu1 Clicked!\n\0");
}

void popmenu2Callback(EControl* control,EEvent* event){
	if((event->m_uSource==1)&&(event->m_uMessage==1))
		BSP_UART_SendCongestionString(0,"PopMenu2 Clicked!\n\0");
}

void popmenu3Callback(EControl* control,EEvent* event){
	if((event->m_uSource==1)&&(event->m_uMessage==1))
		BSP_UART_SendCongestionString(0,"PopMenu3 Clicked!\n\0");
}

void progressBtnCallback(EControl* control,EEvent* event){
	if((event->m_uSource==1)&&(event->m_uMessage==1)){
		prog=prog+10;
		pglbProgress->SetProgress(prog);
	}
}

void desktopRedraw(void){
	pDesktop->ScheduleRedraw();
}

}
