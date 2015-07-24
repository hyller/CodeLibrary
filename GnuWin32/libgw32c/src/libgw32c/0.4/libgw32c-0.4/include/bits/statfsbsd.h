/*
 * Copyright (c) 1989, 1991, 1993
 *   The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *   This product includes software developed by the University of
 *   California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *   @(#)mount.h    8.21 (Berkeley) 5/20/95
 *   $Id: mount.h,v 1.44 1997/07/22 08:03:19 bde Exp $
 */

#ifndef _SYS_STATFSBSD_H
# error "Never include <bits/statfsbsd.h> directly; use <sys/statfsbsd.h> instead."
#endif

#include <bits/types.h>

typedef struct fsid { __int32_t val[2]; } fsid_t;   /* file system id type */

/*
 * file system statistics
 */

#define MFSNAMELEN  16   /* length of fs type name, including null */
#define   MNAMELEN  90   /* length of buffer for returned name */

struct statfsbsd {
     long f_spare2;      /* placeholder */
     long f_bsize;       /* fundamental file system block size */
     long f_iosize;      /* optimal transfer block size */
     long f_blocks;      /* total data blocks in file system */
     long f_bfree;       /* free blocks in fs */
     long f_bavail;      /* free blocks avail to non-superuser */
     long f_files;       /* total file nodes in file system */
     long f_ffree;       /* free file nodes in fs */
     fsid_t    f_fsid;             /* file system id */
     __uid_t     f_owner;       /* user that mounted the filesystem */
     int  f_type;             /* type of filesystem (see below) */
     int  f_flags;       /* copy of mount flags */
     unsigned int f_namelen;
     long f_spare[2];         /* spare for later */
     char f_fstypename[MFSNAMELEN]; /* fs type name */
     char f_mntonname[MNAMELEN];   /* directory on which mounted */
     char f_mntfromname[MNAMELEN];/* mounted filesystem */
};

#define statfsbsd64 statfsbsd

/*
 * File system types (for backwards compat with 4.4Lite.)
 */
#define   MOUNT_NONE     0
#define   MOUNT_UFS 1    /* Fast Filesystem */
#define   MOUNT_NFS 2    /* Sun-compatible Network Filesystem */
#define   MOUNT_MFS 3    /* Memory-based Filesystem */
#define   MOUNT_MSDOS    4    /* MS/DOS Filesystem */
#define   MOUNT_LFS 5    /* Log-based Filesystem */
#define   MOUNT_LOFS     6    /* Loopback Filesystem */
#define   MOUNT_FDESC    7    /* File Descriptor Filesystem */
#define   MOUNT_PORTAL   8    /* Portal Filesystem */
#define MOUNT_NULL  9    /* Minimal Filesystem Layer */
#define MOUNT_UMAP  10   /* User/Group Identifier Remapping Filesystem */
#define MOUNT_KERNFS     11   /* Kernel Information Filesystem */
#define MOUNT_PROCFS     12   /* /proc Filesystem */
#define MOUNT_AFS   13   /* Andrew Filesystem */
#define MOUNT_CD9660     14   /* ISO9660 (aka CDROM) Filesystem */
#define MOUNT_UNION 15   /* Union (translucent) Filesystem */
#define MOUNT_DEVFS 16   /* existing device Filesystem */
#define   MOUNT_EXT2FS   17   /* Linux EXT2FS */
#define MOUNT_TFS   18   /* Netcon Novell filesystem */
#define   MOUNT_MAXTYPE  18

#define INITMOUNTNAMES { \
     "none",        /*  0 MOUNT_NONE */ \
     "ufs",         /*  1 MOUNT_UFS */ \
     "nfs",         /*  2 MOUNT_NFS */ \
     "mfs",         /*  3 MOUNT_MFS */ \
     "msdos",  /*  4 MOUNT_MSDOS */ \
     "lfs",         /*  5 MOUNT_LFS */ \
     "lofs",        /*  6 MOUNT_LOFS */ \
     "fdesc",  /*  7 MOUNT_FDESC */ \
     "portal", /*  8 MOUNT_PORTAL */ \
     "null",        /*  9 MOUNT_NULL */ \
     "umap",        /* 10 MOUNT_UMAP */ \
     "kernfs", /* 11 MOUNT_KERNFS */ \
     "procfs", /* 12 MOUNT_PROCFS */ \
     "afs",         /* 13 MOUNT_AFS */ \
     "cd9660", /* 14 MOUNT_CD9660 */ \
     "union",  /* 15 MOUNT_UNION */ \
     "devfs",  /* 16 MOUNT_DEVFS */ \
     "ext2fs", /* 17 MOUNT_EXT2FS */ \
     "tfs",         /* 18 MOUNT_TFS */ \
     0,        /* 18 MOUNT_SPARE */ \
}

