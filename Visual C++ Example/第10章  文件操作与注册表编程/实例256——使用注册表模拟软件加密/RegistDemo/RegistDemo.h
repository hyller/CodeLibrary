// RegistDemo.h : main header file for the REGISTDEMO application
//

#if !defined(AFX_REGISTDEMO_H__E0AA9073_2681_4523_8FE9_44A05F527857__INCLUDED_)
#define AFX_REGISTDEMO_H__E0AA9073_2681_4523_8FE9_44A05F527857__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "CheckDlg.h"//对话框头文件

/////////////////////////////////////////////////////////////////////////////
// CRegistDemoApp:
// See RegistDemo.cpp for the implementation of this class
//

class CRegistDemoApp : public CWinApp
{
public:
	CRegistDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegistDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRegistDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTDEMO_H__E0AA9073_2681_4523_8FE9_44A05F527857__INCLUDED_)
