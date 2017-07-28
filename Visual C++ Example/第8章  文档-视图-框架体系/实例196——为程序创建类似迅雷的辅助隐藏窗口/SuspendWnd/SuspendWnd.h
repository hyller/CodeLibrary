// SuspendWnd.h : main header file for the SUSPENDWND application
//

#if !defined(AFX_SUSPENDWND_H__FF0CC330_90BF_41E3_BAED_9FEC141377A8__INCLUDED_)
#define AFX_SUSPENDWND_H__FF0CC330_90BF_41E3_BAED_9FEC141377A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSuspendWndApp:
// See SuspendWnd.cpp for the implementation of this class
//

class CSuspendWndApp : public CWinApp
{
public:
	CSuspendWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuspendWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSuspendWndApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUSPENDWND_H__FF0CC330_90BF_41E3_BAED_9FEC141377A8__INCLUDED_)
