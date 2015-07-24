// CreateLink - uses the shell's IShellLink and IPersistFile interfaces  
//   to create and store a shortcut to the specified object. 
// Returns the result of calling the member functions of the interfaces. 
// lpszPathObj - address of a buffer containing the path of the object 
// lpszPathLink - address of a buffer containing the path where the 
//   shell link is to be stored 
// lpszDesc - address of a buffer containing the description of the 
//   shell link 
// Adapted from http://msdn.microsoft.com/library/en-us/shellcc/platform/shell/programmersguide/shell_int/shell_int_programming/shortcuts/shortcut.asp


#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <windows.h>
#include <ole2.h>
#include <shlobj.h>
#include <gw32.h>

#define prog_name "CreateLink"

HRESULT CreateLink(LPCSTR lpszPathObj, 
    LPSTR lpszPathLink, LPSTR lpszDesc) 
{ 
    HRESULT hres; 
    IShellLink* psl; 
	IPersistFile* ppf; 
    WORD wsz[MAX_PATH]; 
	char *ObjWorkingDir;
	char *tmp;
	
#ifdef TEST
	fprintf(stderr, "CreateLink\n");
	fprintf(stderr, "     lpszPathObj: %s\n", lpszPathObj);
	fprintf(stderr, "     lpszPathLink: %s\n", lpszPathLink);
	fprintf(stderr, "     lpszDesc: %s\n", lpszDesc);
#endif

	hres = OleInitialize (NULL);
    if (hres != S_FALSE && hres != S_OK) {
		set_werrno;
//		fprintf (stderr, "%s: Could not initialize OLE interface\n", prog_name);
		CoUninitialize();
        return (-1);

    }

    // Get a pointer to the IShellLink interface. 
    hres = CoCreateInstance(&CLSID_ShellLink, NULL, 
        CLSCTX_INPROC_SERVER, &IID_IShellLink,(LPVOID *) &psl); 
    if (!SUCCEEDED(hres)) {
		set_werrno;
//		fprintf (stderr, "%s: CoCreateInstance failed\n", prog_name);
		CoUninitialize();
        return (-1);
    }
 
  // Set the path to the shortcut target, and add the 
    // description. 
    psl->lpVtbl->SetPath(psl, lpszPathObj); 
    psl->lpVtbl->SetDescription(psl, lpszDesc); 
	ObjWorkingDir = strdup(lpszPathObj);
#ifdef TEST
	fprintf(stderr, "     ObjWDir:  %s\n", ObjWorkingDir);
#endif
	if (ObjWorkingDir) {
		tmp = strrchr(ObjWorkingDir, '\\');
		tmp[0] = '\0';
#ifdef TEST
		fprintf(stderr, "     ObjWDir:  %s\n", ObjWorkingDir);
#endif
		psl->lpVtbl->SetWorkingDirectory (psl, ObjWorkingDir);
	}
 
    // Query IShellLink for the IPersistFile interface for saving the 
    // shortcut in persistent storage. 
    hres = psl->lpVtbl->QueryInterface(psl, &IID_IPersistFile, (void **) &ppf); 
    if (!SUCCEEDED(hres)) { 
		set_werrno;
//	    fprintf (stderr, "%s: QueryInterface failed\n", prog_name);
		CoUninitialize();
        return (-1);
	}
 
    // Ensure that the string is ANSI. 
    hres = MultiByteToWideChar(
		 AreFileApisANSI() ? CP_ACP : CP_OEMCP,	0, lpszPathLink, -1, wsz, MAX_PATH);
	if (!SUCCEEDED (hres)) {
		set_werrno;
//		fprintf (stderr, "%s: Unicode translation failed%ld\n", prog_name, hres);
		CoUninitialize();
        return (-1);
    }

	// Save the link by calling IPersistFile::Save. 
    hres = ppf->lpVtbl->Save(ppf, wsz, TRUE); 
    ppf->lpVtbl->Release(ppf); 
    psl->lpVtbl->Release(psl); 
	CoUninitialize();
    return hres; 
} 

int symlink(const char *src, const char *dest)
{
	HRESULT res;
	char fullsrc[MAX_PATH];
	char fulldst[MAX_PATH];
	char *fs, *fd;
#ifdef TEST
	fprintf(stderr, "symlink\n");
	fprintf(stderr, "     src:  %s\n", src);
	fprintf(stderr, "     dest: %s\n", dest);
#endif
	fs = unix2winpath (getfullpath(src, fullsrc));
//	fs = strcpy(fullsrc, src);
#ifdef TEST
	fprintf(stderr, "symlink 2\n");
	fprintf(stderr, "     dest: %s\n", dest);
//	fprintf(stderr, "     fd: %s\n", fd);
	fprintf(stderr, "     fullsrc: %s\n", fullsrc);
	fprintf(stderr, "     fs: %s\n", fs);
#endif
	fd = unix2winpath (getfullpath (dest, fulldst));
//	fd = strcpy(fulldst, dest);
	strcat (fulldst, ".lnk");
#ifdef TEST
	fprintf(stderr, "symlink 3\n");
	fprintf(stderr, "     fulldst: %s\n", fulldst);
#endif

	res = CreateLink ((LPCSTR) fullsrc, (LPSTR) fulldst, (LPSTR) fullsrc);
#ifdef TEST
	fprintf(stderr, "symlink 4\n");
	fprintf(stderr, "     res: %ld\n", res);
#endif
	return (int) res;
}

#ifdef TEST
HRESULT
main (int argc, char **argv)
{
	int res;
	char src [MAX_PATH];
	char dest [MAX_PATH];
	
	fprintf(stderr, "readlink");
	strcpy(src, argv[1]);
	strcpy(dest, argv[2]);
	fprintf(stderr, "     src:  %s\n", src);
	fprintf(stderr, "     dest: %s\n", dest);
	res = symlink (src, dest);
	fprintf(stderr, "main 2");
	fprintf(stderr, "     res:  %d\n", res);
	return res;
}
#endif /* TEST */
