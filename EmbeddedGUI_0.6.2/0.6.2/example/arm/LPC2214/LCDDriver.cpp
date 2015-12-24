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
	LCDDriver.cpp
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

#ifdef EG_SINGLE_COLOR
unsigned char EG_LCD_Buffer[EG_SUB_ROW][EG_COLUMN];
#else  //EG_RGB_COLOR
#ifndef EG_NO_EBUFFER
	#include "EComponent.h"
EColor EG_LCD_Buffer[EG_ROW][EG_COLUMN];
#endif //EG_NO_EBUFFER
#endif

#ifdef EG_KS010X_LCD_DRIVER

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

#endif //EG_KS010X_LCD_DRIVER

#ifdef EG_T6963C_LCD_DRIVER

void EG_LCDBusyStateCheck(void){
	unsigned char i,d;
	SET_DATA_DIRECTION(0x00);  //set data bus read state
	//CD=1 CE=0 RD=0
	SET_CON_OR_VALUE(P3_0_CD|P3_2_RD);
	SET_CON_NAND_VALUE(P3_3_CE);
	for(i=0;i<20;i++){
		SET_CON_NAND_VALUE(P3_2_RD);   //RD=0
		_NOP_();
		d=GET_DATA_VALUE();
		SET_CON_OR_VALUE(P3_2_RD);   //RD=1
		if((d&0x3)==0x3){
			break;   //D0D1=11  state is free.
		}
	}
	SET_CON_OR_VALUE(P3_3_CE);   //CE=1
}

void EG_LCDWriteCommand(unsigned char cmd){
	SET_CON_DIRECTION(0x0F);
	EG_LCDBusyStateCheck();
	SET_DATA_DIRECTION(0xFF);
	SET_DATA_VALUE(cmd);
	//CD=1 CE=0 WR=0
	SET_CON_OR_VALUE(P3_0_CD);
	SET_CON_NAND_VALUE(P3_1_WR|P3_3_CE);
	_NOP_();
	SET_CON_OR_VALUE(P3_1_WR|P3_3_CE);  //WR=1  CE=1
}

void EG_LCDWriteData(unsigned char data){
	SET_CON_DIRECTION(0x0F);
	EG_LCDBusyStateCheck();
	SET_DATA_DIRECTION(0xFF);
	SET_DATA_VALUE(data);
	//CD=0 CE=0 WR=0
	SET_CON_NAND_VALUE(P3_1_WR|P3_3_CE|P3_0_CD);
	_NOP_();
	SET_CON_OR_VALUE(P3_1_WR|P3_3_CE);  //WR=1  CE=1
}

unsigned char EG_LCDReadData(void){
	unsigned char res;
	SET_CON_DIRECTION(0x0F);
	EG_LCDBusyStateCheck();
	SET_DATA_DIRECTION(0x00);
	//CD=0 CE=0 RD=0
	SET_CON_NAND_VALUE(P3_2_RD|P3_3_CE|P3_0_CD);
	_NOP_();
	res=GET_DATA_VALUE();
	SET_CON_OR_VALUE(P3_2_RD|P3_3_CE);  //RD=1  CE=1
	_NOP_();
	SET_DATA_DIRECTION(0xFF);
	return res;
}

//#define EG_LCDWriteCommand2(C,D) EG_LCDWriteData(D);EG_LCDWriteCommand(C)
//#define EG_LCDWriteCommand3(C,D1,D2) EG_LCDWriteData(D1);EG_LCDWriteData(D2);EG_LCDWriteCommand(C)

void EG_LCDInit(void){
	SET_CON_DIRECTION(0x0F);
	SET_DATA_DIRECTION(0xFF);
	SET_CON_OR_VALUE(P3_2_RD|P3_3_CE|P3_0_CD|P3_1_WR);
	EG_LCDWriteCommand3(EG_LCD_TXT_STP,0x00,0x00);   //set the text RAM start address
	EG_LCDWriteCommand3(EG_LCD_TXT_WID,(EG_COLUMN>>3),0x00);
	EG_LCDWriteCommand3(EG_LCD_GRH_STP,0x00,0x00);  //set the graphic RAM start address
	EG_LCDWriteCommand3(EG_LCD_GRH_WID,(EG_COLUMN>>3),0x00);
	EG_LCDWriteCommand(EG_LCD_MOD_OR);
	EG_LCDWriteCommand(EG_LCD_DIS_SW|0x08);  //graphic display mode
	EG_LCDClearScreen();
}

void EG_LCDClearScreen(void){
	unsigned int i;
	EG_LCDWriteCommand3(EG_LCD_ADR_POS,0x00,0x00);  //set the address pointer
	EG_LCDWriteCommand(EG_LCD_AUT_WR);  //auto write
	for(i=0;i<((EG_COLUMN>>3)*(EG_ROW));i++){
		EG_LCDWriteData(0x00);
	}
	EG_LCDWriteCommand(EG_LCD_AUT_OVR);  //end auto write
	EG_LCDWriteCommand3(EG_LCD_ADR_POS,0x00,0x00);  //reset the address pointer
}

