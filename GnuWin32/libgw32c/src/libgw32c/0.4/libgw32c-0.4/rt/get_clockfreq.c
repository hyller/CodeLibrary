/* Get frequency of the system processor.
   Copyright (C) 2000, 2001 Free Software Foundation, Inc.
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

#include <libc-internal.h>
#include <errno.h>
#include <windows.h>

hp_timing_t
__get_clockfreq (void)
{
	static LARGE_INTEGER Frequency;

	/* If this function was called before, we know the result.  */
	if (Frequency.QuadPart != 0)
	    return (hp_timing_t) Frequency.QuadPart;

	if (QueryPerformanceFrequency(&Frequency))
		return (hp_timing_t) Frequency.QuadPart;
	else {
		set_werrno;
		return 0;
	}
}
