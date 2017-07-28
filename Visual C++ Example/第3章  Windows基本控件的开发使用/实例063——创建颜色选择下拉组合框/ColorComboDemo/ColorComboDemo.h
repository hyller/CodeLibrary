// ColorComboDemo.h : main header file for the COLORCOMBODEMO application
//

#if !defined(AFX_COLORCOMBODEMO_H__79D6E3E2_A18D_4553_BAC7_43B4CD8C9C16__INCLUDED_)
#define AFX_COLORCOMBODEMO_H__79D6E3E2_A18D_4553_BAC7_43B4CD8C9C16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CColorComboDemoApp:
// See ColorComboDemo.cpp for the implementation of this class
//

class CColorComboDemoApp : public CWinApp
{
public:
	CColorComboDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorComboDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CColorComboDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORCOMBODEMO_H__79D6E3E2_A18D_4553_BAC7_43B4CD8C9C16__INCLUDED_)
