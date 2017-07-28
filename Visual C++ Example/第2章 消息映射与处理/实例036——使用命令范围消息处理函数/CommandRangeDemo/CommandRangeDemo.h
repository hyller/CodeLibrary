// CommandRangeDemo.h : main header file for the COMMANDRANGEDEMO application
//

#if !defined(AFX_COMMANDRANGEDEMO_H__2CA69794_634F_4E25_8BBF_56F080D0001C__INCLUDED_)
#define AFX_COMMANDRANGEDEMO_H__2CA69794_634F_4E25_8BBF_56F080D0001C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCommandRangeDemoApp:
// See CommandRangeDemo.cpp for the implementation of this class
//

class CCommandRangeDemoApp : public CWinApp
{
public:
	CCommandRangeDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommandRangeDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCommandRangeDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMANDRANGEDEMO_H__2CA69794_634F_4E25_8BBF_56F080D0001C__INCLUDED_)
