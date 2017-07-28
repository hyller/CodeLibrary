// LimitUseTimers.h : main header file for the LIMITUSETIMERS application
//

#if !defined(AFX_LIMITUSETIMERS_H__DB23E67B_CBC9_46E8_8082_ABD7FAC087A9__INCLUDED_)
#define AFX_LIMITUSETIMERS_H__DB23E67B_CBC9_46E8_8082_ABD7FAC087A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLimitUseTimersApp:
// See LimitUseTimers.cpp for the implementation of this class
//

class CLimitUseTimersApp : public CWinApp
{
public:
	CLimitUseTimersApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLimitUseTimersApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLimitUseTimersApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIMITUSETIMERS_H__DB23E67B_CBC9_46E8_8082_ABD7FAC087A9__INCLUDED_)
