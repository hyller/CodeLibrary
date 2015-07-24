# Process this file with autoconf to produce a configure script.
AC_INIT(libc,0.3,gnuwin32@users.sourceforge.net)
AC_CONFIG_SRCDIR(acconfig.h)

AM_INIT_AUTOMAKE(libc,0.3)
#AC_CONFIG_HEADER(config.h:config.h.in)
AM_CONFIG_HEADER(config.h:config.h.in)

AM_MAINTAINER_MODE

# Checks for programs.
AC_PROG_CC
AM_PROG_AS
AC_PROG_INSTALL
AC_PROG_AWK
AC_PROG_RANLIB
AC_PROG_MAKE_SET

# Checks for header files.
AC_FUNC_ALLOCA
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_HEADER_STAT
AC_HEADER_STDBOOL
AC_HEADER_TIME
AC_HEADER_MAJOR

AC_CHECK_HEADERS([argz.h fcntl.h fenv.h float.h inttypes.h langinfo.h libintl.h limits.h \
locale.h malloc.h mntent.h nl_types.h paths.h sgtty.h stddef.h stdint.h stdio_ext.h stdlib.h \
string.h strings.h sys/file.h sys/ioctl.h sys/param.h sys/statfs.h sys/statvfs.h sys/systeminfo.h \
sys/time.h sys/timeb.h termios.h unistd.h utime.h wchar.h wctype.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STAT
AC_HEADER_STDBOOL
AC_C_CONST
AC_TYPE_UID_T
AC_C_INLINE
AC_TYPE_MODE_T
AC_FUNC_OBSTACK
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_CHECK_MEMBERS([struct stat.st_blksize])
AC_STRUCT_ST_BLOCKS
AC_CHECK_MEMBERS([struct stat.st_rdev])
AC_CHECK_DECLS([sys_siglist])
AC_HEADER_TIME
AC_STRUCT_TM
AC_STRUCT_TIMEZONE
AC_C_VOLATILE
AC_CHECK_TYPES([ptrdiff_t])

AC_DEFINE(HAVE_XCOFF, [1], [coff type of executables])

# Checks for library functions.
AC_PROG_GCC_TRADITIONAL
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_STAT
AC_FUNC_VPRINTF
AC_HEADER_MAJOR
AC_FUNC_REALLOC
AC_FUNC_SELECT_ARGTYPES

AC_CONFIG_FILES([Makefile
				aout/Makefile
				argp/Makefile
				catgets/Makefile
				crypt/Makefile
				csu/Makefile
				ctype/Makefile
				dirent/Makefile
				dlfcn/Makefile
				fpu/Makefile
				grp/Makefile
				inet/Makefile
				io/Makefile
				locale/Makefile
				malloc/Makefile
				misc/Makefile
				posix/Makefile
			    pwd/Makefile
				signal/Makefile
				stdio/Makefile
				stdio-common/Makefile
				stdlib/Makefile
				string/Makefile
				resource/Makefile
				rt/Makefile
				termios/Makefile
				time/Makefile
				win32/Makefile])

#				nss/Makefile
#				iconv/Makefile
#				wcsmbs/Makefile
#				wctype/Makefile

AC_OUTPUT

