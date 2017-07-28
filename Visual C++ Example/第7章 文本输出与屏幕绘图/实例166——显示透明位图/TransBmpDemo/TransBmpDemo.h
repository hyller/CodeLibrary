// TransBmpDemo.h : main header file for the TRANSBMPDEMO application
//

#if !defined(AFX_TRANSBMPDEMO_H__CA3E198A_CBAF_4689_8D99_EBC665FD7601__INCLUDED_)
#define AFX_TRANSBMPDEMO_H__CA3E198A_CBAF_4689_8D99_EBC665FD7601__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTransBmpDemoApp:
// See TransBmpDemo.cpp for the implementation of this class
//

class CTransBmpDemoApp : public CWinApp
{
public:
	CTransBmpDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransBmpDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTransBmpDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSBMPDEMO_H__CA3E198A_CBAF_4689_8D99_EBC665FD7601__INCLUDED_)
