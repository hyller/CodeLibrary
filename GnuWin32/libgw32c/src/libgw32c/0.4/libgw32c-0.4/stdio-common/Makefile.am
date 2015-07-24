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
temptest \
test_tmpnam \
tst-tmpnam 

#tst-perror

perror_CFLAGS = -DTEST

LDADD = ./libstdio-common.a ../libgw32c.a

$(noinst_PROGRAMS): $(lib_LIBRARIES)

lib_LIBRARIES = libstdio-common.a

libstdio_common_a_SOURCES = \
cuserid.c \
errlist.c \
getline.c \
itoa-digits.c \
itoa-udigits.c \
rename.c \
remove.c \
siglist.c \
tempnam.c \
tempname.c \
tmpfile.c \
tmpfile64.c \
tmpnam.c \
tmpnam_r.c

#_itoa.c \
#perror.c \
perror
