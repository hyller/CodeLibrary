// RadioMenuDemo.h : main header file for the RADIOMENUDEMO application
//

#if !defined(AFX_RADIOMENUDEMO_H__2D396093_F27D_4CB9_94B3_FDAD07BD78BE__INCLUDED_)
#define AFX_RADIOMENUDEMO_H__2D396093_F27D_4CB9_94B3_FDAD07BD78BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRadioMenuDemoApp:
// See RadioMenuDemo.cpp for the implementation of this class
//

class CRadioMenuDemoApp : public CWinApp
{
public:
	CRadioMenuDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRadioMenuDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRadioMenuDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RADIOMENUDEMO_H__2D396093_F27D_4CB9_94B3_FDAD07BD78BE__INCLUDED_)
