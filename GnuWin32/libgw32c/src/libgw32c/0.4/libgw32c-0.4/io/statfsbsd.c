/* Return information about the filesystem on which FILE resides.
   Copyright (C) 1998 Free Software Foundation, Inc.
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

#include <errno.h>
#include <sys/statfsbsd.h>
#include <sys/statfsx.h>
#include <stddef.h>
#include <windows.h>
#include <stdio.h>
#include <limits.h>
//#include <libc/sys/fsinfo.h>

/* Return information about the filesystem on which FILE resides.  */
int
__statfsbsd (const char *file, struct statfsbsd *buf)
{
	struct statfsx64 xbuf;
	int res;
     
	res = __statfsx64(file, &xbuf);
	buf->f_bsize = (long) xbuf.f_bsize;
	buf->f_iosize = (long) xbuf.f_iosize;
	buf->f_blocks = (long) xbuf.f_blocks;
	buf->f_bfree = (long) xbuf.f_bfree;
	buf->f_bavail = (long) xbuf.f_bavail;
	buf->f_files = (long) xbuf.f_files;
	buf->f_ffree = (long) xbuf.f_ffree;
	buf->f_fsid.val[0] = (__int32_t) xbuf.f_fsid.__val[0];
	buf->f_fsid.val[1] = (__int32_t) xbuf.f_fsid.__val[1];
	buf->f_owner = (__uid_t) xbuf.f_owner;
	buf->f_type = (int) xbuf.f_type;
	buf->f_flags = (int) xbuf.f_flag;
	buf->f_namelen = (unsigned int) xbuf.f_namelen;
	buf->f_spare[0] = 0;
	buf->f_spare[1] = 0;
    strncpy(buf->f_fstypename, xbuf.f_fstypename, MFSNAMELEN);
    strncpy(buf->f_mntonname, xbuf.f_mntonname, MNAMELEN);
    strncpy(buf->f_mntfromname, xbuf.f_mntfromname, MNAMELEN);
	return res;
}
weak_alias (__statfsbsd, statfsbsd)
