// BaseKeyDemo.h : main header file for the BASEKEYDEMO application
//

#if !defined(AFX_BASEKEYDEMO_H__43128941_B531_4C66_BF7C_3DC97A90EEDE__INCLUDED_)
#define AFX_BASEKEYDEMO_H__43128941_B531_4C66_BF7C_3DC97A90EEDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaseKeyDemoApp:
// See BaseKeyDemo.cpp for the implementation of this class
//

class CBaseKeyDemoApp : public CWinApp
{
public:
	CBaseKeyDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseKeyDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBaseKeyDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEKEYDEMO_H__43128941_B531_4C66_BF7C_3DC97A90EEDE__INCLUDED_)
