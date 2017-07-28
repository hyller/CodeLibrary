////////////////////////////////////////////////////////////////////////////
//
//
//    Project     : VideoNet version 1.1.
//    Description : Peer to Peer Video Conferencing over the LAN.
//	  Author      :	Nagareshwar Y Talekar ( nsry2002@yahoo.co.in)
//    Date        : 15-6-2004.
//
//    This is the modified version of tmndecode (H.263 decoder) 
//    written by Karl & Robert.It was in ANSI C. I have converted into C++
//    so that it can be integrated into any windows application. I have 
//    removed some of the files which had display and file storing 
//    functions.I have removed the unnecessary code and also added some
//    new files..
//	  Original library dealt with files. Input & Output , both were files.
//    I have done some major changes so that it can be used for real time 
//    decoding process. Now one can use this library for decoding H263 frames. 
//
//
//    File description : 
//    Name    : GetVlc.cpp
//
/////////////////////////////////////////////////////////////////////////////

/************************************************************************
 *
 *  getvlc.c, variable length decoding for tmndecode (H.263 decoder)
 *  Copyright (C) 1996  Telenor R&D, Norway
 *        Karl Olav Lillevold <Karl.Lillevold@nta.no>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Karl Olav Lillevold               <Karl.Lillevold@nta.no>
 *  Telenor Research and Development
 *  P.O.Box 83                        tel.:   +47 63 84 84 00
 *  N-2007 Kjeller, Norway            fax.:   +47 63 81 00 76
 *
 *  Robert Danielsen                  e-mail: Robert.Danielsen@nta.no
 *  Telenor Research and Development  www:    http://www.nta.no/brukere/DVC/
 *  P.O.Box 83                        tel.:   +47 63 84 84 00
 *  N-2007 Kjeller, Norway            fax.:   +47 63 81 00 76
 *  
 ************************************************************************/

/*
 * based on mpeg2decode, (C) 1994, MPEG Software Simulation Group
 * and mpeg2play, (C) 1994 Stefan Eckart
 *                         <stefan@lis.e-technik.tu-muenchen.de>
 *
 */


#include "GetVlc.h"


// Definitions of variables......

VLCtab TMNMVtab0[] = {
{3,4}, {61,4}, {2,3}, {2,3}, {62,3}, {62,3}, 
{1,2}, {1,2}, {1,2}, {1,2}, {63,2}, {63,2}, {63,2}, {63,2}
};

VLCtab TMNMVtab1[] = {
{12,10}, {52,10}, {11,10}, {53,10}, {10,9}, {10,9}, 
{54,9}, {54,9}, {9,9}, {9,9}, {55,9}, {55,9}, 
{8,9}, {8,9}, {56,9}, {56,9}, {7,7}, {7,7}, 
{7,7}, {7,7}, {7,7}, {7,7}, {7,7}, {7,7}, 
{57,7}, {57,7}, {57,7}, {57,7}, {57,7}, {57,7}, 
{57,7}, {57,7}, {6,7}, {6,7}, {6,7}, {6,7}, 
{6,7}, {6,7}, {6,7}, {6,7}, {58,7}, {58,7}, 
{58,7}, {58,7}, {58,7}, {58,7}, {58,7}, {58,7}, 
{5,7}, {5,7}, {5,7}, {5,7}, {5,7}, {5,7}, 
{5,7}, {5,7}, {59,7}, {59,7}, {59,7}, {59,7}, 
{59,7}, {59,7}, {59,7}, {59,7}, {4,6}, {4,6}, 
{4,6}, {4,6}, {4,6}, {4,6}, {4,6}, {4,6}, 
{4,6}, {4,6}, {4,6}, {4,6}, {4,6}, {4,6}, 
{4,6}, {4,6}, {60,6}, {60,6},{60,6},{60,6},
{60,6},{60,6},{60,6},{60,6},{60,6},{60,6},
{60,6},{60,6},{60,6},{60,6},{60,6},{60,6}
};

