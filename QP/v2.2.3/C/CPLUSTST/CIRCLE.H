/******************************************************************** 
 * "C+" test sample code
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef circle_h
#define circle_h

#include "shape.h"
                                                                          
SUBCLASS(Circle, Shape)              /* Class Circle extends Shape */
   double r__;                                   /* private radius */
VTABLE(Circle, Shape)
METHODS
   Circle *CircleCtor(Circle *me, char *name, double r);
   double CircleArea(Circle *me);
   void CircleScale(Circle *me, double mag);
END_CLASS

#endif