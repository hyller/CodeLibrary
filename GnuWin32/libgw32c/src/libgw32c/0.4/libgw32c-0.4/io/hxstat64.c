/* Copyright (C) 1991, 1995, 1996, 1997, 2002 Free Software Foundation, Inc.
	 This file is part of the GNU C Library.

	 The GNU C Library is free software; you can redistribute it and/or
	 modify it under the terms of the GNU Lesser General Public
	 License as published by the Free Software Foundation; either
	 version 2.1 of the License, or (at your option) any later version.

	 The GNU C Library is distributed in the hope that it will be useful,
	 but WITHOUT ANY WARRANTY; without even the implied warranty of
	 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the GNU
	 Lesser General Public License for more details.

	 You should have received a copy of the GNU Lesser General Public
	 License along with the GNU C Library; if not, write to the Free
	 Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
	 02111-1307 USA.	*/

#include <errno.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>
#include <direct.h>
#include <stdio.h>
#include <windows.h>
#include <gw32.h>

DWORD
GetVolumeSerialNumber (LPCTSTR FileName)
{
	DWORD VolumeSerialNumber, MaximumComponentLength,
		FileSystemFlags;
	TCHAR VolumeName[PATH_MAX], FileSystemNameBuffer[PATH_MAX];
	char *RootDirectory = unix2winpath(rootdir (FileName));
	
//	printf("RootDirectory: %s\n", RootDirectory);
	if (!GetVolumeInformation(RootDirectory, (LPTSTR) &VolumeName, PATH_MAX,
			&VolumeSerialNumber, &MaximumComponentLength, &FileSystemFlags,
			(LPTSTR) &FileSystemNameBuffer, PATH_MAX))
		VolumeSerialNumber = 0;
	free (RootDirectory);
	return VolumeSerialNumber;
}
	
/* Defines the so called `hashpjw' function by P.J. Weinberger
	 [see Aho/Sethi/Ullman, COMPILERS: Principles, Techniques and Tools,
	 1986, 1987 Bell Telephone Laboratories, Inc.]	*/
#define HASHWORDBITS 64
#define THREE_QUARTERS	((int) ((HASHWORDBITS * 3) / 4))
#define ONE_EIGHTH			((int) (HASHWORDBITS / 8))
#define HIGH_BITS			 ( ~((unsigned long long)(~0) >> ONE_EIGHTH ))
unsigned long long hashval ( const char * str )
{
	unsigned long long hash_value = 0, i;
	if (!str || str[0] == 0)
		return 0;
	for ( hash_value = 0; *str; ++str ) {
		hash_value = ( hash_value << ONE_EIGHTH ) + *str;
		if (( i = hash_value & HIGH_BITS ) != 0 )
				hash_value = ( hash_value ^ ( i >> THREE_QUARTERS ))
						& ~HIGH_BITS;
	}
	return ( hash_value );
}

int
issymlink (const char *path)
{
	char *ext;
	if (path && (ext = strrchr (path, '.')) )
		return !strcmp (ext, ".lnk");
	else
		return 0;
}
	
int handle2mode (const HANDLE hf)
{
	DWORD ft = GetFileType (hf);
	mode_t fmode = 0;

	if (ft == FILE_TYPE_CHAR)
		fmode |= S_IFCHR;
	else if (ft == FILE_TYPE_PIPE)
		fmode |= S_IFIFO;
	return fmode;
}

int attr2mode (const DWORD attr)
{
	mode_t fmode = 0;
	
	if (attr & FILE_ATTRIBUTE_DIRECTORY)
		 fmode |= S_IFDIR;
	else
		 fmode |= S_IFREG;
	fmode |= S_IRUSR | S_IRGRP | S_IROTH;
	if (!(attr & FILE_ATTRIBUTE_READONLY))
		 fmode |= S_IWUSR | S_IWGRP | S_IWOTH;
	return fmode;
}

