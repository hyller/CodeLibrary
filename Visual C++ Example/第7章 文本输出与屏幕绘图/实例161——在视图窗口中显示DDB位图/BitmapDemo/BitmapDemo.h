// BitmapDemo.h : main header file for the BITMAPDEMO application
//

#if !defined(AFX_BITMAPDEMO_H__D9FD9AAC_85FE_4C2C_A059_C6C61DFC050C__INCLUDED_)
#define AFX_BITMAPDEMO_H__D9FD9AAC_85FE_4C2C_A059_C6C61DFC050C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBitmapDemoApp:
// See BitmapDemo.cpp for the implementation of this class
//

class CBitmapDemoApp : public CWinApp
{
public:
	CBitmapDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBitmapDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPDEMO_H__D9FD9AAC_85FE_4C2C_A059_C6C61DFC050C__INCLUDED_)
