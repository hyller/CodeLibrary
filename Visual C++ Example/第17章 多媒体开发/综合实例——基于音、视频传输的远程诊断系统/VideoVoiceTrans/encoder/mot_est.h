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
//    Name    : mot_est.h
//
//
/////////////////////////////////////////////////////////////////////////////


#if !defined _MOT_EST_H
#define _MOT_EST_H


#include "Global.h"


void FindMB(int x, int y, unsigned int *image, unsigned int MB[16][16]);
void FullMotionEstimation(unsigned int *curr, unsigned int *prev_ipol, 
		     int seek_dist, MotionVector *current_MV, int x_curr, 
		     int y_curr);

int SAD_HalfPixelMacroblock(unsigned int *ii,
			    unsigned int *curr,
			    int pixels_on_line, int Min_SAD);

int SAD_HalfPixelMacroblock2(unsigned int *ii,
			    unsigned int *curr,
			    int pixels_on_line, int Min_SAD);
unsigned int *LoadArea(unsigned int *im, int x, int y, 
			int x_size, int y_size, int lx);


#endif
