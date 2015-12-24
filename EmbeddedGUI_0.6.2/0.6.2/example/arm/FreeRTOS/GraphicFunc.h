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
	GraphicFunc.h
*/

#include "EGUIMacro.h"
#include "EFont.h"
#ifndef EG_NO_BITMAP
#include "EComponent.h"
#endif //EG_NO_BITMAP


#ifdef EG_SINGLE_COLOR 
//  Graphic Functions:
//
//  Parameter:
//     x,y          Note that x correspond to column and y correspond to row
//        ____________________
//       |       x [0,127]
//       | y 
//       | [0,63]
//     
//     color 
//     if DOT_MATRIX_LCD is defined ,color can only be 0 or 1.
//			color ->  0    white
//			color ->  1    black
//

#define EG_Graphic_DrawWhitePoint(x,y) EG_LCDClearPixel(y,x) 
#define EG_Graphic_DrawBlackPoint(x,y) EG_LCDSetPixel(y,x) 
void EG_Graphic_DrawHorizonLine(unsigned int x,unsigned int y,unsigned int length);
void EG_Graphic_DrawVerticalLine(unsigned int x,unsigned int y,unsigned int length);
void EG_Graphic_DrawWhiteHorizonLine(unsigned int x,unsigned int y,unsigned int length);
void EG_Graphic_DrawWhiteVerticalLine(unsigned int x,unsigned int y,unsigned int length);
void EG_Graphic_DrawLine(unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1,unsigned char virtualLine);
void EG_Graphic_DrawWidthLine(unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1,unsigned char lineWidth);
void EG_Graphic_DrawEmptyRectangle(unsigned int x,unsigned int y,unsigned int height,unsigned int width);
void EG_Graphic_DrawFilledRectangle(unsigned int x,unsigned int y,unsigned int height,unsigned int width);
void EG_Graphic_DrawWhiteFilledRectangle(unsigned int x,unsigned int y,unsigned int height,unsigned int width);
void EG_Graphic_DrawEmptyCircle(unsigned int x0,unsigned int y0,unsigned int r);
void EG_Graphic_DrawFilledCircle(unsigned int x0,unsigned int y0,unsigned int r);
void EG_Graphic_DrawWhiteFilledCircle(unsigned int x0,unsigned int y0,unsigned int r);
//angle range 1-4
void EG_Graphic_DrawQuarterArc(unsigned int x0,unsigned int y0,unsigned int r,unsigned char angle);
void EG_Graphic_DrawArc(unsigned int x0,unsigned int y0,unsigned int r,unsigned int startAngle,unsigned int endAngle);
void EG_Graphic_DrawPieSlice(unsigned int x0,unsigned int y0,unsigned int r,unsigned int startAngle,unsigned int endAngle);
void EG_Graphic_DrawEmptyEllipse(unsigned int leftX,unsigned int topY,unsigned int rightX,unsigned int bottomY);
void EG_Graphic_DrawFilledEllipse(unsigned int leftX,unsigned int topY,unsigned int rightX,unsigned int bottomY);
void EG_Graphic_DrawChar(unsigned int x,unsigned int y,char val);
void EG_Graphic_DrawString(unsigned int x,unsigned int y,char* string);
//   size is the length of string without '\0'.
void EG_Graphic_DrawConstString(unsigned int x,unsigned int y,char* string,unsigned char size);
//   draw the char with black background.
void EG_Graphic_DrawNotChar(unsigned int x,unsigned int y,char val);
//   draw the string with black background.
void EG_Graphic_DrawNotString(unsigned int x,unsigned int y,char* string);
//number must be less than 100000.
void EG_Graphic_DrawNumber(unsigned int x,unsigned int y,int number);

#ifndef EG_NO_BITMAP
void EG_Graphic_DrawBitmap(unsigned int x,unsigned int y,EBitmap* pBitmap);
#endif //EG_NO_BITMAP

#ifndef EG_NO_FONT
void EG_Graphic_DrawFontChar(unsigned int x,unsigned int y,char val,const EFont& font);
void EG_Graphic_DrawNotFontChar(unsigned int x,unsigned int y,char val,const EFont& font);
void EG_Graphic_DrawFontString(unsigned int x,unsigned int y,char* string,const EFont& font);
void EG_Graphic_DrawConstFontString(unsigned int x,unsigned int y,char* string,unsigned char size,const EFont& font);
void EG_Graphic_DrawNotFontString(unsigned int x,unsigned int y,char* string,const EFont& font);
#endif //EG_NO_FONT

