/******************************************************************** 
 * "C+" -- Portable Object-Oriented Extension to C
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "cplus.h"
#include "qassert.h"

DEFINE_THIS_FILE;

ObjectVTABLE theObjectVTABLE = { 
   0,                                             /* no superclass */
   (void (*)(Object *))ObjectAbstract       /* purely virtual xtor */
};

int ObjectIsKindOf__(Object *me, void *vtable) {
   register ObjectVTABLE *vt;
   for (vt = me->vptr__; vt; vt = vt->super__) {
      if (vt == vtable) {
         return !0;
      }
   }      
   return 0;
}

void ObjectAbstract(void) {
   ASSERT(0);            /* abstract method should never be called */
}

