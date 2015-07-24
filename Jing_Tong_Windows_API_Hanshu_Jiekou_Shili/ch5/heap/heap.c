/* ************************************
*����ͨWindows API�� 
* ʾ������
* heap.c
* 5.2	�ѹ���
**************************************/

/* ͷ�ļ���*/
#include <windows.h>
#include <stdio.h>

/*************************************
* DWORD PrintHeapSize(HANDLE hHeap,LPVOID lpMem)
* ����	��ȡ�ѵĴ�С����ӡ����
*
* ����	HANDLE hHeap���Ѿ��
*		LPVOID lpMem���ڴ��ַָ��
*
* ����ֵ	0����ִ����ɣ�1���뷢������
**************************************/
DWORD PrintHeapSize(HANDLE hHeap,LPVOID lpMem)
{
	SIZE_T dwHeapSize;
	dwHeapSize = HeapSize(hHeap,HEAP_NO_SERIALIZE,lpMem);
	if(dwHeapSize == -1)
	{
		printf("Get HeapSize error :%d",GetLastError());
		return 1;
	}
	printf("�ڴ���СΪ:0x%x\n",dwHeapSize);
	return 0;
}

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
	SYSTEM_INFO si;	//ϵͳ��Ϣ
	HANDLE hHeap;	//�Ѿ��
	LPVOID lpMem;	//�ڴ��ָ��
	LPVOID lpReAlloc;	//�ڴ���С�������ָ��
	DWORD dwHeapSize;	//���ڴ沺��С
	HANDLE hHeaps[24];	//���ڱ�����������еĶѾ��
	DWORD dwHeapNum;	//�����жѵ�����\
	//��ȡϵͳ��Ϣ
	GetSystemInfo(&si);
	//��ϵͳ�ڴ��ҳ��С�����ڴ�������ȴ�ӡ������
	printf("ϵͳ�ڴ�ҳ��С: 0x%x\nϵͳ�ڴ��������:0x%x\n",
		si.dwPageSize,si.dwAllocationGranularity);
	//�����������������ǡ�-a������һ�����Ϊ10����ҳ��С�Ķ�
	if(argc == 2 && 0==lstrcmp(argv[1],"-a"))
	{
		hHeap = HeapCreate(HEAP_NO_SERIALIZE,
			si.dwPageSize,si.dwPageSize*10);
		printf("������,��ʼ����СΪ1ҳ,���Ϊ10ҳ\n");
	}
	//����������Ϊ��-s��ʹ�ý��̳�ʼ��ʱ�Ѿ����ڵĶ�
	else if(argc == 2 && 0==lstrcmp(argv[1],"-s"))
	{
		hHeap = GetProcessHeap();
		printf("��ȡϵͳ�Ѿ����ڵĶ�\n");
	}
	//�����������������һ���������Ķ�
	else
	{
		hHeap = HeapCreate(HEAP_NO_SERIALIZE,0,0);
		printf("������,��ʼ����СΪ1ҳ,��С�ɱ�\n");
	}
	//�ж϶��Ƿ񴴽�/��ȡ�ɹ�
	if(hHeap == NULL)
	{
		printf("�������ȡ���̶Ѵ���: %d",GetLastError());
		return 1;
	}
	//��ȡ����ӡ��ǰ������һ���ж��ٸ��ѣ���û���½��ѣ�ֵ�᲻ͬ
	dwHeapNum = GetProcessHeaps(24,hHeaps);
	if(dwHeapNum == 0)
	{
		printf("GetProcessHeaps error: %d",GetLastError());
	}
	else
	{
		printf("��ǰ����һ����%d����\n",dwHeapNum);
	}
	//�ڶ��Ϸ����ڴ棬3��ҳ���С
	lpMem = HeapAlloc(hHeap,HEAP_ZERO_MEMORY,si.dwPageSize*3);
	if(lpMem == NULL)
	{
		printf("HeapAlloc error: %d",GetLastError());
		return 1;
	}
	printf("�ڶ��ϳɹ������ڴ�,��ʼ��ַΪ:0x%x\n",lpMem);
	//��ӡ��ǰ���ڴ��Ĵ�С
	PrintHeapSize(hHeap,lpMem);
	//�ٷ����ڴ棬�����ڴ�Ĵ�СΪ11����ҳ��С��
	//���ʹ�õ�һ�ַ��������ѣ���������
	lpReAlloc = HeapReAlloc(hHeap, HEAP_ZERO_MEMORY, lpMem, si.dwPageSize*11);
	if(lpReAlloc == NULL)
	{
		printf("HeapReAlloc error: %d",GetLastError());
		return 1;
	}
	printf("�ڶ����ٷ����ڴ�,��ַΪ:0x%x,ԭ��ַ:0x%x\n",lpReAlloc,lpMem);
	//��ӡ������С��Ķ��ڴ���С
	PrintHeapSize(hHeap,lpReAlloc);

	//�ͷ��ڴ�
	if(!HeapFree(  hHeap, HEAP_NO_SERIALIZE, lpReAlloc))
	{
		printf("HeapFree error: %d",GetLastError());
		return 1;
	}
	printf("�ͷ��ڴ�ɹ�\n");
	//����½��˶ѣ����ٶѡ�
	if(argc != 2 || 0!=lstrcmp(argv[1],"-s"))
	{
		printf("����HeapCreate�����Ķ�\n");
		if(!HeapDestroy(hHeap))
		{
			printf("HeapDestroy error: %d",GetLastError());
			return 1;
		}
		printf("���ٶѳɹ�\n");	
	}
	return 0;
}