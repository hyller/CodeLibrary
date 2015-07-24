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

#include <sys/stat.h>
#include <windows.h>

void stat64_to_32(struct stat64 *buf64, struct stat *buf32)
{
	buf32->st_ino = (_ino_t) (((LODWORD(buf64->st_ino))
			^ ((LODWORD(buf64->st_ino)) >> 16))
		^ ((HIDWORD(buf64->st_ino))
			^ ((HIDWORD(buf64->st_ino)) >> 16)) );
	buf32->st_mode = buf64->st_mode;	
	buf32->st_uid = buf64->st_uid;	
	buf32->st_gid = buf64->st_gid;	
	buf32->st_dev = buf64->st_dev;	
	buf32->st_nlink = buf64->st_nlink;	
	buf32->st_rdev = buf64->st_rdev;	
	buf32->st_size = (_off_t) (LODWORD(buf64->st_size));	
	buf32->st_blksize  = buf64->st_blksize;
	buf32->st_blocks   = (__blkcnt_t) buf32->st_blocks;
	buf32->st_mode = buf64->st_mode;	
	buf32->st_atime = buf64->st_atime;	
	buf32->st_mtime = buf64->st_mtime;	
	buf32->st_ctime = buf64->st_ctime;
}

