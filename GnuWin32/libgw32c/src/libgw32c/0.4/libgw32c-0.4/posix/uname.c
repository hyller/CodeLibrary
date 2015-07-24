/* Copyright (C) 1991, 1992, 1996, 1997, 2000 Free Software Foundation, Inc.
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
#include <string.h>
#ifndef _UTSNAME_DOMAIN_LENGTH 
# define _UTSNAME_DOMAIN_LENGTH  _UTSNAME_LENGTH
#endif
#include <sys/utsname.h>
#include <unistd.h>
#include <winsock.h>
#include <gw32.h>


/* This file is created by the configuration process, and defines UNAME_*.  */
#include <config-name.h>

/* Put information about the system in NAME.  */
int
__uname (name)
     struct utsname *name;
{
  char processor[1024];
  int save;
  if (name == NULL)
    {
      __set_errno (EINVAL);
      return -1;
    }

  save = errno;
  if (w32_gethostname (name->nodename, sizeof (name->nodename)) < 0)
    {
	  if (errno == ENOSYS)
	{
	  /* Hostname is meaningless for this machine.  */
	  name->nodename[0] = '\0';
	  __set_errno (save);
	}
#ifdef	ENAMETOOLONG
      else if (errno == ENAMETOOLONG)
	/* The name was truncated.  */
	__set_errno (save);
#endif
      else
	return -1;
    }
  if (!GetOsInfo(name->sysname, name->release, name->version)) {
	  strncpy (name->sysname, UNAME_SYSNAME, sizeof (name->sysname));
	  strncpy (name->release, UNAME_RELEASE, sizeof (name->release));
	  strncpy (name->version, UNAME_VERSION, sizeof (name->version));
  }
  /* "windows32" is as yet the only universal windows description allowed
     by config.guess and config.sub */
  strncpy (name->sysname, "windows32", sizeof (name->sysname));
  if (!GetMachInfo(name->machine, processor))
	  strncpy (name->machine, UNAME_MACHINE, sizeof (name->machine));
  if (getdomainname(name->domainname, sizeof(name->domainname)) < 0)
	  strncpy (name->domainname, UNAME_DOMAINNAME, sizeof (name->domainname));
 
  return 0;
}
weak_alias (__uname, uname)
