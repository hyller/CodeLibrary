#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ../make.common

noinst_PROGRAMS = \
mntent \
tst-dirname \
tst-mntent \
test_usleep	\
tst-hsearch \
tst-tsearch

$(noinst_PROGRAMS): $(lib_LIBRARIES)

mntent_SOURCES = mntent_r.c
mntent_CFLAGS = -DTEST

lib_LIBRARIES=libmisc.a

LDADD = ./libmisc.a ../libgw32c.a

libmisc_a_SOURCES = \
brk.c \
chflags.c \
chroot.c \
dirname.c \
efgcvt.c \
efgcvt_r.c \
err.c \
error.c \
fchflags.c \
fdatasync.c \
fgetxattr.c \
flistxattr.c \
fremovexattr.c \
fsetxattr.c \
fstab.c \
ftruncate.c \
ftruncate64.c \
futimes.c \
getclktck.c \
getdomain.c \
getdtsz.c \
gethostid.c \
gethostbyaddr.c \
gethostbyname.c \
gethostname.c \
getloadavg.c \
getpagesize.c \
getpass.c \
getsysstats.c \
getusershell.c \
getxattr.c \
gtty.c \
hsearch.c \
hsearch_r.c \
init-misc.c \
insremque.c \
ioctl.c \
lgetxattr.c \
listxattr.c \
llistxattr.c \
lremovexattr.c \
lsearch.c \
lsetxattr.c \
lutimes.c \
madvise.c \
mkdtemp.c \
mkstemps.c \
mkstemp64.c \
mktemp.c \
mlock.c \
mlockall.c \
mmap.c \
mmap64.c \
mntent.c \
mntent_r.c \
mprotect.c \
mremap.c \
msync.c \
munlock.c\
munlockall.c \
munmap.c \
qefgcvt.c \
qefgcvt_r.c \
readv.c \
removexattr.c \
sbrk.c \
select.c \
setdomain.c \
setegid.c \
sethostid.c \
sethostname.c \
setregid.c \
setreuid.c \
setxattr.c \
sync.c \
syscall.c \
tsearch.c \
truncate.c \
truncate64.c \
usleep.c \
ustat.c \
utimes.c

#fsync.c \
