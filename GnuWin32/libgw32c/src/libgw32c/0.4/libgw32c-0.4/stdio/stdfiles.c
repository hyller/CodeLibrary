/* Copyright (C) 1993-1997,1999,2000,2002 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.

   As a special exception, if you link the code in this file with
   files compiled with a GNU compiler to produce an executable,
   that does not cause the resulting executable to be covered by
   the GNU Lesser General Public License.  This exception does not
   however invalidate any other reasons why the executable file
   might be covered by the GNU Lesser General Public License.
   This exception applies to code released by its copyright holders
   in files containing the exception.  */


/* This file provides definitions of _IO_stdin, _IO_stdout, and _IO_stderr
   for C code.  Compare stdstreams.cc.
   (The difference is that here the vtable field is set to 0,
   so the objects defined are not valid C++ objects.  On the other
   hand, we don't need a C++ compiler to build this file.) */

#include <stdio.h>

FILE *stdin = (&_iob[STDIN_FILENO]);          /* Standard input stream.  */
FILE *stdout = (&_iob[STDOUT_FILENO]);         /* Standard output stream.  */
FILE *stderr = (&_iob[STDERR_FILENO]);         /* Standard error output stream.  */
