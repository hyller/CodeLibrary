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
//    Name    : pred.cpp
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

#include "pred.h"
#include "mot_est.h"

MB_Structure *Predict_P(unsigned int *curr_image, unsigned int *prev_image,
			unsigned int *prev_ipol, int x, int y, 
			MotionVector *MV_ptr)
{
  int m,n;
  unsigned int curr[16][16];
  int pred[16][16];
  MotionVector *fr0;
  int dx, dy;
  int xmb, ymb;
  MB_Structure *pred_error;

  pred_error = (MB_Structure *)malloc(sizeof(MB_Structure));
    
  xmb = x/MB_SIZE;
  ymb = y/MB_SIZE;

  fr0 = MV_ptr + ymb*Global::mbc + xmb;

  /* Find MB in current image */
#ifdef PRINT_DEBUG
  fprintf(debugf,"FindMB(%d,%d,%p,%p)\n",x,y,curr_image->Y,curr);
#endif
  
  FindMB(x, y, curr_image,curr);

  /* Find prediction based on half pel MV */

  FindPred(x, y, fr0, prev_ipol, &pred[0][0]);

  /* Do the actual prediction */
  if (fr0->Mode == MODE_INTER) {
    for (n = 0; n < MB_SIZE; n++)
      for (m = 0; m < MB_SIZE; m++) 
	pred_error->lum[n][m] = (int)(curr[n][m] - pred[n][m]);

    dx = 2*fr0->x + fr0->x_half;
    dy = 2*fr0->y + fr0->y_half;
    dx = ( dx % 4 == 0 ? dx >> 1 : (dx>>1)|1 );
    dy = ( dy % 4 == 0 ? dy >> 1 : (dy>>1)|1 );
#ifdef PRINTDEBUG
    fprintf(debugf,"DoPredChrom_P(%d,%d,%d,%d,%p,%p,%p)\n",x, y, dx, dy, curr_image, prev_image, pred_error);
#endif 
    DoPredChrom_P(x, y, dx, dy, curr_image, prev_image, pred_error);
  }
  else
    fprintf(stderr,"Illegal Mode in Predict_P (pred.c)\n");

  return pred_error;
}

void DoPredChrom_P(int x_curr, int y_curr, int dx, int dy,
		   unsigned int *curr, unsigned int *prev, 
		   MB_Structure *pred_error)
{
  int m,n;

  int x, y, ofx, ofy, pel, lx;
  int xint, yint;
  int xh, yh;

  lx = Global::pels/2;

  x = x_curr>>1;
  y = y_curr>>1;

  xint = dx>>1;
  xh = dx & 1;
  yint = dy>>1;
  yh = dy & 1;

  if (!xh && !yh) {
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {

	ofx = x + xint + m;
	ofy = y + yint + n;
				/* prev+Global::vskip does not work directly... */
	pel=*(prev+Global::vskip + ofx    + (ofy   )*lx);
	pred_error->Cr[n][m] = 
	  (int)(*(curr+Global::vskip + x+m + (y+n)*Global::cpels) - pel);

	pel=*(prev+Global::uskip + ofx    + (ofy   )*lx);
	pred_error->Cb[n][m] = 
	  (int)(*(curr + Global::uskip + x+m + (y+n)*Global::cpels) - pel);
      }
    }
  }
  else if (!xh && yh) {
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {

	ofx = x + xint + m;
	ofy = y + yint + n;
	pel=(*(prev+Global::vskip + ofx    + (ofy   )*lx)+
	     *(prev+Global::vskip + ofx    + (ofy+yh)*lx) + 1)>>1;

	pred_error->Cr[n][m] = 
	  (int)(*(curr+Global::vskip + x+m + (y+n)*Global::cpels) - pel);

	pel=(*(prev+Global::uskip + ofx    + (ofy   )*lx)+
	     *(prev+Global::uskip + ofx    + (ofy+yh)*lx) + 1)>>1;

	pred_error->Cb[n][m] = 
	  (int)(*( curr+Global::uskip + x+m + (y+n)*Global::cpels) - pel);
      
      }
    }
  }
  else if (xh && !yh) {
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {

	ofx = x + xint + m;
	ofy = y + yint + n;
	pel=(*(prev+Global::vskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::vskip+ofx+xh + (ofy   )*lx) + 1)>>1;

	pred_error->Cr[n][m] = 
	  (int)(*(curr+Global::vskip + x+m + (y+n)*Global::cpels) - pel);

	pel=(*(prev+Global::uskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::uskip+ofx+xh + (ofy   )*lx) + 1)>>1;

	pred_error->Cb[n][m] = 
	  (int)( *( curr+Global::uskip + x+m + (y+n)*Global::cpels) - pel);
      
      }
    }
  }
  else { /* xh && yh */
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {
	ofx = x + xint + m;
	ofy = y + yint + n;
	pel=(*(prev+Global::vskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::vskip+ofx+xh + (ofy   )*lx)+
	     *(prev+Global::vskip+ofx    + (ofy+yh)*lx)+
	     *(prev+Global::vskip+ofx+xh + (ofy+yh)*lx)+
	     2)>>2;

	pred_error->Cr[n][m] = 
	  (int)(*(curr+Global::vskip + x+m + (y+n)*Global::cpels) - pel);

	pel=(*(prev+Global::uskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::uskip+ofx+xh + (ofy   )*lx)+
	     *(prev+Global::uskip+ofx    + (ofy+yh)*lx)+
	     *(prev+Global::uskip+ofx+xh + (ofy+yh)*lx)+
	     2)>>2;

	pred_error->Cb[n][m] = 
	  (int)(*(curr+Global::uskip + x+m + (y+n)*Global::cpels) - pel);
      
      }
    }
  }
  return;
}


