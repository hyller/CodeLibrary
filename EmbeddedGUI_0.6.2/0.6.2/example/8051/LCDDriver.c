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
	LCDDriver.c
*/
#include "LCDDriver.h"

#ifdef DOT_MATRIX_LCD
//    Dot Matrix LCD Driver API
//
//                 _____________________________ 
//                |          pixel=column(128)
//   pixel=row*8  |             [0,127]
//      (64)      |       PixelColumn = [0,127]
//      [0,7]     |
//  PixelRow = [0,63]
//
unsigned char EG_LCD_Buffer[EG_SUB_ROW][EG_COLUMN];

void EG_LCDInit(){
	SET_DATA_DIRECTION(0xFF);
	SET_DATA_VALUE(0x00);
	SET_CON_DIRECTION( P2_0_RS | P2_1_RW | P2_2_EN | P2_3_CS1 | P2_4_CS2 | P2_5_RST );
	SET_CON_VALUE( P2_3_CS1 | P2_4_CS2 | P2_5_RST );
	SET_CON_NAND_VALUE(P2_5_RST);
	_NOP_();
	_NOP_();
	SET_CON_OR_VALUE(P2_2_EN);
	_NOP_();
	_NOP_();
	SET_CON_NAND_VALUE(P2_2_EN);
	_NOP_();
	_NOP_();
	SET_CON_OR_VALUE(P2_5_RST);
	_NOP_();
	_NOP_();	        	
	EG_LCDWriteCommand(0xC0); //display the start line
	EG_LCDWriteCommand(0x3F);  //display ON
	EG_LCDClearScreen();
}

void EG_LCDWriteCommand(unsigned char cmd){
	SET_DATA_DIRECTION(0xFF);
	SET_CON_OR_VALUE(P2_3_CS1+P2_4_CS2);
	SET_CON_NAND_VALUE(P2_0_RS+P2_1_RW);
	SET_DATA_VALUE(cmd);
	SET_CON_OR_VALUE(P2_2_EN);
	SET_CON_NAND_VALUE(P2_2_EN);
}

void EG_LCDWriteValue(unsigned char val,unsigned char CS1,unsigned char CS2){
	SET_DATA_DIRECTION(0xFF);
	if(CS1)
		SET_CON_OR_VALUE(P2_3_CS1);
	else
		SET_CON_NAND_VALUE(P2_3_CS1);
	if(CS2)
		SET_CON_OR_VALUE(P2_4_CS2);
	else
		SET_CON_NAND_VALUE(P2_4_CS2);
	SET_CON_OR_VALUE(P2_0_RS);
	SET_CON_NAND_VALUE(P2_1_RW);
	SET_DATA_VALUE(val);
	SET_CON_OR_VALUE(P2_2_EN);
	SET_CON_NAND_VALUE(P2_2_EN);
}

void EG_LCDClearScreen(){
	unsigned int i,j;
	for(i=0;i<EG_SUB_ROW;i++){
		EG_LCDWriteCommand(i|0xB8);
		EG_LCDWriteCommand(0x40);
		for(j=0;j<EG_COLUMN;j++){
			if(j<=EG_SUB_COLUMN)
				EG_LCDWriteValue(0,1,0);
			else
				EG_LCDWriteValue(0,0,1);
				_NOP_();
		}
	}
}

void EG_LCDShowByte(unsigned char val,unsigned int row,unsigned int column){
	EG_LCDWriteCommand(0xB8|row);
	if(column<=EG_SUB_COLUMN){
		EG_LCDWriteCommand(0x40|column);
		EG_LCDWriteValue(val,1,0);
	}else{
		EG_LCDWriteCommand(0x40|(column-EG_SUB_COLUMN-1));
		EG_LCDWriteValue(val,0,1);
	}
}

void EG_LCDShowBuffer(unsigned char* pBuf,unsigned int size,unsigned int row,unsigned int column){
	unsigned int i;
	unsigned char tmpCol;
	EG_LCDWriteCommand(0xB8|row);
	tmpCol=column;
	for(i=0;i<size;i++){
		if(tmpCol<=EG_SUB_COLUMN){
			EG_LCDWriteCommand(0x40|tmpCol);
			EG_LCDWriteValue(pBuf[i],1,0);
		}else{
			EG_LCDWriteCommand(0x40|(tmpCol-EG_SUB_COLUMN-1));
			EG_LCDWriteValue(pBuf[i],0,1);
		}
		tmpCol++;
	}
}

void EG_LCDClearBuffer(){
    unsigned int n,m;
    for(n=0;n<EG_SUB_ROW;n++){
      for(m=0;m<EG_COLUMN;m++){
          EG_LCD_Buffer[n][m]=0;
      }
    }
}

