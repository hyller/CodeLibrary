# Copyright (C) 2002 GnuWin32 <gnuwin32@users.sourceforge.net>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ./make.common

EXTRA_DIST = reconf configure

SUBLIBDIRS = \
aout argp catgets crypt csu ctype dirent dlfcn fpu grp \ 
inet io locale malloc misc  posix pwd \
resource rt signal stdlib stdio stdio-common \
string termios time win32
#iconv nss wcsmbs wctype

SUBLIBS = $(foreach dir, $(SUBLIBDIRS), $(dir)/lib$(dir).a)
SUBDIRS = $(SUBLIBDIRS)

lib_LIBRARIES = libc.a libc.dll.a libgw32c.a
libc_a_SOURCES =
libgw32c_a_SOURCES =
libc_dll_a_SOURCES =
libc.a:	$(SUBLIBS)
	rm -f $@
	rm -rf $@.libs
	mkdir $@.libs
	cd $@.libs && \
	for sl in $(SUBLIBS); do \
		ar x ../$$sl; \
	done
	ar cru $@ $@.libs/*.o
	rm -rf $@.libs

libc.dll.a: libc.a libc-rc.o
	a2dll libc.a -o libc.dll -l-- -lintl -liconv -liberty -lwsock32 -lole32 -luuid

libgw32c.a: libc.a libc.dll.a
	cp -bfp libc.a libgw32c.a
	cp -bfp libc.dll.a libgw32c.dll.a
