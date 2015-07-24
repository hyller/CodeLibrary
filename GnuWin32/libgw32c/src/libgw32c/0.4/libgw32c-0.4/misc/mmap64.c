/* Copyright (C) 1997 Free Software Foundation, Inc.
	 This file is part of the GNU C Library.

	 The GNU C Library is free software; you can redistribute it and/or
	 modify it under the terms of the GNU Lesser General Public
	 License as published by the Free Software Foundation; either
	 version 2.1 of the License, or (at your option) any later version.

	 The GNU C Library is distributed in the hope that it will be useful,
	 but WITHOUT ANY WARRANTY; without even the implied warranty of
	 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the GNU
	 Lesser General Public License for more details.

	 You should have received a copy of the GNU Lesser General Public
	 License along with the GNU C Library; if not, write to the Free
	 Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
	 02111-1307 USA.	*/

#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <io.h>
#include <stdio.h>
#include <windows.h>
#include <gw32.h>

/* Map addresses starting near ADDR and extending for LEN bytes.	From
	 OFFSET into the file FD describes according to PROT and FLAGS.	If ADDR
	 is nonzero, it is the desired mapping address.	If the MAP_FIXED bit is
	 set in FLAGS, the mapping will be at ADDR exactly (which must be
	 page-aligned); otherwise the system chooses a convenient nearby address.
	 The return value is the actual mapping address chosen or MAP_FAILED
	 for errors (in which case `errno' is set).	A successful `mmap' call
	 deallocates any previous mapping for the affected region.	*/

static DWORD granularity = 0;

DWORD
getgranularity (void)
{
	if (!granularity) {
		SYSTEM_INFO si;
		GetSystemInfo (&si);
		granularity = si.dwAllocationGranularity;
		}
	return granularity;
}

__ptr_t
__mmap64 (__ptr_t addr, size_t len, int prot, int flags, int fd,
		__off64_t offset)
{
	__ptr_t map = (__ptr_t) NULL;
	caddr_t gran_addr = (caddr_t) addr;
	HANDLE handle = INVALID_HANDLE_VALUE;
	DWORD cfm_flags = 0, mvf_flags = 0, sysgran = getgranularity ();
	__off64_t gran_offset = offset, filelen = _filelengthi64(fd);
	int mmlen = len;
	
	switch (prot) {
		case PROT_READ | PROT_WRITE | PROT_EXEC:
		case PROT_WRITE | PROT_EXEC:
			cfm_flags = PAGE_EXECUTE_READWRITE;
			mvf_flags = FILE_MAP_ALL_ACCESS;
			break;
		case PROT_READ | PROT_WRITE:
			cfm_flags = PAGE_READWRITE;
			mvf_flags = FILE_MAP_ALL_ACCESS;
			break;
		case PROT_WRITE:
			cfm_flags = PAGE_READWRITE;
			mvf_flags = FILE_MAP_WRITE;
			break;
		case PROT_READ:
			cfm_flags = PAGE_READONLY;
			mvf_flags = FILE_MAP_READ;
			break;
		case PROT_NONE:
			cfm_flags = PAGE_NOACCESS;
			mvf_flags = FILE_MAP_READ;
			break;
		case PROT_EXEC:
			cfm_flags = PAGE_EXECUTE;
			mvf_flags = FILE_MAP_READ;
			break;
	}
	if (flags & MAP_PRIVATE) {
		if (IsWin9x ())
			cfm_flags = PAGE_WRITECOPY;
		mvf_flags = FILE_MAP_COPY;
	}
	fprintf (stderr, "Addr before:   %p\n", gran_addr);
	fprintf (stderr, "Offset before: %#I64X\n", gran_offset);
	if (flags & MAP_FIXED) {
		gran_offset = offset;
		gran_addr = addr;
	}
	else {
		gran_offset = offset & ~(sysgran - 1);
		gran_addr = (caddr_t) (((DWORD) gran_addr / sysgran) * sysgran);
	}
	fprintf (stderr, "Addr after:    %p\n", gran_addr);
	fprintf (stderr, "Offset after:  %#I64X\n", gran_offset);
	mmlen = (filelen < gran_offset + len ? filelen - gran_offset : len);

	handle = CreateFileMapping ((HANDLE) _get_osfhandle(fd), NULL, cfm_flags,
		0, mmlen, NULL);
	if (!handle) {
		set_werrno;
		WinErr ("CreateFileMapping");
		return MAP_FAILED;
	}
	map = (__ptr_t) MapViewOfFileEx (handle, mvf_flags, HIDWORD(gran_offset),
		LODWORD(gran_offset), (SIZE_T) mmlen, (LPVOID) gran_addr);
	if (map == NULL && (flags & MAP_FIXED) ) {
		fprintf (stderr, "Starting address: %p\n", (LPVOID) gran_addr);
		WinErr ("First try of MapViewOfFileEx failed");
		map = (__ptr_t) MapViewOfFileEx (handle, mvf_flags, HIDWORD(gran_offset),
			LODWORD(gran_offset), (SIZE_T) mmlen, (LPVOID) NULL);
	}
	CloseHandle(handle);
	if (map == NULL) {
		set_werrno;
		WinErr ("MapViewOfFileEx");
		return MAP_FAILED;
	}
	return map;
}

weak_alias (__mmap64, mmap64)
