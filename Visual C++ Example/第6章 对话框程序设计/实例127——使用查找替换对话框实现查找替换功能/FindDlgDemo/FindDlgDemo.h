// FindDlgDemo.h : main header file for the FINDDLGDEMO application
//

#if !defined(AFX_FINDDLGDEMO_H__4F1B9A07_8A6B_4EC8_B159_02E5BA0F6620__INCLUDED_)
#define AFX_FINDDLGDEMO_H__4F1B9A07_8A6B_4EC8_B159_02E5BA0F6620__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFindDlgDemoApp:
// See FindDlgDemo.cpp for the implementation of this class
//

class CFindDlgDemoApp : public CWinApp
{
public:
	CFindDlgDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindDlgDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFindDlgDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDDLGDEMO_H__4F1B9A07_8A6B_4EC8_B159_02E5BA0F6620__INCLUDED_)
