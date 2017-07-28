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
//    Name    : countbit.cpp
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

 
/**********************************************************************
 *
 *	Name:		CountBitsMB
 *	Description:    counts bits used for MB info
 *	
 *	Input:	        Mode, COD, CBP, Picture and Bits structures
 *	Returns:       
 *	Side effects:
 *
 *	Date: 941129	Author: Karl.Lillevold@nta.no
 *
 ***********************************************************************/

#include "countbit.h"


void CountBitsMB(int Mode, int COD, int CBP, int CBPB, Pict *pic, Bits *bits)
{
  extern EHUFF *vlc_cbpy, *vlc_cbpcm, *vlc_cbpcm_intra;
  int cbpy, cbpcm, length;

  /* COD */
  if (Global::trace) {
    fprintf(Global::tf,"MB-nr: %d",pic->MB);
    if (pic->picture_coding_type == PCT_INTER)
      fprintf(Global::tf,"  COD: %d\n",COD);
  }
  if (pic->picture_coding_type == PCT_INTER) {
    mputv(1,COD);
    bits->COD++;
  }

  if (COD) 
    return;    /* not coded */

  /* CBPCM */
  cbpcm = Mode | ((CBP&3)<<4);


  if (Global::trace) {
    fprintf(Global::tf,"CBPCM (CBP=%d) (cbpcm=%d): ",CBP,cbpcm);
  }
  if (pic->picture_coding_type == PCT_INTRA) {
    length = Encode(cbpcm,vlc_cbpcm_intra);
  } else {
    length = Encode(cbpcm,vlc_cbpcm);
  }
  bits->CBPCM += length;

    
  /* CBPY */
  cbpy = CBP>>2;
  if (Mode == MODE_INTRA || Mode == MODE_INTRA_Q) /* Intra */
    cbpy = cbpy^15;
  if (Global::trace) {
    fprintf(Global::tf,"CBPY (CBP=%d) (cbpy=%d): ",CBP,cbpy);
  }
  length = Encode(cbpy, vlc_cbpy);
  bits->CBPY += length;
  

  return;
}


/**********************************************************************
 *
 *	Name:		CountBitsSlice
 *	Description:    couonts bits used for slice (GOB) info
 *	
 *	Input:	        slice no., quantizer
 *
 *	Date: 94????	Author: Karl.Lillevold@nta.no
 *
 ***********************************************************************/

int CountBitsSlice(int slice, int quant)
{
  int bits = 0;


  /* Picture Start Code */
  if (Global::trace)
    fprintf(Global::tf,"GOB sync (GBSC): ");
  mputv(PSC_LENGTH,PSC); /* PSC */
  bits += PSC_LENGTH;

  /* Group Number */
  if (Global::trace)
    fprintf(Global::tf,"GN: ");
  mputv(5,slice);
  bits += 5;

  /* GOB Sub Bitstream Indicator */
  /* if CPM == 1: read 2 bits GSBI */
  /* not supported in this version */

  /* GOB Frame ID */
  if (Global::trace)
    fprintf(Global::tf,"GFID: ");
  mputv(2, 0);  
  /* NB: in error-prone environments this value should change if 
     PTYPE in picture header changes. In this version of the encoder
     PTYPE only changes when PB-frames are used in the following cases:
     (i) after the first intra frame
     (ii) if the distance between two P-frames is very large 
     Therefore I haven't implemented this GFID change */
  /* GFID is not allowed to change unless PTYPE changes */
  bits += 2;

  /* Gquant */
  if (Global::trace)
    fprintf(Global::tf,"GQUANT: ");
  mputv(5,quant);
  bits += 5;

  return bits;
}


/**********************************************************************
 *
 *	Name:		CountBitsCoeff
 *	Description:	counts bits used for coeffs
 *	
 *	Input:		qcoeff, coding mode CBP, bits structure, no. of 
 *                      coeffs
 *			
 *	Returns:	struct with no. of bits used
 *	Side effects:	
 *
 *	Date: 940111	Author:	Karl.Lillevold@nta.no
 *
 ***********************************************************************/

