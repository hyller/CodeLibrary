/* Copyright (C) 1991, 92, 94, 95, 96, 97, 2002 Free Software Foundation, Inc.
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

#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <sys/time.h>
#include <windows.h>

/* Set the current time of day and timezone information.
   This call is restricted to the super-user.  */
int
__setntptimeofday (const struct timespec *tp, const struct timezone *z)
{
	SYSTEMTIME st;
	ULARGE_INTEGER fti;

	if (tp != NULL) {
		fti.QuadPart = UInt32x32To64 (tp->tv_sec, HECTONANOSEC_PER_SEC) + tp->tv_nsec % 100 + FILETIME_1970;
		FileTimeToSystemTime ((LPFILETIME) &fti, &st);
		if (!SetSystemTime (&st)) {
			set_werrno;
			return -1;
		}
	}
	return 0;
}

weak_alias (__setntptimeofday, setntptimeofday)
