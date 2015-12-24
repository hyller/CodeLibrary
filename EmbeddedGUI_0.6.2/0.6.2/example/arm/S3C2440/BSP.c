#include "BSP.h"

////////////////////////////////////////////////////////////////////////
//  utility
//   delay(1)  is  0.15ms
void delay(unsigned int n){
	unsigned int i,k;
	for(i=0;i<=n;i++)
		for(k=0;k<=0xff;k++);
}

//   0 - 9   ->  0x30 - 0x39
//   A - F   ->  0x41 - 0x46
unsigned char convertASCIIHexHigh(unsigned char temp){
	unsigned char res=temp&0xF0;
	res=res>>4;
	if(res<=9)
		return res+0x30;
	else
		return res+0x37;
}

unsigned char convertASCIIHexLow(unsigned char temp){
	unsigned char res=temp&0x0F;
	if(res<=9)
		return res+0x30;
	else
		return res+0x37;
}

////////////////////////////////////////////////////////////////////////
//  GPIO
void BSP_GPIO_Init(unsigned int port,unsigned int value){
	unsigned int temp=(unsigned int)GPCON_BASE;
	volatile unsigned int* conReg;
	port=port<<4;
	conReg=(volatile unsigned int*)(temp|port);
	*conReg=value;
}

void BSP_GPIO_SetPinHigh(unsigned int port,unsigned int pin){
	unsigned int temp=(unsigned int)GPDATA_BASE;
	volatile unsigned int* dataReg;
	unsigned int mask=0x00000001;
	port=port<<4;
	dataReg=(volatile unsigned int*)(temp|port);
	mask=mask<<pin;
	*dataReg=*dataReg|mask;
}

void BSP_GPIO_SetPinLow(unsigned int port,unsigned int pin){
	unsigned int temp=(unsigned int)GPDATA_BASE;
	volatile unsigned int* dataReg;
	unsigned int mask=0x00000001;
	port=port<<4;
	dataReg=(volatile unsigned int*)(temp|port);
	mask=mask<<pin;
	mask=!mask;
	*dataReg=*dataReg&mask;
}

unsigned char BSP_GPIO_GetPinState(unsigned int port,unsigned int pin){
	unsigned int temp=(unsigned int)GPDATA_BASE;
	volatile unsigned int* dataReg;
	unsigned int mask=0x00000001;
	port=port<<4;
	dataReg=(volatile unsigned int*)(temp|port);
	mask=mask<<pin;
	temp=*dataReg;
	if(mask&temp){
		return 1;
	}else{
		return 0;
	}
}

////////////////////////////////////////////////////////////////////////
//  PLL
//set PCLK = HCLK = FCLK = 48MHz
void BSP_PLL_Init(void){	
	MPLLCON = 0x00038022;  
}


////////////////////////////////////////////////////////////////////////
//  UART
void BSP_UART_Init(unsigned int port){
	if(port==0){
		ULCON0 =0x00000003;    //one start bit , eight data bits
		UCON0  =0X00000005;    //serial clk -> PCLK
		UBRDIV0 =0x00000033;   //baudrate 115200
		UFCON0 =0x00000001;
	}else if(port==1){
		ULCON1 =0x00000003;    
		UCON1  =0X00000005;    
		UBRDIV1 =0x00000033;   
		UFCON1 =0x00000001;	
	}else{
		ULCON2 =0x00000003;    
		UCON2  =0X00000005;    
		UBRDIV2 =0x00000033;   
		UFCON2 =0x00000001;	
	}
}

void BSP_UART_Init_HighCLK(unsigned int port){
	if(port==0){
		ULCON0 =0x00000003;     //one start bit , eight data bits
		UCON0  =0X00000005;    //serial clk -> PCLK
		UBRDIV0 =0x0000001A;   //baudrate 115200
		UFCON0 =0x00000001;
	}else if(port==1){
		ULCON1 =0x00000003;    
		UCON1  =0X00000005;    
		UBRDIV1 =0x0000001A;   
		UFCON1 =0x00000001;	
	}else{
		ULCON2 =0x00000003;    
		UCON2  =0X00000005;    
		UBRDIV2 =0x0000001A;   
		UFCON2 =0x00000001;	
	}
}

void BSP_UART_SendByte(unsigned int port,unsigned char byte){
	if(port==0){
		while(!(UTRSTAT0 & 0X04));
		UTXH0=byte;
	}else if(port==1){
		while(!(UTRSTAT1 & 0X04));
		UTXH1=byte;
	}else{
		while(!(UTRSTAT2 & 0X04));
		UTXH2=byte;
	}
}

unsigned char BSP_UART_ReceiveByte(unsigned int port){
	unsigned char res=0x00;
	if(port==0){
		while(!(UTRSTAT0 & 0X01));
		res=URXH0;
	}else if(port==1){
		while(!(UTRSTAT1 & 0X01));
		res=URXH1;
	}else{
		while(!(UTRSTAT2 & 0X01));
		res=URXH2;
	}
	return res;
}


void BSP_UART_SendCongestionString(unsigned int port,char* pString){
	unsigned int n=0;
	while(pString[n]!='\0'){
		BSP_UART_SendByte(port,(unsigned char)(pString[n]));	
		n++;
	}
}

void BSP_UART_SendCongestionBuffer(unsigned int port,unsigned char* pBuffer,unsigned int length){
	unsigned int n;
	for(n=0;n<length;n++){
		BSP_UART_SendByte(port,pBuffer[n]);
	}
}

void BSP_UART_ReceiveCongestionBuffer(unsigned int port,unsigned char* pBuffer,unsigned int length){
	unsigned int n;
	for(n=0;n<length;n++){
		pBuffer[n]=BSP_UART_ReceiveByte(port);
	}
}

