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
//    Name    : libr263.cpp
//    Details : Entry point to encoder....
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


#include "libr263.h"


int InitH263Encoder(CParam *params)
{

  Global::pic = (Pict *)malloc(sizeof(Pict));
  
  if(!Global::pic) 
  {
  return -1;
  }

  Global::pic->unrestricted_mv_mode = DEF_UMV_MODE;
  Global::pic->use_gobsync = DEF_INSERT_SYNC;
  Global::pic->PB = 0;
  Global::pic->TR = 0;
  Global::pic->QP_mean = 0.0;

  if(params->format == CPARAM_QCIF) {
    Global::pels = QCIF_YWIDTH;
    Global::lines = QCIF_YHEIGHT;
    Global::cpels = QCIF_YWIDTH/2;
    Global::pic->source_format = SF_QCIF;
  } else if (params->format == CPARAM_CIF) {
    Global::pels = CIF_YWIDTH;
    Global::lines = CIF_YHEIGHT;
    Global::cpels = CIF_YWIDTH/2;
    Global::pic->source_format = SF_CIF;
  } else if (params->format == CPARAM_SQCIF) {
    Global::pels = SQCIF_YWIDTH;
    Global::lines = SQCIF_YHEIGHT;
    Global::cpels = SQCIF_YWIDTH/2;
    Global::pic->source_format = SF_SQCIF;
  } else if (params->format == CPARAM_4CIF) {
    Global::pels = CIF4_YWIDTH;
    Global::lines = CIF4_YHEIGHT;
    Global::cpels = CIF4_YWIDTH/2;
    Global::pic->source_format = SF_4CIF;  
  } else if (params->format == CPARAM_16CIF) {
    Global::pels = CIF16_YWIDTH;
    Global::lines = CIF16_YHEIGHT;
    Global::cpels = CIF16_YWIDTH/2;
    Global::pic->source_format = SF_16CIF;
  } else {
    Global::pels = params->pels;
    Global::lines = params->lines;
    Global::cpels = params->pels / 2;
    Global::pic->source_format = 0;	/* ILLEGAL H.263! Use it only for testing */
  }
  
  Global::mbr = Global::lines / MB_SIZE;
  Global::mbc = Global::pels / MB_SIZE;
  Global::uskip = Global::lines*Global::pels;
  Global::vskip = Global::uskip + Global::lines*Global::pels/4;
  Global::sizeof_frame = (Global::vskip + Global::lines*Global::pels/4)*sizeof(int);


  Global::headerlength = DEF_HEADERLENGTH;
  /* Initalize VLC_tables */
  InitHuff();
  mwinit();

  /* Init motion detection */
  init_motion_detection();


#ifdef VERYFASTIDCT
  init_idct();			/* Do this in case of VERYFASTIDCT */
#elif STANDARDIDCT
  init_idctref();		/* Do this in case of standard IDCT */
#endif
				/* Do nothing for FASTIDCT */

  /* Set internal variables */
  Global::advanced = DEF_ADV_MODE;
  Global::mv_outside_frame = DEF_UMV_MODE || DEF_ADV_MODE;
  Global::long_vectors = DEF_UMV_MODE;
  Global::pb_frames = DEF_PBF_MODE;
  Global::search_p_frames = DEF_SPIRAL_SEARCH;
  Global::trace = DEF_WRITE_TRACE;

  params->half_pixel_searchwindow = CPARAM_DEFAULT_SEARCHWINDOW; 
  params->inter = CPARAM_DEFAULT_INTER;
  params->search_method = CPARAM_DEFAULT_SEARCH_METHOD;
  params->advanced_method = CPARAM_DEFAULT_ADVANCED_METHOD;
  params->Q_inter = CPARAM_DEFAULT_INTER_Q;
  params->Q_intra = CPARAM_DEFAULT_INTRA_Q;

  params->interpolated_lum = (unsigned int*)malloc(Global::pels*Global::lines*4*sizeof(int));

  if(!params->interpolated_lum)
    return -1;

  params->recon =(unsigned int*) malloc(Global::sizeof_frame);
  if(!params->recon) {
    free(params->interpolated_lum);
    free(Global::pic);
    return -1;
  }

  return 0;
}

