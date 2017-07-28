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
//    Name    : struct.h
//
//
/////////////////////////////////////////////////////////////////////////////


#if !defined _STRUCT_H
#define _STRUCT_H



/* Motionvector structure */
typedef struct motionvector 
{
  int x;			/* Horizontal comp. of mv 	 */
  int y;			/* Vertical comp. of mv 	 */
  int x_half;			/* Horizontal half-pel acc.	 */
  int y_half;			/* Vertical half-pel acc.	 */
  int min_error;		/* Min error for this vector	 */
  int Mode;                     /* Necessary for adv. pred. mode */
} MotionVector;




/* Point structure */
typedef struct point 
{
  int x;
  int y;
} Point;







/* Structure with image data */
typedef struct pict_image 
{
  unsigned int *lum;		/* Luminance plane		*/
  unsigned int *Cr;		/* Cr plane			*/
  unsigned int *Cb;		/* Cb plane			*/
} PictImage;




/* Group of pictures structure. */

/* Picture structure */
typedef struct pict 
{
  int prev; 
  int curr;
  int TR;             /* Time reference */
  int source_format;
  int picture_coding_type;
  int spare;
  int unrestricted_mv_mode;
  int PB;
  int QUANT;
  int DQUANT;
  int MB;
  int seek_dist;        /* Motion vector search window */
  int use_gobsync;      /* flag for gob_sync */
  int MODB;             /* B-frame mode */
  int BQUANT;           /* which quantizer to use for B-MBs in PB-frame */
  int TRB;              /* Time reference for B-picture */
  int frame_inc;        /* buffer control frame_inc */
  float QP_mean;        /* mean quantizer */
} Pict;



/* Slice structure */
typedef struct slice 
{
  unsigned int vert_pos;	/* Vertical position of slice 	*/
  unsigned int quant_scale;	/* Quantization scale		*/
} Slice;



/* Macroblock structure */
typedef struct macroblock 
{
  int mb_address;		/* Macroblock address 		*/
  int macroblock_type;		/* Macroblock type 		*/
  int skipped;			/* 1 if skipped			*/
  MotionVector motion;	        /* Motion Vector 		*/
} Macroblock;



/* Structure for macroblock data */
typedef struct mb_structure 
{
  int lum[16][16];
  int Cr[8][8];
  int Cb[8][8];
} MB_Structure;



/* Structure for average results and virtal buffer data */
typedef struct results 
{
  float SNR_l;			/* SNR for luminance */
  float SNR_Cr;			/* SNR for chrominance */
  float SNR_Cb;
  float QP_mean;                /* Mean quantizer */
} Results;






typedef struct compression_parameters 
{
/* Contains all the parameters that are needed for 
   encoding plus all the status between two encodings */
  int half_pixel_searchwindow; /* size of search window in half pixels
				  if this value is 0, no search is performed
				*/
  int format;			/*  */
  int pels;			/* Only used when format == CPARAM_OTHER */
  int lines;			/* Only used when format == CPARAM_OTHER */
  int inter;			/* TRUE of INTER frame encoded frames,
				   FALSE for INTRA frames */
  int search_method;		/* DEF_EXHAUSTIVE or DEF_LOGARITHMIC */
  int advanced_method;		/* TRUE : Use array to determine 
				          macroblocks in INTER frame
					  mode to be encoded */
  int Q_inter;			/* Quantization factor for INTER frames */
  int Q_intra;			/* Quantization factor for INTRA frames */
  unsigned int *data;		/* source data in qcif format */
  unsigned int *interpolated_lum;	/* intepolated recon luminance part */
  unsigned int *recon;		/* Reconstructed copy of compressed frame */
  int *EncodeThisBlock; 
                                /* Array when advanced_method is used */
} CParam;






/* Structure for counted bits */
typedef struct bits_counted
 {
  int Y;
  int C;
  int vec;
  int CBPY;
  int CBPCM;
  int MODB;
  int CBPB;
  int COD;
  int header;
  int DQUANT;
  int total;
  int no_inter;
  int no_inter4v;
  int no_intra;
/* NB: Remember to change AddBits(), ZeroBits() and AddBitsPicture() 
   when entries are added here */
} Bits;




// Video Format structure...

struct qcif 
{
  unsigned int Y[QCIF_YHEIGHT][QCIF_YWIDTH];
  unsigned int U[QCIF_UHEIGHT][QCIF_UWIDTH];
  unsigned int V[QCIF_VHEIGHT][QCIF_VWIDTH];
};




struct cif 
{
  unsigned int Y[CIF_YHEIGHT][CIF_YWIDTH];
  unsigned int U[CIF_UHEIGHT][CIF_UWIDTH];
  unsigned int V[CIF_VHEIGHT][CIF_VWIDTH];
};




struct qcif8bit 
{
  unsigned char Y[QCIF_YHEIGHT][QCIF_YWIDTH];
  unsigned char U[QCIF_UHEIGHT][QCIF_UWIDTH];
  unsigned char V[QCIF_VHEIGHT][QCIF_VWIDTH];
};



struct cif8bit 
{
  unsigned char Y[CIF_YHEIGHT][CIF_YWIDTH];
  unsigned char U[CIF_UHEIGHT][CIF_UWIDTH];
  unsigned char V[CIF_VHEIGHT][CIF_VWIDTH];
};


#endif
