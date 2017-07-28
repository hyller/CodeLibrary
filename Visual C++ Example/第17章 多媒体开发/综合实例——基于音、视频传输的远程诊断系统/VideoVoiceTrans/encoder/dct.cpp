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
//    Name    : dct.cpp
//
//
/////////////////////////////////////////////////////////////////////////////

/*************************************************
 * libr263: fast H.263 encoder library
 *
 * Copyright (C) 1996, Roalt Aalmoes, Twente University
 * SPA multimedia group
 *
 * Based on Telenor TMN 1.6 encoder (Copyright (C) 1995, Telenor R&D)
 * created by Karl Lillevold 
 *
 * Author encoder: Roalt Aalmoes, <aalmoes@huygens.nl>
 * 
 * Date: 31-07-96
 **************************************************/

/*****************************************************************
 * Some routines are translated from Gisle Bjøntegaards's FORTRAN
 * routines by Robert.Danielsen@nta.no
 *
 *****************************************************************/

/*****************************************************************
 * This source includes sources from Berkeley's MPEG-1 encoder
 * which are copyright of Berkeley University, California, USA
 *****************************************************************/


#include "dct.h"


#include <math.h>

#ifndef PI
# ifdef M_PI
#  define PI M_PI
# else
#  define PI 3.14159265358979323846
# endif
#endif

int	zigzag[8][8] = {
  {0, 1, 5, 6,14,15,27,28},
  {2, 4, 7,13,16,26,29,42},
  {3, 8,12,17,25,30,41,43},
  {9,11,18,24,31,40,44,53},
  {10,19,23,32,39,45,52,54},
  {20,22,33,38,46,51,55,60},
  {21,34,37,47,50,56,59,61},
  {35,36,48,49,57,58,62,63},
};

#ifndef FASTDCT

/**********************************************************************
 *
 *	Name:		Dct
 *	Description:	Does dct on an 8x8 block, does zigzag-scanning of
 *			coefficients
 *
 *	Input:		64 pixels in a 1D array
 *	Returns:	64 coefficients in a 1D array
 *	Side effects:	
 *
 *	Date: 930128	Author: Robert.Danielsen@nta.no
 *
 **********************************************************************/

int Dct( int *block, int *coeff)
{
  int        j1, i, j, k;
  float	b[8];
  float 	b1[8];
  float 	d[8][8];
  float 	f0=.7071068,f1=.4903926,f2=.4619398,f3=.4157348,f4=.3535534;
  float 	f5=.2777851,f6=.1913417,f7=.0975452;

  for (i = 0, k = 0; i < 8; i++, k += 8) {
    for (j = 0; j < 8; j++) {
      b[j] = block[k+j];
    }
    /* Horizontal transform */
    for (j = 0; j < 4; j++) {
      j1 = 7 - j;
      b1[j] = b[j] + b[j1];
      b1[j1] = b[j] - b[j1];
    }
    b[0] = b1[0] + b1[3];
    b[1] = b1[1] + b1[2];
    b[2] = b1[1] - b1[2];
    b[3] = b1[0] - b1[3];
    b[4] = b1[4];
    b[5] = (b1[6] - b1[5]) * f0;
    b[6] = (b1[6] + b1[5]) * f0;
    b[7] = b1[7];
    d[i][0] = (b[0] + b[1]) * f4;
    d[i][4] = (b[0] - b[1]) * f4;
    d[i][2] = b[2] * f6 + b[3] * f2;
    d[i][6] = b[3] * f6 - b[2] * f2;
    b1[4] = b[4] + b[5];
    b1[7] = b[7] + b[6];
    b1[5] = b[4] - b[5];
    b1[6] = b[7] - b[6];
    d[i][1] = b1[4] * f7 + b1[7] * f1;
    d[i][5] = b1[5] * f3 + b1[6] * f5;
    d[i][7] = b1[7] * f7 - b1[4] * f1;
    d[i][3] = b1[6] * f3 - b1[5] * f5;
  }
  /* Vertical transform */
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 4; j++) {
      j1 = 7 - j;
      b1[j] = d[j][i] + d[j1][i];
      b1[j1] = d[j][i] - d[j1][i];
    }
    b[0] = b1[0] + b1[3];
    b[1] = b1[1] + b1[2];
    b[2] = b1[1] - b1[2];
    b[3] = b1[0] - b1[3];
    b[4] = b1[4];
    b[5] = (b1[6] - b1[5]) * f0;
    b[6] = (b1[6] + b1[5]) * f0;
    b[7] = b1[7];
    d[0][i] = (b[0] + b[1]) * f4;
    d[4][i] = (b[0] - b[1]) * f4;
    d[2][i] = b[2] * f6 + b[3] * f2;
    d[6][i] = b[3] * f6 - b[2] * f2;
    b1[4] = b[4] + b[5];
    b1[7] = b[7] + b[6];
    b1[5] = b[4] - b[5];
    b1[6] = b[7] - b[6];
    d[1][i] = b1[4] * f7 + b1[7] * f1;
    d[5][i] = b1[5] * f3 + b1[6] * f5;
    d[7][i] = b1[7] * f7 - b1[4] * f1;
    d[3][i] = b1[6] * f3 - b1[5] * f5;
  }
  /* Zigzag - scanning */
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      *(coeff + zigzag[i][j]) = (int)(d[i][j]);
    }
  }
  return 0;
}

