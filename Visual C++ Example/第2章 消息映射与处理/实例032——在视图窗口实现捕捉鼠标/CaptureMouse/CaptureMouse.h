// CaptureMouse.h : main header file for the CAPTUREMOUSE application
//

#if !defined(AFX_CAPTUREMOUSE_H__DED3964F_8F5E_402D_A574_506CD560776E__INCLUDED_)
#define AFX_CAPTUREMOUSE_H__DED3964F_8F5E_402D_A574_506CD560776E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCaptureMouseApp:
// See CaptureMouse.cpp for the implementation of this class
//

class CCaptureMouseApp : public CWinApp
{
public:
	CCaptureMouseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaptureMouseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCaptureMouseApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTUREMOUSE_H__DED3964F_8F5E_402D_A574_506CD560776E__INCLUDED_)
