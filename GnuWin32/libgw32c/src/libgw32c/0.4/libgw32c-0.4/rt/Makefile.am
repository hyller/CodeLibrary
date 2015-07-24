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
tst-clock \
tst-cpu

LDADD = ./librt.a ../libgw32c.a

$(noinst_PROGRAMS): $(lib_LIBRARIES)

lib_LIBRARIES=librt.a

librt_a_SOURCES = \
clock_getcpuclockid.c \
clock_getres.c \
clock_gettime.c \
clock_nanosleep.c \
clock_settime.c \
cpuspeed.c \
get_clockfreq.c

