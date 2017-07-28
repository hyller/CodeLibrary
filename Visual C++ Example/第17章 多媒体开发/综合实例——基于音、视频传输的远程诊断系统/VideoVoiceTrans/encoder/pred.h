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
//    Name    : pred.h
//
//
/////////////////////////////////////////////////////////////////////////////


#if !defined _PRED_H
#define _PRED_H

#include "Global.h"


MB_Structure *Predict_P(unsigned int *curr_image, unsigned int *prev_image,
			unsigned int *prev_ipol, int x, int y, 
			MotionVector *MV_ptr);

void DoPredChrom_P(int x_curr, int y_curr, int dx, int dy,
		   unsigned int *curr, unsigned int *prev, 
		   MB_Structure *pred_error);
void FindPred(int x, int y, MotionVector *fr, unsigned int *prev, 
	      int *pred); 

MB_Structure *MB_Recon_P(unsigned int *prev_image, unsigned int *prev_ipol,
			 MB_Structure *diff, int x_curr, int y_curr, 
			 MotionVector *MV_ptr);

void ReconLumBlock_P(int x, int y, MotionVector *fr,
		     unsigned int *prev, int *data);
void ReconChromBlock_P(int x_curr, int y_curr, int dx, int dy,
		       unsigned int *prev, MB_Structure *data);
void FindChromBlock_P(int x_curr, int y_curr, int dx, int dy,
		       unsigned int *prev, MB_Structure *data);
int ChooseMode(unsigned int *curr, int x_pos, int y_pos, int min_SAD);





#endif
