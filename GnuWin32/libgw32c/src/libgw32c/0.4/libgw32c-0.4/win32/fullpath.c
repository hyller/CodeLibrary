#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <getopt.h>
#include <errno.h>
#include <gw32.h>

static char prog_name[MAX_PATH];
static int path_flag = 0, unix_flag = 0, windows_flag = 0, absolute_flag = 0,
	shortname_flag = 0;

static struct option long_options[] =
{
  { (char *) "help", no_argument, NULL, 'h' },
  { (char *) "unix", no_argument, NULL, 'u' },
  { (char *) "windows", no_argument, NULL, 'w' },
  { (char *) "short-name", no_argument, NULL, 's' },
  { (char *) "full-path", no_argument, NULL, 'f' },
  { 0, no_argument, 0, 0 }
};

static void
usage ()
{
    fprintf (stderr, "\
Usage: %s (-u|--unix)|(-w|--windows)|(-s|--short-name)|(-f|--fullpath) filename\n\
  -u|--unix         print Unix form of filename\n\
  -w|--windows      print Windows form of filename\n\
  -s|--short-name   print short form of filename\n\
  -f|--full-path    print full path of filename\n",
  prog_name);
  exit (0);
}


int
main (int argc, char **argv)
{
	char *FileName = NULL;
	char PathBuffer [MAX_PATH];
	int c;

	getprogname (prog_name);
	while ((c = getopt_long (argc, argv, (char *) "fhsuw", long_options, (int *) NULL))
	    	!= EOF) {
	    switch (c) {
		case 'f':
			path_flag = 1;
			break;
		case 'u':
			if (unix_flag || windows_flag)
				usage ();
			unix_flag = 1;
			break;
		case 'w':
			if (unix_flag || windows_flag)
				usage ();
			windows_flag = 1;
			break;
		case 's':
//			if (unix_flag)
//				usage ();
			shortname_flag = 1;
			break;
		default:
			usage ();
			break;
		}
    }
    if (optind != argc - 1)
		usage ();
	FileName = argv[optind];
	if (!file_exists (FileName)) {
		__set_errno (EINVAL);
		return -1;
	}
	if (path_flag) {
		if (!realpath (FileName, PathBuffer)) {
			set_werrno;
			return -1;
		}
	}
	else
		strcpy (PathBuffer, FileName);
//	fprintf(stderr, "PathBuffer1: %s\n", PathBuffer);
//	fprintf(stderr, "lpFilePart1: %s\n", lpFilePart);
	if (shortname_flag)
		FileName = getshortpath (PathBuffer, PathBuffer);
	else
		FileName = getlongpath (PathBuffer, PathBuffer);
	if (!FileName)
		return -1;
	if (unix_flag)
		win2unixpath (FileName);
	if (windows_flag)
		unix2winpath (FileName);
	printf("%s", FileName);
	return 1;
}

