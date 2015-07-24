/* Copyright (C) 1991, 1995, 1996, 1997 Free Software Foundation, Inc.
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
#include <unistd.h>
#define _NO_OLDNAMES
#define _STAT_DEFINED
#include <sys/stat.h>
#include <windows.h>

/* Remove the link named NAME.  */
int
__unlink (name)
     const char *name;
{
  int old_errno;
  
  if (name == NULL) {
      __set_errno (EINVAL);
      return -1;
  }
  old_errno = errno;
  if (__access (name, W_OK)) {
//    printf ("%s !W_OK\n", name);
  	_chmod (name, _S_IREAD | _S_IWRITE);
  }
  if (!__access (name, D_OK)) {
//    printf ("%s D_OK\n", name);
  __set_errno (EISDIR);
  return -1;
  }
  __set_errno (old_errno);
  if (!DeleteFile ((LPCTSTR) name)) {
//  if (_unlink (name)) {
  	set_werrno;
//  WinErr (name);
	return -1;
  }
  return 0;
}

weak_alias (__unlink, unlink)
