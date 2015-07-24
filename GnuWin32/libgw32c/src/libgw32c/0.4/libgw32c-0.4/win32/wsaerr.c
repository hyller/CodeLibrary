#include <stdio.h>
#include <windows.h>
#include <gw32.h>

void WSAErr(const char *Msg)
{
	LPVOID lpMsgBuf;

	lpMsgBuf = DecodeError(WSAGetLastError());
	fprintf(stderr, "%s: Socket error %d: %s\n", 
		Msg, WSAGetLastError(), lpMsgBuf);
	LocalFree(lpMsgBuf);
}
