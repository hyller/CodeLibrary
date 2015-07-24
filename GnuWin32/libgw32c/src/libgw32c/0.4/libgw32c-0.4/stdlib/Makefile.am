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
fullname

$(bin_PROGRAMS): $(lib_LIBRARIES)

noinst_PROGRAMS = tst-xpg-basename

$(noinst_PROGRAMS): $(lib_LIBRARIES)

LDADD = ./libstdlib.a ../libgw32c.a

#longname_SOURCES = longname.c longname.rc
#am_longname_OBJECTS = longname.o longname-rc.o

lib_LIBRARIES = libstdlib.a

libstdlib_a_SOURCES = \
a64l.c \
bsearch.c \
canonicalize.c \
drand48-iter.c \
drand48.c \
drand48_r.c \
erand48.c \
erand48_r.c \
jrand48.c \
jrand48_r.c \
lcong48.c \
lcong48_r.c \
lrand48.c \
lrand48_r.c \
lshift.c \
l64a.c \
mrand48.c \
mrand48_r.c \
msort.c \
nrand48.c \
nrand48_r.c \
qsort.c \
rand.c \
rand_r.c \
random.c \
random_r.c \
rshift.c \
secure-getenv.c \
seed48.c \
seed48_r.c \
setenv.c \
srand48.c \
srand48_r.c	\
xpg_basename.c
