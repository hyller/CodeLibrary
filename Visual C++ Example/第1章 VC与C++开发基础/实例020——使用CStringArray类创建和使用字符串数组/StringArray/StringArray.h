// StringArray.h : main header file for the StringArray application
//

#if !defined(AFX_StringArray_H__CCE734B5_2F33_4C70_B846_480B1411E4D1__INCLUDED_)
#define AFX_StringArray_H__CCE734B5_2F33_4C70_B846_480B1411E4D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStringArrayApp:
// See StringArray.cpp for the implementation of this class
//

class CStringArrayApp : public CWinApp
{
public:
	CStringArrayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStringArrayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStringArrayApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_StringArray_H__CCE734B5_2F33_4C70_B846_480B1411E4D1__INCLUDED_)
