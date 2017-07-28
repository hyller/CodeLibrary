// AniBitmapWnd.h : main header file for the ANIBITMAPWND application
//

#if !defined(AFX_ANIBITMAPWND_H__0F71539B_60DC_4F1A_973F_952BCB3088EC__INCLUDED_)
#define AFX_ANIBITMAPWND_H__0F71539B_60DC_4F1A_973F_952BCB3088EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAniBitmapWndApp:
// See AniBitmapWnd.cpp for the implementation of this class
//

class CAniBitmapWndApp : public CWinApp
{
public:
	CAniBitmapWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAniBitmapWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAniBitmapWndApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIBITMAPWND_H__0F71539B_60DC_4F1A_973F_952BCB3088EC__INCLUDED_)
