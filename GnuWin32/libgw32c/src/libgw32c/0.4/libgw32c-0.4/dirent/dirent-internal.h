#ifndef _DIRENT_INTERNAL_H_
#define _DIRENT_INTERNAL_H_

typedef struct DIRdata {
	char *dirname;
	struct dirent64 DIRdir;
} DIRdata;

#endif /* _DIRENT_INTERNAL_H_ */
