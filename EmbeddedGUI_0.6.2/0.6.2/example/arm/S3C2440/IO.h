/*
    EmbeddedGUI Library version 0.5.4
    Copyright (C) 2009  WangChao

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation ,either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
	IO.h
*/

#include "EGUIMacro.h"

#ifdef EG_KS010X_LCD_DRIVER
#ifdef MSP430
	#include <msp430x44x.h>

//    MCU Pin Mapping :
//        P2.0 -> RS      
//        P2.1 -> RW 
//        P2.2 -> EN 
//        P2.3 -> CS1 
//        P2.6 -> CS2   
//        P2.7 -> RST 
//        P3.0~P3.7 -> DB0~DB7   

// change these pin definition in your application.
 
#define		P2_0_RS			0x01
#define		P2_1_RW			0x02
#define		P2_2_EN			0x04
#define		P2_3_CS1		0x08
#define		P2_4_CS2		0x40
#define		P2_5_RST		0x80

#define		P3_0_DB0		0x01
#define		P3_1_DB1		0x02
#define		P3_2_DB2		0x04
#define		P3_3_DB3		0x08
#define		P3_4_DB4		0x10
#define		P3_5_DB5		0x20
#define		P3_6_DB6		0x40
#define		P3_7_DB7		0x80

#define SET_DATA_DIRECTION(DIR) P3DIR=DIR 
#define SET_DATA_VALUE(VAL) P3OUT=VAL
#define SET_CON_DIRECTION(DIR) P2DIR=DIR 
#define SET_CON_VALUE(VAL) P2OUT=VAL
#define SET_CON_NAND_VALUE(VAL) P2OUT&=~VAL
#define SET_CON_OR_VALUE(VAL) P2OUT|=VAL

#define _NOP_ __no_operation

#endif //MSP430

#ifdef LPC22XX
	#include <LPC22xx.H>

//    MCU Pin Mapping :
//        P1.16 -> RS   
//        P1.17 -> RW 
//        P1.18 -> EN 
//        P1.19 -> CS1 
//        P1.20 -> CS2   
//        P1.21 -> RST 
//        P3.0~P3.7 -> DB0~DB7   

#define		P2_0_RS			0x00010000
#define		P2_1_RW			0x00020000
#define		P2_2_EN			0x00040000
#define		P2_3_CS1		0x00080000
#define		P2_4_CS2		0x00100000
#define		P2_5_RST		0x00200000

#define		P3_0_DB0		0x00000001
#define		P3_1_DB1		0x00000002
#define		P3_2_DB2		0x00000004
#define		P3_3_DB3		0x00000008
#define		P3_4_DB4		0x00000010
#define		P3_5_DB5		0x00000020
#define		P3_6_DB6		0x00000040
#define		P3_7_DB7		0x00000080

#define SET_DATA_DIRECTION(DIR) IODIR3=DIR 
#define SET_DATA_VALUE(VAL) IOPIN3=VAL
#define SET_CON_DIRECTION(DIR) IODIR1=DIR 
#define SET_CON_VALUE(VAL) IOPIN1=VAL
#define SET_CON_NAND_VALUE(VAL) IOPIN1&=~VAL
#define SET_CON_OR_VALUE(VAL) IOPIN1|=VAL

#define _NOP_ __nop

#endif  //LPC22XX

#ifdef W78E5XX
	#include <REG54.H>
	#include "INTRINS.H"

//    MCU Pin Mapping :
//        P2.0 -> RS   
//        P2.1 -> RW 
//        P2.2 -> EN 
//        P2.3 -> CS1 
//        P2.4 -> CS2   
//        P2.5 -> RST 
//        P3.0~P3.7 -> DB0~DB7   

#define		P2_0_RS			0x01
#define		P2_1_RW			0x02
#define		P2_2_EN			0x04
#define		P2_3_CS1		0x08
#define		P2_4_CS2		0x10
#define		P2_5_RST		0x20

#define		P3_0_DB0		0x01
#define		P3_1_DB1		0x02
#define		P3_2_DB2		0x04
#define		P3_3_DB3		0x08
#define		P3_4_DB4		0x10
#define		P3_5_DB5		0x20
#define		P3_6_DB6		0x40
#define		P3_7_DB7		0x80

