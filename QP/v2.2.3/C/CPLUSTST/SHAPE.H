/******************************************************************** 
 * "C+" test sample code
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef shape_h
#define shape_h

#include "cplus.h"

SUBCLASS(String, Object)
   char *buf__;                        /* private character buffer */
VTABLE(String, Object)
METHODS
   String *StringCtor1(String *me, const char *str); /*public Ctor1*/
   String *StringCtor2(String *me, String *other);   /*public Ctor2*/
   void StringXtor(String *me);                     /* public Xtor */
   const char *StringToChar(String *me);     /* to-char conversion */
END_CLASS

SUBCLASS(Shape, Object)
   String name;                             /* public shape's name */
VTABLE(Shape, Object)
   double (*area)(Shape *me);                     /* pure virtual! */
   void (*scale)(Shape *me, double mag);          /* pure virtual! */
METHODS
   Shape *ShapeCtor_(Shape *me, char *name);     /* protected Ctor */
   void ShapeXtor_(Shape *me);                   /* protected Xtor */
END_CLASS

#endif