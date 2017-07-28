// RgnDemo.h : main header file for the RGNDEMO application
//

#if !defined(AFX_RGNDEMO_H__2608A276_8A2E_4B58_B6C4_FE8455A123D0__INCLUDED_)
#define AFX_RGNDEMO_H__2608A276_8A2E_4B58_B6C4_FE8455A123D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRgnDemoApp:
// See RgnDemo.cpp for the implementation of this class
//

class CRgnDemoApp : public CWinApp
{
public:
	CRgnDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRgnDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRgnDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGNDEMO_H__2608A276_8A2E_4B58_B6C4_FE8455A123D0__INCLUDED_)
