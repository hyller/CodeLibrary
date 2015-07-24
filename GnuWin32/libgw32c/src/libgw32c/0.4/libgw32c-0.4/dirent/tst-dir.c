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

int
printdir (const char *srcdir)
{
	DIR *dir;
	struct dirent64 *d;
	int result = 0;

	printf("srcdir: %s\n", srcdir);
	dir = opendir (srcdir);
	if (dir == NULL) {
		printf ("cannot open directory: %s\n", srcdir);
		return -1;
    }
//	printf("dir_pathname: %s\n", dir_pathname);
	while ((d = readdir64 (dir)) != NULL)	{
		printf("%d %u %s %#I64X %u %u %u\n",
			dir->fd, dir->offset, d->d_name, d->d_ino, d->d_reclen, d->d_type, d->d_namlen);
	}

	if (closedir (dir) < 0) {
    	printf ("closing dir failed: %m\n");
    	result = 1;
    }
	return result;
}

int
test2dir (const char *name1, const char *name2)
{
	DIR *dir1, *dir2;
	DIRdata *ddp;
	struct dirent *d1, *d2;
	int result = 0;

	dir1 = opendir (name1);
	if (dir1 == NULL) {
		perror (name1);
		return -1;
    }
	ddp = (DIRdata *) dir1->data;
	printf("name1: %s; fd: %d\n", ddp->dirname, dir1->fd);

	dir2 = opendir (name2);
	if (dir2 == NULL) {
		perror (name2);
		return -1;
    }
	ddp = (DIRdata *) dir2->data;
	printf("name2: %s; fd: %d\n", ddp->dirname, dir2->fd);

	while ((d1 = readdir64 (dir1)) && (d2 = readdir64 (dir2))) {
		printf("%d %u %s %u %u %u %u\n",
			dir1->fd, dir1->filepos, d1->d_name, (unsigned int) d1->d_ino, d1->d_reclen, d1->d_type,
			d1->d_namlen);
		printf("%d %u %s %u %u %u %u\n",
			dir2->fd, dir2->filepos, d2->d_name, (unsigned int) d2->d_ino, d2->d_reclen, d2->d_type,
			d2->d_namlen);
	}

	if (closedir (dir1) < 0) {
    	printf ("closing dir failed: %s\n", name1);
    	result = 1;
    }
	if (closedir (dir2) < 0) {
    	printf ("closing dir failed: %s\n", name2);
    	result = 1;
    }
	return result;
}

int
main (int argc, char ** argv)
{
	char * srcdir = ".";
	int result = 0;

	if (argc > 1)
		srcdir = argv[1];
	result = printdir(srcdir);
	if (argc > 2) {
		srcdir = argv[2];
		result = printdir(srcdir);
		test2dir (argv[1], argv[2]);
	}
	return result;
}
