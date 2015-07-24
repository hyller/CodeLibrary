#
# This is the Makefile for the readline examples subdirectory.
#
# Copyright (C) 1994 Free Software Foundation, Inc.

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA.
RL_LIBRARY_VERSION = 5.0

SHELL = /bin/sh
RM = rm -f

srcdir = ../../readline-5.0-src/examples
VPATH = .:../../readline-5.0-src/examples
top_srcdir = ../../readline-5.0-src
BUILD_DIR = .

# Support an alternate destination root directory for package building
DESTDIR =

DEFS = -DHAVE_CONFIG_H
CC = gcc
CFLAGS =  -Wall -O3 -fms-extensions -mms-bitfields  -fno-exceptions -fomit-frame-pointer -march=i386 -mcpu=i686  
LOCAL_CFLAGS =  -DREADLINE_LIBRARY -DRL_LIBRARY_VERSION='"$(RL_LIBRARY_VERSION)"'
CPPFLAGS =   -D__GW32__ -D_LARGEFILE_SOURCE=1 -D_LARGEFILE64_SOURCE=1 -D_FILE_OFFSET_BITS=64     -idirafter e:/progra~1/gnuwin32/include -idirafter h:/glibc/include   

INCLUDES = -I$(srcdir) -I$(top_srcdir) -I..

CCFLAGS  = $(DEFS) $(LOCAL_CFLAGS) $(CPPFLAGS) $(INCLUDES) $(CFLAGS)
LDFLAGS = -g -L..  -Wl,-s -Wl,--force-exe-suffix -Wl,--enable-auto-import -Wl,--enable-runtime-pseudo-reloc -Wl,--allow-multiple-definition   -L./lib/termcap

READLINE_LIB = ../libreadline.a
HISTORY_LIB = ../libhistory.a

TERMCAP_LIB = -ltermcap

.c.o:
	${RM} $@
	$(CC) $(CCFLAGS) -c $<

EXECUTABLES = fileman rltest rl rlcat rlversion histexamp 
OBJECTS = fileman.o rltest.o rl.o rlcat.o rlversion.o histexamp.o

all: $(EXECUTABLES)
everything: all rlfe

rl: rl.o $(READLINE_LIB)
	$(CC) $(LDFLAGS) -o $@ rl.o -lreadline $(TERMCAP_LIB)

rlcat: rlcat.o $(READLINE_LIB)
	$(CC) $(LDFLAGS) -o $@ rlcat.o -lreadline $(TERMCAP_LIB)

fileman: fileman.o $(READLINE_LIB)
	$(CC) $(LDFLAGS) -o $@ fileman.o -lreadline $(TERMCAP_LIB)

rltest: rltest.o $(READLINE_LIB)
	$(CC) $(LDFLAGS) -o $@ rltest.o -lreadline $(TERMCAP_LIB)

rlversion: rlversion.o $(READLINE_LIB)
	$(CC) $(LDFLAGS) -o $@ rlversion.o -lreadline $(TERMCAP_LIB)

histexamp: histexamp.o $(HISTORY_LIB)
	$(CC) $(LDFLAGS) -o $@ histexamp.o -lhistory $(TERMCAP_LIB)

clean mostlyclean:
	$(RM) $(OBJECTS)
	$(RM) $(EXECUTABLES) *.exe
	$(RM) rlfe.o rlfe

distclean maintainer-clean: clean
	$(RM) Makefile

fileman.o: fileman.c
rltest.o: rltest.c
rl.o: rl.c
rlversion.o: rlversion.c
histexamp.o: histexamp.c

fileman.o: $(top_srcdir)/readline.h
rltest.o: $(top_srcdir)/readline.h
rl.o: $(top_srcdir)/readline.h
rlversion.o: $(top_srcdir)/readline.h
histexamp.o: $(top_srcdir)/history.h

# Stuff for Per Bothner's `rlfe' program
 
rlfe: rlfe.o $(READLINE_LIB) $(HISTORY_LIB)
	$(CC) $(LDFLAGS) -o $@ rlfe.o -lreadline -lhistory ${TERMCAP_LIB}

rlfe.o: rlfe.c

rlfe.o: $(top_srcdir)/readline.h
rlfe.o: $(top_srcdir)/history.h