int path2mode (const char *path)
{
	mode_t fmode = 0;
	DWORD bintype;

	if (path && GetBinaryType(path, &bintype))
		 fmode |= S_IXUSR | S_IXGRP | S_IXOTH;
	if (issymlink (path))	{
//	fprintf(stderr, "hxstat64: ISLNK: %s\n", path);
		fmode &= ~S_IFREG;
		fmode |= S_IFLNK;
	}
	return fmode;
}

BOOL
GetFileAttributeData (LPCTSTR FileName, WIN32_FILE_ATTRIBUTE_DATA *lpFileAttributeData)
{
#ifdef UNICODE
# define GETFILEATTRIBUTESEX "GetFileAttributesExW"
#else
# define GETFILEATTRIBUTESEX "GetFileAttributesExA"
#endif
	HMODULE hKernel32 = GetModuleHandle ("kernel32.dll");
	FARPROC pfnGetFileAttributesEx = GetProcAddress (hKernel32, GETFILEATTRIBUTESEX); 
	DWORD attr;
	BOOL res = TRUE;
	WIN32_FIND_DATA FindFileData;
	
	attr = GetFileAttributes (FileName);
	if (attr == INVALID_FILE_ATTRIBUTES)
		return FALSE;
	ZeroMemory (&FindFileData, sizeof (FindFileData));
	if (pfnGetFileAttributesEx) {
		res = pfnGetFileAttributesEx (FileName, GetFileExInfoStandard, lpFileAttributeData);
	}
	else {
		res = FALSE;
	}
	if (res == FALSE) {
		res = (FindFirstFile (FileName, &FindFileData) != INVALID_HANDLE_VALUE);
		lpFileAttributeData->dwFileAttributes = FindFileData.dwFileAttributes;
		lpFileAttributeData->ftCreationTime = FindFileData.ftCreationTime;
		lpFileAttributeData->ftLastAccessTime = FindFileData.ftLastAccessTime;
		lpFileAttributeData->ftLastWriteTime = FindFileData.ftLastWriteTime;
		lpFileAttributeData->nFileSizeHigh = FindFileData.nFileSizeHigh;
		lpFileAttributeData->nFileSizeLow = FindFileData.nFileSizeLow;
	}
	if (res == FALSE) {
		ZeroMemory (lpFileAttributeData, sizeof (WIN32_FILE_ATTRIBUTE_DATA));
		lpFileAttributeData->dwFileAttributes = attr;
	}
	return TRUE;
}

BOOL
GetFileInformationByName (LPCTSTR FileName, BY_HANDLE_FILE_INFORMATION *lpFileInformation)
{
	WIN32_FILE_ATTRIBUTE_DATA FileAttributeData;
	
	if (!GetFileAttributeData (FileName, &FileAttributeData))
		return FALSE;
	lpFileInformation->dwFileAttributes = FileAttributeData.dwFileAttributes;
	lpFileInformation->ftCreationTime = FileAttributeData.ftCreationTime;
	lpFileInformation->ftLastAccessTime = FileAttributeData.ftLastAccessTime;
	lpFileInformation->ftLastWriteTime = FileAttributeData.ftLastWriteTime;
	lpFileInformation->nFileSizeHigh = FileAttributeData.nFileSizeHigh;
	lpFileInformation->nFileSizeLow = FileAttributeData.nFileSizeLow;
	lpFileInformation->nNumberOfLinks = 1;
	lpFileInformation->dwVolumeSerialNumber = GetVolumeSerialNumber (FileName);
	return TRUE;
}

