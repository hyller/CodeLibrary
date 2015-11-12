# Process this file with automake to produce Makefile.in (in this,
# and all subdirectories).
# Makefile for the top-level directory of GNU hello.
# 
# Copyright 1997, 1998, 2005, 2006, 2007, 2008 Free Software
# Foundation, Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Find gnulib headers.
ACLOCAL_AMFLAGS = -I gnulib/m4

# Additional files to distribute.
EXTRA_DIST = ChangeLog.O gnulib/m4/gnulib-cache.m4

# Subdirectories to descend into.
SUBDIRS = contrib gnulib/lib po src doc man tests

# `make diff' produces a diff against the previous version, given both
# .tar.gz's in the current directory.  This should only be done when an
# official release is made (and only if you care to provide diffs).
#
hello_pre = 2.3
#
diff: diffcheck
	@(echo "To apply these patches, cd to the main directory of the package"; \
	  echo "and then use \`patch -p1 < hello-XXX.diff'."; \
	  echo "Before building the program, run \`autogen.sh'."; ) > \
	    $(PACKAGE)-$(hello_pre)-$(VERSION).diff
	-diff -rc2P --exclude=configure --exclude=config.h.in --exclude=*.info \
	    --exclude=*.gmo --exclude=aclocal.m4 \
	    $(PACKAGE)-$(hello_pre) $(PACKAGE)-$(VERSION) >> \
	    $(PACKAGE)-$(hello_pre)-$(VERSION).diff
	gzip --force --best $(PACKAGE)-$(hello_pre)-$(VERSION).diff

diffcheck:
	for d in $(PACKAGE)-$(hello_pre) $(PACKAGE)-$(VERSION) ; do \
	    if test ! -d $$d ; then \
	        if test -r $$d.tar.gz ; then \
	            tar -zxf $$d.tar.gz ; \
                else \
	            echo subdir $$d does not exist. ; \
	            exit 1 ; \
                fi ; \
	    fi ; \
	done

# From coreutils.
# Verify that all source files using _() are listed in po/POTFILES.in.
# The idea is to run this before making pretests, as well as official
# releases, so that 
po-check:
	if test -f po/POTFILES.in; then					\
	  grep -E -v '^(#|$$)' po/POTFILES.in				\
	    | grep -v '^src/false\.c$$' | sort > $@-1;			\
	  files=;							\
	  for file in $$($(CVS_LIST_EXCEPT)) `find * -name '*.[ch]'`; do \
	    case $$file in						\
	    djgpp/* | man/*) continue;;					\
	    esac;							\
	    case $$file in						\
	    *.[ch])							\
	      base=`expr " $$file" : ' \(.*\)\..'`;			\
	      { test -f $$base.l || test -f $$base.y; } && continue;;	\
	    esac;							\
	    files="$$files $$file";					\
	  done;								\
	  grep -E -l '\b(N?_|gettext *)\([^)"]*("|$$)' $$files		\
	    | sort -u > $@-2;						\
	  diff -u $@-1 $@-2 || exit 1;					\
	  rm -f $@-1 $@-2;						\
	fi
