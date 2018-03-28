// TryException.h : main header file for the TRYEXCEPTION application
//

#if !defined(AFX_TRYEXCEPTION_H__780B5AB6_A1E4_4EDB_B1C0_54CB78D290E6__INCLUDED_)
#define AFX_TRYEXCEPTION_H__780B5AB6_A1E4_4EDB_B1C0_54CB78D290E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTryExceptionApp:
// See TryException.cpp for the implementation of this class
//

class CTryExceptionApp : public CWinApp
{
public:
	CTryExceptionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTryExceptionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTryExceptionApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRYEXCEPTION_H__780B5AB6_A1E4_4EDB_B1C0_54CB78D290E6__INCLUDED_)
