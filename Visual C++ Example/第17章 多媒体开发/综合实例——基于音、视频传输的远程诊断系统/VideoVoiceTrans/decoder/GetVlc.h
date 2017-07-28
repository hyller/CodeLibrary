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
//    Name    : GetVlc.h
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GETVLC_H__C5DE7F29_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_GETVLC_H__C5DE7F29_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DGlobal.h"
#include "GetBits.h"
#include "TmnDec.h"



int getTMNMV ();
int getMCBPC ();
int getMODB ();
int getMCBPCintra ();
int getCBPY ();




extern VLCtab TMNMVtab0[];

extern VLCtab TMNMVtab1[];
extern VLCtab TMNMVtab2[];

extern VLCtab MCBPCtab[];

extern VLCtab MCBPCtabintra[];

extern VLCtab CBPYtab[48];

#endif // !defined(AFX_GETVLC_H__C5DE7F29_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
