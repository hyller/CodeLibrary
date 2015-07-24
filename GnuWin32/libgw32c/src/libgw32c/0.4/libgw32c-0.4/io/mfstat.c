/* Copyright (C) 1996, 1997, 1998, 2001 Free Software Foundation, Inc.
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

# include <stdio.h>
# include <time.h>
# include <fcntl.h>

int main (int argc, char **argv)
{
	struct _stat buf;
	int fd;

	fd = open (argv[1], O_RDONLY);
	if (_fstat (fd, &buf) == -1) {
	  	perror ("_fstat: ");
		return -1;
	}
	close (fd);
	fprintf(stderr, "File: %s\n", argv[1]);
	fprintf(stderr, "ino:  %ld\n", (long) buf.st_ino);
	fprintf(stderr, "mode: %#o\n", (unsigned int) buf.st_mode);
	fprintf(stderr, "uid:  %ld\n", (long) buf.st_uid);
	fprintf(stderr, "gid:  %ld\n", (long) buf.st_gid);
	fprintf(stderr, "dev:  %ld\n", (long) buf.st_dev);
	fprintf(stderr, "nlink:%ld\n", (long) buf.st_nlink);
	fprintf(stderr, "size: %ld\n", (long) buf.st_size);
	fprintf(stderr, "atime:%ld: %s", buf.st_atime, ctime(&buf.st_atime));
	fprintf(stderr, "mtime:%ld: %s", buf.st_mtime, ctime(&buf.st_mtime));
	fprintf(stderr, "ctime:%ld: %s", buf.st_ctime, ctime(&buf.st_ctime));
	return 0;
}
