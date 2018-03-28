// DlgPaintDemo.h : main header file for the DlgPaintDemo application
//

#if !defined(AFX_DlgPaintDemo_H__9B5AC945_B5B3_11D6_BA91_0000B48A08B1__INCLUDED_)
#define AFX_DlgPaintDemo_H__9B5AC945_B5B3_11D6_BA91_0000B48A08B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgPaintDemoApp:
// See DlgPaintDemo.cpp for the implementation of this class
//

class CDlgPaintDemoApp : public CWinApp
{
public:
	CDlgPaintDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPaintDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDlgPaintDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgPaintDemo_H__9B5AC945_B5B3_11D6_BA91_0000B48A08B1__INCLUDED_)
