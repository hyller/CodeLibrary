// PaintDcDemo.h : main header file for the PAINTDCDEMO application
//

#if !defined(AFX_PAINTDCDEMO_H__E55390D5_E302_487E_9EBC_E738978F5ECB__INCLUDED_)
#define AFX_PAINTDCDEMO_H__E55390D5_E302_487E_9EBC_E738978F5ECB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPaintDcDemoApp:
// See PaintDcDemo.cpp for the implementation of this class
//

class CPaintDcDemoApp : public CWinApp
{
public:
	CPaintDcDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintDcDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPaintDcDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTDCDEMO_H__E55390D5_E302_487E_9EBC_E738978F5ECB__INCLUDED_)
