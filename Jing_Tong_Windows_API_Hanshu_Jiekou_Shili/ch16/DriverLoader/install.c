/* ************************************
*����ͨWindows API��
* ʾ������
* install.c
* 16.2 IO���ơ��ں�ͨ��
**************************************/
/* ͷ�ļ� */
#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\sys\xioctl.h"
/* ȫ�ֱ��� */
char OutputBuffer[100];
char InputBuffer[100];
/* �������� */
BOOL InstallDriver( SC_HANDLE, LPCTSTR, LPCTSTR );
BOOL RemoveDriver( SC_HANDLE, LPCTSTR );
BOOL StartDriver( SC_HANDLE , LPCTSTR );
BOOL StopDriver( SC_HANDLE , LPCTSTR );

/*************************************
* InstallDriver
* ���� �������񡢰�װ����
* ���� SchSCManager��������������
*         DriverName��������
*         ServiceExe�������Ŀ�ִ�г���·��
**************************************/
BOOL InstallDriver(
				   SC_HANDLE SchSCManager,
				   LPCTSTR DriverName,
				   LPCTSTR ServiceExe
				   )
{
	SC_HANDLE schService;
	DWORD err;

	// ����CreateService��������
	schService = CreateService(SchSCManager, // �����������SCM���
		DriverName, // ������
		DriverName, // �������ʾ��
		SERVICE_ALL_ACCESS, // ��ȡȨ��
		SERVICE_KERNEL_DRIVER, // ��������
		SERVICE_DEMAND_START, // ��������
		SERVICE_ERROR_NORMAL, // ��������Ĵ���
		ServiceExe, // ��ִ�г���
		NULL, NULL, NULL, NULL, NULL
		);

	if (schService == NULL)
	{
		// ��������ʧ��
		err = GetLastError();
		// �����Ѿ�����
		if (err == ERROR_SERVICE_EXISTS)
		{
			return TRUE;// ���سɹ�
		}
		else
		{
			// ���������Ϣ������ʧ��
			printf("CreateService failed! Error = %d \n", err );
			return FALSE;
		}
	}
	// �����ɹ����رշ���
	if (schService)
	{
		CloseServiceHandle(schService);
	}
	// ���سɹ�
	return TRUE;
}

/*************************************
* RemoveDriver
* ���� ɾ����������
* ���� SchSCManager��������������
*         DriverName��������
**************************************/
BOOL RemoveDriver(
			 SC_HANDLE SchSCManager,
			 LPCTSTR DriverName
			 )
{
	SC_HANDLE schService;
	BOOLEAN rCode;

	// �򿪷���
	schService = OpenService(SchSCManager,
		DriverName,
		SERVICE_ALL_ACCESS
		);

	if (schService == NULL)
	{
		// �����ʧ��
		printf("OpenService failed! Error = %d \n", GetLastError());
		return FALSE;
	}

	// ɾ������
	if (DeleteService(schService))
	{
		rCode = TRUE;
	} 
	else
	{
		//ʧ��
		printf("DeleteService failed! Error = %d \n", GetLastError());
		rCode = FALSE;
	}

	// �رշ�����
	if (schService)
	{
		CloseServiceHandle(schService);
	}
	return rCode;
}

/*************************************
* StartDriver
* ���� �𶯷��񣬼���ִ������
* ���� SchSCManager��������������
*         DriverName��������
**************************************/
BOOL StartDriver(
			SC_HANDLE SchSCManager,
			LPCTSTR DriverName
			)
{
	SC_HANDLE schService;
	DWORD err;

	// �򿪷���
	schService = OpenService(SchSCManager,
		DriverName,
		SERVICE_ALL_ACCESS
		);
	if (schService == NULL)
	{
		// ʧ��
		printf("OpenService failed! Error = %d \n", GetLastError());
		return FALSE;
	}

	// ��������
	if (!StartService(schService, // ������
		0, // ������������
		NULL // ����ָ�룬��
		))
	{
		// ����ʧ��
		err = GetLastError();
		// �Ѿ���ʼ����
		if (err == ERROR_SERVICE_ALREADY_RUNNING)
		{
			// ���سɹ�
			return TRUE;
		}
		else
		{
			// ʧ�ܣ���ӡ����
			printf("StartService failure! Error = %d \n", err );
			return FALSE;
		}
	}

	// �رշ�����
	if (schService)
	{
		CloseServiceHandle(schService);
	}

	return TRUE;

}

