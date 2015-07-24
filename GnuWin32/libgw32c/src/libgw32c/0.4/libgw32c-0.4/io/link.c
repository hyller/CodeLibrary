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
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#include <gw32.h>
#include <stdio.h>

void
debugprint(const char *mess)
{
#ifdef TEST
	fprintf(stderr, "%s\n", mess);
#endif
}

int BackupLink(from, to)
     const char *from;
     const char *to;
{
     void *ctx = NULL;
     WIN32_STREAM_ID wsi;
	 char *path;
	 DWORD numwritten;
	HANDLE fh;
	int wpathlen;
	WCHAR wpath[MAX_PATH];

     fh = CreateFile (from, GENERIC_WRITE, 0, NULL, OPEN_EXISTING,
		FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_POSIX_SEMANTICS, NULL);
     if (fh == INVALID_HANDLE_VALUE) {
          CloseHandle (fh);
		  set_werrno;
		  return -1;
     }
	path = unix2winpath (canonicalize_file_name (to));
    wpathlen = mbstowcs (wpath, path, MAX_PATH) * sizeof (WCHAR);

     wsi.dwStreamId = BACKUP_LINK;
     wsi.dwStreamAttributes = 0;
     wsi.dwStreamNameSize = 0;
     wsi.Size.QuadPart = wpathlen;
     if ( ! BackupWrite (fh, (LPBYTE) &wsi,
	 		offsetof (WIN32_STREAM_ID, cStreamName),
			&numwritten, FALSE, FALSE, &ctx ) ) {
          CloseHandle (fh);
		  set_werrno;
		  return -1;
     }
     if (numwritten != offsetof (WIN32_STREAM_ID, cStreamName) ) {
          CloseHandle (fh);
		  set_werrno;
		  return -1;
     }
     if ( ! BackupWrite (fh, (LPBYTE) wpath, wpathlen,
	 		&numwritten, FALSE, FALSE, &ctx) )  {
          CloseHandle (fh);
		  set_werrno;
		  return -1;
     }
     if ( numwritten != wpathlen ) {
          CloseHandle (fh);
		  set_werrno;
		  return -1;
     }
     // make NT release the context
     BackupWrite (fh, NULL, 0, &numwritten, TRUE, FALSE, &ctx);
     CloseHandle (fh);
	return 0;
}

/* Make a link to FROM called TO.  */
int
__link (from, to)
     const char *from;
     const char *to;
{
  HINSTANCE hinst;
  FARPROC chl; /* CreateHardLink */
  int res = -1;
  
  if (from == NULL || to == NULL)
    {
      __set_errno (EINVAL);
      return -1;
    }
    hinst = LoadLibrary ("KERNEL32");
    if (hinst)
#ifdef UNICODE
	    chl = GetProcAddress (hinst, "CreateHardLinkW");
#else
    	chl = GetProcAddress (hinst, "CreateHardLinkA");
#endif
    else {
		debugprint ("kernel32 not found");
        chl = NULL;
	}
	if (chl && chl (to, from, NULL)) {
		res = 0;
		debugprint ("CreateHardLink used");
	}
	else if (!chl)
			debugprint ("CreateHardLink not found");
		else
			debugprint ("CreateHardLink failed");
	if (res == -1) {
		debugprint("BackupLink used");
		res = BackupLink (from, to);
		if (res == -1)
			debugprint ("BackupLink failed");
	}
	if (res == -1) {
		debugprint("CopyFile used");
		if (CopyFile (from, to, TRUE))
			res = 0;
		else			
			debugprint ("CopyFile failed");
	}
	if (res == -1)
		set_werrno;		
	return res;
}

weak_alias (__link, link)

#ifdef TEST
int
main (int argc, char **argv)
{
	int res;
	
	fprintf(stderr, "link: src:  %s\n", argv[1]);
	fprintf(stderr, "      dest: %s\n", argv[2]);
	res = __link(argv[1], argv[2]);
	if (res == -1)
		perror("link");
	return res;
}	
#endif /* TEST */
