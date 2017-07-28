// BrushDemo.h : main header file for the BRUSHDEMO application
//

#if !defined(AFX_BRUSHDEMO_H__EA0EFA65_7768_4A4F_A6D0_E4D764F67743__INCLUDED_)
#define AFX_BRUSHDEMO_H__EA0EFA65_7768_4A4F_A6D0_E4D764F67743__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBrushDemoApp:
// See BrushDemo.cpp for the implementation of this class
//

class CBrushDemoApp : public CWinApp
{
public:
	CBrushDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrushDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBrushDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRUSHDEMO_H__EA0EFA65_7768_4A4F_A6D0_E4D764F67743__INCLUDED_)
