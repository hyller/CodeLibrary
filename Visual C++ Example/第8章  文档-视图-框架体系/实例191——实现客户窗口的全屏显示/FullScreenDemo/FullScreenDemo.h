// FullScreenDemo.h : main header file for the FULLSCREENDEMO application
//

#if !defined(AFX_FULLSCREENDEMO_H__34E4181F_501A_42B0_9CDC_59D30BF4603F__INCLUDED_)
#define AFX_FULLSCREENDEMO_H__34E4181F_501A_42B0_9CDC_59D30BF4603F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDemoApp:
// See FullScreenDemo.cpp for the implementation of this class
//

class CFullScreenDemoApp : public CWinApp
{
public:
	CFullScreenDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullScreenDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFullScreenDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FULLSCREENDEMO_H__34E4181F_501A_42B0_9CDC_59D30BF4603F__INCLUDED_)
