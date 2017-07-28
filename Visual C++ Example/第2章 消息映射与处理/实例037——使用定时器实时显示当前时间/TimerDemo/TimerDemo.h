// TimerDemo.h : main header file for the TIMERDEMO application
//

#if !defined(AFX_TIMERDEMO_H__8AB295D9_3A3C_41B4_ACA6_55AB77971332__INCLUDED_)
#define AFX_TIMERDEMO_H__8AB295D9_3A3C_41B4_ACA6_55AB77971332__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimerDemoApp:
// See TimerDemo.cpp for the implementation of this class
//

class CTimerDemoApp : public CWinApp
{
public:
	CTimerDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimerDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTimerDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERDEMO_H__8AB295D9_3A3C_41B4_ACA6_55AB77971332__INCLUDED_)