#define SET_DATA_DIRECTION(DIR) P3=DIR 
#define SET_DATA_VALUE(VAL) P3=VAL
#define SET_CON_DIRECTION(DIR) P2=DIR 
#define SET_CON_VALUE(VAL) P2=VAL
#define SET_CON_NAND_VALUE(VAL) P2&=~VAL
#define SET_CON_OR_VALUE(VAL) P2|=VAL

#define _NOP_  _nop_ 


#endif //W78E5XX
#endif //EG_KS010X_LCD_DRIVER

#ifdef EG_T6963C_LCD_DRIVER

//    MCU Pin Mapping :
//        P3.1 -> WR      
//        P3.2 -> RD 
//        P3.3 -> CE 
//        P3.0 -> CD 
//        VCC -> RST 
//        P1.0~P1.7 -> DB0~DB7   

#ifdef LPC22XX
	#include <LPC22xx.H>

#define		P3_1_WR		0x00000001
#define		P3_2_RD		0x00000002
#define		P3_3_CE		0x00000004
#define		P3_0_CD		0x00000008

#define		P1_0_DB0		0x00000001
#define		P1_1_DB1		0x00000002
#define		P1_2_DB2		0x00000004
#define		P1_3_DB3		0x00000008
#define		P1_4_DB4		0x00000010
#define		P1_5_DB5		0x00000020
#define		P1_6_DB6		0x00000040
#define		P1_7_DB7		0x00000080

#define SET_DATA_DIRECTION(DIR) IODIR1=DIR 
#define SET_DATA_VALUE(VAL) IOPIN1=VAL
#define GET_DATA_VALUE() IOPIN1
#define SET_CON_DIRECTION(DIR) IODIR3=DIR 
#define SET_CON_VALUE(VAL) IOPIN3=VAL
#define SET_CON_NAND_VALUE(VAL) IOPIN3&=~VAL
#define SET_CON_OR_VALUE(VAL) IOPIN3|=VAL

#define _NOP_ __nop

#endif  //LPC22XX

#endif //EG_T6963C_LCD_DRIVER

#ifdef EG_S6B33C_LCD_DRIVER
//   LCD Module Pin                                                             MCU Pin
// pin 4 	A0 		- (H:Data, L:Command)									P3.1
// pin 5		WR 		- active low, L:Write; use with RD pin			P3.2
// pin 6		RD 		- active low, L:Read; use with WR pin			P3.3
// pin 7-14  D7:D0 	- LCD_DATA 											P1
// pin 15	CS 		- chip select, low active									P3.4
// pin 16	BL_EN 	- backlight enable signal	 (high active)			P3.5
// pin 17	RST 	   - reset, low active											P3.6

#ifdef LPC22XX
	#include <LPC22xx.H>

//  LPC2214 use PLL to generate the 60MHz clk.
//  EG_MCU_FREQ = 60M / 3000
#define  EG_MCU_FREQ 20000

#define		P3_1_A0		0x00000002
#define		P3_2_WR		0x00000004
#define		P3_3_RD		0x00000008
#define		P3_4_CS		0x00000010
#define		P3_5_BL_EN		0x00000020
#define		P3_6_RST		0x00000040

#define		P1_0_DB0		0x00000001
#define		P1_1_DB1		0x00000002
#define		P1_2_DB2		0x00000004
#define		P1_3_DB3		0x00000008
#define		P1_4_DB4		0x00000010
#define		P1_5_DB5		0x00000020
#define		P1_6_DB6		0x00000040
#define		P1_7_DB7		0x00000080

#define SET_DATA_DIRECTION(DIR) IODIR1|=DIR 
#define SET_DATA_VALUE(VAL) IOPIN1=VAL
#define SET_CON_DIRECTION(DIR) IODIR3=DIR 
#define SET_CON_VALUE(VAL) IOPIN3=VAL
#define SET_CON_NAND_VALUE(VAL) IOPIN3&=~VAL
#define SET_CON_OR_VALUE(VAL) IOPIN3|=VAL

#define _NOP_ __nop

#endif  //LPC22XX

#endif //EG_S6B33C_LCD_DRIVER

