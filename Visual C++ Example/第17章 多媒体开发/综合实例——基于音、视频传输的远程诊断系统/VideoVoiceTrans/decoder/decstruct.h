////////////////////////////////////////////////////////////////////////////
//
//
//    Project     : VideoNet version 1.1.
//    Description : Peer to Peer Video Conferencing over the LAN.
//	  Author      :	Nagareshwar Y Talekar ( nsry2002@yahoo.co.in)
//    Date        : 15-6-2004.
//
//    This is the modified version of tmndecode (H.263 decoder) 
//    written by Karl & Robert.It was in ANSI C. I have converted into C++
//    so that it can be integrated into any windows application. I have 
//    removed some of the files which had display and file storing 
//    functions.I have removed the unnecessary code and also added some
//    new files..
//	  Original library dealt with files. Input & Output , both were files.
//    I have done some major changes so that it can be used for real time 
//    decoding process. Now one can use this library for decoding H263 frames. 
//
//
//    File description : 
//    Name    : decstruct.h
//	  Details : Global structure declarations....
//
/////////////////////////////////////////////////////////////////////////////


#if !defined DEC_STRUCT_H
#define DEC_STRUCT_H


 struct ld 
 {
  
  /* bit input */
  unsigned char rdbfr[2051];
  unsigned char *rdptr;
  unsigned char inbfr[16];
  int incnt;
  int bitcnt;
  
  /* block data */
  short block[12][64];

 };


typedef struct 
{
  int val, len;
} VLCtab;

typedef struct 
{
  char run, level, len;
} DCTtab;


typedef struct 
{
  int val, len;
} VLCtabI;


typedef struct 
{
  int val, run, sign;
} RunCoef;


#endif
