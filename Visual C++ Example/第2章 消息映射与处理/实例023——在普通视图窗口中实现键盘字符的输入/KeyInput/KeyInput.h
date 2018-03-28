// KeyInput.h : main header file for the KEYINPUT application
//

#if !defined(AFX_KEYINPUT_H__82BACE0B_4F9C_4BDA_A4BC_C9959036F938__INCLUDED_)
#define AFX_KEYINPUT_H__82BACE0B_4F9C_4BDA_A4BC_C9959036F938__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKeyInputApp:
// See KeyInput.cpp for the implementation of this class
//

class CKeyInputApp : public CWinApp
{
public:
	CKeyInputApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyInputApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CKeyInputApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYINPUT_H__82BACE0B_4F9C_4BDA_A4BC_C9959036F938__INCLUDED_)