void CountBitsCoeff(int *qcoeff, int Mode, int CBP, Bits *bits, int ncoeffs)

{
  
  int i;

  if (Mode == MODE_INTRA) {
    for (i = 0; i < 4; i++) {
      bits->Y += CodeCoeff(Mode, qcoeff,i,ncoeffs);
    }
    for (i = 4; i < 6; i++) {
      bits->C += CodeCoeff(Mode, qcoeff,i,ncoeffs);
    }
  }
  else {
    for (i = 0; i < 4; i++) {
      if ((i==0 && CBP&32) || 
	  (i==1 && CBP&16) ||
	  (i==2 && CBP&8) || 
	  (i==3 && CBP&4) || 
	  (i==4 && CBP&2) ||
	  (i==5 && CBP&1)) {
	bits->Y += CodeCoeff(Mode, qcoeff, i, ncoeffs);
      }
    }
    for (i = 4; i < 6; i++) {
      if ((i==0 && CBP&32) || 
	  (i==1 && CBP&16) ||
	  (i==2 && CBP&8) || 
	  (i==3 && CBP&4) || 
	  (i==4 && CBP&2) ||
	  (i==5 && CBP&1)) {
	bits->C += CodeCoeff(Mode, qcoeff, i, ncoeffs);
      }
    }
  }
  return;
}
  
int CodeCoeff(int Mode, int *qcoeff, int block, int ncoeffs)
{
  int j, bits;
  int prev_run, run, prev_level, level, first;
  int prev_ind, ind, prev_s, s, length;

  extern EHUFF *vlc_3d;

  run = bits = 0;
  first = 1;
  prev_run = prev_level = prev_ind = level = s = prev_s = ind = 0;
  
  for (j = block*ncoeffs; j< (block + 1)*ncoeffs; j++) {
    /* Do this block's DC-coefficient first */
    if (!(j%ncoeffs) && (Mode == MODE_INTRA)) {
      /* DC coeff */
      if (Global::trace) {
	fprintf(Global::tf,"DC: ");
      }
      if (qcoeff[block*ncoeffs] != 128)
	mputv(8,qcoeff[block*ncoeffs]);
      else
	mputv(8,255);
      bits += 8;
    }
    else {
      /* AC coeff */
      s = 0;
      /* Increment run if coeff is zero */
      if ((level = qcoeff[j]) == 0) {
	run++;
      }
      else {
	/* code run & level and count bits */
	if (level < 0) {
	  s = 1;
	  level = -level;
	}
	ind = level | run<<4;
	ind = ind | 0<<12; /* Not last coeff */

	if (!first) {
	  /* Encode the previous ind */
	  if (prev_level  < 13 && prev_run < 64) {
	    length = Encode(prev_ind,vlc_3d);

	  } else
	    length = 0;
	  if (length == 0) {  /* Escape coding */
	    if (Global::trace) {
	      fprintf(Global::tf,"Escape coding:\n");
	    }
	    if (prev_s == 1) {prev_level = (prev_level^0xff)+1;}
	    Encode(ESCAPE,vlc_3d);
	    mputv(1,0);
	    mputv(6,prev_run);
	    mputv(8,prev_level);
	    bits += 22;
	  }
	  else {
	    mputv(1,prev_s);
	    bits += length + 1;
	  }
	}
	prev_run = run; prev_s = s;
	prev_level = level; prev_ind = ind;

	run = first = 0;
      }
    }
  }
  /* Encode the last coeff */
  if (!first) {
    if (Global::trace) {
      fprintf(Global::tf,"Last coeff: ");
    }
    prev_ind = prev_ind | 1<<12;   /* last coeff */
    if (prev_level  < 13 && prev_run < 64) { 
      length = Encode(prev_ind,vlc_3d);
    } else
      length = 0;
    if (length == 0) {  /* Escape coding */
      if (Global::trace) {
	fprintf(Global::tf,"Escape coding:\n");
      }
      if (prev_s == 1) {prev_level = (prev_level^0xff)+1;}
      Encode(ESCAPE,vlc_3d);
      mputv(1,1);
      mputv(6,prev_run);
      mputv(8,prev_level);
      bits += 22;
    }
    else {
      mputv(1,prev_s);
      bits += length + 1;
    }
  }
  return bits;
}

 
/**********************************************************************
 *
 *	Name:		FindCBP
 *	Description:	Finds the CBP for a macroblock
 *	
 *	Input:		qcoeff and mode
 *			
 *	Returns:	CBP
 *	Side effects:	
 *
 *	Date: 940829	Author:	Karl.Lillevold@nta.no
 *
 ***********************************************************************/