#else
				/* Start of MPEG DCT operation */

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;

#ifdef LONG_32		
typedef unsigned long uint32;
typedef long int32;
#else
typedef unsigned int uint32;
typedef int int32;
#endif

/* this is ansi.h */


#undef _ANSI_ARGS_
#undef const

#ifdef NON_ANSI_COMPILER
#define _ANSI_ARGS_(x)       ()
#define CONST

#else

#define _ANSI_ARGS_(x)   x
#define CONST const

#ifdef __cplusplus
#define VARARGS (...)
#else
#define VARARGS ()
#endif

#endif


#define DCTSIZE     8   /* you really don't want to change this */
#define DCTSIZE_SQ 64   /* you really don't want to change this */

#define DCTSIZE2    DCTSIZE*DCTSIZE
typedef short DCTELEM;
typedef DCTELEM DCTBLOCK[DCTSIZE2];
typedef DCTELEM DCTBLOCK_2D[DCTSIZE][DCTSIZE];

/* We assume that right shift corresponds to signed division by 2 with
 * rounding towards minus infinity.  This is correct for typical "arithmetic
 * shift" instructions that shift in copies of the sign bit.  But some
 * C compilers implement >> with an unsigned shift.  For these machines you
 * must define RIGHT_SHIFT_IS_UNSIGNED.
 * RIGHT_SHIFT provides a proper signed right shift of an int32 quantity.
 * It is only applied with constant shift counts.  SHIFT_TEMPS must be
 * included in the variables of any routine using RIGHT_SHIFT.
 */

#ifdef RIGHT_SHIFT_IS_UNSIGNED
#define SHIFT_TEMPS     int32 shift_temp

/*
#define RIGHT_SHIFT(x,shft)  ((shift_temp = (x)) < 0 ? (shift_temp >> (shft)) |((~((int32) 0)) << (32-(shft))) : (shift_temp >> (shft)))
     
	 */   

#else
#define SHIFT_TEMPS
#define RIGHT_SHIFT(x,shft)     ((x) >> (shft))
#endif
          
#define LG2_DCT_SCALE 16

#define ONE	((int32) 1)

#define DCT_SCALE (ONE << LG2_DCT_SCALE)

/* In some places we shift the inputs left by a couple more bits, */
/* so that they can be added to fractional results without too much */
     /* loss of precision. */
#define LG2_OVERSCALE 2
#define OVERSCALE  (ONE << LG2_OVERSCALE)
#define OVERSHIFT(x)  ((x) <<= LG2_OVERSCALE)

/* Scale a fractional constant by DCT_SCALE */
#define FIX(x)	((int32) ((x) * DCT_SCALE + 0.5))

