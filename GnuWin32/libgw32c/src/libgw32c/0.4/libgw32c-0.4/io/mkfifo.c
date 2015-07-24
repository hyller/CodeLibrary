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

/* taken from Microsoft UNIX/ANSI C/C++/Fortran Code Migration Guide p. 420 */
#include <stddef.h>
//#define _NO_OLDNAMES
//#define _STAT_DEFINED
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>


/* Create a named pipe (FIFO) named PATH with protections MODE.  */
int
mkfifo (path, mode)
     const char *path;
     mode_t mode;
{
	#define BUFSIZE 1024
	#define PIPE_TIMEOUT 5000 // 5 Seconds

	HANDLE hPipe;
	TCHAR szPipeName[MAX_PATH];
	int fd;

	if (path == NULL) {
		__set_errno (EINVAL);
		return -1;
    }

// The following is an approximation of mode 0777
	strcpy(szPipeName, "\\\\.\\pipe\\");
	strcat(szPipeName, path);
//	fprintf(stderr, "szPipeName: %s\n", szPipeName);
	hPipe = CreateNamedPipe(
		(LPTSTR) szPipeName, // pipe name
		PIPE_ACCESS_DUPLEX, // read/write access
		PIPE_TYPE_MESSAGE | // message type pipe
		PIPE_READMODE_MESSAGE | // message-read mode
		PIPE_WAIT, // blocking mode
		PIPE_UNLIMITED_INSTANCES, // max. instances
		BUFSIZE, // output buffer size
		BUFSIZE, // input buffer size
		PIPE_TIMEOUT, // client time-out
		NULL); // no security attribute
//fprintf(stderr, "hPipe: %p\n", hPipe);
	if (hPipe == INVALID_HANDLE_VALUE) {
		__set_errno (EBADF);
		return -1;
	}
	fd = _open_osfhandle((intptr_t) hPipe, mode);
	return fd;
}
