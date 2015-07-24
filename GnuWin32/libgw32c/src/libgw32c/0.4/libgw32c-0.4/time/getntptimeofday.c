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

/* Get the current time of day and timezone information,
   putting it into *TV and *TZ.  If TZ is NULL, *TZ is not filled.
   Returns 0 on success, -1 on errors.  */
int
__getntptimeofday (struct timespec *tp, struct timezone *z)
{
	int res = 0;
//	struct _timeb timebuffer;
    ULARGE_INTEGER fti;
	TIME_ZONE_INFORMATION  TimeZoneInformation;
	DWORD tzi;

	if (z != NULL) {
		if ((tzi = GetTimeZoneInformation(&TimeZoneInformation)) != TIME_ZONE_ID_INVALID) {
			z->tz_minuteswest = TimeZoneInformation.Bias;
			if (tzi == TIME_ZONE_ID_DAYLIGHT)
				z->tz_dsttime = 1;
			else
				z->tz_dsttime = 0;
		}
		else {
			z->tz_minuteswest = 0;
			z->tz_dsttime = 0;
			set_werrno;
		}
    }

	 if (tp != NULL) {
          GetSystemTimeAsFileTime ((LPFILETIME) &fti);	 /* 100-nanoseconds since 1-1-1601 */
		  /* The actual accuracy on XP seems to be 125,000 nanoseconds = 125 microseconds = 0.125 milliseconds */
		  fti.QuadPart -= FILETIME_1970;	/* 100 nano-seconds since 1-1-1970 */
          tp->tv_sec = fti.QuadPart / HECTONANOSEC_PER_SEC ;	/* seconds since 1-1-1970 */
          tp->tv_nsec = (long) (fti.QuadPart % HECTONANOSEC_PER_SEC) * 100 ; /* nanoseconds */
     }
	return res;
}

INTDEF(__getntptimeofday)
weak_alias (__getntptimeofday, getntptimeofday)

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
