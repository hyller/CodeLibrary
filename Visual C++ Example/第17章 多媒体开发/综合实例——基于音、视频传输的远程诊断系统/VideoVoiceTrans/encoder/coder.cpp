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
//    Name    : coder.cpp
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

     
/* Modyfied by Roalt Aalmoes with better algorithms and performance
 * objectives
 *
 * Warning: Although I tried to remove all advanced options code,
 * there might still be some artifacts in the code. Please do not
 * blame me for not removing all of it. 
 * Removing all advanced and alternating quantization code was done
 * for performance reasons. I'm sorry these options are not 
 * implemented here, but see the tmn1.7 code for a slow functioning
 * advanced H.263 compression algorithm. 
 *****************************************************************/

/* Notes for clear code: */
/* var. j is used for row indexing of MB in frame */
/* var. i is used for column indexing of MB in frame */

/*  pic is declared global */
/* MV is changed: it is now a real array of MV instead of array of pointers
   to MV. Its range is also equal to MVs encoded, without border MVs 
   Advantages: No more mallocs and frees in the code, disadvantages: ?? */
/* PictImage structure is replaced by int pointer. Drawback: not flexible for
   other format. */

#include"coder.h"
#include "countbit.h"
#include "pred.h"
#include "quant.h"
#include "mot_est.h"
#include "dct.h"

/**********************************************************************
 *
 *	Name:		Clip
 *	Description:    clips recontructed data 0-255
 *	
 *	Input:	        pointer to recon. data structure
 *	Side effects:   data structure clipped
 *
 *	Date: 960715 	Author: Roalt Aalmoes
 *
 ***********************************************************************/

//__inline__ void Clip(MB_Structure *data) 
void Clip(MB_Structure *data) 
{
  int n;
  int *mb_ptr = (int *) data;
  for (n = 0; n < 256 + 64 + 64; n++) {
    *mb_ptr = mmin(255,mmax(0,*mb_ptr));
    mb_ptr++;
  }
}

/* Encodes one frame intra using params */

void CodeIntraH263(CParam *params, Bits *bits)
{
  unsigned int *new_recon;

  MB_Structure *data = (MB_Structure *)malloc(sizeof(MB_Structure));
  int *qcoeff;
  int Mode = MODE_INTRA;
  int CBP;
  int i,j;


  new_recon = params->recon;
  
  ZeroBits(bits);
  
  Global::pic->QUANT = params->Q_intra;
  Global::pic->picture_coding_type = PCT_INTRA;

  bits->header += CountBitsPicture(Global::pic);


  
  for ( j = 0; j < Global::mbr; j++) {

    /* insert sync in *every* slice if use_gobsync is chosen */
    if (Global::pic->use_gobsync && j != 0)
      bits->header += CountBitsSlice(j,params->Q_intra);
   
    for ( i = 0; i < Global::mbc; i++) {

      Global::pic->MB = i + j * Global::mbc;
      bits->no_intra++;

      FillLumBlock(i*MB_SIZE, j*MB_SIZE, params->data, data);
      FillChromBlock(i*MB_SIZE, j*MB_SIZE, params->data, data);
      qcoeff = MB_EncodeAndFindCBP(data, params->Q_intra, Mode, &CBP);

      /* Do standard VLC encoding */
      /* COD = 0 ,Every block is coded as Intra frame */
      CountBitsMB(Mode,0,CBP,0,Global::pic,bits);
      CountBitsCoeff(qcoeff, Mode, CBP,bits,64);
     
      MB_Decode(qcoeff, data, params->Q_intra, Mode);
      Clip(data);
      ReconImage(i,j,data,new_recon);
      free(qcoeff);
    }
  }
  Global::pic->QP_mean = params->Q_intra;

  params->recon = new_recon;

  AddBitsPicture(bits);
  free(data);
  return;
}

/**********************************************************************
 *
 *	Name:		MB_Encode
 *	Description:	DCT and quantization of Macroblocks
 *
 *	Input:		MB data struct, mquant (1-31, 0 = no quant),
 *			MB info struct
 *	Returns:	Pointer to quantized coefficients 
 *	Side effects:	
 *
 *	Date: 930128	Author: Robert.Danielsen@nta.no
 *
 **********************************************************************/
/* If you compare original quant with FindCBP, you see they both act
   on the same range of coefficients in the cases INTRA (1..63) or 
   INTER (0..63) */

