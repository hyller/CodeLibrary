/* Copyright (C) 1991-2002, 2003 Free Software Foundation, Inc.
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
#include <windows.h>



/* Maximum length of a timezone name.  tzset_internal keeps this up to date
   (never decreasing it) when ! __use_tzfile.
   tzfile.c keeps it up to date when __use_tzfile.  */
size_t __tzname_cur_max;

long int
__tzname_max ()
{
  TIME_ZONE_INFORMATION *ptz;
  __tzname_cur_max = sizeof (ptz->StandardName);
  return __tzname_cur_max;
}