/* Scale a fractional constant by DCT_SCALE/OVERSCALE */
/* Such a constant can be multiplied with an overscaled input */
/* to produce something that's scaled by DCT_SCALE */
#define FIXO(x)  ((int32) ((x) * DCT_SCALE / OVERSCALE + 0.5))

/* Descale and correctly round a value that's scaled by DCT_SCALE */
#define UNFIX(x)   RIGHT_SHIFT((x) + (ONE << (LG2_DCT_SCALE-1)), LG2_DCT_SCALE)

/* Same with an additional division by 2, ie, correctly rounded UNFIX(x/2) */
#define UNFIXH(x)  RIGHT_SHIFT((x) + (ONE << LG2_DCT_SCALE), LG2_DCT_SCALE+1)

/* Take a value scaled by DCT_SCALE and round to integer scaled by OVERSCALE */
#define UNFIXO(x)  RIGHT_SHIFT((x) + (ONE << (LG2_DCT_SCALE-1-LG2_OVERSCALE)),LG2_DCT_SCALE-LG2_OVERSCALE)


/* Here are the constants we need */
/* SIN_i_j is sine of i*pi/j, scaled by DCT_SCALE */
/* COS_i_j is cosine of i*pi/j, scaled by DCT_SCALE */

#define SIN_1_4 FIX(0.707106781)
#define COS_1_4 SIN_1_4

#define SIN_1_8 FIX(0.382683432)
#define COS_1_8 FIX(0.923879533)
#define SIN_3_8 COS_1_8
#define COS_3_8 SIN_1_8

#define SIN_1_16 FIX(0.195090322)
#define COS_1_16 FIX(0.980785280)
#define SIN_7_16 COS_1_16
#define COS_7_16 SIN_1_16

#define SIN_3_16 FIX(0.555570233)
#define COS_3_16 FIX(0.831469612)
#define SIN_5_16 COS_3_16
#define COS_5_16 SIN_3_16

/* OSIN_i_j is sine of i*pi/j, scaled by DCT_SCALE/OVERSCALE */
/* OCOS_i_j is cosine of i*pi/j, scaled by DCT_SCALE/OVERSCALE */

#define OSIN_1_4 FIXO(0.707106781)
#define OCOS_1_4 OSIN_1_4

#define OSIN_1_8 FIXO(0.382683432)
#define OCOS_1_8 FIXO(0.923879533)
#define OSIN_3_8 OCOS_1_8
#define OCOS_3_8 OSIN_1_8

#define OSIN_1_16 FIXO(0.195090322)
#define OCOS_1_16 FIXO(0.980785280)
#define OSIN_7_16 OCOS_1_16
#define OCOS_7_16 OSIN_1_16

#define OSIN_3_16 FIXO(0.555570233)
#define OCOS_3_16 FIXO(0.831469612)
#define OSIN_5_16 OCOS_3_16
#define OCOS_5_16 OSIN_3_16
     
/*==================*
 * TYPE DEFINITIONS *
 *==================*/

/*  
 *  your basic Block type
 */
typedef int32 Block[DCTSIZE][DCTSIZE];
typedef int32 FlatBlock[DCTSIZE_SQ];
typedef	    int32   LumBlock[2*DCTSIZE][2*DCTSIZE];
typedef	    int32   ChromBlock[DCTSIZE][DCTSIZE];



/* Prototypes */
void reference_fwd_dct(Block block, Block dest);

void mp_fwd_dct_fast(Block data2d, Block dest2d);

/*void mp_fwd_dct_fast _ANSI_ARGS_((int16 *data2d, int16 *dest2d));
 */
void init_fdct(void);

/*
 * --------------------------------------------------------------
 *
 * mp_fwd_dct_fast --
 *
 * Perform the forward DCT on one block of samples.
 *
 * A 2-D DCT can be done by 1-D DCT on each row followed by 1-D DCT on each
 * column.
 *
 * Results: None
 *
 * Side effects: Overwrites the input data
 *
 * --------------------------------------------------------------
 */
/*
__inline__ voidmp_fwd_dct_fast(data2d, dest2d)
    Block data2d, dest2d;
    */
