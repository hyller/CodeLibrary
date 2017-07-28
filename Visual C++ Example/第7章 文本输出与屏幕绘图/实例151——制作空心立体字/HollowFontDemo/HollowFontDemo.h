// HollowFontDemo.h : main header file for the HOLLOWFONTDEMO application
//

#if !defined(AFX_HOLLOWFONTDEMO_H__D954F6F4_38A9_4412_904A_9066397BFC37__INCLUDED_)
#define AFX_HOLLOWFONTDEMO_H__D954F6F4_38A9_4412_904A_9066397BFC37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHollowFontDemoApp:
// See HollowFontDemo.cpp for the implementation of this class
//

class CHollowFontDemoApp : public CWinApp
{
public:
	CHollowFontDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHollowFontDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHollowFontDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOLLOWFONTDEMO_H__D954F6F4_38A9_4412_904A_9066397BFC37__INCLUDED_)
