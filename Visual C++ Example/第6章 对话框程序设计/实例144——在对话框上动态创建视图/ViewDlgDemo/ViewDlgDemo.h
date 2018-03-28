// ViewDlgDemo.h : main header file for the VIEWDLGDEMO application
//

#if !defined(AFX_VIEWDLGDEMO_H__445FAEEF_FF9B_469C_BD3F_5BAC9728D21A__INCLUDED_)
#define AFX_VIEWDLGDEMO_H__445FAEEF_FF9B_469C_BD3F_5BAC9728D21A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CViewDlgDemoApp:
// See ViewDlgDemo.cpp for the implementation of this class
//

class CViewDlgDemoApp : public CWinApp
{
public:
	CViewDlgDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewDlgDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CViewDlgDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWDLGDEMO_H__445FAEEF_FF9B_469C_BD3F_5BAC9728D21A__INCLUDED_)
