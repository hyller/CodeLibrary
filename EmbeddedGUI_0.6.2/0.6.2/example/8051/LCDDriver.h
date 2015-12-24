/*
    EmbeddedGUI Library version 0.4.2
    Copyright (C) 2009  eluneyun WangChao

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
extern unsigned char EG_LCD_Buffer[EG_SUB_ROW][EG_COLUMN];

//   LCD Operation API
//   
//   Initialize the LCD   
void EG_LCDInit(void);

//   Send a command to LCD
void EG_LCDWriteCommand(unsigned char cmd);

//   Write a byte to LCD RAM, CS1 and CS2 are used to select the page.
void EG_LCDWriteValue(unsigned char val,unsigned char CS1,unsigned char CS2);

//   Erase the LCD RAM,so the screen is clear
void EG_LCDClearScreen(void);

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

//   LCD Buffer API
//
//   clear the EG_LCD_Buffer. 
void EG_LCDClearBuffer(void);

//   set the pixel, PixelRow and PixelColumn are pixel index.
void EG_LCDSetPixel(unsigned int PixelRow,unsigned int PixelColumn);

//   clear the pixel, PixelRow and PixelColumn are pixel index.
void EG_LCDClearPixel(unsigned int PixelRow,unsigned int PixelColumn);

//   get the pixel, PixelRow and PixelColumn are pixel index.
//   if pixel is 1,it will return non-zero value.
unsigned char EG_LCDGetPixel(unsigned int PixelRow,unsigned int PixelColumn);

//   copy the EG_LCD_Buffer into LCD RAM 
void EG_LCDFlushBuffer(void);

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


#endif  //DOT_MATRIX_LCD

#endif //LCD_DRIVER_H

