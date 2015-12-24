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
	SerialCursor.h
*/
#include "EComponent.h"

#ifdef SERIAL_CURSOR_DEBUG

#ifdef S3C2440A	
	
	#define UTXH0  (*(volatile unsigned char*)0X50000020)
	#define URXH0  (*(volatile unsigned char*)0X50000024)
	#define UTRSTAT0 (*(volatile unsigned*)0X50000010) 

	unsigned char EG_UART_ReceiveByte(void);	
	void EG_UART_SendByte(unsigned char byte);

#endif  //S3C2440A

	extern unsigned char EG_SerialCursorBuffer[4];

	unsigned char EG_ReceiveEvent(EEvent* pEvent);

#endif  //SERIAL_CURSOR_DEBUG