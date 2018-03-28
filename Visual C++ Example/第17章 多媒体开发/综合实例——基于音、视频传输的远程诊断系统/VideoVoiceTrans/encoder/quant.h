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
//    Name    : quant.h
//
//
/////////////////////////////////////////////////////////////////////////////

#if !defined _QUANT_H
#define _QUANT_H

#include "Global.h"


void Dequant(int *qcoeff, int *rcoeff, int QP, int I);
int QuantAndFindCBP(int *coeff, int *qcoeff, int QP, int I, int CBP_Mask);




#endif