int *MB_EncodeAndFindCBP(MB_Structure *mb_orig, int QP, int I, int *CBP)
{				
  int		i, j, k, l, row, col;
  int		fblock[64];
  int		coeff[384];
  int		*coeff_ind;
  int 	        *qcoeff;
  int		*qcoeff_ind;
  int CBP_Mask = 32;

  *CBP = 0;			/* CBP gives bit pattern of lowest 6 bits
				   that specify which coordinates are not 
				   zero. Bits 6 (32) to 2 (4) repr. four
				   8x8 Y parts of macroblock, while bits
				   1 (2) and 0 (1) repr. resp. the U and
				   V component */

  if ((qcoeff=(int *)malloc(sizeof(int)*384)) == 0) {
    fprintf(stderr,"mb_encode(): Couldn't allocate qcoeff.\n");
    exit(0);
  }

  coeff_ind = coeff;
  qcoeff_ind = qcoeff;
  for (k=0;k<16;k+=8) {
    for (l=0;l<16;l+=8) {
      for (i=k,row=0;row<64;i++,row+=8) {
#if LONGISDOUBLEINT
	for (j=l,col=0;col<8;j += 2,col +=2 ) {
	  *(long *) (fblock+row+col) = * (long *) &(mb_orig->lum[i][j]);
	}
#else
	for (j=l,col=0;col<8;j++ , col++ ) {
	  *(int *) (fblock+row+col) = * (int *) &(mb_orig->lum[i][j]);
	}
#endif

      }
      Dct(fblock,coeff_ind);
      *CBP |= QuantAndFindCBP(coeff_ind,qcoeff_ind,QP,I,CBP_Mask);
      coeff_ind += 64;
      qcoeff_ind += 64;
      CBP_Mask = CBP_Mask>>1;
    } /* end l */
  } /* End k */

  for (i=0;i<8;i++) {
#ifdef LONGISDOUBLEINT
    for (j=0;j<8;j += 2) {
      *(long *) (fblock+i*8+j) = *(long *) &(mb_orig->Cb[i][j]);
    }
#else
    for (j=0;j<8;j++) {
      *(int *) (fblock+i*8+j) = *(int *) &(mb_orig->Cb[i][j]);
    }    
#endif
  }
  Dct(fblock,coeff_ind);
  *CBP |= QuantAndFindCBP(coeff_ind,qcoeff_ind,QP,I,CBP_Mask /* i == 4 */); 
  coeff_ind += 64;
  qcoeff_ind += 64;
  CBP_Mask = CBP_Mask>>1;

  for (i=0;i<8;i++) {

#ifdef LONGISDOUBLEINT
    for (j=0;j<8;j += 2) {
      * (long *) (fblock+i*8+j) = *(long *) &(mb_orig->Cr[i][j]);
    }
#else
    for (j=0;j<8;j ++) {
      * (int *) (fblock+i*8+j) = *(int *) &(mb_orig->Cr[i][j]);
    }
#endif

  }
  Dct(fblock,coeff_ind);
  *CBP |= QuantAndFindCBP(coeff_ind,qcoeff_ind,QP,I, CBP_Mask /* i == 5 */); 
  
  return qcoeff;
}

/**********************************************************************
 *
 *	Name:		MB_Decode
 *	Description:	Reconstruction of quantized DCT-coded Macroblocks
 *
 *	Input:		Quantized coefficients, MB data
 *			QP (1-31, 0 = no quant), MB info block
 *	Returns:	int (just 0)
 *	Side effects:	
 *
 *	Date: 930128	Author: Robert.Danielsen@nta.no
 *
 **********************************************************************/

     
