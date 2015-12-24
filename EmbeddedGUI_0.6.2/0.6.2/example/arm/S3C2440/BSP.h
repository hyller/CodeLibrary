//BSP.h

////////////////////////////////////////////////////////////////////////
//  Register Definition

#define ULCON0 (*(volatile unsigned *)0X50000000) 
#define UCON0  (*(volatile unsigned *)0X50000004)
#define UFCON0 (*(volatile unsigned *)0X50000008)
#define UTRSTAT0 (*(volatile unsigned*)0X50000010)
#define UBRDIV0 (*(volatile unsigned *)0X50000028)
#define UTXH0  (*(volatile unsigned char*)0X50000020)
#define URXH0  (*(volatile unsigned char*)0X50000024)

#define ULCON1 (*(volatile unsigned *)0X50004000)
#define UCON1  (*(volatile unsigned *)0X50004004)
#define UFCON1 (*(volatile unsigned *)0X50004008)
#define UTRSTAT1 (*(volatile unsigned*)0X50004010)
#define UBRDIV1 (*(volatile unsigned *)0X50004028)
#define UTXH1  (*(volatile unsigned char*)0X50004020)
#define URXH1  (*(volatile unsigned char*)0X50004024)

#define ULCON2 (*(volatile unsigned *)0X50008000)
#define UCON2  (*(volatile unsigned *)0X50008004)
#define UFCON2 (*(volatile unsigned *)0X50008008)
#define UTRSTAT2 (*(volatile unsigned*)0X50008010)
#define UBRDIV2 (*(volatile unsigned *)0X50008028)
#define UTXH2  (*(volatile unsigned char*)0X50008020)
#define URXH2  (*(volatile unsigned char*)0X50008024)

#ifndef MPLLCON
#define MPLLCON (*(volatile unsigned *)0x4C000004)  //PLL control
#endif 

#define GPCON_BASE (volatile unsigned int*)0x56000000  //port control register base addr
#define GPDATA_BASE (volatile unsigned int*)0x56000004  //port data register base addr

//GPHCON 0x56000070 R/W Configures the pins of port H 0x0
#define GPHCON (*(volatile unsigned *)0x56000070)
#define GPHDATA (*(volatile unsigned *)0x56000074)

//Timer Registers
#define TCFG0  (*(volatile unsigned *)0x51000000)	//Timer 0 configuration
#define TCFG1  (*(volatile unsigned *)0x51000004)	//Timer 1 configuration
#define TCON   (*(volatile unsigned *)0x51000008)	//Timer control
#define TCNTB0 (*(volatile unsigned *)0x5100000c)	//Timer count buffer 0
#define TCMPB0 (*(volatile unsigned *)0x51000010)	//Timer compare buffer 0
#define TCNTO0 (*(volatile unsigned *)0x51000014)	//Timer count observation 0
#define TCNTB1 (*(volatile unsigned *)0x51000018)	//Timer count buffer 1
#define TCMPB1 (*(volatile unsigned *)0x5100001c)	//Timer compare buffer 1
#define TCNTO1 (*(volatile unsigned *)0x51000020)	//Timer count observation 1
#define TCNTB2 (*(volatile unsigned *)0x51000024)	//Timer count buffer 2
#define TCMPB2 (*(volatile unsigned *)0x51000028)	//Timer compare buffer 2
#define TCNTO2 (*(volatile unsigned *)0x5100002c)	//Timer count observation 2
#define TCNTB3 (*(volatile unsigned *)0x51000030)	//Timer count buffer 3
#define TCMPB3 (*(volatile unsigned *)0x51000034)	//Timer compare buffer 3
#define TCNTO3 (*(volatile unsigned *)0x51000038)	//Timer count observation 3
#define TCNTB4 (*(volatile unsigned *)0x5100003c)	//Timer count buffer 4
#define TCNTO4 (*(volatile unsigned *)0x51000040)	//Timer count observation 4