int
FileInformationToStat64 (BY_HANDLE_FILE_INFORMATION FileInformation, struct stat64 *stat_buf)
{
	stat_buf->st_ino = (__ino64_t) MAKEDWORDLONG (
			FileInformation.nFileIndexLow, FileInformation.nFileIndexHigh);
	stat_buf->st_dev = FileInformation.dwVolumeSerialNumber;
	stat_buf->st_mode |= attr2mode (FileInformation.dwFileAttributes);	
	stat_buf->st_size = (__off64_t) (MAKEDWORDLONG (
			FileInformation.nFileSizeLow, FileInformation.nFileSizeHigh));
	stat_buf->st_nlink = FileInformation.nNumberOfLinks;
	stat_buf->st_atime = FILETIME_TO_TIME(FileInformation.ftLastAccessTime);
	stat_buf->st_ctime = FILETIME_TO_TIME(FileInformation.ftCreationTime);
	stat_buf->st_mtime = FILETIME_TO_TIME(FileInformation.ftLastWriteTime);
	return 1;
}

BOOL GetStat64ByHandle (const HANDLE hf, struct stat64 *stat_buf)
{
	BY_HANDLE_FILE_INFORMATION FileInformation;
	DWORD TotalBytesAvail;
	
	ZeroMemory (&FileInformation, sizeof(FileInformation));
	if (hf == INVALID_HANDLE_VALUE)
		return -1;
	stat_buf->st_nlink = 1;
	stat_buf->st_mode = handle2mode (hf);
	if (S_ISFIFO (stat_buf->st_mode)) {
		if (PeekNamedPipe (hf, NULL, 0, NULL, &TotalBytesAvail, NULL)) {
			FileInformation.nFileSizeLow = LODWORD (TotalBytesAvail);
			FileInformation.nFileSizeHigh = HIDWORD (TotalBytesAvail);
		}
	}
	else if (S_ISCHR (stat_buf->st_mode)) {
		FileInformation.nFileSizeLow = LODWORD(1LL);
		FileInformation.nFileSizeHigh = HIDWORD(1LL);
	}
	else if (!GetFileInformationByHandle (hf, &FileInformation))
		return -1;
	FileInformationToStat64 (FileInformation, stat_buf);
	return 0;
}

BOOL
GetXStat64ByName (const char *FileName, struct stat64 *stat_buf)
{
	int lenrootdir;
	char *prootdir, *path = canonicalize_file_name(FileName);

	prootdir = rootdir (path);
	lenrootdir = strlen (prootdir);
//	if (!stat_buf->st_ino || GetFileType (hf) != FILE_TYPE_DISK) {
	if (!stat_buf->st_ino || GetDriveType (prootdir) == DRIVE_REMOTE) {
//	if (!stat_buf->st_ino) {
		if (stricmp (path, prootdir) == 0)
			stat_buf->st_ino = 0X5000000000005;
		else 
			stat_buf->st_ino = (__ino64_t) hashval (path + lenrootdir);
	}
	if (!stat_buf->st_dev)
		stat_buf->st_dev = (__dev_t) hashval (prootdir);
	stat_buf->st_mode |= path2mode (path);
	return 0;
}

BOOL GetStat64ByName (const char *FileName, struct stat64 *stat_buf)
{
	char *path = canonicalize_file_name(FileName);
	BY_HANDLE_FILE_INFORMATION FileInformation;
	
	ZeroMemory (&FileInformation, sizeof(FileInformation));
	if (!GetFileInformationByName (path, &FileInformation))
		return -1;
	FileInformationToStat64 (FileInformation, stat_buf);
	GetXStat64ByName (path, stat_buf);
	free (path);
	return 0;
}

int __cxstat64 (const char *__filename, struct stat64 *__stat_buf)
{
	int res = -1;
	HANDLE hFile;

	ZeroMemory (__stat_buf, sizeof (*__stat_buf));
	if (!__filename || !*__filename)
		return 0;
	if (access (__filename, F_OK))
		return -1;
	hFile = CreateFile (__filename, 0, 0, NULL,
		OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_ATTRIBUTE_READONLY, NULL);
	res = GetStat64ByHandle (hFile, __stat_buf);
	CloseHandle (hFile);
	if (res == -1)
		res = GetStat64ByName (__filename, __stat_buf);
	else
		GetXStat64ByName (__filename, __stat_buf);
	if (res == -1)
		set_werrno;
	SetErrorMode(0);
	return res;
}
