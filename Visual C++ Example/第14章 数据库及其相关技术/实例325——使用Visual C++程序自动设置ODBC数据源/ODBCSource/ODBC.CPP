#include <stdio.h>
#include "iostream.h"
#include "windows.h"
#include <ODBCINST.H>

#import "c:\Program Files\Common Files\System\ADO\msado15.dll"  rename("EOF", "_EOF")
using namespace ADODB;

typedef BOOL (WINAPI *SQLCONFIGDATASOURCE_FUNCTION)(HWND,WORD,LPCSTR,LPCSTR);
void main()
{
	//调用动态连接库odbccp32.dll的函数SQLConfigDataSource
	HINSTANCE h=::LoadLibrary("ODBCCP32.DLL");
	SQLCONFIGDATASOURCE_FUNCTION pConfigDataSource=0;
	pConfigDataSource=(SQLCONFIGDATASOURCE_FUNCTION)GetProcAddress(h,"SQLConfigDataSource");
	//使用动态路径设置odbc数据源
	char sDirectory[256];
	::GetCurrentDirectory(256,sDirectory);
	strcat(sDirectory,"\\Student.mdb");
	char ss[256]="DSN=studb 0DBQ=";
	strcat(ss,sDirectory);
	ss[9]=0;			//区分前后子字符串	
	int length=strlen(ss);
	ss[length]=0;		//因为该参数以双结束符结尾	
	BOOL res=pConfigDataSource(NULL,ODBC_ADD_SYS_DSN,"Microsoft Access Driver (*.mdb)", ss);
	::FreeLibrary(h);//释放动态连接库资源
}