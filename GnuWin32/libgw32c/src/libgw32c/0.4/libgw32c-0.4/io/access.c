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
#include <stdio.h>
#include <windows.h>
#ifndef D_OK
# define D_OK (R_OK + W_OK + X_OK + F_OK + 1)
#endif

/* Test for access to FILE.  */
int
__access (file, type)
     const char *file;
     int type;
{
  DWORD attr = 0;
  int res = 0;
//  fprintf(stderr, "__access: file: %s\n", file);
  
  if (file == NULL || (type & ~(R_OK | W_OK | X_OK | F_OK | D_OK)) != 0) {
      __set_errno (EINVAL);
      return -1;
  }
  SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX);
  if ((attr = GetFileAttributes (file)) == INVALID_FILE_ATTRIBUTES) {
	  set_werrno; /* file does not exist or attributes cannot be read */
	  res = -1;
  }
  SetErrorMode(0);
  if (res == -1)
  	return -1;
  if ((type & D_OK) && !(attr & FILE_ATTRIBUTE_DIRECTORY)) {
  	__set_errno (EACCES);
  	return -1;
  }
  if ((type & W_OK) && (attr & FILE_ATTRIBUTE_READONLY)) {
  	__set_errno (EACCES);
  	return -1;
  }
  if (type & X_OK) /* all files that exist are executable */
	return 0;
  if (type & R_OK)  /* all files that exist are readable */
  	return 0;
  return 0;
}

weak_alias (__access, access)
