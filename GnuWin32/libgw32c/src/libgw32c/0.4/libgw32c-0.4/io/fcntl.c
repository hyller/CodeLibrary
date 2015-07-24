/* Copyright (C) 1991, 1995, 1996, 1997, 2002 Free Software Foundation, Inc.
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
#include <fcntl.h>
#include <stdio.h>
#include <windows.h>
#include <winx/mslowiox.h>

int
lock64 (int fd, int cmd, struct flock64 *fl)
{
	LARGE_INTEGER fstart, fend;
	HANDLE hFile = (HANDLE) _get_osfhandle (fd);
	int res;

	fstart.QuadPart = lseek64 (fd, 0, fl->l_whence) + fl->l_start;
	fend.QuadPart = fstart.QuadPart + fl->l_len;
	switch (cmd) {
		case F_GETLK: 		/* Get record locking information */
			__set_errno (ENOSYS);
			return -1;
		case F_SETLK: 		/* Set record locking information */
		case F_SETLKW: 		/* Set record locking information; wait if blocked */
			switch (fl->l_type) {
				case F_RDLCK: 		/* Shared or read lock */
				case F_WRLCK: 		/* Exclusive or write lock */
					res = LockFile (hFile, fstart.LowPart, fstart.HighPart, fend.LowPart, fend.HighPart);
					break;
				case F_UNLCK: 		/* Unlock */
					res = UnlockFile (hFile, fstart.LowPart, fstart.HighPart, fend.LowPart, fend.HighPart);
					break;
				default:
					__set_errno (EINVAL);
					return -1;
			}
			if (!res) {
				set_werrno;
				return -1;
			}
			else
				return 0;
			break;
		default:
			__set_errno (EINVAL);
			return -1;
	}
	return 0;
}

int
lock (int fd, int cmd, struct flock *fl)
{
	struct flock64 fl64;
	fl64.l_type = fl->l_type;
	fl64.l_whence = fl->l_whence;
	fl64.l_start = fl->l_start;
	fl64.l_len = fl->l_len;
//	fl64.l_pid = fl->l_pid;
	return lock64 (fd, cmd, &fl64);
}

int
osflags2mode (int osflags)
{
	int fmode = 0;
	if (osflags & FOPEN)
		fmode |= O_RDWR;
	else if (osflags & FAPPEND)
		fmode |= O_APPEND;
	else if (osflags & FNOINHERIT)
		fmode |= O_NOINHERIT;
	else if (osflags & FTEXT)
		fmode |= O_TEXT;		 
	return fmode;
}

int
mode2osflags (int fmode)
{
	int osflags = 0;
	if (fmode & O_APPEND)
		osflags |= FAPPEND;
	else if (fmode & O_TEXT)
		osflags |= FTEXT;
	return osflags;
}

static int
do_fcntl (int fd, int cmd, void *arg)
{
  switch (cmd) {
	case F_DUPFD:		/* Duplicate file descriptor */
		return dup (fd);
	case F_GETFD: 		/* Get file descriptor flags */
		if (_osfile (fd) & FNOINHERIT)
			return FD_CLOEXEC;
		else
			return 0;
	case F_SETFD: {		/* Set file descriptor flags */
		int newflags = (int) arg;
		if (newflags & FD_CLOEXEC) {
			newflags &= ~FD_CLOEXEC;
			newflags |= FNOINHERIT;
		}
		_osfile (fd) = newflags;
		return 0;
	}
	case F_GETFL: 		/* Get file status flags and file access modes */
		return osflags2mode (_osfile (fd));
	case F_SETFL: 		/* Set file status flags */
		_osfile (fd) = mode2osflags ( (int) arg);
		return 0;
	case F_GETLK: 		/* Get record locking information */
		break;
	case F_SETLK: 		/* Set record locking information */
	case F_SETLKW: {		/* Set record locking information; wait if blocked */
		 if (sizeof (*arg) == sizeof (struct flock64)) {
			 struct flock64 *fl = arg;
			 return lock64 (fd, cmd, fl);
		}
		else if (sizeof (*arg) == sizeof (struct flock)) {
			 struct flock *fl = arg;
			 return lock (fd, cmd, fl);
		}			 
		else {
		    __set_errno (EINVAL);
			return -1;
		}
	  }
	case F_GETOWN: 		/* Get process or process group ID to receive SIGURG signals */
		break;
	case F_SETOWN: 		/* Set process or process group ID to receive SIGURG signals */
		break;
	default:
      __set_errno (EINVAL);
      return -1;
	}
  __set_errno (ENOSYS);
  return -1;
}

/* Perform file control operations on FD.  */
int
__fcntl (int fd, int cmd, ...)
{
  va_list ap;
  void *arg;

  va_start (ap, cmd);
  arg = va_arg (ap, void *);
  va_end (ap);

  if (fd < 0) {
      __set_errno (EBADF);
      return -1;
  }
  return do_fcntl (fd, cmd, arg);
}

libc_hidden_def (__fcntl)

weak_alias (__fcntl, fcntl)
