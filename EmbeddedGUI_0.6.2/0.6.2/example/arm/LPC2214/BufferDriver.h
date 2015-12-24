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
	BufferDriver.h
*/

#include "EGUIMacro.h"

#ifdef WIN32_SIMULATE

#ifdef EG_SINGLE_COLOR

extern unsigned char EG_Sim_Buffer[EG_SUB_ROW][EG_COLUMN];

//   set the pixel, PixelRow and PixelColumn are pixel index.
void EG_LCDSetPixel(unsigned int PixelRow,unsigned int PixelColumn);

//   clear the pixel, PixelRow and PixelColumn are pixel index.
void EG_LCDClearPixel(unsigned int PixelRow,unsigned int PixelColumn);

//   get the pixel, PixelRow and PixelColumn are pixel index.
//   if pixel is 1,it will return non-zero value.
unsigned char EG_LCDGetPixel(unsigned int PixelRow,unsigned int PixelColumn);

//   set a horizonal byte, PixelRow and PixelColumn are pixel index.
//   example: 
//    _|_Pixel Position
//     |XXXXXXXX   <-  val
//      01011111     if val=0x5F
void EG_LCDSetByte(unsigned int PixelRow,unsigned int PixelColumn,unsigned char val);

//   clear the EG_LCD_Buffer. 
void EG_LCDClearBuffer();

#else  //EG_RGB_COLOR

#include "EComponent.h"

extern EColor EG_Sim_Buffer[EG_ROW][EG_COLUMN];

//   clear the EG_LCD_Buffer. 
void EG_LCDClearBuffer();

#endif //EG_RGB_COLOR

#endif //WIN32_SIMULATE
