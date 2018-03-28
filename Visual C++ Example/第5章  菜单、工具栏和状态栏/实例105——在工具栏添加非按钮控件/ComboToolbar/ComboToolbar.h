// ComboToolbar.h : main header file for the COMBOTOOLBAR application
//

#if !defined(AFX_COMBOTOOLBAR_H__0CE0B6EF_5CFA_4817_BEA0_5607F0A5A3D7__INCLUDED_)
#define AFX_COMBOTOOLBAR_H__0CE0B6EF_5CFA_4817_BEA0_5607F0A5A3D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CComboToolbarApp:
// See ComboToolbar.cpp for the implementation of this class
//

class CComboToolbarApp : public CWinApp
{
public:
	CComboToolbarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboToolbarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CComboToolbarApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOTOOLBAR_H__0CE0B6EF_5CFA_4817_BEA0_5607F0A5A3D7__INCLUDED_)
