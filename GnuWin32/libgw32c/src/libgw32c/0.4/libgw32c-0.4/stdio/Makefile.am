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
tst-fseek \
tst-seek

lib_LIBRARIES=libstdio.a

LDADD = ./libstdio.a ../libgw32c.a 

LIBS = -liberty	-lole32 -luuid

$(noinst_PROGRAMS): $(lib_LIBRARIES)

libstdio_a_SOURCES = \
__fsetlocking.c \
flockfile.c \
ftrylockfile.c \
funlockfile.c \
fseeko.c \
fseeko64.c \
ftello.c \
ftello64.c

#stdfiles.c
