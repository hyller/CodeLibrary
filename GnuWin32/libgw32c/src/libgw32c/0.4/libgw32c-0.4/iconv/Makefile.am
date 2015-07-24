#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ../make.common

#lib_LIBRARIES=libiconv.a

#noinst_PROGRAMS = \
tst-iconv1 \
tst-iconv2 \
tst-iconv3

LDADD = ./libiconv.a ../libgw32c.a

AM_CPPFLAGS = -I../locale/programs -I../wcsmbs -DGCONV_DIR='"$(gconvdir)"' -DGCONV_PATH='"$(gconvdir)"'

$(noinst_PROGRAMS): $(lib_LIBRARIES)

libiconv_a_SOURCES = \
dummy-repertoire.c \
gconv.c \
gconv_builtin.c \
gconv_cache.c \
gconv_close.c \
gconv_conf.c \
gconv_db.c \
gconv_dl.c \
gconv_open.c \
gconv_simple.c \
gconv_trans.c \
iconv.c \
iconv_charmap.c \
iconv_close.c \
iconv_open.c \
iconv_prog.c \
iconvconfig.c \
strtab.c 
