/* Copyright (C) 1991, 1995, 1996, 1997 Free Software Foundation, Inc.
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
   02111-1307 USA.  */

#include <errno.h>
#include <signal.h>
#include <windows.h>


/* Send signal SIG to process number PID.  If PID is zero,
   send SIG to all processes in the current process's process group.
   If PID is < -1, send SIG to all processes in process group - PID.  */
int
__kill (pid, sig)
     int pid;
     int sig;
{
	int res = 0;
	HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
	
    if (hProcess == NULL) {
		set_werrno;
        return -1;
	}
    switch (sig) {
	  	case SIGABRT:
  		case SIGKILL:
			if (!TerminateProcess (hProcess, -1)) {
				set_werrno;
				res = -1;
			}
			break;
		case 0:
			break;
  		case SIGHUP:
	  	case SIGINT:
  		case SIGQUIT:
	  	case SIGALRM:
  		case SIGTERM:
		default:
			__set_errno (EINVAL);
			res = -1;
			break;
  }
  CloseHandle(hProcess);
  return res;
}

weak_alias (__kill, kill)
