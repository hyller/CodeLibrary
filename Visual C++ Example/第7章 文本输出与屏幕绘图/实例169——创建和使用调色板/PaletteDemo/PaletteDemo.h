// PaletteDemo.h : main header file for the PALETTEDEMO application
//

#if !defined(AFX_PALETTEDEMO_H__74033DF7_C88C_4DBB_9291_CFD92308B6E7__INCLUDED_)
#define AFX_PALETTEDEMO_H__74033DF7_C88C_4DBB_9291_CFD92308B6E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoApp:
// See PaletteDemo.cpp for the implementation of this class
//

class CPaletteDemoApp : public CWinApp
{
public:
	CPaletteDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaletteDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPaletteDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PALETTEDEMO_H__74033DF7_C88C_4DBB_9291_CFD92308B6E7__INCLUDED_)
