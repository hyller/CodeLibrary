// CursorHotDemo.h : main header file for the CURSORHOTDEMO application
//

#if !defined(AFX_CURSORHOTDEMO_H__323F0B83_D505_4175_AE0F_DB4DFA89527A__INCLUDED_)
#define AFX_CURSORHOTDEMO_H__323F0B83_D505_4175_AE0F_DB4DFA89527A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCursorHotDemoApp:
// See CursorHotDemo.cpp for the implementation of this class
//

class CCursorHotDemoApp : public CWinApp
{
public:
	CCursorHotDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCursorHotDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCursorHotDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CURSORHOTDEMO_H__323F0B83_D505_4175_AE0F_DB4DFA89527A__INCLUDED_)
