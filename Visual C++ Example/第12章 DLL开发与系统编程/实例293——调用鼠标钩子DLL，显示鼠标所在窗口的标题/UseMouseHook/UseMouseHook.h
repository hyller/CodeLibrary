// UseMouseHook.h : main header file for the UseMouseHook application
//

#if !defined(AFX_UseMouseHook_H__3926B9FC_AC33_4F96_A465_D0263FED07B0__INCLUDED_)
#define AFX_UseMouseHook_H__3926B9FC_AC33_4F96_A465_D0263FED07B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseMouseHookApp:
// See UseMouseHook.cpp for the implementation of this class
//

class CUseMouseHookApp : public CWinApp
{
public:
	CUseMouseHookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseMouseHookApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseMouseHookApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UseMouseHook_H__3926B9FC_AC33_4F96_A465_D0263FED07B0__INCLUDED_)