int MB_Decode(int *qcoeff, MB_Structure *mb_recon, int QP, int I)
{
  int	i, j, k, l, row, col;
  int	*iblock;
  int	*qcoeff_ind;
  int	*rcoeff, *rcoeff_ind;


  if ((iblock = (int *)malloc(sizeof(int)*64)) == NULL) {
    fprintf(stderr,"MB_Coder: Could not allocate space for iblock\n");
    exit(-1);
  }
  if ((rcoeff = (int *)malloc(sizeof(int)*384)) == NULL) {
    fprintf(stderr,"MB_Coder: Could not allocate space for rcoeff\n");
    exit(-1);
  }  

  /* For control purposes */
  /* Zero data */
  for (i = 0; i < 16; i++)

#ifdef LONGISDOUBLEINT
    for (j = 0; j < 8; j+=2)
      *(long *) &(mb_recon->lum[i][j]) = 0L;
#else
    for (j = 0; j < 8; j++)
      *(int *) &(mb_recon->lum[i][j]) = 0;
#endif

  for (i = 0; i < 8; i++) 
#ifdef LONGISDOUBLEINT
    for (j = 0; j < 8; j += 2) {
      *(long *) &(mb_recon->Cb[i][j]) = 0L;
      *(long *) &(mb_recon->Cr[i][j]) = 0L;
    }
#else
    for (j = 0; j < 8; j ++) {
      *(int *) &(mb_recon->Cb[i][j]) = 0;
      *(int *) &(mb_recon->Cr[i][j]) = 0;
    }
#endif

  qcoeff_ind = qcoeff;
  rcoeff_ind = rcoeff;

  for (k=0;k<16;k+=8) {
    for (l=0;l<16;l+=8) {
      Dequant(qcoeff_ind,rcoeff_ind,QP,I);

#ifdef STANDARDIDCT
  idctref(rcoeff_ind,iblock); 
#else
  idct(rcoeff_ind,iblock); 
#endif

      qcoeff_ind += 64;
      rcoeff_ind += 64;
      for (i=k,row=0;row<64;i++,row+=8) {
#ifdef LONGISDOUBLEINT
	for (j=l,col=0;col<8;j += 2,col += 2) {
	  *(long *) &(mb_recon->lum[i][j]) = * (long *) (iblock+row+col);
       	}
#else
	for (j=l,col=0;col<8; j++, col++) {
	  *(int *) &(mb_recon->lum[i][j]) = * (int *) (iblock+row+col);
       	}
#endif
      }
    }
  }
  Dequant(qcoeff_ind,rcoeff_ind,QP,I);

#ifdef STANDARDIDCT
  idctref(rcoeff_ind,iblock); 
#else
  idct(rcoeff_ind,iblock); 
#endif

  qcoeff_ind += 64;
  rcoeff_ind += 64;
  for (i=0;i<8;i++) {
#ifdef LONGISDOUBLEINT
    for (j=0;j<8;j +=2 ) {
      *(long *) &(mb_recon->Cb[i][j]) = *(long *) (iblock+i*8+j);
    }
#else
    for (j=0;j<8;j++ ) {
      *(int *) &(mb_recon->Cb[i][j]) = *(int *) (iblock+i*8+j);
    }
#endif
  }
  Dequant(qcoeff_ind,rcoeff_ind,QP,I);
#ifdef STANDARDIDCT
  idctref(rcoeff_ind,iblock); 
#else
  idct(rcoeff_ind,iblock); 
#endif

  for (i=0;i<8;i++) {
#ifdef LONGISDOUBLEINT
    for (j=0;j<8;j += 2) {
      *(long *) &(mb_recon->Cr[i][j]) = *(long *) (iblock+i*8+j);
    }
#else
    for (j=0;j<8;j++) {
      *(int *) &(mb_recon->Cr[i][j]) = *(int *) (iblock+i*8+j);
    }
#endif
  }
  free(iblock);
  free(rcoeff);
  return 0;
}


/**********************************************************************
 *
 *	Name:		FillLumBlock
 *	Description:   	Fills the luminance of one block of lines*pels
 *	
 *	Input:	      	Position, pointer to qcif, array to fill
 *	Returns:       	
 *	Side effects:	fills array
 *
 *	Date: 930129	Author: Karl.Lillevold@nta.no
 *
 ***********************************************************************/

void FillLumBlock( int x, int y, unsigned int *image, MB_Structure *data)
{
  int n, m;
				/* OPTIMIZE HERE */
  /* m -> int conversion is done here, so no long optimiz. possible */
  for (n = 0; n < MB_SIZE; n++)
    for (m = 0; m < MB_SIZE; m++)
      data->lum[n][m] = 
	(int) (*(image + x+m + (y+n)*Global::pels));
  return;
}

/**********************************************************************
 *
 *	Name:		FillChromBlock
 *	Description:   	Fills the chrominance of one block of qcif
 *	
 *	Input:	      	Position, pointer to qcif, array to fill
 *	Returns:       	
 *	Side effects:	fills array
 *                      128 subtracted from each
 *
 *	Date: 930129	Author: Karl.Lillevold@nta.no
 *
 ***********************************************************************/

void FillChromBlock(int x_curr, int y_curr, unsigned int *image,
		    MB_Structure *data)
{
  int n;
  register int m;

  int x, y;

  x = x_curr>>1;
  y = y_curr>>1;

  for (n = 0; n < (MB_SIZE>>1); n++)
    for (m = 0; m < (MB_SIZE>>1); m++) {
      data->Cr[n][m] = 
	(int) (*(image + Global::vskip + x+m + (y+n)*Global::cpels));
      data->Cb[n][m] = 
	(int) (*(image + Global::uskip + x+m + (y+n)*Global::cpels));
    }
  return;
}


/**********************************************************************
 *
 *	Name:		ZeroMBlock
 *	Description:   	Fills one MB with Zeros
 *	
 *	Input:	      	MB_Structure to zero out
 *	Returns:       	
 *	Side effects:	
 *
 *	Date: 940829	Author: Karl.Lillevold@nta.no
 *
 ***********************************************************************/

void ZeroMBlock(MB_Structure *data)
{
  int n;
  register int m;

  /* ALPHA optimization */
#ifdef LONGISDOUBLEINT
  for (n = 0; n < MB_SIZE; n++)
    for (m = 0; m < MB_SIZE; m +=2 )
      *(long *) &(data->lum[n][m]) = 0L;
  for (n = 0; n < (MB_SIZE>>1); n++)
    for (m = 0; m < (MB_SIZE>>1); m +=2 ) {
      *(long *) &(data->Cr[n][m]) = 0L;
      *(long *) &(data->Cb[n][m]) = 0L;
    }
#else
  for (n = 0; n < MB_SIZE; n++)
    for (m = 0; m < MB_SIZE; m++ )
      *(int *) &(data->lum[n][m]) = 0;
  for (n = 0; n < (MB_SIZE>>1); n++)
    for (m = 0; m < (MB_SIZE>>1); m++ ) {
      *(int *) &(data->Cr[n][m]) = 0;
      *(int *) &(data->Cb[n][m]) = 0;
    }
#endif
  return;
}