void EG_LCDShowByte(unsigned char val,unsigned int row,unsigned int column){
	unsigned int addr;
	unsigned char temp;
	addr=row*(EG_COLUMN>>3)+(column>>3);
	EG_LCDWriteCommand3(EG_LCD_ADR_POS,addr&0xFF,addr>>8);  //set the address pointer
	EG_LCDWriteCommand2(EG_LCD_INC_WR,val);
}

void EG_LCDFlushBuffer(void){
	unsigned char mask,temp;
	unsigned int x,y;
	for(y=0;y<EG_ROW;y++){
		for(x=0;x<EG_COLUMN;x++){
			if((x&0x07)==0x00){  
				mask=0x01;		
				temp=0x00;
			}else{
				mask=mask<<1;
			}
			if(EG_LCDGetPixel(x,y))
				temp=temp|mask;
			if((x&0x07)==0x07){
				EG_LCDShowByte(temp,x-7,y);
			}
		}	
	}
	EG_LCDWriteCommand3(EG_LCD_ADR_POS,0x00,0x00);  //set the address pointer
}

#endif //EG_T6963C_LCD_DRIVER

#ifdef EG_S6B33C_LCD_DRIVER

void EG_LCDDelay(unsigned int n){
	for(unsigned int x=0;x<n;x++){
		for(unsigned int y=0;y<EG_MCU_FREQ;y++){
			_NOP_();
		}	
	}
}

void EG_LCDReset(void){
	SET_CON_NAND_VALUE(P3_6_RST);
	EG_LCDDelay(1);
	SET_CON_OR_VALUE(P3_6_RST);
}

void EG_LCDTurnBackLight(unsigned char on){
	if(on){
		SET_CON_OR_VALUE(P3_5_BL_EN);
	}else{
		SET_CON_NAND_VALUE(P3_5_BL_EN);
	}
}

void EG_LCDWriteCommand(unsigned char cmd){
	SET_CON_NAND_VALUE(P3_1_A0|P3_4_CS);
	SET_DATA_VALUE(cmd);
	_NOP_();
	SET_CON_NAND_VALUE(P3_2_WR);
	_NOP_();
	SET_CON_OR_VALUE(P3_2_WR);
	_NOP_();
	SET_CON_OR_VALUE(P3_4_CS);
}

void EG_LCDWriteData(unsigned char data){
	SET_CON_OR_VALUE(P3_1_A0);
	SET_CON_NAND_VALUE(P3_4_CS);
	SET_DATA_VALUE(data);
	_NOP_();
	SET_CON_NAND_VALUE(P3_2_WR);
	_NOP_();
	SET_CON_OR_VALUE(P3_2_WR);
	_NOP_();
	SET_CON_OR_VALUE(P3_4_CS);
}

//The relation between V1 voltage and Contrast(1) set value in 3-bit step.
//	Refer to Samsung data sheet (S6B33BC) page 36 for details
void EG_LCDSetContrast(unsigned char contrast){
	EG_LCDWriteCommand(EG_LCD_CONTRAST_CONTROL1);
	EG_LCDWriteCommand(contrast);
}

#define EG_LCDOpen() EG_LCDWriteCommand(EG_LCD_DISPLAY_ON)
#define EG_LCDClose() EG_LCDWriteCommand(EG_LCD_DISPLAY_OFF)

