// SplashDlg.h : main header file for the SPLASHDLG application
//

#if !defined(AFX_SPLASHDLG_H__BFF090FE_F3F0_4CDB_BD17_B7621C8D2F8E__INCLUDED_)
#define AFX_SPLASHDLG_H__BFF090FE_F3F0_4CDB_BD17_B7621C8D2F8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSplashDlgApp:
// See SplashDlg.cpp for the implementation of this class
//

class CSplashDlgApp : public CWinApp
{
public:
	CSplashDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplashDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSplashDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLASHDLG_H__BFF090FE_F3F0_4CDB_BD17_B7621C8D2F8E__INCLUDED_)
