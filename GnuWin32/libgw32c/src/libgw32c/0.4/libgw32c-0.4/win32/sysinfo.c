#include <sys/systeminfo.h>
#include <sys/utsname.h>
#include <errno.h>
#include <string.h>
#include <gw32.h>

long getuname(int command, char *buf, long count)
{
    struct utsname name;
	uname(&name);
	switch (command) {
		case SI_SYSNAME:
			return strlen(strncpy(buf, name.sysname, count));
			break;
		case SI_HOSTNAME:
			return strlen(strncpy(buf, name.nodename, count));
			break;
		case SI_RELEASE:
			return strlen(strncpy(buf, name.release, count));
			break;
		case SI_VERSION:
			return strlen(strncpy(buf, name.version, count));
			break;
		case SI_MACHINE:
			return strlen(strncpy(buf, name.machine, count));
			break;
		default:
			return -1;
	}
}

long sysinfo (int command, char *buf, long count)
{
	long retlen;
	
	switch (command) {
		case SI_SYSNAME:
		case SI_HOSTNAME:
		case SI_RELEASE:
		case SI_VERSION:
		case SI_MACHINE:
			return getuname(command, buf, count);
			break;
		case SI_ARCHITECTURE: {
			char machname [1024], procname[1024];
			GetMachInfo(machname, procname);
			return strlen(strncpy(buf, procname, count));
			break;
		}
		case SI_SET_HOSTNAME:
			return sethostname(buf, strlen(buf));
			break;
		case SI_HW_PROVIDER:
		case SI_HW_SERIAL:
		case SI_SRPC_DOMAIN:
		case SI_SET_SRPC_DOMAIN:
		case SI_INITTAB_NAME:
		case SI_VENDOR:
		case SI_OS_PROVIDER:
		case SI_OS_NAME:
		case SI_HW_NAME:
		case SI_NUM_PROCESSORS:
		case SI_HOSTID:
		case SI_OSREL_MAJ:
		case SI_OSREL_MIN:
		case SI_OSREL_PATCH:
		case SI_PROCESSORS:
		case SI_AVAIL_PROCESSORS:
			__set_errno(ENOSYS);
			return -1;
			break;
	}
}
