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
	LCDDriver.h
*/

#include "EGUIMacro.h"
#include "IO.h"

#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

#ifdef DOT_MATRIX_LCD
//    Dot Matrix LCD Driver API
//
//    Pixel Addressing :
//    eg:  
//           define COLUMN=128 ROW=64
//
//                    128*64(column*row) pixels
//                   _____________________________ 
//                  |          pixel=column(128)
//   pixel=subrow*8 |             [0,127]
//       (64)       |       PixelColumn = [0,127]
//       [0,7]      |
//  PixelRow = [0,63]
//                  |     [0,63]          [64,127]
//                      Left Page(CS1)   Right Page(CS2)
//                   

#ifdef EG_SINGLE_COLOR
extern unsigned char EG_LCD_Buffer[EG_SUB_ROW][EG_COLUMN];
#else  //EG_RGB_COLOR
#ifndef EG_NO_EBUFFER
	#include "EComponent.h"
extern EColor EG_LCD_Buffer[EG_ROW][EG_COLUMN];
#endif //EG_NO_EBUFFER
#endif

//   LCD Operation API

//   Initialize the LCD   
void EG_LCDInit(void);

//   Erase the LCD RAM,so the screen is clear
void EG_LCDClearScreen(void);

//   copy the EG_LCD_Buffer into LCD RAM 
void EG_LCDFlushBuffer(void);

#ifdef EG_NO_EBUFFER
//show a pixel, write the EColor directly to LCD RAM 
void EG_LCDFlushPoint(EColor& val,unsigned int PixelColumn,unsigned int PixelRow);
#endif  //EG_NO_EBUFFER

#ifdef EG_KS010X_LCD_DRIVER
//   Send a command to LCD
void EG_LCDWriteCommand(unsigned char cmd);

//   Write a byte to LCD RAM, CS1 and CS2 are used to select the page.
void EG_LCDWriteValue(unsigned char val,unsigned char CS1,unsigned char CS2);

//   Write a byte to LCD RAM, row and column are position index.
void EG_LCDShowByte(unsigned char val,unsigned int row,unsigned int column);

//   Write a buffer to LCD RAM, row and column are start position index.
void EG_LCDShowBuffer(unsigned char* pBuf,unsigned int size,unsigned int row,unsigned int column);

#ifndef W78E5XX
//Keil C51 doesnot support inline function.....  :(

//   Send 0x3E command to LCD, close the LCD.
INLINE void EG_LCDClose(void){
  EG_LCDWriteCommand(0x3E);  //Display OFF	
}

//   Send 0x3F command to LCD, open the LCD.
INLINE void EG_LCDOpen(void){
  EG_LCDWriteCommand(0x3F);  //Display ON	
}
#endif //W78E5XX
#endif //EG_KS010X_LCD_DRIVER

#ifdef EG_T6963C_LCD_DRIVER

/* T6963C command definition*/
#define  EG_LCD_CUR_POS		0x21						/*set the cursor position*/
#define  EG_LCD_CGR_POS		0x22						/*CGRAM offset address position*/
#define  EG_LCD_ADR_POS		0x24						/*read and write pointer address*/

#define  EG_LCD_TXT_STP		0x40						/*address of text area*/
#define  EG_LCD_TXT_WID		0x41						/*width of text area*/
#define  EG_LCD_GRH_STP		0x42						/*address of graphic area*/
#define  EG_LCD_GRH_WID		0x43						/*width of graphic area*/

#define  EG_LCD_MOD_OR			0x80						/*display method : OR*/
#define  EG_LCD_MOD_XOR		0x81						/*display method : XOR*/
#define  EG_LCD_MOD_AND		0x82						/*display method : AND*/
#define  EG_LCD_MOD_TCH		0x83						/* display method : TEXT*/

#define  EG_LCD_AUT_WR			0xB0						/*auto write mode*/
#define  EG_LCD_AUT_RD			0xB1						/*auto read mode*/
#define  EG_LCD_AUT_OVR		0xB2						/*auto mode over*/

#define  EG_LCD_INC_WR			0xC0						/*write data , address increase*/
#define  EG_LCD_INC_RD			0xC1						/*read data , address increase*/
#define  EG_LCD_DEC_WR			0xC2						/*write data , address decrease*/
#define  EG_LCD_DEC_RD			0xC3						/*read data , address decrease*/
#define  EG_LCD_NOC_WR			0xC4						/*write data , address unchanged*/
#define  EG_LCD_NOC_RD			0xC5						/*read data , address unchanged*/

#define  EG_LCD_DIS_SW			0x90						/*display mode*/

//check the LCD module state
void EG_LCDBusyStateCheck(void);

//write a command to LCD
void EG_LCDWriteCommand(unsigned char cmd);

//write data to LCD
void EG_LCDWriteData(unsigned char data);

