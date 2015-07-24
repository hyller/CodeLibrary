/* Copyright (C) 1991,1992,1995,1996,1997,2002 Free Software Foundation, Inc.
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

//#define _NO_OLDNAMES
//#define _STAT_DEFINED
#include <sys/stat.h>
//#include <stdio.h>

int
__lxstat (int version, const char *file, struct stat *buf)
{
     struct stat64 buf64;
     int res;

//	 fprintf(stderr, "__lxstat: %s\n", file);
     if ((res = __lxstat64 (version, file, &buf64)) == -1)
          return -1;
     stat64_to_32(&buf64, buf);
//	fprintf(stderr, "ino:  %ld\n", (long) buf->st_ino);
//	fprintf(stderr, "mode: %#o\n", (unsigned int) buf->st_mode);
//	fprintf(stderr, "uid:  %ld\n", (long) buf->st_uid);
//	fprintf(stderr, "gid:  %ld\n", (long) buf->st_gid);
//	fprintf(stderr, "dev:  %lu\n", (_dev_t) buf->st_dev);
//	fprintf(stderr, "rdev:  %lu\n", (_dev_t) buf->st_rdev);
//	fprintf(stderr, "nlink:%ld\n", (long) buf->st_nlink);
//	fprintf(stderr, "size: %ld\n", (long) buf->st_size);
//	fprintf(stderr, "atime:%ld: %s", buf->st_atime, ctime(buf->st_atime));
//	fprintf(stderr, "mtime:%ld: %s", buf->st_mtime, ctime(buf->st_mtime));
//	fprintf(stderr, "ctime:%ld: %s", buf->st_ctime, ctime(buf->st_ctime));
	
	 return res;
}
hidden_def (__lxstat)
weak_alias (__lxstat, _lxstat)
