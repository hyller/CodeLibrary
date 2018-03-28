// ColorDlgDemo.h : main header file for the COLORDLGDEMO application
//

#if !defined(AFX_COLORDLGDEMO_H__6390C428_B788_4D9C_89B7_900D3D284EA3__INCLUDED_)
#define AFX_COLORDLGDEMO_H__6390C428_B788_4D9C_89B7_900D3D284EA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CColorDlgDemoApp:
// See ColorDlgDemo.cpp for the implementation of this class
//

class CColorDlgDemoApp : public CWinApp
{
public:
	CColorDlgDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorDlgDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CColorDlgDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORDLGDEMO_H__6390C428_B788_4D9C_89B7_900D3D284EA3__INCLUDED_)