/*************************************
* StopDriver
* ���� ֹͣ����ֹͣ��������
* ���� SchSCManager��������������
*         DriverName��������
**************************************/
BOOL StopDriver(
		   SC_HANDLE SchSCManager,
		   LPCTSTR DriverName
		   )
{
	BOOLEAN rCode = TRUE;
	SC_HANDLE schService;
	SERVICE_STATUS serviceStatus;

	// �򿪷���
	schService = OpenService(SchSCManager,
		DriverName,
		SERVICE_ALL_ACCESS
		);

	if (schService == NULL)
	{
		// ʧ��
		printf("OpenService failed! Error = %d \n", GetLastError());
		return FALSE;
	}

	// ֹͣ����
	if (ControlService(schService,
		SERVICE_CONTROL_STOP,
		&serviceStatus
		))
	{
		rCode = TRUE;
	}
	else 
	{
		// ʧ��
		printf("ControlService failed! Error = %d \n", GetLastError() );
		rCode = FALSE;
	}

	// �رշ�����
	if (schService)
	{
		CloseServiceHandle (schService);
	}
	return rCode;

} 

/*************************************
* GetDriverPath
* ���� ��÷���������·��
* ���� DriverLocation������������·��
**************************************/
BOOL GetDriverPath(
				LPSTR DriverLocation
				)
{

	DWORD driverLocLen = 0;

	// ����.sys�ļ��ڱ�����ͬһĿ����
	driverLocLen = GetCurrentDirectory(MAX_PATH,
		DriverLocation
		);

	if (!driverLocLen)
	{
		printf("GetCurrentDirectory failed! Error = %d \n", GetLastError());
		return FALSE;
	}

	// ����·��������������
	lstrcat(DriverLocation, "\\");
	lstrcat(DriverLocation, DRIVER_NAME);
	lstrcat(DriverLocation, ".sys");

	return TRUE;
}

/*************************************
* int _cdecl main( )
* ���� �������������п���
**************************************/
int _cdecl main()
{
	HANDLE hDevice;
	BOOL bRc;
	ULONG bytesReturned;
	DWORD errNum = 0;
	UCHAR driverLocation[MAX_PATH];

	SC_HANDLE schSCManager;// ������������
	// �򿪷����������������װ����������ʹ�õ���
	schSCManager = OpenSCManager(NULL, // ����
		NULL, // �������ݿ�
		SC_MANAGER_ALL_ACCESS // ��ȡȨ��
		);
	if (!schSCManager)
	{
		// ��ʧ��
		printf("Open SC Manager failed! Error = %d \n", GetLastError());
		return 1;
	}
	// ��������ļ���·��
	if (!GetDriverPath(driverLocation))
	{
		return 1;
	}
	// ��װ��������
	if (InstallDriver(schSCManager,
		DRIVER_NAME,
		driverLocation
		))
	{
		// ��װ�ɹ�������������������
		if(!StartDriver(schSCManager, DRIVER_NAME ))
		{
			printf("Unable to start driver. \n");
			return 1;
		}
	}
	else
	{
		// ��װʧ�ܣ�ɾ��������
		RemoveDriver(schSCManager, DRIVER_NAME );
		printf("Unable to install driver. \n");
		return 1;
	}
	// ����������ÿ������õľ��
	// �����������ķ�������
	hDevice = CreateFile( "\\\\.\\IoctlTest",
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if ( hDevice == INVALID_HANDLE_VALUE )
	{
		printf ( "Error: CreatFile Failed : %d\n", GetLastError());
		return 1;
	}

	// ��ӡ�����������
	printf("InputBuffer Pointer = %p, BufLength = %d\n", InputBuffer,
		sizeof(InputBuffer));
	printf("OutputBuffer Pointer = %p BufLength = %d\n", OutputBuffer,
		sizeof(OutputBuffer));
	
	// ���뵽�ں˵����ݣ�
	lstrcpy(InputBuffer,
		"This String is from User Application; using IOCTL_XIOCTL_BUFFER");
	printf("\nCalling DeviceIoControl IOCTL_XIOCTL_BUFFER:\n");
	
	// ����������
	memset(OutputBuffer, 0, sizeof(OutputBuffer));
	// ����IO���ƣ�
	bRc = DeviceIoControl ( hDevice,// ���
		(DWORD) IOCTL_XIOCTL_BUFFER,// IOCTL
		&InputBuffer,// ��������
		strlen ( InputBuffer )+1,// �������ݵĳ���
		&OutputBuffer,// �������
		sizeof( OutputBuffer),// ������ݳ���
		&bytesReturned,// ʵ����������ݳ���
		NULL
		);
	// �ж��Ƿ�ɹ�
	if ( !bRc )
	{
		printf ( "Error in DeviceIoControl : %d", GetLastError());
		return 1;
	}
	// ��ӡ���ں����������
	printf(" OutBuffer (%d): %s\n", bytesReturned, OutputBuffer);
	// �رվ��
	CloseHandle ( hDevice );
	// ֹͣ����
	StopDriver(schSCManager,
		DRIVER_NAME
		);
	// ɾ������
	RemoveDriver(schSCManager,
		DRIVER_NAME
		);
	// �رշ��������
	CloseServiceHandle (schSCManager);
	return 0;
}