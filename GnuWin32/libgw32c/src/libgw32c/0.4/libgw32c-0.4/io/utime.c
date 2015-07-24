/* Copyright (C) 1991,95,96,97,2002 Free Software Foundation, Inc.
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
#include <utime.h>
#include <sys/time.h>

static struct timeval
TimeTToTimeVal (const time_t t)
{
	struct timeval tv;
	tv.tv_sec = t;
	tv.tv_usec = 0;
	return tv;
}

/* Set the access and modification times of FILE to those given in TIMES.
   If TIMES is NULL, set them to the current time.  */
int
utime (file, times)
     const char *file;
     struct utimbuf *times;
{
	struct timeval tv[2];
	
	if (file == NULL) {
		__set_errno (EINVAL);
		return -1;
    }
	if (times == NULL)
		return utimes (file, 0);
	tv[0] = TimeTToTimeVal (times->actime);
	tv[1] = TimeTToTimeVal (times->modtime);
	return utimes (file, tv);
}

//libc_hidden_def (utime)
