#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ../make.common

bin_PROGRAMS = gencat

LDADD = ./libcatgets.a ../libgw32c.a

LIBS = -liberty -lole32 -luuid -lintl -liconv

gencat_SOURCES = gencat.c
am_gencat_OBJECTS = gencat.o

$(bin_PROGRAMS): $(lib_LIBRARIES)

lib_LIBRARIES = libcatgets.a

libcatgets_a_SOURCES = \
catgets.c \
open_catalog.c
