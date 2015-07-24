/*
 * Copyright 2000 Martin Fuchs
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>
#include "winefile.h"

#ifdef UNICODE

void _wsplitpath(const WCHAR* path, WCHAR* drv, WCHAR* dir, WCHAR* name, WCHAR* ext)
{
        const WCHAR* end; /* end of processed string */
	const WCHAR* p;	  /* search pointer */
	const WCHAR* s;	  /* copy pointer */

	/* extract drive name */
	if (path[0] && path[1]==':') {
		if (drv) {
			*drv++ = *path++;
			*drv++ = *path++;
			*drv = L'\0';
		}
	} else if (drv)
		*drv = L'\0';

	/* search for end of string or stream separator */
	for(end=path; *end && *end!=L':'; )
		end++;

	/* search for begin of file extension */
	for(p=end; p>path && *--p!=L'\\' && *p!=L'/'; )
		if (*p == L'.') {
			end = p;
			break;
		}

	if (ext)
		for(s=end; *ext=*s++; )
			ext++;

	/* search for end of directory name */
	for(p=end; p>path; )
		if (*--p=='\\' || *p=='/') {
			p++;
			break;
		}

	if (name) {
		for(s=p; s<end; )
			*name++ = *s++;

		*name = L'\0';
	}

	if (dir) {
		for(s=path; s<p; )
			*dir++ = *s++;

		*dir = L'\0';
	}
}

#else

void _splitpath(const CHAR* path, CHAR* drv, CHAR* dir, CHAR* name, CHAR* ext)
{
        const CHAR* end; /* end of processed string */
	const CHAR* p;	 /* search pointer */
	const CHAR* s;	 /* copy pointer */

	/* extract drive name */
	if (path[0] && path[1]==':') {
		if (drv) {
			*drv++ = *path++;
			*drv++ = *path++;
			*drv = '\0';
		}
	} else if (drv)
		*drv = '\0';

	/* search for end of string or stream separator */
	for(end=path; *end && *end!=':'; )
		end++;

	/* search for begin of file extension */
	for(p=end; p>path && *--p!='\\' && *p!='/'; )
		if (*p == '.') {
			end = p;
			break;
		}

	if (ext)
		for(s=end; (*ext=*s++); )
			ext++;

	/* search for end of directory name */
	for(p=end; p>path; )
		if (*--p=='\\' || *p=='/') {
			p++;
			break;
		}

	if (name) {
		for(s=p; s<end; )
			*name++ = *s++;

		*name = '\0';
	}

	if (dir) {
		for(s=path; s<p; )
			*dir++ = *s++;

		*dir = '\0';
	}

}
#endif

#ifdef TEST

void split_print_path (const CHAR* path)
{
	TCHAR drv[_MAX_DRIVE+1], dir[_MAX_DIR], name[_MAX_FNAME], ext[_MAX_EXT];
	_tsplitpath (path, drv, dir, name, ext);
	printf("Path: %s", path);
	printf(" Drv: %s", drv);
	printf(" Dir: %s", dir);
	printf(" Name: %s", name);
	printf(" Ext: %s\n", ext);
}

void main()	// test splipath()
{

	split_print_path("x\\y");
	split_print_path("x\\");
	split_print_path("\\x");
	split_print_path("x");
	split_print_path("");
	split_print_path(".x");
	split_print_path(":x");
	split_print_path("a:x");
	split_print_path("a.b:x");
	split_print_path("W:\\/\\abc/Z:~");
	split_print_path("abc.EFGH:12345");
	split_print_path("C:/dos/command.com");
}

#endif
