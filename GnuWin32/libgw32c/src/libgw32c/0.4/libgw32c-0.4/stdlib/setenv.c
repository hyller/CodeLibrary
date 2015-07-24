#include <stdlib.h>
#include <string.h>
#include <windows.h>

int setenv (const char *name, const char *value, int replace)
{
	char string0[MAX_PATH];
	char *string;

	if (getenv(name)!=NULL && replace==0)
		return 1;
	strcpy(string0, name);
	strcat(string0, "=");
	strcat(string0, value);
	string=strdup(string0);
	if (putenv(string))
		return 1;
	else
		return 0;
	
}

int unsetenv (const char *name)
{
	if (putenv(name))
		return 1;
	else
		return 0;
}
