#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ../make.common

noinst_PROGRAMS = test-ffs
LDADD = ./libstring.a ../libgw32c.a

lib_LIBRARIES = libstring.a

$(noinst_PROGRAMS): $(lib_LIBRARIES)

libstring_a_SOURCES = \
_strerror.c \
argz-addsep.c \
argz-append.c \
argz-count.c \
argz-create.c \
argz-ctsep.c \
argz-delete.c \
argz-extract.c \
argz-insert.c \
argz-next.c \
argz-replace.c \
argz-stringify.c \
basename.c \
bcopy.c \
bzero.c \
envz.c \
ffs.c \
memfrob.c \
mempcpy.c \
memrchr.c \
rawmemchr.c \
stpcpy.c \
stpncpy.c \
strchrnul.c \
strfry.c \
strlcat.c \
strlcpy.c \
strmode.c \
strncase.c \
strndup.c \
strnlen.c \
strsep.c \
strsignal.c \
strtok_r.c \
strverscmp.c \
wordcopy.c

#strncase_l.c \
#strerror.c \