void EG_LCDInit(void){
	SET_CON_DIRECTION(0x7E);
	SET_DATA_DIRECTION(0xFF);
	SET_CON_OR_VALUE(P3_4_CS|P3_2_WR|P3_1_A0|P3_3_RD);
	SET_DATA_VALUE(0x00);
	SET_CON_OR_VALUE(P3_5_BL_EN);
	EG_LCDReset();
	EG_LCDWriteCommand(EG_LCD_STANDBY_MODE_OFF);  //standby mode off
	EG_LCDDelay(20);  		//delay 20ms for 1st booster output stablization
	EG_LCDWriteCommand(EG_LCD_OSCILLATION_MODE_SET); //use internal OSC and OSC On
	EG_LCDWriteCommand(0x01);
	EG_LCDDelay(20);  		
	EG_LCDWriteCommand(EG_LCD_DC_DC_SET); //select the first booster's boosting step for V1 gen
	EG_LCDWriteCommand(0x0F);  //x1.5 step for normal mode
	EG_LCDDelay(20);
	EG_LCDWriteCommand(EG_LCD_DCDC_AMP_ON_OFF_SET);	//control boosters
	EG_LCDWriteCommand(0x01);		//1st booster ON
	EG_LCDDelay(20);
	EG_LCDWriteCommand(EG_LCD_DCDC_AMP_ON_OFF_SET);	//1st booster and V1 AMP ON
	EG_LCDWriteCommand(0x09);
	EG_LCDDelay(20);
	EG_LCDWriteCommand(EG_LCD_DCDC_AMP_ON_OFF_SET);	//1'st booster, V1 AMP and 2'nd booster ON
	EG_LCDWriteCommand(0x0B);
	EG_LCDDelay(20);
	EG_LCDWriteCommand(EG_LCD_DCDC_AMP_ON_OFF_SET);	//1'st booster, V1 AMP, 2'nd booster and 
	EG_LCDWriteCommand(0x0F);	//3'rd booster ON	
	EG_LCDDelay(20);
	EG_LCDWriteCommand(EG_LCD_TEMP_COMPENSATION_SET);	//set the temperature compensation ratio
	EG_LCDWriteCommand(0x00);
	EG_LCDWriteCommand(EG_LCD_DDRAM_BURST_MODE_OFF);//burst mode off for data RAM write
	EG_LCDWriteCommand(EG_LCD_RAM_SKIP_AREA_SET);		//RAM address skip area setting
	EG_LCDWriteCommand(0x00);
	EG_LCDWriteCommand(EG_LCD_SPEC_DISPLAY_PATTERN_SET);	//specify display pattern
	EG_LCDWriteCommand(0x00);		//normal display
	EG_LCDWriteCommand(EG_LCD_DRIVER_OUTPUT_MODE_SET);	//set the display duty to be 1/162 matching the LCD panel
	EG_LCDWriteCommand(0x25);		//SDIR=1, SWP=0, & CDR=1 for display direction matching
	EG_LCDWriteCommand(EG_LCD_ENTRY_MODE_SET);	//entry mode set, non-reverse, Y-Direction
	EG_LCDWriteCommand(0x00);
	EG_LCDWriteCommand(EG_LCD_CURRENT_BIAS_SET);		//1/5 bias set
	EG_LCDWriteCommand(0x11);
	EG_LCDWriteCommand(EG_LCD_PCK_GENER_MODE_SET);//DC-DC Clock div set
	EG_LCDWriteCommand(0x33);			//fosc/8 and partial mode 1		
	EG_LCDWriteCommand(EG_LCD_N_LINE_INVERSION_SET);	//N-line inversion set
	EG_LCDWriteCommand(0x10);
	EG_LCDWriteCommand(EG_LCD_FRAME_FREQUENCY_CONTROL_SET);
	EG_LCDWriteCommand(0x01);
	EG_LCDWriteCommand(EG_LCD_SPEC_DISPLAY_PATTERN_SET);//specify display pattern
	EG_LCDWriteCommand(0x00);	//normal display
	EG_LCDWriteCommand(EG_LCD_PARTIAL_DISPLAY_MODE_SET);//partial display mode set
	EG_LCDWriteCommand(0x00);
	EG_LCDSetContrast(0x60);	//set a good looking contrast for each module

	EG_LCDWriteCommand(EG_LCD_X_ADDRESS_AREA_SET);//X-address counter set, offset from 2~161 for 160 dots
	EG_LCDWriteCommand(2);
	EG_LCDWriteCommand(EG_ROW+1);
	EG_LCDWriteCommand(EG_LCD_Y_ADDRESS_AREA_SET);	//Y-address counter set, offset from 4~131 for 128 dots
	EG_LCDWriteCommand(4);
	EG_LCDWriteCommand(EG_COLUMN+3);

	EG_LCDWriteCommand(EG_LCD_ADDRESSING_MODE_SET);//addressing mode set, 65k color
	EG_LCDWriteCommand(0x1C);
	EG_LCDClearScreen();
	EG_LCDWriteCommand(EG_LCD_DISPLAY_ON);				
}

void EG_LCDClearScreen(void){
	EG_LCDWriteCommand(EG_LCD_X_ADDRESS_AREA_SET);//X-address counter set, offset from 2~161 for 160 dots
	EG_LCDWriteCommand(2);
	EG_LCDWriteCommand(EG_ROW+1);
	EG_LCDWriteCommand(EG_LCD_Y_ADDRESS_AREA_SET);	//Y-address counter set, offset from 4~131 for 128 dots
	EG_LCDWriteCommand(4);
	EG_LCDWriteCommand(EG_COLUMN+3);
	for(unsigned int x=0;x<EG_ROW;x++){
		for(unsigned int y=0;y<EG_COLUMN;y++){
			EG_LCDWriteData(0x00);
			EG_LCDWriteData(0x00);
		}
	}
}

void EG_LCDShowPixel(EColor& val,unsigned int x,unsigned int y){
	EG_LCDWriteCommand(EG_LCD_X_ADDRESS_AREA_SET);//X-address counter set, offset from 2~161 for 160 dots
	EG_LCDWriteCommand(y+2);	//offset for scan COM from 2~161
	EG_LCDWriteCommand(y+3);
	EG_LCDWriteCommand(EG_LCD_Y_ADDRESS_AREA_SET);	//Y-address counter set, offset from 4~131 for 128 dots
	EG_LCDWriteCommand(x+4);  //offset for scan SEG from 4~131
	EG_LCDWriteCommand(x+5);
	EG_LCDWriteData(val.m_cHighByte);
	EG_LCDWriteData(val.m_cLowByte);
}

