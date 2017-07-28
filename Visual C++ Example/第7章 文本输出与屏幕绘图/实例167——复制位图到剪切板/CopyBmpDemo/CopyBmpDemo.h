// CopyBmpDemo.h : main header file for the COPYBMPDEMO application
//

#if !defined(AFX_COPYBMPDEMO_H__80D42FA5_D4FF_4788_9BA8_13E3DCF9FF57__INCLUDED_)
#define AFX_COPYBMPDEMO_H__80D42FA5_D4FF_4788_9BA8_13E3DCF9FF57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCopyBmpDemoApp:
// See CopyBmpDemo.cpp for the implementation of this class
//

class CCopyBmpDemoApp : public CWinApp
{
public:
	CCopyBmpDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCopyBmpDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCopyBmpDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COPYBMPDEMO_H__80D42FA5_D4FF_4788_9BA8_13E3DCF9FF57__INCLUDED_)
