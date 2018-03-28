// ExternVar.cpp: implementation of the ExternVar class.
//
//////////////////////////////////////////////////////////////////////

#include "ExternVar.h"
#include "Windows.h"
char* myVar;									//定义变量
//DLLMain函数，即DLL的入口函数
BOOL WINAPI DllMain(HANDLE hInst,ULONG ul_reason_for_call,LPVOID lpReserved)
{
	switch( ul_reason_for_call ) 
	{
	case DLL_PROCESS_ATTACH:						//新的进程要访问DLL
		//开始初始化DLL
		myVar="新的进程访问了DLL的导出变量";
		break;
	case DLL_THREAD_ATTACH:						//新的线程要访问DLL
	case DLL_THREAD_DETACH:						//一个线程不再使用DLL
	case DLL_PROCESS_DETACH:						//一个进程不再使用DLL
		myVar="";
		break;
	}
	return TRUE;
}