void SkipH263Frames(int frames_to_skip)
{
  Global::pic->TR += frames_to_skip % 256;
}

int CompressFrame(CParam *params, Bits *bits)
{
  if(!params->inter) {
    CodeIntraH263(params, bits);
  } else {
    CodeInterH263(params, bits);
  }
  bits->header += zeroflush();  /* pictures shall be byte aligned */
  Global::pic->TR += 1 % 256; /* one means 30 fps */
  return 0;
}

void ExitH263Encoder(CParam *params)
{
  mwcloseinit();
  free(params->interpolated_lum);
  free(params->recon);
  free(Global::pic);
  return;
}

/* Motion Detection part */

static int global_mb_threshold;
static int global_pixel_threshold;

/* This array is computed for QCIF
  movement_detection[] = {0, 354, 528, 177,
                          3, 353, 531, 178,
		          352, 179, 530, 1,
		          355, 176, 2, 529 };
			  */
/* This array determines the order in a pixel is checked per 4x4 block */
/* {x, y} within [0..3] */
static unsigned int movement_coords[16][2] = { {0,0}, {2,2},{0,3},{1,1},
		               		       {3,0},{1,2},{3,3},{2,1},
				               {0,2},{3,1},{2,3},{1,0},
				               {3,2},{0,1},{2,0},{1,3} };


static int movement_detection[16][4];

void init_motion_detection()
{
  unsigned int counter, pos;

  for(counter = 0; counter < 16; counter++) {
    pos = movement_coords[counter][0] + movement_coords[counter][1]*Global::pels;
    movement_detection[counter][0] = pos;
    movement_detection[counter][1] = pos + 4;
    movement_detection[counter][2] = pos + Global::pels*4;
    movement_detection[counter][3] = pos + Global::pels*4 + 4;
  }
  return;
}

//__inline__ static int Check8x8(unsigned int *orig, unsigned int *recon, int pos)
static int Check8x8(unsigned int *orig, unsigned int *recon, int pos)
{
  int value, index;
  register int thres = global_pixel_threshold;

  value = 0;

  /* Mark pixel changed when lum value differs more than "thres" */
  index = movement_detection[pos][0];
  value += abs(*(orig + index) - *(recon+index)) > thres;

  index = movement_detection[pos][1];
  value += abs(*(orig + index) - *(recon+index)) > thres;

  index = movement_detection[pos][2];				
  value += abs(*(orig + index) - *(recon+index)) > thres;

  index = movement_detection[pos][3];			
  value += abs(*(orig + index) - *(recon+index)) > thres;

  return value;
}

static int HasMoved(int call_time,  void *real,
	     void *recon, int x, int y)
{
  int offset1;
  unsigned int *MB_orig;
  unsigned int *MB_recon;
  int position;
  int value = 0;

  offset1 = (y*Global::pels+x)*MB_SIZE;
  position = call_time;

  /* Integration of 8x8 and 4x4 check might improve performance, 
     but is not done here */
  MB_orig = (unsigned int *) real + offset1;
  MB_recon = (unsigned int *) recon + offset1;
  value += Check8x8(MB_orig, MB_recon, position);

  MB_orig += 8; MB_recon += 8;
  value += Check8x8(MB_orig, MB_recon, position); 

  MB_orig += 8*Global::pels - 8; MB_recon += 8*Global::pels - 8;
  value += Check8x8(MB_orig, MB_recon, position);

  MB_orig += 8; MB_recon += 8;
  value += Check8x8(MB_orig, MB_recon, position);

  return value > global_mb_threshold;	
  /* Mark MB changed if more than "global_mb_threshold" pixels are changed */
}


int FindMotion(CParam *params, int mb_threshold, int pixel_threshold)
{
  static int call_time = 0;

  int j,i;
  int counter = 0;

  global_mb_threshold = mb_threshold;
  global_pixel_threshold = pixel_threshold;

  for(j = 0; j < Global::mbr; j++) {
    for(i = 0; i < Global::mbc; i++) {
      *(params->EncodeThisBlock + j*Global::mbc + i) = 
	HasMoved(call_time, params->data, params->recon, i,j);

      counter += *(params->EncodeThisBlock +j*Global::mbc + i);
    }
  }

  call_time = (call_time + 1) % 16;
 
  return counter;
}



