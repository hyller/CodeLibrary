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
//    Name    : mot_est.cpp
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

#include "Global.h"






/* Efficient macroblock comparison op. */

/* The comparison is between a non-interpolated lowres block of pixel 
   and a interpolated hires block of pixel. This might be confusing:

   Example: compare 3x3 block with 3x3 block, then the 1s of block 1 are
   compared with the 2s of block 2.

   Block 1:	Block 2:	
   1.1.1.	222
   ......	222
   1.1.1.	222
   ......
   1.1.1.

   You see, for block one (ii), you have 4 times more data!

*/

//inline int SAD_HalfPixelMacroblock(unsigned int *ii,
//			    unsigned int *curr,
//			    int pixels_on_line, int Min_SAD)
int SAD_HalfPixelMacroblock(unsigned int *ii,
			    unsigned int *curr,
			    int pixels_on_line, int Min_SAD)

{
  int j = 16;
  int sad = 0;
  while(j--) {
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii- (*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-(*curr++));  
    ii += 2;
    sad += abs(*ii-(*curr++));
    ii += 2;
    sad += abs(*ii-*curr);

    if(sad > Min_SAD)
      return INT_MAX;

    ii += pixels_on_line*4 - 30; 
                                /* Interpolated image, that means two times */
				/* We also take only one of the two pixels */
				/* This means another two times ... */
    curr += pixels_on_line - 15;

  } /* end while */

  return sad;
} 

/* This implementation contains two mayor algorithms: exhaustive and 
   logarithmic. The exhaustive algorithm was adapted to be applied on
   half-pixel luminance, and the logarithmic algorithm was implemented
   by Roalt Aalmoes and is functional equivalent to the one in berkeley's
   MPEG encoder. */

