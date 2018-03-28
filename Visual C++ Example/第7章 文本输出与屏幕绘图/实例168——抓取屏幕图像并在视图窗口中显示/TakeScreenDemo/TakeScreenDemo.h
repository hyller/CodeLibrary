// TakeScreenDemo.h : main header file for the TAKESCREENDEMO application
//

#if !defined(AFX_TAKESCREENDEMO_H__C82D493A_D77A_474E_81BF_603FF6A5816F__INCLUDED_)
#define AFX_TAKESCREENDEMO_H__C82D493A_D77A_474E_81BF_603FF6A5816F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTakeScreenDemoApp:
// See TakeScreenDemo.cpp for the implementation of this class
//

class CTakeScreenDemoApp : public CWinApp
{
public:
	CTakeScreenDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTakeScreenDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTakeScreenDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAKESCREENDEMO_H__C82D493A_D77A_474E_81BF_603FF6A5816F__INCLUDED_)