VLCtab TMNMVtab2[] = {
{32,12}, {31,12}, {33,12}, {30,11}, {30,11}, {34,11}, 
{34,11}, {29,11}, {29,11}, {35,11}, {35,11}, {28,11}, 
{28,11}, {36,11}, {36,11}, {27,11}, {27,11}, {37,11}, 
{37,11}, {26,11}, {26,11}, {38,11}, {38,11}, {25,11}, 
{25,11}, {39,11}, {39,11}, {24,10}, {24,10}, {24,10}, 
{24,10}, {40,10}, {40,10}, {40,10}, {40,10}, {23,10}, 
{23,10}, {23,10}, {23,10}, {41,10}, {41,10}, {41,10}, 
{41,10}, {22,10}, {22,10}, {22,10}, {22,10}, {42,10}, 
{42,10}, {42,10}, {42,10}, {21,10}, {21,10}, {21,10}, 
{21,10}, {43,10}, {43,10}, {43,10}, {43,10}, {20,10}, 
{20,10}, {20,10}, {20,10}, {44,10}, {44,10}, {44,10}, 
{44,10}, {19,10}, {19,10}, {19,10}, {19,10}, {45,10}, 
{45,10}, {45,10}, {45,10}, {18,10}, {18,10}, {18,10}, 
{18,10}, {46,10}, {46,10}, {46,10}, {46,10}, {17,10}, 
{17,10}, {17,10}, {17,10}, {47,10}, {47,10}, {47,10}, 
{47,10}, {16,10}, {16,10}, {16,10}, {16,10}, {48,10}, 
{48,10}, {48,10}, {48,10}, {15,10}, {15,10}, {15,10}, 
{15,10}, {49,10}, {49,10}, {49,10}, {49,10}, {14,10}, 
{14,10}, {14,10}, {14,10}, {50,10}, {50,10}, {50,10}, 
{50,10}, {13,10}, {13,10}, {13,10}, {13,10}, {51,10}, 
{51,10}, {51,10}, {51,10}
};


