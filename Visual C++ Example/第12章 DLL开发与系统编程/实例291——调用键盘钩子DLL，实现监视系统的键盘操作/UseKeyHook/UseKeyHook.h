// UseKeyHook.h : main header file for the USEKEYHOOK application
//

#if !defined(AFX_USEKEYHOOK_H__A1EC75FE_4532_4935_8F97_2872504727C7__INCLUDED_)
#define AFX_USEKEYHOOK_H__A1EC75FE_4532_4935_8F97_2872504727C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseKeyHookApp:
// See UseKeyHook.cpp for the implementation of this class
//

class CUseKeyHookApp : public CWinApp
{
public:
	CUseKeyHookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseKeyHookApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CUseKeyHookApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEKEYHOOK_H__A1EC75FE_4532_4935_8F97_2872504727C7__INCLUDED_)