//read data from LCD
unsigned char EG_LCDReadData(void);

#define EG_LCDWriteCommand2(C,D) EG_LCDWriteData(D);EG_LCDWriteCommand(C)
#define EG_LCDWriteCommand3(C,D1,D2) EG_LCDWriteData(D1);EG_LCDWriteData(D2);EG_LCDWriteCommand(C)

//   Write a byte to LCD RAM, row and column are position index.
void EG_LCDShowByte(unsigned char val,unsigned int row,unsigned int column);

#endif  //EG_T6963C_LCD_DRIVER

#ifdef EG_S6B33C_LCD_DRIVER
/*
Note :  The LCD driver of S6B33C is written by John Leung, TechToys Co. Hong Kong and 
            modified by Wang Chao. Please refer to http://www.TechToys.com.hk for more information.
            Since I don't have the hardware of LCD module using S6B33C as control IC, this
			part of software is not fully tested by myself. Although, it has been tested by John Leung,
			based on the hardware platform provided by TechToys Co. Hong Kong.
*/
/* S6B33C command definition*/
// Please refer to S6B33C datasheet Table15 Instruction Table for more details.
#define EG_LCD_OSCILLATION_MODE_SET			0x02
#define EG_LCD_DRIVER_OUTPUT_MODE_SET			0x10
#define EG_LCD_DC_DC_SET						0x20
#define EG_LCD_CURRENT_BIAS_SET				0x22
#define EG_LCD_PCK_GENER_MODE_SET				0x24	//DC-DC Clock division set
#define EG_LCD_DCDC_AMP_ON_OFF_SET				0x26
#define EG_LCD_TEMP_COMPENSATION_SET			0x28
#define EG_LCD_CONTRAST_CONTROL1				0x2A
#define EG_LCD_CONTRAST_CONTROL2				0x2B
#define EG_LCD_STANDBY_MODE_OFF				0x2C
#define EG_LCD_STANDBY_MODE_ON					0x2D
#define EG_LCD_DDRAM_BURST_MODE_OFF			0x2E
#define EG_LCD_DDRAM_BURST_MODE_ON				0x2F
#define EG_LCD_ADDRESSING_MODE_SET				0x30
#define EG_LCD_ROW_VECTOR_MODE_SET				0x32	
#define EG_LCD_N_LINE_INVERSION_SET			0x34
#define EG_LCD_FRAME_FREQUENCY_CONTROL_SET		0x36
#define EG_LCD_ENTRY_MODE_SET					0x40
#define EG_LCD_X_ADDRESS_AREA_SET				0x42
#define EG_LCD_Y_ADDRESS_AREA_SET				0x43
#define EG_LCD_RAM_SKIP_AREA_SET				0x45
#define EG_LCD_DISPLAY_OFF						0x50
#define EG_LCD_DISPLAY_ON						0x51
#define EG_LCD_SPEC_DISPLAY_PATTERN_SET		0x53
#define EG_LCD_PARTIAL_DISPLAY_MODE_SET		0x55
#define EG_LCD_PARTIAL_DISPLAY_START_LINE_SET	0x56
#define EG_LCD_PARTIAL_DISPLAY_END_LINE_SET	0x57
#define EG_LCD_AREA_SCROLL_MODE_SET			0x59
#define EG_LCD_SCROLL_START_LINE_SET			0x5A
#define EG_LCD_SET_DISPLAY_DATA_LENGTH			0xFC

//delay function 
//delay time >= n * 1ms
void EG_LCDDelay(unsigned int n);

//reset the LCD Module
void EG_LCDReset(void);

//Switch the backlight
void EG_LCDTurnBackLight(unsigned char on);

//write a command to LCD
void EG_LCDWriteCommand(unsigned char cmd);

//write data to LCD
void EG_LCDWriteData(unsigned char data);

//The relation between V1 voltage and Contrast(1) set value in 3-bit step.
//	Refer to Samsung data sheet (S6B33BC) page 36 for details
void EG_LCDSetContrast(unsigned char contrast);

//show a pixel, write the EColor to LCD RAM 
void EG_LCDShowPixel(EColor& val,unsigned int x,unsigned int y);

#ifdef EG_NO_EBUFFER
#define EG_LCDFlushPoint EG_LCDShowPixel
#endif //EG_NO_BUFFER

#define EG_LCDOpen() EG_LCDWriteCommand(EG_LCD_DISPLAY_ON)
#define EG_LCDClose() EG_LCDWriteCommand(EG_LCD_DISPLAY_OFF)

#endif //EG_S6B33C_LCD_DRIVER

#ifdef EG_RA8803_LCD_DRIVER

//delay function 
//delay time >= n * 1ms
void EG_LCDDelay(unsigned int n);

//reset the LCD Module
void EG_LCDReset(void);

