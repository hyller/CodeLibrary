// AviButtonDemo.h : main header file for the AVIBUTTONDEMO application
//

#if !defined(AFX_AVIBUTTONDEMO_H__37E211AC_26B7_48D4_BF5D_C49C9E099272__INCLUDED_)
#define AFX_AVIBUTTONDEMO_H__37E211AC_26B7_48D4_BF5D_C49C9E099272__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAviButtonDemoApp:
// See AviButtonDemo.cpp for the implementation of this class
//

class CAviButtonDemoApp : public CWinApp
{
public:
	CAviButtonDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAviButtonDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAviButtonDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVIBUTTONDEMO_H__37E211AC_26B7_48D4_BF5D_C49C9E099272__INCLUDED_)
