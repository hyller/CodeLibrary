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
	ExtGDIplus.h
*/

#pragma once
#include "EGUIMacro.h"
#include "GraphicFunc.h"
#include "BufferDriver.h"
#include "stdafx.h"
#include <gdiplus.h>
using namespace Gdiplus;

#ifdef WIN32_SIMULATE

#ifdef EG_SINGLE_COLOR

class EG_BinaryBufferDisplay{
public:
	EG_BinaryBufferDisplay(unsigned int sizeX,unsigned int sizeY)
		:m_uX(sizeX),m_uY(sizeY),m_cWrite(255,255,255),m_cBlack(0,0,0){
		m_pGraphic=NULL;
		m_pBitmap=NULL;
		EG_LCDClearBuffer();
	}
	EG_BinaryBufferDisplay(HDC hDC,unsigned int sizeX,unsigned int sizeY)
		:m_uX(sizeX),m_uY(sizeY),m_cWrite(255,255,255),m_cBlack(0,0,0){
		m_pGraphic=new ::Graphics(hDC);
		m_pBitmap=new ::Bitmap(sizeX,sizeY,m_pGraphic);
		EG_LCDClearBuffer();
	}
	virtual ~EG_BinaryBufferDisplay(){
		delete m_pBitmap;
		delete m_pGraphic;
	}

	void SetDeviceContext(HDC hDC){
		if(m_pGraphic==NULL){
			m_pGraphic=new ::Graphics(hDC);
			m_pBitmap=new ::Bitmap(this->m_uX,this->m_uY,m_pGraphic);
		}
	}
	
	virtual void BufferDisplay(){
		for(unsigned int n=0;n<m_uX;n++){    // flush the bitmap
			for(unsigned int m=0;m<m_uY;m++){
				if(EG_LCDGetPixel(m,n)){  //row,column => m,n
					m_pBitmap->SetPixel(n,m,m_cBlack);	//x,y => n,m	
				}else{
					m_pBitmap->SetPixel(n,m,m_cWrite);			
				}
			}
		}
		m_pGraphic->DrawImage(m_pBitmap,0,0);	
	}

	::Bitmap* GetCurrentBitmap(){
		return m_pBitmap;
	}

protected:

	Gdiplus::Color m_cWrite;
	Gdiplus::Color m_cBlack;
	Gdiplus::Graphics* m_pGraphic;
	Gdiplus::Bitmap* m_pBitmap;	
private:
	unsigned int m_uX;
	unsigned int m_uY;
};

#else  //EG_RGB_COLOR

class EG_RGBBufferDisplay{
public:
	EG_RGBBufferDisplay(unsigned int sizeX,unsigned int sizeY)
		:m_uX(sizeX),m_uY(sizeY){
		m_pGraphic=NULL;
		m_pBitmap=NULL;
		EG_LCDClearBuffer();
	}
	EG_RGBBufferDisplay(HDC hDC,unsigned int sizeX,unsigned int sizeY)
		:m_uX(sizeX),m_uY(sizeY){
		m_pGraphic=new Graphics(hDC);
		m_pBitmap=new Bitmap(sizeX,sizeY,m_pGraphic);
		EG_LCDClearBuffer();
	}
	virtual ~EG_RGBBufferDisplay(){
		delete m_pBitmap;
		delete m_pGraphic;
	}
	
	void SetDeviceContext(HDC hDC){
		if(m_pGraphic==NULL){
			m_pGraphic=new Graphics(hDC);
			m_pBitmap=new Bitmap(this->m_uX,this->m_uY,m_pGraphic);
		}
	}
	virtual void BufferDisplay(){
		EColor temp;
		for(unsigned int n=0;n<m_uX;n++){    // flush the bitmap
			for(unsigned int m=0;m<m_uY;m++){
				temp=EG_Sim_Buffer[m][n];
#ifdef EG_COMPACT_ECOLOR
				m_pBitmap->SetPixel(n,m,::Color(temp.GetRed(),temp.GetGreen(),temp.GetBlue()));	
#else
				m_pBitmap->SetPixel(n,m,::Color(temp.m_cRed,temp.m_cGreen,temp.m_cBlue));	
#endif
			}
		}
		m_pGraphic->DrawImage(m_pBitmap,0,0);	
	}

	::Bitmap* GetCurrentBitmap(){
		return m_pBitmap;
	}

protected:
	Gdiplus::Graphics* m_pGraphic;
	Gdiplus::Bitmap* m_pBitmap;	
private:
	unsigned int m_uX;
	unsigned int m_uY;
};


#endif  //EG_RGB_COLOR

#endif //WIN32_SIMULATE
