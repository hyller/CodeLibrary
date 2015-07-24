/******************************************************************** 
 * "C+" test sample code
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "rect.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                                      
BEGIN_VTABLE(Rect, Shape)
   VMETHOD(Shape, area) = (double (*)(Shape *))RectArea;
   VMETHOD(Shape, scale) = (void (*)(Shape *, double))RectScale;
END_VTABLE

Rect *RectCtor(Rect *me, char *name, double w, double h) {
   if (!ShapeCtor_(&me->super_, name)) {   /* construct superclass */
      return NULL;                               /* report failure */
   }
   VHOOK(Rect);                                 /* hook Rect class */
   me->h__ = h;                            /* initialise member(s) */
   me->w__ = w;
   return me;
}

double RectArea(Rect *me) {
   return me->w__  * me->h__;
}

void RectScale(Rect *me, double mag){
   me->w__ *= mag;
   me->h__ *= mag;
}

