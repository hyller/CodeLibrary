// AfxMessageBoxDemo.h : main header file for the AFXMESSAGEBOXDEMO application
//

#if !defined(AFX_AFXMESSAGEBOXDEMO_H__9D9710F6_ECDC_4D9A_BAB0_11D755D0CCD4__INCLUDED_)
#define AFX_AFXMESSAGEBOXDEMO_H__9D9710F6_ECDC_4D9A_BAB0_11D755D0CCD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAfxMessageBoxDemoApp:
// See AfxMessageBoxDemo.cpp for the implementation of this class
//

class CAfxMessageBoxDemoApp : public CWinApp
{
public:
	CAfxMessageBoxDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAfxMessageBoxDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAfxMessageBoxDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AFXMESSAGEBOXDEMO_H__9D9710F6_ECDC_4D9A_BAB0_11D755D0CCD4__INCLUDED_)