void FullMotionEstimation(unsigned int *curr, unsigned int *prev_ipol, 
		     int seek_dist, MotionVector *current_MV, int x_curr, 
		     int y_curr)
				/*  x_curr and y_curr are whole-pixel
				    values to indicate upperleft (0,0)
				    pixel of this MB in whole frame curr */
{

  int Min_FRAME;
  MotionVector MV_FRAME;
  unsigned int *curr_image_MB;
  int sxy,xblock,k,yblock,l;
  int RightXBorder,LeftXBorder,RightYBorder,LeftYBorder;
  int xmax,ymax,sad;
  int CenterX, CenterY, origCenterX, origCenterY, newCenterX, newCenterY;
  int StepSizeX, StepSizeY;



  curr_image_MB = curr + Global::pels*y_curr + x_curr;
  /* from now on, all pixel related operations are based on prev_ipol */
  /* way: thus resolution is enhanced by 2 for halfpixel search */
  CenterX = 2*x_curr;
  CenterY = 2*y_curr;

  xmax = 2*Global::pels;
  ymax = 2*Global::lines;
  sxy = mmin(31, seek_dist);  


  LeftXBorder = CenterX - sxy;
  RightXBorder = CenterX + sxy;

  LeftYBorder = CenterY - sxy;
  RightYBorder = CenterY + sxy;

  if (LeftXBorder<0) LeftXBorder = 0;
  if (RightXBorder>xmax-32) RightXBorder = xmax-32; 
  /* Comparison is still on 16x16 blocks */
  if (LeftYBorder<0) LeftYBorder = 0;		      
  /* but this is interleaved by 1 pixel! */
  if (RightYBorder>ymax-32) RightYBorder = ymax-32; 
  /* e.g. comp. pixno.1 3 5 7 or 2 4 6 8 */
  /*but never 1 2 3 4 as this is halfres.*/

  Min_FRAME = INT_MAX;
  MV_FRAME.x = 0;
  MV_FRAME.y = 0;
  MV_FRAME.x_half = 0;
  MV_FRAME.y_half = 0;
  
 
  if(Global::search_p_frames == CPARAM_EXHAUSTIVE) {
    /* This is the spriral search variant of exhaustive seach */
    /* First determine zero MV value SAD */
    xblock = CenterX; yblock = CenterY;

    sad = SAD_HalfPixelMacroblock(prev_ipol + xblock + yblock*Global::pels*2,
				  curr_image_MB,
				  Global::pels, Min_FRAME) - PREF_NULL_VEC;
 
    /* I assume sad < INT_MAX  */
    Min_FRAME = sad;
    
    /* Then do the surrounding MV SADs */

    for (l = 1; l <= sxy; l++) {
      /* For every loop from inside to outside do */
      xblock = CenterX - l;
      yblock = CenterY - l;
      for (k = 0; k < 8*l; k++) {
	if (xblock>=LeftXBorder && xblock<=RightXBorder 
	    && yblock>=LeftYBorder && yblock<=RightYBorder) {

	  /* 16x16 integer pel MV */
	  sad = SAD_HalfPixelMacroblock(prev_ipol + xblock + yblock*Global::pels*2,
					curr_image_MB,
					Global::pels, Min_FRAME); 
	  if (sad < Min_FRAME) {
	    MV_FRAME.x = xblock - CenterX;
	    MV_FRAME.y = yblock - CenterY;
	    Min_FRAME = sad;
	  }

	}
	if      (k<2*l) xblock++;
	else if (k<4*l) yblock++;
	else if (k<6*l) xblock--;
	else            yblock--;
      }      
    } /* end for */
  } else { /* Global::search_p_frames == DEF_LOGARITHMIC_SEARCH */

    

    /* origCenter* is necessary because Center* changes */
    origCenterX = CenterX; origCenterY = CenterY;


    StepSizeX = ((2*sxy + 1) + 1)/3; /* round(Size of Xinterval / 3), 
					this is maximum size of between two
					probes */ 
    StepSizeY = ((2*sxy + 1) + 1)/3; /* round(Size of Yinterval / 3) */


    sad = SAD_HalfPixelMacroblock(prev_ipol + CenterX + CenterY*Global::pels*2,
				  curr_image_MB,Global::pels, 
				  Min_FRAME) - PREF_NULL_VEC;
 
    /* I assume sad < INT_MAX  */
    Min_FRAME = sad;
 

    while (StepSizeX >= 1 || StepSizeY >= 1) {
      newCenterX = CenterX;
      newCenterY = CenterY;


      /* Do this loop three times */
      for(xblock = CenterX - StepSizeX; xblock <= CenterX + StepSizeX &&
	    (StepSizeX != 0); xblock += StepSizeX) {
	if(xblock < LeftXBorder || xblock > RightXBorder)
	  continue;
	/* Do this loop three times */
	for(yblock = CenterY - StepSizeY; yblock <= CenterY + StepSizeY &&
	      (StepSizeY != 0); yblock+= StepSizeY) {
	  if(yblock < LeftYBorder || yblock > RightYBorder)
	    continue;
	  /* In fact, the middlest comparison is only required 
	     the first time, as the last time it is calculated 
	     on the previous while-loop, remember:
	     NewCenterZ = zblock */

	  sad = SAD_HalfPixelMacroblock(prev_ipol + xblock + yblock*Global::pels*2,
					curr_image_MB,Global::pels, Min_FRAME); 
	  if (sad < Min_FRAME) {
	    MV_FRAME.x = xblock - origCenterX;
	    MV_FRAME.y = yblock - origCenterY;
	    Min_FRAME = sad;
	    newCenterX = xblock; newCenterY = yblock;
	  }

	}	/* end for yblock */
      } /* end for xblock */

      if(newCenterX < CenterX) {
	RightXBorder = LeftXBorder + StepSizeX - 1;
      } else if(newCenterX == CenterX) {
	LeftXBorder = LeftXBorder + StepSizeX;
        RightXBorder = RightXBorder - StepSizeX;
      } else {
	LeftXBorder = RightXBorder - StepSizeX + 1;
      }

      if(newCenterY < CenterY) {
	RightYBorder = LeftYBorder + StepSizeY - 1;
      } else if(newCenterY == CenterY) {
	LeftYBorder = LeftYBorder + StepSizeY;
	RightYBorder = RightYBorder - StepSizeY;
      } else {
	LeftYBorder = RightYBorder - StepSizeY + 1;
      }

      CenterX = newCenterX;
      CenterY = newCenterY;

      /* Stepsizes are 0 when RightZBorder == LeftZBorder */
      StepSizeX = ((RightXBorder - LeftXBorder + 1) + 1)/3; 
      /* round(Size of Xinterval / 3), this is maximum size of between two
	 probes */ 
      StepSizeY = ((RightYBorder - LeftYBorder + 1) + 1)/3; 
      /* round(Size of Yinterval / 3) */
      
    } /* End while stepsize */
  } /* end logarithmic search algorithm */
  


  current_MV->x = MV_FRAME.x / 2;
  current_MV->x_half = MV_FRAME.x % 2; /*This might not work for neg. values!*/
  current_MV->y = MV_FRAME.y / 2;
  current_MV->y_half = MV_FRAME.y % 2; /* This might not work! */
  current_MV->min_error = Min_FRAME;



  return;
}


