#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ../make.common

#lib_LIBRARIES = libwctype.a

#noinst_PROGRAMS = \
test_wcfuncs \
test_wctype

LDADD = ./libwctype.a ../libgw32c.a

$(noinst_PROGRAMS): $(lib_LIBRARIES)

libwctype_a_SOURCES = \
iswctype.c \
iswctype_l.c \
towctrans.c \
towctrans_l.c \
wcfuncs.c \
wcfuncs_l.c \
wctrans.c \
wctrans_l.c \
wctype.c \
wctype_l.c
