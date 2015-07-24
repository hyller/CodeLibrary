#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ../make.common

bin_PROGRAMS = gstat 

noinst_PROGRAMS = euidaccess \
symlink readlink link stat stat64 fstat64 fstat test-utime \
ftwtest tst-getcwd tst-fcntl test-lfs test-stat test-stat2

lib_LIBRARIES = libio.a

LDADD = ./libio.a ../libgw32c.a

LIBS = -liberty	-lole32 -luuid

link_SOURCES = link.c
link_CFLAGS = -DTEST
symlink_CFLAGS = -DTEST
symlink_SOURCES = symlink.c
readlink_CFLAGS = -DTEST
readlink_SOURCES = readlink.c
stat_CFLAGS = -DTEST
stat_SOURCES = stat.c
stat64_CFLAGS = -DTEST
stat64_SOURCES = stat64.c
fstat_CFLAGS = -DTEST
fstat_SOURCES = fstat.c
fstat64_CFLAGS = -DTEST
fstat64_SOURCES = fstat64.c
euidaccess_CFLAGS = -DTEST
euidaccess_SOURCES = euidaccess.c
test_utime_CFLAGS = -DTEST
test_utime_SOURCES = test-utime.c
test_stat_CFLAGS = -D_FILE_OFFSET_BITS=64
#test_stat2_CFLAGS = -D_FILE_OFFSET_BITS=64

gstat_SOURCES = gstat.c gstat.rc
am_gstat_OBJECTS = gstat.o gstat-rc.o

$(bin_PROGRAMS): $(lib_LIBRARIES)
$(noinst_PROGRAMS): $(lib_LIBRARIES)

libio_a_SOURCES = \
access.c \
chdir.c \
chown.c \
euidaccess.c \
fchdir.c \
fchmod.c \
fchown.c \
fcntl.c \
fstat.c \
fstat64.c \
fstatfs.c \
fstatfs64.c \
fstatvfs.c \
fstatvfs64.c \
fts.c \
ftw.c \
ftw64.c \
fxstat.c \
fxstat64.c \
getcwd.c \
getdirname.c \
getwd.c \
hxstat64.c \
lchmod.c \
lchown.c \
link.c \
lstat.c \
lstat64.c \
lxstat.c \
lxstat64.c \
mkdir.c \
mkfifo.c \
mknod.c \
pipe.c \
readlink.c \
rmdir.c \
stat.c \
stat64.c \
stat64_to_32.c \
statfs.c \
statfs64.c \
statfsx64.c \
statfsbsd.c \
statvfs.c \
statvfs64.c \
symlink.c \
ttyname.c \
unlink.c \
utime.c \
xmknod.c \
xstat.c	\
xstat64.c

#ftw.c \
#ftw64.c \
