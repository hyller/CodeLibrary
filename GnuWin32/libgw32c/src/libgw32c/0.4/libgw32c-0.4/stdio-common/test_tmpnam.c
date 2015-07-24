#include <stdio.h>
#include <string.h>
//#include <windows.h>

int
main (int argc, char **argv)
{
	char name[256];
	char *pname;
	FILE *f;
	
	fprintf(stderr, "Prog:  %s\n", argv[0]);
	
	pname=tmpnam(NULL);
	f = fopen(pname, "w");
	fprintf(stderr, "Tmpnam:  %s\n", pname);
	pname=tmpnam(name);
	fprintf(stderr, "Tmpnam:  %s\n", pname);
	pname=tmpnam(name);
	fprintf(stderr, "Tmpnam:  %s\n", pname);
	pname=tmpnam(name);
	fprintf(stderr, "Tmpnam:  %s\n", pname);
	pname=tmpnam(name);
	fprintf(stderr, "Tmpnam:  %s\n", pname);
	pname=tmpnam(NULL);
	fprintf(stderr, "Tmpnam:  %s\n", pname);
}
