// OpenURL.h : main header file for the OPENURL application
//

#if !defined(AFX_OPENURL_H__82A931E1_D2A2_4FA6_ACBA_B1BE746E3B01__INCLUDED_)
#define AFX_OPENURL_H__82A931E1_D2A2_4FA6_ACBA_B1BE746E3B01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COpenURLApp:
// See OpenURL.cpp for the implementation of this class
//

class COpenURLApp : public CWinApp
{
public:
	COpenURLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenURLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COpenURLApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENURL_H__82A931E1_D2A2_4FA6_ACBA_B1BE746E3B01__INCLUDED_)
