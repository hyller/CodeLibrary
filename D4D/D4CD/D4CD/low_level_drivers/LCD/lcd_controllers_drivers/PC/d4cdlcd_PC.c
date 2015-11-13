/**************************************************************************
* 
* Copyright 2014 by Petr Gargulak. eGUI/D4CD Community.
* Copyright 2011-2013 by Petr Gargulak. Freescale Semiconductor, Inc.
*
***************************************************************************
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License Version 3 
* or later (the "LGPL").
*
* As a special exception, the copyright holders of the D4CD project give you
* permission to link the D4CD sources with independent modules to produce an
* executable, regardless of the license terms of these independent modules,
* and to copy and distribute the resulting executable under terms of your 
* choice, provided that you also meet, for each linked independent module,
* the terms and conditions of the license of that module.
* An independent module is a module which is not derived from or based 
* on this library. 
* If you modify the D4CD sources, you may extend this exception 
* to your version of the D4CD sources, but you are not obligated 
* to do so. If you do not wish to do so, delete this
* exception statement from your version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* You should have received a copy of the GNU General Public License
* and the GNU Lesser General Public License along with this program.
* If not, see <http://www.gnu.org/licenses/>.
*
***************************************************************************//*!
*
* @file      d4cdlcd_Simulator.c
*
* @author    Petr Gargulak
* 
* @version   0.0.1.0
* 
* @date      Jan-6-2011
* 
* @brief     D4CD driver - template lcd driver source c file 
*
******************************************************************************/

#include "d4cd.h"            // include of all public items (types, function etc) of D4CD driver
#include "d4cd_lldapi.h"     // include non public low level driver interface header file (types, function prototypes, enums etc. )
#include "d4cd_private.h"    // include the private header file that contains perprocessor macros as D4CD_MK_STR
#include "stdio.h"
#include "windows.h"

// identification string of driver - must be same as name D4CDLCD_FUNCTIONS structure + "_ID"
// it is used for enable the code for compilation
#define d4cdlcd_Simulator_ID 1

static char str[D4CD_SCREEN_LINE_CNT][D4CD_SCREEN_CHAR_CNT + 1] = {0};
static char xx = 0;
static char yy = 0;

