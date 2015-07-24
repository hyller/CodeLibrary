#include <stdio.h>
#include <windows.h>

#ifdef gethostname
#undef gethostname
#endif


int __w32_gethostname (char *__name, size_t __len)
{

	if (ws_init() == -1)
		return -1;
	if (gethostname (__name, __len) < 0) {
		WSAErr;
		return -1;
	}

	return 0;
}
 
weak_alias (__w32_gethostname, w32_gethostname)
