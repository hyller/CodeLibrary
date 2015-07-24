#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <gw32.h>

int file_exists(const char *filename)
{
	return (access(filename, F_OK) != -1);
}

char *win2unixpath(char *FileName)
{
	char *s = FileName;
	while (*s) {
		if (*s == '\\')
			*s = '/';
		*s++;
	}
	return FileName;
}

void win2posixpath(const char *winpath, char *posixpath)
{
	strcpy (posixpath, winpath);
	win2unixpath (posixpath);
}

char *unix2winpath(char *FileName)
{
	char *s = FileName;
	while (*s) {
		if (*s == '/') {
			*s = '\\';
}
		*s++;
	}
	return FileName;
}

void posix2winpath(const char *posixpath, char *winpath)
{
	strcpy (winpath, posixpath);
	unix2winpath (winpath);
}

void posix2winfullpath (const char *posixpath, char *winpath)
{
	__realpath (posixpath, winpath);
	unix2winpath (winpath);
}

void win2posixfullpath (const char *winpath, char *posixpath)
{
	__realpath (posixpath, winpath);
	win2unixpath (posixpath);
}

char *getexecpath (char *exec_path)
{
	int res;
//	strcpy(exec_path, _pgmptr);
	res = GetModuleFileName (NULL, exec_path, MAX_PATH);
	if (!res) {
		exec_path = NULL;
		set_werrno;
	} else if (res > MAX_PATH) {
		exec_path = NULL;
		__set_errno (ENAMETOOLONG);
	}		
	win2unixpath (exec_path);
	return exec_path;
}

char *getprogname (char *prog_name)
{
	char *lastslash;

	getexecpath(prog_name);
	if ((lastslash = strrchr (prog_name, '/')) != NULL)
		prog_name = ++lastslash;
	return prog_name;
}

char *getexecdir (char *exec_dir)
{
	char *lastslash;

	getexecpath(exec_dir);
	if ((lastslash = strrchr (exec_dir, '/')) != NULL)
		*lastslash = '\0';
	return exec_dir;
}

char *getexecparent (char *exec_parent)
{
	char *lastslash;

	getexecdir (exec_parent);
	if ((lastslash = strrchr (exec_parent, '/')) != NULL)
		*lastslash = '\0';
	return exec_parent;
}

int w32_same_file(const char *filename1, const char *filename2)
{
    int res;
    char *fullname1, *fullname2;

	fullname1 = canonicalize_file_name(filename1);
	fullname2 = canonicalize_file_name(filename2);
////	fprintf(stderr, "fullname1: %s\n", fullname1);
////	fprintf(stderr, "fullname2: %s\n", fullname2);
	res = !strcasecmp(fullname1, fullname2);
	free(fullname1);
	free(fullname2);
	return res;
}

/* taken from the Perl sources */

#define STRLEN int
#define isALPHA isalpha
#define STMT_START
#define STMT_END
#define isSLASH(c) ((c) == '/' || (c) == '\\')
#define SKIP_SLASHES(s) \
    STMT_START {                   \
     while (*(s) && isSLASH(*(s)))      \
         ++(s);                    \
    } STMT_END
#define COPY_NONSLASHES(d,s) \
    STMT_START {                   \
     while (*(s) && !isSLASH(*(s)))          \
         *(d)++ = *(s)++;               \
    } STMT_END


/* Find the longname of a given path.  path is destructively modified.
 * It should have space for at least MAX_PATH characters. */
char *
win32_longpath(char *path)
{
    WIN32_FIND_DATA fdata;
    HANDLE fhand;
    char tmpbuf[MAX_PATH+1];
    char *tmpstart = tmpbuf;
    char *start = path;
    char sep;
    if (!path)
     return NULL;

    /* drive prefix */
    if (isALPHA(path[0]) && path[1] == ':') {
     start = path + 2;
     *tmpstart++ = path[0];
     *tmpstart++ = ':';
    }
    /* UNC prefix */
    else if (isSLASH(path[0]) && isSLASH(path[1])) {
     start = path + 2;
     *tmpstart++ = path[0];
     *tmpstart++ = path[1];
     SKIP_SLASHES(start);
     COPY_NONSLASHES(tmpstart,start);   /* copy machine name */
     if (*start) {
         *tmpstart++ = *start++;
         SKIP_SLASHES(start);
         COPY_NONSLASHES(tmpstart,start);    /* copy share name */
     }
    }
    *tmpstart = '\0';
    while (*start) {
     /* copy initial slash, if any */
     if (isSLASH(*start)) {
         *tmpstart++ = *start++;
         *tmpstart = '\0';
         SKIP_SLASHES(start);
     }

     /* FindFirstFile() expands "." and "..", so we need to pass
      * those through unmolested */
     if (*start == '.'
         && (!start[1] || isSLASH(start[1])
          || (start[1] == '.' && (!start[2] || isSLASH(start[2])))))
     {
         COPY_NONSLASHES(tmpstart,start);    /* copy "." or ".." */
         *tmpstart = '\0';
         continue;
     }

     /* if this is the end, bust outta here */
     if (!*start)
         break;

     /* now we're at a non-slash; walk up to next slash */
     while (*start && !isSLASH(*start))
         ++start;

     /* stop and find full name of component */
     sep = *start;
     *start = '\0';
     fhand = FindFirstFile(path,&fdata);
     *start = sep;
     if (fhand != INVALID_HANDLE_VALUE) {
         STRLEN len = strlen(fdata.cFileName);
         if ((STRLEN)(tmpbuf + sizeof(tmpbuf) - tmpstart) > len) {
          strcpy(tmpstart, fdata.cFileName);
          tmpstart += len;
          FindClose(fhand);
         }
         else {
          FindClose(fhand);
          errno = ERANGE;
          return NULL;
         }
     }
     else {
         /* failed a step, just return without side effects */
         /*PerlIO_printf(Perl_debug_log, "Failed to find %s\n", path);*/
         errno = EINVAL;
         return NULL;
     }
    }
    strcpy(path,tmpbuf);
    return path;
}

char *
getlongpath(char *longpath, const char *shortpath)
{
	HMODULE hKernel32 = GetModuleHandle("kernel32.dll");
	FARPROC pfnGetLongPathName = GetProcAddress (hKernel32, "GetLongPathName");
	
	if (pfnGetLongPathName)
		if (pfnGetLongPathName(shortpath, longpath, MAX_PATH))
			return longpath;
		else
			return NULL;
	else {
		strcpy (longpath, shortpath);
		return win32_longpath(longpath);
	}
}

char *getshortpath (char *shortpath, const char *longpath)
{

	if (GetShortPathName(longpath, shortpath, MAX_PATH))
		return shortpath;
	else
		return NULL;
}

