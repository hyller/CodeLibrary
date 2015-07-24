/* Copyright (C) 1991, 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <errno.h>
#include <stddef.h>
#include <strings.h>
#include <dirent.h>
#include <assert.h>
//#include <stdio.h>

/* Read a directory entry from DIRP.  */
struct dirent *
__readdir (DIR *dirp)
{
  struct dirent64 *entry64 = readdir64 (dirp);
  if (entry64 == NULL)
  	return NULL;

  if (sizeof (struct dirent64) == sizeof (struct dirent))
    return (struct dirent *) entry64;

  struct dirent *const entry = ((void *) (&entry64->d_ino + 1)
                    - sizeof entry->d_ino);
  /* These are all compile-time constants.  We know that d_ino is the first
     member and that the layout of the following members matches exactly in
     both structures.  */
  assert (offsetof (struct dirent, d_ino) == 0);
  assert (offsetof (struct dirent64, d_ino) == 0);
//  printf( "%d \n", offsetof (struct dirent64, d_reclen));
//  printf( "%d \n", sizeof (entry64->d_ino));
//  printf( "%d \n", offsetof (struct dirent, d_reclen));
//  printf( "%d \n", sizeof (__ino_t));
# define MATCH(memb)                                         \
  assert (offsetof (struct dirent64, memb) - sizeof (entry64->d_ino)        \
       == offsetof (struct dirent, memb) - sizeof (entry->d_ino))
  MATCH (d_reclen);
  MATCH (d_type);
  MATCH (d_namlen);
# undef MATCH

  return entry;
}
weak_alias (__readdir, readdir)