__inline__ void mp_fwd_dct_fast(Block data2d, Block dest2d)
{
    int32 *data = (int32 *) data2d;	/* this algorithm wants
					 * a 1-d array */
    int32 *dest = (int32 *) dest2d;
    int rowctr, columncounter;
    register int32 *inptr, *outptr;
    int32 workspace[DCTSIZE_SQ];
    int32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
    int32 tmp10, tmp11, tmp12, tmp13;
    int32 tmp14, tmp15, tmp16, tmp17;
    int32 tmp25, tmp26;

    SHIFT_TEMPS;

    /*
     * Each iteration of the inner loop performs one 8-point 1-D DCT. It
     * reads from a *row* of the input matrix and stores into a *column*
     * of the output matrix.  In the first pass, we read from the data[]
     * array and store into the local workspace[].  In the second pass,
     * we read from the workspace[] array and store into data[], thus
     * performing the equivalent of a columnar DCT pass with no variable
     * array indexing.
     */

    inptr = data;		/* initialize pointers for first pass */
    outptr = workspace;
   
    /* PASS ONE */
	
    for (rowctr = DCTSIZE - 1; rowctr >= 0; rowctr--) {
      /*
       * many tmps have nonoverlapping lifetime -- flashy
       * register colourers should be able to do this lot
       * very well
       */
      /* SHIFT_TEMPS */
      
      /* temp0 through tmp7:  -512 to +512 */
      /* if I-block, then -256 to +256 */
      tmp0 = inptr[7] + inptr[0];
      tmp1 = inptr[6] + inptr[1];
      tmp2 = inptr[5] + inptr[2];
      tmp3 = inptr[4] + inptr[3];
      tmp4 = inptr[3] - inptr[4];
      tmp5 = inptr[2] - inptr[5];
      tmp6 = inptr[1] - inptr[6];
      tmp7 = inptr[0] - inptr[7];
      
      /* tmp10 through tmp13:  -1024 to +1024 */
      /* if I-block, then -512 to +512 */
      tmp10 = tmp3 + tmp0;
      tmp11 = tmp2 + tmp1;
      tmp12 = tmp1 - tmp2;
      
      tmp13 = tmp0 - tmp3;
      
      outptr[0] = (int32) UNFIXH((tmp10 + tmp11) * SIN_1_4);
      outptr[DCTSIZE * 4] = (int32) UNFIXH((tmp10 - tmp11) * COS_1_4);
      
      outptr[DCTSIZE * 2] = (int32) UNFIXH(tmp13 * COS_1_8 + tmp12 * SIN_1_8);
      outptr[DCTSIZE * 6] = (int32) UNFIXH(tmp13 * SIN_1_8 - tmp12 * COS_1_8);
      
      tmp16 = UNFIXO((tmp6 + tmp5) * SIN_1_4);
      tmp15 = UNFIXO((tmp6 - tmp5) * COS_1_4);
      
      OVERSHIFT(tmp4);
      OVERSHIFT(tmp7);
      
      /*
       * tmp4, tmp7, tmp15, tmp16 are overscaled by
       * OVERSCALE
       */
      
      tmp14 = tmp4 + tmp15;
      tmp25 = tmp4 - tmp15;
      tmp26 = tmp7 - tmp16;
      tmp17 = tmp7 + tmp16;
      
      outptr[DCTSIZE] = (int32) UNFIXH(tmp17 * OCOS_1_16 + tmp14 * OSIN_1_16);
      outptr[DCTSIZE * 7] = (int32) UNFIXH(tmp17 * OCOS_7_16 - tmp14 * OSIN_7_16);
      outptr[DCTSIZE * 5] = (int32) UNFIXH(tmp26 * OCOS_5_16 + tmp25 * OSIN_5_16);
      outptr[DCTSIZE * 3] = (int32) UNFIXH(tmp26 * OCOS_3_16 - tmp25 * OSIN_3_16);
      
      inptr += DCTSIZE;	/* advance inptr to next row */
      outptr++;		/* advance outptr to next column */
    
    }

    /* end of pass; in case it was pass 1, set up for pass 2 */
    inptr = workspace;
    outptr = dest;

    columncounter = 0;
    /* PASS TWO */

    for (rowctr = DCTSIZE - 1; rowctr >= 0; rowctr--) {
      /*
       * many tmps have nonoverlapping lifetime -- flashy
       * register colourers should be able to do this lot
       * very well
       */
      /* SHIFT_TEMPS */
      
      /* temp0 through tmp7:  -512 to +512 */
      /* if I-block, then -256 to +256 */
      tmp0 = inptr[7] + inptr[0];
      tmp1 = inptr[6] + inptr[1];
      tmp2 = inptr[5] + inptr[2];
      tmp3 = inptr[4] + inptr[3];
      tmp4 = inptr[3] - inptr[4];
      tmp5 = inptr[2] - inptr[5];
      tmp6 = inptr[1] - inptr[6];
      tmp7 = inptr[0] - inptr[7];
      
      /* tmp10 through tmp13:  -1024 to +1024 */
      /* if I-block, then -512 to +512 */
      tmp10 = tmp3 + tmp0;
      tmp11 = tmp2 + tmp1;
      tmp12 = tmp1 - tmp2;
      
      tmp13 = tmp0 - tmp3;
      
      outptr[ zigzag[0][columncounter] ] = (int32) UNFIXH((tmp10 + tmp11) * SIN_1_4);
      outptr[ zigzag[4][columncounter] ] = (int32) UNFIXH((tmp10 - tmp11) * COS_1_4);
      
      outptr[ zigzag[2][columncounter] ] = (int32) UNFIXH(tmp13 * COS_1_8 + tmp12 * SIN_1_8);
      outptr[ zigzag[6][columncounter] ] = (int32) UNFIXH(tmp13 * SIN_1_8 - tmp12 * COS_1_8);
      
      tmp16 = UNFIXO((tmp6 + tmp5) * SIN_1_4);
      tmp15 = UNFIXO((tmp6 - tmp5) * COS_1_4);
      
      OVERSHIFT(tmp4);
      OVERSHIFT(tmp7);
      
      /*
       * tmp4, tmp7, tmp15, tmp16 are overscaled by
       * OVERSCALE
       */
      
      tmp14 = tmp4 + tmp15;
      tmp25 = tmp4 - tmp15;
      tmp26 = tmp7 - tmp16;
      tmp17 = tmp7 + tmp16;
      
      outptr[ zigzag[1][columncounter] ] = (int32) UNFIXH(tmp17 * OCOS_1_16 + tmp14 * OSIN_1_16);
      outptr[ zigzag[7][columncounter] ] = (int32) UNFIXH(tmp17 * OCOS_7_16 - tmp14 * OSIN_7_16);
      outptr[ zigzag[5][columncounter] ] = (int32) UNFIXH(tmp26 * OCOS_5_16 + tmp25 * OSIN_5_16);
      outptr[ zigzag[3][columncounter] ] = (int32) UNFIXH(tmp26 * OCOS_3_16 - tmp25 * OSIN_3_16);
      
      inptr += DCTSIZE;	/* advance inptr to next row */	
                   /*      outptr++;*/		/* advance outptr to next column */
      columncounter++;

    }
				/* END OF PASS TWO */


}

