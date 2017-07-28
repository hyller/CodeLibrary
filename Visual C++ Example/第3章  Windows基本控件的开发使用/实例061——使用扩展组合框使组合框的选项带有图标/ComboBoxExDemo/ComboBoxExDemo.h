// ComboBoxExDemo.h : main header file for the COMBOBOXEXDEMO application
//

#if !defined(AFX_COMBOBOXEXDEMO_H__A509639B_FFDC_4421_8D72_2E89D145F183__INCLUDED_)
#define AFX_COMBOBOXEXDEMO_H__A509639B_FFDC_4421_8D72_2E89D145F183__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CComboBoxExDemoApp:
// See ComboBoxExDemo.cpp for the implementation of this class
//

class CComboBoxExDemoApp : public CWinApp
{
public:
	CComboBoxExDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboBoxExDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CComboBoxExDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOBOXEXDEMO_H__A509639B_FFDC_4421_8D72_2E89D145F183__INCLUDED_)
