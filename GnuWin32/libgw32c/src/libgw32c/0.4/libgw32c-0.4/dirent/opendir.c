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
#include <windows.h>


/* Open a directory stream on NAME.  */
DIR *
__opendir (const char *name)
{
  DIR *dirp;
  DIRdata *ddp;
  DWORD attr;

  if (name == NULL || name[0] == '\0') {
	__set_errno (ENOENT);
    return NULL;
  }

  if ((attr = GetFileAttributes (name)) == INVALID_FILE_ATTRIBUTES) {
  	set_werrno;
	return NULL;
  }
  if (!(attr & FILE_ATTRIBUTE_DIRECTORY)) {
  	__set_errno (ENOTDIR);
	return NULL;
  }
  
  if (!(dirp = (DIR *) malloc (sizeof (DIR))))
    return NULL;

  if (!(ddp = (DIRdata *) malloc (sizeof (DIRdata))))
    return NULL;

  __libc_lock_lock (dirp->lock);
  ddp->dirname = canonicalize_file_name (name);
  dirp->data = (char *) ddp;
  dirp->fd = INVALID_DIRFD;
  dirp->allocation = sizeof (DIRdata);
  dirp->size = dirp->allocation;
  dirp->offset = offsetof (DIRdata, DIRdir);
  dirp->filepos = 1;
  __libc_lock_unlock (dirp->lock);

//  strncpy (dir_pathname, name, nlen);
//  dir_pathname[nlen] = '\0';

  return dirp;
}

weak_alias (__opendir, opendir)