int FindCBP(int *qcoeff, int Mode, int ncoeffs)
{
  
  int i,j;
  int CBP = 0;

				/* IF INTRABLOCK then intra =1 else 0 */
  int intra = (Mode == MODE_INTRA);

  /* Set CBP for this Macroblock */
  for (i = 0; i < 6; i++) {
				
    /* First time i = 0: j = 0 ..64-1  set bit 5 if coeff != 0
       Sec. time  i = 1; j = 64..128-1 set bit 4 if coeff != 0
       */
    /* OPTIMIZE: I think for i can be removed 
       and only values i=0 must be proessed */
    for (j = i*ncoeffs + intra; j < (i+1)*ncoeffs; j++) {
      if (qcoeff[j]) {
	if (i == 0) {CBP |= 32;}
	else if (i == 1) {CBP |= 16;}
	else if (i == 2) {CBP |= 8;}
	else if (i == 3) {CBP |= 4;}
	else if (i == 4) {CBP |= 2;}
	else if (i == 5) {CBP |= 1;}
	else {
	  fprintf(stderr,"Error in CBP assignment\n");
	  exit(-1);
	}
	break;
      }
    }
  }

  return CBP;
}


void CountBitsVectors(MotionVector *MV_ptr, Bits *bits, 
		      int x, int y, int Mode, int newgob, Pict *pic)
{
  int y_vec, x_vec;
  extern EHUFF *vlc_mv;
  int pmv0, pmv1;
  int start,stop,block;
  MotionVector *MV_xy;

  start = 0; stop = 0;
  MV_xy = MV_ptr + y*Global::mbc + x;

  for (block = start; block <= stop;  block++) {

    FindPMV(MV_ptr,x,y,&pmv0,&pmv1, block, newgob, 1);

    x_vec = (2*(*MV_xy).x + (*MV_xy).x_half) - pmv0;
    y_vec = (2*(*MV_xy).y + (*MV_xy).y_half) - pmv1;

    if (!Global::long_vectors) {
      if (x_vec < -32) x_vec += 64;
      else if (x_vec > 31) x_vec -= 64;

      if (y_vec < -32) y_vec += 64;
      else if (y_vec > 31) y_vec -= 64;
    }
    else {
      if (pmv0 < -31 && x_vec < -63) x_vec += 64;
      else if (pmv0 > 32 && x_vec > 63) x_vec -= 64;

      if (pmv1 < -31 && y_vec < -63) y_vec += 64;
      else if (pmv1 > 32 && y_vec > 63) y_vec -= 64;
    }
    
    if (x_vec < 0) x_vec += 64;
    if (y_vec < 0) y_vec += 64;

    if (Global::trace) {
      fprintf(Global::tf,"Vectors:\n");
    }
    bits->vec += Encode(x_vec,vlc_mv);
    bits->vec += Encode(y_vec,vlc_mv);

    if (Global::trace) {
      if (x_vec > 31) x_vec -= 64;
      if (y_vec > 31) y_vec -= 64;
      fprintf(Global::tf,"(x,y) = (%d,%d) - ",
	      (2*(*MV_xy).x + (*MV_xy).x_half),
	      (2*(*MV_xy).y + (*MV_xy).y_half));
      fprintf(Global::tf,"(Px,Py) = (%d,%d)\n", pmv0,pmv1);
      fprintf(Global::tf,"(x_diff,y_diff) = (%d,%d)\n",x_vec,y_vec);
    }
  }

  return;
}

