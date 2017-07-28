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
//    Name    : stream.cpp
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

/*************************************************************
Copyright (C) 1990, 1991, 1993 Andy C. Hung, all rights reserved.
PUBLIC DOMAIN LICENSE: Stanford University Portable Video Research
Group. If you use this software, you agree to the following: This
program package is purely experimental, and is licensed "as is".
Permission is granted to use, modify, and distribute this program
without charge for any purpose, provided this license/ disclaimer
notice appears in the copies.  No warranty or maintenance is given,
either expressed or implied.  In no event shall the author(s) be
liable to you or a third party for any special, incidental,
consequential, or other damages, arising out of the use or inability
to use the program for any purpose (or the loss of data), even if we
have been advised of such possibilities.  Any public reference or
advertisement of this source code should refer to it as the Portable
Video Research Group (PVRG) code, and not by any author(s) (or
Stanford University) name.
*************************************************************/

/*
************************************************************
stream.c

This file handles all of the bit-level stream commands.

************************************************************
*/

/*LABEL stream.c */

#include "stream.h"


extern char *BitPrint(int length, int val);
static int current_write_byte;
static int write_position;

int bit_set_mask[] =
{0x00000001,0x00000002,0x00000004,0x00000008,
0x00000010,0x00000020,0x00000040,0x00000080,
0x00000100,0x00000200,0x00000400,0x00000800,
0x00001000,0x00002000,0x00004000,0x00008000,
0x00010000,0x00020000,0x00040000,0x00080000,
0x00100000,0x00200000,0x00400000,0x00800000,
0x01000000,0x02000000,0x04000000,0x08000000,
0x10000000,0x20000000,0x40000000,0x80000000};

#define WRITEBYTE(x) WriteByteFunction(x) 

#define mput1()\
{current_write_byte|=bit_set_mask[write_position--];\
 if (write_position<0) {WRITEBYTE(current_write_byte); write_position=7;current_write_byte=0;}}

#define mput0()\
{write_position--;if(write_position<0){WRITEBYTE(current_write_byte);write_position=7;current_write_byte=0;}}


/*

mwinit() initializes static variables for writing 

*/

void mwinit()
{
    current_write_byte=0;
    write_position=7;

}


/*

mwcloseinit() closes the write bit-stream. It flushes the remaining byte
with ones, consistent with -1 returned on EOF.

*/

void  mwcloseinit()
{
    while(write_position!=7)
	{
	    mput1();
	}
}


/*
  
zeroflush() flushes out the rest of the byte with 0's.
returns number og bits written to bitstream (kol)
  
*/

int zeroflush()
{
    int bits = 0;
    /*  printf("WP: %d\n",write_position);*/
    while (write_position!=7)
	{
	    mput0();
	    bits++;
	}
    return bits;
}

/*

mputb() puts a bit to the write stream.

*/


void mputb(int b)
{
    char *bit;
    if (Global::trace) {
      bit = BitPrint(1,b);
      fprintf(Global::tf," wrote %s = %d\n", bit, b);
      free(bit);
    }
    if (b) {mput1();}
    else {mput0();}
}

/*

mputv() puts a n bits to the stream from byte b.

*/


void mputv(int n,int b)
{
    char *bit;

    if (Global::trace) {
      bit = BitPrint(n, b);
      fprintf(Global::tf,"wrote %s = %d\n", bit, b);
      free(bit);
    }
    while(n--)
	{
	    if(b&bit_set_mask[n]) {mput1();}
	    else {mput0();}
	}
}