#ifdef EG_NO_EBUFFER
void EG_LCDFlushBuffer(void){
	//do nothing 
}
#else
void EG_LCDFlushBuffer(void){
    unsigned int n,m;
    for(n=0;n<EG_ROW;n++){
		for(m=0;m<EG_COLUMN;m++){
			EG_LCDShowPixel(EG_LCD_Buffer[n][m],m,n);
		}
    }
}
#endif  // EG_NO_EBUFFER

#endif //EG_S6B33C_LCD_DRIVER

#ifdef EG_RA8803_LCD_DRIVER

void EG_LCDDelay(unsigned int n){
	for(unsigned int x=0;x<n;x++){
		for(unsigned int y=0;y<EG_MCU_FREQ;y++){
			_NOP_();
		}	
	}
}

void EG_LCDReset(void){
	SET_DATA_VALUE(0xFF);
	SET_CON_NAND_VALUE(P3_4_CS);   //CS=0
	EG_LCDDelay(100);   //wait for 100ms
	SET_CON_NAND_VALUE(P3_5_RST);   //RST=0
	EG_LCDDelay(250);   //wait for 250ms    LCD reset
	SET_CON_OR_VALUE(P3_5_RST);	   //RST=1
	EG_LCDDelay(100);   //wait for 100ms
}

void EG_LCDCheckBusy(void){
	do{
		_NOP_();
	}while((GET_CON_VALUE()&P3_0_BUSY));
}

//write a command to LCD
void EG_LCDWriteCommand(unsigned char cmdReg,unsigned char cmdData){
	SET_DATA_VALUE(cmdReg); //write register address
	SET_CON_NAND_VALUE(P3_4_CS);  //Enable RA8803
	SET_CON_OR_VALUE(P3_3_RD);   //not to read
	SET_CON_NAND_VALUE(P3_1_RS);   //write cmd to register
	SET_CON_NAND_VALUE(P3_2_WR);   
	_NOP_();
	SET_CON_OR_VALUE(P3_2_WR);   //next write operation
	SET_CON_OR_VALUE(P3_1_RS);   
	SET_CON_OR_VALUE(P3_4_CS);   //disable RA8803
	_NOP_();
	SET_DATA_VALUE(cmdData); //write data
	SET_CON_NAND_VALUE(P3_4_CS);   //Enable RA8803
	SET_CON_NAND_VALUE(P3_1_RS);   //write data to register
	SET_CON_NAND_VALUE(P3_2_WR);
	_NOP_();
	SET_CON_OR_VALUE(P3_2_WR);
	SET_CON_OR_VALUE(P3_1_RS);
	SET_CON_OR_VALUE(P3_4_CS);   //disable RA8803
}

unsigned char EG_LCDReadData(unsigned char cmdReg){
	unsigned char temp=0xFF;
	EG_LCDCheckBusy();   //Check if RA8803 is busy.
	SET_DATA_VALUE(cmdReg);  //write the cmd register address
	SET_CON_NAND_VALUE(P3_4_CS);   //Enable RA8803
	SET_CON_OR_VALUE(P3_3_RD);   //not to read
	SET_CON_NAND_VALUE(P3_1_RS);   //write cmd to register
	SET_CON_NAND_VALUE(P3_2_WR);   
	_NOP_();
	SET_CON_OR_VALUE(P3_2_WR);   //next read operation
	SET_CON_OR_VALUE(P3_1_RS);   
	SET_CON_OR_VALUE(P3_4_CS);   //disable RA8803
	_NOP_();
	SET_CON_NAND_VALUE(P3_4_CS); //Enable RA8803
	SET_CON_OR_VALUE(P3_2_WR); //not to write
	SET_CON_NAND_VALUE(P3_1_RS); //read from the register 
	SET_CON_NAND_VALUE(P3_3_RD); 
	temp=GET_DATA_VALUE();
	SET_CON_OR_VALUE(P3_3_RD); 
	SET_CON_OR_VALUE(P3_1_RS);
	SET_CON_OR_VALUE(P3_4_CS);   //disable RA8803
	return temp; 
}

//write data to LCD display RAM
void EG_LCDWriteData(unsigned char data){
	EG_LCDCheckBusy();   //Check if RA8803 is busy.
	SET_DATA_VALUE(data); //the data to be writen
	SET_CON_NAND_VALUE(P3_4_CS); //Enable RA8803
	SET_CON_OR_VALUE(P3_3_RD); 
	SET_CON_OR_VALUE(P3_1_RS); //write to DisplayRAM
	SET_CON_NAND_VALUE(P3_2_WR); 
	_NOP_();
	SET_CON_OR_VALUE(P3_2_WR); //end the write operation
	SET_CON_OR_VALUE(P3_1_RS);
	SET_CON_OR_VALUE(P3_4_CS); //disable RA8803
}

//   Write a byte to LCD RAM, row and column are position index.
void EG_LCDShowByte(unsigned char val,unsigned int row,unsigned int column){
	EG_LCDWriteCommand(0x60,column);  //set the horizonal address 
	EG_LCDWriteCommand(0x70,row);  //set the vertical address
	EG_LCDWriteData(val);
}

