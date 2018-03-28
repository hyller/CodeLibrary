// MyEmailClient.h : main header file for the MYEMAILCLIENT application
//

#if !defined(AFX_MYEMAILCLIENT_H__CA4F38A5_8965_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_MYEMAILCLIENT_H__CA4F38A5_8965_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyEmailClientApp:
// See MyEmailClient.cpp for the implementation of this class
//

class CMyEmailClientApp : public CWinApp
{
public:
	CMyEmailClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyEmailClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyEmailClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEMAILCLIENT_H__CA4F38A5_8965_11D6_8F32_00E04CE76240__INCLUDED_)
