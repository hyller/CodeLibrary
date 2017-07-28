// FileDlgDemo.h : main header file for the FILEDLGDEMO application
//

#if !defined(AFX_FILEDLGDEMO_H__4F702277_E95F_4B15_85B7_A77DD0F3C34D__INCLUDED_)
#define AFX_FILEDLGDEMO_H__4F702277_E95F_4B15_85B7_A77DD0F3C34D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileDlgDemoApp:
// See FileDlgDemo.cpp for the implementation of this class
//

class CFileDlgDemoApp : public CWinApp
{
public:
	CFileDlgDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileDlgDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileDlgDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEDLGDEMO_H__4F702277_E95F_4B15_85B7_A77DD0F3C34D__INCLUDED_)