/**********************************************************************
 *
 *	Name:		ReconImage
 *	Description:	Puts together reconstructed image
 *	
 *	Input:		position of curr block, reconstructed
 *			macroblock, pointer to recontructed image
 *	Returns:
 *	Side effects:
 *
 *	Date: 930123  	Author: Karl.Lillevold@nta.no
 *
 ***********************************************************************/

void ReconImage (int i, int j, MB_Structure *data, unsigned int *recon)
{
  int n;
  int x_curr, y_curr;
  int *lum_ptr, *Cb_ptr, *Cr_ptr;
  unsigned int *recon_ptr, *recon_Cb_ptr, *recon_Cr_ptr;

 
  x_curr = i * MB_SIZE;
  y_curr = j * MB_SIZE;
  
  lum_ptr = &(data->lum[0][0]);
  recon_ptr = recon + x_curr + y_curr*Global::pels;

  /* Fill in luminance data */
  for (n = 0; n < MB_SIZE; n++) {
#ifdef LONGISDOUBLEINT
    * (long *) recon_ptr = * (long *) lum_ptr;
    recon_ptr += 2; lum_ptr += 2;
    * (long *) recon_ptr = * (long *) lum_ptr;
    recon_ptr += 2; lum_ptr += 2;
    * (long *) recon_ptr = * (long *) lum_ptr;
    recon_ptr += 2; lum_ptr += 2;
    * (long *) recon_ptr = * (long *) lum_ptr;
    recon_ptr += 2; lum_ptr += 2;
    * (long *) recon_ptr = * (long *) lum_ptr;
    recon_ptr += 2; lum_ptr += 2;
    * (long *) recon_ptr = * (long *) lum_ptr;
    recon_ptr += 2; lum_ptr += 2;
    * (long *) recon_ptr = * (long *) lum_ptr;
    recon_ptr += 2; lum_ptr += 2;
    * (long *) recon_ptr = * (long *) lum_ptr;
    recon_ptr += Global::pels - 14; lum_ptr += 2;
    /* Was: for every m = 0..15 :
     *(recon->lum + x_curr+m + (y_curr+n)*Global::pels) = *(lum_ptr++);
     */
#else
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;
    recon_ptr++; lum_ptr++;
    * (int *) recon_ptr = * (int *) lum_ptr;

    recon_ptr += Global::pels - 15; lum_ptr++;
#endif
  }

  recon_Cb_ptr = recon+Global::uskip+ (x_curr>>1) + (y_curr>>1)*Global::cpels;
  recon_Cr_ptr = recon+Global::vskip+ (x_curr>>1) + (y_curr>>1)*Global::cpels;
  Cb_ptr = &(data->Cb[0][0]);
  Cr_ptr = &(data->Cr[0][0]);

  /* Fill in chrominance data */
  for (n = 0; n < MB_SIZE>>1; n++) {
#ifdef LONGISDOUBLEINT
    * (long *) recon_Cb_ptr = * (long *) Cb_ptr;
    recon_Cb_ptr += 2; Cb_ptr += 2;
    * (long *) recon_Cr_ptr = * (long *) Cr_ptr;
    recon_Cr_ptr += 2; Cr_ptr += 2;
    * (long *) recon_Cb_ptr = * (long *) Cb_ptr;
    recon_Cb_ptr += 2; Cb_ptr += 2;
    * (long *) recon_Cr_ptr = * (long *) Cr_ptr;
    recon_Cr_ptr += 2; Cr_ptr += 2;
    * (long *) recon_Cb_ptr = * (long *) Cb_ptr;
    recon_Cb_ptr += 2; Cb_ptr += 2;
    * (long *) recon_Cr_ptr = * (long *) Cr_ptr;
    recon_Cr_ptr += 2; Cr_ptr += 2;
    * (long *) recon_Cb_ptr = * (long *) Cb_ptr;
    recon_Cb_ptr += Global::cpels - 6; Cb_ptr += 2;
    * (long *) recon_Cr_ptr = * (long *) Cr_ptr;
    recon_Cr_ptr += Global::cpels - 6; Cr_ptr += 2;
#else
    * (int *) recon_Cb_ptr = * (int *) Cb_ptr;
    recon_Cb_ptr++; Cb_ptr++;
    * (int *) recon_Cr_ptr = * (int *) Cr_ptr;
    recon_Cr_ptr++; Cr_ptr++;    
    * (int *) recon_Cb_ptr = * (int *) Cb_ptr;
    recon_Cb_ptr++; Cb_ptr++;
    * (int *) recon_Cr_ptr = * (int *) Cr_ptr;
    recon_Cr_ptr++; Cr_ptr++;    
    * (int *) recon_Cb_ptr = * (int *) Cb_ptr;
    recon_Cb_ptr++; Cb_ptr++;
    * (int *) recon_Cr_ptr = * (int *) Cr_ptr;
    recon_Cr_ptr++; Cr_ptr++;    
    * (int *) recon_Cb_ptr = * (int *) Cb_ptr;
    recon_Cb_ptr++; Cb_ptr++;
    * (int *) recon_Cr_ptr = * (int *) Cr_ptr;
    recon_Cr_ptr++; Cr_ptr++;   
    * (int *) recon_Cb_ptr = * (int *) Cb_ptr;
    recon_Cb_ptr++; Cb_ptr++;
    * (int *) recon_Cr_ptr = * (int *) Cr_ptr;
    recon_Cr_ptr++; Cr_ptr++;    
    * (int *) recon_Cb_ptr = * (int *) Cb_ptr;
    recon_Cb_ptr++; Cb_ptr++;
    * (int *) recon_Cr_ptr = * (int *) Cr_ptr;
    recon_Cr_ptr++; Cr_ptr++;    
    * (int *) recon_Cb_ptr = * (int *) Cb_ptr;
    recon_Cb_ptr++; Cb_ptr++;
    * (int *) recon_Cr_ptr = * (int *) Cr_ptr;
    recon_Cr_ptr++; Cr_ptr++;    

    * (int *) recon_Cb_ptr = * (int *) Cb_ptr;
    * (int *) recon_Cr_ptr = * (int *) Cr_ptr;

    recon_Cb_ptr += Global::cpels - 7; Cb_ptr ++;
    recon_Cr_ptr += Global::cpels - 7; Cr_ptr ++;
#endif
  }
  /* WAS:   
     for (m = 0; m < MB_SIZE>>1; m++) {
     *(recon->Cr + (x_curr>>1)+m + ((y_curr>>1)+n)*Global::cpels) = data->Cr[n][m];
     *(recon->Cb + (x_curr>>1)+m + ((y_curr>>1)+n)*Global::cpels) = data->Cb[n][m];
     }
     */
  return;
}