// copilation enable preprocessor condition
// the string d4cdlcd_hd44780_ID must be replaced by define created one line up
#if (D4CD_MK_STR(D4CD_LLD_LCD) == d4cdlcd_Simulator_ID)
  
  // include of low level driver heaser file
  // it will be included into wole project only in case that this driver is selected in main D4CD configuration file
  #include "d4cdlcd_pc.h"
  /******************************************************************************
  * Macros 
  ******************************************************************************/

  /******************************************************************************
  * Internal function prototypes 
  ******************************************************************************/

  static unsigned char D4CDLCD_Init_Simulator(void);
  static unsigned char D4CDLCD_GoTo_Simulator(unsigned char x, unsigned char y);
  static unsigned char D4CDLCD_Send_Char_Simulator(unsigned char value) ;
  static unsigned char D4CDLCD_Read_Char_Simulator(void);
  static unsigned char D4CDLCD_WriteUserChar_Simulator(unsigned char ix, unsigned char *pData);
  static unsigned char D4CDLCD_SetCursor(unsigned char enable, unsigned char blink);
  static void D4CDLCD_Delay_ms_Simulator(unsigned short period);
  static unsigned char D4CDLCD_DeInit_Simulator(void);

  /**************************************************************//*!
  *
  * Global variables
  *
  ******************************************************************/
  
  // the main structure that contains low level driver api functions
  // the name fo this structure is used for recognizing of configured low level driver of whole D4CD
  // so this name has to be used in main configuration header file of D4CD driver to enable this driver
  const D4CDLCD_FUNCTIONS d4cdlcd_Simulator =
  {
    D4CDLCD_Init_Simulator,
    D4CDLCD_GoTo_Simulator,
    D4CDLCD_Send_Char_Simulator,
    D4CDLCD_Read_Char_Simulator,
    D4CDLCD_WriteUserChar_Simulator,
    D4CDLCD_SetCursor,
    D4CDLCD_Delay_ms_Simulator,
    D4CDLCD_DeInit_Simulator,
  };

  /**************************************************************//*!
  *
  * Local variables
  *
  ******************************************************************/

  /**************************************************************//*!
  *
  * Functions bodies
  *
  ******************************************************************/

   
  //-----------------------------------------------------------------------------
  // FUNCTION:    D4CDLCD_Init_Simulator
  // SCOPE:       Low Level Driver API function
  // DESCRIPTION: The function is used for initialization of this low level driver 
  //              
  // PARAMETERS:  none
  //              
  // RETURNS:     result: 1 - Success
  //                      0 - Failed
  //-----------------------------------------------------------------------------  
  static unsigned char D4CDLCD_Init_Simulator(void)
  {
    LWord i;
    
    for(i = 0; i < D4CD_SCREEN_CHAR_CNT; i++)
    {
      str[0][i] = ' ';
      str[1][i] = ' ';
    }
    str[0][D4CD_SCREEN_CHAR_CNT] = 0;
    str[1][D4CD_SCREEN_CHAR_CNT] = 0;
    
    return 1;
  }
     
  //-----------------------------------------------------------------------------
  // FUNCTION:    D4CDLCD_DeInit_Simulator
  // SCOPE:       Low Level Driver API function
  // DESCRIPTION: The function is used for deinitialization of this low level driver 
  //              
  // PARAMETERS:  none
  //              
  // RETURNS:     result: 1 - Success
  //                      0 - Failed
   //-----------------------------------------------------------------------------  
  static unsigned char D4CDLCD_DeInit_Simulator(void)
  {
    return 1;
  }    
  
  
  //-----------------------------------------------------------------------------
  // FUNCTION:    D4CDLCD_GoTo_Simulator
  // SCOPE:       Low Level Driver API function
  // DESCRIPTION: The function sets start coordination in memory of LCD driver
  // 
  // PARAMETERS:  unsigned char x - left cordination 
  //              unsigned char y - top cordination
  //              
  // RETURNS:     result: 1 - Success
  //                      0 - Failed
    //----------------------------------------------------------------------------- 
  static unsigned char D4CDLCD_GoTo_Simulator(unsigned char x, unsigned char y)
  {
    if ( x < D4CD_SCREEN_CHAR_CNT && y <  D4CD_SCREEN_LINE_CNT )
    {
      xx = x;
      yy = y;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  
  void D4CDLCD_Flush_Simulator(void)
  {
     system("cls");
     puts(&str[0][0]);
     puts(&str[1][0]);
  }

  //-----------------------------------------------------------------------------
  // FUNCTION:    D4CDLCD_Send_Char_Simulator
  // SCOPE:       Low Level Driver API function
  // DESCRIPTION: The function send the one char into LCD  
  //
  // PARAMETERS:  unsigned char ch    char to print
  //
  // RETURNS:     result: 1 - Success
  //                      0 - Failed                
  //-----------------------------------------------------------------------------
  static unsigned char D4CDLCD_Send_Char_Simulator(unsigned char ch)
  {       
     str[yy][xx] = ch;
     xx++;

     D4CDLCD_Flush_Simulator();
     return 1;
  }
  

 
  //-----------------------------------------------------------------------------
  // FUNCTION:    D4CDLCD_Read_Char_Simulator
  // SCOPE:       Low Level Driver API function
  // DESCRIPTION: The function reads the one char from LCD (if this function is supported)  
  //
  // PARAMETERS:  none
  //
  // RETURNS:     unsigned char - the readed char
  //              
  //-----------------------------------------------------------------------------
  static unsigned char D4CDLCD_Read_Char_Simulator(void)
  {       
    return str[yy][xx];
  }
  
    //-----------------------------------------------------------------------------
  // FUNCTION:    D4CDLCD_WriteUserChar_Simulator
  // SCOPE:       Low Level Driver API function
  // DESCRIPTION: The function load new char into char LCD display
  // 
  // PARAMETERS:  unsigned char ix - internal index of user char table  
  //              unsigned char *pData - pointer of new char data
  //              
  // RETURNS:     result: 1 - Success
  //                      0 - Failed
    //----------------------------------------------------------------------------- 
  static unsigned char D4CDLCD_WriteUserChar_Simulator(unsigned char ix, unsigned char *pData)
  {
    return 0;
  }
  
  //-----------------------------------------------------------------------------
  // FUNCTION:    D4CDLCD_SetCursor
  // SCOPE:       Low Level Driver API function
  // DESCRIPTION: The function control cursor of LCD
  // 
  // PARAMETERS:  unsigned char enable - enable / disable cursor  
  //              unsigned char blink - set mode of cursor
  //              
  // RETURNS:     result: 1 - Success
  //                      0 - Failed
    //----------------------------------------------------------------------------- 
  static unsigned char D4CDLCD_SetCursor(unsigned char enable, unsigned char blink)
  {
    unsigned char data;
    
    data = 0x0c;
    
    if(enable)
      data |= 0x02;
    
    if(blink)
      data |= 0x01;
  
    return 1;
  }

  //-----------------------------------------------------------------------------
  // FUNCTION:    D4CDLCD_Delay_ms_Simulator
  // SCOPE:       Low Level Driver API function
  // DESCRIPTION: For do some small delays in ms
  //
  // PARAMETERS:  period - count of ms
  //              
  // RETURNS:     none
  //-----------------------------------------------------------------------------
  static void D4CDLCD_Delay_ms_Simulator(unsigned short period)
  {       

  }

#endif //(D4CD_MK_STR(D4CD_LLD_LCD) == d4cdlcd_Simulator_ID)
