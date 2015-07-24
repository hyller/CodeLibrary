/* ************************************
*����ͨWindows API�� 
* ʾ������
* child.c
* 6.2.1  �������̡���ȡ���������Ϣ����ȡ��������
**************************************/
/* ͷ�ļ���*/
#include <windows.h>
#include <stdio.h>
/* �궨�塡*/
#define MyAlloc(size) HeapAlloc(GetProcessHeap(),0,size)
#define MyFree(lpMem) HeapFree(GetProcessHeap(),0,lpMem)
/* �ṹ�嶨�塡*/
typedef struct _PROCESS_INFO
{
	DWORD dwPid;
	HANDLE hProcess;
	DWORD dwPrioClass;
	DWORD dwHandleCount;
	DWORD dwAffinityMask;
	SIZE_T dwWorkingSetSizeMax;
	SIZE_T dwWorkingSetSizeMin;
	LPWSTR szwCommandLine;
	STARTUPINFO sti;
}PROCESS_INFO, *LPPROCESS_INFO;
/* ȫ�ֱ�����*/
HANDLE hMySelf;
/* ����������*/
DWORD GetProcessInfo(LPPROCESS_INFO lppi);

/*************************************
* int WinMain(
	HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
* ����	��ʾ��ȡ������Ϣ���ڽ����л�ȡ�����в�����
*
**************************************/
int WinMain(
	HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
	PROCESS_INFO pi;
	INT argc;
	WCHAR **argv;
	DWORD i;
	DWORD dwBufferSize = lstrlen(lpCmdLine)+MAX_PATH+1024;
	LPSTR szShowBuffer = (LPSTR)MyAlloc(dwBufferSize);

	hMySelf = hInstance;
	// ��ʾֱ�Ӵ�WinMain���������õ�����Ϣ
	wsprintf(szShowBuffer,
		"��������\nʵ�������%.8X�������в�����%s����ʾѡ�%.8X",
		hInstance,lpCmdLine,nCmdShow);
	MessageBox(NULL,szShowBuffer,"WinMain��������",MB_OK);
	// ʹ���Զ���ĺ�����ȡ�����Ϣ
	GetProcessInfo(&pi);
	// �������в�������
	argv = CommandLineToArgvW(pi.szwCommandLine,&argc);
	// �ַ�����������ʾ
	*szShowBuffer = '\x00';	
	for(i=0; i<argc; i++)
	{
		DWORD dwBufferSize = lstrlenW(*argv)+1;
		LPSTR szMBArgv = MyAlloc(dwBufferSize);
		WideCharToMultiByte(CP_ACP,0,*argv,-1,szMBArgv,dwBufferSize,NULL,NULL);
		argv++;
		lstrcat(szShowBuffer,"\n");
		lstrcat(szShowBuffer,szMBArgv);
		MyFree(szMBArgv);
	}
	MessageBox(NULL,szShowBuffer,"����",MB_OK);
	MyFree(szShowBuffer);
	// ��ӡ������Ϣ TODO
	return 0;
}
/*************************************
* DWORD GetProcessInfo(LPPROCESS_INFO lppi)
* ����	��ȡ���������Ϣ��������PROCESS_INFO�ṹ��
*
* ����	LPPROCESS_INFO lppi	���ڱ��������Ϣ
**************************************/
DWORD GetProcessInfo(LPPROCESS_INFO lppi)
{
	// PID
	lppi->dwPid = GetCurrentProcessId();
	// ���
	lppi->hProcess = GetCurrentProcess();
	// ���ȼ�
	lppi->dwPrioClass = GetPriorityClass(hMySelf);
	// �������
	//windows xp sp1 sdk ������API GetProcessHandleCount
	//lppi->dwHandleCount 
	//	= GetProcessHandleCount(lppi->hProcess,&lppi->dwHandleCount);
	
	// AffinityMask
	GetProcessAffinityMask(hMySelf,
		&lppi->dwAffinityMask,
		NULL);	
	// WorkingSetSize
	GetProcessWorkingSetSize(hMySelf,
		&lppi->dwWorkingSetSizeMin,
		&lppi->dwWorkingSetSizeMax);	
	lppi->szwCommandLine =  GetCommandLineW();
	// ������Ϣ
	GetStartupInfo(&lppi->sti);
	return 0;
}