/**********************************************************************
 *
 *	Name:		ReconCopyImage
 *	Description:	Copies previous recon_image to current recon image
 *	
 *	Input:		position of curr block, reconstructed
 *			macroblock, pointer to recontructed image
 *	Returns:
 *	Side effects:
 *
 *	Date: 960423  	Author: Roalt Aalmoes
 *
 ***********************************************************************/

void ReconCopyImage (int i, int j, unsigned int *recon, unsigned int *prev_recon)
{
  int n;
  int x_curr, y_curr;
  unsigned int *lum_now, *lum_prev, *cb_now, *cr_now, *cb_prev, *cr_prev;

 
  x_curr = i * MB_SIZE;
  y_curr = j * MB_SIZE;

  lum_now = recon + x_curr + y_curr*Global::pels;
  lum_prev = prev_recon + x_curr + y_curr*Global::pels;

  /* Fill in luminance data */
  for (n = 0; n < 16; n++) {
#ifdef LONGISDOUBLEINT
    *(long *)(lum_now) = *(long *)(lum_prev);
    *(long *)(lum_now + 2) = *(long *)(lum_prev + 2);
    *(long *)(lum_now + 4) = *(long *)(lum_prev + 4);
    *(long *)(lum_now + 6) = *(long *)(lum_prev + 6);
    *(long *)(lum_now + 8) = *(long *)(lum_prev + 8);
    *(long *)(lum_now + 10) = *(long *)(lum_prev + 10);
    *(long *)(lum_now + 12) = *(long *)(lum_prev + 12);
    *(long *)(lum_now + 14) = *(long *)(lum_prev + 14);
#else
    *(int *)(lum_now) = *(int *)(lum_prev);
    *(int *)(lum_now + 1) = *(int *)(lum_prev + 1);

    *(int *)(lum_now + 2) = *(int *)(lum_prev + 2);
    *(int *)(lum_now + 3) = *(int *)(lum_prev + 3);
    *(int *)(lum_now + 4) = *(int *)(lum_prev + 4);
    *(int *)(lum_now + 5) = *(int *)(lum_prev + 5);
    *(int *)(lum_now + 6) = *(int *)(lum_prev + 6);
    *(int *)(lum_now + 7) = *(int *)(lum_prev + 7);
    *(int *)(lum_now + 8) = *(int *)(lum_prev + 8);
    *(int *)(lum_now + 9) = *(int *)(lum_prev + 9);
    *(int *)(lum_now + 10) = *(int *)(lum_prev + 10);
    *(int *)(lum_now + 11) = *(int *)(lum_prev + 11);
    *(int *)(lum_now + 12) = *(int *)(lum_prev + 12);
    *(int *)(lum_now + 13) = *(int *)(lum_prev + 13);
    *(int *)(lum_now + 14) = *(int *)(lum_prev + 14);
    *(int *)(lum_now + 15) = *(int *)(lum_prev + 15);

#endif
    lum_now += Global::pels;
    lum_prev += Global::pels;
     
  }


  cb_now = recon+Global::uskip + (x_curr>>1) + (y_curr>>1)*Global::cpels;
  cr_now = recon+Global::vskip + (x_curr>>1) + (y_curr>>1)*Global::cpels;
  cb_prev = prev_recon+Global::uskip+ (x_curr>>1) + (y_curr>>1)*Global::cpels;
  cr_prev = prev_recon+Global::vskip + (x_curr>>1) + (y_curr>>1)*Global::cpels;

  /* Fill in chrominance data */
  for (n = 0; n < (MB_SIZE>>1); n++) {
#ifdef LONGISDOUBLEINT
    *(long *)(cb_now) = *(long *)(cb_prev);
    *(long *)(cb_now + 2) = *(long *)(cb_prev + 2);
    *(long *)(cb_now + 4) = *(long *)(cb_prev + 4);
    *(long *)(cb_now + 6) = *(long *)(cb_prev + 6);
    cb_now += Global::cpels;
    cb_prev += Global::cpels;

    *(long *)(cr_now) = *(long *)(cr_prev);
    *(long *)(cr_now + 2) = *(long *)(cr_prev + 2);
    *(long *)(cr_now + 4) = *(long *)(cr_prev + 4);
    *(long *)(cr_now + 6) = *(long *)(cr_prev + 6);
    cr_now += Global::cpels;
    cr_prev += Global::cpels;
#else
    *(int *)(cb_now) = *(int *)(cb_prev);
    *(int *)(cb_now + 1) = *(int *)(cb_prev + 1);
    *(int *)(cb_now + 2) = *(int *)(cb_prev + 2);
    *(int *)(cb_now + 3) = *(int *)(cb_prev + 3);
    *(int *)(cb_now + 4) = *(int *)(cb_prev + 4);
    *(int *)(cb_now + 5) = *(int *)(cb_prev + 5);
    *(int *)(cb_now + 6) = *(int *)(cb_prev + 6);
    *(int *)(cb_now + 7) = *(int *)(cb_prev + 7);
    cb_now += Global::cpels;
    cb_prev += Global::cpels;

    *(int *)(cr_now) = *(int *)(cr_prev);
    *(int *)(cr_now + 1) = *(int *)(cr_prev + 1);
    *(int *)(cr_now + 2) = *(int *)(cr_prev + 2);
    *(int *)(cr_now + 3) = *(int *)(cr_prev + 3);
    *(int *)(cr_now + 4) = *(int *)(cr_prev + 4);
    *(int *)(cr_now + 5) = *(int *)(cr_prev + 5);
    *(int *)(cr_now + 6) = *(int *)(cr_prev + 6);
    *(int *)(cr_now + 7) = *(int *)(cr_prev + 7);
    cr_now += Global::cpels;
    cr_prev += Global::cpels;
#endif
  }

  return;
}


