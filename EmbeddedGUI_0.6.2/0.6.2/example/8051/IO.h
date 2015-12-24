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
	IO.h
*/

#ifdef MSP430
	#include <msp430x44x.h>

//    MCU Pin Mapping :
//        P2.0 -> RS      
//        P2.1 -> RW 
//        P2.2 -> EN 
//        P2.3 -> CS1 
//        P2.6 -> CS2   
//        P2.7 -> RST 
//        P3.0~P3.7 -> DB0~DB7   

// change these pin definition in your application.
 
#define		P2_0_RS			0x01
#define		P2_1_RW			0x02
#define		P2_2_EN			0x04
#define		P2_3_CS1		0x08
#define		P2_4_CS2		0x40
#define		P2_5_RST		0x80

#define		P3_0_DB0		0x01
#define		P3_1_DB1		0x02
#define		P3_2_DB2		0x04
#define		P3_3_DB3		0x08
#define		P3_4_DB4		0x10
#define		P3_5_DB5		0x20
#define		P3_6_DB6		0x40
#define		P3_7_DB7		0x80

#define SET_DATA_DIRECTION(DIR) P3DIR=DIR 
#define SET_DATA_VALUE(VAL) P3OUT=VAL
#define SET_CON_DIRECTION(DIR) P2DIR=DIR 
#define SET_CON_VALUE(VAL) P2OUT=VAL
#define SET_CON_NAND_VALUE(VAL) P2OUT&=~VAL
#define SET_CON_OR_VALUE(VAL) P2OUT|=VAL

#define _NOP_ __no_operation

#endif //MSP430

#ifdef LPC22XX
	#include <LPC22xx.H>

//    MCU Pin Mapping :
//        P1.16 -> RS   
//        P1.17 -> RW 
//        P1.18 -> EN 
//        P1.19 -> CS1 
//        P1.20 -> CS2   
//        P1.21 -> RST 
//        P3.0~P3.7 -> DB0~DB7   

#define		P2_0_RS			0x00010000
#define		P2_1_RW			0x00020000
#define		P2_2_EN			0x00040000
#define		P2_3_CS1		0x00080000
#define		P2_4_CS2		0x00100000
#define		P2_5_RST		0x00200000

#define		P3_0_DB0		0x00000001
#define		P3_1_DB1		0x00000002
#define		P3_2_DB2		0x00000004
#define		P3_3_DB3		0x00000008
#define		P3_4_DB4		0x00000010
#define		P3_5_DB5		0x00000020
#define		P3_6_DB6		0x00000040
#define		P3_7_DB7		0x00000080

#define SET_DATA_DIRECTION(DIR) IODIR3=DIR 
#define SET_DATA_VALUE(VAL) IOPIN3=VAL
#define SET_CON_DIRECTION(DIR) IODIR1=DIR 
#define SET_CON_VALUE(VAL) IOPIN1=VAL
#define SET_CON_NAND_VALUE(VAL) IOPIN1&=~VAL
#define SET_CON_OR_VALUE(VAL) IOPIN1|=VAL

#define _NOP_ __nop

#endif  //LPC22XX

#ifdef W78E5XX
	#include <REG54.H>
	#include "INTRINS.H"

//    MCU Pin Mapping :
//        P2.0 -> RS   
//        P2.1 -> RW 
//        P2.2 -> EN 
//        P2.3 -> CS1 
//        P2.4 -> CS2   
//        P2.5 -> RST 
//        P3.0~P3.7 -> DB0~DB7   

#define		P2_0_RS			0x01
#define		P2_1_RW			0x02
#define		P2_2_EN			0x04
#define		P2_3_CS1		0x08
#define		P2_4_CS2		0x10
#define		P2_5_RST		0x20

#define		P3_0_DB0		0x01
#define		P3_1_DB1		0x02
#define		P3_2_DB2		0x04
#define		P3_3_DB3		0x08
#define		P3_4_DB4		0x10
#define		P3_5_DB5		0x20
#define		P3_6_DB6		0x40
#define		P3_7_DB7		0x80

#define SET_DATA_DIRECTION(DIR) P3=DIR 
#define SET_DATA_VALUE(VAL) P3=VAL
#define SET_CON_DIRECTION(DIR) P2=DIR 
#define SET_CON_VALUE(VAL) P2=VAL
#define SET_CON_NAND_VALUE(VAL) P2&=~VAL
#define SET_CON_OR_VALUE(VAL) P2|=VAL

#define _NOP_  _nop_ 


#endif //W78E5XX
