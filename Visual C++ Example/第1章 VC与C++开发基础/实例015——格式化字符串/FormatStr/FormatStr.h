// FormatStr.h : main header file for the FORMATSTR application
//

#if !defined(AFX_FORMATSTR_H__26F4AE41_E4A1_4271_A813_39F82BB2D373__INCLUDED_)
#define AFX_FORMATSTR_H__26F4AE41_E4A1_4271_A813_39F82BB2D373__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFormatStrApp:
// See FormatStr.cpp for the implementation of this class
//

class CFormatStrApp : public CWinApp
{
public:
	CFormatStrApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormatStrApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFormatStrApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMATSTR_H__26F4AE41_E4A1_4271_A813_39F82BB2D373__INCLUDED_)
