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
errno

lib_LIBRARIES=libcsu.a

LDADD = ./libcsu.a ../libgw32c.a

errno_CFLAGS = -DTEST

libcsu_a_SOURCES= \
errno.c	\
init-first.c 

