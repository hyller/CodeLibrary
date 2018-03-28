// ViewControlBox.h : main header file for the VIEWCONTROLBOX application
//

#if !defined(AFX_VIEWCONTROLBOX_H__8A66E282_E6C9_4FA3_BFCD_149D63991BA3__INCLUDED_)
#define AFX_VIEWCONTROLBOX_H__8A66E282_E6C9_4FA3_BFCD_149D63991BA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CViewControlBoxApp:
// See ViewControlBox.cpp for the implementation of this class
//

class CViewControlBoxApp : public CWinApp
{
public:
	CViewControlBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewControlBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CViewControlBoxApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWCONTROLBOX_H__8A66E282_E6C9_4FA3_BFCD_149D63991BA3__INCLUDED_)
