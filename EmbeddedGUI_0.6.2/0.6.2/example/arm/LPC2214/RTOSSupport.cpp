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
	RTOSSupport.cpp
*/

//EmbeddedGUI includes
#include "LCDDriver.h"
#include "EControl.h"
#include "EFrame.h"

#ifdef FREERTOS_SUPPORT

//redraw is the highest priority
#define mainREDRAW_TASK_PRIORITY		( tskIDLE_PRIORITY + XXXXXXXXX )

// User global controls and windows variables here.

extern "C"{	 

#include "FreeRTOS.h"
#include "Task.h"
#include "Serial.h"

void vGUIRedraw( void * pvParameters );

void vGUIInit(void){

	//init the LCD 
	EG_LCDInit();
    // Clear the buffer, set the buffer to 0
    EG_LCDClearBuffer();
	//User Code Here,Init the controls,windows and desktop.
	
    // Global Redraw upon the buffer
	desk.GlobalRedraw();
	//create the redraw task
	xTaskCreate( vGUIRedraw, "Redraw", configMINIMAL_STACK_SIZE, NULL, mainREDRAW_TASK_PRIORITY, NULL );

}

void vGUIRedraw( void * pvParameters ){

	/* Parameters are not used. */
	( void ) pvParameters;

	portTickType xLastWakeTime;
	const portTickType xFrequency = 10;
	
	// Initialise the xLastWakeTime variable with the current time.
	xLastWakeTime = xTaskGetTickCount ();
	for( ;; ){
		// Wait for the next cycle.
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
		
		//redraw all the desktop here.
		desk.ScheduleRedraw();
	}
}

}


#endif  //FREERTOS_SUPPORT
