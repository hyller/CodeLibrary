/* ************************************
*����ͨWindows API�� 
* ʾ������
* dir.c
* 4.3.3	����Ŀ¼
**************************************/

/* ͷ�ļ���*/
#include <windows.h>
#include <stdio.h>

/* ************************************
* int main(void)
* ����	��ʾʹ��CreateDirectory����Ŀ¼
**************************************/
int main(void)
{
	//�ڳ���ĵ�ǰĿ¼�´�����sub_dir����Ŀ¼
	LPSTR szDirPath = "sub_dir";
	if (!CreateDirectory(szDirPath, NULL)) 
	{ 
		printf("����Ŀ¼ %s ����\n",szDirPath); 
		return 1;
	}

	//��C���´���Ŀ¼��example_dir��
	szDirPath = "C:\\example_dir";
	if (!CreateDirectory(szDirPath, NULL)) 
	{ 
		printf("����Ŀ¼ %s ����\n",szDirPath); 
		return 1;
	} 
	printf("�ɹ�\n"); 

	return 0;
}