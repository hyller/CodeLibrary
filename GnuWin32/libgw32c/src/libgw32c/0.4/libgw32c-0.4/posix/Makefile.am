#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include ../make.common

noinst_PROGRAMS = \
test_alarm \
test_uname	\
tst-truncate \
tst-truncate64 \
tstgetopt

lib_LIBRARIES = libposix.a

LDADD = ./libposix.a ../libgw32c.a

$(noinst_PROGRAMS): $(lib_LIBRARIES)

libposix_a_SOURCES = \
alarm.c \
fork.c \
fpathconf.c \
getgid.c \
getegid.c \
getlogin.c \
getopt.c \
getopt1.c \
getopt_init.c \
getpgrp.c \
getpgid.c \
getppid.c \
getsid.c \
getuid.c \
geteuid.c \
group_member.c \
nanosleep.c \
pathconf.c \
setgid.c \
setlogin.c \
setpgrp.c \
setpgid.c \
setuid.c \
sleep.c \
sysconf.c \
times.c \
uname.c \
wait.c \
wait3.c \
wait4.c \
waitid.c \
waitpid.c

#fnmatch.c
