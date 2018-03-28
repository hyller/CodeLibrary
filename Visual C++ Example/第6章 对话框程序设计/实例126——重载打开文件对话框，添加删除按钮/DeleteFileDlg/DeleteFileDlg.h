// DeleteFileDlg.h : main header file for the DELETEFILEDLG application
//

#if !defined(AFX_DELETEFILEDLG_H__C8FF88EF_FFFE_4707_89CB_5E9CEB55040D__INCLUDED_)
#define AFX_DELETEFILEDLG_H__C8FF88EF_FFFE_4707_89CB_5E9CEB55040D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDeleteFileDlgApp:
// See DeleteFileDlg.cpp for the implementation of this class
//

class CDeleteFileDlgApp : public CWinApp
{
public:
	CDeleteFileDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteFileDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDeleteFileDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEFILEDLG_H__C8FF88EF_FFFE_4707_89CB_5E9CEB55040D__INCLUDED_)