VLCtab MCBPCtab[] = {
{-1,0},
{255,9}, {52,9}, {36,9}, {20,9}, {49,9}, {35,8}, {35,8}, {19,8}, {19,8}, 
{50,8}, {50,8}, {51,7}, {51,7}, {51,7}, {51,7}, {34,7}, {34,7}, {34,7}, 
{34,7}, {18,7}, {18,7}, {18,7}, {18,7}, {33,7}, {33,7}, {33,7}, {33,7}, 
{17,7}, {17,7}, {17,7}, {17,7}, {4,6}, {4,6}, {4,6}, {4,6}, {4,6}, 
{4,6}, {4,6}, {4,6}, {48,6}, {48,6}, {48,6}, {48,6}, {48,6}, {48,6}, 
{48,6}, {48,6}, {3,5}, {3,5}, {3,5}, {3,5}, {3,5}, {3,5}, {3,5}, 
{3,5}, {3,5}, {3,5}, {3,5}, {3,5}, {3,5}, {3,5}, {3,5}, {3,5}, 
{32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, 
{32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, 
{32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {32,4}, 
{32,4}, {32,4}, {32,4}, {32,4}, {32,4}, {16,4}, {16,4}, {16,4}, {16,4}, 
{16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, 
{16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, 
{16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, {16,4}, 
{16,4}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, 
{2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, 
{2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, 
{2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, 
{2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, 
{2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, 
{2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, 
{2,3}, {2,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, 
{1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, 
{1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, 
{1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, 
{1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, 
{1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, 
{1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3}, 
{1,3}, {1,3}, {1,3}, 
};



VLCtab MCBPCtabintra[] = {
{-1,0},
{20,6}, {36,6}, {52,6}, {4,4}, {4,4}, {4,4}, 
{4,4}, {19,3}, {19,3}, {19,3}, {19,3}, {19,3}, 
{19,3}, {19,3}, {19,3}, {35,3}, {35,3}, {35,3}, 
{35,3}, {35,3}, {35,3}, {35,3}, {35,3}, {51,3}, 
{51,3}, {51,3}, {51,3}, {51,3}, {51,3}, {51,3}, 
{51,3},
};



VLCtab CBPYtab[48] =
{ {-1,0}, {-1,0}, {9,6}, {6,6}, {7,5}, {7,5}, {11,5}, {11,5},
  {13,5}, {13,5}, {14,5}, {14,5}, {15,4}, {15,4}, {15,4}, {15,4}, 
  {3,4}, {3,4}, {3,4}, {3,4}, {5,4},{5,4},{5,4},{5,4},
  {1,4}, {1,4}, {1,4}, {1,4}, {10,4}, {10,4}, {10,4}, {10,4},
  {2,4}, {2,4}, {2,4}, {2,4}, {12,4}, {12,4}, {12,4}, {12,4}, 
  {4,4}, {4,4}, {4,4}, {4,4}, {8,4}, {8,4}, {8,4}, {8,4}, 
};








int getTMNMV()
{
  int code;

  if (trace)
    fputs("motion_code (",dlog);

  if (getbits1())
  {
    if (trace)
      fputs("1): 0\n",dlog);
    return 0;
  }

  if ((code = showbits(12))>=512)
  {
    code = (code>>8) - 2;
    flushbits(TMNMVtab0[code].len);

    if (trace)
    {
      fputs("0",dlog);
      printbits(code+2,4,TMNMVtab0[code].len);
      //fputs("): %d\n", TMNMVtab0[code].val);
    }

    return TMNMVtab0[code].val;
  }

  if (code>=128)
  {
    code = (code>>2) -32;
    flushbits(TMNMVtab1[code].len);

    if (trace)
    {
      fputs("0",dlog);
      printbits(code+32,10,TMNMVtab1[code].len);
     // printf("): %d\n",TMNMVtab1[code].val);
    }

    return TMNMVtab1[code].val;
  }

  if ((code-=5)<0)
  {
    if (!quiet)
      fputs("Invalid motion_vector code\n",dlog);
    fault=1;
    return 0;
  }

  flushbits(TMNMVtab2[code].len);

  if (trace)
  {
    fputs("0",dlog);
    printbits(code+5,12,TMNMVtab2[code].len);
   // printf("): %d\n",TMNMVtab2[code].val);
  }

  return TMNMVtab2[code].val;
}


int getMCBPC()
{
  int code;

  if (trace)
    fputs("MCBPC (",dlog);

  code = showbits(9);

  if (code == 1) {
    /* macroblock stuffing */
    if (trace)
      fputs("000000001): stuffing\n",dlog);
    flushbits(9);
    return 255;
  }

  if (code == 0) {
    if (!quiet) 
      fputs("Invalid MCBPC code\n",dlog);
    fault = 1;
    return 0;
  }
    
  if (code>=256)
  {
    flushbits(1);
   // if (trace)
   //  fputs(1): %d\n",0);
    return 0;
  }
    
  flushbits(MCBPCtab[code].len);

  if (trace)
  {
    printbits(code,9,MCBPCtab[code].len);
    //printf("): %d\n",MCBPCtab[code].val);
  }

  return MCBPCtab[code].val;
}

int getMODB()
{
  int code;
  int MODB;

  if (trace)
    fputs("MODB (",dlog);

  code = showbits(2);

  if (code < 2) {
    if (trace)
      fputs("0): MODB = 0\n",dlog);
    MODB = 0;
    flushbits(1);
  }
  else if (code == 2) {
    if (trace)
      fputs("10): MODB = 1\n",dlog);
    MODB = 1;
    flushbits(2);
  }
  else { /* code == 3 */
    if (trace)
      fputs("11): MODB = 2\n",dlog);
    MODB = 2;
    flushbits(2);
  }
  return MODB;
}


int getMCBPCintra()
{
  int code;

  if (trace)
    fputs("MCBPCintra (",dlog);

  code = showbits(9);

  if (code == 1) {
    /* macroblock stuffing */
    if (trace)
      fputs("000000001): stuffing\n",dlog);
    flushbits(9);
    return 255;
  }

  if (code < 8) {
    if (!quiet) 
      fputs("Invalid MCBPCintra code\n",dlog);
    fault = 1;
    return 0;
  }

  code >>= 3;
    
  if (code>=32)
  {
    flushbits(1);
    //if (trace)
    //  printf("1): %d\n",3);
    return 3;
  }

  flushbits(MCBPCtabintra[code].len);

  if (trace)
  {
    printbits(code,6,MCBPCtabintra[code].len);
    //printf("): %d\n",MCBPCtabintra[code].val);
  }

  return MCBPCtabintra[code].val;
}

int getCBPY()
{
  int code;

  if (trace)
    fputs("CBPY (",dlog);

  code = showbits(6);
  if (code < 2) {
    if (!quiet) 
      fputs("Invalid CBPY code\n",dlog);
    fault = 1;
    return -1;
  }
    
  if (code>=48)
  {
    flushbits(2);
    //if (trace)
     // printf("11): %d\n",0);
    return 0;
  }

  flushbits(CBPYtab[code].len);

  if (trace)
  {
    printbits(code,6,CBPYtab[code].len);
    //printf("): %d\n",CBPYtab[code].val);
  }

  return CBPYtab[code].val;
}

