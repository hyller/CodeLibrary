#include <errno.h>
#include <string.h>
#ifndef _UTSNAME_DOMAIN_LENGTH 
# define _UTSNAME_DOMAIN_LENGTH  _UTSNAME_LENGTH
#endif
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/systeminfo.h>
#include <stdio.h>
#include <winsock.h>

int
main (int argc, char **argv)
{
  struct utsname name;
  char processor[256];

  if (uname (&name) == -1)
    fprintf(stderr, "Cannot get uname\n");

  fprintf(stderr, "Hostname: %s\n", name.nodename);
  fprintf(stderr, "Sysname: %s\n", name.sysname);
  fprintf(stderr, "Release: %s\n", name.release);
  fprintf(stderr, "Version: %s\n", name.version);
  fprintf(stderr, "Domainname: %s\n", name.domainname);
  fprintf(stderr, "Machine: %s\n", name.machine);

  if (sysinfo (SI_ARCHITECTURE, processor, sizeof (processor)) == -1)
    fprintf(stderr, "Cannot get processor type\n");

  fprintf(stderr, "Processor: %s\n", processor);
  return 0;
}

