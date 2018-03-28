// MyFontDemo.h : main header file for the MYFONTDEMO application
//

#if !defined(AFX_MYFONTDEMO_H__8CC3D3EC_E7A8_4347_91B7_C5252AA5BF65__INCLUDED_)
#define AFX_MYFONTDEMO_H__8CC3D3EC_E7A8_4347_91B7_C5252AA5BF65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyFontDemoApp:
// See MyFontDemo.cpp for the implementation of this class
//

class CMyFontDemoApp : public CWinApp
{
public:
	CMyFontDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFontDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyFontDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFONTDEMO_H__8CC3D3EC_E7A8_4347_91B7_C5252AA5BF65__INCLUDED_)
