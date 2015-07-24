#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ../make.common

bin_PROGRAMS = \
fullpath \
osname \
ps

noinst_PROGRAMS = \
test_progname \
rootdir	\
splitpath

LDADD = ./libwin32.a ../libgw32c.a 

fullpath_SOURCES = fullpath.c fullpath.rc
am_fullpath_OBJECTS = fullpath.o fullpath-rc.o
splitpath_CFLAGS = -DTEST
rootdir_CFLAGS = -DTEST
rootdir_SOURCES = rootdir.c

$(bin_PROGRAMS): $(lib_LIBRARIES)
$(noinst_PROGRAMS): $(lib_LIBRARIES)

lib_LIBRARIES = libwin32.a

libwin32_a_SOURCES = \
getmachinfo.c \
getosinfo.c \
progname.c \
rootdir.c \
splitpath.c \
sysinfo.c \
winerr.c \
wsacleanup.c \
wsaerr.c \
wsinit.c 