#ifdef EG_RA8803_LCD_DRIVER
//   LCD Module Pin                                                             MCU Pin
// pin 9        BUSY    - busy flag                                             P3.0
// pin 8 	    RS 		- (H:Data, L:Command)									P3.1
// pin 5		WR 		- active low, L:Write; use with RD pin			        P3.2
// pin 6		RD 		- active low, L:Read; use with WR pin			        P3.3
// pin 11-18     D7:D0 	- LCD_DATA 											    P1
// pin 7	    CS 		- chip select, low active								P3.4
// pin 10   	RST     - reset, low active										P3.5

#ifdef LPC22XX
	#include <LPC22xx.H>

//  LPC2214 use PLL to generate the 60MHz clk.
//  EG_MCU_FREQ = 60M / 3000
#define  EG_MCU_FREQ 20000

#define     P3_0_BUSY   0x00000001
#define		P3_1_RS		0x00000002
#define		P3_2_WR		0x00000004
#define		P3_3_RD		0x00000008
#define		P3_4_CS		0x00000010
#define		P3_5_RST	0x00000020

#define		P1_0_DB0		0x00000001
#define		P1_1_DB1		0x00000002
#define		P1_2_DB2		0x00000004
#define		P1_3_DB3		0x00000008
#define		P1_4_DB4		0x00000010
#define		P1_5_DB5		0x00000020
#define		P1_6_DB6		0x00000040
#define		P1_7_DB7		0x00000080

#define SET_DATA_DIRECTION(DIR) IODIR1|=DIR 
#define SET_DATA_VALUE(VAL) IOPIN1=VAL
#define GET_DATA_VALUE() IOPIN1
#define SET_CON_DIRECTION(DIR) IODIR3=DIR 
#define SET_CON_VALUE(VAL) IOPIN3=VAL
#define SET_CON_NAND_VALUE(VAL) IOPIN3&=~VAL
#define SET_CON_OR_VALUE(VAL) IOPIN3|=VAL
#define GET_CON_VALUE() IOPIN3

#define _NOP_ __nop

#endif  //LPC22XX

#endif //EG_RA8803_LCD_DRIVER

#ifdef EG_S1D13305_LCD_DRIVER
//   LCD Module Pin                                                             MCU Pin
// pin 7 	    A0 		- (H:Data, L:Command)									P3.1
// pin 4		WR 		- active low, L:Write; use with RD pin			        P3.2
// pin 5		RD 		- active low, L:Read; use with WR pin			        P3.3
// pin 11-18     D7:D0 	- LCD_DATA 											    P1
// pin 6	    CS 		- chip select, low active								P3.4
// pin 8    	RST     - reset, low active										P3.5

#ifdef LPC22XX
	#include <LPC22xx.H>

//  LPC2214 use PLL to generate the 60MHz clk.
//  EG_MCU_FREQ = 60M / 3000
#define  EG_MCU_FREQ 20000

#define		P3_1_A0		0x00000002
#define		P3_2_WR		0x00000004
#define		P3_3_RD		0x00000008
#define		P3_4_CS		0x00000010
#define		P3_5_RST	0x00000020

#define		P1_0_DB0		0x00000001
#define		P1_1_DB1		0x00000002
#define		P1_2_DB2		0x00000004
#define		P1_3_DB3		0x00000008
#define		P1_4_DB4		0x00000010
#define		P1_5_DB5		0x00000020
#define		P1_6_DB6		0x00000040
#define		P1_7_DB7		0x00000080

#define SET_DATA_DIRECTION(DIR) IODIR1|=DIR 
#define SET_DATA_VALUE(VAL) IOPIN1=VAL
#define SET_CON_DIRECTION(DIR) IODIR3=DIR 
#define SET_CON_VALUE(VAL) IOPIN3=VAL
#define SET_CON_NAND_VALUE(VAL) IOPIN3&=~VAL
#define SET_CON_OR_VALUE(VAL) IOPIN3|=VAL

#define _NOP_ __nop

#endif  //LPC22XX

#endif  //EG_S1D13305_LCD_DRIVER

