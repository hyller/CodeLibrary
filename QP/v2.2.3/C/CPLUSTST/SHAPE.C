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

/* implementation of String ---------------------------------------*/
BEGIN_VTABLE(String, Object)
   VMETHOD(Object, xtor) = (void (*)(Object *))StringXtor;
END_VTABLE

String *StringCtor1(String *me, const char *str) {
   ObjectCtor_(&me->super_);              /* construct superclass  */
   VHOOK(String);                      /* hook on the String class */
   me->buf__ = (char *)malloc(strlen(str) + 1);
   if (!me->buf__) {
      return NULL;                               /* report failure */
   }
   strcpy(me->buf__, str);
   return me;
}
String *StringCtor2(String *me, String *other) {
   return StringCtor1(me, StringToChar(other));
}
const char *StringToChar(String *me) {
   return me->buf__;
}
void StringXtor(String *me) {
   free(me->buf__);                              /* release buffer */ 
   ObjectXtor_(&me->super_);                 /* destroy superclass */
}

/* implementation of Shape ----------------------------------------*/
BEGIN_VTABLE(Shape, Object)
   VMETHOD(Object, xtor) = (void (*)(Object *))ShapeXtor_;
   VMETHOD(Shape, area) = (double (*)(Shape *))ObjectAbstract;
   VMETHOD(Shape, scale) = 
                      (void (*)(Shape *, double))ObjectAbstract;
END_VTABLE

Shape *ShapeCtor_(Shape *me, char *name) {
   ObjectCtor_(&me->super_);               /* construct superclass */
   VHOOK(Shape);                               /* hook Shape class */
   if (!StringCtor1(&me->name, name)) {        /* construct member */
      return NULL;                               /* report failure */
   }
   return me;
}
void ShapeXtor_(Shape *me) {
   StringXtor(&me->name);                        /* destroy member */
   ObjectXtor_(&me->super_);                 /* destroy superclass */
}


