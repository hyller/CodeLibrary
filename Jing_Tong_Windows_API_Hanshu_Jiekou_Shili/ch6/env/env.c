/* ************************************
*����ͨWindows API�� 
* ʾ������
* virtual.c
* 5.4.2  ������ͷſɶ���д�������ڴ�ҳ��
**************************************/

/* ͷ�ļ���*/
#include <windows.h>
#include <stdio.h>


#include "../env_dll/env.h"


/*************************************
* int main(void)
* ����	��ʾ�����ڴ��ʹ��
*
* ����	δʹ��
**************************************/
int main(void)
{
	EnumEnvironmentVariables();
	ChangeEnviromentVariables("PATH","C:\\",VARIABLES_APPEND);
	EnumEnvironmentVariables();
	ChangeEnviromentVariables("PATH","C:\\",VARIABLES_NULL);
	EnumEnvironmentVariables();
	ChangeEnviromentVariables("XX","C:\\",VARIABLES_RESET);
	EnumEnvironmentVariables();
}