int Dct( int *block, int *coeff)
{

  mp_fwd_dct_fast( *(Block *) &block[0], *(Block *) &coeff[0]);

  return 0; 
}      

#endif /* End of ifnotdef FASTDCT */

#define FASTIDCT 10
#ifdef FASTIDCT

/**********************************************************************
 *
 *	Name:		idct
 *	Description:	Descans zigzag-scanned coefficients and does
 *			inverse dct on 64 coefficients
 *                      single precision floats
 *
 *	Input:		64 coefficients, block for 64 pixels
 *	Returns:    	0
 *	Side effects:	
 *
 *	Date: 930128	Author: Robert.Danielsen@nta.no
 *
 **********************************************************************/

int idct(int *coeff,int *block)
{
  int 	        j1, i, j;
  double 	b[8], b1[8], d[8][8];
  double 	f0=.7071068, f1=.4903926, f2=.4619398, f3=.4157348;
  double	        f4=.3535534;
  double 	f5=.2777851, f6=.1913417, f7=.0975452;
  double 	e, f, g, h;

  /* Horizontal */

  /* Descan coefficients first */

  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      b[j] = *( coeff + zigzag[i][j]);
    }
    e = b[1] * f7 - b[7] * f1;
    h = b[7] * f7 + b[1] * f1;
    f = b[5] * f3 - b[3] * f5;
    g = b[3] * f3 + b[5] * f5;

    b1[0] = (b[0] + b[4]) * f4;
    b1[1] = (b[0] - b[4]) * f4;
    b1[2] = b[2] * f6 - b[6] * f2;
    b1[3] = b[6] * f6 + b[2] * f2;
    b[4] = e + f;
    b1[5] = e - f;
    b1[6] = h - g;
    b[7] = h + g;
    
    b[5] = (b1[6] - b1[5]) * f0;
    b[6] = (b1[6] + b1[5]) * f0;
    b[0] = b1[0] + b1[3];
    b[1] = b1[1] + b1[2];
    b[2] = b1[1] - b1[2];
    b[3] = b1[0] - b1[3];

    for (j = 0; j < 4; j++) {
      j1 = 7 - j;
      d[i][j] = b[j] + b[j1];
      d[i][j1] = b[j] - b[j1];
    }
  }

  /* Vertical */
  
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      b[j] = d[j][i];
    }
    e = b[1] * f7 - b[7] * f1;
    h = b[7] * f7 + b[1] * f1;
    f = b[5] * f3 - b[3] * f5;
    g = b[3] * f3 + b[5] * f5;

    b1[0] = (b[0] + b[4]) * f4;
    b1[1] = (b[0] - b[4]) * f4;
    b1[2] = b[2] * f6 - b[6] * f2;
    b1[3] = b[6] * f6 + b[2] * f2;
    b[4] = e + f;
    b1[5] = e - f;
    b1[6] = h - g;
    b[7] = h + g;

    b[5] = (b1[6] - b1[5]) * f0;
    b[6] = (b1[6] + b1[5]) * f0;
    b[0] = b1[0] + b1[3];
    b[1] = b1[1] + b1[2];
    b[2] = b1[1] - b1[2];
    b[3] = b1[0] - b1[3];

    for (j = 0; j < 4; j++) {
      j1 = 7 - j;
      d[j][i] = b[j] + b[j1];
      d[j1][i] = b[j] - b[j1];
    }
  }

  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      *(block + i * 8 + j) = mnint(d[i][j]);
    }
  }
  return 0;
}

