#include <stdio.h>
#include <windows.h>
#include <errno.h>
#include <gw32.h>

static int ws_init_done = 0;
int ws_init ()
{
	if (!ws_init_done ) {
		int wsaerr;
    	WORD wVersionRequested;
		WSADATA wsaData;

		wVersionRequested = MAKEWORD( 1, 0 );
	    wsaerr = WSAStartup(wVersionRequested, &wsaData);
		if (wsaerr) {
			__set_errno (__get_errno (wsaerr));
			WSAErr("WSAStartup");
		    return -1;
		}
		atexit(ws_cleanup);
		ws_init_done = 1;
	}
	return 0;
}	
