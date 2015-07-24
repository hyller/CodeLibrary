#include <stdio.h>
#include <windows.h>

LPSTR DecodeError(const int ErrorCode)
{
	LPVOID lpMsgBuf;
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS |
		FORMAT_MESSAGE_MAX_WIDTH_MASK | FORMAT_MESSAGE_ALLOCATE_BUFFER,
        NULL, ErrorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf, 0, NULL);
    return lpMsgBuf;
}

void PrintWinErr(const char *Msg, const int ErrorCode)
{
	LPSTR lpMsgBuf;

	lpMsgBuf = DecodeError(ErrorCode);
	fprintf(stderr, "%s: Windows error %d: %s\n", 
		Msg, ErrorCode, lpMsgBuf);
//	fflush (stderr);
	LocalFree(lpMsgBuf);
}

void WinErr(const char *Msg)
{
	PrintWinErr (Msg, GetLastError ());
}
