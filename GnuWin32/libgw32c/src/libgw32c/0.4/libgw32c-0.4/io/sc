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

//#define _NO_OLDNAMES
//#define _STAT_DEFINED
#include <sys/stat.h>

/* This definition is only used if inlining fails for this function; see
   the last page of <sys/stat.h>.  The real work is done by the `x'
   function which is passed a version number argument.  We arrange in the
   makefile that when not inlined this function is always statically
   linked; that way a dynamically-linked executable always encodes the
   version number corresponding to the data structures it uses, so the `x'
   functions in the shared library can adapt without needing to recompile
   all callers.  */

#undef stat
int
__stat (const char *file, struct stat *buf)
{
  return __xstat (_STAT_VER, file, buf);
}

weak_alias (__stat, stat)

/* Hide the symbol so that no definition but the one locally in the
   executable or DSO is used.  */
#ifdef HAVE_DOT_HIDDEN
asm (".hidden\tstat");
asm (".hidden\t__stat");
#endif

#ifdef TEST
# include <stdio.h>
# include <time.h>

int main (int argc, char **argv)
{
	struct stat buf;

	if (__stat(argv[1], &buf) == -1) {
	  	perror("__xstat: ");
		return -1;
	}
	fprintf(stderr, "File: %s\n", argv[1]);
	fprintf(stderr, "ino:  %ld\n", (long) buf.st_ino);
	fprintf(stderr, "mode: %#o\n", (unsigned int) buf.st_mode);
	fprintf(stderr, "uid:  %ld\n", (long) buf.st_uid);
	fprintf(stderr, "gid:  %ld\n", (long) buf.st_gid);
	fprintf(stderr, "dev:  %lu\n", (_dev_t) buf.st_dev);
	fprintf(stderr, "rdev:  %lu\n", (_dev_t) buf.st_rdev);
	fprintf(stderr, "nlink:%ld\n", (long) buf.st_nlink);
	fprintf(stderr, "size: %ld\n", (long) buf.st_size);
	fprintf(stderr, "atime:%ld: %s", buf.st_atime, ctime(&buf.st_atime));
	fprintf(stderr, "mtime:%ld: %s", buf.st_mtime, ctime(&buf.st_mtime));
	fprintf(stderr, "ctime:%ld: %s", buf.st_ctime, ctime(&buf.st_ctime));
	return 0;
}
#endif /* TEST */

