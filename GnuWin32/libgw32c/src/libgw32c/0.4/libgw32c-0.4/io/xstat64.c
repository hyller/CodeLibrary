/* Copyright (C) 1991, 1995, 1996, 1997, 2002 Free Software Foundation, Inc.
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
#include <sys/stat.h>
#include <unistd.h>

/* Get file information about FILE in BUF.  */
int
__xstat64 (int __ver, __const char *__filename,
                struct stat64 *__stat_buf)
{
  int res;

//	fprintf(stderr, "__xstat64: filename: %s\n", __filename);
  res = __lxstat64(__ver, __filename, __stat_buf);
  if ((res != -1) && S_ISLNK (__stat_buf->st_mode)) {
    char linkname[MAX_PATH];
//	fprintf(stderr, "__xstat64: ISLNK: %s\n", __filename);
//	fprintf(stderr, "__xstat64: st_mode: %#o\n", __stat_buf->st_mode);
//	fprintf(stderr, "__xstat64: S_ISLNK(st_mode): %d\n", S_ISLNK(__stat_buf->st_mode));
	if (readlink (__filename, linkname, MAX_PATH) == -1)
		return -1;
	res = __lxstat64(__ver, linkname, __stat_buf);
//	fprintf(stderr, "__xstat64: linkname: %s\n", linkname);
  }		
  return res;
}
hidden_def (__xstat64)
