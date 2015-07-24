/* ************************************
*����ͨWindows API�� 
* ʾ������
* lock.c
* 5.2.4 �ѹ���
**************************************/

/* ͷ�ļ���*/
#include <windows.h>
#include <stdio.h>
/* ȫ�ֱ�����*/
HANDLE hHeap;
/* ����������*/
DWORD WINAPI ThreadProc(LPVOID lpParameter);

/*************************************
* int main(int argc, PCHAR argv[])
* ����	��ʾ�ѵ�ʹ��
*
* ����	argv[1]���Ϊ��-s����ôʹ�ý��̶� 
*		argv[1]���Ϊ��-a����ô����һ���ɱ��С�Ķ�
*		argv[1]���Ϊ��������ô����������С�Ķѡ�
*
* 2007��10��
*
**************************************/
int main(int argc, PCHAR argv[])
{	
	DWORD dwThreadId;
	HANDLE hThread;
	DWORD i;
	LPVOID lpMem;
	hHeap = HeapCreate(HEAP_NO_SERIALIZE,0,0);
	if(hHeap != NULL)
	{
		printf("�߳�1�������ѳɹ�\n");
	}
	else
	{
		printf("�߳�1��������ʧ��(%d)\n",GetLastError());
		return 1;
	}
	hThread = CreateThread( 
		NULL, 0,
		ThreadProc,
		NULL, 0,
		&dwThreadId); 
	if(hThread == NULL)
	{
		printf("�߳�1�������߳�ʧ��(%d)\n",GetLastError());
		return 1;
	}
	printf("�߳�1�������̳߳ɹ�\n");
	for(i = 0; i<30; i++)
	{
		Sleep(100);
		lpMem = HeapAlloc(hHeap,HEAP_ZERO_MEMORY,40960);
		if(lpMem == NULL)
		{
			printf("�߳�1�������ڴ����(%d)\n",GetLastError());
			continue;
		}
		if(!HeapFree(hHeap,HEAP_NO_SERIALIZE,lpMem))
		{
			printf("�߳�1���ͷ��ڴ����(%d)\n",GetLastError());
			continue;
		}
		printf("�߳�1�����ԴӶѷ��䵽�ڴ�\n");		
	}
	return 0;
}

DWORD WINAPI ThreadProc(
						LPVOID lpParameter
						)
{
	LPVOID lpMem;
	printf("�߳�2���ȴ�1��\n");
	Sleep(1000);	
	if(HeapLock(hHeap))
	{
		printf("�߳�2�����Ѿ�������\n");
		lpMem = HeapAlloc(hHeap,HEAP_ZERO_MEMORY,40960);
		if(lpMem == NULL)
		{
			goto error;
		}
		printf("�߳�2���Ѿ��ɹ��������ڴ�\n");
		printf("�߳�2���ȴ�1��\n");
		Sleep(1000);
		if(HeapFree(hHeap,HEAP_NO_SERIALIZE,lpMem))
		{
			printf("�߳�2���Ѿ��ɹ��ͷ����ڴ�\n");
		}
		else
		{
			goto error;
		}
		if(HeapUnlock(hHeap))
		{
			printf("�߳�2���Ѿ�����˶Զѵ�����\n");
		}
		else
		{
			goto error;
		}
	}
	else
	{
		goto error;
	}
	return 0;
error:
	printf("�߳�2������(%d)���˳�\n",GetLastError());
	ExitProcess(0);
}