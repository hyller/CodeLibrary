// RefrainChild.h : main header file for the REFRAINCHILD application
//

#if !defined(AFX_REFRAINCHILD_H__F6E6B3B1_BD14_4139_BD84_BFD6DF2B4FB0__INCLUDED_)
#define AFX_REFRAINCHILD_H__F6E6B3B1_BD14_4139_BD84_BFD6DF2B4FB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRefrainChildApp:
// See RefrainChild.cpp for the implementation of this class
//

class CRefrainChildApp : public CWinApp
{
public:
	CRefrainChildApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRefrainChildApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRefrainChildApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REFRAINCHILD_H__F6E6B3B1_BD14_4139_BD84_BFD6DF2B4FB0__INCLUDED_)