//   Initialize the LCD   
void EG_LCDInit(void){
	//set IO direction 
	SET_CON_DIRECTION(P3_1_RS|P3_2_WR|P3_4_CS|P3_5_RST);
	SET_DATA_DIRECTION(0xFF);
	SET_CON_OR_VALUE(P3_1_RS|P3_2_WR|P3_4_CS|P3_5_RST);
	SET_DATA_VALUE(0x00);
	
	EG_LCDReset();
	//set the size and position of work window.
	EG_LCDWriteCommand(0x20,0x1D);
	EG_LCDWriteCommand(0x30,0x7F);
	EG_LCDWriteCommand(0x40,0x00);
	EG_LCDWriteCommand(0x50,0x00);
	//set the size and position of display window.
	EG_LCDWriteCommand(0x21,0x1D);
	EG_LCDWriteCommand(0x31,0x80);
	EG_LCDWriteCommand(0x41,0x00);
	EG_LCDWriteCommand(0x51,0x00);
	
	EG_LCDWriteCommand(0x00,0xC5);  //WLCR graphic mode
	EG_LCDWriteCommand(0x81,0x40);  //FRCA
	EG_LCDWriteCommand(0x11,0x10);  //DWLR set the cursor
	EG_LCDWriteCommand(0x12,0x11);  //MAMR :  GIM=0 RM=001 OP=00 WM=01
	EG_LCDWriteCommand(0x10,0x68);  //WCCR 
	EG_LCDWriteCommand(0x90,0x0A);	//SCCR set the clock
}

//   Erase the LCD RAM,so the screen is clear
void EG_LCDClearScreen(void){
	unsigned char m,n;
	EG_LCDWriteCommand(0x60,0);  //set the horizonal address = 0
	EG_LCDWriteCommand(0x70,0);  //set the vertical address = 0
	for(m=0;m<EG_COLUMN;m++){
		for(n=0;n<EG_SUB_ROW;n++){
			EG_LCDWriteData(0x00);
		}
	}
}

//   copy the EG_LCD_Buffer into LCD RAM 
void EG_LCDFlushBuffer(void){
	unsigned char m,n;
	EG_LCDWriteCommand(0x60,0);  //set the horizonal address = 0
	EG_LCDWriteCommand(0x70,0);  //set the vertical address = 0
	for(m=0;m<EG_COLUMN;m++){
		for(n=0;n<EG_SUB_ROW;n++){
			EG_LCDWriteData(EG_LCD_Buffer[n][m]);
		}
	}
}

#endif  //EG_RA8803_LCD_DRIVER

#ifdef EG_S1D13305_LCD_DRIVER

void EG_LCDDelay(unsigned int n){
	for(unsigned int x=0;x<n;x++){
		for(unsigned int y=0;y<EG_MCU_FREQ;y++){
			_NOP_();
		}	
	}
}

void EG_LCDWriteCommand(unsigned char cmd){
	SET_CON_NAND_VALUE(P3_4_CS);
	SET_CON_OR_VALUE(P3_1_A0);
	SET_DATA_VALUE(cmd);
	SET_CON_OR_VALUE(P3_3_RD);
	SET_CON_NAND_VALUE(P3_2_WR);
	_NOP_();
	SET_CON_OR_VALUE(P3_2_WR);
	SET_CON_OR_VALUE(P3_4_CS);
}

void EG_LCDWriteData(unsigned char data){
	SET_CON_NAND_VALUE(P3_4_CS);
	SET_CON_NAND_VALUE(P3_1_A0);
	SET_DATA_VALUE(data);
	SET_CON_OR_VALUE(P3_3_RD);
	SET_CON_NAND_VALUE(P3_2_WR);
	_NOP_();
	SET_CON_OR_VALUE(P3_2_WR);
	SET_CON_OR_VALUE(P3_4_CS);
}

