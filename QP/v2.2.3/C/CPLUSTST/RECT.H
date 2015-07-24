/******************************************************************** 
 * "C+" test sample code
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef rect_h
#define rect_h

#include "shape.h"
                                                                          
SUBCLASS(Rect, Shape)                  /* Class Rect extends Shape */
   double w__;                                   /* private width  */
   double h__;                                   /* private height */
VTABLE(Rect, Shape)
METHODS
   Rect *RectCtor(Rect *me, char *name, double w, double h);
   double RectArea(Rect *me);
   void RectScale(Rect *me, double mag);
END_CLASS

#endif