// GetFullPath.h : main header file for the GETFULLPATH application
//

#if !defined(AFX_GETFULLPATH_H__E84583A0_569E_4A61_B1FC_2B05EF8E05D6__INCLUDED_)
#define AFX_GETFULLPATH_H__E84583A0_569E_4A61_B1FC_2B05EF8E05D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetFullPathApp:
// See GetFullPath.cpp for the implementation of this class
//

class CGetFullPathApp : public CWinApp
{
public:
	CGetFullPathApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetFullPathApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetFullPathApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETFULLPATH_H__E84583A0_569E_4A61_B1FC_2B05EF8E05D6__INCLUDED_)
