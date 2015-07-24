/* Copyright (C) 1994, 1995, 1996, 1997 Free Software Foundation, Inc.
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

#include <sys/types.h>
#include <sys/mman.h>
#include <errno.h>
#include <windows.h>

/* Change the memory protection of the region starting at ADDR and
   extending LEN bytes to PROT.  Returns 0 if successful, -1 for errors
   (and sets errno).  */

int
__mprotect (__ptr_t addr, size_t len, int prot)
{
 
  DWORD old_prot;
  DWORD new_prot = 0;

  switch (prot) {
      case PROT_READ | PROT_WRITE | PROT_EXEC:
      case PROT_WRITE | PROT_EXEC:
  	      new_prot = PAGE_EXECUTE_READWRITE;
      	  break;
	  case PROT_READ | PROT_WRITE:
	  case PROT_WRITE:
    	  new_prot = PAGE_READWRITE;
		  break;
	  case PROT_READ:
    	  new_prot = PAGE_READONLY;
		  break;
	  case PROT_NONE:
    	  new_prot = PAGE_NOACCESS;
		  break;
	  case PROT_EXEC:
	      new_prot = PAGE_EXECUTE;
		  break;
  }

  if (!VirtualProtect (addr, len, new_prot, &old_prot)) {
  	set_werrno;
	return -1;
  }
  return 0;
}

weak_alias (__mprotect, mprotect)

