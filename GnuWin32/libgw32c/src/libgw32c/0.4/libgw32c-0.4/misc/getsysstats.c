/* getsysstats - Determine various system internal values, stub version.
   Copyright (C) 1996, 1997, 2001 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1996.

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
#include <sys/sysinfo.h>
#include <windows.h>

static SYSTEM_INFO sysinf;
static LPSYSTEM_INFO lpSysInfo = NULL;

#define init_sysinfo \
{\
	if (!lpSysInfo) {\
	   lpSysInfo = &sysinf; \
	   ZeroMemory(lpSysInfo, sizeof(SYSTEM_INFO));\
	   GetSystemInfo(lpSysInfo);\
	}\
}

int
__get_nprocs ()
{
   init_sysinfo;
   return lpSysInfo->dwNumberOfProcessors;
}
weak_alias (__get_nprocs, get_nprocs)

int
__get_nprocs_conf ()
{
  /* We don't know how to determine the number.  */
  return __get_nprocs ();
}
weak_alias (__get_nprocs_conf, get_nprocs_conf)

long int
__get_phys_pages ()
{
   init_sysinfo;
   return (lpSysInfo->lpMaximumApplicationAddress - lpSysInfo->lpMinimumApplicationAddress)
   	/ lpSysInfo->dwPageSize;
}
weak_alias (__get_phys_pages, get_phys_pages)

long int
__get_avphys_pages ()
{
  /* We have no general way to determine this value.  */
  return __get_phys_pages ();
}
weak_alias (__get_avphys_pages, get_avphys_pages)
