// PenDemo.h : main header file for the PENDEMO application
//

#if !defined(AFX_PENDEMO_H__58CE1F31_E037_4659_BB7B_19F476B33903__INCLUDED_)
#define AFX_PENDEMO_H__58CE1F31_E037_4659_BB7B_19F476B33903__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPenDemoApp:
// See PenDemo.cpp for the implementation of this class
//

class CPenDemoApp : public CWinApp
{
public:
	CPenDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPenDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPenDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PENDEMO_H__58CE1F31_E037_4659_BB7B_19F476B33903__INCLUDED_)