#elif VERYFASTIDCT
/*
 * tmndecode 
 * Copyright (C) 1995 Telenor R&D
 *                    Karl Olav Lillevold <kol@nta.no>                    
 *
 * based on mpeg2decode, (C) 1994, MPEG Software Simulation Group
 * and mpeg2play, (C) 1994 Stefan Eckart
 *                         <stefan@lis.e-technik.tu-muenchen.de>
 *
 */


/**********************************************************/
/* inverse two dimensional DCT, Chen-Wang algorithm       */
/* (cf. IEEE ASSP-32, pp. 803-816, Aug. 1984)             */
/* 32-bit integer arithmetic (8 bit coefficients)         */
/* 11 mults, 29 adds per DCT                              */
/*                                      sE, 18.8.91       */
/**********************************************************/
/* coefficients extended to 12 bit for IEEE1180-1990      */
/* compliance                           sE,  2.1.94       */
/**********************************************************/

/* this code assumes >> to be a two's-complement arithmetic */
/* right shift: (-2)>>1 == -1 , (-3)>>1 == -2               */


#define W1 2841 /* 2048*sqrt(2)*cos(1*pi/16) */
#define W2 2676 /* 2048*sqrt(2)*cos(2*pi/16) */
#define W3 2408 /* 2048*sqrt(2)*cos(3*pi/16) */
#define W5 1609 /* 2048*sqrt(2)*cos(5*pi/16) */
#define W6 1108 /* 2048*sqrt(2)*cos(6*pi/16) */
#define W7 565  /* 2048*sqrt(2)*cos(7*pi/16) */

