// PopUpMenu.h : main header file for the POPUPMENU application
//

#if !defined(AFX_POPUPMENU_H__410E9E07_C99B_41AC_9447_2B49743F79F9__INCLUDED_)
#define AFX_POPUPMENU_H__410E9E07_C99B_41AC_9447_2B49743F79F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPopUpMenuApp:
// See PopUpMenu.cpp for the implementation of this class
//

class CPopUpMenuApp : public CWinApp
{
public:
	CPopUpMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopUpMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPopUpMenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPUPMENU_H__410E9E07_C99B_41AC_9447_2B49743F79F9__INCLUDED_)