//write a command to LCD
void EG_LCDWriteCommand(unsigned char cmdReg,unsigned char cmdData);

//write data to LCD
void EG_LCDWriteData(unsigned char data);

//read data from LCD
unsigned char EG_LCDReadData(unsigned char cmdReg);

//check the busy state of LCD.
void EG_LCDCheckBusy(void);

//   Write a byte to LCD RAM, row and column are position index.
void EG_LCDShowByte(unsigned char val,unsigned int row,unsigned int column);

#endif  //EG_RA8803_LCD_DRIVER

#ifdef EG_S1D13305_LCD_DRIVER

//LCD Driver IC Command Set
#define EG_LCD_SYSTEMSET 0x40
#define EG_LCD_SLEEPIN   0x53
#define EG_LCD_DISPLAY   0x59
#define EG_LCD_SCROLL    0x44
#define EG_LCD_CGROMADR  0x5C
#define EG_LCD_CSRFORM   0x5D
#define EG_LCD_CSRDIR    0x4C
#define EG_LCD_SDOTSCR   0x5A
#define EG_LCD_OVERLAY   0x5B
#define EG_LCD_CSRW      0x46
#define EG_LCD_CSRR      0x47
#define EG_LCD_MWRITE    0x42
#define EG_LCD_MREAD     0x43

//delay function 
//delay time >= n * 1ms
void EG_LCDDelay(unsigned int n);

//write a command to LCD
void EG_LCDWriteCommand(unsigned char cmd);

//write data to LCD
void EG_LCDWriteData(unsigned char data);

#endif  //EG_S1D13305_LCD_DRIVER

#ifdef EG_HX8238_LCD_DRIVER
/*
	Note that I initialize the LCD Controller in S3C2440 ARM920T to generate
	TFT signals such as VSYNC and HSYNC. I leave all the SPI interface pins of 
	HX8238A open(Please refer to serial interface block in HX8238 data sheet ). 
	So, any TFT CCIR601/656 input mode LCD module which connected to S3C2440 
	can use this LCD driver.
	For more details,please refer to EmbeddedGUI Library User Manual Charpter Five.
*/

	//  These functions below will be invoked by EG_LCDInit(). 
	//  Please do not invoke them again.
	void EG_LCDChangePLL(void);
	void EG_LCDEnableVideoOutput(unsigned char on);
	void EG_LCDPowerEnable(int invpwren,int pwren);
	void EG_LCDSetBacklight(unsigned int highRadio);
#endif //EG_HX8238_LCD_DRIVER

//   LCD Buffer API
//
//   clear the EG_LCD_Buffer. 
void EG_LCDClearBuffer(void);

#ifdef EG_SINGLE_COLOR
//   set the pixel, PixelRow and PixelColumn are pixel index.
void EG_LCDSetPixel(unsigned int PixelRow,unsigned int PixelColumn);

//   clear the pixel, PixelRow and PixelColumn are pixel index.
void EG_LCDClearPixel(unsigned int PixelRow,unsigned int PixelColumn);

//   get the pixel, PixelRow and PixelColumn are pixel index.
//   if pixel is 1,it will return non-zero value.
unsigned char EG_LCDGetPixel(unsigned int PixelRow,unsigned int PixelColumn);

//   get the horizonal byte, PixelRow and PixelColumn are pixel index.
//   eg:   __|__  Pixel Position
//           |XXXXXXXX
//               return value
unsigned char EG_LCDGetHorizonalByte(unsigned int PixelRow,unsigned int PixelColumn);

//   set a horizonal byte, PixelRow and PixelColumn are pixel index.
//   example: 
//    _|_Pixel Position
//     |XXXXXXXX   <-  val
//      01011111     if val=0x5F
void EG_LCDSetByte(unsigned int PixelRow,unsigned int PixelColumn,unsigned char val);

//   set a vertical byte, PixelRow and PixelColumn are pixel index.
//   eg:
//   _|_ Pixel Position
//    |X                  1
//     X                  1
//     X  <-  val         1
//     X                  1
//     X                  1
//     X                  0
//     X                  1
//     X                  0    if val=0x5F 
void EG_LCDSetVerticalByte(unsigned int PixelRow,unsigned int PixelColumn,unsigned char val);

//   set a vertical byte bit or with the original byte, PixelRow and PixelColumn are pixel index. 
void EG_LCDSetORVerticalByte(unsigned int PixelRow,unsigned int PixelColumn,unsigned char val);

//   set a vertical byte bit and with the original byte, PixelRow and PixelColumn are pixel index. 
void EG_LCDSetANDVerticalByte(unsigned int PixelRow,unsigned int PixelColumn,unsigned char val);
#endif //EG_SINGLE_COLOR

#endif  //DOT_MATRIX_LCD

#endif //LCD_DRIVER_H

