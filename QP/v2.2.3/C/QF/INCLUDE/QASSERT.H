/********************************************************************
 * Quantum Assertions--Design by Contract(TM of ISI) facilities
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/

#ifndef qassert_h
#define qassert_h

#ifdef __cplusplus
extern "C" {
#endif

/** NASSERT macro disables all contract validations
 * (assertions, preconditions, postconditions, and invariants).
 */  
#ifndef NASSERT 
                  /* callback invoked in case of assertion failure */
extern void onAssert__(char const *file, unsigned line);

#define DEFINE_THIS_FILE \
   static const char THIS_FILE__[] = __FILE__

#define ASSERT(test_)\
   if (test_) {      \
   }                 \
   else onAssert__(THIS_FILE__, __LINE__)

#define REQUIRE(test_)   ASSERT(test_)
#define ENSURE(test_)    ASSERT(test_)
#define INVARIANT(test_) ASSERT(test_)
#define ALLEGE(test_)    ASSERT(test_)

#else                                           /* #ifndef NASSERT */

#define DEFINE_THIS_FILE extern const char THIS_FILE__[]
#define ASSERT(test_)    
#define REQUIRE(test_)   
#define ENSURE(test_)    
#define INVARIANT(test_) 
#define ALLEGE(test_)\
   if (test_) {      \
   }                 \
   else

#endif

#ifdef __cplusplus
}
#endif

#endif                                                /* qassert_h */
