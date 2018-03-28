// UseExportClassDll.h : main header file for the USEEXPORTCLASSDLL application
//

#if !defined(AFX_USEEXPORTCLASSDLL_H__F9C0BCAD_949F_4234_876C_110BF5A67EEE__INCLUDED_)
#define AFX_USEEXPORTCLASSDLL_H__F9C0BCAD_949F_4234_876C_110BF5A67EEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseExportClassDllApp:
// See UseExportClassDll.cpp for the implementation of this class
//

class CUseExportClassDllApp : public CWinApp
{
public:
	CUseExportClassDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseExportClassDllApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseExportClassDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEEXPORTCLASSDLL_H__F9C0BCAD_949F_4234_876C_110BF5A67EEE__INCLUDED_)
