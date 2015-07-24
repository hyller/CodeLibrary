/* Copyright (C) 1996, 1997, 2001 Free Software Foundation, Inc.
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

#include <sys/stat.h>

/* This definition is only used if inlining fails for this function; see
   the last page of <sys/stat.h>.  The real work is done by the `x'
   function which is passed a version number argument.  We arrange in the
   makefile that when not inlined this function is always statically
   linked; that way a dynamically-linked executable always encodes the
   version number corresponding to the data structures it uses, so the `x'
   functions in the shared library can adapt without needing to recompile
   all callers.  */

#undef fstat64
int
fstat64 (int fd, struct stat64 *buf)
{
  return __fxstat64 (_STAT_VER, fd, buf);
}

/* Hide the symbol so that no definition but the one locally in the
   executable or DSO is used.  */
#ifdef HAVE_DOT_HIDDEN
asm (".hidden\tfstat64");
#endif

#ifdef TEST
# include <stdio.h>
# include <time.h>
# include <fcntl.h>
# include <windows.h>

int main (int argc, char **argv)
{
	struct stat64 buf;
	int fd;

	SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX);
	if (argc == 1)
		fd = 0;
	else
		fd = open (argv[1], O_RDONLY);
	printf ("File: %s\n", argv[1]);
	printf ("Filedescriptor: %d\n", fd);
	if (fstat64(fd, &buf) == -1) {
	  	perror("fstat64: ");
		return -1;
	}
	close (fd);
	printf("File:  %s\n", argv[1]);
	printf("Filedescriptor: %d\n", fd);
	printf("ino:   %#I64X\n", (__int64) buf.st_ino);
	printf("mode:  %#o\n", (unsigned int) buf.st_mode);
	printf("uid:   %ld\n", (long) buf.st_uid);
	printf("gid:   %ld\n", (long) buf.st_gid);
	printf("dev:   %lu\n", (dev_t) buf.st_dev);
	printf("nlink: %ld\n", (long) buf.st_nlink);
	printf("size:  %I64d\n", (__int64) buf.st_size);
	printf("atime: %ld: %s", buf.st_atime, ctime(&buf.st_atime));
	printf("mtime: %ld: %s", buf.st_mtime, ctime(&buf.st_mtime));
	printf("ctime: %ld: %s\n", buf.st_ctime, ctime(&buf.st_ctime));
	SetErrorMode(0);
	return 0;
}
#endif /* TEST */
