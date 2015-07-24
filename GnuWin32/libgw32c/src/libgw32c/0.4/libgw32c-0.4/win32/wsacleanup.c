#include <errno.h>
#include <windows.h>

void ws_cleanup(void)
{
	if (!WSACleanup())
		set_werrno;
}