/**********************************************************************
 *
 *	Name:		InterpolateImage
 *	Description:    Interpolates a complete image for easier half
 *                      pel prediction
 *	
 *	Input:	        pointer to image structure
 *	Returns:        pointer to interpolated image
 *	Side effects:   allocates memory to interpolated image
 *
 *	Date: 950207 	Author: Karl.Lillevold@nta.no
 *            960207    Author: Roalt aalmoes
 ***********************************************************************/

void InterpolateImage(unsigned int *image, unsigned int *ipol_image, 
			       int width, int height)
{
  /* If anyone has better ideas to optimize this code, be my guest!
     note: assembly or some advanced bitshifts routine might do the trick...*/

  register unsigned int *ii, *oo, 
    *ii_new, 
    *ii_new_line2, 
    *oo_prev, 
    *oo_prev_line2;
  
  register int i,j;

  register unsigned int pix1,pix2,pix3,pix4;

  ii = ipol_image;
  oo = image;

  oo_prev = image;
  oo_prev_line2 = image + width;
  ii_new = ipol_image;
  ii_new_line2 = ipol_image + (width<<1);

  /* main image */
  for (j = 0; j < height-1; j++) {
				/* get Pix1 and Pix3, because they are
				   not known the first time */
    pix1 = *oo_prev;
    pix3 = *oo_prev_line2;

    for (i = 0; i  < width-1; i++) {
				/* Pix1 Pix2
				   Pix3 Pix4 */
      /* Pix2 and Pix4 are used here for first time */
      pix2 = *(oo_prev + 1);
      pix4 = *(oo_prev_line2 + 1);

      *(ii_new) = pix1;					/* X.
							   ..*/
      *(ii_new + 1) = (pix1 + pix2 + 1)>>1; 		/* *X
							   .. */
      *ii_new_line2 = (pix1 + pix3 + 1)>>1; 		/* *.
						           X. */
      *(ii_new_line2 + 1) = (pix1 + pix2 + pix3 + pix4 + 2)>>2;
      
      oo_prev++; oo_prev_line2++; ii_new += 2; ii_new_line2 += 2;
      
      pix1 = pix2;
      pix3 = pix4;		/* Pix1 Pix2=Pix1' Pix2' */
				/* Pix3 Pix4=Pix3' Pix4' */
    }
    
    /* One but last column */
    *(ii_new++) = pix1;	
    *(ii_new++) = pix3;
    
    /* Last column -On the Edge - */
    *(ii_new_line2++) = (pix1 + pix3 + 1 ) >>1;
    *(ii_new_line2++) = (pix1 + pix3 + 1 ) >>1;

    ii_new += (width<<1);	/* ii_new now on old position ii_new_line2,so
				   one interpolated screen line must be added*/

    ii_new_line2 += (width<<1);	/* In fact, ii_new_line here has same value
				   as ii_new */

    oo_prev += 1; /* Remember, loop is done one time less! */

    oo_prev_line2 += 1;
    
  }

  /* last lines */
  pix1 = *oo_prev;

  for (i = 0; i < width-1; i++) {
    pix2 = *(oo_prev + 1);
    *ii_new = *ii_new_line2 = pix1;
    *(ii_new + 1) = *(ii_new_line2 + 1) = (pix1 + pix2 + 1)>>1;
    ii_new += 2;
    ii_new_line2 += 2;
    oo_prev += 1;
    pix1 = pix2;			/* Pix1 Pix2=Pix1' Pix2' */
  }
  
  /* bottom right corner Global::pels */
  *(ii_new) = pix1;
  *(ii_new + 1) = pix1;
  *(ii_new_line2) = pix1;
  *(ii_new_line2+1) = pix1;

  return;
}