//////////////////////////////////////////////////////////////////////////
// Timer 
void BSP_TimerSys_Init(unsigned int CFG0Prescale){
	TCFG0|=CFG0Prescale;
	//TCFG1=0x00000000;
	//   auto reload  = 1  manual update = 1 output interver = 0 start = 1 
	//             01111011 10111011 00001011
	TCON=0x007BBB0B;	       
	TCON=0x00488808;                
}

void BSP_Timer_Init(unsigned int timerIndex,unsigned int timerCount,unsigned int timerCompare){
	volatile unsigned int* baseReg;
	unsigned int temp=0x5100000C;
	temp=temp+12*timerIndex;
	baseReg=(volatile unsigned int*)temp;
	*baseReg=timerCount;
	baseReg=(volatile unsigned int*)(temp+4);
	*baseReg=timerCompare;
}

void BSP_Timer_Start(unsigned int timerIndex){
	if(timerIndex==0){
		TCON|=0x00000001;			
	}else if(timerIndex==1){
		TCON|=0x00000100;		
	}else if(timerIndex==2){
		TCON|=0x00001000;		
	}else if(timerIndex==3){
		TCON|=0x00000100;		
	}else{
		TCON|=0x00001000;
	}
}

void BSP_Timer_InterruptInit(unsigned int timerIndex){
	if(timerIndex==0){
		INTMSK&=~BIT_TIMER0;	
	}else if(timerIndex==1){
		INTMSK&=~BIT_TIMER1;	
	}else if(timerIndex==2){
		INTMSK&=~BIT_TIMER2;	
	}else if(timerIndex==3){
		INTMSK&=~BIT_TIMER3;	
	}else{
		INTMSK&=~BIT_TIMER4;	
	}	
}

void BSP_Timer_ClearInterruptFlag(unsigned int timerIndex){
	if(timerIndex==0){
		SRCPND=BIT_TIMER0;
		INTPND=BIT_TIMER0;
	}else if(timerIndex==1){
		SRCPND=BIT_TIMER1;
		INTPND=BIT_TIMER1;
	}else if(timerIndex==2){
		SRCPND=BIT_TIMER2;
		INTPND=BIT_TIMER2;
	}else if(timerIndex==3){
		SRCPND=BIT_TIMER3;
		INTPND=BIT_TIMER3;
	}else{
		SRCPND=BIT_TIMER4;
		INTPND=BIT_TIMER4;
	}
}

//////////////////////////////////////////////////////////////////////////
// TouchScreen
unsigned int BSP_TS_XPosition;
unsigned int BSP_TS_YPosition;

void BSP_TouchScreen_Init(void){
    ADCDLY=50000;                  //Normal conversion mode delay about (1/3.6864M)*50000=13.56ms
    ADCCON=(1<<14)+(9<<6);   //ADCPRS En, ADCPRS Value
    ADCTSC=0xd3;                  //Wfait,XP_PU,XP_Dis,XM_Dis,YP_Dis,YM_En
}

void BSP_TouchScreen_InterruptInit(void){
	INTMSK&=~BIT_ADC;       //ADC Touch Screen Mask bit clear
	INTSUBMSK&=~(BIT_SUB_TC);
}

void BSP_TouchScreen_ISR(void){
	unsigned int saveAdcdly;

    if(ADCDAT0&0x8000){
		ADCTSC&=0xff;	// Set stylus down interrupt bit
    }

	ADCTSC=(1<<3)|(1<<2);         //Pull-up disable, Seq. X,Y postion measure.
	saveAdcdly=ADCDLY;
	ADCDLY=40000;                 //Normal conversion mode delay about (1/50M)*40000=0.8ms
	ADCCON|=0x1;                   //start ADC

	while(ADCCON & 0x1);		//check if Enable_start is low
	while(!(ADCCON & 0x8000));        //check if EC(End of Conversion) flag is high, This line is necessary~!!
	while(!(SRCPND & (BIT_ADC)));     //check if ADC is finished with interrupt bit

    BSP_TS_XPosition=(ADCDAT0&0x3ff);
    BSP_TS_YPosition=(ADCDAT1&0x3ff);

	 //YH 0627, To check Stylus Up Interrupt.
	SUBSRCPND|=BIT_SUB_TC;
	SRCPND = BIT_ADC;
	INTPND = BIT_ADC;
	INTSUBMSK&=~(BIT_SUB_TC);
	INTMSK&=~(BIT_ADC);
			 
	ADCTSC =0xd3;    //Waiting for interrupt
	ADCTSC=ADCTSC|(1<<8); // Detect stylus up interrupt signal.

	while(1){		//to check Pen-up state
		if(SUBSRCPND & (BIT_SUB_TC)){	//check if ADC is finished with interrupt bit
			break;	//if Stylus is up(1) state
		}
	}	

	BSP_UART_SendCongestionString(0,"Touchscreen data:\n\0");
	BSP_UART_SendCongestionBuffer(0,(unsigned char*)(&BSP_TS_XPosition),4);
	BSP_UART_SendCongestionBuffer(0,(unsigned char*)(&BSP_TS_YPosition),4);
	
	ADCDLY=saveAdcdly; 
	ADCTSC=ADCTSC&~(1<<8); // Detect stylus Down interrupt signal.
    SUBSRCPND|=BIT_SUB_TC;
    INTSUBMSK&=~(BIT_SUB_TC);	// Unmask sub interrupt (TC)     
	SRCPND = BIT_ADC;
	INTPND = BIT_ADC;
}

///////////////////////////////////////////////////////////////////////////
//  ISR
void BSP_ISR_Init(void){
	INTMOD=0x0;	  // All=IRQ mode
	INTMSK=BIT_ALLMSK;	  // All interrupt is masked.
}

















