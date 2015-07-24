/* Copyright (C) 1993, 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
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
   02111-1307 USA.

   As a special exception, if you link the code in this file with
   files compiled with a GNU compiler to produce an executable,
   that does not cause the resulting executable to be covered by
   the GNU Lesser General Public License.  This exception does not
   however invalidate any other reasons why the executable file
   might be covered by the GNU Lesser General Public License.
   This exception applies to code released by its copyright holders
   in files containing the exception.  */

#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <io.h>

int
fseeko64 (fp, offset, whence)
     FILE* fp;
     __off64_t offset;
     int whence;
{
#ifdef _G_LSEEK64
  fpos_t pos;
  if (whence == SEEK_CUR) {
	fgetpos(fp, &pos);
	pos += (fpos_t) offset;
  }
  else if (whence == SEEK_END) 
  	pos = (fpos_t) (_filelengthi64(fileno(fp)) + offset);
  else if (whence == SEEK_SET)
    pos = (fpos_t) offset;
  return fsetpos(fp, &pos);
#else /* _G_LSEEK64 */
  __set_errno (ENOSYS);
  return -1;
#endif  /* _G_LSEEK64 */
}
