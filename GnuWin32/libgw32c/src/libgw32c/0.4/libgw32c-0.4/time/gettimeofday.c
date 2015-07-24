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

#include <time.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <errno.h>
#include <windows.h>

#include <stdio.h>


/* Get the current time of day and timezone information,
   putting it into *TV and *TZ.  If TZ is NULL, *TZ is not filled.
   Returns 0 on success, -1 on errors.  */
int
__gettimeofday (struct timeval *p, struct timezone *z)
{
	struct timespec tp;

	if (getntptimeofday (&tp, z)) {
		return -1;
	}
	TIMESPEC_TO_TIMEVAL (p, &tp);
	return 0;
}

INTDEF(__gettimeofday)
weak_alias (__gettimeofday, gettimeofday)

#ifdef TEST
#include <stdio.h>

int main()
{
     struct timeval p;
     struct timezone z;

	gettimeofday(&p,&z);
	fprintf(stderr, "The time is     %lu sec %lu microsec\n", p.tv_sec, p.tv_usec);
	fprintf(stderr, "The timezone is %d min DST: %d\n", z.tz_minuteswest, z.tz_dsttime);
}
#endif /* TEST */
