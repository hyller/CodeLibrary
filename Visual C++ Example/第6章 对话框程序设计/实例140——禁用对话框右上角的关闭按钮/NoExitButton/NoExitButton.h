// NoExitButton.h : main header file for the NOEXITBUTTON application
//

#if !defined(AFX_NOEXITBUTTON_H__A89B5F5B_A985_40A0_9AC8_0D31A23E7FCB__INCLUDED_)
#define AFX_NOEXITBUTTON_H__A89B5F5B_A985_40A0_9AC8_0D31A23E7FCB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNoExitButtonApp:
// See NoExitButton.cpp for the implementation of this class
//

class CNoExitButtonApp : public CWinApp
{
public:
	CNoExitButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoExitButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNoExitButtonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOEXITBUTTON_H__A89B5F5B_A985_40A0_9AC8_0D31A23E7FCB__INCLUDED_)
