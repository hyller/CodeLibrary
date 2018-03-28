// FullScreenDlgDemo.h : main header file for the FullScreenDlgDemo application
//

#if !defined(AFX_FullScreenDlgDemo_H__AF1D871D_A670_4C06_8AD8_FF878159CED8__INCLUDED_)
#define AFX_FullScreenDlgDemo_H__AF1D871D_A670_4C06_8AD8_FF878159CED8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDlgDemoApp:
// See FullScreenDlgDemo.cpp for the implementation of this class
//

class CFullScreenDlgDemoApp : public CWinApp
{
public:
	CFullScreenDlgDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullScreenDlgDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFullScreenDlgDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FullScreenDlgDemo_H__AF1D871D_A670_4C06_8AD8_FF878159CED8__INCLUDED_)
