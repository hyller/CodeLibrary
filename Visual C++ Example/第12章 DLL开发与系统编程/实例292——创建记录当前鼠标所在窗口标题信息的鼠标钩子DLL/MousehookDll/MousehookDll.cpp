// MousehookDll.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxdllx.h>
#include "MousehookDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


static AFX_EXTENSION_MODULE MousehookDllDLL = { NULL, NULL };


#pragma data_seg("Titlename")
	HWND glhPrevWnd=NULL; //上次鼠标所指的窗口句柄 
	HWND glhDisplayWnd=NULL; //显示目标窗口标题编辑框的句柄 
	HHOOK glhHook=NULL; //安装的鼠标钩子句柄 
	HINSTANCE glhInstance=NULL;//DLL实例句柄 
#pragma data_seg() 


extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("MOUSEHOOKDLL.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(MousehookDllDLL, hInstance))
			return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.

		new CDynLinkLibrary(MousehookDllDLL);
		glhInstance=hInstance;//插入保存DLL实例句柄 
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("MOUSEHOOKDLL.DLL Terminating!\n");
		// Terminate the library before destructors are called
		AfxTermExtensionModule(MousehookDllDLL);
	}
	return 1;   // ok
}
//鼠标钩子函数的实现
LRESULT CALLBACK MouseProc(int nCode,WPARAM wparam,LPARAM lparam) 
{ 
	LPMOUSEHOOKSTRUCT pMouseHook=(MOUSEHOOKSTRUCT FAR *) lparam; 
	if (nCode>=0) 
	{ 
		HWND glhTargetWnd=pMouseHook->hwnd;//取目标窗口句柄 
		HWND ParentWnd=glhTargetWnd; 
		while (ParentWnd !=NULL) 
		{ 
			glhTargetWnd=ParentWnd; 
			ParentWnd=GetParent(glhTargetWnd); //取应用程序主窗口句柄 
		} 
		if(glhTargetWnd!=glhPrevWnd) 
		{ 
			char szCaption[100]; 
			GetWindowText(glhTargetWnd,szCaption,100); //取目标窗口标题 
			if(IsWindow(glhDisplayWnd)) 
				SendMessage(glhDisplayWnd,WM_SETTEXT,0,(LPARAM)(LPCTSTR)szCaption); 
			glhPrevWnd=glhTargetWnd; //保存目标窗口 
		} 
	} 
	return CallNextHookEx(glhHook,nCode,wparam,lparam); //继续传递消息 
} 


CMouseHook::CMouseHook() //类构造函数 
{ 
} 
CMouseHook::~CMouseHook() //类析构函数 
{ 
	StopHook(); 
} 

BOOL CMouseHook::StartHook(HWND hWnd) //安装钩子并设定接收显示窗口句柄 
{ 
	BOOL bResult=FALSE;
	glhHook=SetWindowsHookEx(WH_MOUSE,MouseProc,glhInstance,0); 
	if(glhHook!=NULL) 
	{
		bResult=TRUE;
	}
	glhDisplayWnd=hWnd;//设置显示目标窗口标题编辑框的句柄 
	return bResult; 
} 

BOOL CMouseHook::StopHook() //卸载钩子 
{ 
	BOOL bResult=FALSE; 
	if(glhHook) 
	{ 
		bResult= UnhookWindowsHookEx(glhHook); 
		if(bResult) 
		{ 
			glhPrevWnd=NULL; 
			glhDisplayWnd=NULL;//清变量 
			glhHook=NULL; 
		} 
	} 
	return bResult; 
} 



