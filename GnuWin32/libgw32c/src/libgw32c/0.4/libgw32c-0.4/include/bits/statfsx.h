/* Definition of `struct statfsx', information about a filesystem.
   Copyright (C) 1996, 1997 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#ifndef _SYS_STATFSX_H
# error "Never include <bits/statfsx.h> directly; use <sys/statfsx.h> instead."
#endif

#include <bits/types.h>

#define MFSNAMELEN  16   /* length of fs type name, including null */
#define   MNAMELEN  90   /* length of buffer for returned name */

struct statfsx
  {
    unsigned int f_type;           /* type of filesystem (see fsinfo.h) */
    unsigned int f_bsize;               /* file system block size */    
    unsigned long int f_frsize;    /* fragment size: fundamental filesystem block */
    unsigned long int f_iosize;    /* optimal transfer block size */
#ifndef __USE_FILE_OFFSET64
    __fsblkcnt_t f_blocks;              /* total number of blocks on file system
in units of f_frsize */             
    __fsblkcnt_t f_bfree;               /* total number of free blocks */      
                                     
    __fsblkcnt_t f_bavail;              /* number of free blocks available to non-privileged
process */              
    __fsfilcnt_t f_files;          /* total number of file serial numbers */
    __fsfilcnt_t f_ffree;          /* total number of free file serial numbers
*/
    __fsfilcnt_t f_favail;         /* number of file serial numbers available
to non-privileged process */
#else                                        
    __fsblkcnt64_t f_blocks;       /* total number of blocks on file system
in units of f_frsize */
    __fsblkcnt64_t f_bfree;             /* total number of free blocks */    
                          
    __fsblkcnt64_t f_bavail;       /* number of free blocks available to non-privileged
process */ 
    __fsfilcnt64_t f_files;        /* total number of file serial numbers */
                             
    __fsfilcnt64_t f_ffree;        /* total number of free file serial numbers
*/                         
    __fsfilcnt64_t f_favail;  /* number of file serial numbers available to
non-privileged process */
#endif
    __fsid_t f_fsid;                    /* file system id */
    __uid_t     f_owner;       /* user that mounted the filesystem */
    unsigned long int f_flag; /* bit mask of f_flag values */
    char f_fstypename[MFSNAMELEN]; /* fs type name */
    char f_mntonname[MNAMELEN];   /* directory on which mounted */
    char f_mntfromname[MNAMELEN];/* mounted filesystem */
    unsigned int f_namelen;             /* maximum filename length */
  };

#ifdef __USE_LARGEFILE64
struct statfsx64
  {
    unsigned int f_type;           /* type of filesystem (see fsinfo.h) */
    unsigned int f_bsize;               /* file system block size */ 
    unsigned long int f_frsize;    /* fragment size: fundamental filesystem block */
    unsigned long int f_iosize;    /* optimal transfer block size */
    __fsblkcnt64_t f_blocks;       /* total number of blocks on file system
in units of f_frsize */
    __fsblkcnt64_t f_bfree;             /* total number of free blocks */    
                          
    __fsblkcnt64_t f_bavail;       /* number of free blocks available to non-privileged
process */ 
    __fsblkcnt64_t f_files;             /* total number of file serial numbers
*/                       
    __fsblkcnt64_t f_ffree;             /* total number of free file serial numbers
*/                  
    __fsfilcnt_t f_favail;         /* number of file serial numbers available
to non-privileged process */
    __fsid_t f_fsid;                    /* file system id */         
    __uid_t     f_owner;       /* user that mounted the filesystem */
    unsigned long int f_flag; /* bit mask of f_flag values */
    char f_fstypename[MFSNAMELEN]; /* fs type name */
    char f_mntonname[MNAMELEN];   /* directory on which mounted */
    char f_mntfromname[MNAMELEN];/* mounted filesystem */
    unsigned int f_namelen;             /* maximum filename length */
  };
#endif

/* Tell code we have this member.  */
#define _STATFS_F_NAMELEN
