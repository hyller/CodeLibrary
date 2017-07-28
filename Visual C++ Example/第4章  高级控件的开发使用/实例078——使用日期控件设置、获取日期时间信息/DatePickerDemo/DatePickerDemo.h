// DatePickerDemo.h : main header file for the DATEPICKERDEMO application
//

#if !defined(AFX_DATEPICKERDEMO_H__D51DE718_8CDD_4D21_8962_9B594819CB96__INCLUDED_)
#define AFX_DATEPICKERDEMO_H__D51DE718_8CDD_4D21_8962_9B594819CB96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDatePickerDemoApp:
// See DatePickerDemo.cpp for the implementation of this class
//

class CDatePickerDemoApp : public CWinApp
{
public:
	CDatePickerDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatePickerDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDatePickerDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATEPICKERDEMO_H__D51DE718_8CDD_4D21_8962_9B594819CB96__INCLUDED_)
