/********************************************************************
 * QP C-comment parser test harness
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include <stdlib.h>
#include <stdio.h>

#include "qassert.h"

DEFINE_THIS_FILE;

void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}

#include "cparser3.h"
static CParser3 cparser;

int main(int argc, char *argv[]) {
   FILE *f;
   long n = 0; 
   int ch;

   if (argc < 2) {
      printf("usage: %s <c-file>\n", argv[0]);
      return -1; 
   }
   f = fopen(argv[1], "r");
   if (!f) {
      printf("file %s cannot be opened for reading\n", argv[1]);
      return -1; 
   }

   n = 0;
   CParser3Ctor(&cparser);            /* explicitely call the Ctor */
   CParser3Init(&cparser);              /* take initial transition */
   while ((ch = fgetc(f)) != EOF) {
      switch (ch) {
      case '/': CParser3onSLASH(&cparser); break;
      case '*': CParser3onSTAR(&cparser);  break;
      default:  CParser3onCHAR(&cparser, (char)ch); break;
      } 
      ++n; 
   }
   fclose(f);

   printf("file %s contains %ld comment characters, "
          "%ld total.\n", 
          argv[1], CParser3GetCommentCtr(&cparser), n);

   return 0;
}