/**********************************************************************
 *
 *	Name:		FullMotionEstimatePicture
 *	Description:    Finds integer and half pel motion estimation
 *	
 *	Input:	       current image, previous image, interpolated
 *                     reconstructed previous image, seek_dist,
 *                     motion vector array
 *	Returns:       
 *	Side effects: allocates memory for MV structure
 *
 *	Date: 960418	Author: Roatlt
 *
 ***********************************************************************/


void FullMotionEstimatePicture(unsigned int *curr, unsigned int *prev, 
			       unsigned int *prev_ipol, int seek_dist, 
			       MotionVector *MV_ptr,
			       int advanced_method,
			       int *EncodeThisBlock)
{
  int i,j;
  MotionVector *current_MV;



  for(j = 0; j < Global::mbr; j++) {

   for(i = 0; i < Global::mbc; i++) {
     current_MV = MV_ptr + j*Global::mbc + i;

     if(advanced_method && !*(EncodeThisBlock + j*Global::mbc + i) ) {
	
       current_MV->x = current_MV->y = current_MV->x_half = 
	 current_MV->y_half = 0;
       current_MV->Mode = MODE_SKIP;

      } else {			/* EncodeThisBlock */
       
	FullMotionEstimation(curr, prev_ipol, seek_dist, current_MV, 
			     i*MB_SIZE, j*MB_SIZE);
	
	current_MV->Mode = ChooseMode(curr,i*MB_SIZE,j*MB_SIZE,
				      current_MV->min_error);
	if(current_MV->Mode == MODE_INTRA) 
	  ZeroVec(current_MV);
      }

    }
  }


}


