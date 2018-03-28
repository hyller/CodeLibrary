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
//    Name    : rlib.h
//
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RLIB_H__9AA44A66_691B_11D6_889A_000B2B0F84B6__INCLUDED_)
#define AFX_RLIB_H__9AA44A66_691B_11D6_889A_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000




#include "Global.h"


/* As you can see, there are 2 different formats:
   - avaqcif format, U and V signed (not used in this distribution)
   - qcif format, U and V unsigned

   Also note that the data is received and stored as 8-bit characters,but
   is processed as 32-bit integers. This is done because the data can fit
   into 8-bit, but on most systems 8-bit operations are a LOT slower than
   32-bit operations.
*/

/* Format as expected by encoder/decoder */

/* Note that from AVA, the U and V values must be converted from signed to
   unsigned, like     U.new = (unsigned char) U.old + 128 
   (Not applicable for this distribution)
*/


/* Prototypes */
int ReadQCIF(FILE *f, struct qcif *aq);
int WriteQCIF(FILE *f, struct qcif *qc);
int ReadCIF(FILE *f, struct cif *aq);
int WriteCIF(FILE *f, struct cif *qc);
void my_usleep(unsigned int microseconds);




#endif // !defined(AFX_RLIB_H__9AA44A66_691B_11D6_889A_000B2B0F84B6__INCLUDED_)
