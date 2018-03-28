// WordPrint.h : main header file for the WORDPRINT application
//

#if !defined(AFX_WORDPRINT_H__F677E3FF_0D9C_456C_AC13_224DC1FBA6C3__INCLUDED_)
#define AFX_WORDPRINT_H__F677E3FF_0D9C_456C_AC13_224DC1FBA6C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWordPrintApp:
// See WordPrint.cpp for the implementation of this class
//

class CWordPrintApp : public CWinApp
{
public:
	CWordPrintApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordPrintApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWordPrintApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDPRINT_H__F677E3FF_0D9C_456C_AC13_224DC1FBA6C3__INCLUDED_)
