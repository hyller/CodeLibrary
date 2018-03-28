// WindowDcDemo.h : main header file for the WINDOWDCDEMO application
//

#if !defined(AFX_WINDOWDCDEMO_H__D2CCE300_5554_45D9_A1E6_8DAC8F095C17__INCLUDED_)
#define AFX_WINDOWDCDEMO_H__D2CCE300_5554_45D9_A1E6_8DAC8F095C17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWindowDcDemoApp:
// See WindowDcDemo.cpp for the implementation of this class
//

class CWindowDcDemoApp : public CWinApp
{
public:
	CWindowDcDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowDcDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWindowDcDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWDCDEMO_H__D2CCE300_5554_45D9_A1E6_8DAC8F095C17__INCLUDED_)
