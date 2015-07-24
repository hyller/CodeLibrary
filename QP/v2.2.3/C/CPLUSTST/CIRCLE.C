/******************************************************************** 
 * "C+" test sample code
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "circle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

BEGIN_VTABLE(Circle, Shape)
   VMETHOD(Shape, area) = (double (*)(Shape *))CircleArea;
   VMETHOD(Shape, scale) = 
                        (void (*)(Shape *, double))CircleScale;
END_VTABLE

Circle *CircleCtor(Circle *me, char *name, double r) {
   if (!ShapeCtor_(&me->super_, name)) {   /* construct superclass */
      return NULL;                               /* report failure */
   }
   VHOOK(Circle);                             /* hook Circle class */
   me->r__ = r;                            /* initialise member(s) */
   return me;
}

double CircleArea(Circle *me) {
   return 3.141592535 * me->r__ * me->r__;       /* pi * r-squared */
}

void CircleScale(Circle *me, double mag) {
   me->r__ *= mag;
}
    
