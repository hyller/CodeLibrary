// Adapted from http://msdn.microsoft.com/library/en-us/shellcc/platform/shell/programmersguide/shell_int/shell_int_programming/shortcuts/shortcut.asp

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <windows.h>
#include <ole2.h>
#include <shlobj.h>
#include <gw32.h>

#define prog_name "ResolveLink"

HRESULT ResolveLink(LPCSTR lpszLinkFile, LPSTR lpszPath)
{ 
    HRESULT hres; 
    IShellLink* psl; 
	IPersistFile* ppf; 
    WORD wsz[MAX_PATH]; 
	char szGotPath[MAX_PATH]; 
 
    *lpszPath = 0; // assume failure 
 		
    hres = OleInitialize (NULL);
    if (hres != S_FALSE && hres != S_OK) {
		set_werrno;
//		fprintf (stderr, "%s: Could not initialize OLE interface\n", prog_name);
		CoUninitialize();
  		return(-1);
    }

    // Get a pointer to the IShellLink interface. 
    hres = CoCreateInstance( (REFCLSID) &CLSID_ShellLink, NULL, 
            CLSCTX_INPROC_SERVER, (REFIID) &IID_IShellLink, (LPVOID *) &psl); 
    if (!SUCCEEDED(hres)) {
		set_werrno;
//	    fprintf (stderr, "%s: CoCreateInstance failed\n", prog_name);
		CoUninitialize();
  		return(-1);
    }
 
    hres = psl->lpVtbl->QueryInterface(psl, &IID_IPersistFile, (void **) &ppf );
	// Ensure that the string is Unicode. 
    hres = MultiByteToWideChar(AreFileApisANSI() ? CP_ACP : CP_OEMCP,
		0, lpszLinkFile, -1, (LPWSTR) wsz, MAX_PATH); 
	if (!SUCCEEDED (hres)) {
		set_werrno;
//		fprintf (stderr, "%s: Unicode translation failed%ld\n", prog_name, hres);
		CoUninitialize();
  	    return(-1);
    }

    // Load the shortcut. 
    hres = ppf->lpVtbl->Load(ppf, wsz, STGM_READ); 
    if (!SUCCEEDED(hres)) { 
		set_werrno;
//	    fprintf (stderr, "%s: Could not load shortcut %s\n", prog_name, lpszLinkFile);
		CoUninitialize();
  		return(-1);
	}
 
    // Resolve the link. 
//    hres = psl->lpVtbl->Resolve(psl, NULL, 0);
//			SLR_ANY_MATCH
//			| SLR_NO_UI | SLR_NOLINKINFO | SLR_NOUPDATE | SLR_NOSEARCH
//			| SLR_NOTRACK);
//    if (!SUCCEEDED(hres)) { 
//		set_werrno;
////	    fprintf (stderr, "%s: Could not resolve link %s\n", prog_name, lpszLinkFile);
//		CoUninitialize();
//  		return(-1);
//	}
 
    // Get the path to the link target. 
    hres = psl->lpVtbl->GetPath(psl, szGotPath, MAX_PATH, NULL,	0);
//		SLGP_UNCPRIORITY);
//		    SLGP_SHORTPATH); 
    if (!SUCCEEDED(hres)) { 
		set_werrno;
//	    fprintf (stderr, "%s: Could not get path to link target %s\n", prog_name, lpszLinkFile);
		CoUninitialize();
  		return(-1);
	}

	lstrcpy(lpszPath, szGotPath); 

	// Release the pointer to the IPersistFile interface. 
    ppf->lpVtbl->Release(ppf); 
    // Release the pointer to the IShellLink interface. 
    psl->lpVtbl->Release(psl); 
	CoUninitialize();
  
    return hres; 
} 

int readlink(const char *path, char *buf, size_t bufsize)
{
	HRESULT res;
	char linkname [bufsize+5];
#   define LNKEXT ".lnk"
	
	strcpy(linkname, path);
	if (!strstr(path, LNKEXT))
		strcat(linkname, LNKEXT);
	SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX);
	res = ResolveLink ((LPCSTR) linkname, (LPSTR) buf);
	SetErrorMode(0);
	win2unixpath (buf);
	if (res == -1)
		return (int) res;
	else
		return strlen(buf);
}

#ifdef TEST
int
main (int argc, char **argv)
{
	int res;
	char dest[MAX_PATH];

	fprintf(stderr, "Prog:  %s\n", argv[0]);
	fprintf(stderr, "src:  %s\n", argv[1]);
	res = readlink (argv[1], dest, MAX_PATH);
	fprintf(stderr, "dest: %s\n", dest);
	fprintf(stderr, "res:  %d\n", res);
	return res;
}
#endif /* TEST */
