// RoundDlg.h : main header file for the ROUNDDLG application
//

#if !defined(AFX_ROUNDDLG_H__3A047F36_3BC0_4827_BD06_CFBB49A45148__INCLUDED_)
#define AFX_ROUNDDLG_H__3A047F36_3BC0_4827_BD06_CFBB49A45148__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRoundDlgApp:
// See RoundDlg.cpp for the implementation of this class
//

class CRoundDlgApp : public CWinApp
{
public:
	CRoundDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoundDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRoundDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROUNDDLG_H__3A047F36_3BC0_4827_BD06_CFBB49A45148__INCLUDED_)