//   Initialize the LCD   
void EG_LCDInit(void){
	unsigned char m,n;
	
	//set IO direction 
	SET_CON_DIRECTION(P3_1_A0|P3_2_WR|P3_4_CS|P3_5_RST);
	SET_DATA_DIRECTION(0xFF);
	SET_CON_OR_VALUE(P3_1_A0|P3_2_WR|P3_4_CS|P3_5_RST);
	SET_DATA_VALUE(0xFF);
	
	//reset LCD module
	SET_CON_NAND_VALUE(P3_5_RST);
	EG_LCDDelay(100);  //delay 100ms
	SET_CON_OR_VALUE(P3_5_RST);
	EG_LCDDelay(100);  //delay 100ms
	
	EG_LCDWriteCommand(EG_LCD_SYSTEMSET);
	EG_LCDWriteData(0x30);  //single panel ,no CGROM
	EG_LCDWriteData(0x87);  //char width = 8
	EG_LCDWriteData(0x07);  //char height = 8
	EG_LCDWriteData((EG_COLUMN/8)-1);   //display width 
	EG_LCDWriteData(0x2b);  //TC/R>=C/R+4
	EG_LCDWriteData(EG_ROW-1);   //display height
	EG_LCDWriteData(EG_COLUMN/8);
	EG_LCDWriteData(0x00);
	
	EG_LCDWriteCommand(EG_LCD_SCROLL);
	EG_LCDWriteData(0x00);   //layer 1 address = 0x0000
	EG_LCDWriteData(0x00);
	EG_LCDWriteData(0xEF);   //scan for 240 lines
	EG_LCDWriteData(0x80);   //layer 2 address = 0x2580  -> 9600Bytes
	EG_LCDWriteData(0x25);   
	EG_LCDWriteData(0xEF);   //scan for 240 lines
	EG_LCDWriteData(0x00);   //layer 3 address = 0x0000
	EG_LCDWriteData(0x00);
	
	EG_LCDWriteCommand(EG_LCD_CSRFORM);
	EG_LCDWriteData(0x07);
	EG_LCDWriteData(0x87);   // CM=1 in graphic mode
	EG_LCDWriteCommand(EG_LCD_SDOTSCR);
	EG_LCDWriteData(0x00);
	EG_LCDWriteCommand(EG_LCD_OVERLAY);
	EG_LCDWriteData(0x0C);   //three layers,OR relation
	EG_LCDWriteCommand(EG_LCD_CSRDIR);   //cursor moves to right
	
	//clear the display RAM
	EG_LCDClearScreen();	
	EG_LCDWriteCommand(EG_LCD_CSRW);  //set the cursor address = 0x0000
	EG_LCDWriteData(0x80);
	EG_LCDWriteData(0x25);
	EG_LCDWriteCommand(EG_LCD_MWRITE);  //write to the RAM
	for(m=0;m<EG_SUB_ROW;m++){
		for(n=0;n<EG_COLUMN;n++){
			EG_LCDWriteData(0x00);
		}
	}
	
	EG_LCDWriteCommand(EG_LCD_DISPLAY);
	EG_LCDWriteData(0x16);   //display,not blink
}

//   Erase the LCD RAM,so the screen is clear
void EG_LCDClearScreen(void){
	unsigned char m,n;
	EG_LCDWriteCommand(EG_LCD_CSRW);  //set the cursor address = 0x0000
	EG_LCDWriteData(0x00);
	EG_LCDWriteData(0x00);
	EG_LCDWriteCommand(EG_LCD_MWRITE);  //write to the RAM
	for(m=0;m<EG_ROW;m++){
		for(n=0;n<(EG_COLUMN>>3);n++){
			EG_LCDWriteData(0x00);
		}
	}
}

//   copy the EG_LCD_Buffer into LCD RAM 
void EG_LCDFlushBuffer(void){
	unsigned char m,n;
	EG_LCDWriteCommand(EG_LCD_CSRW);  //set the cursor address = 0x0000
	EG_LCDWriteData(0x00);
	EG_LCDWriteData(0x00);
	EG_LCDWriteCommand(EG_LCD_MWRITE);  //write to the RAM
	for(m=0;m<EG_ROW;m++){
		for(n=0;n<(EG_COLUMN>>3);n++){
			EG_LCDWriteData(EG_LCDGetHorizonalByte(m,n<<3));
		}
	}
}

#endif  //EG_S1D13305_LCD_DRIVER

#ifdef EG_HX8238_LCD_DRIVER
/*
	Note that I initialize the LCD Controller in S3C2440 ARM920T to generate
	TFT signals such as VSYNC and HSYNC. I leave all the SPI interface pins of 
	HX8238A open(Please refer to serial interface block in HX8238 data sheet ). 
	So, any TFT CCIR601/656 input mode LCD module which connected to S3C2440 
	can use this LCD driver.
	For more details,please refer to EmbeddedGUI Library User Manual Charpter Five.
*/

