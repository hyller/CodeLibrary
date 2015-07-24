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
#include <windows.h>
#include <unistd.h>
#include <gw32.h>
#ifdef gethostbyname
# undef gethostbyname
#endif
#ifdef gethostname
# undef gethostname
#endif

/* Return the current machine's Internet number.  */
long int
gethostid ()
{
	char name [MAX_PATH];
	struct hostent *hostinfo;
	char *ip;
	long int id;
		
	if (ws_init() == -1)
		return -1;
	if (gethostname(name, MAX_PATH) == 0) 
		if ((hostinfo = gethostbyname(name)) != NULL) {
			ip = inet_ntoa(*(struct in_addr *)hostinfo->h_addr_list[0]);
			id = inet_addr(ip);
			return id;
		}
	return 0L;
}
