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
	ECursor.cpp   
*/

#include "ECursor.h"

#ifdef EG_CURSOR

#ifdef EG_RGB_COLOR

EPosition ECursor::SetCursorPosition(const EPosition& curPos){
	EPosition temp=m_pOldBufferPos;
#ifdef WIN32_SIMULATE
	int nmax,mmax;
	int n,m;
	if(this->m_bOldBufferValid){   //  if the old buffer is valid, recover it first
		//make sure the curPos is in the range.
		if(m_pOldBufferPos.m_uX<=EG_COLUMN-16){
			nmax=16;
		}else{
			nmax=EG_COLUMN-m_pOldBufferPos.m_uX-1;
		}
		if(m_pOldBufferPos.m_uY<=EG_ROW-16){
			mmax=16;
		}else{
			mmax=EG_ROW-m_pOldBufferPos.m_uY-1;
		}
		for(n=0;n<nmax;n++){
			for(m=0;m<mmax;m++){
				EG_Sim_Buffer[m_pOldBufferPos.m_uY+m][m_pOldBufferPos.m_uX+n]=m_cbOldBuffer.m_cCursorShape[m][n];
			}			
		}			
	}
	this->m_bOldBufferValid=true;
	//save the old buffer
	this->m_pOldBufferPos=curPos;
	//make sure the curPos is in the range.
	if(m_pOldBufferPos.m_uX<=EG_COLUMN-16){
		nmax=16;
	}else{
		nmax=EG_COLUMN-m_pOldBufferPos.m_uX-1;
	}
	if(m_pOldBufferPos.m_uY<=EG_ROW-16){
		mmax=16;
	}else{
		mmax=EG_ROW-m_pOldBufferPos.m_uY-1;
	}
	for(n=0;n<nmax;n++){
		for(m=0;m<mmax;m++){
			this->m_cbOldBuffer.m_cCursorShape[m][n]=EG_Sim_Buffer[curPos.m_uY+m][curPos.m_uX+n];
		}			
	}
	//draw the new cursor
	for(n=0;n<nmax;n++){
		for(m=0;m<mmax;m++){
#ifdef EG_COMPACT_ECOLOR
			if(!((this->m_cbCursor.m_cCursorShape[n][m].m_cHighByte==255)&&
				(this->m_cbCursor.m_cCursorShape[n][m].m_cLowByte==255))){
#else
			if(!((this->m_cbCursor.m_cCursorShape[n][m].m_cBlue==255)&&
				(this->m_cbCursor.m_cCursorShape[n][m].m_cGreen==255)&&
				(this->m_cbCursor.m_cCursorShape[n][m].m_cRed==255))){
#endif
				EG_Sim_Buffer[curPos.m_uY+m][curPos.m_uX+n]=this->m_cbCursor.m_cCursorShape[m][n];
			}
		}			
	}	
#endif  //WIN32_SIMULATE	
#ifdef DOT_MATRIX_LCD
	int nmax,mmax;
	int n,m;
	if(this->m_bOldBufferValid){   //  if the old buffer is valid, recover it first
		//make sure the curPos is in the range.
		if(m_pOldBufferPos.m_uX<=EG_COLUMN-16){
			nmax=16;
		}else{
			nmax=EG_COLUMN-m_pOldBufferPos.m_uX-1;
		}
		if(m_pOldBufferPos.m_uY<=EG_ROW-16){
			mmax=16;
		}else{
			mmax=EG_ROW-m_pOldBufferPos.m_uY-1;
		}
		for(n=0;n<nmax;n++){
			for(m=0;m<mmax;m++){
				EG_LCD_Buffer[m_pOldBufferPos.m_uY+m][m_pOldBufferPos.m_uX+n]=m_cbOldBuffer.m_cCursorShape[m][n];
			}			
		}			
	}
	this->m_bOldBufferValid=true;
	//save the old buffer
	this->m_pOldBufferPos=curPos;
	//make sure the curPos is in the range.
	if(m_pOldBufferPos.m_uX<=EG_COLUMN-16){
		nmax=16;
	}else{
		nmax=EG_COLUMN-m_pOldBufferPos.m_uX-1;
	}
	if(m_pOldBufferPos.m_uY<=EG_ROW-16){
		mmax=16;
	}else{
		mmax=EG_ROW-m_pOldBufferPos.m_uY-1;
	}
	for(n=0;n<nmax;n++){
		for(m=0;m<mmax;m++){
			this->m_cbOldBuffer.m_cCursorShape[m][n]=EG_LCD_Buffer[curPos.m_uY+m][curPos.m_uX+n];
		}			
	}
	//draw the new cursor
	for(n=0;n<nmax;n++){
		for(m=0;m<mmax;m++){
#ifdef EG_COMPACT_ECOLOR
			if(!((this->m_cbCursor.m_cCursorShape[n][m].m_cHighByte==255)&&
				(this->m_cbCursor.m_cCursorShape[n][m].m_cLowByte==255))){
#else
			if(!((this->m_cbCursor.m_cCursorShape[n][m].m_cBlue==255)&&
				(this->m_cbCursor.m_cCursorShape[n][m].m_cGreen==255)&&
				(this->m_cbCursor.m_cCursorShape[n][m].m_cRed==255))){
#endif
				EG_LCD_Buffer[curPos.m_uY+m][curPos.m_uX+n]=this->m_cbCursor.m_cCursorShape[m][n];
			}
		}			
	}	
#endif  //DOT_MATRIX_LCD
	return temp;
}

void ECursor::LoadCursorShape(const unsigned char* pcursor){
	for(int n=0;n<16;n++){
		for(int m=0;m<16;m++){
#ifdef EG_COMPACT_ECOLOR
			this->m_cbCursor.m_cCursorShape[n][m].SetBlue(*(pcursor+n*16+m));
			this->m_cbCursor.m_cCursorShape[n][m].SetRed(*(pcursor+n*16+m));
			this->m_cbCursor.m_cCursorShape[n][m].SetGreen(*(pcursor+n*16+m));
#else
			this->m_cbCursor.m_cCursorShape[n][m].m_cBlue=*(pcursor+n*16+m);					
			this->m_cbCursor.m_cCursorShape[n][m].m_cGreen=*(pcursor+n*16+m);					
			this->m_cbCursor.m_cCursorShape[n][m].m_cRed=*(pcursor+n*16+m);					
#endif  //EG_COMPACT_ECOLOR
		}		
	}
}

void ECursor::ClearCursorShape(){
	EColor temp(255,255,255);
	for(int n=0;n<16;n++){
		for(int m=0;m<16;m++){			
			this->m_cbCursor.m_cCursorShape[n][m]	=temp;	
		}
	}
}

#else

EPosition ECursor::SetCursorPosition(const EPosition& curPos){
	EPosition temp=m_pOldBufferPos;
#ifdef WIN32_SIMULATE
	unsigned int tempy=m_pOldBufferPos.m_uY>>3;
	int nmax,mmax;
	int n,m;
	if(this->m_bOldBufferValid){   //  if the old buffer is valid, recover it first
		//make sure the curPos is in the range.
		if(m_pOldBufferPos.m_uX<=EG_COLUMN-8){
			nmax=8;
		}else{
			nmax=EG_COLUMN-m_pOldBufferPos.m_uX-1;
		}
		if(tempy<=EG_SUB_ROW-2){
			mmax=2;
		}else{
			mmax=1;
		}
		for(n=0;n<nmax;n++){
			for(m=0;m<mmax;m++){
				EG_Sim_Buffer[tempy+m][m_pOldBufferPos.m_uX+n]=m_caOldBuffer[m][n];
			}			
		}			
	}
	this->m_bOldBufferValid=true;
	//save the old buffer
	this->m_pOldBufferPos=curPos;
	tempy=m_pOldBufferPos.m_uY>>3;
	//make sure the curPos is in the range.
	if(m_pOldBufferPos.m_uX<=EG_COLUMN-8){
		nmax=8;
	}else{
		nmax=EG_COLUMN-m_pOldBufferPos.m_uX-1;
	}
	if(tempy<=EG_SUB_ROW-2){
		mmax=2;
	}else{
		mmax=1;
	}
	for(n=0;n<nmax;n++){
		for(m=0;m<mmax;m++){
			this->m_caOldBuffer[m][n]=EG_Sim_Buffer[tempy+m][curPos.m_uX+n];
		}			
	}
	//draw the new cursor
	unsigned char upCursor[8];
	unsigned char downCursor[8];
	if(mmax==2){
		for(n=0;n<nmax;n++){
			if((curPos.m_uY&0x7)!=0){
				for(int a=0;a<8;a++){
					upCursor[a]=this->m_cbCursor.m_cCursorShape[a]<<(curPos.m_uY&0x7);
					downCursor[a]=this->m_cbCursor.m_cCursorShape[a]>>(8-curPos.m_uY&0x7);
				}
			}else{
				for(int a=0;a<8;a++){
					upCursor[a]=this->m_cbCursor.m_cCursorShape[a];
					downCursor[a]=0;
				}
			}
			EG_Sim_Buffer[tempy][curPos.m_uX+n]|=upCursor[n];
			EG_Sim_Buffer[tempy+1][curPos.m_uX+n]|=downCursor[n];
		}	
	}else{
		for(n=0;n<nmax;n++){
			for(int a=0;a<8;a++){
				upCursor[a]=this->m_cbCursor.m_cCursorShape[a]<<(curPos.m_uY&0x7);
			}
			EG_Sim_Buffer[tempy][curPos.m_uX+n]|=upCursor[n];
		}	
	}
#endif  //WIN32_SIMULATE	
#ifdef DOT_MATRIX_LCD
	unsigned int tempy=m_pOldBufferPos.m_uY>>3;
	int nmax,mmax;
	int n,m;
	if(this->m_bOldBufferValid){   //  if the old buffer is valid, recover it first
		//make sure the curPos is in the range.
		if(m_pOldBufferPos.m_uX<=EG_COLUMN-8){
			nmax=8;
		}else{
			nmax=EG_COLUMN-m_pOldBufferPos.m_uX-1;
		}
		if(tempy<=EG_SUB_ROW-2){
			mmax=2;
		}else{
			mmax=1;
		}
		for(n=0;n<nmax;n++){
			for(m=0;m<mmax;m++){
				EG_LCD_Buffer[tempy+m][m_pOldBufferPos.m_uX+n]=m_caOldBuffer[m][n];
			}			
		}			
	}
	this->m_bOldBufferValid=true;
	//save the old buffer
	this->m_pOldBufferPos=curPos;
	tempy=m_pOldBufferPos.m_uY>>3;
	//make sure the curPos is in the range.
	if(m_pOldBufferPos.m_uX<=EG_COLUMN-8){
		nmax=8;
	}else{
		nmax=EG_COLUMN-m_pOldBufferPos.m_uX-1;
	}
	if(tempy<=EG_SUB_ROW-2){
		mmax=2;
	}else{
		mmax=1;
	}
	for(n=0;n<nmax;n++){
		for(m=0;m<mmax;m++){
			this->m_caOldBuffer[m][n]=EG_LCD_Buffer[tempy+m][curPos.m_uX+n];
		}			
	}
	//draw the new cursor
	unsigned char upCursor[8];
	unsigned char downCursor[8];
	if(mmax==2){
		for(n=0;n<nmax;n++){
			if((curPos.m_uY&0x7)!=0){
				for(int a=0;a<8;a++){
					upCursor[a]=this->m_cbCursor.m_cCursorShape[a]<<(curPos.m_uY&0x7);
					downCursor[a]=this->m_cbCursor.m_cCursorShape[a]>>(8-curPos.m_uY&0x7);
				}
			}else{
				for(int a=0;a<8;a++){
					upCursor[a]=this->m_cbCursor.m_cCursorShape[a];
					downCursor[a]=0;
				}
			}
			EG_LCD_Buffer[tempy][curPos.m_uX+n]|=upCursor[n];
			EG_LCD_Buffer[tempy+1][curPos.m_uX+n]|=downCursor[n];
		}	
	}else{
		for(n=0;n<nmax;n++){
			for(int a=0;a<8;a++){
				upCursor[a]=this->m_cbCursor.m_cCursorShape[a]<<(curPos.m_uY&0x7);
			}
			EG_LCD_Buffer[tempy][curPos.m_uX+n]|=upCursor[n];
		}	
	}
#endif  //DOT_MATRIX_LCD	
	return temp;
}

#endif  //EG_RGB_COLOR

#endif  //EG_CURSOR