void FindPred(int x, int y, MotionVector *fr, unsigned int *prev, 
	      int *pred)
{
  int n;
  int new_x, new_y;
  int *prev_ptr;

  new_x = 2*(x + fr->x) + fr->x_half;
  new_y = 2*(y + fr->y) + fr->y_half;

  prev_ptr =  (int *) prev + 2*new_y*Global::pels + new_x;
  /* Fill pred. data */
  for (n = 0; n < 16; n++) {
    /* Interpolated data -> too bad it can't be done in longs... */

      *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);
      prev_ptr += 2;
       *(pred++) = *(prev_ptr);

      prev_ptr += Global::pels*4 - 30;
  }
  return;
}


MB_Structure *MB_Recon_P(unsigned int *prev_image, unsigned int *prev_ipol,
			 MB_Structure *diff, int x_curr, int y_curr, 
			 MotionVector *MV_ptr)
{
  MB_Structure *recon_data = (MB_Structure *)malloc(sizeof(MB_Structure));
  MotionVector *fr0;
  int dx, dy;

  fr0 = MV_ptr + (y_curr/MB_SIZE)*Global::mbc + (x_curr/MB_SIZE);

  if (fr0->Mode == MODE_INTER) {
      /* Inter 16x16 */
    ReconLumBlock_P(x_curr,y_curr,fr0,prev_ipol,&diff->lum[0][0]);
    
    dx = 2*fr0->x + fr0->x_half;
    dy = 2*fr0->y + fr0->y_half;
    dx = ( dx % 4 == 0 ? dx >> 1 : (dx>>1)|1 );
    dy = ( dy % 4 == 0 ? dy >> 1 : (dy>>1)|1 );
    ReconChromBlock_P(x_curr, y_curr, dx, dy, prev_image, diff);
  }

  memcpy(recon_data, diff, sizeof(MB_Structure));

  return recon_data;
}

void ReconLumBlock_P(int x, int y, MotionVector *fr, 
		     unsigned int *prev, int *data)
{
  int m, n;
  int x1, y1;
  int *data_ptr = data;
  unsigned int *prev_ptr;

  x1 = 2*(x + fr->x) + fr->x_half;
  y1 = 2*(y + fr->y) + fr->y_half;
  
  prev_ptr = prev + x1 + y1*2*Global::pels;
  for (n = 0; n < 16; n++) {
    for (m = 0; m < 16; m++) {
      *data_ptr++ += (int)(*prev_ptr);
      prev_ptr += 2;
    }
    prev_ptr += 2*2*Global::pels - 32;
  }

  return;
}


void ReconChromBlock_P(int x_curr, int y_curr, int dx, int dy,
		       unsigned int *prev, MB_Structure *data)

