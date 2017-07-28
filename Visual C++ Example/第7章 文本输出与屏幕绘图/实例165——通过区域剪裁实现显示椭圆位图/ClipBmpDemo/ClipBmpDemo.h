// ClipBmpDemo.h : main header file for the CLIPBMPDEMO application
//

#if !defined(AFX_CLIPBMPDEMO_H__59EE595F_D4AA_4D93_96C8_03F5C76F11EF__INCLUDED_)
#define AFX_CLIPBMPDEMO_H__59EE595F_D4AA_4D93_96C8_03F5C76F11EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CClipBmpDemoApp:
// See ClipBmpDemo.cpp for the implementation of this class
//

class CClipBmpDemoApp : public CWinApp
{
public:
	CClipBmpDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipBmpDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CClipBmpDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPBMPDEMO_H__59EE595F_D4AA_4D93_96C8_03F5C76F11EF__INCLUDED_)