//   Initialize the LCD   
//   Well, this is init code for LCD Controller in S3C2440.
void EG_LCDInit(void){
	EG_LCDChangePLL();
    GPCUP=0xFFFFFFFF; // Disable Pull-up register
    GPCCON=0xAAAA56A9; //Initialize VD[7:0],LCDVF[2:0],VM,VFRAME,VLINE,VCLK,LEND 
    GPDUP=0xFFFFFFFF; // Disable Pull-up register
    GPDCON=0xAAAAAAAA; //Initialize VD[15:8]

	//  LCDCON1  0x4D000000   ->   0x00000979
	//    CLKVAL = 9   VCLK = HCLK / [(CLKVAL+1)*2] = HCLK / 20
	//    PNRMODE = 3     TFT LCD panel
	//    BPPMODE = 12    16bpp for TFT
	//    ENVID = 0       video output enable later in EG_LCDEnableVideoOutput()
	//  LCDCON2  0x4D000004   ->   0x033BC14F
	//    VBPD = 3    Vertical back porch
	//    LINEVAL = Vertical display size - 1 = 239
	//    VFPD = 5    Vertical front porch
	//    VSPW = 15   Vertical sync pulse width
	//  LCDCON3  0x4D000008   ->   0x01D13F0F
	//    HBPD = 58   Horizonal back porch
	//    HOZVAL = Horizonal display size - 1 = 319
	//    HFPD = 15   Horizonal front porch
	//  LCDCON4  0x4D00000C   ->   0x00000D08
	//    MVAL = 13   STN use!!
	//    HSPW = 8    Horizonal sync pulse
	//  LCDCON5  0x4D000010   ->   0x00004B09
	//    BPP24BL = 0   
	//    FRM565  = 1
	//    INVVCLK = 0
	//    INVVLINE = 1
	//    INVVFRAME = 1
	//    INVVD = 0
	//    INVVDEN = 0 
	//    INVPWREN = 0
	//    INVLEND = 0
	//    PWREN = 1    LCD_PWREN output signal
	//    ENLEND = 0   disable LEND signal
	//    BSWP = 0    byte swap disable
	//    HWSWP = 1   half word swap enable
	//  LCDSADDR1   0x4D000014   ->  0x19007F7E  
	//  LCDSADDR2   0x4D000018   ->  0x0001AB7E
	//  LCDSADDR3   0x4D00001C   ->  0x00000140
	//    OFFSIZE = 0    
	//    PAGEWIDTH = 320   virtual screen page width   
	LCDCON1=(CLKVAL_TFT<<8)|(MVAL_USED<<7)|(3<<5)|(12<<1);
    	// TFT LCD panel,12bpp TFT,ENVID=off
	LCDCON2=(VBPD<<24)|(LINEVAL_TFT<<14)|(VFPD<<6)|(VSPW);
	LCDCON3=(HBPD<<19)|(HOZVAL_TFT<<8)|(HFPD);
	LCDCON4=(MVAL<<8)|(HSPW);
	LCDCON5=(1<<11)|(1<<9)|(1<<8)|(1<<3)|(BSWP<<1)|(HWSWP);

	LCDSADDR1=(((unsigned int)EG_LCD_Buffer>>22)<<21)|M5D((unsigned int)EG_LCD_Buffer>>1);
	LCDSADDR2=M5D( ((unsigned int)EG_LCD_Buffer+(EG_COLUMN*EG_ROW*2))>>1 );
	LCDSADDR3=(((EG_COLUMN-EG_COLUMN)/1)<<11)|(EG_COLUMN/1);  //EG_COLUMN;
	LCDINTMSK|=(3); // MASK LCD Sub Interrupt
    //TCONSEL|=((1<<4)|1); // Disable LCC3600, LPC3600
	TPAL=0; // Disable Temp Palette
	EG_LCDSetBacklight(70);
	EG_LCDPowerEnable(0,1);
	EG_LCDEnableVideoOutput(1);
	//EG_LCDClearBuffer();
}

void EG_LCDEnableVideoOutput(unsigned char on){
    if(on==1)
		LCDCON1|=1; // ENVID=ON
    else
		LCDCON1 =LCDCON1 & 0x3FFFE; // ENVID Off
}

void EG_LCDPowerEnable(int invpwren,int pwren){
    //GPG4 is setted as LCD_PWREN
    GPGUP=GPGUP&(~(1<<4))|(1<<4); // Pull-up disable
    GPGCON=GPGCON&(~(3<<8))|(3<<8); //GPG4=LCD_PWREN
    //Enable LCD POWER ENABLE Function
    LCDCON5=LCDCON5&(~(1<<3))|(pwren<<3);   // PWREN
    LCDCON5=LCDCON5&(~(1<<5))|(invpwren<<5);   // INVPWREN
}

void EG_LCDSetBacklight(unsigned int highRadio){
	if(!highRadio){
		GPBCON  = GPBCON & (~(3<<2)) | (1<<2) ;	//GPB1 output
		GPBDAT &= ~(1<<1);
		return;
	}
	GPBCON = GPBCON & (~(3<<2)) | (2<<2) ;		//GPB1 TOUT1
	
	if(highRadio > 100 )
		highRadio = 100 ;	
	
	TCON = TCON & (~(0xf<<8)) ;			// clear manual update bit, stop Timer1
	TCFG0 	&= 0xffffff00;					// set Timer 0&1 prescaler 0
	TCFG0 |= 15;							//prescaler = 15+1
	TCFG1 	&= 0xffffff0f;					// set Timer 1 MUX 1/16
	TCFG1  |= 0x00000030;					// set Timer 1 MUX 1/16

	TCNTB1	 = ( 100000000>>8 )/1000;		//if set inverter off, when TCNT2<=TCMP2, TOUT is high, TCNT2>TCMP2, TOUT is low
	TCMPB1  = ( TCNTB1*(100-highRadio))/100 ;	//if set inverter on,  when TCNT2<=TCMP2, TOUT is low,  TCNT2>TCMP2, TOUT is high
	TCON = TCON & (~(0xf<<8)) | (0x0e<<8) ;
	TCON = TCON & (~(0xf<<8)) | (0x0d<<8) ;		//enable backlight
}

