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
#include <unistd.h>
#include <windows.h>
#include <tlhelp32.h>


/* Get the parent process ID of the calling process.  */
int
__getppid ()
{
    HANDLE hProcess, thProcess;
    PROCESSENTRY32 ProcessEntry;

    thProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (thProcess == INVALID_HANDLE_VALUE) {
		set_werrno;
		return -1;
	}
    ProcessEntry.dwSize = sizeof(PROCESSENTRY32);
    ProcessEntry.th32ParentProcessID = 0;
    if (!Process32First(thProcess, &ProcessEntry)) {
		set_werrno;
		return -1;
	}
	CloseHandle(thProcess);
    hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, ProcessEntry.th32ProcessID);
    if (hProcess == NULL) {
		set_werrno;
        return -1;
	}
	CloseHandle(hProcess);
	return ProcessEntry.th32ParentProcessID;
}

weak_alias (__getppid, getppid)
