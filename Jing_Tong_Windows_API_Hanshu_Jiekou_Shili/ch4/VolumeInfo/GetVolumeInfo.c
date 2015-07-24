/* ************************************
 *����ͨWindows API�� 
 * ʾ������
 * GetVolumeInfo.c
 * 4.2.1	��������������ȡ����������
 **************************************/

/* ͷ�ļ���*/
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
/* Ԥ���塡*/
#define BUFSIZE 1024
/* ����������*/
BOOL GetDirverInfo(LPSTR szDrive);

/* ************************************
 * ����	Ӧ�ó���������������������������
 *			GetDirverInfo ��ȡ����������
 **************************************/
void main(void)
{
	CHAR szLogicalDriveStrings[BUFSIZE];
	PCHAR szDrive;

	ZeroMemory(szLogicalDriveStrings,BUFSIZE);
	// ��ȡ�߼�������������
	GetLogicalDriveStrings(BUFSIZE - 1,szLogicalDriveStrings);	
	szDrive = (PCHAR)szLogicalDriveStrings;
	// ѭ������ÿ����
	do
	{
		if(!GetDirverInfo(szDrive))
		{
			printf("\nGet Volume Information Error: %d", GetLastError());
		}
		szDrive += (lstrlen(szDrive)+1);
	}
	while(*szDrive!='\x00');
}

/* ************************************
 * BOOL GetDirverInfo(LPSTR szDrive)
 * ����	��ȡ������������
 * ����	LPSTR szDrive
 * 	ָ��Ҫ��ȡ���Ե��������ĸ�·�� �� C:\
 * ����ֵ BOOL �Ƿ�ɹ�
 **************************************/
BOOL GetDirverInfo(LPSTR szDrive)
{
	UINT uDriveType;
	DWORD dwVolumeSerialNumber;
	DWORD dwMaximumComponentLength;
	DWORD dwFileSystemFlags;
	TCHAR szFileSystemNameBuffer[BUFSIZE];
	printf("\n%s\n",szDrive);
	uDriveType = GetDriveType(szDrive);
	// �ж�����
	switch(uDriveType)
	{
	case DRIVE_UNKNOWN:
		printf("The drive type cannot be determined. ");
		break;
	case DRIVE_NO_ROOT_DIR:
		printf("The root path is invalid, for example, no volume is mounted at the path. ");
		break;
	case DRIVE_REMOVABLE:
		printf("The drive is a type that has removable media, for example, a floppy drive or removable hard disk. ");
		break;
	case DRIVE_FIXED:
		printf("The drive is a type that cannot be removed, for example, a fixed hard drive. ");
		break;
	case DRIVE_REMOTE:
		printf("The drive is a remote (network) drive. ");
		break;
	case DRIVE_CDROM:
		printf("The drive is a CD-ROM drive. ");
		break;
	case DRIVE_RAMDISK:
		printf("The drive is a RAM disk. ");
		break;
	default:
		break;
	}
	if (!GetVolumeInformation(
		szDrive, NULL, 0,
		&dwVolumeSerialNumber,
		&dwMaximumComponentLength,
		&dwFileSystemFlags,
		szFileSystemNameBuffer,
		BUFSIZE
		))
	{
		return FALSE;
	}
	printf ("\nVolume Serial Number is %u",dwVolumeSerialNumber);
	printf ("\nMaximum Component Length is %u",dwMaximumComponentLength);
	printf ("\nSystem Type is %s\n",szFileSystemNameBuffer);

	if(dwFileSystemFlags & FILE_SUPPORTS_REPARSE_POINTS)
	{
		printf ("The file system does not support volume mount points.\n");
	}
	if(dwFileSystemFlags & FILE_VOLUME_QUOTAS)
	{
		printf ("The file system supports disk quotas.\n");
	}
	if(dwFileSystemFlags & FILE_CASE_SENSITIVE_SEARCH)
	{
		printf ("The file system supports case-sensitive file names.\n");
	}
	//you can use these value to get more informaion
	//
	//FILE_CASE_PRESERVED_NAMES
	//FILE_CASE_SENSITIVE_SEARCH
	//FILE_FILE_COMPRESSION
	//FILE_NAMED_STREAMS
	//FILE_PERSISTENT_ACLS
	//FILE_READ_ONLY_VOLUME
	//FILE_SUPPORTS_ENCRYPTION
	//FILE_SUPPORTS_OBJECT_IDS
	//FILE_SUPPORTS_REPARSE_POINTS
	//FILE_SUPPORTS_SPARSE_FILES
	//FILE_UNICODE_ON_DISK
	//FILE_VOLUME_IS_COMPRESSED
	//FILE_VOLUME_QUOTAS
	printf("...\n");
	return TRUE;
}