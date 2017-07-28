// StaticSplitWnd2.h : main header file for the StaticSplitWnd2 application
//

#if !defined(AFX_StaticSplitWnd2_H__A27EEC79_5A32_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_StaticSplitWnd2_H__A27EEC79_5A32_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd2App:
// See StaticSplitWnd2.cpp for the implementation of this class
//

class CStaticSplitWnd2App : public CWinApp
{
public:
	CStaticSplitWnd2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticSplitWnd2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CStaticSplitWnd2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_StaticSplitWnd2_H__A27EEC79_5A32_11D6_8F32_00E04CE76240__INCLUDED_)
