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
#include <sys/times.h>
#include <stddef.h>
#include <windows.h>
#include <stdio.h>

#define FILETIME2CLOCK(ft) ( (clock_t) ( ( ft.dwLowDateTime ) + \
	( ( ft.dwHighDateTime ) << 32) ) );
	
/* Store the CPU time used by this process and all its
   dead children (and their dead children) in BUFFER.
   Return the elapsed real time, or (clock_t) -1 for errors.
   All times are in CLK_TCKths of a second.  */
clock_t
__times (buffer)
     struct tms *buffer;
{
/* 1 sec = 1000 millisec = 1,000,000 microsec = 1,000,000,000 nanosec = 10,000,000 100-nanosec 
   1 microsec = 1000 nanosec = 10 100-nanosec
   100 nanosec = 0.1 microsec
*/
	FILETIME CreationTime;	/* 100-nanoseconds since 1-1-1601 */
	FILETIME ExitTime;		/* 100-nanoseconds since 1-1-1601 */
	FILETIME KernelTime;	/* 100-nanoseconds */
	FILETIME UserTime;		/* 100-nanoseconds */

	if (buffer == NULL) {
		__set_errno (EINVAL);
		return (clock_t) -1;
    }

    if (GetProcessTimes (GetCurrentProcess(), &CreationTime, &ExitTime,
			&KernelTime,&UserTime)) {
		buffer->tms_utime = FILETIME2CLOCK(UserTime);
		buffer->tms_stime = FILETIME2CLOCK(KernelTime);
		buffer->tms_cutime = 0;
		buffer->tms_cstime = 0;
		return (clock_t) (buffer->tms_utime + buffer->tms_stime);
    }
	else {
		buffer->tms_utime = 0;
		buffer->tms_stime = 0;
		buffer->tms_cutime = 0;
		buffer->tms_cstime = 0;
		set_werrno;
		return (clock_t) -1;
    }
}

weak_alias (__times, times)
