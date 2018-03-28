// PartTransDlg.h : main header file for the PARTTRANSDLG application
//

#if !defined(AFX_PARTTRANSDLG_H__18879080_722B_475C_A974_3531F25300B5__INCLUDED_)
#define AFX_PARTTRANSDLG_H__18879080_722B_475C_A974_3531F25300B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPartTransDlgApp:
// See PartTransDlg.cpp for the implementation of this class
//

class CPartTransDlgApp : public CWinApp
{
public:
	CPartTransDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPartTransDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPartTransDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARTTRANSDLG_H__18879080_722B_475C_A974_3531F25300B5__INCLUDED_)
