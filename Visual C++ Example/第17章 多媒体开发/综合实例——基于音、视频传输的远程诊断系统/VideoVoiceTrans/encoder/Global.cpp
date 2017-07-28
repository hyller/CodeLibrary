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
//    Name    : Global.cpp
//
//
/////////////////////////////////////////////////////////////////////////////

#include "Global.h"


// Global variable 
WriteByte WriteByteFunction;


int Global::advanced=0;
int Global::cpels=0;
//FILE * Global::debugf=0;
int Global::headerlength=0;
int Global::lines=0;
int Global::long_vectors=0;
int Global::mbc=0;
int Global::mbr=0;
FILE * Global::mv_file=0;
int Global::mv_outside_frame=0;
int Global::pb_frames=0;
int Global::pels=0;
int Global::search_p_frames=0;
size_t Global::sizeof_frame=0;
float Global::target_framerate=0;
FILE * Global::tf=0;
int Global::trace=0;
int Global::uskip=0;
int Global::vskip=0;
Pict* Global::pic=NULL;
