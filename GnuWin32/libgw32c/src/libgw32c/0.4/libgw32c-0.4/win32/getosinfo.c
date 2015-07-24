/*
Platform SDK: Windows System Information 

Adapted from:
http://msdn.microsoft.com/library/en-us/sysinfo/base/getting_the_system_version.asp
http://www.codeproject.com/system/winvertable.asp

Getting the System Version

The following example uses the GetVersionEx function to display the
version of the currently running operating system. 

Relying on version information is not the best way to test for a feature.
Instead, refer to the documentation for the feature of interest.
For more information on common techniques for feature detection, see
Operating System Version. 

If you must require a particular operating system, be sure to use it
as a minimum supported version, rather than design the test for the
one operating system. This way, your detection code will continue to
work on future versions of Windows. 
*/


#include <windows.h>
#include <stdio.h>
#include <gw32.h>

#define BUFSIZE 255

static int __ISWINNT = -1, __ISWIN9X = -1, __ISWIN31 = -1, __ISWINCE = -1;

BOOL GetOsInfo(LPSTR OsName, LPSTR Release, LPSTR Version)
{
   OSVERSIONINFOEX osvi;
   BOOL bOsVersionInfoEx;
   DWORD BuildNumber;

   // Try calling GetVersionEx using the OSVERSIONINFOEX structure.
   // If that fails, try using the OSVERSIONINFO structure.

   ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
   osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

   if( !(bOsVersionInfoEx = GetVersionEx ((LPOSVERSIONINFO) &osvi)) ) {
      // If OSVERSIONINFOEX doesn't work, try OSVERSIONINFO.
      osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
      if (! GetVersionEx ( (LPOSVERSIONINFO) &osvi) ) 
         return FALSE;
   }

   BuildNumber = osvi.dwBuildNumber & 0xFFFF;
   switch (osvi.dwPlatformId) {
      // Tests for Windows NT product family.
      case VER_PLATFORM_WIN32_NT:
      // Test for the product.
		 __ISWINNT = 1;
		 __ISWIN9X = 0;
		 __ISWIN31 = 0;
		 __ISWINCE = 0;
		 if ( osvi.dwMajorVersion == 3 && osvi.dwMinorVersion == 51 ) 
            strcpy(OsName, "Microsoft Windows NT 3.51");
		 else if ( osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 0 ) 
            strcpy(OsName, "Microsoft Windows NT 4.0");
		 else if ( osvi.dwMajorVersion <= 4 && osvi.dwMinorVersion == 0 ) 
            strcpy(OsName, "Microsoft Windows NT");
		 else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 )
            strcpy(OsName, "Microsoft Windows Server&nbsp;2003 family, ");
         else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1 )
            strcpy(OsName, "Microsoft Windows XP");
		 else if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0 )
            strcpy(OsName, "Microsoft Windows 2000");


         if( bOsVersionInfoEx ) { // Use information from GetVersionEx.
         // Test for the workstation type.
            if ( osvi.wProductType == VER_NT_WORKSTATION ) {
               if( osvi.wSuiteMask & VER_SUITE_PERSONAL )
                  strcat(OsName,  " Home Edition" );
               else
                  strcat(OsName,  " Professional" );
            }
         // Test for the server type.
            else if ( osvi.wProductType == VER_NT_SERVER) {
				if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2) {
				   if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
        	          strcat(OsName,  " Datacenter Edition" );
            	   else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
                	  if( osvi.dwMajorVersion == 4 )
                    	 strcat(OsName, " Advanced Server" );
	                  else
    	                 strcat(OsName,  " Enterprise Edition" );
        	       else if ( osvi.wSuiteMask == VER_SUITE_BLADE )
            	      strcat(OsName,  " Web Edition" );
	               else
    	              strcat(OsName,  " Standard Edition" );
        	    }
	         else if( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0 )  {
                  if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
                     strcat(OsName, " Datacenter Server" );
                  else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
                     strcat(OsName, " Advanced Server" );
                  else
                     strcat(OsName, " Server" );
               }
             else  // Windows NT 4.0 {
                  if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
                     printf ("Server 4.0, Enterprise Edition " );
                  else
                     printf ( "Server 4.0 " );
               }
		 }
		 else  { // Use the registry on early versions of Windows NT.
            HKEY hKey;
            char szProductType[BUFSIZE];
            DWORD dwBufLen=BUFSIZE;
            LONG lRet;

            lRet = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
               "SYSTEM\\CurrentControlSet\\Control\\ProductOptions",
               0, KEY_QUERY_VALUE, &hKey );
            if( lRet != ERROR_SUCCESS )
                return FALSE;

            lRet = RegQueryValueEx( hKey, "ProductType", NULL, NULL,
               (LPBYTE) szProductType, &dwBufLen);
            if( (lRet != ERROR_SUCCESS) || (dwBufLen > BUFSIZE) )
                return FALSE;

            RegCloseKey( hKey );

            if ( lstrcmpi( "WINNT", szProductType) == 0 )
               strcat(OsName,  " Professional" );
            if ( lstrcmpi( "LANMANNT", szProductType) == 0 )
               strcat(OsName,  " Server" );
            if ( lstrcmpi( "SERVERNT", szProductType) == 0 )
               strcat(OsName,  " Advanced Server" );
         }
	  // Display version, service pack (if any), and build number.
			 strcat (OsName, " ");
			 strcat (OsName, osvi.szCSDVersion);
         break;
      // Test for the Windows 95 product family.
      case VER_PLATFORM_WIN32_WINDOWS:
 		 __ISWINNT = 0;
		 __ISWIN9X = 1;
		 __ISWIN31 = 0;
		 __ISWINCE = 0;

		 if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 0) {
             strcpy(OsName, "Microsoft Windows 95");
             if (BuildNumber > 950 && BuildNumber <= 1080)
			 	strcat(OsName, " SP1");
             else if (BuildNumber > 1080)
			 	strcat(OsName, " OSR2");
/*
			 if ( osvi.szCSDVersion[1] == 'C' || osvi.szCSDVersion[1] == 'B' )
                strcat(OsName, "OSR2 " );
*/
		 } 

         if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 10) {
             strcpy(OsName, "Microsoft Windows 98");
             if (BuildNumber > 1998 && BuildNumber < 2183)
			 	strcat(OsName, " SP1");
             else if (BuildNumber >= 2183)
			 	strcat(OsName, " SE");
/*
             if ( osvi.szCSDVersion[1] == 'A' )
                strcat(OsName, "SE " );
*/
		 } 

         if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 90) {
             strcpy(OsName, "Microsoft Windows Millennium Edition ");
         } 
		 break;
      case VER_PLATFORM_WIN32s:
 		 __ISWINNT = 0;
		 __ISWIN9X = 1;
		 __ISWIN31 = 0;
		 __ISWINCE = 0;
         strcpy(OsName, "Microsoft Windows 3.1 with Win32s ");
		break;
	  case VER_PLATFORM_WIN32_CE:
 		 __ISWINNT = 0;
		 __ISWIN9X = 0;
		 __ISWIN31 = 0;
		 __ISWINCE = 1;
         strcpy(OsName, "Microsoft Windows CE ");
		 break;	  	
   }
	sprintf(Release, "%lu.%lu.%lu", osvi.dwPlatformId,
	   osvi.dwMajorVersion,
       osvi.dwMinorVersion);
	sprintf(Version, "%lu",
       osvi.dwBuildNumber & 0xFFFF);
   return TRUE; 
}
#define HIBITDW(dw)   ((BYTE)((dw)>>31) & 0x1)

int winplatform ()
{
	OSVERSIONINFO osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if (! GetVersionEx ( (LPOSVERSIONINFO) &osvi) ) 
		return 0;
	return osvi.dwPlatformId;
}

int
winmajor()
{
	return  (int)(LOBYTE(LOWORD(GetVersion())));
}

int
winminor()
{
	return  (int)(HIBYTE(LOWORD(GetVersion())));
}

int
winos()
{
	return  (int)(HIWORD(GetVersion()));
}

int
IsWinNT(void)
{
	if (__ISWINNT < 0)
		return winplatform () == VER_PLATFORM_WIN32_NT;
	return __ISWINNT > 0;
}

int
IsWin9x(void)
{
	if (__ISWIN9X < 0)
		return winplatform () == VER_PLATFORM_WIN32_WINDOWS;
	return __ISWIN9X > 0;
}

int
IsWin31(void)
{
	if (__ISWIN31 < 0)
		return winplatform () == VER_PLATFORM_WIN32s;
	return __ISWIN31 > 0;
}

int
IsWinCE(void)
{
	if (__ISWINCE < 0) {
		return winplatform () == VER_PLATFORM_WIN32_CE;
	}
	return __ISWINCE > 0;
}
