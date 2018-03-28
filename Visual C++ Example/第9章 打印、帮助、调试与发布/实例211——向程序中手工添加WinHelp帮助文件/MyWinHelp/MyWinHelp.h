// MyWinHelp.h : main header file for the MYWINHELP application
//

#if !defined(AFX_MYWINHELP_H__91F20BAE_4492_4C9D_BC71_F65458E6A5DC__INCLUDED_)
#define AFX_MYWINHELP_H__91F20BAE_4492_4C9D_BC71_F65458E6A5DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyWinHelpApp:
// See MyWinHelp.cpp for the implementation of this class
//

class CMyWinHelpApp : public CWinApp
{
public:
	CMyWinHelpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWinHelpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyWinHelpApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWINHELP_H__91F20BAE_4492_4C9D_BC71_F65458E6A5DC__INCLUDED_)
