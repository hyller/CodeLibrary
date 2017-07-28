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
//    Name    : GetPic.h
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GETPIC_H__C5DE7F28_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_GETPIC_H__C5DE7F28_6033_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DGlobal.h"
#include "Indices.h"
#include "Sactbls.h"
#include "GetBlk.h"
#include "GetVlc.h"
#include "Idctref.h"
#include "Idct.h"

/* public */
void getpicture (int *framenum);
void putlast (int framenum);



/* private */

static void getMBs (int framenum);
static void clearblock (int comp);
static int motion_decode (int vec,int pmv);
static int find_pmv (int x, int y, int block, int comp);
static void addblock (int comp, int bx, int by,int addflag);
static void reconblock_b (int comp,int bx,int by,int mode,int bdx, int bdy);
static void find_bidir_limits (int vec, int *start, int*stop, int nhv);
static void find_bidir_chroma_limits (int vec, int *start, int*stop);
static void make_edge_image  (unsigned char *src, unsigned char *dst, int width, int height, int edge);
void interpolate_image (unsigned char *in, unsigned char *out, int width, int height);


#endif // !defined(AFX_GETPIC_H__C5DE7F28_6033_11D6_889B_000B2B0F84B6__INCLUDED_)
