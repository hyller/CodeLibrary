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

#include "cparser4.h"
static CParser4 cparser;

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
   CParser4Ctor(&cparser);            /* explicitely call the Ctor */
   FsmInit((Fsm *)&cparser);            /* take initial transition */
   while ((ch = fgetc(f)) != EOF) {
       int sig;
       switch (ch) {
       case '/': sig = SLASH_SIG; break;
       case '*': sig = STAR_SIG;  break;
       default:  sig = CHAR_SIG;  break;
       }
       FsmDispatch((Fsm *)&cparser, sig);              /* dispatch */
       ++n; 
   }
   fclose(f);

   printf("file %s contains %ld comment characters, "
          "%ld total.\n", 
          argv[1], CParser4GetCommentCtr(&cparser), n);

   return 0;
}
