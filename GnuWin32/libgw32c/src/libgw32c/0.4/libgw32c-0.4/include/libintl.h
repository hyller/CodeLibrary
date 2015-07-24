#include_next <libintl.h>

#define __dcgettext dcgettext

extern const char _libc_intl_domainname[];
extern const char _libc_intl_domainname_internal[] attribute_hidden;

/* Define the macros `_' and `N_' for conveniently marking translatable
   strings in the libc source code.  We have to make sure we get the
   correct definitions so we undefine the macros first.  */

# undef N_
# define N_(msgid)  msgid

# undef _
/* This is defined as an optimizing macro, so use it.  */
# if !defined NOT_IN_libc && defined SHARED
#  define _(msgid) \
  __dcgettext_internal (_libc_intl_domainname_internal, msgid, LC_MESSAGES)
# else
#  define _(msgid) \
  __dcgettext (_libc_intl_domainname, msgid, LC_MESSAGES)
#endif

#undef _
#ifndef _
# define _(s) s
#endif
