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
//    Name    : coder.h
//
//
/////////////////////////////////////////////////////////////////////////////


#if !defined _CODER_H
#define _CODER_H

#include "Global.h"


void ZeroMBlock(MB_Structure *data);
void CodeIntraH263(CParam *params, Bits *bits);
void CodeInterH263(CParam *params, Bits *bits);
//__inline__ void Clip(MB_Structure *data);
void Clip(MB_Structure *data);

int *MB_EncodeAndFindCBP(MB_Structure *mb_orig, int QP, int I, int *CBP);
int MB_Decode(int *qcoeff, MB_Structure *mb_recon, int QP, int I);
void FullMotionEstimatePicture(unsigned int *curr, unsigned int *prev, 
			       unsigned int *prev_ipol, int seek_dist, 
			       MotionVector *MV_ptr,
			       int advanced_method,
			       int *EncodeThisBlock);
void ReconCopyImage(int i, int j, unsigned int *recon, unsigned int *prev_recon);
void ReconImage (int i, int j, MB_Structure *data, unsigned int *recon);
void InterpolateImage(unsigned int *image,
			       unsigned int *ipol_image, 
			       int w, int h);
void FillLumBlock( int x, int y, unsigned int *image, MB_Structure *data);
void FillChromBlock(int x_curr, int y_curr, unsigned int *image,
		    MB_Structure *data);

#endif
