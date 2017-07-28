// DialogBarDemo.h : main header file for the DIALOGBARDEMO application
//

#if !defined(AFX_DIALOGBARDEMO_H__ACD2F082_4775_487B_8A70_990D76A83DA3__INCLUDED_)
#define AFX_DIALOGBARDEMO_H__ACD2F082_4775_487B_8A70_990D76A83DA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDemoApp:
// See DialogBarDemo.cpp for the implementation of this class
//

class CDialogBarDemoApp : public CWinApp
{
public:
	CDialogBarDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogBarDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDialogBarDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGBARDEMO_H__ACD2F082_4775_487B_8A70_990D76A83DA3__INCLUDED_)
