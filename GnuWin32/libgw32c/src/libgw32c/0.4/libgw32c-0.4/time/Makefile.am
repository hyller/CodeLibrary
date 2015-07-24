#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ../make.common

lib_LIBRARIES = libtime.a

noinst_PROGRAMS = \
	clocktest \
	test_gettimeofday \
	test_getntptimeofday \
	test_settimeofday \
	test_setntptimeofday \
	tst-mktime \
	tst-posixtz \
	tst-strftime \
	tst-strptime \
	tst_wcsftime
#	tst-ftime_l 
#	tst-getdate 


LDADD = ./libtime.a ../libgw32c.a

$(noinst_PROGRAMS): $(lib_LIBRARIES)

libtime_a_SOURCES = \
clock.c \
gettimeofday.c \
getntptimeofday.c \
settimeofday.c \
setntptimeofday.c \
strptime.c \
tzset.c
#alt_digit.c 
#getdate.c 
#lc-time-cleanup.c 
#mktime.c
#era.c
