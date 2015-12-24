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
	EGUIMacro.h
*/

///<version>(current)
// [0.6.2]
///</version>

///<macro>(MCU)
///<summary>
//if you use the LCD Driver API, you should define it.
///</summary>	
//#define MCU
///</macro>

#ifdef MCU
//select the MCU you used, so the IO.h could adapt to it.	

///<macro>(MSP430)
///<summary>
	//MSP430 series
///</summary>	
	//#define MSP430
///</macro>

///<macro>(LPC22XX)
///<summary>
	//LPC22xx series        
///</summary>
	//#define LPC22XX
///</macro>

///<macro>(W78E5XX)
///<summary>
	//W78E5xx 8051based series
///</summary>
	//#define W78E5XX
///</macro>

///<macro>(S3C2440A)
///<summary>
	//S3C2440A ARM920T
///</summary>
//	#define S3C2440A	
///</macro>
	
#endif

///<macro>(DOT_MATRIX_LCD)
///<summary>
//select the LCD you used.
///</summary>
//#define DOT_MATRIX_LCD
///</macro>

///<macro>(WIN32_SIMULATE)
///<summary>
//select the LCD you used.
///</summary>
#define WIN32_SIMULATE
///</macro>

#ifdef DOT_MATRIX_LCD

///<macro>(EG_KS010X_LCD_DRIVER)
//#define EG_KS010X_LCD_DRIVER
///</macro>

///<macro>(EG_T6963C_LCD_DRIVER)
//#define EG_T6963C_LCD_DRIVER
///</macro>

///<macro>(EG_S6B33C_LCD_DRIVER)
//#define EG_S6B33C_LCD_DRIVER
///</macro>

///<macro>(EG_RA8803_LCD_DRIVER)
//#define EG_RA8803_LCD_DRIVER
///</macro>

///<macro>(EG_S1D13305_LCD_DRIVER)
//#define EG_S1D13305_LCD_DRIVER
///</macro>

///<macro>(EG_HX8238_LCD_DRIVER)
//#define EG_HX8238_LCD_DRIVER
///</macro>

#endif //DOT_MATRIX_LCD

///<macro>(EXTERNAL_LCD_DRIVER)
///<summary>
//user custom LCD driver
///</summary>
//#define EXTERNAL_LCD_DRIVER
///</macro>

///<macro>(EG_SINGLE_COLOR)
///<summary>
//select the color system
///</summary>
//#define EG_SINGLE_COLOR
///</macro>

///<macro>(EG_RGB_COLOR)
///<summary>
//select the color system
///</summary>
#define EG_RGB_COLOR
///</macro>

#ifdef EG_RGB_COLOR
///<macro>(EG_COMPACT_ECOLOR)
///<summary>
///EColor will only use two bytes.
///</summary>
//#define EG_COMPACT_ECOLOR
///</macro>
#endif  //EG_RGB_COLOR

#ifdef DOT_MATRIX_LCD
#ifdef EG_RGB_COLOR
///<macro>(EG_NO_EBUFFER)
///<summary>
/// Write LCD pixel data directly to driver IC
///</summary>
//#define EG_NO_EBUFFER
///</macro>
#endif  //EG_RGB_COLOR
#endif //DOT_MATRIX_LCD

///<macro>(EG_COLUMN)
///<summary>
//the size of the dot matrix lcd
///</summary>
#define EG_COLUMN 256
///</macro>

///<macro>(EG_SUB_COLUMN)
///<summary>
// EG_SUB_COLUMN should be EG_COLUMN/2-1
///</summary>
#define EG_SUB_COLUMN 127
///</macro>

///<macro>(EG_ROW)
#define EG_ROW 128		
///</macro>

///<macro>(EG_SUB_ROW)
///<summary>
// EG_SUB_ROW should be EG_ROW / 8 
///</summary>
#define EG_SUB_ROW 16
///</macro>

///<macro>(EG_NO_FONT)
///<summary>
//define it when omitting the font graphic functions.
///</summary>
//#define EG_NO_FONT
///</macro>

///<macro>(EG_SMALL_FONT_ONLY)
///<summary>
//define it when you only want to use smallest font.
///</summary>
//#define EG_SMALL_FONT_ONLY
///</macro>

///<macro>(EG_CURSOR)
///<summary>
//define it when using the cursor
///</summary>
#define EG_CURSOR
///</macro>

///<macro>(EG_CONTROL)
///<summary>
//define it when using controls
///</summary>
#define EG_CONTROL
///</macro>

///<macro>(EG_RICH_STYLE)
///<summary>
//define it when using rich style, cost more time to draw better control.
///</summary>
//#define EG_RICH_STYLE
///</macro>

#ifdef EG_RICH_STYLE
// make sure RGB color
#ifndef EG_RGB_COLOR
#define EG_RGB_COLOR
#endif  //EG_RGB_COLOR

// make sure font graphic functions are included.
#ifdef EG_NO_FONT
#undef EG_NO_FONT   
#endif //EG_NO_FONT

//make sure all fonts are included. 
#ifdef EG_SMALL_FONT_ONLY
#undef EG_SMALL_FONT_ONLY
#endif  //EG_SMALL_FONT_ONLY
#endif  //EG_RICH_STYLE

///<macro>(EG_EXTERN_DEFAULT_STYLE)
///<summary>
//define it when you don't want define EG_DefaultStyle in EControl.cpp
///</summary>
//#define EG_EXTERN_DEFAULT_STYLE
///</macro>

///<macro>(EG_REDRAW_IN_CALLBACK_FUNC)
///<summary>
//define it when you need to redraw the control in callback.
///</summary>
#define EG_REDRAW_IN_CALLBACK_FUNC
///</macro>
	
///<macro>(EG_WINDOW_HOOK_FUNC)
///<summary>
//define it when you use the window hook function.
///</summary>
#define EG_WINDOW_HOOK_FUNC
///</macro>

///<macro>(EG_DESKTOP_HOOK_FUNC)
///<summary>
//define it when you use the desktop hook function.
///</summary>
#define EG_DESKTOP_HOOK_FUNC
///</macro>

///<macro>(EG_DEFAULT_ICON)
///<summary>
//define it when you use the default icon
///</summary>
#define EG_DEFAULT_ICON
///</macro>

///<macro>(FREERTOS_SUPPORT)
///<summary>
//define it when you use the FreeRTOS.
///</summary>
//#define FREERTOS_SUPPORT
///</macro>

///<macro>(SERIAL_CURSOR_DEBUG)
///<summary>
//define it when you use the serial port cursor.
///</summary>
//#define SERIAL_CURSOR_DEBUG
///</macro>

///<macro>(EXTERNAL_HOOK)
///<summary>
//hook functions are defined by EGUI Designer.
///</summary>
//#define EXTERNAL_HOOK
///</macro>

///<macro>(INLINE)
#define INLINE __inline
///</macro>

#ifndef NULL
#define NULL 0
#endif

