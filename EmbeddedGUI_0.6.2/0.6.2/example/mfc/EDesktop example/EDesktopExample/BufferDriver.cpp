/*
    EmbeddedGUI Library version 0.6.2
    Copyright (C) 2011  WangChao

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
	BufferDriver.c
*/

#include "BufferDriver.h"

#ifdef WIN32_SIMULATE
#ifdef EG_SINGLE_COLOR

unsigned char EG_Sim_Buffer[EG_SUB_ROW][EG_COLUMN];

void EG_LCDSetPixel(unsigned int PixelRow,unsigned int PixelColumn){
    unsigned int row,pixels;
	unsigned char temp;
    if((PixelRow>EG_ROW)||(PixelColumn>EG_COLUMN)){
        return;
    }
    row=PixelRow>>3;
    pixels=PixelRow&0x07;
    temp=0x01;
    temp=temp<<pixels;
    EG_Sim_Buffer[row][PixelColumn]=EG_Sim_Buffer[row][PixelColumn]|temp;
}

void EG_LCDClearPixel(unsigned int PixelRow,unsigned int PixelColumn){
    unsigned int row,pixels;
	unsigned char temp;
    if((PixelRow>EG_ROW)||(PixelColumn>EG_COLUMN)){
        return;
    }
    row=PixelRow>>3;
    pixels=PixelRow&0x07;
    temp=0x01;
    temp=temp<<pixels;
    temp=~temp;
    EG_Sim_Buffer[row][PixelColumn]=EG_Sim_Buffer[row][PixelColumn]&temp;
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
    return EG_Sim_Buffer[row][PixelColumn]&temp;
}

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

void EG_LCDClearBuffer(){
    unsigned int n,m;
    for(n=0;n<EG_SUB_ROW;n++){
		for(m=0;m<EG_COLUMN;m++){
		  EG_Sim_Buffer[n][m]=0;
		}
    }
}

#else //EG_RGB_COLOR

EColor EG_Sim_Buffer[EG_ROW][EG_COLUMN];

void EG_LCDClearBuffer(){
    unsigned int n,m;
	EColor c=EColor(255,255,255);
    for(n=0;n<EG_ROW;n++){
		for(m=0;m<EG_COLUMN;m++){
		    EG_Sim_Buffer[n][m]=c;
		}
    }
}

#endif //EG_RGB_COLOR

#endif //WIN32_SIMULATE

