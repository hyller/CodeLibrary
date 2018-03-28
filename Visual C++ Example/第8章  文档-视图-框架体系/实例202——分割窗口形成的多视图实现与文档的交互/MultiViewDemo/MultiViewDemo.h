// MultiViewDemo.h : main header file for the MULTIVIEWDEMO application
//

#if !defined(AFX_MULTIVIEWDEMO_H__6E49F79C_0459_4493_BDD0_738D23F6A10D__INCLUDED_)
#define AFX_MULTIVIEWDEMO_H__6E49F79C_0459_4493_BDD0_738D23F6A10D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDemoApp:
// See MultiViewDemo.cpp for the implementation of this class
//

class CMultiViewDemoApp : public CWinApp
{
public:
	CMultiViewDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiViewDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMultiViewDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIVIEWDEMO_H__6E49F79C_0459_4493_BDD0_738D23F6A10D__INCLUDED_)