#ifdef EG_HX8238_LCD_DRIVER
#ifdef S3C2440A
	//GPIO Register of S3C2440A
	#define GPBCON    (*(volatile unsigned *)0x56000010)	//Port B control
	#define GPBDAT    (*(volatile unsigned *)0x56000014)	//Port B data
	#define GPBUP     (*(volatile unsigned *)0x56000018)	//Pull-up control B
	#define GPCUP     (*(volatile unsigned *)0x56000028)	//Pull-up control C
	#define GPCCON    (*(volatile unsigned *)0x56000020)	//Port C control
	#define GPDUP     (*(volatile unsigned *)0x56000038)	//Pull-up control D
	#define GPDCON    (*(volatile unsigned *)0x56000030)	//Port D control
	#define GPDDAT    (*(volatile unsigned *)0x56000034)	//Port D data
	#define GPGCON    (*(volatile unsigned *)0x56000060)	//Port G control
	#define GPGDAT    (*(volatile unsigned *)0x56000064)	//Port G data
	#define GPGUP     (*(volatile unsigned *)0x56000068)	//Pull-up control G

	//LCD Register
	#define LCDCON1    (*(volatile unsigned *)0x4d000000)	//LCD control 1
	#define LCDCON2    (*(volatile unsigned *)0x4d000004)	//LCD control 2
	#define LCDCON3    (*(volatile unsigned *)0x4d000008)	//LCD control 3
	#define LCDCON4    (*(volatile unsigned *)0x4d00000c)	//LCD control 4
	#define LCDCON5    (*(volatile unsigned *)0x4d000010)	//LCD control 5
	#define LCDSADDR1  (*(volatile unsigned *)0x4d000014)	//STN/TFT Frame buffer start address 1
	#define LCDSADDR2  (*(volatile unsigned *)0x4d000018)	//STN/TFT Frame buffer start address 2
	#define LCDSADDR3  (*(volatile unsigned *)0x4d00001c)	//STN/TFT Virtual screen address set
	#define REDLUT     (*(volatile unsigned *)0x4d000020)	//STN Red lookup table
	#define GREENLUT   (*(volatile unsigned *)0x4d000024)	//STN Green lookup table 
	#define BLUELUT    (*(volatile unsigned *)0x4d000028)	//STN Blue lookup table
	#define DITHMODE   (*(volatile unsigned *)0x4d00004c)	//STN Dithering mode
	#define TPAL       (*(volatile unsigned *)0x4d000050)	//TFT Temporary palette
	#define LCDINTPND  (*(volatile unsigned *)0x4d000054)	//LCD Interrupt pending
	#define LCDSRCPND  (*(volatile unsigned *)0x4d000058)	//LCD Interrupt source
	#define LCDINTMSK  (*(volatile unsigned *)0x4d00005c)	//LCD Interrupt mask
	#define TCONSEL     (*(volatile unsigned *)0x4d000060)	//LPC3600 Control
	#define PALETTE     0x4d000400						//Palette start address

	// PWM TIMER
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

	// CLOCK & POWER MANAGEMENT
	#define LOCKTIME   (*(volatile unsigned *)0x4c000000)	//PLL lock time counter
	#define MPLLCON    (*(volatile unsigned *)0x4c000004)	//MPLL Control
	#define UPLLCON    (*(volatile unsigned *)0x4c000008)	//UPLL Control
	#define CLKCON     (*(volatile unsigned *)0x4c00000c)	//Clock generator control
	#define CLKSLOW    (*(volatile unsigned *)0x4c000010)	//Slow clock control
	#define CLKDIVN    (*(volatile unsigned *)0x4c000014)	//Clock divider control
	#define CAMDIVN    (*(volatile unsigned *)0x4c000018)	//USB, CAM Clock divider control

	#define MVAL		(13)
	#define MVAL_USED 	(0)		//0=each frame   1=rate by MVAL
	#define INVVDEN		(1)		//0=normal       1=inverted
	#define BSWP		(0)		//Byte swap control
	#define HWSWP		(1)		//Half word swap control

	#define M5D(n) ((n) & 0x1fffff)	// To get lower 21bits

	//TFT320240
	#define HOZVAL_TFT	(EG_COLUMN-1)
	#define LINEVAL_TFT	(EG_ROW-1)

	//Timing parameter for LCD Module
	#define VBPD		(3)	 //3
	#define VFPD		(5)	 //5
	#define VSPW		(15)	 //15

	#define HBPD		(58)	//58
	#define HFPD		(15)	//15
	#define HSPW		(8)	//8

	#define CLKVAL_TFT	9 // 10
	//FCLK=180MHz,HCLK=90MHz,VCLK=6.5MHz
		
#endif  //S3C2440A
#endif  //EG_HX8238_LCD_DRIVER

