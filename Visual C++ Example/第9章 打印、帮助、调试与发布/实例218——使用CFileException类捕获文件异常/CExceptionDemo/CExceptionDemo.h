// CExceptionDemo.h : main header file for the CEXCEPTIONDEMO application
//

#if !defined(AFX_CEXCEPTIONDEMO_H__961CF347_997C_4524_894F_980BD5936B80__INCLUDED_)
#define AFX_CEXCEPTIONDEMO_H__961CF347_997C_4524_894F_980BD5936B80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCExceptionDemoApp:
// See CExceptionDemo.cpp for the implementation of this class
//

class CCExceptionDemoApp : public CWinApp
{
public:
	CCExceptionDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCExceptionDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCExceptionDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CEXCEPTIONDEMO_H__961CF347_997C_4524_894F_980BD5936B80__INCLUDED_)
