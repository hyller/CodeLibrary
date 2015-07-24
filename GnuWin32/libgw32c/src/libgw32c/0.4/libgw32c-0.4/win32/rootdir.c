#include <ctype.h>
#include <errno.h>
#include <sys/statfs.h>
#include <stddef.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <gw32.h>

#define MAX_DRIVES 32
static __uint64_t drivetable[MAX_DRIVES][2];
static int drivetable_initialized = 0;

static int
drivetable_init (void)
{
	char *rootlist = NULL;
	int n = -1;

	rootlist = getrootdirs (rootlist);
	while (rootlist && rootlist[0]) {
		drivetable[++n][0] = rootlist[0];
		drivetable[n][1] = GetVolumeSerialNumber (rootlist);
		rootlist = strchr (rootlist, 0) + 1;
	}
	drivetable_initialized = 1;
	return 1;
}

char
vsn2drive (const DWORD vsn)
{
	char drive = 0;
	int n = -1;
	
	if (!drivetable_initialized)
		drivetable_init ();
	while (drive == 0 && ++n <= MAX_DRIVES)
		if (drivetable[n][1] == vsn)
			drive = drivetable[n][0];
	return drive;
}

#ifdef __USE_FILE_OFFSET64
# error __USE_FILE_OFFSET64
#endif

/* Return the root directory of a file */
char * rootdir (const char *file)
{
	char *path, *RootDirectory, *p;
	int len;

	path = canonicalize_file_name (file);
#ifdef TEST
	fprintf (stderr, "Path: %s\n", path);
#endif /* TEST */
	if (path && strlen (path) >= 3 && path[1] == ':' && path[2] == '/') {
		RootDirectory = strdup (" :/");
		RootDirectory[0] = toupper (path[0]);
	}
	else if (path && (len = strlen (path)) >= 5 && path[0] == '/' && path[1] == '/') {
		p = strchr (path+2, '/');
		if (p)
			p = strchr (p+1, '/');
		if (p)
			len = p - path + 1;
		else
			len++;
		RootDirectory = calloc (len + 1, sizeof (char));
		strncpy (RootDirectory, path, len+1);
		RootDirectory[len-1] = '/';
		RootDirectory[len] = 0;
	}
	else
		RootDirectory = NULL;
	free (path);
	return (RootDirectory);
}

/* Return the root directory on a device */
char * devrootdir (const __dev_t dev)
{
	char *RootDirectory = strdup(" :\\");
	RootDirectory[0] = vsn2drive (dev);
	return (RootDirectory);
}

/* Return the root directory of a file descriptor */
char * frootdir (const int fd)
{
	struct stat64 sb;
	if (fstat64(fd, &sb) == -1)
		return NULL;
	return devrootdir (sb.st_dev);
}

#ifdef TEST
# include <stdio.h>

int main (int argc, char **argv)
{
	char *RootDirectory;

	fprintf (stderr, "File: %s\n", argv[1]);
	RootDirectory = rootdir (argv[1]);
	fprintf (stderr, "RootDirectory: %s\n", RootDirectory);
	free (RootDirectory);
	return 0;
}
#endif /* TEST */
