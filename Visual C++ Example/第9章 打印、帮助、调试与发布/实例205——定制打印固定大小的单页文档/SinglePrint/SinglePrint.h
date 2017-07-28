// SinglePrint.h : main header file for the SINGLEPRINT application
//

#if !defined(AFX_SINGLEPRINT_H__32801E1D_610C_4FB2_8287_30CC26A1D3ED__INCLUDED_)
#define AFX_SINGLEPRINT_H__32801E1D_610C_4FB2_8287_30CC26A1D3ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSinglePrintApp:
// See SinglePrint.cpp for the implementation of this class
//

class CSinglePrintApp : public CWinApp
{
public:
	CSinglePrintApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinglePrintApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSinglePrintApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEPRINT_H__32801E1D_610C_4FB2_8287_30CC26A1D3ED__INCLUDED_)
