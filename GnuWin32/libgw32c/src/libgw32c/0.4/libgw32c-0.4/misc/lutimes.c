/* lutimes -- change access and modification times of a symlink.  Stub version.
   Copyright (C) 2002 Free Software Foundation, Inc.
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

#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <stddef.h>
#include <windows.h>


static void 
TimeValToFileTime (const struct timeval *p, FILETIME *ft)
{
	ULARGE_INTEGER fti;

	fti.QuadPart = UInt32x32To64 (p->tv_sec + ft70sec, 10000000) + p->tv_usec * 10;
	ft->dwHighDateTime = fti.HighPart;
	ft->dwLowDateTime = fti.LowPart;
}


/* Change the access time of HANDLE to TVP[0] and
   the modification time of HANDLE to TVP[1], but do not follow symlinks.  */
int
__hutimes (const HANDLE h, const char *file, const struct timeval tvp[2])
{
	FILETIME lastaccess, lastwrite;

	if (h == INVALID_HANDLE_VALUE) {
		if (GetFileAttributes (file) & FILE_ATTRIBUTE_DIRECTORY)
			return 0;
		else {
			set_werrno;
			return -1;
		}
	}
	if (!tvp) {
		GetSystemTimeAsFileTime (&lastaccess);	 /* 100-nanoseconds since 1-1-1601 */
		lastwrite = lastaccess;
	} else {
		TimeValToFileTime (&tvp[0], &lastaccess);
		TimeValToFileTime (&tvp[1], &lastwrite);
	}
    if (!SetFileTime (h, NULL, &lastaccess, &lastwrite)) {
		set_werrno;
		return -1;
	} else
		return 0;
}

/* Change the access time of FILE to TVP[0] and
   the modification time of FILE to TVP[1], but do not follow symlinks.  */
int
__lutimes (const char *file, const struct timeval tvp[2])
{
	int res = 0;
	HANDLE h = CreateFile (file, FILE_WRITE_ATTRIBUTES,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_BACKUP_SEMANTICS,
		NULL);
	res = __hutimes(h, file, tvp);
	CloseHandle (h);
	return res;
}

weak_alias (__lutimes, lutimes)