/* private data */
static int iclip[1024]; /* clipping table */
static int *iclp;

/* private prototypes */
static void idctrow(int *blk);
static void idctcol(int *blk);

/* row (horizontal) IDCT
 *
 *           7                       pi         1
 * dst[k] = sum c[l] * src[l] * cos( -- * ( k + - ) * l )
 *          l=0                      8          2
 *
 * where: c[0]    = 128
 *        c[1..7] = 128*sqrt(2)
 */

static void idctrow(int *blk)
{
  int x0, x1, x2, x3, x4, x5, x6, x7, x8;

  /* shortcut */
  if (!((x1 = blk[4]<<11) | (x2 = blk[6]) | (x3 = blk[2]) |
        (x4 = blk[1]) | (x5 = blk[7]) | (x6 = blk[5]) | (x7 = blk[3])))
  {
    blk[0]=blk[1]=blk[2]=blk[3]=blk[4]=blk[5]=blk[6]=blk[7]=blk[0]<<3;
    return;
  }

  x0 = (blk[0]<<11) + 128; /* for proper rounding in the fourth stage */

  /* first stage */
  x8 = W7*(x4+x5);
  x4 = x8 + (W1-W7)*x4;
  x5 = x8 - (W1+W7)*x5;
  x8 = W3*(x6+x7);
  x6 = x8 - (W3-W5)*x6;
  x7 = x8 - (W3+W5)*x7;
  
  /* second stage */
  x8 = x0 + x1;
  x0 -= x1;
  x1 = W6*(x3+x2);
  x2 = x1 - (W2+W6)*x2;
  x3 = x1 + (W2-W6)*x3;
  x1 = x4 + x6;
  x4 -= x6;
  x6 = x5 + x7;
  x5 -= x7;
  
  /* third stage */
  x7 = x8 + x3;
  x8 -= x3;
  x3 = x0 + x2;
  x0 -= x2;
  x2 = (181*(x4+x5)+128)>>8;
  x4 = (181*(x4-x5)+128)>>8;
  
  /* fourth stage */
  blk[0] = (x7+x1)>>8;
  blk[1] = (x3+x2)>>8;
  blk[2] = (x0+x4)>>8;
  blk[3] = (x8+x6)>>8;
  blk[4] = (x8-x6)>>8;
  blk[5] = (x0-x4)>>8;
  blk[6] = (x3-x2)>>8;
  blk[7] = (x7-x1)>>8;
}

/* column (vertical) IDCT
 *
 *             7                         pi         1
 * dst[8*k] = sum c[l] * src[8*l] * cos( -- * ( k + - ) * l )
 *            l=0                        8          2
 *
 * where: c[0]    = 1/1024
 *        c[1..7] = (1/1024)*sqrt(2)
 */
__inline__ static void idctcol(int *blk)
{
  int x0, x1, x2, x3, x4, x5, x6, x7, x8;

  /* shortcut */
  if (!((x1 = (blk[32]<<8)) | (x2 = blk[48]) | (x3 = blk[16]) |
        (x4 = blk[8]) | (x5 = blk[56]) | (x6 = blk[40]) | (x7 = blk[24])))
  {
    blk[0]=blk[8]=blk[16]=blk[24]=blk[32]=blk[40]=blk[48]=blk[56]=
      iclp[(blk[0]+32)>>6];
    return;
  }

  x0 = (blk[8*0]<<8) + 8192;

  /* first stage */
  x8 = W7*(x4+x5) + 4;
  x4 = (x8+(W1-W7)*x4)>>3;
  x5 = (x8-(W1+W7)*x5)>>3;
  x8 = W3*(x6+x7) + 4;
  x6 = (x8-(W3-W5)*x6)>>3;
  x7 = (x8-(W3+W5)*x7)>>3;
  
  /* second stage */
  x8 = x0 + x1;
  x0 -= x1;
  x1 = W6*(x3+x2) + 4;
  x2 = (x1-(W2+W6)*x2)>>3;
  x3 = (x1+(W2-W6)*x3)>>3;
  x1 = x4 + x6;
  x4 -= x6;
  x6 = x5 + x7;
  x5 -= x7;
  
  /* third stage */
  x7 = x8 + x3;
  x8 -= x3;
  x3 = x0 + x2;
  x0 -= x2;
  x2 = (181*(x4+x5)+128)>>8;
  x4 = (181*(x4-x5)+128)>>8;
  
  /* fourth stage */
  blk[0] = iclp[(x7+x1)>>14];
  blk[8] = iclp[(x3+x2)>>14];
  blk[16] = iclp[(x0+x4)>>14];
  blk[24] = iclp[(x8+x6)>>14];
  blk[32] = iclp[(x8-x6)>>14];
  blk[40] = iclp[(x0-x4)>>14];
  blk[48] = iclp[(x3-x2)>>14];
  blk[56] = iclp[(x7-x1)>>14];
}

