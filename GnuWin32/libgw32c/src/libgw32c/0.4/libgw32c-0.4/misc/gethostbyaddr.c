#include <stdio.h>
#include <windows.h>
#ifdef gethostbyadddr
#undef gethostbyaddr
#endif

/* Return entry from host data base which address match ADDR with
   length LEN and type TYPE.  */
struct hostent *__w32_gethostbyaddr (__const void *__addr, __socklen_t __len,
                          int __type)
{
	struct hostent *ht;
	
	if (ws_init() == -1)
		return NULL;

	ht = gethostbyaddr (__addr, __len, __type);
	if (ht == NULL)
		WSAErr;
	return ht;
}
 
weak_alias (__w32_gethostbyaddr, w32_gethostbyaddr)