//	invoke example:
//  EG_Graphic_DrawPoint(0,0,1);
//  EG_Graphic_DrawPoint(49,49,1);
//  EG_Graphic_DrawHorizonLine(2,2,10,1);
//  EG_Graphic_DrawVerticalLine(5,5,5,1);
//  EG_Graphic_DrawEmptyRectangle(50,10,5,5,1);
//  EG_Graphic_DrawFilledRectangle(20,20,5,5,1);
//  EG_Graphic_DrawEmptyCircle(30,30,6,1);
//  EG_Graphic_DrawChar(60,10,'a'); 
//  EG_Graphic_DrawChar(40,40,'g');  
//  EG_Graphic_DrawChar(50,40,'T');  
//  EG_Graphic_DrawChar(60,40,'W');  
//  EG_Graphic_DrawString(70,10,"fdasf\0");
//  EG_Graphic_DrawConstString(90,10,"fa",2);

#else // EG_RGB_COLOR 

#ifdef DOT_MATRIX_LCD
#define EG_Graphic_DrawPoint(pos,color) EG_LCD_Buffer[pos.m_uY][pos.m_uX]=color
#endif  //DOT_MATRIX_LCD

#ifdef WIN32_SIMULATE
#include "BufferDriver.h"
#define EG_Graphic_DrawPoint(pos,color) EG_Sim_Buffer[pos.m_uY][pos.m_uX]=color
#endif //WIN32_SIMULATE

void EG_Graphic_DrawHorizonLine(const EPosition& pos,unsigned int length,const EColor& color);
void EG_Graphic_DrawVerticalLine(const EPosition& pos,unsigned int length,const EColor& color);
void EG_Graphic_DrawLine(const EPosition& pos0,const EPosition& pos1,const EColor& color,bool virtualLine);
void EG_Graphic_DrawWidthLine(const EPosition& pos0,const EPosition& pos1,const EColor& color,unsigned char lineWidth);
void EG_Graphic_DrawEmptyRectangle(const EPosition& pos,const ESize& size,const EColor& color);
void EG_Graphic_DrawFilledRectangle(const EPosition& pos,const ESize& size,const EColor& color);
void EG_Graphic_DrawEmptyCircle(const EPosition& center,unsigned int radius,const EColor& color);
void EG_Graphic_DrawFilledCircle(const EPosition& center,unsigned int radius,const EColor& color);
//angle range 1-4
void EG_Graphic_DrawQuarterArc(const EPosition& center,unsigned int radius,const EColor& color,unsigned char angle);
void EG_Graphic_DrawArc(const EPosition& center,unsigned int radius,const EColor& color,unsigned int startAngle,unsigned int endAngle);
void EG_Graphic_DrawPieSlice(const EPosition& center,unsigned int radius,const EColor& color,unsigned int startAngle,unsigned int endAngle);
void EG_Graphic_DrawEmptyEllipse(unsigned int leftX,unsigned int topY,unsigned int rightX,unsigned int bottomY,const EColor& color);
void EG_Graphic_DrawFilledEllipse(unsigned int leftX,unsigned int topY,unsigned int rightX,unsigned int bottomY,const EColor& color);
void EG_Graphic_DrawChar(const EPosition& pos,char val,const EColor& color);
void EG_Graphic_DrawNotChar(const EPosition& pos,char val,const EColor& color);
void EG_Graphic_DrawString(const EPosition& pos,char* string,const EColor& color);
//   size is the length of string without '\0'.
void EG_Graphic_DrawConstString(const EPosition& pos,char* string,unsigned char size,const EColor& color);
//   draw the string with black background.
void EG_Graphic_DrawNotString(const EPosition& pos,char* string,const EColor& color);
//number must be less than 100000.
void EG_Graphic_DrawNumber(const EPosition& pos,int number,const EColor& color);

#ifndef EG_NO_BITMAP
void EG_Graphic_DrawBitmap(const EPosition& pos,EBitmap* pBitmap);
#endif //EG_NO_BITMAP

#ifndef EG_NO_FONT
void EG_Graphic_DrawFontChar(const EPosition& pos,char val,const EColor& color,const EFont& font);
void EG_Graphic_DrawNotFontChar(const EPosition& pos,char val,const EColor& color,const EFont& font);
void EG_Graphic_DrawFontString(const EPosition& pos,char* string,const EColor& color,const EFont& font);
void EG_Graphic_DrawConstFontString(const EPosition& pos,char* string,unsigned char size,const EColor& color,const EFont& font);
void EG_Graphic_DrawNotFontString(const EPosition& pos,char* string,const EColor& color,const EFont& font);
void EG_Graphic_DrawFontNumber(const EPosition& pos,int number,const EColor& color,const EFont& font);
#endif  //EG_NO_FONT

#endif // EG_RGB_COLOR
