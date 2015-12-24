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
	EGUIMacro.h
*/

//if you use the LCD Driver API, you should define it.
#define MCU

#ifdef MCU
	//select the MCU you used, so the IO.h could adapt to it.	
	//MSP430 series
	//#define MSP430
	//LPC22xx series        
	//#define LPC22XX
	//W78E5xx 8051based series
	#define W78E5XX
#endif

//select the LCD you used.
#define DOT_MATRIX_LCD
//#define WIN32_SIMULATE

//select the color system
#define EG_SINGLE_COLOR
//#define EG_RGB_COLOR

//the size of the dot matrix lcd
#define EG_COLUMN 128
// EG_SUB_COLUMN should be EG_COLUMN/2-1
#define EG_SUB_COLUMN 63
#define EG_ROW 64		
// EG_SUB_ROW should be EG_ROW / 8 
#define EG_SUB_ROW 8
	
//define it when omitting the font graphic functions.
#define EG_NO_FONT

//define it when you only want to use smallest font.
#define EG_SMALL_FONT_ONLY

//define it when using the cursor
//#define EG_CURSOR

//define it when using controls
//#define EG_CONTROL

//define it when you need to redraw the control in callback.
//#define EG_REDRAW_IN_CALLBACK_FUNC

//define it when you use the window hook function.
//#define EG_WINDOW_HOOK_FUNC

//define it when you use the desktop hook function.
//#define EG_DESKTOP_HOOK_FUNC

//define it when you use the default icon
//#define EG_DEFAULT_ICON

//define it when you will not use the EBitmap
#define EG_NO_BITMAP

#define INLINE 
