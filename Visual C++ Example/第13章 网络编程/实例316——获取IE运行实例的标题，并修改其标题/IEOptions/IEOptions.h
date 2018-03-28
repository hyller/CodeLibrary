// IEOptions.h : main header file for the IEOPTIONS application
//

#if !defined(AFX_IEOPTIONS_H__6A45D70C_8BDE_40D3_A19B_C11AC3917D89__INCLUDED_)
#define AFX_IEOPTIONS_H__6A45D70C_8BDE_40D3_A19B_C11AC3917D89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIEOptionsApp:
// See IEOptions.cpp for the implementation of this class
//

class CIEOptionsApp : public CWinApp
{
public:
	CIEOptionsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIEOptionsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIEOptionsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IEOPTIONS_H__6A45D70C_8BDE_40D3_A19B_C11AC3917D89__INCLUDED_)
