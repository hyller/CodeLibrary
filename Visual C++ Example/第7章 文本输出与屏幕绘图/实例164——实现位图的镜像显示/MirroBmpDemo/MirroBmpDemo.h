// MirroBmpDemo.h : main header file for the MIRROBMPDEMO application
//

#if !defined(AFX_MIRROBMPDEMO_H__E36948FD_0959_4475_9227_A1997BE3A367__INCLUDED_)
#define AFX_MIRROBMPDEMO_H__E36948FD_0959_4475_9227_A1997BE3A367__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMirroBmpDemoApp:
// See MirroBmpDemo.cpp for the implementation of this class
//

class CMirroBmpDemoApp : public CWinApp
{
public:
	CMirroBmpDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMirroBmpDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMirroBmpDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MIRROBMPDEMO_H__E36948FD_0959_4475_9227_A1997BE3A367__INCLUDED_)