void EG_LCDSetPixel(unsigned int PixelRow,unsigned int PixelColumn){
    unsigned int row;
	unsigned char pixels,temp;
    if((PixelRow>EG_ROW)||(PixelColumn>EG_COLUMN)){
        return;
    }
    row=PixelRow>>3;
    pixels=PixelRow&0x07;
    temp=0x01;
    temp=temp<<pixels;
    EG_LCD_Buffer[row][PixelColumn]=EG_LCD_Buffer[row][PixelColumn]|temp;
}

void EG_LCDClearPixel(unsigned int PixelRow,unsigned int PixelColumn){
    unsigned int row;
	unsigned char pixels,temp;
    if((PixelRow>EG_ROW)||(PixelColumn>EG_COLUMN)){
        return;
    }
    row=PixelRow>>3;
    pixels=PixelRow&0x07;
    temp=0x01;
    temp=temp<<pixels;
    temp=~temp;
    EG_LCD_Buffer[row][PixelColumn]=EG_LCD_Buffer[row][PixelColumn]&temp;
}

unsigned char EG_LCDGetPixel(unsigned int PixelRow,unsigned int PixelColumn){
    unsigned int row,pixels;
	unsigned char temp;
    if((PixelRow>EG_ROW)||(PixelColumn>EG_COLUMN)){
        return 0;
    }
    row=PixelRow>>3;
    pixels=PixelRow&0x07;
    temp=0x01;
    temp=temp<<pixels;
    return EG_LCD_Buffer[row][PixelColumn]|temp;
}

//example: 
//   _|_ Pixel Position
//    |X                  1
//     X                  1
//     X  <-  val         1
//     X                  1
//     X                  1
//     X                  0
//     X                  1
//     X                  0    if val=0x5F 
//Note that the value is upside down.
void EG_LCDSetVerticalByte(unsigned int PixelRow,unsigned int PixelColumn,unsigned char val){
    unsigned int row;
	unsigned char pixels,temp;
    if((PixelRow>EG_ROW)||(PixelColumn>EG_COLUMN)){
        return;
    }
    row=PixelRow>>3;
    pixels=PixelRow&0x07;
    temp=val<<pixels;
    EG_LCD_Buffer[row][PixelColumn]=temp;
    temp=val>>(8-pixels);
    EG_LCD_Buffer[row+1][PixelColumn]=temp;
}

void EG_LCDSetORVerticalByte(unsigned int PixelRow,unsigned int PixelColumn,unsigned char val){
    unsigned int row;
	unsigned char pixels,temp;
    if((PixelRow>EG_ROW)||(PixelColumn>EG_COLUMN)){
        return;
    }
    row=PixelRow>>3;
    pixels=PixelRow&0x07;
    temp=val<<pixels;
    EG_LCD_Buffer[row][PixelColumn]|=temp;
    temp=val>>(8-pixels);
    EG_LCD_Buffer[row+1][PixelColumn]|=temp;
}

void EG_LCDSetANDVerticalByte(unsigned int PixelRow,unsigned int PixelColumn,unsigned char val){
    unsigned int row;
	unsigned char pixels,temp;
    if((PixelRow>EG_ROW)||(PixelColumn>EG_COLUMN)){
        return;
    }
    row=PixelRow>>3;
    pixels=PixelRow&0x07;
    temp=val<<pixels;
    EG_LCD_Buffer[row][PixelColumn]&=temp;
    temp=val>>(8-pixels);
    EG_LCD_Buffer[row+1][PixelColumn]&=temp;
}

//   example: 
//    _|_Pixel Position
//     |XXXXXXXX   <-  val
void EG_LCDSetByte(unsigned int PixelRow,unsigned int PixelColumn,unsigned char val){
    unsigned char temp=0x80;
    unsigned char n=0;
    for(;n<8;n++){
        if(val&temp){
            EG_LCDSetPixel(PixelRow,PixelColumn+n);
        }else{
            EG_LCDClearPixel(PixelRow,PixelColumn+n);
        }
        temp=temp>>1;
    }
}

void EG_LCDFlushBuffer(){
  unsigned int i,j;
  for(i=0;i<EG_SUB_ROW;i++){
    EG_LCDWriteCommand(i|0xB8);
    EG_LCDWriteCommand(0x40);
    for(j=0;j<EG_COLUMN;j++){
      if(j<=EG_SUB_COLUMN)
        EG_LCDWriteValue(EG_LCD_Buffer[i][j],1,0);
      else
        EG_LCDWriteValue(EG_LCD_Buffer[i][j],0,1);
      _NOP_();
    }
  }
}

#endif


