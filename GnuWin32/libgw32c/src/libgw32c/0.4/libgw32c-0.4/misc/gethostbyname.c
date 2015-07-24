#include <stdio.h>
#include <windows.h>
#ifdef gethostbyname
#undef gethostbyname
#endif
 
/* Return entry from host data base for host with NAME.  */
struct hostent *__w32_gethostbyname (__const char *__name)
{
	struct hostent *ht;
	
	if (ws_init() == -1)
		return NULL;
	ht = gethostbyname (__name);
	if (ht == NULL)
		WSAErr;
	return ht;
}
 
weak_alias (__w32_gethostbyname, w32_gethostbyname)
