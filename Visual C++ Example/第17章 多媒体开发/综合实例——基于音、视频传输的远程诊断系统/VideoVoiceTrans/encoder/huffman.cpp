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
//    Name    : huffman.cpp
//
//
/////////////////////////////////////////////////////////////////////////////

/*****************************************************************
 * tmn (TMN encoder) 
 * Copyright (C) 1995 Telenor R&D
 *                    Karl Olav Lillevold <kol@nta.no>                    
 *
 * These routines are written by Andy C. Hung
 *
 *****************************************************************/

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
huffman.c

This file contains the Huffman routines.  They are constructed to use
no look-ahead in the stream.

************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"
#include "ctables.h"


#define MakeStructure(S) (S *) malloc(sizeof(S))

EHUFF *vlc_3d;
EHUFF *vlc_cbpcm;
EHUFF *vlc_cbpcm_intra;
EHUFF *vlc_cbpy;
EHUFF *vlc_mv;

/**********************************************************************
 *
 *	Name:		InitHuff
 *	Description:   	Initializes vlc-tables
 *	
 *	Input:	      
 *	Returns:       
 *	Side effects:
 *
 *	Date: 941128	Author: Karl.Lillevold@ta.no
 *			        Idea: see above
 *
 ***********************************************************************/

void InitHuff()
{
  vlc_3d = MakeEhuff(8192);
  vlc_cbpcm = MakeEhuff(256);
  vlc_cbpcm_intra = MakeEhuff(256);
  vlc_cbpy = MakeEhuff(16);
  vlc_mv = MakeEhuff(65);
  LoadETable(vlc_3d_coeff,vlc_3d);
  LoadETable(vlc_cbpcm_coeff,vlc_cbpcm);
  LoadETable(vlc_cbpcm_intra_coeff,vlc_cbpcm_intra);
  LoadETable(vlc_cbpy_coeff,vlc_cbpy);
  LoadETable(vlc_mv_coeff,vlc_mv);
  return;
}

/* FreeHuff(): Frees the VLC-tables */
void FreeHuff()
{
  FreeEhuff(vlc_3d);
  FreeEhuff(vlc_cbpcm);
  FreeEhuff(vlc_cbpcm_intra);
  FreeEhuff(vlc_cbpy);
  FreeEhuff(vlc_mv);
}
    
/*
MakeEhuff() constructs an encoder huff with a designated table-size.
This table-size, n, is used for the lookup of Huffman values, and must
represent the largest positive Huffman value.

*/

EHUFF *MakeEhuff(int n)
{
    int i;
    EHUFF *temp;

    temp = MakeStructure(EHUFF);
    temp->n = n;
    temp->Hlen = (int *) calloc(n,sizeof(int));
    temp->Hcode = (int *) calloc(n,sizeof(int));
    for(i=0;i<n;i++)
	{
	    temp->Hlen[i] = -1;
	    temp->Hcode[i] = -1;
	}
    return(temp);
}

void FreeEhuff(EHUFF *eh)
{
    free(eh->Hlen);
    free(eh->Hcode);
    free(eh);
}

/*

LoadETable() is used to load an array into an encoder table.  The
array is grouped in triplets and the first negative value signals the
end of the table.

*/

void LoadETable(int *array,EHUFF *table)
{
    while(*array>=0)
	{
	    if (*array>table->n)
		{
		    printf("Table overflow.\n");
		    exit(-1);
		}
	    table->Hlen[*array] = array[1];
	    table->Hcode[*array] = array[2];
	    array+=3;
	}
}

/*

PrintEhuff() prints the encoder Huffman structure passed into it.

*/

/*$void PrintEhuff(EHUFF *huff)
{
    int i;

    printf("Modified Huffman Encoding Structure: %x\n",&huff);
    printf("Number of values %d\n",huff->n);
    for(i=0;i<huff->n;i++)
	{
	    if (huff->Hlen[i]>=0)
		{
		    printf("Value: %x  Length: %d  Code: %x\n",
			   i,huff->Hlen[i],huff->Hcode[i]);
		}
	}
}$*/

/*

PrintTable() prints out 256 elements in a nice byte ordered fashion.

*/

void PrintTable(int *table)
{
    int i,j;

    for(i=0;i<16;i++)
	{
	    for(j=0;j<16;j++)
		printf("%2x ",*(table++));
	    printf("\n");
	}
}

/*
Encode() encodes a symbol according to a designated encoder Huffman
table out to the stream. It returns the number of bits written to the
stream and a zero on error.
*/

int Encode(int val,EHUFF *huff)
{

    if (val < 0)
	{
	    fprintf(stderr,"Out of bounds val:%d.\n",val);
	    fflush(Global::tf);
	    exit(-1);
	}
    else if (val >= huff->n) {
	return 0; /* No serious error, can occur with some values */
    }
    else if (huff->Hlen[val] < 0) {
	return 0;
    }
    else {
	mputv(huff->Hlen[val],huff->Hcode[val]); 
	return(huff->Hlen[val]);
    }
}


char *BitPrint(int length, int val)
{
    int m;
    char *bit = (char *)malloc(sizeof(char)*(length+3));

    m = length;
    bit[0] = '"';
    while (m--) 
	bit[length-m] = (val & (1<<m)) ? '1' : '0';
    bit[length+1] = '"';
    bit[length+2] = '\0';
    return bit;
}