void FindPMV(MotionVector *MV_ptr, int x, int y, 
	     int *pmv0, int *pmv1, int block, int newgob, int half_pel)
{
  int p1,p2,p3;
  int xin1,xin2,xin3;
  int yin1,yin2,yin3;
  int vec1,vec2,vec3;
  int l8,o8,or8;

  l8 = o8 = or8 = 0;
 
  vec1 = (l8 ? 2 : 0) ; yin1 = y  ; xin1 = x-1;
  vec2 = (o8 ? 3 : 0) ; yin2 = y-1; xin2 = x;
  vec3 = (or8? 3 : 0) ; yin3 = y-1; xin3 = x+1;

  if (half_pel) {

    p1 = (x > 0) ? 
      2*((*(MV_ptr + yin1*Global::mbc + xin1)).x) + (*(MV_ptr+ yin1*Global::mbc + xin1)).x_half : 0;
    p2 = (y > 0) ? 
      2*((*(MV_ptr + yin2*Global::mbc + xin2)).x) + (*(MV_ptr + yin2*Global::mbc + xin2)).x_half : 2*NO_VEC;
    if((y > 0) && (x < Global::mbc - 1))
      p3 = 2*((*(MV_ptr+yin3*Global::mbc + xin3)).x) + ((*(MV_ptr + yin3*Global::mbc + xin3)).x_half);
    else if(x == Global::mbc - 1)
      p3 = 0;
    else			/* y == 0 && x != Global::mbc - 1 */
      p3 = 2*NO_VEC;
    }
  else {
    p1 =  (x > 0) ? 
      (2*((*(MV_ptr + yin1*Global::mbc + xin1)).x)) : 0;
    p2 =  (y > 0) ? 
      (2*((*(MV_ptr + yin2*Global::mbc + xin2)).x)) : 2*NO_VEC;
    if((y > 0) && (x < Global::mbc - 1))
      p3 = 2*((*(MV_ptr + yin3*Global::mbc + xin3)).x);
    else if(x == Global::mbc - 1)
      p3 = 0;
    else			/* y == 0 && x != Global::mbc - 1 */
      p3 = 2*NO_VEC;
  }

  if (newgob && (block == 0 || block == 1 || block == 2))
    p2 = 2*NO_VEC;

  if (p2 == 2*NO_VEC) { p2 = p3 = p1; }

  *pmv0 = p1+p2+p3 - mmax(p1,mmax(p2,p3)) - mmin(p1,mmin(p2,p3));
  if (half_pel) {
    p1 =  (x > 0) ? 
      (2*((*(MV_ptr + yin1*Global::mbc + xin1)).y)) + ((*(MV_ptr + yin1*Global::mbc + xin1)).y_half) : 0;
    p2 =  (y > 0) ? 
      2*((*(MV_ptr + yin2*Global::mbc + xin2)).y) + ((*(MV_ptr + yin2*Global::mbc + xin2)).y_half) : 2*NO_VEC;

    if((y > 0) && (x < Global::mbc - 1))
      p3 = 2*((*(MV_ptr + yin3*Global::mbc + xin3)).y) + ((*(MV_ptr + Global::mbc*yin3 + xin3)).y_half);
    else if(x == Global::mbc - 1)
      p3 = 0;
    else			/* y == 0 && x != Global::mbc - 1 */
      p3 = 2*NO_VEC;
 
  }
  else {
    p1 = (x > 0) ?
      (2*((*(MV_ptr + yin1*Global::mbc + xin1)).y)) : 0;
    p2 =  (y > 0) ?
      (2*((*(MV_ptr + yin2*Global::mbc + xin2)).y)) : 2*NO_VEC;
    if((y > 0) && (x < Global::mbc - 1))
      p3 = 2*((*(MV_ptr + yin3*Global::mbc + xin3)).y);
    else if(x == Global::mbc - 1)
      p3 = 0;
    else			/* y == 0 && x != Global::mbc - 1 */
      p3 = 2*NO_VEC;
  }    

 
  if (newgob && (block == 0 || block == 1 || block == 2))
    p2 = 2*NO_VEC;

  if (p2 == 2*NO_VEC) { p2 = p3 = p1; }

  *pmv1 = p1+p2+p3 - mmax(p1,mmax(p2,p3)) - mmin(p1,mmin(p2,p3));
  
  return;
}