{
  int m,n;

  int x, y, ofx, ofy, pel,lx;
  int xint, yint;
  int xh, yh;

  lx = Global::pels/2;

  x = x_curr>>1;
  y = y_curr>>1;

  xint = dx>>1;
  xh = dx & 1;
  yint = dy>>1;
  yh = dy & 1;
    
  if (!xh && !yh) {
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {

	ofx = x + xint + m;
	ofy = y + yint + n;
	pel=*(prev+Global::vskip+ ofx    + (ofy   )*lx);
	data->Cr[n][m] += pel;

	pel=*(prev+Global::uskip + ofx    + (ofy   )*lx);
	data->Cb[n][m] += pel;
      }
    }
  }
  else if (!xh && yh) {
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {

	ofx = x + xint + m;
	ofy = y + yint + n;
	pel=(*(prev+Global::vskip+ ofx    + (ofy   )*lx)+
	     *(prev+Global::vskip+ ofx    + (ofy+yh)*lx) + 1)>>1;

	data->Cr[n][m] += pel;

	pel=(*(prev+Global::uskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::uskip+ofx    + (ofy+yh)*lx) + 1)>>1;

	data->Cb[n][m] += pel;
      
      }
    }
  }
  else if (xh && !yh) {
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {

	ofx = x + xint + m;
	ofy = y + yint + n;
	pel=(*(prev+Global::vskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::vskip+ofx+xh + (ofy   )*lx) + 1)>>1;

	data->Cr[n][m] += pel;

	pel=(*(prev+Global::uskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::uskip+ofx+xh + (ofy   )*lx) + 1)>>1;

	data->Cb[n][m] += pel;
      
      }
    }
  }
  else { /* xh && yh */
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {
	ofx = x + xint + m;
	ofy = y + yint + n;
	pel=(*(prev+Global::vskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::vskip+ofx+xh + (ofy   )*lx)+
	     *(prev+Global::vskip+ofx    + (ofy+yh)*lx)+
	     *(prev+Global::vskip+ofx+xh + (ofy+yh)*lx)+
	     2)>>2;

	data->Cr[n][m] += pel;

	pel=(*(prev+Global::uskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::uskip+ofx+xh + (ofy   )*lx)+
	     *(prev+Global::uskip+ofx    + (ofy+yh)*lx)+
	     *(prev+Global::uskip+ofx+xh + (ofy+yh)*lx)+
	     2)>>2;

	data->Cb[n][m] += pel;
      
      }
    }
  }
  return;
}

void FindChromBlock_P(int x_curr, int y_curr, int dx, int dy,
		      unsigned int *prev, MB_Structure *data)

{
  int m,n;

  int x, y, ofx, ofy, pel,lx;
  int xint, yint;
  int xh, yh;

  lx = Global::pels/2;

  x = x_curr>>1;
  y = y_curr>>1;

  xint = dx>>1;
  xh = dx & 1;
  yint = dy>>1;
  yh = dy & 1;
    
  if (!xh && !yh) {
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {

	ofx = x + xint + m;
	ofy = y + yint + n;
	pel=*(prev+Global::vskip+ofx    + (ofy   )*lx);
	data->Cr[n][m] = pel;

	pel=*(prev+Global::uskip+ofx    + (ofy   )*lx);
	data->Cb[n][m] = pel;
      }
    }
  }
  else if (!xh && yh) {
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {

	ofx = x + xint + m;
	ofy = y + yint + n;
	pel=(*(prev+Global::vskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::vskip+ofx    + (ofy+yh)*lx) + 1)>>1;

	data->Cr[n][m] = pel;

	pel=(*(prev+Global::uskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::uskip+ofx    + (ofy+yh)*lx) + 1)>>1;

	data->Cb[n][m] = pel;
      
      }
    }
  }
  else if (xh && !yh) {
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {

	ofx = x + xint + m;
	ofy = y + yint + n;
	pel=(*(prev+Global::vskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::vskip+ofx+xh + (ofy   )*lx) + 1)>>1;

	data->Cr[n][m] = pel;

	pel=(*(prev+Global::uskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::uskip+ofx+xh + (ofy   )*lx) + 1)>>1;

	data->Cb[n][m] = pel;
      
      }
    }
  }
  else { /* xh && yh */
    for (n = 0; n < 8; n++) {
      for (m = 0; m < 8; m++) {
	ofx = x + xint + m;
	ofy = y + yint + n;
	pel=(*(prev+Global::vskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::vskip+ofx+xh + (ofy   )*lx)+
	     *(prev+Global::vskip+ofx    + (ofy+yh)*lx)+
	     *(prev+Global::vskip+ofx+xh + (ofy+yh)*lx)+
	     2)>>2;

	data->Cr[n][m] = pel;

	pel=(*(prev+Global::uskip+ofx    + (ofy   )*lx)+
	     *(prev+Global::uskip+ofx+xh + (ofy   )*lx)+
	     *(prev+Global::uskip+ofx    + (ofy+yh)*lx)+
	     *(prev+Global::uskip+ofx+xh + (ofy+yh)*lx)+
	     2)>>2;

	data->Cb[n][m] = pel;
      
      }
    }
  }
  return;
}




int ChooseMode(unsigned int *curr, int x_pos, int y_pos, int min_SAD)
{
  int i,j;
  int MB_mean = 0, A = 0;
  int y_off;

  for (j = 0; j < MB_SIZE; j++) {
    y_off = (y_pos + j) * Global::pels;
    for (i = 0; i < MB_SIZE; i++) {
      MB_mean += *(curr + x_pos + i + y_off);
    }
  }
  MB_mean /= (MB_SIZE*MB_SIZE);
  for (j = 0; j < MB_SIZE; j++) {
    y_off = (y_pos + j) * Global::pels;
    for (i = 0; i < MB_SIZE; i++) {
      A += abs( *(curr + x_pos + i + y_off) - MB_mean );
    }
  }

  if (A < (min_SAD - 500)) 
    return MODE_INTRA;
  else
    return MODE_INTER;
}



