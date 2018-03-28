// KeyHook.h : main header file for the KEYHOOK DLL
//

#if !defined(AFX_KEYHOOK_H__E8C955E0_E727_423F_8543_EC0FE4CC7FFB__INCLUDED_)
#define AFX_KEYHOOK_H__E8C955E0_E727_423F_8543_EC0FE4CC7FFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKeyHookApp
// See KeyHook.cpp for the implementation of this class
//
#define DllExport __declspec(dllexport)
DllExport void WINAPI OutEv();//声明导出函数

class CKeyHookApp : public CWinApp
{
public:
	CKeyHookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyHookApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CKeyHookApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYHOOK_H__E8C955E0_E727_423F_8543_EC0FE4CC7FFB__INCLUDED_)