void CodeInterH263(CParam *params, Bits *bits)
{

  MotionVector *MV;	
  MotionVector ZERO = {0,0,0,0,0};
  MB_Structure *recon_data_P; 
  MB_Structure *diff;
  int *qcoeff_P;
  unsigned int *new_recon=NULL;
  unsigned int *prev_recon;
  int Mode;  
  int CBP, CBPB=0;
  int newgob;
  int i,j;

  Global::search_p_frames = params->search_method;

  MV =(struct motionvector*) malloc(sizeof(MotionVector)*Global::mbc*Global::mbr);

  new_recon =(unsigned int*) malloc(Global::sizeof_frame);
  prev_recon = params->recon;
  /* buffer control vars */
  
  ZeroBits(bits);

  /* Interpolate luminance from reconstr. picture */


  InterpolateImage(prev_recon,params->interpolated_lum,Global::pels,Global::lines);

  FullMotionEstimatePicture( params->data,
			     prev_recon, 
			    params->interpolated_lum, 
			    params->half_pixel_searchwindow,MV,
			    params->advanced_method, params->EncodeThisBlock);
  
  /* Calculate MV for each MB */

  /* ENCODE TO H.263 STREAM */
  
  for ( j = 0; j < Global::mbr; j++) {

    newgob = 0;

    if (j == 0) {
      Global::pic->QUANT = params->Q_inter;
      Global::pic->picture_coding_type = PCT_INTER;
      bits->header += CountBitsPicture(Global::pic);
    }
    else if (Global::pic->use_gobsync && j%Global::pic->use_gobsync == 0) {
      bits->header += CountBitsSlice(j,params->Q_inter); /* insert gob sync */
      newgob = 1;
    }

    for ( i = 0; i < Global::mbc; i++) {
      /* This means: For every macroblock (i,j) do ... */


      /* We have 4 different situations:
         1) !EncodeThisBlock: this means that the
	    macroblock in not encoded
         2) EncodeThisBlock: This means that the MB is 
	    encoded by using the predicted motion vector.
         3) EncodeThisBlock: However, the approx of the
	    motion vector was so bad, that INTRA coding is more
	    appropiate here ...
	 4) EncodeThisBlock: The approx is so good that
            the coefficients are all zero (after quant.) and are not	
	    send.
      */

	/* This means: For every macroblock (i,j) do ... */
        Global::pic->DQUANT = 0;

	Mode = MV[j*Global::mbc + i].Mode;

	/* Determine position of MB */
	Global::pic->MB = i + j * Global::mbc;

	if(Mode == MODE_SKIP) {
	  /* SITUATION 1 */
	  Mode = MODE_INTRA;	/* This might be done "better" in the future*/
	  MV[j*Global::mbc + i].Mode = Mode;

	  ZeroVec(&(MV[j*Global::mbc + i]));
 
	  CBP = CBPB = 0;
 
	  /* Now send code for "skip this MB" */
	  CountBitsMB(Mode,1,CBP,CBPB,Global::pic,bits);
   
	  ReconCopyImage(i,j,new_recon,prev_recon);

	} else { /* Encode this block */

	  if (Mode == MODE_INTER) {
	    /* SITUATION 2 */
	    /* Predict P-MB */
	    diff = Predict_P(params->data,
			     prev_recon,
			     params->interpolated_lum,i*MB_SIZE,
			     j*MB_SIZE,MV);
	  } else {
	    /* SITUATION 3 */

	    /* Create MB_Structure diff that contains coefficients that must be
	       sent to the other end */
	
	    diff = (MB_Structure *)malloc(sizeof(MB_Structure));
	    FillLumBlock(i*MB_SIZE, j*MB_SIZE, params->data, diff); 
	    /* Copy curr->lum to diff for macroblock (i,j) */
	    FillChromBlock(i*MB_SIZE, j*MB_SIZE, params->data, diff);
	    /* Equiv. for curr->Cb and curr->Cr */
	  }
	  /* P or INTRA Macroblock */
	  /*  diff -> DCT -> QUANTIZED -> qcoeff_P */
	  qcoeff_P = MB_EncodeAndFindCBP(diff, params->Q_inter, Mode,&CBP);
	
	  /*   CBP = FindCBP(qcoeff_P, Mode, 64); -> Not required anymore */

	  /* All encoded, now calculate decoded image
	     for comparison in next frame */

	  /* Do DECODING */

	  if (CBP == 0 && (Mode == MODE_INTER) ) {
				/* SITUATION 4 */
	    ZeroMBlock(diff);
	  } else {
	    /*  qcoeff_P -> Dequantized -> IDCT -> diff */
	    MB_Decode(qcoeff_P, diff, params->Q_inter, Mode);
	  }

	  recon_data_P = MB_Recon_P(prev_recon, 
				    params->interpolated_lum,diff, 
				    i*MB_SIZE,j*MB_SIZE,MV);

	  Clip(recon_data_P);
	  free(diff);

	  /* Do bitstream encoding */
	
	  if((CBP==0) && (EqualVec(&(MV[j*Global::mbc+i]),&ZERO)) &&
	     (Mode == MODE_INTER) ) {

	    /* Skipped MB : both CBP and CBPB are zero, 16x16 vector is zero,
	       PB delta vector is zero and Mode = MODE_INTER */
	    /* Now send code for "skip this MB" */
	    CountBitsMB(Mode,1,CBP,CBPB,Global::pic,bits);

	  } else {

	    /* Normal MB */
	    /* VLC */
	    CountBitsMB(Mode,0,CBP,CBPB,Global::pic,bits);

	    if (Mode == MODE_INTER) {
	      bits->no_inter++;
	      CountBitsVectors(MV, bits, i, j, Mode, newgob, Global::pic);
	    } else {
	      /* MODE_INTRA */
	      bits->no_intra++;
	    }
	    /* Only encode coefficient if they are nonzero or Mode is INTRA*/
	    
	    if (CBP || Mode == MODE_INTRA)
	      CountBitsCoeff(qcoeff_P, Mode, CBP, bits, 64);
	   

	  } /* End skip/not skip macroblock encoding */

	  ReconImage(i,j,recon_data_P,new_recon);
	  free(recon_data_P);
	  free(qcoeff_P);
	
	}      /* End advanced */
       
    } /* End for i */

  } /* End for j */

  Global::pic->QP_mean = params->Q_inter;
  
  free(prev_recon);
  params->recon = new_recon;

  AddBitsPicture(bits);
  free(MV);

  return;
}
				

