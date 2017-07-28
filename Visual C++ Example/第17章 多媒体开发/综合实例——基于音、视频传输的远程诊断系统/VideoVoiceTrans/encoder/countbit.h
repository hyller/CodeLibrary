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
//    Name    : countbit.h
//
//
/////////////////////////////////////////////////////////////////////////////


#if !defined _COUNTBIT_H
#define _COUNTBIT_H


#include "Global.h"
#include"huffman.h"
//#include"indices.h"


void ZeroBits(Bits *bits);
void ZeroRes(Results *res);
int FindCBP(int *qcoeff, int Mode, int ncoeffs);
void CountBitsVectors(MotionVector *MV_ptr, Bits *bits, 
		      int x, int y, int Mode, int newgob, Pict *pic);
void FindPMV(MotionVector *MV_ptr, int x, int y, 
	     int *p0, int *p1, int block, int newgob, int half_pel);
void CountBitsCoeff(int *qcoeff, int I, int CBP, Bits *bits, int ncoeffs);
int CodeCoeff(int Mode, int *qcoeff, int block, int ncoeffs);
int CountBitsPicture(Pict *pic);
void AddBitsPicture(Bits *bits);
void CountBitsMB(int Mode, int COD, int CBP, int CBPB, Pict *pic, Bits *bits);
int CountBitsSlice(int slice, int quant);
void ZeroVec(MotionVector *MV);
void MarkVec(MotionVector *MV);
void CopyVec(MotionVector *MV1, MotionVector *MV2);
int EqualVec(MotionVector *MV2, MotionVector *MV1);


#endif
