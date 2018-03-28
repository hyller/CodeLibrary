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
//    Name    : config.h
//
//
/////////////////////////////////////////////////////////////////////////////


#if !defined(AFX_CONFIG_H__9AA44A69_691B_11D6_889A_000B2B0F84B6__INCLUDED_)
#define AFX_CONFIG_H__9AA44A69_691B_11D6_889A_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define YES 1
#define NO 0

/*************************************************************************/

/* Default modes */
/* see http://www.nta.no/brukere/DVC/h263_options.html */

/* use Unrestricted Motion Vector mode as default (also option "-D") */
#define DEF_UMV_MODE   NO

/* use Syntax-based Arithmetic Coding mode as default (also option "-E") */
#define DEF_SAC_MODE   NO

/* use Advanced Prediction mode as default (also option "-F") */
#define DEF_ADV_MODE   NO

/* use PB-frames mode as default (also option "-G") */
#define DEF_PBF_MODE   NO

/*************************************************************************/


/* Default filenames */

/* default input sequence filename (also option "-i <filename>") */
#define DEF_SEQNAME   "/b2/qcif/claire.qcif"

/* default output bitstream filename (also option "-B <filename>") */
#define DEF_STREAMNAME   "./stream.263"

/* default filename for reconstructed sequence 
   (also option "-o <filename>") */
#define DEF_OUTFILENAME   "/b2/kol/out.qcif"

/* write difference image to file (also option "-w") */
#define DEF_WRITE_DIFF   NO

/* default filename for difference images if "-w" is used */
#define DEF_DIFFILENAME   "./diff.qcif"

/* added by Roalt */
#define DEF_MV_FILENAME   "./mvfile.dat"
#define DEF_SKIN_LIMIT	37
#define DEF_FACE_VALUE_LIMIT 132
/*************************************************************************/


/* Frame rate parameters */

/* default reference frame rate, 25 or 30 Hz 
 * (also option "-Z <n>") */
#define DEF_REF_FRAME_RATE   30.0

/* default number of skipped frames in original sequence compared to */
/* the reference picture rate ( also option "-O <n>" ) */
/* 3 means that the original sequence is grabbed at 6.25/7.5 Hz */
/* 0 means that the original sequence is grabbed at 25.0/30.0 Hz */
#define DEF_ORIG_SKIP      0

/* default skipped frames between encoded frames (P or B) */
/* reference is original sequence */
/* 2 means 8.33/10.0 fps encoded frame rate with 25.0/30.0 fps original */
/* 0 means 8.33/10.0 fps encoded frame rate with 8.33/10.0 fps original */
#define DEF_FRAMESKIP      2   

/*************************************************************************/

/* Search windows */


/* default integer pel search seek distance ( also option "-s <n> " ) */
#define DEF_SEEK_DIST   15   

/* default integer search window for 8x8 search centered 
   around 16x16 vector. When it is zero only half pel estimation
   around the integer 16x16 vector will be performed */
/* for best performance, keep this small, preferably zero,
   but do your own simulations if you want to try something else */
#define DEF_8X8_WIN     0

/* default search window for PB delta vectors */
/* keep this small also */
#define DEF_PBDELTA_WIN   2

/*************************************************************************/


/* Frame numbers to start and stop encoding at */

/* default frame number to start at (also option "-a <n>") */
#define DEF_START_FRAME   0

/* default frame number to stop at (also option "-b <n>") */
#define DEF_STOP_FRAME    0

/*************************************************************************/


/* Quantization parameters */

/* default inter quantization parameter (also option "-q <n>") */
#define DEF_INTER_QUANT   10

/* default intra quantization parameter (also option "-I <n>") */
#define DEF_INTRA_QUANT   10

/* BQUANT parameter for PB-frame coding 
 *   (n * QP / 4 ) 
 *
 *  BQUANT  n 
 *   0      5 
 *   1      6 
 *   2      7 
 *   3      8 
 * ( also option "-Q <BQUANT>" ) */
#define DEF_BQUANT   2


/*************************************************************************/

/* Miscellaneous */

/* write repeated reconstructed frames to disk (useful for variable
 * framerate, since sequence will be saved at 25 Hz) 
 * Can be changed at run-time with option "-m" */
#define DEF_WRITE_REPEATED   NO

/* write bitstream trace to files trace.intra / trace 
 * (also option "-t") */
#define DEF_WRITE_TRACE   NO

/* start rate control after DEF_START_RATE_CONTROL % of sequence
 * has been encoded. Can be changed at run-time with option "-R <n>" */
#define DEF_START_RATE_CONTROL   0

/* headerlength on concatenated 4:1:1 YUV input file 
 * Can be changed at run-time with option -e <headerlength> */
#define DEF_HEADERLENGTH   0

/* insert sync after each DEF_INSERT_SYNC for increased error robustness
 * 0 means do not insert extra syncs */
#define DEF_INSERT_SYNC   0

/*************************************************************************/


#endif // !defined(AFX_CONFIG_H__9AA44A69_691B_11D6_889A_000B2B0F84B6__INCLUDED_)
