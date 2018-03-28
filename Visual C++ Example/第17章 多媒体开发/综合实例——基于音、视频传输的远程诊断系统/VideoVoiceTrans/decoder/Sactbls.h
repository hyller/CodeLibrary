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
//    Name    : Sactbls.h
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SACTBLS_H__C5DE7F2B_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_SACTBLS_H__C5DE7F2B_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


extern int cumf_COD[];
extern int cumf_MCBPC[];
extern int cumf_MCBPC_intra[];
extern int cumf_MODB[];
extern int cumf_YCBPB[];
extern int cumf_UVCBPB[];
extern int cumf_CBPY[];
extern int cumf_CBPY_intra[];
extern int cumf_DQUANT[];
extern int cumf_MVD[];
extern int cumf_INTRADC[];
extern int cumf_TCOEF1[];
extern int cumf_TCOEF2[];
extern int cumf_TCOEF3[];
extern int cumf_TCOEFr[];
extern int cumf_TCOEF1_intra[];
extern int cumf_TCOEF2_intra[];
extern int cumf_TCOEF3_intra[];
extern int cumf_TCOEFr_intra[];
extern int cumf_SIGN[];
extern int cumf_LAST[];
extern int cumf_LAST_intra[];
extern int cumf_RUN[];
extern int cumf_RUN_intra[];
extern int cumf_LEVEL[];
extern int cumf_LEVEL_intra[];



#endif // !defined(AFX_SACTBLS_H__C5DE7F2B_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
