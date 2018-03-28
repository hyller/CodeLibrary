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
//    Name    : quant.cpp
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

#include "quant.h"

/* For q=8, a "speedy" version is integrated */
int QuantAndFindCBP(int *coeff, int *qcoeff, int QP, int Mode, int CBP_Mask)
{
  int i;
  int level;
  int tempje;
  int CBP = 0;

  if (Mode == MODE_INTRA) { /* Intra */
    qcoeff[0] = mmax(1,mmin(254,coeff[0] >> 3)); /* was: /8 */

    if(QP == 8) {

      for(i = 1; i < 64; i++) {
	level = (abs(coeff[i])) >> 4;
	qcoeff[i] = mmin(127, mmax(-127,sign(coeff[i]) * level));
	if(qcoeff[i])
	  CBP = CBP_Mask;
      }
    } else {			/* QP != 8 */
      for(i = 1; i < 64; i++) {

	level = (abs(coeff[i])) / (2*QP);
	qcoeff[i] =  mmin(127,mmax(-127,sign(coeff[i]) * level));
	if(qcoeff[i])
	  CBP = CBP_Mask;
      }

    }	/* End QP == 8 */
  }
  else { /* non Intra */
    if(QP == 8) {
      for(i = 0; i < 64; i++) {
	tempje = abs(coeff[i]) - 4;
	if(tempje < 0) {
	  *(qcoeff++) = 0;
	} else {
	  level = tempje >> 4; /* Note 2*QP == 2*8 = 2^4 == ">>4" */
	  if((*(qcoeff++) = mmin(127,mmax(-127,(sign(coeff[i]) > 0) ?
					  level :
					  -level))) != 0)
	    CBP = CBP_Mask;
	}
      }
      
    } else {			/* QP != 8 */
      
      for (i = 0; i < 64; i++) {
	level = (abs(coeff[i])-QP/2)  / (2*QP);
	if((*(qcoeff++) = mmin(127,mmax(-127,sign(coeff[i]) * level)))!= 0)
	  CBP = CBP_Mask;
      }
      
    } /* End QP == 8 */
    
  }  
  return CBP;
}


void Dequant(int *qcoeff, int *rcoeff, int QP, int Mode)
{
  int i;
  
  if (QP) {
    for (i = 0; i < 64; i++) {
      if (qcoeff[i]) {
	if ((QP % 2) == 1)
	  rcoeff[i] = QP * (2*abs(qcoeff[i]) + 1);
	else
	  rcoeff[i] = QP * (2*abs(qcoeff[i]) + 1) - 1;
	rcoeff[i] = sign(qcoeff[i]) * rcoeff[i];
      }
      else
	rcoeff[i] = 0;
    }
    if (Mode == MODE_INTRA) { /* Intra */
      rcoeff[0] = qcoeff[0]*8;
    }
  }
  else {
    /* No quantizing at all */
    for (i = 0; i < 64; i++) {
      rcoeff[i] = qcoeff[i];
    }
  }
  return;
}



