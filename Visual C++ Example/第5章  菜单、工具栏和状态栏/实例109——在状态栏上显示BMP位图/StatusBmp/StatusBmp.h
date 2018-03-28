// StatusBmp.h : main header file for the STATUSBMP application
//

#if !defined(AFX_STATUSBMP_H__419BF451_6396_4260_8260_15EA2D5D937D__INCLUDED_)
#define AFX_STATUSBMP_H__419BF451_6396_4260_8260_15EA2D5D937D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStatusBmpApp:
// See StatusBmp.cpp for the implementation of this class
//

class CStatusBmpApp : public CWinApp
{
public:
	CStatusBmpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusBmpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CStatusBmpApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSBMP_H__419BF451_6396_4260_8260_15EA2D5D937D__INCLUDED_)
