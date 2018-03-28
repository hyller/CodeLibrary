// UseExtentionDll.h : main header file for the USEEXTENTIONDLL application
//

#if !defined(AFX_USEEXTENTIONDLL_H__C5A491A4_B252_4343_8301_F6D1B49EBD2D__INCLUDED_)
#define AFX_USEEXTENTIONDLL_H__C5A491A4_B252_4343_8301_F6D1B49EBD2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseExtentionDllApp:
// See UseExtentionDll.cpp for the implementation of this class
//

class CUseExtentionDllApp : public CWinApp
{
public:
	CUseExtentionDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseExtentionDllApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseExtentionDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEEXTENTIONDLL_H__C5A491A4_B252_4343_8301_F6D1B49EBD2D__INCLUDED_)
