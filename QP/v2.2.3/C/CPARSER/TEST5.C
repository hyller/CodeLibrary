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

#include "cparser5.h"
static CParser5 cparser;

static QEvent cparser5Evts[] = {
    { SLASH_SIG, 0, 0 }, { STAR_SIG,  0, 0 }, { CHAR_SIG,  0, 0 }
};

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
   CParser5Ctor(&cparser);            /* explicitely call the Ctor */
   QFsmInit((QFsm *)&cparser, 0);       /* take initial transition */
   while ((ch = fgetc(f)) != EOF) {
       QEvent *e;
       switch (ch) {
       case '/': e = &cparser5Evts[0]; break;
       case '*': e = &cparser5Evts[1]; break;
       default:  e = &cparser5Evts[2]; break;
       }
       QFsmDispatch((QFsm *)&cparser, e);              /* dispatch */
       ++n; 
   }
   fclose(f);
   
   printf("file %s contains %ld comment characters, "
          "%ld total.\n", 
          argv[1], CParser5GetCommentCtr(&cparser), n);

   return 0;
}