void ZeroBits(Bits *bits)
{
#ifndef MINIMAL_REPORT
  bits->Y = 0;
  bits->C = 0;
  bits->vec = 0;
  bits->CBPY = 0;
  bits->CBPCM = 0;
  bits->MODB = 0;
  bits->CBPB = 0;
  bits->COD = 0;
  bits->DQUANT = 0;
  bits->header = 0;
  bits->total = 0;
  bits->no_inter = 0;
  bits->no_inter4v = 0;
  bits->no_intra = 0;
#endif
  return;
}

void ZeroRes(Results *res)
{
#ifndef MINIMAL_REPORT
  res->SNR_l = 0;
  res->SNR_Cr = 0;
  res->SNR_Cb = 0;
  res->QP_mean = 0;
#endif
}

void AddBits(Bits *total, Bits *bits)
{
#ifndef MINIMAL_REPORT
  total->Y += bits->Y;
  total->C += bits->C;
  total->vec += bits->vec;
  total->CBPY += bits->CBPY;
  total->CBPCM += bits->CBPCM;
  total->MODB += bits->MODB;
  total->CBPB += bits->CBPB;
  total->COD += bits->COD;
  total->DQUANT += bits->DQUANT;
  total->header += bits->header;
  total->total += bits->total;
  total->no_inter += bits->no_inter;
  total->no_inter4v += bits->no_inter4v;
  total->no_intra += bits->no_intra;
#endif
  return;
}
void AddRes(Results *total, Results *res, Pict *pic)
{
#ifndef MINIMAL_REPORT
  total->SNR_l += res->SNR_l;
  total->SNR_Cr += res->SNR_Cr;
  total->SNR_Cb += res->SNR_Cb;
  total->QP_mean += pic->QP_mean;
#endif
  return;
}

void AddBitsPicture(Bits *bits)
{
#ifndef MINIMAL_REPORT
  bits->total = 
    bits->Y + 
    bits->C + 
    bits->vec +  
    bits->CBPY + 
    bits->CBPCM + 
    bits->MODB +
    bits->CBPB +
    bits->COD + 
    bits->DQUANT +
    bits->header ;
#endif
} 
void ZeroVec(MotionVector *MV)
{
  MV->x = 0;
  MV->y = 0;
  MV->x_half = 0;
  MV->y_half = 0;
  return;
}
void MarkVec(MotionVector *MV)
{
  MV->x = NO_VEC;
  MV->y = NO_VEC;
  MV->x_half = 0;
  MV->y_half = 0;
  return;
}

void CopyVec(MotionVector *MV2, MotionVector *MV1)
{
  MV2->x = MV1->x;
  MV2->x_half = MV1->x_half;
  MV2->y = MV1->y;
  MV2->y_half = MV1->y_half;
  return;
}

int EqualVec(MotionVector *MV2, MotionVector *MV1)
{
  if (MV1->x != MV2->x)
    return 0;
  if (MV1->y != MV2->y)
    return 0;
  if (MV1->x_half != MV2->x_half)
    return 0;
  if (MV1->y_half != MV2->y_half)
    return 0;
  return 1;
}

