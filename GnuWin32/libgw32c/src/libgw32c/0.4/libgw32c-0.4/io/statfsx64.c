/* Return information about the filesystem on which FILE resides.
   Copyright (C) 1998 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#include <unistd.h>
#include <errno.h>
#include <sys/statfsx.h>
#include <sys/statvfs.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/fsinfo.h>
#include <gw32.h>
#include <windows.h>

/* Return information about the filesystem with rootdir FILE   */
/* struct statfsx is the smallest common multiple of statfs, statvfs, statfs_bsd */
int
__rstatfsx64 (const char *RootDirectory, struct statfsx64 *buf)

{
	DWORD VolumeSerialNumber, MaximumComponentLength,
		FileSystemFlags, SectorsPerCluster, BytesPerSector,
		BytesPerCluster, FreeClusters, Clusters, Attributes;
	ULARGE_INTEGER FreeBytesAvailableToCaller, TotalNumberOfBytes,
		TotalNumberOfFreeBytes;
	TCHAR VolumeName[PATH_MAX];
	TCHAR FileSystemNameBuffer[PATH_MAX];
	HINSTANCE hinst = LoadLibrary ("KERNEL32");
	FARPROC pfnGetDiskFreeSpaceEx = GetProcAddress (hinst, "GetDiskFreeSpaceEx");
	int retval = 0;
	
	if (RootDirectory == NULL ) { //|| access (RootDirectory, F_OK)) {
		buf = NULL;
		__set_errno(ENOENT);
		return -1;
	}
//	fprintf(stderr, "__rstatfsx64: RootDirectory: %s\n", RootDirectory);

	if (!GetVolumeInformation (RootDirectory, (LPTSTR) &VolumeName, PATH_MAX,
		&VolumeSerialNumber, &MaximumComponentLength, &FileSystemFlags,
		(LPTSTR) &FileSystemNameBuffer, PATH_MAX)) {
//			fprintf (stderr, "%s\n", "Cannot obtain volume information");
			set_werrno;
			return -1;
		}
/*	fprintf(stderr, "%s: %s\n", "VolumeName", VolumeName);
	fprintf(stderr, "%s: %s\n", "FileSystemNameBuffer", FileSystemNameBuffer);
	fprintf(stderr, "%s: %u\n", "VolumeSerialNumber", VolumeSerialNumber);
	fprintf(stderr, "%s: %d\n", "MaximumComponentLength", MaximumComponentLength);
*/
	if (!GetDiskFreeSpace (RootDirectory, &SectorsPerCluster, &BytesPerSector,
		&FreeClusters, &Clusters)) {
//			fprintf (stderr, "%s\n", "Cannot obtain free disk space");
			SectorsPerCluster = 1;
			BytesPerSector = 1;
			FreeClusters = 0;
			Clusters = 0;
		}
//	fprintf(stderr, "%s: %10u\n", "SectorsPerCluster", SectorsPerCluster);
//	fprintf(stderr, "%s: %10u\n", "BytesPerSector   ", BytesPerSector);
//	fprintf(stderr, "%s: %10u\n", "FreeClusters     ", FreeClusters);
//	fprintf(stderr, "%s: %10u\n", "Clusters         ", Clusters);

	if (pfnGetDiskFreeSpaceEx) {
		if (!pfnGetDiskFreeSpaceEx (RootDirectory, &FreeBytesAvailableToCaller, &TotalNumberOfBytes,
			&TotalNumberOfFreeBytes)) {
//			fprintf (stderr, "Cannot obtain free disk space ex\n");
			}
	} else {
		BytesPerCluster = SectorsPerCluster * BytesPerSector;
//		fprintf (stderr, "NoGetDiskFreeSpaceEx\n"); 
		TotalNumberOfBytes.QuadPart = Int32x32To64(Clusters, BytesPerCluster);
		TotalNumberOfFreeBytes.QuadPart = Int32x32To64(FreeClusters, BytesPerCluster);
		FreeBytesAvailableToCaller=TotalNumberOfFreeBytes;
	}
	if (hinst) 
		FreeLibrary(hinst);
//	fprintf(stderr, "%s: %20I64u      \n", "TotalNumberOfBytes        ", TotalNumberOfBytes);
//	fprintf(stderr, "%s: %20Lu %20Lu\n", "TotalNumberOfBytes        ",
//		TotalNumberOfBytes.HighPart, TotalNumberOfBytes.LowPart);
//	fprintf(stderr, "%s: %20I64u      \n", "FreeBytesAvailableToCaller", FreeBytesAvailableToCaller);
//	fprintf(stderr, "%s: %20Lu %20Lu\n", "FreeBytesAvailableToCaller",
//		FreeBytesAvailableToCaller.HighPart, FreeBytesAvailableToCaller.LowPart);
//	fprintf(stderr, "%s: %20I64u      \n", "TotalNumberOfFreeBytes    ", TotalNumberOfFreeBytes);
//	fprintf(stderr, "%s: %20Lu %20Lu\n", "TotalNumberOfFreeBytes    ",
//		TotalNumberOfFreeBytes.HighPart, TotalNumberOfFreeBytes.LowPart);
//	fflush(stderr);

	if ((Attributes = GetFileAttributes (RootDirectory)) == INVALID_FILE_ATTRIBUTES) {
		set_werrno;
		retval = -1;
/*		fprintf (stderr, "Cannot obtain file attributes\n"); */
	}
	buf->f_flag = 0;
	if (Attributes & FILE_ATTRIBUTE_READONLY){
		buf->f_flag |= ST_RDONLY;
	}

	if (!strcmp (FileSystemNameBuffer, "FAT32")){
		buf->f_type = FAT32_SUPER_MAGIC;
		buf->f_flag |= ST_NOSUID;
	}
	else if (!strcmp (FileSystemNameBuffer, "FAT")) {
		buf->f_type = FAT_SUPER_MAGIC;
		buf->f_flag |= ST_NOSUID;
	}
	else if (!strcmp (FileSystemNameBuffer, "NTFS"))
		buf->f_type = NTFS_SUPER_MAGIC;
	else if (!strcmp (FileSystemNameBuffer, "CDFS")) {
		buf->f_type = CDFS_SUPER_MAGIC;
		buf->f_flag |= ST_NOSUID;
	}
	else {
//		fprintf(stderr, "%s: %s\n", "Unknown Filesystem", FileSystemNameBuffer);
		buf->f_flag |= ST_NOSUID;
	}
//		fprintf(stderr, "Flag: %X\n", buf->f_flag);

	buf->f_bsize = BytesPerSector;
	buf->f_frsize = BytesPerSector;
	buf->f_iosize = BytesPerSector;
	buf->f_blocks = TotalNumberOfBytes.QuadPart / BytesPerSector;
	buf->f_bfree = TotalNumberOfFreeBytes.QuadPart / BytesPerSector;
	buf->f_bavail = FreeBytesAvailableToCaller.QuadPart / BytesPerSector;
	buf->f_files = buf->f_blocks / SectorsPerCluster;
	buf->f_ffree = buf->f_bfree / SectorsPerCluster;
	buf->f_favail = buf->f_bavail / SectorsPerCluster; 
	buf->f_namelen = (unsigned int) MaximumComponentLength;
	buf->f_fsid.__val[0] = HIWORD(VolumeSerialNumber);
	buf->f_fsid.__val[1] = LOWORD(VolumeSerialNumber);
	buf->f_owner = (__uid_t) -1;
//   	fprintf(stderr, "FileSystemNameBuffer: %s\n", FileSystemNameBuffer);
//   	fprintf(stderr, "RootDirectory: %s\n", RootDirectory);
    strncpy (buf->f_fstypename, FileSystemNameBuffer, MFSNAMELEN);
    strncpy (buf->f_mntonname, RootDirectory, MNAMELEN);
    strncpy (buf->f_mntfromname, RootDirectory, MNAMELEN);
//   	fprintf(stderr, "buf->f_fstypename: %s\n", buf->f_fstypename);
//   	fprintf(stderr, "buf->f_mntonname: %s\n", buf->f_mntonname);
//   	fprintf(stderr, "buf->f_mntfromname: %s\n", buf->f_mntfromname);
	return retval;
}

int
__statfsx64 (const char *file, struct statfsx64 *buf)
{
	char *RootDirectory = rootdir (file);
	int res = 0;
	
	if ((RootDirectory == NULL) ) {// || access (file, F_OK)) { // || (GetDriveType(RootDirectory) == DRIVE_REMOVABLE)) {
//   	fprintf(stderr, "__statfsx64: RootDirectory: %s\n", RootDirectory);
		buf = NULL;
		__set_errno(ENOENT);
		res = -1;
	}
	else
		res = __rstatfsx64 ((const char *) RootDirectory, buf);
	free (RootDirectory);
	return res;
}

weak_alias (__statfsx64, statfsx64)
