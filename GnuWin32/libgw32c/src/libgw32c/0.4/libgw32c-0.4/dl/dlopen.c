/* Load a shared object at run time.
   Copyright (C) 1995,96,97,98,99,2000 Free Software Foundation, Inc.
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

#include <dlfcn.h>
#include <stddef.h>
#include <windows.h>
#include <errno.h>
#include <gw32.h>

void
*dlopen(const char *name, int mode)
{
  HINSTANCE hdll = NULL;
  DWORD flags = 0;

  unix2winpath (name);
  switch (mode) {
  	case RTLD_LAZY:
		flags = DONT_RESOLVE_DLL_REFERENCES;
  }
  if (!name)
  	hdll = GetModuleHandle (NULL);
  else
    hdll = LoadLibraryEx (name, NULL, flags);
  if (!hdll) {
  	set_werrno;
	return -1;
  }
  return (void *) hdll;
}