int SAD_HalfPixelMacroblock2(unsigned int *ii,
			    unsigned int *curr,
			    int pixels_on_line, int Min_SAD)
{
  int j = 16;
  int sad = 0;
  while(j--) {
    sad += abs(*ii-(*curr));

    sad += abs(*(ii + 2)-(*(curr+1)));
    sad += abs(*(ii + 4)-(*(curr+2)));
    sad += abs(*(ii + 6)-(*(curr+3)));
    sad += abs(*(ii + 8)-(*(curr+4)));
    sad += abs(*(ii + 10)-(*(curr+5)));
    sad += abs(*(ii + 12)-(*(curr+6)));
    sad += abs(*(ii + 14)-(*(curr+7)));
    sad += abs(*(ii + 16)-(*(curr+8)));
    sad += abs(*(ii + 18)-(*(curr+9)));
    sad += abs(*(ii + 20)-(*(curr+10)));
    sad += abs(*(ii + 22)-(*(curr+11)));
    sad += abs(*(ii + 24)-(*(curr+12)));
    sad += abs(*(ii + 26)-(*(curr+13)));
    sad += abs(*(ii + 28)-(*(curr+14)));
    sad += abs(*(ii + 30)-(*(curr+15)));

    if(sad > Min_SAD)
      return INT_MAX;

    ii += pixels_on_line*2*2; 
                                /* Interpolated image, that means two times */
				/* We also take only one of the two pixels */
				/* This means another two times ... */
    curr += pixels_on_line;

  } /* end while */

  return sad;
} 


unsigned int *LoadArea(unsigned int *im, int x, int y, 
			int x_size, int y_size, int lx)
{
  unsigned int *res = (unsigned int *)malloc(sizeof(int)*x_size*y_size);
  unsigned int *in;
  unsigned int *out;
  int i = x_size;
  int j = y_size;

  in = im + (y*lx) + x;
  out = res;

  while (j--) {
    while (i--)
      *out++ = *in++;
    i = x_size;
    in += lx - x_size;
  };
  return res;
}



void FindMB(int x, int y, unsigned int *image, unsigned int MB[16][16])

{
  int n;
  unsigned int *MB_ptr = &MB[0][0];
  unsigned int *image_ptr;

  MB_ptr = &MB[0][0];
  image_ptr = image + x + y*Global::pels;

#ifdef LONGISDOUBLEINT
  for(n = 0; n < 16; n++) {
    * (unsigned long *) MB_ptr = * (unsigned long *) image_ptr; 
    MB_ptr += 2; image_ptr += 2;
    * (unsigned long *) MB_ptr = * (unsigned long *) image_ptr; 
    MB_ptr += 2; image_ptr += 2;
    * (unsigned long *) MB_ptr = * (unsigned long *) image_ptr; 
    MB_ptr += 2; image_ptr += 2;
    * (unsigned long *) MB_ptr = * (unsigned long *) image_ptr; 
    MB_ptr += 2; image_ptr += 2;
    * (unsigned long *) MB_ptr = * (unsigned long *) image_ptr; 
    MB_ptr += 2; image_ptr += 2;
    * (unsigned long *) MB_ptr = * (unsigned long *) image_ptr; 
    MB_ptr += 2; image_ptr += 2;
    * (unsigned long *) MB_ptr = * (unsigned long *) image_ptr; 
    MB_ptr += 2; image_ptr += 2;
    * (unsigned long *) MB_ptr = * (unsigned long *) image_ptr; 
    MB_ptr += 2; image_ptr += 2;
    
    image_ptr += Global::pels - 16;
  }

#else

  for (n = 0; n < 16; n++) {
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    *(unsigned int *) MB_ptr++ = *(unsigned int *) image_ptr++;
    image_ptr += Global::pels - 16;
  }
#endif

}






