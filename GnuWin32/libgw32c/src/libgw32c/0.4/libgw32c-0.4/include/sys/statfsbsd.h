/* Definitions for getting information about a filesystem.
   Copyright (C) 1996, 1997, 1998, 1999 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#ifndef	_SYS_STATFSBSD_H
#define	_SYS_STATFSBSD_H	1

#include <features.h>

/* Get the system-specific definition of `struct statfs'.  */
#include <bits/statfsbsd.h>

__BEGIN_DECLS

/* Return information about the filesystem on which FILE resides.  */
#ifndef __USE_FILE_OFFSET64
extern int statfsbsd (__const char *__file, struct statfsbsd *__buf) __THROW;
#else
# ifdef __REDIRECT
extern int __REDIRECT (statfsbsd,
		       (__const char *__file, struct statfsbsd *__buf) __THROW,
		       statfsbsd64);
# else
#  define statfsbsd statfsbsd64
# endif
#endif
#ifdef __USE_LARGEFILE64
extern int statfsbsd64 (__const char *__file, struct statfsbsd64 *__buf) __THROW;
#endif

/* Return information about the filesystem containing the file FILDES
   refers to.  */
#ifndef __USE_FILE_OFFSET64
extern int fstatfsbsd (int __fildes, struct statfsbsd *__buf) __THROW;
#else
# ifdef __REDIRECT
extern int __REDIRECT (fstatfsbsd, (int __fildes, struct statfsbsd *__buf) __THROW,
		       fstatfsbsd64);
# else
#  define fstatfsbsd fstatfsbsd64
# endif
#endif
#ifdef __USE_LARGEFILE64
extern int fstatfsbsd64 (int __fildes, struct statfsbsd64 *__buf) __THROW;
#endif

__END_DECLS

#endif	/* sys/statfsbsd.h */
