/* Tests of fseek and fseeko.
   Copyright (C) 2000, 2001, 2002 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@redhat.com>, 2000.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

//#include <error.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#undef fseek
#undef ftell
#undef ftelli64

#define oint __off64_t

#include <windows.h>

void
error (status, errnum, message)
     int status;
     int errnum;
     char *message;
{
	fprintf(stderr, message);
	fprintf(stderr, strerror(errnum));
	if (status)
		exit(status);
}

//__off64_t
//ftello64 (fp)
//     FILE *fp;
//{
//  fpos_t pos;
//  fgetpos(fp, &pos);
//  return (__off64_t) pos;
//}
//off_t
//ftello (fp)
//     FILE *fp;
//{
//#ifdef  _LARGEFILE_SOURCE
//  return ftello64(fp);
//#else
//  return _ftell(fp);
//#endif
//}

#define printpos \
{ \
  fprintf(stderr, "ftell:    %lu\n", ftell(fp)); \
  fprintf(stderr, "ftello:   %I64u\n", (int64_t) ftello(fp)); \
  fprintf(stderr, "ftello64: %I64u\n",(int64_t) ftello64(fp)); \
  fprintf(stderr, "_tell:    %lu\n", _tell(fd)); \
  tl=_telli64(fd); \
  fprintf(stderr, "_telli64: %I64u\n", (int64_t) tl); \
  fgetpos(fp, &fpos); \
  fprintf(stderr, "fgetpos:  %I64u\n", (int64_t) fpos); \
}


#define fsp(fs) \
{ \
  fprintf(stderr,  #fs ); \
  fprintf(stderr, "\n"); \
  fs; \
  printpos;	\
  if (fgets(instr, 200, fp)) \
	  fprintf(stderr, "Instr:    %s.\n", instr); \
  else \
  	  fprintf(stderr, "EOF\n"); \
  printpos;	\
}

int
main (int argc, char *argv[])
{
  char *fname = "./tst-seek.in";
  int res, instrlen;
  char instr[200];
  int c, fs, fd, result = 0;
  oint os, tl, pos;
  FILE *fp;
  fpos_t fpos;
  uint64_t pow2;
  
  if (argc > 1)
  	fname = argv[1];
  if (!(fp = fopen (fname, "r")))
    error (EXIT_FAILURE, errno, "cannot get FILE for temporary file");
fprintf(stderr, "%s\n", fname);
//  pow2 = 1 <<30;
//  fprintf(stderr, "Sizeof fpos:          %ld\n", 8*sizeof(fpos_t));
//  fprintf(stderr, "Sizeof off_t:         %ld\n", 8*sizeof(off_t));
//  fprintf(stderr, "Sizeof _off_t:        %ld\n", 8*sizeof(_off_t));
//  fprintf(stderr, "Sizeof __off64_t:     %ld\n", 8*sizeof(__off64_t));
//  fprintf(stderr, "Sizeof long:          %ld\n", 8*sizeof(long));
//  fprintf(stderr, "Sizeof long long:     %ld\n", 8*sizeof(long long));
//  fprintf(stderr, "Sizeof unsigned long long: %ld\n", 8*sizeof(long long));
//  fprintf(stderr, "Sizeof int32:         %ld\n", 8*sizeof(int32_t));
//  fprintf(stderr, "Sizeof int64:         %ld\n", 8*sizeof(int64_t));
//  fprintf(stderr, "Sizeof uint64:        %ld\n", 8*sizeof(uint64_t));
//  fprintf(stderr, "Sizeof DWORD:         %ld\n", 8*sizeof(DWORD));
//  fprintf(stderr, "Sizeof LARGE_INTEGER: %ld\n", 8*sizeof(LARGE_INTEGER));
//  fprintf(stderr, "Sizeof ULARGE_INTEGER:%ld\n", 8*sizeof(ULARGE_INTEGER));
//  fprintf(stderr, "Sizeof 2^30:          %ld\n", 8*sizeof(2^30));
//  fprintf(stderr, "UINT64_MAX:           %ld\n", 8*sizeof(UINT64_MAX));
  fd = fileno(fp);
  fsp(fseeko(fp, 0LL, SEEK_SET));
//  printpos;
  c = fgetc(fp);
  c = fgetc(fp);
  printpos;
//  fprintf(stderr, "ftell:    %ld\n", ftell(fp)); 
//  fprintf(stderr, "ftello:   %I64d\n", ftello(fp));
//  fprintf(stderr, "ftello64: %I64d\n", ftello64(fp)); 
//  fprintf(stderr, "_tell:    %ld\n", _tell(fd)); 
//  fprintf(stderr, "_telli64: %I64d\n", (tl=_telli64(fd))); 
//  fprintf(stderr, "fgetpos:  %I64d\n", (fgetpos(fp, &fpos), fpos));

  fsp(fseeko64 (fp, 4LL, SEEK_SET));
  fsp(fseeko64 (fp, 8LL, SEEK_SET));
  fsp(fseeko64 (fp, 0LL, SEEK_END));
  fsp(fseeko64 (fp, -4LL, SEEK_END));
  fsetpos(fp, &fpos);
  printpos;
  fsp(fseeko64 (fp, 0LL, SEEK_CUR));
  fsp(fseeko64 (fp, -2LL, SEEK_CUR));
  fsp(fseeko64 (fp, 4LL, SEEK_CUR));
  return result;
}