void EG_LCDChangePLL(){
	//init FCLK=400M, so change MPLL first, Fin=12MHz
	//MPLL Control Register
	//	Mpll = (2 * m * Fin) / (p * 2*exp(s))
	//	m = (MDIV + 8), p = (PDIV + 2), s = SDIV
    MPLLCON = (92<<12) | (1<<4) | 1;
	//Register CLKDIVN   Bit          Description 
	//        DIVN_UPLL [3]     UCLK select register(UCLK must be 48MHz for USB)
	//							0: UCLK = UPLL clock
	// 							1: UCLK = UPLL clock / 2
	//							Set to 0, when UPLL clock is set as 48MHz
	//							Set to 1. when UPLL clock is set as 96MHz.
	//           HDIVN [2:1]    00 : HCLK = FCLK/1.
	//							01 : HCLK = FCLK/2.
	//							10 : HCLK = FCLK/4 when CAMDIVN[9] = 0.
	//								 HCLK= FCLK/8 when CAMDIVN[9] = 1.
	//							11 : HCLK = FCLK/3 when CAMDIVN[8] = 0.
	//								 HCLK = FCLK/6 when CAMDIVN[8] = 1.
	//			PDIVN [0]       0: PCLK has the clock same as the HCLK/1.
	//							1: PCLK has the clock same as the HCLK/2.
	//    HCLK = 2* PCLK     FCLK = 4* HCLK 
	CLKDIVN = (2<<1) | 1;
	//Now we have   FCLK = MPLLOutput = 400MHz  
	//				HCLK = 100MHz      PCLK = 50MHz
}

/*
	LCD Controller of S3C2440 is really useful and I like it  :)
	Here is how it works:
	    First you create a image buffer in RAM . In EmbeddedGUI,it is EG_LCD_Buffer of course.
		The next thing you need to do is to tell S3C2440 the timing sequence of your LCD Driver IC.
		Initialize the registers which define the vertical back porch,vertical front porch and so on....
		 _________________      ___________________                __________________
		|       RAM       |    |  LCD Controller   |              |                  |
		|                 |    |__________         |   VD[15:0]   |   LCD Driver IC  | 
		|  EG_LCD_Buffer  |    |          |        |<------------>|                  |
		|                 |<-->| LCD DMA  |        | TFT Signals  |                  |
		|_________________|    |__________|________|<------------>|__________________|

*/
//   Erase the LCD RAM,so the screen is clear
void EG_LCDClearScreen(void){
	EG_LCDClearBuffer();
}

//   copy the EG_LCD_Buffer into LCD RAM 
void EG_LCDFlushBuffer(void){
	//do nothing...
}

#endif  //EG_HX8238_LCD_DRIVER

#ifdef EG_SINGLE_COLOR
void EG_LCDClearBuffer(){
    unsigned int n,m;
    for(n=0;n<EG_SUB_ROW;n++){
      for(m=0;m<EG_COLUMN;m++){
          EG_LCD_Buffer[n][m]=0;
      }
    }
}
#else
#ifdef EG_COMPACT_ECOLOR 
void EG_LCDClearBuffer(){
    unsigned int n,m;
	EColor c=EColor(255,255);
    for(n=0;n<EG_ROW;n++){
		for(m=0;m<EG_COLUMN;m++){
		    EG_LCD_Buffer[n][m]=c;
		}
    }
}
#else
void EG_LCDClearBuffer(){
    unsigned int n,m;
	EColor c=EColor(255,255,255);
    for(n=0;n<EG_ROW;n++){
		for(m=0;m<EG_COLUMN;m++){
		    EG_LCD_Buffer[n][m]=c;
		}
    }
}
#endif  //EG_COMPACT_ECOLOR
#endif //EG_SINGLE_COLOR

#ifdef EG_SINGLE_COLOR

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
    return EG_LCD_Buffer[row][PixelColumn]&temp;
}

//   get the horizonal byte, PixelRow and PixelColumn are pixel index.
//   eg:   __|__  Pixel Position
//           |XXXXXXXX
//           return value
unsigned char EG_LCDGetHorizonalByte(unsigned int PixelRow,unsigned int PixelColumn){
	unsigned int row,pixels,col;
	unsigned char temp=0x00;
	unsigned char res=0x00;
    if((PixelRow>EG_ROW)||(PixelColumn>EG_COLUMN)){
        return 0;
    }
    row=PixelRow>>3;
    pixels=PixelRow&0x07;
	switch(pixels){
		case 0:
			temp=0x01;
			break;
		case 1:
			temp=0x02;
			break;
		case 2:
			temp=0x04;
			break;
		case 3:
			temp=0x08;
			break;
		case 4:
			temp=0x10;
			break;
		case 5:
			temp=0x20;
			break;
		case 6:
			temp=0x40;
			break;
		case 7:
			temp=0x80;
			break;
		default:
			temp=0x00;
			break;
	}
	for(col=PixelColumn;col<PixelColumn+8;col++){
		if(EG_LCD_Buffer[row][col]&temp)
			res|=0x01;
		if(col!=PixelColumn+7)	
			res=res<<1;
	}
	return res;
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
#endif  //EG_SINGLE_COLOR

#endif


