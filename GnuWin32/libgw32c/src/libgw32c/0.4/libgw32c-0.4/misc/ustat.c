/* Return info on filesystem.
   Copyright (C) 1995, 1996, 1997 Free Software Foundation, Inc.
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

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/ustat.h>
#include <sys/statfsx.h>
#include <gw32.h>

int
ustat (dev, ust)
     __dev_t dev;
     struct ustat * ust;
{
  char *rootdir = devrootdir (dev);
  struct statfsx64 sb;

  if (!statfsx64 (rootdir, &sb)) {
    free (rootdir);
  	return -1;
  }
  ust->f_tfree = sb.f_bfree;
  ust->f_tinode	= sb.f_ffree;
  strncpy (ust->f_fname, sb.f_mntonname, 6);
  strncpy (ust->f_fpack, sb.f_mntonname, 6);
  free (rootdir);
  return 0;
};
