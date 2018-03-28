// ChangeSizeDlg.h : main header file for the CHANGESIZEDLG application
//

#if !defined(AFX_CHANGESIZEDLG_H__F3774409_D456_4745_B8CA_DE90DC8120AB__INCLUDED_)
#define AFX_CHANGESIZEDLG_H__F3774409_D456_4745_B8CA_DE90DC8120AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CChangeSizeDlgApp:
// See ChangeSizeDlg.cpp for the implementation of this class
//

class CChangeSizeDlgApp : public CWinApp
{
public:
	CChangeSizeDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeSizeDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CChangeSizeDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGESIZEDLG_H__F3774409_D456_4745_B8CA_DE90DC8120AB__INCLUDED_)
