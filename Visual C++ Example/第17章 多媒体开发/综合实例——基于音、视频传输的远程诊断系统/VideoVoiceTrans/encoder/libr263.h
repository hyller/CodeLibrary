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
//    Name    : libr263.h
//
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIBR263_H__9AA44A61_691B_11D6_889A_000B2B0F84B6__INCLUDED_)
#define AFX_LIBR263_H__9AA44A61_691B_11D6_889A_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Global.h"
#include "def.h"
#include "stream.h"
#include "huffman.h"
#include "coder.h"





/* Order of usage of lib263:
   1. Set CParams.format to some value and call InitH23Encoder(cparams).
   2. WriteByteFunction = OwnWriteFunction  (1 and 2 in arbitrary order)
   3. Set cparams and do CompressFrame(cparams) with INTRA encoding
   4. Set cparams and do CompressFrame(cparams) with either INTRA 
      or INTER encoding
   5. redo 4. or to stop do 6
   6. Finally close with ExitH263Encoder()
 */


/* Prototypes */
int CompressFrame(CParam *params, Bits *bits);
int InitH263Encoder(CParam *params);
void ExitH263Encoder(CParam *params);
void SkipH263Frames(int frames_to_skip);

/* Procedure to detect motion, expects param->EncodeThisBlock is set to
   array. 
   Advised values for threshold: mb_threholds = 2; pixel_threshold = 2 */
int FindMotion(CParam *params, int mb_threshold, int pixel_threshold);


static void init_motion_detection(void);
//__inline__ static int Check8x8(unsigned int *orig, 
//			       unsigned int *recon, int pos);

static int Check8x8(unsigned int *orig,unsigned int *recon, int pos);

static int HasMoved(int call_time,  void *real, void *recon, int x, int y);




#endif // !defined(AFX_LIBR263_H__9AA44A61_691B_11D6_889A_000B2B0F84B6__INCLUDED_)
