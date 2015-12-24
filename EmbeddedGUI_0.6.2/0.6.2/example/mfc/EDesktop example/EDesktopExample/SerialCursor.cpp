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
	SerialCursor.c
*/
#include "SerialCursor.h"

#ifdef SERIAL_CURSOR_DEBUG
#ifdef S3C2440A	

	unsigned char EG_UART_ReceiveByte(void){
		while(!(UTRSTAT0 & 0X01));
		return URXH0;			
	}
	
	void EG_UART_SendByte(unsigned char byte){
		while(!(UTRSTAT0 & 0X04));
		UTXH0=byte;	
	}

#endif  //S3C2440A

	unsigned char EG_SerialCursorBuffer[4];

	unsigned char EG_ReceiveEvent(EEvent* pEvent){
		unsigned int temp;
		do{
			EG_SerialCursorBuffer[0]=EG_UART_ReceiveByte();
		}while(EG_SerialCursorBuffer[0]!=0x5A);
		EG_SerialCursorBuffer[1]=EG_UART_ReceiveByte();
		if(EG_SerialCursorBuffer[1]!=0xA5){
			return 1;
		}
		EG_SerialCursorBuffer[0]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[1]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[2]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[3]=EG_UART_ReceiveByte();
		temp=(EG_SerialCursorBuffer[0]<<24)+(EG_SerialCursorBuffer[1]<<16)+(EG_SerialCursorBuffer[2]<<8)+(EG_SerialCursorBuffer[3]);
		pEvent->m_uSource=temp;
		EG_SerialCursorBuffer[0]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[1]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[2]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[3]=EG_UART_ReceiveByte();
		temp=(EG_SerialCursorBuffer[0]<<24)+(EG_SerialCursorBuffer[1]<<16)+(EG_SerialCursorBuffer[2]<<8)+(EG_SerialCursorBuffer[3]);
		pEvent->m_uMessage=temp;
		EG_SerialCursorBuffer[0]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[1]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[2]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[3]=EG_UART_ReceiveByte();
		temp=(EG_SerialCursorBuffer[0]<<24)+(EG_SerialCursorBuffer[1]<<16)+(EG_SerialCursorBuffer[2]<<8)+(EG_SerialCursorBuffer[3]);
		pEvent->m_pPosition.m_uX=temp;
		EG_SerialCursorBuffer[0]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[1]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[2]=EG_UART_ReceiveByte();
		EG_SerialCursorBuffer[3]=EG_UART_ReceiveByte();
		temp=(EG_SerialCursorBuffer[0]<<24)+(EG_SerialCursorBuffer[1]<<16)+(EG_SerialCursorBuffer[2]<<8)+(EG_SerialCursorBuffer[3]);
		pEvent->m_pPosition.m_uY=temp;
		EG_SerialCursorBuffer[0]=EG_UART_ReceiveByte();
		if(EG_SerialCursorBuffer[0]!=0x5F){
			return 2;
		}
		EG_SerialCursorBuffer[0]=EG_UART_ReceiveByte();
		if(EG_SerialCursorBuffer[0]!=0xF5){
			return 3;
		}
		return 0;
	}

#endif  //SERIAL_CURSOR_DEBUG



