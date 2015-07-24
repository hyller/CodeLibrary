/******************************************************************** 
 * "C+" test sample code
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "shape.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DEFINE_THIS_FILE;

/* tests for abstract Shape (independent on concrete sublcasses)..*/
void testArea(Shape *s) {
   ASSERT(ObjectIS_KIND_OF(s, Shape));
   printf("name=\"%s\", area()=%.2f, ",
          StringToChar(&s->name),                /* static binding */
          VCALL(Shape, area, s)END_CALL);       /* dynamic binding */
}

void testScale(Shape *s) {
   double mag = 2.0;
   ASSERT(ObjectIS_KIND_OF(s, Shape));
   printf("scale(%.0f), ", mag);
   VCALL(Shape, scale, s), mag END_CALL;        /* dynamic binding */
}

/* ................................................................*/
#include "circle.h"
#include "rect.h"
enum { NRECT = 4 };

int main() {
   Circle circle;            /* Circle instance on the stack frame */
   Circle *c;
   Rect r[NRECT]; 
   int i;

   /* construct objects... */
   c = CircleCtor(&circle, "Circle", 1.0);
   for (i = 0; i < NRECT; i++) {
      char name[20];
      sprintf(name, "Rectangle-%d", i);        /* prepare the name */
      RectCtor(&r[i], name, (double)i, 1.0);     /* construct Rect */
   }

   /* test each object... */
   testArea((Shape *)c);
   testScale(&c->super_);
   testArea((Shape *)c);
   printf("\n");
   for (i = 0; i < NRECT; i++) {
      testArea((Shape *)&r[i]);
      testScale(&r[i].super_);
      testArea((Shape *)&r[i]);
      printf("\n");
   }
   /* detstroy objects... */
   VCALL(Object, xtor, c)END_CALL;              /* dynamic binding */
   for (i = 0; i < NRECT; i++) {
      VCALL(Object, xtor, &r[i])END_CALL;
   }
   return 0;
}
    
void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}

