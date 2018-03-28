// MultiPrint.h : main header file for the MultiPrint application
//

#if !defined(AFX_MultiPrint_H__32801E1D_610C_4FB2_8287_30CC26A1D3ED__INCLUDED_)
#define AFX_MultiPrint_H__32801E1D_610C_4FB2_8287_30CC26A1D3ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiPrintApp:
// See MultiPrint.cpp for the implementation of this class
//

class CMultiPrintApp : public CWinApp
{
public:
	CMultiPrintApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiPrintApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMultiPrintApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MultiPrint_H__32801E1D_610C_4FB2_8287_30CC26A1D3ED__INCLUDED_)
