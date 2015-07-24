#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ../make.common

noinst_PROGRAMS = tst-dir list tst-seekdir bug-readdir1	opendir-tst1
list_CFLAGS = -D_FILE_OFFSET_BITS=64
LDADD = ./libdirent.a ../libgw32c.a

lib_LIBRARIES = libdirent.a

$(noinst_PROGRAMS): $(lib_LIBRARIES)

libdirent_a_SOURCES = \
alphasort.c \
alphasort64.c \
closedir.c \
dirfd.c \
opendir.c \
readdir.c \
readdir_r.c \
readdir64.c \
readdir64_r.c \
rewinddir.c \
scandir.c \
scandir64.c \
seekdir.c \
telldir.c \
versionsort.c \
versionsort64.c


#dirent.c
