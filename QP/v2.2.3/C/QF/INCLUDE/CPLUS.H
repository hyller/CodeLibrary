/******************************************************************** 
 * "C+" -- Portable Object-Oriented Extension to C
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef cplus_h
#define cplus_h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Macros for declaring simple classes (without polymorphism)
 */
#define CLASS(name_)          \
   typedef struct name_ name_;\
   struct name_ {
#define METHODS };
#define END_CLASS

/**
 * Abstract base class 'Object', root of all classes with
 * polymorphism
 */
CLASS(Object) 
   struct ObjectVTABLE *vptr__;         /* private virtual pointer */
METHODS
                              /* protected constructor 'inline'... */
#  define ObjectCtor_(me_) ((me_)->vptr__ = &theObjectVTABLE, (me_))
                               /* protected destructor 'inline'... */
#  define ObjectXtor_(me_) ((void)0)
                      /* dummy implementation for abstract methods */
    void ObjectAbstract(void);
                                                           /* RTTI */
#   define ObjectIS_KIND_OF(me_, class_) \
        ObjectIsKindOf__((Object *)(me_), &the##class_##VTABLE)
    int ObjectIsKindOf__(Object *me, void *class);
END_CLASS

CLASS(ObjectVTABLE)
   ObjectVTABLE *super__;           /* pointer to superclass' VTBL */
   void (*xtor)(Object *);            /* public virtual destructor */
METHODS
END_CLASS

extern ObjectVTABLE theObjectVTABLE;    /* Object class descriptor */

/**
 * Macros for declaring subclasses
 */
#define SUBCLASS(class_, superclass_) \
   CLASS(class_)                      \
      superclass_ super_;

/**
 * Macros for defining VTABLEs and binding virtual functions
 */
#define VTABLE(class_, superclass_) };          \
   typedef struct class_##VTABLE class_##VTABLE;\
   extern class_##VTABLE the##class_##VTABLE;   \
   struct class_##VTABLE {                      \
      superclass_##VTABLE super_;

#define BEGIN_VTABLE(class_, superclass_)                  \
   class_##VTABLE the##class_##VTABLE;                     \
   static ObjectVTABLE *class_##VTABLECtor(class_ *t) {    \
      register class_##VTABLE *me = &the##class_##VTABLE;  \
      *(superclass_##VTABLE *)me =                         \
          *(superclass_##VTABLE *)((Object *)t)->vptr__;

#define VMETHOD(class_, meth_) ((class_##VTABLE *)me)->meth_

#define END_VTABLE\
      ((ObjectVTABLE*)me)->super__ = ((Object*)t)->vptr__; \
      return (ObjectVTABLE *)me;                           \
   }

/**
 * Macro to hook virtual pointer used in constructors
 */
#define VHOOK(class_)                                      \
   if (((ObjectVTABLE *)&the##class_##VTABLE)->super__== 0)\
       ((Object *)me)->vptr__ = class_##VTABLECtor(me);    \
   else                                                    \
       ((Object *)me)->vptr__ =                            \
                  (ObjectVTABLE *)&the##class_##VTABLE

/**
 * Macro to access v-pointer
 */
#define VPTR(class_, obj_) \
    ((class_##VTABLE *)(((Object *)(obj_))->vptr__)) 

/**
 * Macro for invoking virtual class methods
 * and macro for invoking interface methods.
 */
#define VCALL(class_, meth_, obj_)\
   (*VPTR(class_, obj_)->meth_)((class_*)(obj_)
#define END_CALL )

/**
 * Find an offset of a member into its class
 */
#define OFFSET_OF(class_, attr_) \
   ((unsigned)&((class_ *)0)->attr_)

#ifdef __cplusplus
}
#endif

#endif                                                  /* cplus_h */
