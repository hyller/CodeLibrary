// HotKeyDemo.h : main header file for the HOTKEYDEMO application
//

#if !defined(AFX_HOTKEYDEMO_H__33682CA3_BA10_41FD_A4FC_3691BCF06C73__INCLUDED_)
#define AFX_HOTKEYDEMO_H__33682CA3_BA10_41FD_A4FC_3691BCF06C73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHotKeyDemoApp:
// See HotKeyDemo.cpp for the implementation of this class
//

class CHotKeyDemoApp : public CWinApp
{
public:
	CHotKeyDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHotKeyDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHotKeyDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOTKEYDEMO_H__33682CA3_BA10_41FD_A4FC_3691BCF06C73__INCLUDED_)
