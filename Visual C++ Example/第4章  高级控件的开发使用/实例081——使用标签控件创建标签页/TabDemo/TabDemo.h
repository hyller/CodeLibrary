// TabDemo.h : main header file for the TABDEMO application
//

#if !defined(AFX_TABDEMO_H__601EDA85_D637_452C_9715_15818A1B95DD__INCLUDED_)
#define AFX_TABDEMO_H__601EDA85_D637_452C_9715_15818A1B95DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTabDemoApp:
// See TabDemo.cpp for the implementation of this class
//

class CTabDemoApp : public CWinApp
{
public:
	CTabDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTabDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABDEMO_H__601EDA85_D637_452C_9715_15818A1B95DD__INCLUDED_)
