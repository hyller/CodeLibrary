#include <stdio.h>
#include <gw32.h>

#define BUFSIZE 255

int
main (int argc, char **argv)
{
	char OsName [BUFSIZE];
	char Version [BUFSIZE];
	char Release [BUFSIZE];

	if (GetOsInfo(OsName, Release, Version))
		fprintf(stderr, "%s", OsName);
/*
	fprintf(stderr, "IsWinNT: %d\n", iswinnt ());
	fprintf(stderr, "IsWin9X: %d\n", iswin9x ());
	fprintf(stderr, "IsWin31: %d\n", iswin31 ());
	fprintf(stderr, "IsWinCE: %d\n", iswince ());
*/
	return 0;
}
