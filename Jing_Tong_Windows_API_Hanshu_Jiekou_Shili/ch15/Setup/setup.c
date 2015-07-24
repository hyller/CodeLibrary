/* ************************************
*����ͨWindows API��
* ʾ������
* setup.c
* 15.3 setup.exe
**************************************/
/* ͷ�ļ� */
#include <Windows.h>
#include <Setupapi.h>
#include <shlobj.h>
/* �� */
#pragma comment (lib, "shell32.lib")
#pragma comment (lib, "Setupapi.lib")

/*************************************
* VOID GetSourceDirectory(LPSTR szPath)
* ���� ��õ�ǰ·��
* szPath������·��
**************************************/
VOID GetSourceDirectory(LPSTR szPath)
{
	int i;

	GetModuleFileName(NULL,szPath,MAX_PATH);

	i=strlen(szPath);
	while ((i>0)&&(szPath[i-1]!='\\'))
	{
		szPath[--i]=0;
	}
}

/*************************************
* WinMain
* ���� �������Setup API���а�װ
**************************************/
INT WinMain(
			HINSTANCE hInstance,
			HINSTANCE hPrevInstance,
			LPSTR lpCmdLine,
			int nCmdShow
			)
{
	HINF hInf; // INF�ļ����
	CHAR szSrcPath[MAX_PATH];// Դ·��
	CHAR szDisPath[MAX_PATH];// Ŀ��·��
	BOOL bResult;
	PVOID pContext;
	// �뱾������ͬһĿ¼�µ�Setup.inf
	GetSourceDirectory(szSrcPath);
	lstrcat(szSrcPath,"setup.inf");
	// �� inf �ļ�
	hInf = SetupOpenInfFile(szSrcPath, NULL, INF_STYLE_WIN4, NULL);
	// �Ƿ�ɹ�
	if (hInf == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,
			"Error: Could not open the INF file.",
			"ERROR",
			MB_OK|MB_ICONERROR);
		return FALSE;
	}
	// ���Program Files��·��
	SHGetSpecialFolderPath(NULL, 
		szDisPath, CSIDL_PROGRAM_FILES , FALSE);
	// ����Ŀ��·��
	lstrcat(szDisPath,"\\MyInstall");

	// ��inf�����ļ��е�·��ID��ֵ��ʹ��·���滻·��ID
	bResult = SetupSetDirectoryId(hInf, 32768, szDisPath);
	if (!bResult)
	{
		MessageBox(NULL,
			"Error: Could not associate a directory ID with the destination directory.",
			"ERROR",
			MB_OK|MB_ICONERROR);
		SetupCloseInfFile(hInf);
		return FALSE;
	}

	// ����Ĭ��callback�����Ĳ���
	pContext=SetupInitDefaultQueueCallback(NULL);

	// ���а�װ
	bResult=SetupInstallFromInfSection(
		NULL, // �����ھ��
		hInf, // INF�ļ����
		"Install", // INF�ļ��У������˰�װ��Ϣ�Ľ���
		SPINST_FILES | SPINST_REGISTRY , // ��װ��־
		NULL, // ��װ��ֵ
		NULL, // Դ�ļ���·����������INF�ļ�������
		0, // ����ʱ�Ķ���
		(PSP_FILE_CALLBACK)SetupDefaultQueueCallback, // �ص�����
		pContext, // �ص������Ĳ���
		NULL, // �豸��Ϣ
		NULL // �豸��Ϣ
		);
	// ��װ�Ƿ�ɹ�
	if (!bResult)
	{
		// ʧ�ܣ����������Ϣ
		MessageBox(NULL,
			"SetupInstallFromInfSection",
			"ERROR",
			MB_OK|MB_ICONERROR);
		//�ر�
		SetupTermDefaultQueueCallback(pContext);
		SetupCloseInfFile(hInf);
		return FALSE;
	}

	// �ر�
	SetupTermDefaultQueueCallback(pContext);
	SetupCloseInfFile(hInf);

	return TRUE;
}