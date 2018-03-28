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
//    Name    : rlib.cpp
//    Details : Reading and writing to file...
//
/////////////////////////////////////////////////////////////////////////////


#include "rlib.h"
//#include "owntypes.h"

int ReadQCIF(FILE *f, struct qcif *qc)
{
  struct qcif8bit source;
  int i;
  int file_err;
  unsigned int *ud;
  unsigned char *us;

  file_err = fread(&source, sizeof(source), 1, f);

  if(file_err != 1)
    return FALSE;

  us = &source.Y[0][0];
  ud = &qc->Y[0][0];
  
  for(i = 0; i < QCIF_YWIDTH*QCIF_YHEIGHT; i++)
    *ud++ = (unsigned int) *us++;
  
  us = &source.U[0][0];
  ud = &qc->U[0][0];
  
  for(; i < QCIF_YWIDTH*QCIF_YHEIGHT + QCIF_UWIDTH*QCIF_UHEIGHT + 
	QCIF_VWIDTH*QCIF_VHEIGHT; i++)
    *ud++ = (signed int) *us++;

  return TRUE;
}

int ReadCIF(FILE *f, struct cif *qc)
{
  struct cif8bit source;
  int i;
  int file_err;
  unsigned int *ud;
  unsigned char *us;

  file_err = fread(&source, sizeof(source), 1, f);

  if(file_err != 1)
    return FALSE;

  us = &source.Y[0][0];
  ud = &qc->Y[0][0];
  
  for(i = 0; i < CIF_YWIDTH*CIF_YHEIGHT; i++)
    *ud++ = (unsigned int) *us++;
  
  us = &source.U[0][0];
  ud = &qc->U[0][0];
  
  for(; i < CIF_YWIDTH*CIF_YHEIGHT + CIF_UWIDTH*CIF_UHEIGHT + 
	CIF_VWIDTH*CIF_VHEIGHT; i++)
    *ud++ = (signed int) *us++;

  return TRUE;
}

int WriteQCIF(FILE *f, struct qcif *qc)
{
  struct qcif8bit dest;
  int i;
  int file_err;
  unsigned char *ud;
  unsigned int *us;

  us = &qc->Y[0][0];
  ud = &dest.Y[0][0];
  
  for(i = 0; i < QCIF_YWIDTH*QCIF_YHEIGHT; i++)
    *ud++ = (unsigned char) *us++;
  
  us = &qc->U[0][0];
  ud = &dest.U[0][0];

  for(; i < QCIF_YWIDTH*QCIF_YHEIGHT + QCIF_UWIDTH*QCIF_UHEIGHT + 
	QCIF_VWIDTH*QCIF_VHEIGHT; i++)
    *ud++ = (unsigned char) *us++;

 file_err = fwrite(&dest, sizeof(dest), 1, f);

 return (file_err == 1);

}

int WriteCIF(FILE *f, struct cif *qc)
{
  struct cif8bit dest;
  int i;
  int file_err;
  unsigned char *ud;
  unsigned int *us;

  us = &qc->Y[0][0];
  ud = &dest.Y[0][0];
  
  for(i = 0; i < CIF_YWIDTH*CIF_YHEIGHT; i++)
    *ud++ = (unsigned char) *us++;
  
  us = &qc->U[0][0];
  ud = &dest.U[0][0];

  for(; i < CIF_YWIDTH*CIF_YHEIGHT + CIF_UWIDTH*CIF_UHEIGHT + 
	CIF_VWIDTH*CIF_VHEIGHT; i++)
    *ud++ = (unsigned char) *us++;

 file_err = fwrite(&dest, sizeof(dest), 1, f);

 return (file_err == 1);

}
