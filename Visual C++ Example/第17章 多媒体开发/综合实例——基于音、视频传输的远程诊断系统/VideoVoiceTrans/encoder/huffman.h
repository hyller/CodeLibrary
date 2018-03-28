////////////////////////////////////////////////////////////////////////////
//
//
//    Project     : VideoNet version 1.1.
//    Description : Peer to Peer Video Conferencing over the LAN.
//	  Author      :	Nagareshwar Y Talekar ( nsry2002@yahoo.co.in)
//    Date        : 15-6-2004.
//
//    I have converted origional fast h.263 encoder library from C to C++ 
//	  so that it can be integrated into any windows application easily.
//	  I have removed some of unnecessary codes/files from the
//	  fast h263 library.Also moved definitions and declarations
//	  in their proper .h and .cpp files.
//
//    File description : 
//    Name    : huffman.h
//
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HUFFMAN_H__9AA44A62_691B_11D6_889A_000B2B0F84B6__INCLUDED_)
#define AFX_HUFFMAN_H__9AA44A62_691B_11D6_889A_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Global.h"

#define EHUFF struct Modified_Encoder_Huffman

EHUFF
{
  int n;
  int *Hlen;
  int *Hcode;
};

/* From huffman.c */
void InitHuff();
void FreeHuff();
void PrintEhuff();

EHUFF *MakeEhuff(int );
void FreeEhuff(EHUFF *eh);
void LoadETable(int *array,EHUFF *table);
int Encode(int val,EHUFF *huff);
void mputv(int n,int b);

/* From stream.c */
void mwopen();
void mwclose();
int zeroflush();
void mputv();
long mwtell();
void mwseek();

#endif // !defined(AFX_HUFFMAN_H__9AA44A62_691B_11D6_889A_000B2B0F84B6__INCLUDED_)
