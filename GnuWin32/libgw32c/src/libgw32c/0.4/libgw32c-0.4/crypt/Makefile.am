# Copyright (C) 2002 GnuWin32 <gnuwin32@users.sourceforge.net>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


include ../make.common

lib_LIBRARIES=libcrypt.a

libcrypt_a_SOURCES=crypt-entry.c crypt.c crypt_util.c \
	md5-crypt.c md5.c crypt-private.h md5.h ufc-crypt.h

bin_PROGRAMS = cert md5test md5c-test ufc

LDADD = -L. -lcrypt -lc


