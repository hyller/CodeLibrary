// StatusTime.h : main header file for the STATUSTIME application
//

#if !defined(AFX_STATUSTIME_H__A5EC4781_356D_4735_A20B_E6466C788F11__INCLUDED_)
#define AFX_STATUSTIME_H__A5EC4781_356D_4735_A20B_E6466C788F11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStatusTimeApp:
// See StatusTime.cpp for the implementation of this class
//

class CStatusTimeApp : public CWinApp
{
public:
	CStatusTimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusTimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CStatusTimeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSTIME_H__A5EC4781_356D_4735_A20B_E6466C788F11__INCLUDED_)
