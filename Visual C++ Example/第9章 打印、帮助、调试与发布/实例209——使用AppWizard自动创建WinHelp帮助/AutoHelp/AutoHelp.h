// AutoHelp.h : main header file for the AUTOHELP application
//

#if !defined(AFX_AUTOHELP_H__80683E2F_C7F2_42C0_A9D6_66914EAF3C57__INCLUDED_)
#define AFX_AUTOHELP_H__80683E2F_C7F2_42C0_A9D6_66914EAF3C57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAutoHelpApp:
// See AutoHelp.cpp for the implementation of this class
//

class CAutoHelpApp : public CWinApp
{
public:
	CAutoHelpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoHelpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAutoHelpApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOHELP_H__80683E2F_C7F2_42C0_A9D6_66914EAF3C57__INCLUDED_)
