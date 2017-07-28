// EnumWindowsProc.h : main header file for the ENUMWINDOWSPROC application
//

#if !defined(AFX_ENUMWINDOWSPROC_H__3358F32A_D5EE_458E_8FDB_3B3C73B55768__INCLUDED_)
#define AFX_ENUMWINDOWSPROC_H__3358F32A_D5EE_458E_8FDB_3B3C73B55768__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnumWindowsProcApp:
// See EnumWindowsProc.cpp for the implementation of this class
//

class CEnumWindowsProcApp : public CWinApp
{
public:
	CEnumWindowsProcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumWindowsProcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEnumWindowsProcApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMWINDOWSPROC_H__3358F32A_D5EE_458E_8FDB_3B3C73B55768__INCLUDED_)
