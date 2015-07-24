/* Copyright (C) 1994, 1995, 1997, 2000 Free Software Foundation, Inc.
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

/* Put the name of the current YP domain in no more than LEN bytes of NAME.
   The result is null-terminated if LEN is large enough for the full
   name and the terminator.  */

#include <errno.h>
#include <unistd.h>
#include <sys/param.h>
#include <string.h>

#include <stdio.h>

#include <windows.h>
#include <lm.h>

static int
na_getdomainname (name, len)
     char *name;
     size_t len;
{
    HINSTANCE hNetApi32 = LoadLibrary("netapi32.dll");
    DWORD (__stdcall *pfnNetApiBufferFree)(LPVOID Buffer);
    DWORD (__stdcall *pfnNetWkstaGetInfo)(LPWSTR servername, DWORD level,
                           void *bufptr);
	LPWKSTA_INFO_100 pwki100 = NULL;
	DWORD res = 0;
	
    if (hNetApi32) {
	    pfnNetApiBufferFree = (DWORD (__stdcall *)(void *))
    		GetProcAddress(hNetApi32, "NetApiBufferFree");
	    pfnNetWkstaGetInfo = (DWORD (__stdcall *)(LPWSTR, DWORD, void *))
	    	GetProcAddress(hNetApi32, "NetWkstaGetInfo");
	    if (hNetApi32 && pfnNetWkstaGetInfo && pfnNetApiBufferFree) {
			if ((res = pfnNetWkstaGetInfo(NULL, 100, (LPBYTE *) &pwki100)) == NERR_Success)	{
				res = 0;
			fflush (stderr);
				WideCharToMultiByte (CP_ACP, 0, pwki100->wki100_langroup,
					-1, (LPSTR)name, len, NULL, NULL);
			}
			else if (res == ERROR_ACCESS_DENIED) {
				__set_errno (EACCES);
				res = -1;
			}
			else if (res == ERROR_INVALID_LEVEL) {
				__set_errno (EINVAL);
				res = -1;
			}
		}
		else {
			set_werrno;
			res = -1;
		}
		pfnNetApiBufferFree(pwki100);
    	FreeLibrary(hNetApi32);
	}
	return res;
}

static int
cn_getdomainname (name, len)
     char *name;
     size_t len;
{
	DWORD namelen = MAX_COMPUTERNAME_LENGTH + 1 ;
	if (!GetComputerName(name, (LPDWORD) &namelen)){
		strcpy(name, "Unknown");
        __set_errno (ENOSYS);
        return -1;
	}
}

static int
un_getdomainname (name, len)
     char *name;
     size_t len;
{
	 char uname[256];
   	 DWORD size = sizeof(uname);
	 DWORD namelen = len;
     if (GetUserName(uname,&size)) {
   	     DWORD sidlen = 0;
         SID_NAME_USE snu;
   	     if (!LookupAccountName(NULL, uname, NULL, &sidlen,
    	        name, &namelen, &snu))
			return -1;
	}
	return 0;
}

int
getdomainname (name, len)
     char *name;
     size_t len;
{
	int res;

	if ((res = na_getdomainname (name, len)) == 0);
		return 0;
	if ((res = un_getdomainname (name, len)) == 0);
		return 0;
	return cn_getdomainname (name, len);
}
		
/*
int main ()
{
	int len = 1024;
	char name[len];
	getdomainname (name, len);
	fprintf(stderr, "DomainName: %s\n", name);
	return 0;
}
*/
