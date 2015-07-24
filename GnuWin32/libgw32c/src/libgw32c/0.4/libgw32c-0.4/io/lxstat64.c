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
#include <stddef.h>
#include <sys/stat.h>
#include <gw32.h>

//#include <stdio.h>

/* Get file information about FILE in BUF.
   If FILE is a symbolic link, do not follow it.  */
int
__lxstat64 (int __ver, __const char *__filename,
                struct stat64 *__stat_buf)
{
int res;
//  fprintf(stderr, "in __lxstat64\n");
  if (__ver != _STAT_VER || __filename == NULL || __stat_buf == NULL)
    {
      __set_errno (EINVAL);
      return -1;
    }
  res = __cxstat64(__filename, __stat_buf);
//  fprintf(stderr, "__lxstat64 res: %d\n", res);
//	fprintf(stderr, "__lxstat64: __filename %s   ino:  %I64u\n", __filename, (__int64) __stat_buf->st_ino);
//	fprintf(stderr, "__lxstat64: __filename %s   dev:  %I64u\n", __filename, (__dev_t) __stat_buf->st_dev);
  return res;
}
hidden_def (__lxstat64)
