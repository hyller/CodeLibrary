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
//    Name    : Tmndec.h
//    Details : Main entry point for decoder.
//
//    Usage : 
//			1) InitH263Decoder
//			2) Invoke DecompressFrame with parameters
//			      compressed data and output data pointers.
//			  Note > Output data must be large enough to hold RGB data.
//                 > Change the DecompressFrame function if you want 
//					 output in YUV420 format only. Just comment out conversion routine
//          3) Repeat the step 2 for each compressed frame , for exit do 4
//			4) ExitH263Decoder  .
//
/////////////////////////////////////////////////////////////////////////////





/************************************************************************
 *
 *  tmndec.h, TMN specific defines for tmndecode (H.263 decoder)
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


#if !defined(AFX_TMNDEC_H__C5DE7F23_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_TMNDEC_H__C5DE7F23_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



//#define GLOBAL

#include "DGlobal.h"
#include "GetBits.h"
#include "GetPic.h"
#include "GetHdr.h"
#include "convert.h"



void error (char *text);
void printbits (int code, int bits, int len);


/* private prototypes */
void InitH263Decoder();
int DecompressFrame(unsigned char *cdata,int size,unsigned char *outdata,int outsize);
void ExitH263Decoder();
static void initdecoder();


#endif // !defined(AFX_TMNDEC_H__C5DE7F23_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
