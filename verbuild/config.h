/*
 * config.h --- Dummy config.h for TCLAP.
 *
 * Copyright (c) 2013 Paul Ward <asmodai@gmail.com>
 *
 * Time-stamp: <Thursday May 30, 2013 11:53:46 asmodai>
 * Revision:   2
 *
 * Author:     Paul Ward <asmodai@gmail.com>
 * Maintainer: Paul Ward <asmodai@gmail.com>
 * Created:    30 May 2013 10:42:23
 * Keywords:   
 * URL:        not distributed yet
 */
/* {{{ License: */
/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see  <http://www.gnu.org/licenses/>.
 */
/* }}} */
/* {{{ Commentary: */
/*
 *
 */
/* }}} */

#ifndef _config_h_
#define _config_h_

/**
 * @file config.h
 * @author Paul Ward
 * @brief Dummy @em config.h for TCLAP.
 */

#if defined(_WIN32) || defined(_WIN64)

# define HAVE_CLASS_STRSTREAM
# define HAVE_INTTYPES_H
# define HAVE_LONG_LONG
# define HAVE_MEMORY_H
# define HAVE_NAMESPACE
# define HAVE_SSTREAM
# define HAVE_STDINT_H
# define HAVE_STDLIB_H
# define HAVE_STRINGS_H
# define HAVE_STRING_H
# define HAVE_STRSTREAM
# define HAVE_SYS_STAT_H
# define HAVE_SYS_TYPES_H
# undef HAVE_UNISTD_H

#elif defined(__linux) || defined(__linux__) || defined(__gnu_linux__)

# define HAVE_CLASS_STRSTREAM
# define HAVE_INTTYPES_H
# define HAVE_LONG_LONG
# define HAVE_MEMORY_H
# define HAVE_NAMESPACE
# define HAVE_SSTREAM
# define HAVE_STDINT_H
# define HAVE_STDLIB_H
# define HAVE_STRINGS_H
# define HAVE_STRING_H
# define HAVE_STRSTREAM
# define HAVE_SYS_STAT_H
# define HAVE_SYS_TYPES_H
# define HAVE_UNISTD_H

#endif

#endif /* !_config_h_ */

/* config.h ends here */