/* two dimensional inverse discrete cosine transform */
int idct(int *coeff, int *block)
{
  int i;
  extern int zigzag[8][8];
  int *block_ptr, *zigzag_ptr;

  block_ptr = block; zigzag_ptr = &(zigzag[0][0]);

  for (i = 0; i < 8; i++) {
    *(block_ptr++) = *(coeff + *(zigzag_ptr++));
    *(block_ptr++) = *(coeff + *(zigzag_ptr++));
    *(block_ptr++) = *(coeff + *(zigzag_ptr++));
    *(block_ptr++) = *(coeff + *(zigzag_ptr++));
    *(block_ptr++) = *(coeff + *(zigzag_ptr++));
    *(block_ptr++) = *(coeff + *(zigzag_ptr++));
    *(block_ptr++) = *(coeff + *(zigzag_ptr++));
    *(block_ptr++) = *(coeff + *(zigzag_ptr++));
    /* WAS:     block[j + i*8] = (int) *( coeff + zigzag[i][j]); */
  }

  for (i=0; i<8; i++)
    idctrow(block+8*i);
  
  for (i=0; i<8; i++)
    idctcol(block+i);

  
  return 0;
}

void init_idct()
{
  int i;

  iclp = iclip+512;
  for (i= -512; i<512; i++)
    iclp[i] = (i<-256) ? -256 : ((i>255) ? 255 : i);
}


#else

/*  Perform IEEE 1180 reference (64-bit floating point, separable 8x1
 *  direct matrix multiply) Inverse Discrete Cosine Transform
*/


/* Here we use math.h to generate constants.  Compiler results may
   vary a little */


/* private data */

/* cosine transform matrix for 8x1 IDCT */
static double c[8][8];

/* initialize DCT coefficient matrix */

void init_idctref()
{
  int freq, time;
  double scale;

  for (freq=0; freq < 8; freq++)
  {
    scale = (freq == 0) ? sqrt(0.125) : 0.5;
    for (time=0; time<8; time++)
      c[freq][time] = scale*cos((PI/8.0)*freq*(time + 0.5));
  }
}

/* perform IDCT matrix multiply for 8x8 coefficient block */

void idctref(int *coeff, int *block)
{
  int i, j, k, v;
  double partial_product;
  double tmp[64];
  int tmp2[64];
  extern int zigzag[8][8];

  for (i=0; i<8; i++)
    for (j=0; j<8; j++)
      tmp2[j+i*8] = *(coeff + zigzag[i][j]);

  for (i=0; i<8; i++)
    for (j=0; j<8; j++)
    {
      partial_product = 0.0;

      for (k=0; k<8; k++)
        partial_product+= c[k][j]*tmp2[8*i+k];

      tmp[8*i+j] = partial_product;
    }

  /* Transpose operation is integrated into address mapping by switching 
     loop order of i and j */

  for (j=0; j<8; j++)
    for (i=0; i<8; i++)
    {
      partial_product = 0.0;

      for (k=0; k<8; k++)
        partial_product+= c[k][i]*tmp[8*k+j];

      v = floor(partial_product+0.5);
      block[8*i+j] = (v<-256) ? -256 : ((v>255) ? 255 : v);
    }


}
#endif
