// DialogStatusBar.h : main header file for the DIALOGSTATUSBAR application
//

#if !defined(AFX_DIALOGSTATUSBAR_H__160B6C0D_EA18_4359_B28F_AAA8B07B1FF1__INCLUDED_)
#define AFX_DIALOGSTATUSBAR_H__160B6C0D_EA18_4359_B28F_AAA8B07B1FF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialogStatusBarApp:
// See DialogStatusBar.cpp for the implementation of this class
//

class CDialogStatusBarApp : public CWinApp
{
public:
	CDialogStatusBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogStatusBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialogStatusBarApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSTATUSBAR_H__160B6C0D_EA18_4359_B28F_AAA8B07B1FF1__INCLUDED_)