/**********************************************************************
 *
 *	Name:		CountBitsPicture(Pict *pic)
 *	Description:    counts the number of bits needed for picture
 *                      header
 *	
 *	Input:	        pointer to picture structure
 *	Returns:        number of bits
 *	Side effects:
 *
 *	Date: 941128	Author:Karl.Lillevold@nta.no
 *
 ***********************************************************************/

int CountBitsPicture(Pict *pic)
{
  int bits = 0;

 
  /* Picture start code */
  if (Global::trace) {
    fprintf(Global::tf,"picture_start_code: ");
  }
  mputv(PSC_LENGTH,PSC);
  bits += PSC_LENGTH;

  /* Group number */
  if (Global::trace) {
    fprintf(Global::tf,"Group number in picture header: ");
  }
  mputv(5,0); 
  bits += 5;
  
  /* Time reference */
  if (Global::trace) {
    fprintf(Global::tf,"Time reference: ");
  }
  mputv(8,pic->TR);
  bits += 8;

 /* bit 1 */
  if (Global::trace) {
    fprintf(Global::tf,"spare: ");
  }
  pic->spare = 1; /* always 1 to avoid start code emulation */
  mputv(1,pic->spare);
  bits += 1;

  /* bit 2 */
  if (Global::trace) {
    fprintf(Global::tf,"always zero for distinction with H.261\n");
  }
  mputv(1,0);
  bits += 1;
  
  /* bit 3 */
  if (Global::trace) {
    fprintf(Global::tf,"split_screen_indicator: ");
  }
  mputv(1,0);     /* no support for split-screen in this software */
  bits += 1;

  /* bit 4 */
  if (Global::trace) {
    fprintf(Global::tf,"document_camera_indicator: ");
  }
  mputv(1,0);
  bits += 1;

  /* bit 5 */
  if (Global::trace) {
    fprintf(Global::tf,"freeze_picture_release: ");
  }
  mputv(1,0);
  bits += 1;

  /* bit 6-8 */
  if (Global::trace) {
    fprintf(Global::tf,"source_format: ");
  }
  mputv(3,pic->source_format);
  bits += 3;

  /* bit 9 */
  if (Global::trace) {
    fprintf(Global::tf,"picture_coding_type: ");
  }
  mputv(1,pic->picture_coding_type);
  bits += 1;

  /* bit 10 */
  if (Global::trace) {
    fprintf(Global::tf,"Global::mv_outside_frame: ");
  }
  mputv(1,pic->unrestricted_mv_mode);  /* Unrestricted Motion Vector mode */
  bits += 1;

  /* bit 11 */
  if (Global::trace) {
    fprintf(Global::tf,"sac_coding: ");
  }
  mputv(1,0); /* Syntax-based Arithmetic Coding mode not used*/
  bits += 1;

  /* bit 12 */
  if (Global::trace) {
    fprintf(Global::tf,"adv_pred_mode: ");
  }
  mputv(1,Global::advanced); /* Advanced Prediction mode */
  bits += 1;

  /* bit 13 */
  if (Global::trace) {
    fprintf(Global::tf,"PB-coded: "); /* PB-frames mode */
  }
  mputv(1,pic->PB);
  bits += 1;


  /* QUANT */
  if (Global::trace) {
    fprintf(Global::tf,"QUANT: ");
  }
  mputv(5,pic->QUANT);
  bits += 5;

  /* Continuous Presence Multipoint (CPM) */
  mputv(1,0); /* CPM is not supported in this software */
  bits += 1;

  /* Picture Sub Bitstream Indicator (PSBI) */
  /* if CPM == 1: 2 bits PSBI */
  /* not supported */


  /* PEI (extra information) */
  if (Global::trace) {
    fprintf(Global::tf,"PEI: ");
  }
  /* "Encoders shall not insert PSPARE until specified by the ITU" */
  mputv(1,0); 
  bits += 1;

  /* PSPARE */
  /* if PEI == 1: 8 bits PSPARE + another PEI bit */
  /* not supported */

  return bits;
}