#define SRCPND     (*(volatile unsigned *)0x4a000000)	//Interrupt request status
#define INTMOD     (*(volatile unsigned *)0x4a000004)	//Interrupt mode control
#define INTMSK     (*(volatile unsigned *)0x4a000008)	//Interrupt mask control
#define PRIORITY   (*(volatile unsigned *)0x4a00000c)	//IRQ priority control
#define INTPND     (*(volatile unsigned *)0x4a000010)	//Interrupt request status
#define SUBSRCPND  (*(volatile unsigned *)0x4a000018)	//Sub source pending
#define INTSUBMSK  (*(volatile unsigned *)0x4a00001c)	//Interrupt sub mask

// ADC Registers
#define ADCCON    (*(volatile unsigned *)0x58000000)	//ADC control
#define ADCTSC    (*(volatile unsigned *)0x58000004)	//ADC touch screen control
#define ADCDLY    (*(volatile unsigned *)0x58000008)	//ADC start or Interval Delay
#define ADCDAT0   (*(volatile unsigned *)0x5800000c)	//ADC conversion data 0
#define ADCDAT1   (*(volatile unsigned *)0x58000010)	//ADC conversion data 1
#define ADCUPDN   (*(volatile unsigned *)0x58000014)	//Stylus Up/Down interrupt status


#define BIT_TIMER0		(0x1<<10)
#define BIT_TIMER1		(0x1<<11)
#define BIT_TIMER2		(0x1<<12)
#define BIT_TIMER3		(0x1<<13)
#define BIT_TIMER4		(0x1<<14)
#define BIT_ADC			(0x1<<31)
#define BIT_ALLMSK		(0xffffffff)
#define BIT_SUB_TC		(0x1<<9)
#define BIT_SUB_ALLMSK	(0x7fff)			//Changed from 0x7ff to 0x7fff for 2440A 



////////////////////////////////////////////////////////////////////////
//  utility
//   delay(1)  is  0.15ms
void delay(unsigned int n);

//   0 - 9   ->  0x30 - 0x39
//   A - F   ->  0x41 - 0x46
unsigned char convertASCIIHexHigh(unsigned char temp);
unsigned char convertASCIIHexLow(unsigned char temp);

////////////////////////////////////////////////////////////////////////
//  GPIO
//port = 0 - 7    corresponding to Port A to H
//   NOTE:  Port J is excluded
void BSP_GPIO_Init(unsigned int port,unsigned int value);
void BSP_GPIO_SetPinHigh(unsigned int port,unsigned int pin);
void BSP_GPIO_SetPinLow(unsigned int port,unsigned int pin);
unsigned char BSP_GPIO_GetPinState(unsigned int port,unsigned int pin);

////////////////////////////////////////////////////////////////////////
//  PLL
//set PCLK = HCLK = FCLK = 48MHz
void BSP_PLL_Init(void);

////////////////////////////////////////////////////////////////////////
//  UART

//Init the UART 
// Baudrate = 115200
// Parity  = None
// Width = 8
// port = 0-2
void BSP_UART_Init(unsigned int port);
void BSP_UART_Init_HighCLK(unsigned int port);

void BSP_UART_SendByte(unsigned int port,unsigned char byte);
unsigned char BSP_UART_ReceiveByte(unsigned int port);

//send or receive by polling
void BSP_UART_SendCongestionString(unsigned int port,char* pString);
void BSP_UART_SendCongestionBuffer(unsigned int port,unsigned char* pBuffer,unsigned int length);
void BSP_UART_ReceiveCongestionBuffer(unsigned int port,unsigned char* pBuffer,unsigned int length);

//////////////////////////////////////////////////////////////////////////
// Timer 
void BSP_TimerSys_Init(unsigned int CFG0Prescale);
void BSP_Timer_Init(unsigned int timerIndex,unsigned int timerCount,unsigned int timerCompare);
void BSP_Timer_Start(unsigned int timerIndex);
void BSP_Timer_InterruptInit(unsigned int timerIndex);
void BSP_Timer_ClearInterruptFlag(unsigned int timerIndex);

//////////////////////////////////////////////////////////////////////////
// TouchScreen

extern unsigned int BSP_TS_XPosition;
extern unsigned int BSP_TS_YPosition;

void BSP_TouchScreen_Init(void);
void BSP_TouchScreen_InterruptInit(void);
void BSP_TouchScreen_ISR(void);

///////////////////////////////////////////////////////////////////////////
//  ISR
void BSP_ISR_Init(void);


