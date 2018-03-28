// DrawArrowDemo.h : main header file for the DRAWARROWDEMO application
//

#if !defined(AFX_DRAWARROWDEMO_H__271CE6CC_DAFA_4D27_83F3_5DD3689A5834__INCLUDED_)
#define AFX_DRAWARROWDEMO_H__271CE6CC_DAFA_4D27_83F3_5DD3689A5834__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawArrowDemoApp:
// See DrawArrowDemo.cpp for the implementation of this class
//

class CDrawArrowDemoApp : public CWinApp
{
public:
	CDrawArrowDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawArrowDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDrawArrowDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWARROWDEMO_H__271CE6CC_DAFA_4D27_83F3_5DD3689A5834__INCLUDED_)
