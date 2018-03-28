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
//    Name    : def.h
//
//
/////////////////////////////////////////////////////////////////////////////



#if !defined _DEF_H
#define _DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <sys/types.h>



// Simple macros....for mathematical function...

#define sign(a)  	((a) < 0 ? -1 : 1)
#define Int(a)          ((a) < 0 ? (int)(a-0.5) : (int)(a))
#define mnint(a)	((a) < 0 ? (int)(a - 0.5) : (int)(a + 0.5))
#define mfloor(a)       ((a) < 0 ? (int)(a - 0.5) : (int)(a))
#define mmax(a, b)  	((a) > (b) ? (a) : (b))
#define mmin(a, b)  	((a) < (b) ? (a) : (b))
#define limit(x) \
{ \
    if (x > 255) x = 255; \
    if (x <   0)   x = 0; \
}





/* This should not be changed */
#define MB_SIZE 16

/* Compression parameter structure */

#define CPARAM_INTER TRUE
#define CPARAM_INTRA FALSE
#define CPARAM_EXHAUSTIVE TRUE
#define CPARAM_LOGARITHMIC FALSE
#define CPARAM_ADVANCED TRUE
#define CPARAM_NOADVANCED FALSE

#define CPARAM_QCIF 0
#define CPARAM_CIF 1
#define CPARAM_4CIF 2
#define CPARAM_16CIF 3
#define CPARAM_SQCIF 4
#define CPARAM_OTHER 99

#define CPARAM_DEFAULT_INTER_Q 8
#define CPARAM_DEFAULT_INTRA_Q 8
#define CPARAM_DEFAULT_SEARCHWINDOW 3

#define CPARAM_DEFAULT_INTER CPARAM_INTRA
#define CPARAM_DEFAULT_SEARCH_METHOD CPARAM_LOGARITHMIC
#define CPARAM_DEFAULT_ADVANCED_METHOD CPARAM_NOADVANCED
#define CPARAM_DEFAULT_FORMAT CPARAM_QCIF




/* Definitions for AVA */


#define XTILESIZE 8
#define YTILESIZE 8

#define QCIF_YWIDTH 176
#define QCIF_YHEIGHT 144
#define QCIF_UWIDTH 88
#define QCIF_UHEIGHT 72
#define QCIF_VWIDTH 88
#define QCIF_VHEIGHT 72
#define QCIFXTILES 22
#define QCIFYTILES 18

#define SQCIF_YWIDTH 128
#define SQCIF_YHEIGHT 96

#define SQCIFXTILES 16
#define SQCIFYTILES 12

#define CIF4_YWIDTH 704
#define CIF4_YHEIGHT 576

#define CIF16_YWIDTH 1408
#define CIF16_YHEIGHT 1152


#define CIF_YWIDTH 352
#define CIF_YHEIGHT 288
#define CIF_UWIDTH 176
#define CIF_UHEIGHT 144
#define CIF_VWIDTH 176
#define CIF_VHEIGHT 144
#define CIFXTILES 44
#define CIFYTILES 36





#define YES 1
#define NO 0
#define DEF_UMV_MODE   NO
#define DEF_SAC_MODE   NO
#define DEF_ADV_MODE   NO
#define DEF_PBF_MODE   NO
#define DEF_ORIG_SKIP      0
#define DEF_FRAMESKIP      2   

/* headerlength on concatenated 4:1:1 YUV input file */
#define DEF_HEADERLENGTH   0


/* insert sync after each DEF_INSERT_SYNC for increased error robustness
 * 0 means do not insert extra syncs */
#define DEF_INSERT_SYNC   0


/* Parameters from TMN */
#define PREF_NULL_VEC 100
#define PREF_16_VEC 200
#define PREF_PBDELTA_NULL_VEC 50



#define PSC				1
#define PSC_LENGTH			17

#define ESCAPE                          7167

#define PCT_INTER                       1
#define PCT_INTRA                       0
#define ON                              1
#define OFF                             0

#define SF_SQCIF                        1  /* 001 */
#define SF_QCIF                         2  /* 010 */
#define SF_CIF                          3  /* 011 */
#define SF_4CIF                         4  /* 100 */
#define SF_16CIF                        5  /* 101 */

#define MODE_INTER                      0
#define MODE_INTER_Q                    1
#define MODE_INTER4V                    2
#define MODE_INTRA                      3
#define MODE_INTRA_Q                    4
#define MODE_SKIP			5 /* Created by Roalt */

#define PBMODE_NORMAL                   0
#define PBMODE_MVDB                     1
#define PBMODE_CBPB_MVDB                2

#define NO_VEC                          999

/* added by Roalt */
#define DEF_SPIRAL_SEARCH		0
#define DEF_LOGARITHMIC_SEARCH		1
#define DEF_WRITE_TRACE   NO

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE (1)
#endif



#ifndef FASTIDCT
/* global declarations for idctref */
void init_idctref (void);
void idctref (int *coeff, int *block);
#endif

#ifdef VERYFASTIDCT
void init_idct(void);
#endif

#endif
