// ZhuceDemo.h : main header file for the ZHUCEDEMO application
//

#if !defined(AFX_ZHUCEDEMO_H__B2E147D2_10EB_4542_AA0D_33663C339824__INCLUDED_)
#define AFX_ZHUCEDEMO_H__B2E147D2_10EB_4542_AA0D_33663C339824__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CZhuceDemoApp:
// See ZhuceDemo.cpp for the implementation of this class
//

class CZhuceDemoApp : public CWinApp
{
public:
	CZhuceDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZhuceDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CZhuceDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHUCEDEMO_H__B2E147D2_10EB_4542_AA0D_33663C339824__INCLUDED_)
