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
#include <dirent.h>
#include <dirent-internal.h>
#include <stdio.h>
#include <sys/stat.h>
#include <windows.h>

/* Read a directory entry from DIRP.  */
struct dirent64 *
__readdir64 (DIR *dirp)
{
  WIN32_FIND_DATA dir_find_data;
  DIRdata *ddp = (DIRdata *) dirp->data;
  struct stat64 sb;
  
  if (dirp == NULL) {
     __set_errno (EBADF);
     return NULL;
  }

  /* If we aren't dir_finding, do a find-first, otherwise do a find-next. */
  if (dirp->fd == INVALID_DIRFD) {
      char filename[MAX_PATH + 3];
      int len;
	  
	  strcpy (filename, ddp->dirname);
      len = strlen (filename) - 1;
      if (!ISDIRSEP (filename[len]))
	      strcat (filename, "\\");
      strcat (filename, "*");
      dirp->fd = (int) FindFirstFile (filename, &dir_find_data);
      if (dirp->fd == INVALID_HANDLE_VALUE) {
          dirp->fd = INVALID_DIRFD;
		  set_werrno;
          return NULL;
	  }
	}
  else {
      if (!FindNextFile ((HANDLE) dirp->fd, &dir_find_data)) {
	  	 if (!(GetLastError () == ERROR_NO_MORE_FILES))
		 	set_werrno;
	     return NULL;
	  }
	}
  __libc_lock_lock (dirp->lock);
  strncpy (ddp->DIRdir.d_name, ddp->dirname, MAX_PATH);
  strncat (ddp->DIRdir.d_name, "\\", MAX_PATH);
  strncat (ddp->DIRdir.d_name, dir_find_data.cFileName, MAX_PATH);
  if (lstat64 (ddp->DIRdir.d_name, &sb)) {
	set_werrno;
	return NULL;
  }
  ddp->DIRdir.d_type = IFTODT(sb.st_mode);
  ddp->DIRdir.d_namlen = strlen (dir_find_data.cFileName);
  ddp->DIRdir.d_reclen = sizeof (struct dirent64);
  ddp->DIRdir.d_ino = sb.st_ino;
  strncpy (ddp->DIRdir.d_name, dir_find_data.cFileName, MAX_PATH);
  __libc_lock_unlock (dirp->lock);  ++dirp->filepos;
  errno = 0;
  return &ddp->DIRdir;
}

weak_alias (__readdir64, readdir64)
