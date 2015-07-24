/* ************************************
*����ͨWindows API��
* ʾ������
* pro_s1.c
* 4.4.2  ͨ��Mapping File�ڽ��̼乲���ڴ�
**************************************/
/* ͷ�ļ���*/
#include <windows.h>
#include <stdio.h>
#include <conio.h>
/* Ԥ����������*/
#define BUF_SIZE 256
/* ȫ�ֱ�����*/
LPTSTR szName = TEXT("SharedFileMappingObject");
LPTSTR szMsg = TEXT("���̵���Ϣ");

/* ************************************
* int main(void)
* ����	��ʾ�ļ�mapping�����ڴ棬д�����ݵ������ڴ�
*
* ����	��
*
* ����ֵ	0����ִ����ɣ�������������
**************************************/
void main(int argc, PCHAR argv[])
{
	//�ļ�ӳ����
	HANDLE hMapFile;
	//�������ݻ�����ָ��
	LPTSTR pBuf;
	//�����������ļ�ӳ�䣬����������Ӳ���ϵ��ļ�
	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL, 
		PAGE_READWRITE,
		0,
		BUF_SIZE, 
		szName);
	if (hMapFile == NULL || hMapFile == INVALID_HANDLE_VALUE) 
	{ 
		printf("CreateFileMapping error: %d\n",	GetLastError());
		return;
	}
	//����View
	pBuf = (LPTSTR) MapViewOfFile(hMapFile,
		FILE_MAP_ALL_ACCESS,
		0,                   
		0,                   
		BUF_SIZE);
	if (pBuf == NULL) 
	{ 
		printf("MapViewOfFile error %d\n", 	GetLastError()); 
		return;
	}
	//���������ݸ��Ƶ��ļ�ӳ���У��������ʱ�����˲�����ʹ�ò���
	if(argc==1)
	{
		CopyMemory((PVOID)pBuf, szMsg, strlen(szMsg));
	}
	else
	{
		DWORD dwCopyLen = (lstrlen(argv[1])<BUF_SIZE) ? lstrlen(argv[1]): BUF_SIZE;
		CopyMemory((PVOID)pBuf, argv[1], dwCopyLen);
	}
	printf("���г���������к󣬰�������˳���");
	_getch();
	//ȡ��ӳ�䣬�˳�
	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);
}