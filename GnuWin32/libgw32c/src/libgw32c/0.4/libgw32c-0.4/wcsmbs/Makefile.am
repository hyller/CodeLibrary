#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ../make.common

#lib_LIBRARIES = libwcsmbs.a

#noinst_PROGRAMS = \
tst-btowc \
tst-mbrtowc \
tst-wcrtomb \
tst-wcsnlen \
tst-wcstof


LDADD = ./libwcsmbs.a ../libgw32c.a

$(noinst_PROGRAMS): $(lib_LIBRARIES)

libwcsmbs_a_SOURCES = \
btowc.c \
mbrlen.c \
mbrtowc.c \
mbsinit.c \
mbsnrtowcs.c \
mbsrtowcs.c \
mbsrtowcs_l.c \
wcpcpy.c \
wcpncpy.c \
wcrtomb.c \
wcscasecmp.c \
wcscasecmp_l.c \
wcscat.c \
wcschr.c \
wcschrnul.c \
wcscmp.c \
wcscoll.c \
wcscoll_l.c \
wcscpy.c \
wcscspn.c \
wcsdup.c \
wcslen.c \
wcsmbs-tst1.c \
wcsmbsload.c \
wcsncase.c \
wcsncase_l.c \
wcsncat.c \
wcsncmp.c \
wcsncpy.c \
wcsnlen.c \
wcsnrtombs.c \
wcspbrk.c \
wcsrchr.c \
wcsrtombs.c \
wcsspn.c \
wcsstr.c \
wcstod.c \
wcstod_l.c \
wcstof.c \
wcstof_l.c \
wcstok.c \
wcstold.c \
wcstold_l.c \
wcswidth.c \
wcsxfrm.c \
wcsxfrm_l.c \
wctob.c \
wcwidth.c \
wmemchr.c \
wmemcmp.c \
wmemcpy.c \
wmemmove.c \
wmempcpy.c \
wmemset.c
